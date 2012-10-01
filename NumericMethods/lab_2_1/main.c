#include <stdio.h>
#include "matrix.h"
#include "vector.h"

/** \brief Главная функция.
 * 
 * В главной функции распределяется место под переменные:
 * - scal --- число;
 * - res --- модуль вектора;
 * - sum --- скалярное произведение вектора;
 * - vector_a --- вектор а;
 * - rasmer_a --- размер вектора а;
 * - vector_b[10] --- вектор b;
 * - rasmer_b --- размер вектора b;
 * - vector_res[10] --- конечный вектор(результат);
 * - vector_res_rasmer --- размер конечного ветктора;
 * - matr_a --- матрица A;
 * - int matr_strok_a --- кол-во строк матрицы A.
 * - matr_stolb_a ---кол-во столбцов матрицы A.
 * - p_matr_a --- массив указателей на double, служащий для доступа к элементам матрицы A из функций манипулирования;
 * - matr_b --- матрица B;
 * - matr_strok_b --- кол-во строк матрицы B;
 * - matr_stolb_b ---кол-во столбцов матрицы B;
 * - p_matr_b --- массив указателей на double, служащий для доступа к элементам матрицы B из функций манипулирования;
 * 
  
 */

int main()
{

  double scal; // число

  int rasmer_a; // размер вектора а.
  double vector_a[10]; // вектора а.

  int rasmer_b;//размер вектора b
  double vector_b[10];// вектора b

  double vector_res[10];//конечный вектор(результат)
  int vector_res_rasmer;//размер конечного ветктора

  double sum = 0; //скалярное произведение вектора
  double res = 0; //модуль вектора
  int i;

  double matr_a[10][10];
  int matr_strok_a, matr_stolb_a; //кол-во строк и столбцов матрицы а
  double *p_matr_a[10];//Указатель на первые элементы строк в первом столбце матрицы matr.

  for ( i = 0; i < 10; ++i )
    p_matr_a[i] = &matr_a[i][0]; //

  double matr_b[10][10];
  int matr_strok_b, matr_stolb_b; //кол-во строк и столбцов матрицы b
  double *p_matr_b[10];//Указатель на первые элементы строк в первом столбце матрицы matr.

  for ( i = 0; i < 10; ++i )
    p_matr_b[i] = &matr_b[i][0];

  double matr_res[10][10];//конечная матрица(результат)
  int matr_res_strok, matr_res_stolb;//кол-во строк и столбцов конечной матрицы
  double *p_matr_res[10];//Указатель на первые элементы строк в первом столбце матрицы matr_res.

  for ( i = 0; i < 10; ++i )
    p_matr_res[i] = &matr_res[i][0];

  char a[10];//переменная, отвечающая за выбор действия

  do
    {
      printf ( "\na: Mult vector and scal;" );
      printf ( "\nb: Summ 2 vectors;" );
      printf ( "\nc: Scal mult vectors;" );
      printf ( "\nd: Modul vector;" );
      printf ( "\ne: Transpon matrix;" );
      printf ( "\nf: Mult scal and matrix;" );
      printf ( "\ng: Mult vector and matrix;" );
      printf ( "\nh: Summ 2 matrix;" );
      printf ( "\ni: Mult 2 matrix;" );
      printf ( "\nx: Exit" );
      printf ( "\nChoose the variant:" );
      scanf ( "%s", a );

      switch ( a[0] )
        {
        case 'a'://Умножение вектора на скаляр.
          printf ( "Enter chislo:" );
          scanf ( "%lf", &scal ); //ввод числа
          printf ( "\nscal=%f", scal );
          input ( vector_a, &rasmer_a ); //функция ввода вектора
          vivod ( vector_a, rasmer_a, "vector_a" ); //функция вывода вектора
          vecscal ( scal, vector_a, rasmer_a, vector_res, &vector_res_rasmer ); //функция умножения скаляра на вектор
          vivod ( vector_res, vector_res_rasmer, "vector_res" ); //вывод конечного вектора
          break;
        case 'b'://Сумма векторов.
          input ( vector_a, &rasmer_a ); //ввод вектора а
          vivod ( vector_a, rasmer_a, "vector_a" ); //вывод вектора а
          input ( vector_b, &rasmer_b ); //ввод вектора b
          vivod ( vector_b, rasmer_b, "vector_b" );
          vecsum ( vector_a, rasmer_a, vector_b, rasmer_b, vector_res, &vector_res_rasmer ); //функция сложения 2х векторов
          vivod ( vector_res, vector_res_rasmer, "vector_res" );
          break;
        case 'c'://Скалярное произведение векторов.
          input ( vector_a, &rasmer_a );
          vivod ( vector_a, rasmer_a, "vector_a" );
          input ( vector_b, &rasmer_b );
          vivod ( vector_b, rasmer_b, "vector_b" );
          sum = scalmnog ( vector_a, rasmer_a, vector_b, rasmer_b ); //функция скалярного произведения векторов
          printf ( "sum= %f\n ", sum );
          break;
        case 'd'://Модуль вектора
          input ( vector_a, &rasmer_a );
          vivod ( vector_a, rasmer_a, "vector_a" );
          res = modul_vec ( vector_a, rasmer_a ); //функция вычисления модуля вектора
          printf ( "res= %f\n ", res );
          break;
        case 'e'://Транспонирование матрицы.
          input_matr ( p_matr_a, &matr_strok_a, &matr_stolb_a ); //
          vivod_matr ( p_matr_a, matr_strok_a, matr_stolb_a, "matr_a" );
          transp_matr ( p_matr_a, matr_strok_a, matr_stolb_a,
                        p_matr_res, &matr_res_strok, &matr_res_stolb );
          vivod_matr ( p_matr_res, matr_res_strok, matr_res_stolb, "trasmon matr" );
          break;
        case 'f'://Умножение матрицы на число.
          printf ( "enter chislo:" );
          scanf ( "%lf", &scal );
          printf ( "\nscal=%f", scal );
          input_matr ( p_matr_a, &matr_strok_a, &matr_stolb_a );
          vivod_matr ( p_matr_a, matr_strok_a, matr_stolb_a, "matr_a" );
          scal_matr ( p_matr_a, matr_strok_a, matr_stolb_a,
                      p_matr_res, &matr_res_strok, &matr_res_stolb, scal );
          vivod_matr ( p_matr_res, matr_res_strok, matr_res_stolb, "scal_matr" );
          break;
        case 'g'://Умножение вектора на матрицу.
          input ( vector_a, &rasmer_a );
          vivod ( vector_a, rasmer_a, "vector_a" );
          input_matr ( p_matr_a, &matr_strok_a, &matr_stolb_a );
          vivod_matr ( p_matr_a, matr_strok_a, matr_stolb_a, "matr_a" );

          if ( mnog_vec_matr ( vector_a, rasmer_a,
                               p_matr_a, matr_strok_a, matr_stolb_a,
                               vector_res, &vector_res_rasmer ) == 0 )
            vivod ( vector_res, vector_res_rasmer, "vector_res" );

          break;
        case 'h'://Сумма двух матриц
          input_matr ( p_matr_a, &matr_strok_a, &matr_stolb_a );
          vivod_matr ( p_matr_a, matr_strok_a, matr_stolb_a, "matr_a" );
          input_matr ( p_matr_b, &matr_strok_b, &matr_stolb_b );
          vivod_matr ( p_matr_b, matr_strok_b, matr_stolb_b, "matr_b" );

          if ( sum_matr ( p_matr_a, matr_strok_a, matr_stolb_a,
                          p_matr_b, matr_strok_b, matr_stolb_b,
                          p_matr_res, &matr_res_strok, &matr_res_stolb ) == 0 )
            vivod_matr ( p_matr_res, matr_res_strok, matr_res_stolb, "sum_matr" );

          break;
        case 'i'://Умножение двух матриц
          input_matr ( p_matr_a, &matr_strok_a, &matr_stolb_a );
          vivod_matr ( p_matr_a, matr_strok_a, matr_stolb_a, "matr_a" );
          input_matr ( p_matr_b, &matr_strok_b, &matr_stolb_b );
          vivod_matr ( p_matr_b, matr_strok_b, matr_stolb_b, "matr_b" );

          if ( mnog_matr ( p_matr_a, matr_strok_a, matr_stolb_a,
                           p_matr_b, matr_strok_b, matr_stolb_b,
                           p_matr_res, &matr_res_strok, &matr_res_stolb ) == 0 ) //если функция работает правильно(условие умножение матриц соблюдены),то выводинтся конечная матрица
            vivod_matr ( p_matr_res, matr_res_strok, matr_res_stolb, "mnog_matr" );

          break;
        case 'x'://Выход
          break;

        }
    }
  while ( a[0] != 'x' ); //действия выполняются,пока в переменной а не содержится символ х

  return 0;
}

