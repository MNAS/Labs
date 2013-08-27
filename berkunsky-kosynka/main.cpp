#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include "stol.h"


int main() 
{
//    std::string s="assa  to  massa ";
//    std::vector<std::string> vs;
//    boost::split(vs,s,boost::is_any_of(" "), boost::token_compress_on);
//    int sz=vs.size();
//    for(int i=0;i<sz;++i)
//    {
//	std::cout<<vs.at(i)<<"\n";
//    }
//     boost::random::mt19937 gen(std::time(0));
//     boost::random::uniform_int_distribution<> dist(1, 52);
//    Koloda* k=new Koloda;
//    k->cardsFaceUp();
//    std::cout<<(*k);
//    k->peretosovat();
//    std::cout<<(*k);
    Stol *st=new Stol;
    st->loop();
//    std::cout<<(*st);
//     for(int i = 0; i < 52; ++i) 
//     {
//       std::cout << dist(gen)<<"\n";
//     }
//     std::cout << std::endl;
}
