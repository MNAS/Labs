#ifndef DOM_H
#define DOM_H
#include <iostream>
#include "stopka.h"

class Dom
{
public:
    Stopka *A;
    Stopka *B;
    Stopka *C;
    Stopka *D;
public:
    Dom();
    Dom(const Dom& other);
    ~Dom();
    Dom& operator=(const Dom& other);
    bool operator==(const Dom& other);
    
//    void output();
private:
    friend std::ostream& operator<<(std::ostream & os, Dom & d);
};
#endif // DOM_H
