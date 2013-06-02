#include "hash.h"
#include <iostream>
#include <string.h>
using namespace std;

int HashDictionary::code(char c)
{
	char alf[]="abcdefghijklmnopqrstuvwxyz";
	return strchr(alf,c)-alf+1;//������ ����� ��������� ������� � ��������� ��������
}

int HashDictionary::hash(const string &str)
{
	int sum=0;
	for(int i=0;i<str.length();++i)
	{
		sum+=code(str[i])+i;
	}
	return (P*sum+Q)%LENGTH;
}

int HashDictionary::findPos(const string &word)const
{
	int i=hash(word);//������� ������ ����� � �������
	for(int counter=0;counter<LENGTH;++counter)
	{
		if(dict[i]==NULL || *dict[i]==word)
			return i;//����� ��� ������� ��� ��� ������� �������
		else if(++i==LENGTH)
			i=0;//������� � ���������� �������
	}
	return -1;//��������� ��� ������� � �������
}

void HashDictionary::add(const string &word)
{
	int i=findPos(word);//������� ����� � �������
	if(i==-1)
		return;//� ������ ������������ �������
	if(dict[i]==NULL)
		dict[i]= new string();
	*dict[i]=word;//���������� ����� � ��� ����������	
}

bool HashDictionary::hasWord(const string &word) const
{
	int i=findPos(word);
	return i!=-1 && dict[i]!=NULL;
}

void HashDictionary::output()
{
	for(int i=0;i<LENGTH;++i)
	{
	  if(dict[i])
		cout<<i<<" "<<*dict[i]<<endl;
	}
}