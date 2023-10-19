#include <iostream>
#include <string>
#include"HashMap.h"

//Hashcodes
class HashCode {
public:
    int operator() (const char* k, int len) {
        unsigned int h = 0;
        
        for(int i = 0; i < len; i++) {
            h = (h << 5) | (h >> 27);
            h += (unsigned int) k[i];
        }

        return operator() (int(h));
    }

};

int main(int argc, char const *argv[])
{
    HashMap<int, std::string, HashCode<std::string>> map;

    
    return 0;
}
