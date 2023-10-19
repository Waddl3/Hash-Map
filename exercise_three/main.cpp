#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <cctype>

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
        k = h(word);

        //std::cout << std::abs(hasher) << std::endl;

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

    std::cout << "WordList" << std::endl;
   auto wordIter = wordList.begin();
    while (wordIter != wordList.end()) {
        std::cout << "{" << wordIter->second << "}" << std::endl;
        ++wordIter;
    }


    std::cout << "Number of collisions: " << sumOfCollisions << std::endl;
    
    return 0;
}
