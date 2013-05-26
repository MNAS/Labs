#include "graph.h"
#include <iostream>

Kaima::Kaima():Graph(), numEndVersh(0)
{
  endVershins=new Vertex*[100];
}

Kaima::~Kaima()
{
    numReber=0;
    numVersh=0;
    delete endVershins;
}

Vertex * Kaima::findVershWhisMinWayFrom(Vertex *aStart)
{
    Vertex *temp=0;//результирующая вершина,до которой минимальный путь
    int minWay=2000000000;
    ListOfEndVersh();
    for(int i=0; i<numEndVersh; ++i)
    {
        int a=findWay(aStart,endVershins[i]);//временная переменная,содержит расстояние от стартовой вершины до конечных
        if(a<minWay)
        {
            minWay=a;
            temp=endVershins[i];//temp запоминает вершину, до которой минимальный путь
        }

    }
    return temp;
}

int Kaima::findWay(Vertex* From, Vertex* A)
{
    int lenWay=0;
    Vertex *temp=A;//промежуточная переменная
    while(temp!=From)
    {
      findInRebra(temp);
      if(this->numInReber==1)
      {
	temp=inRebra[0]->getStart();
	lenWay+=inRebra[0]->getWeight();
      }
      else
	return 2000000000;
    }
    return lenWay;
}

//ищет список конечных вершин(из которых не выходит ребер)
int Kaima::ListOfEndVersh()
{
    numEndVersh=0;
    for(int i=0; i<numVersh; ++i)
    {
        if(findOutRebra(vershins[i])==0)
        {
            endVershins[numEndVersh++]=vershins[i];
        }
    }
    return numEndVersh;
}

void Kaima::createKaima(Kaima *tree, Graph *G)
{
  copy(*tree);
  for(int i=0;i<numVersh;++i)
  {
    G->findOutRebra(vershins[i]);
    copyOutRebra(G);
    addOutRebersIfNotExist();
  }
  for(int i=0;i<numReber;++i)
    addVersh(rebrs[i]->getEnd());
}

void Kaima::copy(Kaima& K)
{
  clean();
  numReber=K.numReber;
  numVersh=K.numVersh;
  for(int i=0;i<numReber;++i) 
    rebrs[i]=K.rebrs[i];
  for(int i=0;i<numVersh;++i) 
    vershins[i]=K.vershins[i];
}

void Kaima::addOutRebersIfNotExist()
{
  for(int i=0; i<numOutReber; ++i)
    addRebro(outRebra[i]);
}