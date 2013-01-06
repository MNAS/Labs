#ifndef VECTOR_H
#define VECTOR_H
///Произведение скаляра на вектор.
int vecscal ( double scal, double * vector,int rasmer, double * vector_res, int *rasmer_res);

///Вывод вектора на печать.
void vivod ( double * vector,int rasmer, char* msg );

///Сумма двух векторов.
int vecsum (double *vector_a,int rasmer_a, 
			double * vector_b, int rasmer_b,
			double * vector_res, int *rasmer_res );

///Сумма двух векторов.
int vecmin (double *vector_a,int rasmer_a, 
			double * vector_b, int rasmer_b,
			double * vector_res, int *rasmer_res );


///Скалярное произведение векторов.
double scalmnog ( double *vector_a,int rasmer_a,double * vector_b,int rasmer_b);

///Определение модуля вектора.
double modul_vec ( double *vector_a, int rasmer_a);

///Ввод вектора
void input(double *vector,int *razmer);

#endif
