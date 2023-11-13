#if !defined(UTILITY_H)
#define UTILITY_H 1
#include <vector>
#include <string>
#include "defines.hpp"
#include <math.h>       /* pow */
// #include "../nlohmann/json.hpp"

// using JSON = nlohmann::json;

constexpr char hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
class Utility 
{
    public:
    static std::string toHexString(std::vector<unsigned char> bytes)
    {
        int len = bytes.size();
        std::string s(len * 2, ' ');
        for (int i = 0; i < len; ++i) 
        {
            s[2 * i]     = hexmap[(bytes.at(i) & 0xF0) >> 4];
            s[2 * i + 1] = hexmap[bytes.at(i) & 0x0F];
        }
        return s;
    }

    static std::vector<unsigned char> toBinary(const std::string& hex)
    {
        std::vector<unsigned char> bytes;
        for (unsigned int i = 0; i < hex.length(); i += 2) {
            std::string byteString = hex.substr(i, 2);
            char byte = (char) strtol(byteString.c_str(), NULL, 16);
            bytes.push_back(byte);
        }

        return bytes;
    }

    static int32_t degreesToSemicircles(double degrees){
        return (int32_t)((degrees *  pow (2.0, 31.0)) / 180.0 );
    }

    static double semicirclesToDegrees(int32_t semicircles){
        return ((double) semicircles /  pow (2.0, 31.0)) * 180.0 ;
    }
};
#endif
