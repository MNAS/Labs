#include <stdio.h> 
#include "Point.h" 
#include "Arc.h"
#include "Moon.h"

int main() 
{
 /*   Point A;
    Point B(5,6);
    Point C;
    Arc a;
    Arc b(10,20,30);
    Arc c(b);
    Arc d(B,15);
    
    a.input();
    
    a.output(); printf("\n");
    b.output(); printf("\n");
    c.output(); printf("\n");
    d.output(); printf("\n");
    
   
    
    
    
    
    A.output();
    B.output();
    C.input();
    C.output();
    printf("Distance=%f\n",B.distance(C));
*/  
    Moon Aa;
    Aa.input();
    Aa.output();
    printf("%f\n",Aa.perimetr());
    printf("%f\n",Aa.area());
    return 0;
}
