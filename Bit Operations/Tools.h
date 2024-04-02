#pragma once

#include <vector>
#include <cstring>
#include <string>

namespace Tools
{
    class BitOperations
    {
        public:
            BitOperations(){}

        public:
            static int hex_to_int(const std::vector<char> &hex_vector, char *bytes)
            {
                std::string str(hex_vector.begin(), hex_vector.end());
                size_t length = str.length();
                for(size_t i = 0 ; i <length; i += 2)
                {
                    std::string byte = str.substr(i,2);
                    unsigned char charByte = static_cast<unsigned char>(std::stoul(byte,nullptr,16));
                    bytes[i/2] = charByte;
                }
                return 0;
            }

            static char* int_to_hex(int val)
            {
                auto remaining = val % 16;
                auto quotient = val / 16;
                char *hex = new char[2];

                hex[0] = (char) (quotient < 10 ? '0' + quotient : 'A' + quotient - 10);
                hex[1] = (char) (remaining < 10 ? '0' + remaining : 'A' + remaining - 10);

                return hex;
            }
    };

}