#include <iostream>
#include <string>
#include "HashMap.h"

class intHashCode{
public:
    int operator() (int k) { return k; }
};

class stringHashCode {
public:
    int operator() (const std::string& k){
        return k.size();
    }
};

int main(int argc, char const *argv[])
{
    HashMap<int, std::string, intHashCode> mp(11);
    mp.put(13, "31");

    
    return 0;
}
