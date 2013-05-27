#include "graph.h"
#include <iostream>

Kaima::Kaima():Graph(), num(0)
{
    kajmaVertexes=new Vertex*[100];
    kajmaRibs=new Rib*[100];
    kajmaLenPath=new int[100];

    lenPathTree=new int[100];
}

Kaima::~Kaima()
{
    num=0;
    delete kajmaVertexes;
    delete kajmaRibs;
}

int Kaima::findVershWhisMinWayFrom()
{
    int res=0;//результирующая вершина,до которой минимальный путь
    int minWay=2000000000;
    for(int i=0; i<num; ++i)
    {
        Vertex *s=kajmaRibs[i]->getStart();
        int s_index=-1;
        for(int j=0; j<numVersh; ++j)
        {
            if(vershins[j]==s)
            {
                s_index=j;
                break;
            }
        }
        int len=lenPathTree[s_index]+kajmaRibs[i]->getWeight();
        minWay=(len<minWay)?(res=i,len):minWay;
    }
    return res;
}

int Kaima::findWay(Vertex* From, Vertex* A)
{
    int lenWay=0;
    Vertex *temp=A;//промежуточная переменная
    std::cout<<"Результирующий путь из конца в начало:"<<std::endl;
    while(temp!=From)
    {
	temp->output();
	std::cout<<"<-";
        findInRebra(temp);
        if(this->numInReber==1)
        {
            temp=inRebra[0]->getStart();
            lenWay+=inRebra[0]->getWeight();
        }
        else
            return 2000000000;
    }
    From->output();
    std::cout<<"="<<lenWay<<std::endl;
    return lenWay;
}

void Kaima::initKaima(Vertex *V, Graph* G)
{
    num=0;
    numVersh=0;
    numReber=0;
    lenPathTree[numVersh]=0;
    if(G && G->isExist(V))//Вершина присутствует в графе.
    {

        addVersh(V);

        G->findOutRebra(V);
        for(int i=0; i<G->numOutReber; ++i)
        {
            kajmaRibs[num]=G->outRebra[i];
            kajmaVertexes[num]=G->outRebra[i]->getEnd();
            kajmaLenPath[num]=G->outRebra[i]->getWeight();
            ++num;
        }
    }
    else
        std::cout<<"V not Exist in G"<<std::endl;
}

void Kaima::add (int index, Graph* G)
{
    addVersh(kajmaVertexes[index]);
    addRebro(kajmaRibs[index]);
    lenPathTree[numVersh]=kajmaLenPath[index];

    G->findOutRebra(kajmaVertexes[index]);

    for(int i=index; index+1<num; ++index)
    {
        kajmaVertexes[i]=kajmaVertexes[i+1];
        kajmaRibs[i]=kajmaRibs[i+1];
        kajmaLenPath[i]=kajmaLenPath[i+1];
    }
    --num;
    for(int i=0; i<G->numOutReber; ++i)
    {
        kajmaRibs[num]=G->outRebra[i];
        kajmaVertexes[num]=G->outRebra[i]->getEnd();
        kajmaLenPath[num]=G->outRebra[i]->getWeight();
        ++num;
    }

}

void Kaima::output()
{   std::cout<<"Kaima:";
    Graph::output();
    for(int i=0; i<num; ++i)
    {
        kajmaRibs[i]->output();
        std::cout<<"\t";
        kajmaVertexes[i]->output();
        std::cout<<"\t";
        std::cout<<" "<<kajmaLenPath[i]<<std::endl;
    }
}
