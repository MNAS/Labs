#include "graph.h"
#include <iostream>

Rib::Rib()
{
    weight=0;
    start=0;
    end=0;
}

Rib::~Rib()
{

}

void Rib::output()
{
    std::cout<<"Rib:"<<weight<<" "
             <<start->getName()<<" "<<start->getIndex()<<" "
             <<end->getName()<<" "<<end->getIndex()<<std::endl;
}
