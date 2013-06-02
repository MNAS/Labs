
#include <iostream>
#include <string.h>
using namespace std;


// ласс, представл€ющий словарь в виде хэш-таблицы


class HashDictionary{
private:
	static const int P=7549;
	static const int Q=4639;
	static const int LENGTH=8193;
	
	string *dict[10000];// хранилище на 1000 слов
	
	static int code(const char c);//функци€ определ€ет код буквы как ее пор€дковый номер в латинском алфавите
	int findPos(const string &word) const;//внутренн€€ функци€ поиска позиции слова в словаре
public:
	HashDictionary(){memset(dict,0,sizeof(dict));};//конструктор записывает в словарь пустые ссылки
	static int hash(const string &str);//функци€ расстановки, основанна€ на сложении кодов букв со смещением, соответствующим их позиции
	void add(const string &word);//функци€ добавлени€ слова в словарь
	bool hasWord(const string &word) const;//функци€ проверки наличи€ слова в словаре
	void output();
};