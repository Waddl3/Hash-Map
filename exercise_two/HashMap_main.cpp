#include <iostream>
#include "HashMap.h"

int main(int argc, char const *argv[])
{
    HashMap<int, std::string, int> mp(11);

    mp.put(13, "31");
    mp.put(21, "12");
    mp.put(5, "5");
    mp.put(37, "73");
    mp.put(15, "51");

    auto p = mp.begin();
    std::cout << *p;

    mp.erase(20);
    mp.erase(37);


    std::cout << "\n End part 1 \n" << std::endl;
    
    return 0;
}
