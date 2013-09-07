#include "massive.h"
#include <iostream>

Massive::Massive(int rows, int cols)
{
    row=rows;
    col=cols;
    if(col==0)
        arr=0;
    else
        arr=new int[col/2*row];//размер массива.внутреннее представление
}

Massive::~Massive()
{
    delete arr;
}

int Massive::get(int i, int j)
{
    if(j%2==1)
        return arr[i*(col/2)+(j+1)/2-1];//если столбец нечетный,то индексация смещается по формуле
    else
        return 0;
}

void Massive::set(int i, int j, int value)
{
    if(j%2==1)
        arr[i*(col/2)+(j+1)/2-1]=value;//если столбец нечетный,то индексация смещается по формуле
}

int Massive::getCols()
{
    return col;
}

int Massive::getRows()
{
    return row;
}

void Massive::outputVnutr()
{
    std::cout << "Внутреннее представление массива" << std::endl;
    for(int i=0; i<(col/2*row); ++i)
        std::cout << i << " "<< arr[i] <<std::endl;//вывод значений элементов во внутреннем представлении
}

void Massive::outputVnesh()
{
    std::cout << "Внешнее представление массива" << std::endl;
    for(int i=0; i<getRows(); ++i)
    {
        for(int j=0; j<getCols(); ++j)
        {
            std::cout<<get(i,j)<<" ";
        }
        std::cout<<std::endl;
    }
}







