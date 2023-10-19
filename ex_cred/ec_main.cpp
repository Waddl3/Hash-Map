#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>

//Hashcodes
class HashCode {
public:
    //cyclic shift hash codes
    int operator() (const std::string& s, int a = 37) {
        unsigned int h = 0;

        for(int i = 0; i < s.size(); i++) {
            h = (h << 5) | (h >> a);
            h += (unsigned int) s[i];
        }

        return static_cast<int>(h);
    }
};

int main(int argc, char const *argv[])
{

    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;
    std::unordered_map<int, int> collisions;
    std::unordered_map<int, std::string> wordList;
    std::ifstream US_DoI_File("C:/Users/jesus/GitHub/Hash-Map/usdeclarPC.txt");
    HashCode h;
    int k = 0;
    std::string word = "";
    int sumOfCollisions = 0;

    //not open?
    if(!US_DoI_File.is_open()) std::cout << "Not Open!" << std::endl;

    while(US_DoI_File >> word) {
        k = std::abs(h(word, 40));

        //collisions
        if(collisions.find(k) != collisions.end()){
            collisions[k]++;
        }
        else {
            collisions[k] = 1;
        }

        //words repeated ignore
        wordList[k] = word;
    }

    //n collisions
    auto iter = collisions.begin();
    while(iter != collisions.end()){
        if(iter->second > 1) {
            sumOfCollisions += iter->second;
        }

        ++iter;
    }

    std::cout << "Cyclic Shift Hashcode - Number of collisions: " << sumOfCollisions << std::endl;
    
    return 0;
}
