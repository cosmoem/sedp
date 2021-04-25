#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <chrono>
#include <fstream>


bool isPalindrome(std::string word){
    int wordSize= word.size();
    if (wordSize%2==0) {

        std::string partOne = word.substr(0, wordSize / 2 );
        std::string partTwo = word.substr(wordSize / 2, wordSize-1);
        reverse(partTwo.begin(),partTwo.end());
        return partOne == partTwo;

    }
    else{
        std::string partOne = word.substr(0, wordSize / 2);
        std::string partTwo = word.substr(wordSize / 2 + 1, wordSize-1);
        reverse(partTwo.begin(),partTwo.end());
        return partOne ==partTwo;
    }
}



int main(int argc, char* argv [])
{

    // Input

    std::ifstream cin("../palindromes_small.txt");
    std::streambuf *cinbuf = std::cin.rdbuf();
    std::cin.rdbuf(cin.rdbuf());


   std::string line;
    std::vector<std::string> lines;
    while (std::getline(std::cin, line))
    {
        if (line.empty())
        {
            continue;
        }

        const auto size = line.size();
        lines.push_back(std::move(line));
        line.reserve(size);
    }


    // Todo: Implement algorithm to sort palindromes to the front of the list

    std::vector<std::string> palindromeVector;
    std::vector<std::string> nonPalindromeVector;
    for(const auto & word :lines)
    {

        if(isPalindrome(word)){
            palindromeVector.push_back(word);
        }else{
            nonPalindromeVector.push_back(word);
        }

    }

    std::copy(palindromeVector.begin(),palindromeVector.end(), lines.begin());
    std::copy(nonPalindromeVector.begin(),nonPalindromeVector.end(), lines.begin()+ palindromeVector.size());


    std::cout << "Sorted by palindromity" << std::endl << std::endl;
    for (const auto & s : lines)
    {
        std::cout << s << std::endl;
    }

    return 0;
}
