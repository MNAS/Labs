#include "koloda.h"

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <iostream>
#include <ctime>
#include <algorithm>

int Koloda::N=52;

Koloda::Koloda ( const Koloda& other )
{

}

Koloda::~Koloda()
{

}

Koloda& Koloda::operator= ( const Koloda& other )
{

}

bool Koloda::operator== ( const Koloda& other )
{

}


Koloda::Koloda()
{
        fillKoloda();
}

int Koloda::getN()
{
        return N;
}

std::vector<Card*>* Koloda::getKoloda()
{
        return &cards;
}


void Koloda::fillKoloda()
{
        int c=0;
        for ( int i=0; i<Card::numMast; ++i ) {
                for ( int j=1; j<=Card::numStarsh; ++j ) {
                        Card* a=new Card ( i,j,0 );
                        cards.push_back ( a );
                        ++c;
                }
        }
}

void Koloda::peretosovat()
{
        boost::random::mt19937 gen ( std::time ( 0 ) );
        boost::random::uniform_int_distribution<> dist ( 0, Koloda::N-1 );
        int a, b;	///<Промежуточные переменные,содержащие случайные числа.
        Card *c=NULL;
        for ( int i=0; i<100; ++i ) {
                a= ( int ) dist ( gen );
                b= ( int ) dist ( gen );
                c=cards[a];
                cards[a]=cards[b];
                cards[b]=c;
        }
}

void Koloda::cardsFaceUp()
{
        for_each ( cards.begin(), cards.end(), faceToUp );
}



void Koloda::cardsFaceDown()
{
        for_each ( cards.begin(), cards.end(), faceToDown );
}

std::ostream& operator<< ( std::ostream & os, const Koloda & k )
{
        for ( int i=0; i<Koloda::N; ++i ) {
                os<<i<<" ";
                os<<* ( k.cards.at ( i ) ) <<"\n";
        }
        return os;
}
