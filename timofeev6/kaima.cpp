#include "graf.h"
#include <iostream>

Kaima::Kaima():Graf()
{}

Kaima::~Kaima()
{
    numReber=0;
    numVersh=0;
}

Versh * Kaima::findMinWayToVersh(Versh *aStart)
{
    Versh *temp=0;//результирующая вершина,до которой минимальный путь
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

int Kaima::findWay(Versh *from,Versh *a)
{
    int lenWay=2000000000;
    Versh *temp=a;//промежуточная переменная
    while(temp!=from)
    {
        for(int i=0; i<numReber; ++i)
        {
            if(rebrs[i]->getEnd()==temp)
                lenWay+=rebrs[i]->getWeight();
            temp=rebrs[i]->getStart();
        }
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

void Kaima::createKaima(Kaima *tree, Graf *g)
{
    /*	for(int i=0;i<tree->numVersh;++i)
    	{
    		if()
    	}
    	a->addVersh(aStart);//добавляем в нее начальную вершину
    	findOutRebra(aStart);//находим все ребра,которые выходят из начальной вершины
    	for(int i=0;i<numOutReber;++i)//проходимся по массиву с исходящими ребрами
    	{
    		a->addRebro(outRebra[i]);//добавляем все исходящие ребра в кайму
    		a->addVersh(outRebra[i]->getEnd());//добавляем конечные вершины этих ребер в кайму
    	}
    	return a;
    */
}
