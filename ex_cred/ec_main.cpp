#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <cctype>

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

std::string lowerCase(std::string& s) {
    std::string word = s;
    for(char& c : s){
        c = std::tolower(c);
    }

    return s;
}

int main(int argc, char const *argv[])
{
    std::cout << "Author: Jesus Rodriguez-Luna" << std::endl;
    std::unordered_map<int, int> collisions;
    std::unordered_map<int, std::string> wordList;
    std::ifstream US_DoI_File("C:/Users/jesus/Documents/GitHub/Hash-Map/usdeclarPC.txt");
    HashCode h;
    int hasher = 0;
    std::string word = "";
    int sumOfCollisions = 0;

    //not open?
    if(!US_DoI_File.is_open()) std::cout << "Not Open!" << std::endl;

    while(US_DoI_File >> word) {
        //before generating hashcode, check if word exists
        hasher = std::abs(h(lowerCase(word)));
        auto p = wordList.find(hasher);
        if(p == wordList.end()){
            wordList[hasher] = word;
            collisions[hasher] = 1;
        }
        else {
            collisions[hasher]++;
        }
    }

    auto q = collisions.begin();
    while(q != collisions.end()) {
        if(q->second > 1) sumOfCollisions += q->second;
        ++q;
    }

    auto p = wordList.begin();
    while(p != wordList.end()) {
        std::cout << "{" << p->first << ", " << p->second << "}" << std::endl;
        ++p;
    }

    std::cout << "Cyclic Shift Hashcode - Number of collisions: " << sumOfCollisions << std::endl;
    
    return 0;
}
