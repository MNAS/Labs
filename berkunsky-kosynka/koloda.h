#ifndef KOLODA_H
#define KOLODA_H

#include "card.h"
#include <vector>
#include <ostream>

class Koloda
{
    friend std::ostream &operator<<(std::ostream &os, const Koloda &k);
private:
    static int N;		///<Количество карт в колоде.
    std::vector<Card *> cards;	///<Карты колоды.
public:
    Koloda(const Koloda &other);
    ~Koloda();
    Koloda &operator=(const Koloda &other);
    bool operator==(const Koloda &other);

    Koloda();
    int getN();			///<Возвращает количество карт в колоде.
    std::vector<Card *> *getKoloda();
    void fillKoloda();		///<Заполнение колоды картами.
    void peretosovat();		///<Перетасовать карты.
    void cardsFaceUp();		///<Переворачивает все карты колоды лицами вверх.
    void cardsFaceDown();	///<Переворачивает все карты колоды лицами вниз.
};
#endif // KOLODA_H
