#include "Arc.h"
#include <stdio.h> 
#include <math.h> 

Arc::Arc()
{
    x=0.0;
    y=0.0;
    r=0.0;
}

Arc::Arc(double X, double Y,double R)
{
    x=X;
    y=Y;
    r=R;
}

Arc::Arc(Point A,double R)
{
    x=A.x;
    y=A.y;
    r=R;
}

Arc::Arc(const Arc&Ar)
{
    x=Ar.x;
    y=Ar.y;
    r=Ar.r;

}

Arc& Arc::operator=(const Arc&Ar)
{
    x=Ar.x;
    y=Ar.y;
    r=Ar.r;
    return *this;
}

void Arc::output()
{
  Point::output();
  printf(" %f",r); 
}

void Arc::input()
{
  Point::input();
  printf("Enter r:");
  scanf("%lf",&r); 
}

double Arc::segArea(double R,double angle)
{
  return 0.5*R*R*(angle-sin(angle));
}

double Arc::segArea(double angle)
{
  return segArea(r,angle);
}