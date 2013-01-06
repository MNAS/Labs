#include "Geom.h"
#include "Arc.h"

#ifndef MOONH
#define MOONH

class Moon : public Geom
{
public:
  Moon();
  Moon(const Arc &f, const Arc & s);
  void output();
  void input();
protected :
  Arc first;
  Arc second;
public :
  double area();
  double perimetr();
};

#endif