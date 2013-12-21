#include <iostream>
#include "hill.h"

vector::vector()
{
    this->v[0]=0;
    this->v[1]=0;
    this->v[2]=0;
}


vector::~vector()
{

}

void vector::setVector(int i, int a)
{
    this->v[i]=a;
}

int vector::getSymb(int i)
{
    return v[i];
}

void vector::mod(int n)
{
    for(int i=0; i<3; i++)
    {
        v[i]%=n;
    }
}

void vector::output(std::ostream& os)
{
    for(int i=0; i<3; i++)
    {
        os<<v[i]<<std::endl;
    }
}


key::key()
{
    arr[0][0]=17;
    arr[0][1]=17;
    arr[0][2]=5;
    arr[1][0]=21;
    arr[1][1]=18;
    arr[1][2]=21;
    arr[2][0]=2;
    arr[2][1]=2;
    arr[2][2]=19;
}

//Обратный ключ
key::key(int a)
{
    arr[0][0]=4;
    arr[0][1]=9;
    arr[0][2]=15;
    arr[1][0]=15;
    arr[1][1]=17;
    arr[1][2]=6;
    arr[2][0]=24;
    arr[2][1]=0;
    arr[2][2]=17;
}


key::~key()
{

}


vector key::mult(vector p)
{
  vector c;
    for (int i=0; i<keySize(); ++i )
    {
        for ( int j=0; j<keySize(); j++ )
        {
            c.v[i]+=p.v[j]*arr[i][j];
        }
    }
    return c;
}







