#ifndef STOPKA_H
#define STOPKA_H

#include <iostream>
#include <vector>
#include "card.h"

class Stopka
{
public:
    Stopka();
    Stopka(const Stopka& other);
    ~Stopka();
    Stopka& operator=(const Stopka& other);
    bool operator==(const Stopka& other);
    
    std::vector<Card*> *cards;

    static int numStopok;	///< Количество стопок.

    void output();
    void openLastCard();
    Card * getLastCard();
    Card * getFirstCard();
    void closeCards();
private:
    void StopkaStopka();
    void StopkaDom();
    friend std::ostream & operator<<(std::ostream & os, Stopka & s);
};



#endif // STOPKA_H
