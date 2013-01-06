#include "Point.h" 
#include <stdio.h> 
#include <math.h> 

Point::Point()
{
  x=0.0;
  y=0.0;
}

Point::Point(double X, double Y)
{
  x=X;
  y=Y;
}

Point::~Point()
{  
}

void Point::output()
{
  printf("%f %f",x,y); 
}

void Point::input()
{
  printf("Enter x:");
  scanf("%lf",&x); 
  
  printf("Enter y:");
  scanf("%lf",&y); 
}

double Point::distance(Point A)
{
  return sqrt((A.x-x)*(A.x-x)+(A.y-y)*(A.y-y));
}

