#include <math.h>
#include "vector.h"
#include "matrix.h"
#include "chisl_5.h"

void fx(double a, double b, int n, double *x)
{
    int i;
    for (i=1; i<=n; ++i)
        x[i-1]=a+(i-1)*(b-a)/(n-1);

}

void fy(double *x, double *y, int n)
{
    int i;
    for (i=0; i<n; ++i)
        y[i]=f(x[i]);
}

double f(double x)
{
    return log(x+1.0);
}

double eytken(double *x, double *y, int n, double X)
{
    int i,j;

    double L[n][n];
    double *pL[n];

    for ( i=0; i<n; ++i )
    {
        pL[i]=&L[i][0];
        for ( j=0; j<n; ++j)
            L[i][j]=0.0;
    }
//     vivod_matr ( pL,n,n,"L");
    for(i=0; i<n; ++i)
        L[0][i]=y[i];
//     vivod ( L[0], n, "L");
    for (j=1; j<n; ++j)
    {
        for(i=0; i<n-j; ++i)
        {
            L[j][i]=1.0/(x[i+j]-x[i])*
                    (L[j-1][i]*(x[i+j]-X) - L[j-1][i+1]*(x[i]-X));
        }
// 	vivod_matr ( pL,n,n,"L");
    }
//     vivod_matr ( pL,n,n,"L");
    return L[n-1][0];
}
















