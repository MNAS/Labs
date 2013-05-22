#ifndef __SORT_H__
#define __SORT_H__

///Сортировка методом вставки. 
void sortVstavkaInt(int size, int *array);

///Сортировка методом вставки. 
void sortVstavkaChar(int size, char *array);

///Сортировка методом слияния.
void mergeSort(int size, int *array);

///Возведение числа v в степень p перемножением.
int i_pow(int v, int p);

void print_arrInt(int N,int *array);

void print_arrChar(int N,char *array);

void initArrInt(int N,int *array);

void initArrChar(int N,char *array);

///Слияние двух отсортированных массивов A[m] и B[n] с помещением результата в C.
///Память под массив C должна быть предварительно распределена.
void merge( int *A, int *B, int *C, int m, int n );

#endif /* __SORT_H__ */
