#include "graf.h"
#include <iostream>

int main()
{
    Rebro *b=new Rebro;
    Graf A;
    A.addVersh('A');
    A.addVersh('B');
    A.addVersh('C');
    A.addVersh('D');
    A.addVersh('E');
    A.addVersh('F');

    A.addRebro(A.findVershByName('A'),A.findVershByName('B'), 5);
    A.addRebro(A.findVershByName('A'),A.findVershByName('E'), 30);
    A.addRebro(A.findVershByName('B'),A.findVershByName('F'), 40);
    A.addRebro(A.findVershByName('B'),A.findVershByName('C'), 10);
    A.addRebro(A.findVershByName('C'),A.findVershByName('F'), 70);
    A.addRebro(A.findVershByName('C'),A.findVershByName('D'), 15);
    A.addRebro(A.findVershByName('D'),A.findVershByName('F'), 60);
    A.addRebro(A.findVershByName('E'),A.findVershByName('D'), 20);
    A.addRebro(A.findVershByName('F'),A.findVershByName('E'), 50);
    A.addRebro(A.findVershByName('A'),A.findVershByName('Z'), 100);
    A.output();
    A.findMinWay('A', 'F');
    return 0;
}
