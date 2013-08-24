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

/*
void Sdacha::output()
{
    std::cout<<"Sdacha.Closed ";
    closed->output();
    std::cout<<"\n";
    std::cout.flush();

    std::cout<<"Sdacha.Opened ";
    opened->output();
    std::cout<<"\n";
    std::cout.flush();
}
*/

std::ostream & operator<<(std::ostream & os, Sdacha & sd)
{
    os<<"Сдача.Закрытая ";
    os<<(*sd.closed);//->output();
    os<<"\n";
    std::cout<<"Сдача.Открытая ";
    os<<(*sd.opened);//->output();
    os<<"\n";
    os.flush();
}