#include <stdio.h> 
#include "Point.h" 
#include "Romb.h"
#include "Arc.h"
#include "Moon.h"

int main() 
{
  Point a;
    Romb Aa;
     Aa.input();
     Aa.output();
     printf("%f\n",Aa.perimetr());
     printf("%f\n",Aa.area());
    return 0;
}
