#include <stdio.h>
#include "chisl_5.h"
#include "vector.h"

int main()
{
    double a=0.0, b=11.0, h=0.5, X;
    int n =6;

    double x[6], y[6];
    fx(a,b,n,x);
    vivod ( x, n, "X");
    fy(x,y,n);
    vivod ( y, n, "Y");
    X=a;
    eytken(x,y,n,3.5);
    while(X<=b)
    {
      printf("X=%f eytken=%f f(X)=%f\n",X,eytken(x,y,n,X),f(X));
      X+=h;
    }
    return 0;
}

