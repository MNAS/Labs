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
    std::cout<<"Rib:";
    start->output();
    std::cout<<"->";
    end->output();
    std::cout<<"; Weight="<<weight;
    std::cout.flush();
}
