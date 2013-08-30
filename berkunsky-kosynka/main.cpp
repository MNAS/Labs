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
    Stol *st=new Stol;
    st->loop();
//    Card a(std::string("5d"));
//    Card b(std::string("5d"));
//    std::cout<<"a="<<a<<" "<<"b="<<b<<std::endl;
//    a==b;
//    std::cout<<(a==b)<<std::endl;
}
