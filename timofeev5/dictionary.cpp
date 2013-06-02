#include "hash.h"
#include <iostream>
#include <string.h>
using namespace std;

HashDictionary::HashDictionary( int length, int p, int q):LENGTH(length),P(p),Q(q)
{
    dict=new string*[LENGTH];
    memset(dict,0,sizeof(dict));
}

int HashDictionary::code(char c)
{
    int rez=-1;
    char alf[]="abcdefghijklmnopqrstuvwxyz";
    int i=0;
    while(alf[i]!=0)
    {
        if(alf[i]==c)
        {   rez=i;
            break;
        }
        else
            ++i;
    }
    return rez+1;//выдает номер входящего символа в латинском алфавите
}

int HashDictionary::hash(const string &str)const
{
    int sum=0;
    for(int i=0; i<str.length(); ++i)
    {
        sum+=code(str[i])+i;
    }
    return (P*sum+Q)%LENGTH;
}

int HashDictionary::findPos(const string &word)const
{
    int i=hash(word);//текущий индекс слова в словаре
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i]==NULL || *dict[i]==word)
            return i;//слово или позиция для его вставки найдена
        else if(++i==LENGTH)
            i=0;//переход к следующему индексу
    }
    return -1;//перебраны все позиции в словаре
}

void HashDictionary::add(const string &word)
{
    int i=findPos(word);//позиция слова в словаре
    if(i==-1)
        return;//в случае переполнения словаря
    if(dict[i]==NULL)
    {
        dict[i]= new string();
        *dict[i]=word;//добавление слова
    }
}

bool HashDictionary::hasWord(const string &word) const
{
    int i=hash(word);
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i] && *dict[i]==word)
            return true;
        else if(++i==LENGTH)
            i=0;//переход к следующему индексу
    }
    return false;
}

void HashDictionary::output()
{
    for(int i=0; i<LENGTH; ++i)
    {
        if(dict[i])
            cout<<i<<" "<<*dict[i]<<endl;
    }
}

void HashDictionary::del(const string &word)
{
    int i=hash(word);
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i] && *dict[i]==word)
        {
            delete dict[i];
            dict[i]=0;
            return;
        }
        else if(++i==LENGTH)
            i=0;//переход к следующему индексу
    }
}

int HashDictionary::findKey(const string &word)const
{
    int i=hash(word);
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i] && *dict[i]==word)
            return i;//возвращает индекс искомого слова
        else if(++i==LENGTH)
            i=0;//переход к следующему индексу
    }
    return -1;//если не нашли слова в словаре
}
