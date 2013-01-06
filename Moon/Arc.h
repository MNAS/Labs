#include "Point.h"

#ifndef ARCH
#define ARCH

/**
 * Класс дуга.
 *
 * Используется в классе Moon.
 *
 */
class Arc : public Point
{
public:
    double r;
public:
    Arc();///<Конструктор по умолчанию.
    Arc(const Arc&Ar);///<Конструктор копирования.
    Arc(Point A,double R);
    Arc(double X, double Y,double R);

    Arc& operator=(const Arc&Ar);

    void output();///<Функция вывода в консоль.
    void input();///<Функция ввода с консоли.
    double segArea(double angle);
static double segArea(double r,double angle);
};


#endif
