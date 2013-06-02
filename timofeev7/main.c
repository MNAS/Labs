#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int main (int argc, char* argv[])
{

    int i;
    int N;//=100000;
    int loops;//=10;
    int arr[100000];
    int arr_1[100000];

    char brr[100000];
    char brr_1[100000];

    switch(argc)
    {
    case 1:
        printf("Usage: %s n_sorted_elements n_loops\n", argv[0]);
        return 1;
    case 2:
        printf("Usage: %s n_sorted_elements n_loops\n", argv[0]);
        return 1;
    case 3:
        N=atoi(argv[1]);
        loops=atoi(argv[2]);
        break;
    default:
        N=100000;
        loops=10;
        break;
    }
    printf("N=%d; loops=%d\n", N,loops);

    initArrInt(N,arr_1);
    initArrChar(N,brr_1);
    for(i=0; i<N; ++i)
    {   arr[i]=arr_1[i];
        brr[i]=brr_1[i];
    }

    printf("Method of sorting Sliyanie(int)calloc-free -> ");
    detectTimeInt(callFreeInt,N,arr,loops);
    printf("\n");

    printf("Method of sorting Sliyanie(char)calloc-free -> ");
    detectTimeChar(callFreeChar,N,brr,loops);
    printf("\n");

    printf("Method of sorting Sliyanie(int) -> ");
    detectTimeInt(mergeSortInt,N,arr,loops);
    //  print_arrInt(N,arr);
    printf("\n");

    printf("Method of sorting Sliyanie(char) -> ");
    detectTimeChar(mergeSortChar,N,brr,loops);
    //  print_arrChar(N,brr);
    printf("\n");

    for(i=0; i<N; ++i)
    {
        arr[i]=arr_1[i];
        brr[i]=brr_1[i];
    }

    printf("Method of sorting Vstavka(int) -> ");
    detectTimeInt(sortVstavkaInt,N,arr,loops);
//  print_arrInt(N,arr);
    printf("\n");

    printf("Method of sortingVstavka(char) -> ");
    detectTimeChar(sortVstavkaChar,N,brr,loops);
    //  print_arrChar(N,brr);
    printf("\n");

    return 0;
}
