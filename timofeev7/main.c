#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int main ()
{
    int N=25;
    int arr[N];
    char brr[N];
    int i=0;
    clock_t start,end;
    double t;
    int n=1000000;
    int stime;
    long ltime;

    ltime=time(NULL);
    stime=(unsigned)ltime/2;
    srand(stime);

    initArrInt(N,arr);
    initArrChar(N,brr);

    printf("Method of sorting(int)\n");
    print_arrInt(N,arr);

    start=clock();
    for(i=0; i<n; ++i)
    {
        sortVstavkaInt(N,arr);
    }
    end=clock();
    t=(end-start)*1.0/CLOCKS_PER_SEC;
    print_arrInt(N,arr);
    printf("Time for sum int=%f\n",t);

    printf("\n");
    printf("Method of sorting(char)\n");
    print_arrChar(N,brr);


    start=clock();
    for(i=0; i<n; ++i)
    {
        sortVstavkaChar(N,brr);
    }
    end=clock();
    t=(end-start)*1.0/CLOCKS_PER_SEC;
    print_arrChar(N,brr);
    printf("Time for sum int=%f\n",t);

    print_arrInt(N,arr);
    mergeSort(N,arr);
    print_arrInt(N,arr);
    return 0;
}
