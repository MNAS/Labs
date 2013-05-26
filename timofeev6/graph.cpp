#include "graph.h"
#include <iostream>

Graph::Graph()
{
    rebrs=new Rib*[100];
    vershins=new Vertex*[100];
    numReber=0;
    numVersh=0;
    outRebra=new Rib*[100];
    inRebra=new Rib*[100];
    numOutReber=0;
    numInReber=0;
}

Graph::~Graph()
{
    for(int i=0; i<numReber; ++i)
        delete rebrs[i];

    for(int i=0; i<numVersh; ++i)
        delete vershins[i];

    delete rebrs;
    delete vershins;
}

void Graph::addRebro(Vertex *aStart, Vertex *aEnd, int aWeight)
{
    if(aStart!=0&&aEnd!=0)
    {
        Rib *a=new Rib;//создается ребро
        rebrs[numReber++]=a;//в массив добавляется ребро,кол-во ребер увеличивается на 1
        a->setStart(aStart);//связываем ребро с вершинами
        a->setEnd(aEnd);
        a->setWeight(aWeight);
    }
}

void Graph::addVersh(char aName)
{
    Vertex *a=new Vertex;
    vershins[numVersh++]=a;
    a->setName(aName);
}

void Graph::output()
{
    std::cout<<"Graph:"<<std::endl;
    for(int i=0; i<numReber; ++i)
        rebrs[i]->output();

    for(int i=0; i<numVersh; ++i)
        vershins[i]->output();
}

Vertex* Graph::findVershByName(char aName)
{
    for(int i=0; i<numVersh; ++i)
    {
        if(vershins[i]->getName()==aName)
            return vershins[i];
    }
    return 0;
}

int Graph::findOutRebra(Vertex *a)
{
    numOutReber=0;
    for(int i=0; i<numReber; ++i)
    {
        if(rebrs[i]->getStart()==a)
            outRebra[numOutReber++]=rebrs[i];//если вершина совпадает с начальной вершиной какого-либо ребра из массива ребер,то добавляем найденное ребро в массив найденных ребер и увеличиваем количество найд. ребер
    }
    return numOutReber;
}

int Graph::findInRebra(Vertex *a)
{
    numInReber=0;
    for(int i=0; i<numReber; ++i)
    {
        if(rebrs[i]->getEnd()==a)
            inRebra[numInReber++]=rebrs[i];//если вершина совпадает с начальной вершиной какого-либо ребра из массива ребер,то добавляем найденное ребро в массив найденных ребер и увеличиваем количество найд. ребер
    }
    return numInReber;
}

void Graph::copyOutRebra(Graph* G)
{
    numOutReber=G->numOutReber;
    for(int i=0; i<numOutReber; ++i)
        outRebra[i]=G->outRebra[i];
}

void Graph::addVersh(Vertex *V)
{
    if(isExist(V))
        return;
    vershins[numVersh++]=V;
}

void Graph::addRebro(Rib* R)
{
    if(isExist(R))
        return;
    rebrs[numReber++]=R;
}


bool Graph::isExist(Vertex* V)
{
    for(int i=0; i<numVersh; ++i)
        if(vershins[i]==V)
            return true;
    return false;
}

bool Graph::isExist(Rib *R)
{
    for(int i=0; i<numReber; ++i)
        if(rebrs[i]==R)
            return true;
    return false;
}

int Graph::findMinWay(char fromName, char toName)
{
    Kaima *a=new Kaima;//создаем койму
    Kaima *tree=new Kaima;//дерево из присоедененных вершин
    Vertex *from=findVershByName(fromName);//нахождение указателя вершины по имени
    Vertex *to=findVershByName(toName);
    if(from==0 || to==0)
        return 2000000000;//если нет какой-либо из вершин,то найти расстояние нельзя
        
    tree->addVersh(from);
    tree->output();
    a->createKaima(tree, this);
    a->output();
    
    {
    Vertex *vA =a->findVershByName('A');
    Vertex *vB =a->findVershByName('B');
    Vertex *vE =a->findVershByName('E');
    vA->output(); vB->output(); vE->output();
    int i=0;
    i=a->findWay(vA,vA);
    i=a->findWay(vA,vB);
    i=a->findWay(vA,vE);
    ++i;
    }
    
    while(!tree->isExist(to))
    {
        Vertex *b=a->findVershWhisMinWayFrom(from);//вершина с минимальным расстоянием до начальной
        tree->addVersh(b);//добавили вершину к дереву
	a->createKaima(tree, this);
/*
         if(a->findInRebra(b)!=1)//находим ребра,которые входят в вершину с мин.расстоянием
            return 2000000000;
        else
        {
            tree->addRebro(a->inRebra[0]);//добавляем в дерево единственное входящее в вершину с мин.расстоянием ребро
            a->createKaima(tree, this);
        }
*/
        tree->output();
	a->output();
    }
    delete a;
    delete tree;
}




