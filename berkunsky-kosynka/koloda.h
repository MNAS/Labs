#ifndef KOLODA_H
#define KOLODA_H
#include "card.h"
#include <vector>
#include <ostream>


class Koloda
{
private:
    static int N;
    std::vector<Card*> cards;

public:
  
    Koloda(const Koloda& other);
    ~Koloda();
    Koloda& operator=(const Koloda& other);
    bool operator==(const Koloda& other);

    Koloda();
    int getN();
    std::vector<Card*>* getKoloda();
    void fillKoloda();
    void peretosovat();
    void cardsFaceUp();		///<Переворачивает все карты колоды лицами вверх.
    void cardsFaceDown();	///<Переворачивает все карты колоды лицами вниз.
    
private:
    friend std::ostream& operator<<(std::ostream & os, const Koloda & k);
};

#endif // KOLODA_H
