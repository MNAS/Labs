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
  scanf ( "%d", &pV->n );

  for ( i = 0; i < pV->n; ++i )
    pV->d[i] = 0;

  printf ( "\nEnter vector:\n" );

  for ( i = 0; i < pV->n; ++i )
    {
      printf ( "\nVector[%i]=", i );
      scanf ( "%lf", &pV->d[i] );
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

int dotProduct_S_V ( double S, const struct sVector Va, struct sVector *V_rez)
{
  int i;
  V_rez->n = Va.n;

  for ( i = 0; i < Va.n; ++i )
      V_rez->d[i] = S * Va.d[i];

  return 0;
}

int addProduct_V_V ( const struct sVector Va, const struct sVector Vb, struct  sVector *Vc )
{
  int i;

  if ( Va.n != Vb.n )
    {
      Vc->n = 0;
      printf ( "Vector summ is not able\n" );
      return 1;
    }

  Vc->n = Va.n;

  for ( i = 0; i < Va.n; ++i )
    Vc->d[i] = Va.d[i] + Vb.d[i];

  return 0;
}

double dotProduct_V_V ( const struct sVector Va, const struct sVector Vb )
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

double norm_V ( const struct sVector V )
{
  int i;
  double sum = 0;

  for ( i = 0; i < V.n; ++i )
    sum += V.d[i] * V.d[i];

  return sqrt ( sum );
}


