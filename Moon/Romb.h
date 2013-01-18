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
	Point centre;///<центр ромба(точка на пересечении диагоналей)
	double angle;///<угол между d1 диагональю и осью х, измеряется в градусах
	double d1;///<длина первой диагонали
	double d2;///<длина второй диагонали
	
public:
   double area();
   double perimetr();
	
};
#endif