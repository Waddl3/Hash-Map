#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <ctime>

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
    //unordered_map
    
    std::map<int, std::string> mp;
    std::map<int, std::string>::iterator p;
    //mp.insert(std::pair<int, std::string>(13,"31"));
    mp[13] = "31";
    mp[21] = "12";
    mp[5] = "5";
    mp[37] = "73";
    mp[15] = "51";

    p = mp.find(10);
    if(p == mp.end()) std::cout << "does not exist" << std::endl;
    else std::cout << "(" << p->first << ", " << p->second << ")\n";

    p = mp.find(21);
    if(p == mp.end()) std::cout << "does not exist" << std::endl;
    else std::cout << "(" << p->first << ", " << p->second << ")\n";

    mp.erase(20);
    mp.erase(37);
    
    p = mp.find(37);
    if(p == mp.end()) std::cout << "does not exist" << std::endl;
    else std::cout << "(" << p->first << ", " << p->second << ")\n";

    std::cout << "\n End part 1 \n" << std::endl;

    /*
        FILES PART 2 OF 3
    */

    std::fstream small_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/small1k.txt", std::ios_base::in);
    std::fstream large_inFile("C:/Users/jesus/Documents/GitHub/Hash-Map/large100k.txt", std::ios_base::in);
    std::map<int, std::string> mps;
    int v = 0;
    std::string k = "";
    clock_t start, end;

    //not open?
    if(!small_inFile.is_open()) std::cout << "Not open" << std::endl;

    //store inputtext to variable

    start = clock();
    while(small_inFile >> v) {
        k = std::to_string(v);
        reverseKey(k);

        //store v & k
        mps[v] = k;
    }
    end = clock();

    std::cout << "small1k.txt Running-time: " << end - start << " ms" << std::endl;

    auto q = mps.begin();   //iterator
    int n = 5;              //first 5 print for test
    while(q != mps.end() && n--) {
        std::cout << "{(" << q->first << ", " << q->second << ")} , ";
        ++q;    //increment to the next
    }

    std::cout << "\n\n End part 2 \n\n" << std::endl;

    /*
        FILE PART 3 OF 3
    */

   //Reset
   mps.clear();
   v = 0;
   k = "";

   start = clock();
    while(large_inFile >> v) {
        k = std::to_string(v);
        reverseKey(k);

        //store v & k
        mps[v] = k;
    }
    end = clock();

    std::cout << "large100k.txt Running-time: " << end - start << " ms" << std::endl;

    q = mps.begin();
    n = 10;    //first 10
    while(q != mps.end() && n--) {
        std::cout << "{(" << q->first << ", " << q->second << ")} , ";
        ++q;
    }

    std::cout << "\n\n End part 3 \n\n" << std::endl;

    return 0;
}
