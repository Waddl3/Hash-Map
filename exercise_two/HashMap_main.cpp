#include <iostream>
#include <string>
#include <fstream>
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

void reverseKey(std::string& key) {
    int l = 0;
    int r = key.size() - 1;

        //reverse string order of v
        while(l < r) {
            std::swap(key[l], key[r]);
            ++l;
            --r;
        }
}

int main(int argc, char const *argv[])
{
    HashMap<int, std::string, intHashCode> mp(11);

    mp.put(13, "31");
    mp.put(21, "12");
    mp.put(5, "5");
    mp.put(37, "73");
    mp.put(15, "51");

    for(auto p = mp.begin(); !(p == mp.end()); ++p) {
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;
    }

    //output DNE
    auto p = mp.find(10);
    if(p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;

    //output exists
    p = mp.find(21);
    if(p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;

    // mp.erase(20);   throws 'NonexistentElement'
    mp.erase(37);

    p = mp.find(37);
    if(p == mp.end())
        std::cout << "DNE" << std::endl;
    else
        std::cout << "{(" << (*p).key() << ", " << (*p).value() << ")}" << std::endl;
    
    std::cout << "\n End part 1 \n" << std::endl;

    /*
        FILES PART 2 OF 3
    */

    std::fstream small_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/small1k.txt", std::ios_base::in);
    std::fstream large_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/large100k.txt", std::ios_base::in);
    HashMap<int, std::string, intHashCode> filesMap(2 * 1000 + 1);
    int k = 0;
    std::string v = "";
    clock_t start, end;

    //not open?
    if(!small_inFile.is_open()) std::cout << "Not Found" << std::endl;

    //store input
    start = clock();
    while(small_inFile >> k) {
        v = std::to_string(k);
        reverseKey(v);

        //store v & k
        filesMap.put(k, v);
    }
    end = clock();
    //clock time
    std::cout << "small1k.txt Running-time: " << end - start << " ms" << std::endl;

    auto q = filesMap.begin();
    int n = 10;
    while(!(q == filesMap.end()) && n--) {
        std::cout << "{(" << (*q).key() << ", " << (*q).value() << ")}" << std::endl;
        ++q;
    }

    std::cout << "\n\n End part 2 \n\n" << std::endl;

    /*
        FILE PART 3 OF 3
    */
    HashMap<int, std::string, intHashCode> large_fileMaps(2 * 100000 + 1);

    //not open?
    if(!large_inFile.is_open()) std::cout << "Not Found" << std::endl;

    //store input
    start = clock();
    while(large_inFile >> k) {
        v = std::to_string(k);
        reverseKey(v);

        //store v & k
        large_fileMaps.put(k, v);
    }
    end = clock();
    
    //clock time
    std::cout << "large100k.txt Running-time: " << end - start << " ms" << std::endl;

    q = large_fileMaps.begin();
    n = 10;
    while(!(q == large_fileMaps.end()) && n--) {
        std::cout << "{(" << (*q).key() << ", " << (*q).value() << ")}" << std::endl;
        ++q;
    }

    std::cout << "\n\n End part 3 \n\n" << std::endl;

    return 0;
}


