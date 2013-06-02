#ifndef __SORT_H__
#define __SORT_H__

///Сортировка методом вставки целочисленного массива. 
void sortVstavkaInt(int size, int *array, int loops);

///Сортировка методом вставки символьного массива. 
void sortVstavkaChar(int size, char *array, int loops);

///Сортировка методом слияния целочисленного массива.
void mergeSortInt(int size, int *array, int loops);

///Сортировка методом слияния символьного массива.
void mergeSortChar(int size, char *array, int loops);


///Оценка времени распределения-освобождения памяти под int.
void callFreeInt(int size, int *array, int loops);

///Оценка времени распределения-освобождения памяти под char.
void callFreeChar(int size, char *array, int loops);

///Возведение числа v в степень p перемножением.
int i_pow(int v, int p);

///Вывод на экран целочисленного массива
void print_arrInt(int N,int *array);

///Вывод на экран символьного массива
void print_arrChar(int N,char *array);

///Заполнение целочисленного массива случайными числами
void initArrInt(int N,int *array);

///Заполнение символьного массива случайными числами
void initArrChar(int N,char *array);

///Слияние двух отсортированных массивов A[m] и B[n] с помещением результата в C.
///Память под массив C должна быть предварительно распределена.
void merge( int *A, int *B, int *C, int m, int n );

void detectTimeInt(void(*foo)(int, int*, int),int size, int *array, int n);
void detectTimeChar(void(*foo)(int, char*, int),int size, char *array, int n);

#endif /* __SORT_H__ */
