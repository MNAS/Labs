#include "stopka.h"
#include <iostream>

int Stopka::numStopok=7;

Stopka::Stopka():cards(0)
{
    cards = new std::vector<Card*>;
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

/*
void Stopka::output()
{
    int size = cards->size();
    for(int i=0; i<size; ++i) {
        cards->at(i)->output();
        std::cout<<" ";
    }
    std::cout<<"\n";
    std::cout.flush();
}
*/

std::ostream & operator<<(std::ostream &os, Stopka &s)
{
    int size = s.cards->size();
    for(int i=0; i<size; ++i) 
    {
        os<<*s.cards->at(i);//->output();
        os<<" ";
    }
    os<<"\n";
    os.flush();
}

void Stopka::openLastCard()
{
    if(cards->empty()) return;
    cards->at(cards->size()-1)->setSostoyanie(1);
}

Card* Stopka::getLastCard()
{
    if(cards->empty()) return NULL;
    return cards->at(cards->size()-1);
}

Card* Stopka::getFirstCard()
{
    if(cards->empty()) return NULL;
    return cards->at(0);
}

void Stopka::closeCards()
{
    int size=cards->size();
    for(int i=0; i<size; ++i)
        cards->at(i)->setSostoyanie(0);
}

void Stopka::StopkaStopka()
{

}

void Stopka::StopkaDom() {

}
