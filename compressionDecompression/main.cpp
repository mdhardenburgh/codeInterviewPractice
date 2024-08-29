#include <string>
#include <iostream>

/**
 * From: https://techdevguide.withgoogle.com/resources/former-interview-question-compression-and-decompression/#!
 *
 * 
 * In this exercise, you're going to decompress a compressed string.
 *
 * Your input is a compressed string of the format number[string] and the decompressed output form should be the string written number times. For example:
 *
 * The input:
 * 3[abc]4[ab]c
 *
 * Would be output as:
 * abcabcabcababababc
 * 
 * Other rules:
 * * Number can have more than one digit. For example, 10[a] is allowed, and just means aaaaaaaaaa
 * * One repetition can occur inside another. For example, 2[3[a]b] decompresses into aaabaaab
 * * Characters allowed as input include digits, small English letters and brackets [ ].
 * * Digits are only to represent amount of repetitions.
 * * Letters are just letters.
 * * Brackets are only part of syntax of writing repeated substring.
 * * Input is always valid, so no need to check its validity.
 *
 * Learning objectives:
 *
 * This question gives you the chance to practice with strings, recursion, algorithm, compilers, automata, and loops. It’s also an opportunity to work on coding with better efficiency. 
 **/

enum class states : const uint32_t
{
    NUMBER,
    CHAR,
};

std::string expand(uint32_t number, std::string chars)
{
    std::string expandedString;
    expandedString.clear();
    for(uint32_t iIter = 0; iIter < number; iIter++)
    {
        expandedString.append(chars);
    }
    return expandedString;
}

std::string decompress(std::string input)
{
    states state = states::NUMBER;
    std::string number;
    std::string chars;
    std::string returnValue;

    number.clear();
    chars.clear();
    returnValue.clear();
    
    for(uint32_t iIter = 0; iIter < input.size(); iIter++)
    {
        if(states::NUMBER == state)
        {
            char extracted[1] = {input.at(iIter)};
            if('[' != extracted[0])
            {
                number.append(extracted);
                state = states::NUMBER;
            }
            else if('[' == extracted[0])
            {
                state = states::CHAR;
            }
            else
            {
                std::cerr<<"states::NUMBER=> shouldn't be in this state, somethings gone wrong"<<std::endl;
                break;
            }
            
        }

        if(states::CHAR == state)
        {
            char extracted[1] = {input.at(iIter)};
            if("]" != extracted)
            {
                chars.append(extracted);
                state = states::NUMBER;
            }
            else if("]" == extracted)
            {
                state = states::CHAR;
                returnValue.append(expand(stoi(number), chars));
                number.clear();
                chars.clear();
            }
            else
            {
                std::cerr<<"states::CHAR=> shouldn't be in this state, somethings gone wrong"<<std::endl;
                break;
            }
        }
    }

    return returnValue;
} 

int main()
{
    std::cout<< "3[abc]4[ab]c decompressed is "<<decompress("3[abc]4[ab]c")<<std::endl;

    return 0;
}