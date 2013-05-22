#include "graf.h"
#include <iostream>

int Versh::counter=0;

Versh::Versh() {
    index=++counter;
    name=0;
}

Versh::~Versh()
{
}

void Versh::output()
{
    std::cout<<"Versh:"<<name<<" "<<index<<std::endl;
}
