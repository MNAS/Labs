#include "dom.h"
#include <iostream>

Dom::Dom()
{
    A=new Stopka;
    B=new Stopka;
    C=new Stopka;
    D=new Stopka;
}

Dom::Dom(const Dom& other)
{

}

Dom::~Dom()
{

}

Dom& Dom::operator=(const Dom& other)
{

}

bool Dom::operator==(const Dom& other)
{

}

std::ostream & operator<<(std::ostream & os, Dom & d)
{
    std::string h="zxcv";
    os<<"H "<<"{"<<h.at(0)<<"}"<<" ";
    if(d.A->cards->empty()) os<<"--\n";
    else os<<(*d.A);
    
    os<<"H "<<"{"<<h.at(1)<<"}"<<" ";
    if(d.B->cards->empty()) os<<"--\n";
    else os<<(*d.B);
    
    os<<"H "<<"{"<<h.at(2)<<"}"<<" ";
    if(d.C->cards->empty())  os<<"--\n";
    else os<<(*d.C);

    os<<"H "<<"{"<<h.at(3)<<"}"<<" ";
    if(d.D->cards->empty())  os<<"--";
    else os<<(*d.D);

    os<<"\n";
    os.flush();
    return os;
}