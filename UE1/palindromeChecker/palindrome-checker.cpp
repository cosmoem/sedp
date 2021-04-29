#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <chrono>

// Function to check if a string is a palindrome
bool isPalindrome(std::string word){
    int wordSize= (int)word.size();
    std::for_each(word.begin(), word.end(), [](char & c){
        c = (char)::tolower(c);
    });
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

// run with time measurement: g++ -std=c++14 -o palindrome-checker palindrome-checker.cpp && time ./palindrome-checker measure < [FILE NAME]
// run without time measurement: g++ -std=c++14 -o palindrome-checker palindrome-checker.cpp && ./palindrome-checker < [FILE NAME]
int main(int argc, char* argv [])
{

    // Input
    auto line = std::string("");
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

    // Start time measurement
    const auto start = std::chrono::high_resolution_clock::now();

    // Check input for palindromity
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

    // Overwrite lines vector so that it's sorted
    std::copy(palindromeVector.begin(),palindromeVector.end(), lines.begin());
    std::copy(nonPalindromeVector.begin(), nonPalindromeVector.end(), lines.begin() + (long)palindromeVector.size());

    // Stop time measurement
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = end - start;
    std::cout << std::dec << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << std::endl;

    // Output
    std::cout << "Sorted by palindromity" << std::endl << std::endl;
    for (const auto & s : lines)
    {
        std::cout << s << std::endl;
    }

    return 0;
}
