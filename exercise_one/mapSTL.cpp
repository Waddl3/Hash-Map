#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::map<int, std::string> mp;
    std::map<int, std::string>::iterator p;
    mp[13] = "31";
    mp[21] = "12";
    mp[5] = "5";
    mp[37] = "75";
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

    std::fstream small_inFile("C:/Users/jesus/GitHub/Hash-Map/small1k.txt", std::ios_base::in);
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
        int l = 0;
        int r = k.size() - 1;

        //reverse string order of v
        while(l < r) {
            std::swap(k[l], k[r]);
            ++l;
            --r;
        }

        //store v & k
        mps[v] = k;
    }
    end = clock();

    std::cout << "Running-time: " << end - start << " ms" << std::endl;

    auto q = mps.begin();
    int n = 5;
    while(q != mps.end() && n--) {
        std::cout << "{(" << q->first << ", " << q->second << ")} , ";
        ++q;
    }

    std::cout << "\n\n End part 2 \n\n" << std::endl;

    return 0;
}
