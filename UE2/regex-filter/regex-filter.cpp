
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <map>

using namespace std::string_literals;

void match(const std::string& match_string, std::map<std::string, int> & matches){
    std::locale loc;
    std::string lowercase;
    for(auto str : match_string) {
        lowercase += std::tolower(str, loc);
    }
    matches[lowercase] += 1;
}

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "No regex passed" << std::endl;

        return -1;
    }

    // Input
    
    const auto filename = "emails.txt"s; // change to ../emails.txt for cmake
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
        if(strcmp(argv[2], "true") == 0) { // Command-line argument to set case-insensitive
            regex.assign(argv[1], std::regex_constants::icase);
        }
    }

    std::smatch base_match;
    std::map<std::string, int> matches;
    for (const auto & l : lines) {
        // discarding all unmatched lines
        if(std::regex_search(l, base_match, regex)) {
            // collecting and counting the matches
            // matching simple string
            match(base_match[base_match.size()-1].str(), matches);
        }
    }

    // Outputting all matches with their number of occurrences
    for (auto const & match : matches) {
        std::cout << match.first << ": " << match.second << std::endl;
    }
    
    return 0;
}
