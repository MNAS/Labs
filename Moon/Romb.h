#include "Geom.h"
#include "Point.h" 

#ifndef ROMBH
#define ROMBH

class Romb: public Geom
{
public:
	Romb();
	Romb(const Point &f, double Angle, double D1, double D2);
	void output();
	void input();
	
protected:
	Point centre;///<����� �����(����� �� ����������� ����������)
	double angle;///<���� ����� d1 ���������� � ���� �, ���������� � ��������
	double d1;///<����� ������ ���������
	double d2;///<����� ������ ���������
	
public:
   double area();
   double perimetr();
	
};
#endif