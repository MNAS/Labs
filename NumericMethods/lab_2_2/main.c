#include <stdio.h>
#include <math.h>
#include <time.h>

double f ( double x );
double df ( double x );
int metod_hord ( double a, double b, double eps, double *x_rez );
int metod_newthona ( double a, double b, double eps, double *x_rez );
int metod_rafsona ( double a, double b, double eps, double *x_rez );
int metod_iteration ( double a, double b, double eps, double *x_rez );

int main()
{
  double a, b, x_rez;
  clock_t start, end;
  start = clock();

//   printf ( "\na=" );
//   scanf ( "%lf", &a );
//   printf ( "\nb=" );
//   scanf ( "%lf", &b );
//   printf ( "\na=%f\tb=%f", a, b );
  a = 0.1;
  b = 1.1;
  long int iii;
  long int delay=1000000;

  if ( metod_hord ( a, b, 0.001, &x_rez ) == 0 )
    {
      start = clock();

      for ( iii = 0; iii < delay; ++iii )
        metod_hord ( a, b, 0.001, &x_rez );

      end = clock();
      printf ( "\nx_rez(metod_hord)=%f", x_rez );
      printf ( "\nTime %f\n", 1.0*(end - start)/CLOCKS_PER_SEC );
    }
  else
    {
      printf ( "There are no roots" );
    }

  if ( metod_newthona ( a, b, 0.001, &x_rez ) == 0 )
    {
      start = clock();

      for ( iii = 0; iii < delay; ++iii )
        metod_newthona ( a, b, 0.001, &x_rez );

      end = clock();
      printf ( "\nx_rez(by metod_newthona)=%f", x_rez );
      printf ( "\nTime %f\n", 1.0*(end - start)/CLOCKS_PER_SEC );
    }
  else
    {
      printf ( "\nThere are no roots" );
    }

  if ( metod_rafsona ( a, b, 0.001, &x_rez ) == 0 )
    {
      start = clock();

      for ( iii = 0; iii < delay; ++iii )
        metod_rafsona ( a, b, 0.001, &x_rez );

      end = clock();
      printf ( "\nx_rez(by metod_rafsona)=%f", x_rez );
      printf ( "\nTime %f\n", 1.0*(end - start)/CLOCKS_PER_SEC );
    }
  else
    {
      printf ( "\nThere are no roots" );
    }

  start = clock();
  for ( iii = 0; iii < delay; ++iii )
    metod_iteration ( a, b, 0.001, &x_rez );
  end = clock();
  
  printf ( "\nx_rez(by metod_iteration)=%f", x_rez );
  printf ( "\nTime %f\n", 1.0*(end - start)/CLOCKS_PER_SEC );
  return 0;
}

int metod_hord ( double a, double b, double eps, double *x_rez )
{
  double x, xn, fa;

  if ( f ( a ) * f ( b ) > 0 )
    return 1;

  x = a;

  do
    {
      xn = x;
      fa = f ( a );
      x = a - ( b - a ) / ( f ( b ) - fa ) * fa;

      if ( f ( x ) *fa > 0 )
        a = x;
      else
        b = x;
    }
  while ( fabs ( ( x - xn ) / x ) > eps );

  *x_rez = x;

  return 0;
}

int metod_newthona ( double a, double b, double eps, double *x_rez )
{
  double x, xn;

  if ( f ( a ) * f ( b ) > 0 )
    return 1;

  x = ( a + b ) / 2.0;

  do
    {
      xn = x;
      x = xn - f ( xn ) / df ( xn );
    }
  while ( fabs ( ( x - xn ) / x ) > eps );

  *x_rez = x;
  return 0;
}

int metod_rafsona ( double a, double b, double eps, double *x_rez )
{
  double x, xn, xn1;

  if ( f ( a ) * f ( b ) > 0 )
    return 1;

  xn = a;
  x = b;

  do
    {
      xn1 = xn;
      xn = x;
      x = xn1 - ( xn - xn1 ) / ( f ( xn ) - f ( xn1 ) ) * f ( xn1 );
    }
  while ( fabs ( ( x - xn ) / x ) > eps );

  *x_rez = xn;
  return 0;
}

double f ( double x )
{
  return tan ( 0.5 * x + 0.1 ) - x * x;
}

double df ( double x )
{
  return 0.5 / ( cos ( 0.5 * x + 0.1 ) * cos ( 0.5 * x + 0.1 ) ) - 2.0 * x;
}


int metod_iteration ( double a, double b, double eps, double *x_rez )
{
  double x, xn;
  xn = a;

  do
    {
      x = xn;
      xn = f ( x ) + x;
    }
  while ( fabs ( ( x - xn ) / x ) > eps );

  *x_rez = xn;
  return 0;
}





















