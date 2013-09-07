#ifndef SDACHA_H
#define SDACHA_H

#include <iostream>
#include "stopka.h"

class Sdacha
{
    friend std::ostream &operator<<(std::ostream &os, Sdacha &sd);
public:
    Stopka *opened;	///<Открытая часть
    Stopka *closed;	///<Закрытая часть

public:
    Sdacha();
    Sdacha(const Sdacha &other);
    ~Sdacha();
    Sdacha &operator=(const Sdacha &other);
    bool operator==(const Sdacha &other);
};
#endif // SDACHA_H
