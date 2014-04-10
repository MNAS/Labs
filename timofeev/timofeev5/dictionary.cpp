#include "hash.h"
#include <iostream>
#include <string.h>
using namespace std;

HashDictionary::HashDictionary( int length, int p, int q)
				:LENGTH(length),P(p),Q(q),keyLength(13)
{
    dict=new string*[LENGTH];
	defin=new string*[LENGTH];
    memset(dict,0,sizeof(dict));
	memset(defin,0,sizeof(defin));
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
    return rez+1;//������ ����� ��������� ������� � ��������� ��������
}

int HashDictionary::hash(const string &str)const
{
    int sum=0;
    for(int i=0; i<str.length(); ++i)
    {
        sum+=code(str[i])+i;
    }
    return (P*sum+Q)%keyLength;
}

int HashDictionary::findPos(const string &word)const
{
    int i=hash(word);//������� ������ ����� � �������
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i]==NULL || *dict[i]==word)
            return i;//����� ��� ������� ��� ��� ������� �������
        else if(++i==LENGTH)
            i=0;//������� � ���������� �������
    }
    return -1;//��������� ��� ������� � �������
}

void HashDictionary::add(const string &word, const string &def)
{
	if(word.length()>keyLength)
		return;
    int i=findPos(word);//������� ����� � �������
    if(i==-1)
        return;//� ������ ������������ �������
    if(dict[i]==NULL)
    {
        dict[i]= new string();
        *dict[i]=word;//���������� �����
		defin[i]=new string();
		*defin[i]=def;
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
            i=0;//������� � ���������� �������
    }
    return false;
}

void HashDictionary::output()
{
	cout<<"Index Hash Key Definition"<<endl;
    for(int i=0; i<LENGTH; ++i)
    {
        if(dict[i])
            cout<<i<<" "<<hash(*dict[i])<<" "<<*dict[i]<<" "<<*defin[i]<<endl;
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
			delete defin[i];
			defin[i]=0;
            return;
        }
        else if(++i==LENGTH)
            i=0;//������� � ���������� �������
    }
}

int HashDictionary::findKey(const string &word)const
{
    int i=hash(word);
    for(int counter=0; counter<LENGTH; ++counter)
    {
        if(dict[i] && *dict[i]==word)
            return i;//���������� ������ �������� �����
        else if(++i==LENGTH)
            i=0;//������� � ���������� �������
    }
    return -1;//���� �� ����� ����� � �������
}
