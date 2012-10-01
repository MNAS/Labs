#include <stdio.h>
#include <math.h>

int vecscal ( double scal,
              double *vector, int rasmer,
              double *vector_res, int *rasmer_res )
{

  int i;
  *rasmer_res = rasmer;

  for ( i = 0; i < rasmer; ++i )
    {
      vector_res[i] = scal * vector[i];
    }

  return 0;
}

void vivod ( double *vector, int rasmer, char *msg )
{
  int i;
  printf ( "\n%s[%i]:", msg, rasmer );

  for ( i = 0; i < rasmer; ++i )
    {
      printf ( "\t%f", vector[i] );
    }

  printf ( "\n" );
}

int vecsum ( double *vector_a, int rasmer_a,
             double *vector_b, int rasmer_b,
             double *vector_res, int *rasmer_res )
{
  int i;

  if ( rasmer_a != rasmer_b )
    {
      *rasmer_res = 0;
      printf ( "Vector summ is not able\n" );
      return 1;
    }

  *rasmer_res = rasmer_a;

  for ( i = 0; i < rasmer_a; ++i )
    vector_res[i] = vector_a[i] + vector_b[i];

  return 0;
}

double scalmnog ( double *vector_a, int rasmer_a,
                  double *vector_b, int rasmer_b )
{
  int i;
  double sum = 0;

  if ( rasmer_a != rasmer_b )
    {
      sum = 0;
      printf ( "Scal mult is not able\n" );
      return 0;
    }

  for ( i = 0; i < rasmer_a; ++i )
    {
      sum += vector_a[i] * vector_b[i];
    }

  return sum;
}

double modul_vec ( double *vector_a, int rasmer_a )
{
  int i;
  double res = 0;
  double sum = 0;

  for ( i = 0; i < rasmer_a; ++i )
    {
      sum += vector_a[i] * vector_a[i];
    }

  res = sqrt ( sum );
  return res;
}

void input ( double *vector, int *razmer )
{
  int i;
  printf ( "\nEnter vector size=" );
  scanf ( "%d", razmer );
  printf ( "\nEnter vector:\n" );

  for ( i = 0; i < *razmer; ++i )
    vector[i] = 0;

  for ( i = 0; i < *razmer; ++i )
    {
      printf ( "\nVector[%i]=", i );
      scanf ( "%lf", &vector[i] );
      vivod ( vector, *razmer, "V" );
    }
}


