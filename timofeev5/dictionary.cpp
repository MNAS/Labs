#include "hash.h"
#include <iostream>
#include <string.h>
using namespace std;

int HashDictionary::code(char c)
{
	char alf[]="abcdefghijklmnopqrstuvwxyz";
	return strchr(alf,c)-alf+1;//выдает номер входящего символа в латинском алфавите
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
	int i=hash(word);//текущий индекс слова в словаре
	for(int counter=0;counter<LENGTH;++counter)
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
		dict[i]= new string();
	*dict[i]=word;//добавление слова и его перезапись	
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