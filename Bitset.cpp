#include <iostream>
#include <bitset>
#include <algorithm>

unsigned char convertToByte(std::bitset<8> bitSet){
    unsigned char convertedByte{0};

    for(int i = 0; i < 8; i++){
        if(bitSet[i]){
            convertedByte |= 1 << (7 - i);
        }
    }

    return convertedByte;
}

std::bitset<8> convertToBitset(unsigned char byte){
    std::bitset<8> convertedBitset{byte};

    for(auto idx= 0; idx < 4; idx++){
        bool temp = convertedBitset[idx];
        convertedBitset[idx] = convertedBitset[7-idx];
        convertedBitset[7 - idx] = temp;
    }
    return convertedBitset;
}

int main(int, char**){
    std::bitset<8> testSet;
    for(int i = 0; i < 8; i++){
        
        if(i%2 == 0)
        {
            testSet.set(i,true);
        }
        else
        {
            testSet.set(i,false);
        }
    }

    unsigned char convertedByte = convertToByte(testSet);

    std::cout << std::hex << static_cast<unsigned>(convertedByte) << std::endl;

    std::bitset<8> convertedBitset = convertToBitset(convertedByte);
    

    for(int i = 0; i < 8; i++){
        std::cout << convertedBitset[i];
    }
}
