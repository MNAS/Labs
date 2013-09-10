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
    
    std::vector<Card*> *cards;	///<Вектор указателей на карты составляющие стопку.

    void openLastCard();	///<Перевернуть последнюю карту в стопке лицом вверх.
    Card * getLastCard();
    Card * getFirstCard();
    void closeCards();		///<Перевернуть все карты в стопке рубашкой вверх.
    bool isAllOpend();		///<Возвращает true если все карты стопки перевернуты лицом вверх.
private:
    friend std::ostream & operator<<(std::ostream & os, Stopka & s);
};

#endif // STOPKA_H
