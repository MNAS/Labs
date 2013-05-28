#include "graph.h"
#include <iostream>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int i=1;
    Graph *A =new Graph;
    if(argc<3)
        std::cout<<"Usage: graph-path from to [from_1 to_1 weight_1]"<<std::endl;
	std::cout<<"./graph-path A F  A B 5  A E 30  B C 10  C D 15  E D 20  C F 70  D F 60  B F 40"<<std::endl;
    while(i<3)
        i++;
    while(i+2<argc)
    {
        if(!A->findVershByName(argv[i][0]))
            A->addVersh(argv[i][0]);
        if(!A->findVershByName(argv[i+1][0]))
            A->addVersh(argv[i+1][0]);
        A->addRebro(A->findVershByName(argv[i][0]),A->findVershByName(argv[i+1][0]), atoi(argv[i+2]));
        i+=3;
    }
    A->output();
    A->findMinWay(argv[1][0], argv[2][0]);
    return 0;
}
