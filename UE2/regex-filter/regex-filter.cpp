
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>

using namespace std::string_literals;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "No regex passed" << std::endl;

        return -1;
    }

    // Input
    
    const auto filename = "emails.txt"s;
    std::ifstream file(filename, std::ios::in);

    if (!file.good())
    {
        std::cerr << "Unable to read file " << filename << std::endl;
        return -2;
    }

    file.seekg(0, std::ios::end);
    const auto contents_length = file.tellg();
    file.seekg(0, std::ios::beg);

    if (contents_length <= 0)
    {
        std::cerr << "No contents in " << filename << std::endl;
        return -3;
    }

    auto line = std::string("");
    std::vector<std::string> lines;
    while (std::getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        lines.push_back(std::move(line));
    }

    // Filtering and counting

    std::regex regex(argv[1]); // Command-line argument regex

    // Case-sensitive per default
    if(argc >= 3) {
        if(argv[2]) { // Command-line argument to set case-insensitive TODO is there a specific command-line switch option?
            regex.assign(argv[1], std::regex_constants::icase);
        }
    }

    std::smatch base_match;
    std::map<std::string, int> matches;
    for (const auto & line : lines) {
        // discarding all unmatched lines
        if(std::regex_match(line, base_match, regex)) {
            // collecting and counting the match within the line
            if (base_match.size() == 2) {
                matches[base_match[1].str()] += + 1;
            }
        }
    }

    // Outputting all matches with their number of occurrences
    for (auto const & match : matches) {
        std::cout << match.first << ": " << match.second << std::endl;
    }
    
    return 0;
}

// compile: g++ -std=c++14 -o regex-filter regex-filter.cpp
// run case-sensitive option 1: ./regex-filter "Lu.*@(hpi|student.*).de" --> no results
// run case-sensitive option 2: ./regex-filter "Lu.*@(hpi|student.*).de" false --> no results
// run case-insensitive: ./regex-filter "Lu.*@(hpi|student.*).de" true --> hpi: 1, student.hpi.uni-potsdam: 2
// run case-sensitive: ./regex-filter "lu.*@(hpi|student.*).de" --> hpi: 1, student.hpi.uni-potsdam: 2
