#include <stdio.h>
#include "Point.h"
#include "Romb.h"
#include "Arc.h"
#include "Moon.h"

int main()
{
    Romb Rb;
    Rb.input();
    Rb.output();
    printf("%f\n",Rb.perimetr());
    printf("%f\n",Rb.area());

    Moon Mn;
    Mn.input();
    Mn.output();
    printf("%f\n",Mn.perimetr());
    printf("%f\n",Mn.area());
    return 0;
}



// {
//     Point A;
//     Point B(5,6);
//     Point C;
//     Arc a;
//     Arc b(10,20,30);
//     Arc c(b);
//     Arc d(B,15);
// 
//     a.input();
// 
//     a.output();
//     printf("\n");
//     b.output();
//     printf("\n");
//     c.output();
//     printf("\n");
//     d.output();
//     printf("\n");
// 
// 
//     A.output();
//     B.output();
//     C.input();
//     C.output();
//     printf("Distance=%f\n",B.distance(C));
// }

