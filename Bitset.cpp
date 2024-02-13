#include <iostream>
#include <bitset>

unsigned char convertToByte(std::bitset<8> bitSet){
    unsigned char convertedByte{0};

    for(int i = 0; i < 8; i++){
        if(bitSet[i]){
            convertedByte |= 1 << (7 - i);
        }
    }

    return convertedByte;
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

}
