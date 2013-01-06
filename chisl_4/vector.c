#include <stdio.h>
#include <math.h>

int vecscal ( double scal, double * vector,int rasmer, double * vector_res, int *rasmer_res)//передача в функцию числа,вектора и его размеров,результирующего вектора и его размеров
{

	int i;
	*rasmer_res=rasmer;//присвоение результирующему вектору размеров исходного
	for ( i=0; i<rasmer; ++i ) {
		vector_res[i]=scal*vector[i];//поэлементное умножение на число
	}
	return 0;
}

void vivod ( double * vector,int rasmer, char* msg )//передача вектора и его размеров,поля для сопровождающего сообщения
{
	int i;
	printf ( "\n%s[%i]:", msg, rasmer);
	for ( i=0; i<rasmer; ++i ) 
	{
		printf ( "\t%f",vector[i] );//вывод элементов вектора
	}
	printf ( "\n");
}

int vecsum (double *vector_a,int rasmer_a, 
			double * vector_b, int rasmer_b,
			double * vector_res, int *rasmer_res )//передача двух векторов и их размеров,а также результирующего вектора и его размеров
{
	int i;
	if(rasmer_a!=rasmer_b)//проверка на равенство размеров векторов
	{
		*rasmer_res=0;
		printf("Vector summ is not able\n");
		return 1;
	}
	*rasmer_res=rasmer_a;
	for ( i=0; i<rasmer_a; ++i ) {
		vector_res[i]=vector_a[i]+vector_b[i];//поэлементное суммирование 
	}
	return 0;
}

int vecmin (double *vector_a,int rasmer_a, 
			double * vector_b, int rasmer_b,
			double * vector_res, int *rasmer_res )//передача двух векторов и их размеров,а также результирующего вектора и его размеров
{
	int i;
	if(rasmer_a!=rasmer_b)//проверка на равенство размеров векторов
	{
		*rasmer_res=0;
		printf("Vector summ is not able\n");
		return 1;
	}
	*rasmer_res=rasmer_a;
	for ( i=0; i<rasmer_a; ++i ) {
		vector_res[i]=vector_a[i]-vector_b[i];//поэлементное суммирование 
	}
	return 0;
}

double scalmnog ( double *vector_a,int rasmer_a,double * vector_b,int rasmer_b)//передача 2х векторов и их размеров
{
	int i;
	double sum=0;
	if(rasmer_a!=rasmer_b)//проверка на равенство размеров векторов
	{
		sum=0;
		printf("Scal mult is not able\n");
		return 0;
	}
	for ( i=0; i<rasmer_a; ++i ) {
		sum+=vector_a[i]*vector_b[i];//суммирование произведения элементов векторов
	}
	return sum;
}

double modul_vec ( double *vector_a, int rasmer_a)//передача вектора и его размера
{
	int i;
	double res=0;//обнуление переменных, в которых будет храниться результат
	double sum=0;
	for ( i=0; i<rasmer_a; ++i ) {
		sum+=vector_a[i]*vector_a[i];//суммирование квадратов элементов
	}
	res=sqrt ( sum );//извлечение корня
	return res;
}

void input(double *vector,int *razmer)//передача вектора и его размера
{
	int i;
	printf("\nEnter vector size=");
	scanf("%d",razmer);//ввод размера вектора
	printf("\nEnter vector:\n");
	for(i=0;i<*razmer;++i)
		vector[i]=0;//обнуление вектора
	for(i=0;i<*razmer;++i)
	{		
		printf("\nVector[%i]=",i);
		scanf("%lf",&vector[i]);//ввод элементов вектора
		vivod(vector,*razmer,"V");
	}
}


