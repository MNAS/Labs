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
}
