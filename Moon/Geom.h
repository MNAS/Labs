#ifndef GEOMH
#define GEOMH

class Geom
{
protected:
  Geom(){}
  virtual double area()=0;
  virtual double perimetr()=0;
};

#endif