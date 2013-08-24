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
    os<<"Дом\n";

    if(d.A->cards->empty()) os<<"--\n";
    else os<<(*d.A);

    if(d.B->cards->empty()) os<<"--\n";
    else os<<(*d.B);

    if(d.C->cards->empty())  os<<"--\n";
    else os<<(*d.C);

    if(d.D->cards->empty())  os<<"--";
    else os<<(*d.D);

    os<<"\n";
    os.flush();
    return os;
}