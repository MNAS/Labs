#include <stdio.h>

#ifndef MATRIX_H
#define MATRIX_H

///��������� ������� �� �����.
void scal_matr ( double *matr[], int strok, int stolb,
                 double *matr_res[], int *strok_res, int *stolb_res,
                 double scal );

///����� ������� �� ������.
void vivod_matr ( double *matr[], int strok, int stolb, char *msg );

///���������������� �������
/**�������� �������,�������������� �������,������*/
void transp_matr ( double *matr[], int strok, int stolb,
                   double *matr_res[], int *strok_res, int *stolb_res );

///����� ������
int sum_matr (
  double *matr_a[], int strok_a, int stolb_a ,
  double *matr_b[], int strok_b, int stolb_b ,
  double *matr_res[], int *strok_res, int *stolb_res );

///��������� ������
int mnog_matr (
  double *matr_a[], int strok_a, int stolb_a,
  double *matr_b[], int strok_b, int stolb_b,
  double *matr_res[], int *strok_res, int *stolb_res );

///��������� ������� �� �������
int mnog_vec_matr (
  double *vector, int rasmer_vec,
  double *matr[], int strok_matr, int stolb_matr,
  double *vect_res, int *rasmer );

///���� �������
void input_matr ( double *matr[], int *strok, int *stolb );

#endif
