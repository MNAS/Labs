#ifndef DOM_H
#define DOM_H
#include <iostream>
#include "stopka.h"

class Dom
{
    friend std::ostream &operator<<(std::ostream &os, Dom &d);
public:
    Stopka *A;
    Stopka *B;
    Stopka *C;
    Stopka *D;
public:
    Dom();
    Dom(const Dom &other);
    ~Dom();
    Dom &operator=(const Dom &other);
    bool operator==(const Dom &other);
};
#endif // DOM_H
