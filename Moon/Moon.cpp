#include "Moon.h"
#include <stdio.h>
#include <math.h>

Moon::Moon():first(10,10,30)
{
    second.x=20;
    second.y=20;
    second.r=20;
}

Moon::Moon(const Arc &f,const Arc &s):first(f)
{
    second=s;
}

double Moon::area()
{
    double a=first.distance(second);
    double b=first.r;
    double c=second.r;

    if(b+c>a && (b>c?b:c)-(b<c?b:c)<a)
    {
        double betta=acos(-(b*b-a*a-c*c)/(2.0*a*c));
        double gamma=acos(-(c*c-a*a-b*b)/(2.0*a*b));
        return M_PI*c*c-Arc::segArea(b,gamma*2.0)-Arc::segArea(c,betta*2.0);
    }
    else
        return 0.0;
}

double Moon::perimetr()
{
    double a=first.distance(second);
    double b=first.r;
    double c=second.r;

    if(b+c>a && (b>c?b:c)-(b<c?b:c)<a)
    {
        double betta=acos(-(b*b-a*a-c*c)/(2.0*a*c));
        double gamma=acos(-(c*c-a*a-b*b)/(2.0*a*b));
        return 2.0*gamma*b+2.0*M_PI*c-2.0*betta*c;
    }
    else
        return 0.0;
}

void Moon::output()
{
    printf("Moon:\n");
    printf("First arc:");
    first.output();
    printf("\n");
    printf("Second arc:");
    second.output();
    printf("\n");
}

void Moon::input()
{
    printf("Moon:\n");
    printf("First arc:\n");
    first.input();
    printf("Second arc:\n");
    second.input();
}