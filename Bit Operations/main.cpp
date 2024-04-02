#include <iostream>
#include "Tools.h"

int main(int, char**){
    
    int val = 62;
    char *bytes = Tools::BitOperations::int_to_hex(val);
    
    //write the output of hex to int
    std::vector<char> hex_vector;

    for(int i = 0; i < 2; i++)
    {
        hex_vector.push_back(bytes[i]);
    }

    char *bytes2 = new char[1];
    Tools::BitOperations::hex_to_int(hex_vector, bytes2);
    std::cout << "Output of int to hex: " << bytes[0] << bytes[1] << std::endl;
    return 0;
}
