#include <iostream>
#include "massive.h"

int main(int argc, char **argv) {
    int val=4;
    Massive a(5,4);
    for(int i=0; i<a.getRows(); ++i)
    {
        for(int j=0; j<a.getCols(); ++j)
        {
            a.set(i,j,val++);
        }
    }
    a.outputVnutr();
    a.outputVnesh();
    return 0;
}
