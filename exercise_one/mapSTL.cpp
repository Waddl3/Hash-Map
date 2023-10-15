#include <iostream>
#include <map>

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


    //FILES

    return 0;
}
