#include "card.h"
#include <iterator>
#include <iostream>
#include <boost/lexical_cast.hpp>

int Card::numMast = 4;
int Card::numStarsh = 13;

Card::Card() : mast(2), starshinstvo(6), sostoyanie(1)
{}

Card::Card(int a_mast, int a_starshinstvo, int a_sostoyanie)
    : mast(a_mast)
    , starshinstvo(a_starshinstvo)
    , sostoyanie(a_sostoyanie)
{}

bool Card::isBlack()
{
    if (getMast() < 2)
        return true;
    return false;
}

bool Card::isRed()
{
    return !isBlack();
}

void Card::setMast(int a_mast)
{
    mast = a_mast;
}

void Card::setStarshinstvo(int a_starshinstvo)
{
    starshinstvo = a_starshinstvo;
}

void Card::setSostoyanie(int a_sostoyanie)
{
    sostoyanie = a_sostoyanie;
}


int Card::getMast() const
{
    return mast;
}

int Card::getStarshinstvo() const
{
    return starshinstvo;
}

int Card::getSostoyanie() const
{
    return sostoyanie;
}

std::ostream &operator<< (std::ostream &os, const Card &C)
{
    if (C.getSostoyanie() == 0)
        std::cout << "[]";
    else
        std::cout << C.name();
    return os;
}

std::string Card::name() const
{
    std::string m ; //Масть
    std::string s ; //Старшинство

    switch (getStarshinstvo()) {
    case 13:
        s = "K";
        break;
    case 12:
        s = "Q";
        break;
    case 11:
        s = "J";
        break;
    case 10:
        s = "T";
        break;
    case 1:
        s = "A";
        break;
    default:
        s = boost::lexical_cast<std::string> (getStarshinstvo());
        break;
    }
    switch (getMast()) {
    case 0:
        m = "s";
        break;
    case 1:
        m = "c";
        break;
    case 2:
        m = "d";
        break;
    case 3:
        m = "h";
        break;
    default:
        std::cout << "Fault";
        std::cout.flush();
        break;
    }
    return s + m;

}

std::string Card::toString() const
{
    std::string rez = "Card{";
    rez += "mast=" + boost::lexical_cast<std::string> (mast) + ", starshinstvo=" +
           boost::lexical_cast<std::string> (starshinstvo) + ", sostoyanie=" +
           boost::lexical_cast<std::string> (sostoyanie) + '}';
    return rez ;
}


void faceToUp(Card *i)
{
    i->setSostoyanie(1);
}
void faceToDown(Card *i)
{
    i->setSostoyanie(0);
}

void toStream(Card *c)
{

}