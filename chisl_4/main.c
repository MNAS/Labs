#include "matrix.h"
#include "vector.h"
#include "stdio.h"
#include "math.h"

int main(int argc, char **argv)
{
    int sz=50;
    int i;

    double A[sz][sz];
    int A_row,A_col;
    double *pA[sz];
    for ( i=0; i<sz; ++i ) pA[i]=&A[i][0];

    double b[sz]; int b_sz;
    double bp[sz]; int bp_sz; //для проверки

    double r1[sz];
    int r1_sz;
    double r2[sz];
    int r2_sz;
    double r3[sz];
    int r3_sz;
    double r4[sz];
    int r4_sz;

    input_matr(pA,&A_row,&A_col);
    vivod_matr(pA,A_row,A_col,"A");

    input(b,&b_sz);
    vivod(b,b_sz,"b");

    double x[sz];
    int x_sz=b_sz;

    for(i=0; i<sz; i++) x[i]=10;

    for(i=0; i<100; ++i)
    {
        printf("Итерация = %d\t",i);
        vivod(x,x_sz,"x");

        mnog_vec_matr (x, x_sz, pA, A_row,A_col, r1, &r1_sz); //r1=A*x
//         vivod(r1,r1_sz,"r1");

        vecmin(r1,r1_sz,b,b_sz,r2,&r2_sz);//(rk=)r2=r1-b=A*x-b
//         vivod(r2,r2_sz,"r2");

        mnog_vec_matr (r2, r2_sz, pA, A_row, A_col, r3, &r3_sz);//r3=A*rk
//         vivod(r3,r3_sz,"r3");

        double chisl= scalmnog ( r2,r2_sz,r2,r2_sz);//chisl=r2*r2
//         printf("chisl=%fl\n",chisl);

        double zn = scalmnog ( r2,r2_sz,r3,r3_sz);//zn=r2*r3
//         printf("zn=%f\n",zn);

        double a=chisl/zn;
//         printf("a=%f\n",a);

        vecscal (a,r2,r2_sz,r4,&r4_sz);//r4=a*rk
//         vivod(r4,r4_sz,"r4");

        vecmin(x,x_sz,r4,r4_sz,x,&x_sz);
        vivod(x,x_sz,"x");
    }
    mnog_vec_matr(x,x_sz,pA,A_row,A_col,bp,&bp_sz);
    vivod(b,b_sz,"b");
    vivod(bp,bp_sz,"bp");
    return 0;
}
