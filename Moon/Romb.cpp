#include "Romb.h"
#include <stdio.h>
#include <math.h>

Romb::Romb():
    centre(),
    angle(0.0),
    d1(5),
    d2(3)
{

}

Romb::Romb(const Point &f, double Angle, double D1, double D2)
{
    centre=f;
    /*double a=Angle%360;
    if(a<0)
    	angle=a+360;///<усли остаток от деления на 360 отрицательный,то +360 градусов
    else
    	angle=a;*/
    angle=Angle;
    d1=fabs(D1);
    d2=fabs(D2);
}

void Romb::output()
{
    printf("Romb:\n");
    printf("Centre:");
    centre.output();
    printf("\n");
    printf("Angle:%f\n",angle);
    printf("Diagonal 1:%f\n",d1);
    printf("Diagonal 2:%f\n",d2);

}

void Romb::input()
{
    printf("Romb:\n");
    printf("Enter centre:\n");
    centre.input();
    printf("Enter angle:\n");
    scanf("%f",&angle);
    printf("Enter diagonal 1 lenth:\n");
    scanf("%lf",&d1);
    printf("Enter diagonal 2 lenth:\n");
    scanf("%lf",&d2);

}

double Romb::perimetr()
{
    double a=d1/2;
    double b=d2/2;
    double c=sqrt(a*a+b*b);
    return c*4;
}

double Romb::area()
{
    return d1*d2/2;
}
