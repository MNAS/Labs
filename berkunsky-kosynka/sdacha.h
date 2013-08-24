#ifndef SDACHA_H
#define SDACHA_H

#include <iostream>
#include "stopka.h"

class Sdacha
{
public:
  Stopka *opened;	///<Открытая часть
  Stopka *closed;	///<Закрытая часть
  
public:
    Sdacha();
    Sdacha(const Sdacha& other);
    ~Sdacha();
    Sdacha& operator=(const Sdacha& other);
    bool operator==(const Sdacha& other);
    
    void output();
private:
    friend std::ostream & operator<<(std::ostream & os, Sdacha & sd);

};
#endif // SDACHA_H
