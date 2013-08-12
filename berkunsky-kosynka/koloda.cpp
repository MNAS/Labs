#include "koloda.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <iostream>
#include <ctime>

int Koloda::N=52;

Koloda::Koloda(const Koloda& other)
{

}

Koloda::~Koloda()
{

}

Koloda& Koloda::operator=(const Koloda& other)
{

}

bool Koloda::operator==(const Koloda& other)
{

}


Koloda::Koloda()
{
    fillKoloda();
}

int Koloda::getN() {
    return N;
}

std::vector<Card*>* Koloda::getKoloda() {
    return &koloda;
}


void Koloda::fillKoloda() {

    int c=0;
    for(int i=0; i<Card::numMast; ++i) {
        for(int j=0; j<Card::numStarsh; ++j) {
            Card* a=new Card(i,j,0);
            koloda[c++]=a;
        }
    }
}

void Koloda::peretosovat() 
{
    boost::random::mt19937 gen(std::time(0));
    boost::random::uniform_int_distribution<> dist(0, Koloda::N-1);
    int a, b;	///<Промежуточные переменные,содержащие случайные числа.
    Card *c=NULL;
    for(int i=0; i<100; ++i) 
    {
        a=(int) dist(gen);
        b=(int) dist(gen);
        c=koloda[a];
        koloda[a]=koloda[b];
        koloda[b]=c;
    }
}

void Koloda::output() 
{
    for(int i=0; i<N; ++i) 
    {
        std::cout<<" "<<i;
        koloda[i]->output();
    }
  
}

