#include <cstdint>
#include <iostream>

/**
 * Reverse bits and bytes. Write an algorithm that will reverse the order of a given byte.
 * Ex: 10100011 becomes 11000101
 *     11001101 becomes 10110011
 * 
 * Then continuing on with that, reverse a set of bytes
 * Ex: 11000101 10110011 becomes 10110011 11000101
*/

void reverseByte(int* byte)
{
    int temp[8];
    for(uint32_t iIter; iIter < 8; iIter++)
    {
        temp[7-iIter] = byte[iIter];
    }
    byte = temp;
}


int main()
{
    
    int myArr[8] = {1, 0, 1, 0, 0, 0, 1, 1};
    reverseByte(myArr);

    for(uint32_t iIter = 0; iIter < 8; iIter++)
    {
        std::cout<<myArr[iIter];
    }
    std::cout<<std::endl;

    return 0;
}