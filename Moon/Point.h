#ifndef POINTH
#define POINTH

class Point
{
public :
    Point();
    Point(double X, double Y);
    ~Point();
    double x;
    double y;
    void output();
    void input();
    double distance(Point A);
};

#endif
