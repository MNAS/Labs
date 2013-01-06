#include "vector.h"
#include "matrix.h"

void vivod_matr ( double * matr[],int strok,int stolb, char * msg )//�������� �������,���-�� ����� � �������� � ���� ��� ��������������� ���������
{
  int i,j;
  printf ( "\n%s [%i][%i]", msg,strok,stolb );
  for ( i=0; i<strok; ++i )
    {
      printf ( "\n" );
      for ( j=0; j<stolb; j++ )
        printf ( "%f\t",matr[i][j] );//����� ��������� �������
    }
  printf ( "\n" );
}

void transp_matr ( double * matr[],int strok,int stolb, double * matr_res[], int *strok_res, int *stolb_res )//�������� ������� � �� ��������,� ����� �������� �������������� ������� � �� ���������
{
  int i,j;
  *strok_res=stolb;//���������� �������������� ������� �������� ��������
  *stolb_res=strok;
  for ( i=0; i<strok; ++i )
    for ( j=0; j<stolb; ++j )
      matr_res[j][i]=matr[i][j];//������ ������� ����� � ��������
}

void scal_matr ( double * matr[], int strok, int stolb, double * matr_res[], int *strok_res,int *stolb_res, double scal )//�������� ������� � �� ��������,�������� �������������� ������� � �� ���������,������
{
  int i,j;
  *strok_res=strok;//���������� �������������� ������� �������� ��������
  *stolb_res=stolb;
  for ( i=0; i<strok; ++i )
    for ( j=0; j<stolb; ++j )
      matr_res[i][j]=scal*matr[i][j];//������������ ��������� �� �����
}

int sum_matr (
  double * matr_a[], int strok_a, int stolb_a ,
  double * matr_b[],int strok_b, int stolb_b ,
  double * matr_res[], int *strok_res, int *stolb_res )//�������� 2� ������ � �� ��������,�������������� ������� � �� ��������
{
  int i,j;
  if ( ( strok_a!=strok_b ) || ( stolb_a!=stolb_b ) )//������� ��� �������� ��������� �������� ����������� ������
    {
      printf ( "\nSumm is not able\n" );
      return 1;
    }
  *strok_res=strok_a;
  *stolb_res=stolb_a;
  for ( i=0; i<strok_a; ++i )
    for ( j=0; j<stolb_a; ++j )
      matr_res[i][j]=matr_a[i][j]+matr_b[i][j];//������������ ������������
  return 0;
}

int mnog_matr (
  double * matr_a[], int strok_a,int stolb_a,
  double * matr_b[],int strok_b,int stolb_b,
  double * matr_res[],int *strok_res, int *stolb_res )//�������� 2� ������ � �� ��������,�������������� ������� � �� ��������
{
  int i,j,k;
  if ( stolb_a!=strok_b )//�������� ��������� ���-�� �������� ������� � � ����� ������� b
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
        matr_res[i][j]=0;//��������� �������
        for ( k=0; k<stolb_a; k++ )
          {
            matr_res[i][j]+=matr_a[i][k]*matr_b[k][j];//������������ ������������ ��������� 2� ������
          }
	  }
    }
  return 0;
}

int mnog_vec_matr ( double *vector, int rasmer_vec,
                    double *matr[], int strok_matr, int stolb_matr,
                    double *vect_res, int *rasmer )//�������� ������� � �� ��������,������� � ��� �������,��������������� ������� � ��� �������
{
  int j,k;
  if ( rasmer_vec!=strok_matr )//�������� �� ��������� ������� ������� � ���-�� ����� �������
    {
      printf ( "\nError\n" );
      return 1;
    }
  *rasmer=stolb_matr;

  for ( j=0; j<stolb_matr; ++j )
    {
      vect_res[j]=0;//��������� �������
      for ( k=0; k<rasmer_vec; k++ )
        {
          vect_res[j]+=vector[k]*matr[k][j];//������������ ������������ ���������� ������� � �������
        }
    }
  return 0;
}

void input_matr(double *matr[],int *strok,int *stolb)//�������� ������� � �� ��������
{
	int i,j;
	printf("\nEnter row number=");
	scanf("%d",strok);//���� � ���������� ���-�� �����
	printf("\nEnter colomn number=");
	scanf("%d",stolb);//���� � ���������� ���-�� ��������
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
			scanf("%lf",&matr[i][j]);//���� ��������� �������
			vivod_matr(matr,*strok,*stolb,"M");
		}
	
}





