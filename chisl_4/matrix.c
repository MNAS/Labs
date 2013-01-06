#include "vector.h"
#include "matrix.h"

void vivod_matr ( double * matr[],int strok,int stolb, char * msg )//передаем матрицу,кол-во строк и столбцов и поле дл€ сопровождающего сообщени€
{
  int i,j;
  printf ( "\n%s [%i][%i]", msg,strok,stolb );
  for ( i=0; i<strok; ++i )
    {
      printf ( "\n" );
      for ( j=0; j<stolb; j++ )
        printf ( "%f\t",matr[i][j] );//вывод элементов массива
    }
  printf ( "\n" );
}

void transp_matr ( double * matr[],int strok,int stolb, double * matr_res[], int *strok_res, int *stolb_res )//передача матрицы и ее размеров,а также передача результирующей матрицы с ее размерами
{
  int i,j;
  *strok_res=stolb;//присвоение результирующей матрице размеров исходной
  *stolb_res=strok;
  for ( i=0; i<strok; ++i )
    for ( j=0; j<stolb; ++j )
      matr_res[j][i]=matr[i][j];//замена местами строк и столбцов
}

void scal_matr ( double * matr[], int strok, int stolb, double * matr_res[], int *strok_res,int *stolb_res, double scal )//передача матрицы и ее размеров,передача результирующей матрицы с ее размерами,скал€р
{
  int i,j;
  *strok_res=strok;//присвоение результирующей матрице размеров исходной
  *stolb_res=stolb;
  for ( i=0; i<strok; ++i )
    for ( j=0; j<stolb; ++j )
      matr_res[i][j]=scal*matr[i][j];//поэлементное умножение на число
}

int sum_matr (
  double * matr_a[], int strok_a, int stolb_a ,
  double * matr_b[],int strok_b, int stolb_b ,
  double * matr_res[], int *strok_res, int *stolb_res )//передача 2х матриц и их размеров,результирующей матрицы и ее размеров
{
  int i,j;
  if ( ( strok_a!=strok_b ) || ( stolb_a!=stolb_b ) )//условие дл€ проверки равенства размеров суммируемых матриц
    {
      printf ( "\nSumm is not able\n" );
      return 1;
    }
  *strok_res=strok_a;
  *stolb_res=stolb_a;
  for ( i=0; i<strok_a; ++i )
    for ( j=0; j<stolb_a; ++j )
      matr_res[i][j]=matr_a[i][j]+matr_b[i][j];//поэлементное суммирование
  return 0;
}

int mnog_matr (
  double * matr_a[], int strok_a,int stolb_a,
  double * matr_b[],int strok_b,int stolb_b,
  double * matr_res[],int *strok_res, int *stolb_res )//передача 2х матриц и их размеров,результирующей матрицы и ее размеров
{
  int i,j,k;
  if ( stolb_a!=strok_b )//проверка равенства кол-ва столбцов матрицы а и строк матрицы b
    {
      printf ( "\nMult is not able\n" );
      return 1;
    }
  *strok_res=strok_a;
  *stolb_res=stolb_b;
  for ( i=0; i<strok_a; ++i )
	{
    for ( j=0; j<stolb_b; ++j )
      {
        matr_res[i][j]=0;//обнуление матрицы
        for ( k=0; k<stolb_a; k++ )
          {
            matr_res[i][j]+=matr_a[i][k]*matr_b[k][j];//суммирование произведени€ элементов 2х матриц
          }
	  }
    }
  return 0;
}

int mnog_vec_matr ( double *vector, int rasmer_vec,
                    double *matr[], int strok_matr, int stolb_matr,
                    double *vect_res, int *rasmer )//передача матрицы и ее размеров,вектора и его размера,результирующего вектора и его размера
{
  int j,k;
  if ( rasmer_vec!=strok_matr )//проверка на равенство размера вектора и кол-ва строк матрицы
    {
      printf ( "\nError\n" );
      return 1;
    }
  *rasmer=stolb_matr;

  for ( j=0; j<stolb_matr; ++j )
    {
      vect_res[j]=0;//обнуление вектора
      for ( k=0; k<rasmer_vec; k++ )
        {
          vect_res[j]+=vector[k]*matr[k][j];//суммирование произведени€ элементиов вектора и матрицы
        }
    }
  return 0;
}

void input_matr(double *matr[],int *strok,int *stolb)//передача матрицы и ее размеров
{
	int i,j;
	printf("\nEnter row number=");
	scanf("%d",strok);//ввод с клавиатуры кол-ва строк
	printf("\nEnter colomn number=");
	scanf("%d",stolb);//ввод с клавиатуры кол-ва столбцов
	printf("\nEnter massive:\n");
	for(i=0;i<*strok;++i)
		for(j=0;j<*stolb;++j)
		{
			matr[i][j]=0;
		}
	for(i=0;i<*strok;++i)
		for(j=0;j<*stolb;++j)
		{
			printf("\nmassive[%i][%i]=",i,j);
			scanf("%lf",&matr[i][j]);//ввод элементов массива
			vivod_matr(matr,*strok,*stolb,"M");
		}
	
}





