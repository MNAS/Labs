// map::find
#include <iostream>
#include <map>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    std::map<char, int> mymap;
    std::map<char, double> map_fr;
    std::map<char, std::string> map_color;
    std::map<char, int>::iterator it;
    std::map<char, double>::iterator i_map_fr;
    char ch;

    if (argc != 2) {
        std::cout << "Usage:" << std::endl;
        std::cout << "data_secure_01 file_name" << std::endl;
        return 1;
    }
    std::ifstream in(argv[1]);
    if (!in.good())
        return 2;

    while (in.good()) {
        in >> ch;
        it = mymap.find(ch);
        if (it ==  mymap.end())
            mymap[ch] = 1;
        else
            it->second++;
    }
    in.close();
    int counter = 0;
    for (std::map<char, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        counter += i->second;
    }

    for (std::map<char, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        map_fr[i->first] = double(i->second) / double(counter);
        if (map_fr[i->first] < 0.2)
            map_color[i->first] = "\e[0;31m";
        else if (map_fr[i->first] < 0.4)
            map_color[i->first] = "\e[0;32m";
        else if (map_fr[i->first] < 0.6)
            map_color[i->first] = "\e[0;33m";
        else if (map_fr[i->first] < 0.8)
            map_color[i->first] = "\e[0;34m";
        else if (map_fr[i->first] <= 1.0)
            map_color[i->first] = "\e[0;35m";
    }


    for (std::map<char, int>::iterator i = mymap.begin(); i != mymap.end(); ++i) {
        std::cout << i->first << " " << i->second << std::endl;
    }

    for (std::map<char, double>::iterator i = map_fr.begin(); i != map_fr.end(); ++i) {
        std::cout << i->first << " " << i->second << std::endl;
    }
    in.open(argv[1]);

    if (!in.good())
        return 3;

    while (in.good()) {
        in >> ch;
        std::cout << map_color[ch] << ch << "\e[0m";
    }
    return 0;
}
