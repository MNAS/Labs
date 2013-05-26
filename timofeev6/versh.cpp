#include "graph.h"
#include <iostream>

int Vertex::counter=0;

Vertex::Vertex() {
    index=++counter;
    name=0;
}

Vertex::~Vertex()
{
}

void Vertex::output()
{
    std::cout<<"Versh:"<<name<<" "<<index<<std::endl;
}
