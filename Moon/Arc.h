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
    double r;///<Радиус дуги.
public:
    Arc();///<Конструктор по умолчанию.
    Arc(const Arc&Ar);///<Конструктор копирования.
    Arc(Point A,double R);///<Конструктор создания дуги по точке и радиусу.
    Arc(double X, double Y,double R);///<Конструктор создания дуги по координатам точки и радиусу.

    Arc& operator=(const Arc&Ar);///<Оператори присваивания.

    void output();///<Функция вывода в консоль.
    void input();///<Функция ввода с консоли.
    double segArea(double angle);///<Вычисление площади сегмента дуги.
static double segArea(double r,double angle);///<Вычистение площади сегмента дуги.
};


#endif
