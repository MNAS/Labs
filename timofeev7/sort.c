#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int i_pow(int v, int p)
{
    if(p<0) return 0;

    int i, rez=1;
    for(i=0; i<p; ++i) rez*=v;
    return rez;
}

void sortVstavkaInt(int size, int *array)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] < temp)
                break;
            array[j+1] = array[j];
            array[j]= temp;
        }
    }

}

void sortVstavkaChar(int size, char *array)
{
    int i, j, temp;
    for (i = 1; i < size; i++)
    {
        temp = array[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (array[j] < temp)
                break;
            array[j+1] = array[j];
            array[j]= temp;
        }
    }

}

void print_arrInt(int N,int *array)
{
    int i;
    for(i=0; i<N; i++) printf(" %i ",array[i]);
    printf("\n");
}

void print_arrChar(int N,char *array)
{
    int i;
    for(i=0; i<N; i++)
        printf(" %c ",array[i]);
    printf("\n");
}

void initArrInt(int N,int *array)
{
    int i;
    for(i=0; i<N; ++i) array[i]=rand()%360;
}

void initArrChar(int N,char *array)
{
    int i;
    for(i=0; i<N; ++i)
        array[i]=rand()%39+61;
}

void merge( int *a, int *b, int *c, int m, int n )
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n)
    {
        if( a[i] < b[j] )
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while ( i < m )
        c[k++] = a[i++];
    while ( j < n )
        c[k++] = b[j++];
}

void mergeSort(int size, int *array)
{
    int i,j;

    int *w =calloc(size,sizeof(int));		//Указатель на промежуточный массив.
    int *b1=array;				//Промежуточный массив из которого берутся данные.
    int *b2=w;					//Промежуточный массив в который вставляются данные.

    i=1;
    int num=0;					//Количество шагов сортировки.

    while(i<size) i=i*2, ++num;

    printf("num=%d\n",num);

    for(i=0; i<num; ++i)
    {
        int numElem=i_pow(2,i);			//Количество элементов в группах сравнений
        int numDel=size/i_pow(2,i+1);
        printf("numDel=%d\n",numDel);
        j=0;
        while(2*j*numElem<size)
        {
            int startArr1=2*j*numElem;		//Смещение первой части от начала массива b1
            int sizeArr1=0;			//Количество элементов в первой части.
            sizeArr1=(size-startArr1<numElem)?size-startArr1:numElem;

            int startArr2=(2*j+1)*numElem;	//Смещение второй части от начала массива b1
            int sizeArr2=0;			//Количество элементов во второй части.
            sizeArr2=(size-startArr2<numElem)?size-startArr2:numElem;

            int startArr3=2*j*numElem;		//Смещение отсортированных данных от начала массива b2

            merge(b1+startArr1,b1+startArr2,b2+startArr3,sizeArr1,sizeArr2);
            ++j;
        }
        int *b3=b2;
        b2=b1;
        b1=b3;//Перестановка виртуальных буферов местами для выполнения следующего шага сортировки.
    }
    if(array==b2)
        for(i=0; i<size; ++i)
            array[i]=b1[i];
    free(w);
}