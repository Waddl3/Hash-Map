#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>

//Hashcodes
class HashCode {
public:
    //polynomial hash code
    int operator() (const std::string& s, const int a = 37) {
        unsigned int h = 0;
        int k = s.size();

        for(int i = 0; i < k; i++) {
            int power = (k - 1) - i;
            h += (unsigned int) s[i] * std::pow(a, power);
        }

        return h;
    }

};

int main(int argc, char const *argv[])
{

    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;

    std::ifstream US_DoI_File("C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt");

    //not open?
    if(!US_DoI_File.is_open()) std::cout << "Not Open!" << std::endl;


    HashCode h;
    std::unordered_map<int, int> map;
    std::string word = "";

    while(US_DoI_File >> word) {
        int hasher = std::abs(h(word, 0));

        if(map.find(hasher) != map.end()) {
            map[hasher]++;
        }
        else {
            map[hasher] = 1;
        }
    }

    auto p = map.begin();
    std::cout << "{(HASH, COLLISION)}, a = 0" << std::endl;
    while(!(p == map.end())) {
        std::cout << "{(" << p->first << ", " << p->second << ")}" << std::endl;
        ++p;
    }
    
    
    return 0;
}
