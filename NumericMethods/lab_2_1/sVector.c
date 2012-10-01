#include <stdio.h>
#include <math.h>
#include "sVector.h"


struct sVector init_V ( double *v, int N , int SZ )
{
  struct sVector sV;
  sV.d = v;
  sV.n = N;
  sV.size = SZ;
  return sV;
}

void in_V ( struct sVector *pV )
{
  int i;
  printf ( "\nEnter vector size=" );
  scanf ( "%d", pV->n );
  printf ( "\nEnter vector:\n" );

  for ( i = 0; i < pV->n; ++i )
    pV->d[i] = 0;

  for ( i = 0; i < pV->n; ++i )
    {
      printf ( "\nVector[%i]=", i );
      scanf ( "%lf", pV->d[i] );
      out_V ( *pV, "V" );
    }
}

void out_V ( struct sVector V, char *msg )
{
  int i;
  printf ( "\n%s[%i]:", msg, V.n );

  for ( i = 0; i < V.n; ++i )
    printf ( "\t%f", V.d[i] );

  printf ( "\n" );
}

int add_V ( const struct sVector a, const struct sVector b, struct  sVector c )
{
  int i;

  if ( a.n != b.n )
    {
      c.n = 0;
      printf ( "Vector summ is not able\n" );
      return 1;
    }

  c.n = a.n;

  for ( i = 0; i < a.n; ++i )
    c.d[i] = a.d[i] + b.d[i];

  return 0;
}

double scalMult_V ( const struct sVector Va, const struct sVector Vb )
{
  int i;
  double sum = 0;

  if ( Va.n != Vb.n )
    {
      sum = 0;
      printf ( "Scal mult is not able\n" );
      return 0;
    }

  for ( i = 0; i < Va.n; ++i )
    sum += Va.d[i] * Vb.d[i];

  return sum;
}

double norma_V ( const struct sVector V )
{
  int i;
  double sum = 0;

  for ( i = 0; i < V.n; ++i )
    sum += V.d[i] * V.d[i];

  return sqrt ( sum );
}


