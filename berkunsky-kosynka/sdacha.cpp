#include "sdacha.h"
#include <iostream>

Sdacha::Sdacha():opened(0),closed(0)
{
    opened = new Stopka;
    closed  = new Stopka;
}

Sdacha::Sdacha(const Sdacha& other)
{

}

Sdacha::~Sdacha()
{

}

Sdacha& Sdacha::operator=(const Sdacha& other)
{

}

bool Sdacha::operator==(const Sdacha& other)
{
    return true;
}

std::ostream & operator<<(std::ostream & os, Sdacha & sd)
{
    std::string r="qw";
    os<<"RC "<<"{"<<r.at(0)<<"}"<<" ";
    os<<(*sd.closed);
    os<<"RO "<<"{"<<r.at(1)<<"}"<<" ";
    os<<(*sd.opened);
    os.flush();
}
