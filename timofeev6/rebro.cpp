#include "graf.h"
#include <iostream>

Rebro::Rebro()
{
    weight=0;
    start=0;
    end=0;
}

Rebro::~Rebro()
{

}

void Rebro::output()
{
    std::cout<<"Rebro:"<<weight<<" "
             <<start->getName()<<" "<<start->getIndex()<<" "
             <<end->getName()<<" "<<end->getIndex()<<std::endl;
}
