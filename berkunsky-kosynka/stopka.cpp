#include "stopka.h"
#include <iostream>

int Stopka::numStopok=7;

Stopka::Stopka()
{

}

Stopka::Stopka(const Stopka& other)
{

}

Stopka::~Stopka()
{

}

Stopka& Stopka::operator=(const Stopka& other)
{

}

bool Stopka::operator==(const Stopka& other)
{

}

void Stopka::output() 
{
    int size = stopka.size();
    for(int i=0; i<size; ++i) {
        stopka.at(i)->output();
        std::cout<<" ";
    }
    std::cout<<"\n"; 
    std::cout.flush();
}

void Stopka::openLastCard() 
{
    if(stopka.empty()) return;
    stopka.at(stopka.size()-1)->setSostoyanie(1);
}

Card* Stopka::getLastCard() 
{
    if(stopka.empty()) return NULL;
    return stopka.at(stopka.size()-1);    
}

Card* Stopka::getFirstCard() 
{
    if(stopka.empty()) return NULL;
    return stopka.at(0);
}

void Stopka::closeCards() 
{
    int size=stopka.size();
    for(int i=0; i<size; ++i)
        stopka.at(i)->setSostoyanie(0);
}

void Stopka::StopkaStopka() 
{

}

void Stopka::StopkaDom() {

}
