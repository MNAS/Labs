
#include <iostream>
#include <string.h>
using namespace std;


//Класс, представляющий словарь в виде хэш-таблицы

class HashDictionary{
private:
	//static const int P=7549;
	//static const int Q=4639;
	//static const int LENGTH=8193;
	
	const int P;
	const int Q;
	const int LENGTH;//длина словаря
	string **dict;// хранилище ключей
	string **defin;//хранилище значений
	const int keyLength;//длина ключа
	
	static int code(const char c);//функция определяет код буквы как ее порядковый номер в латинском алфавите
	int findPos(const string &word) const;//ищет пустую позицию для вставки слова в словарь
public:
	HashDictionary(int length, int p, int q);//конструктор записывает в словарь пустые ссылки
	int hash(const string &str)const;//функция расстановки, основанная на сложении кодов букв со смещением, соответствующим их позиции
	void add(const string &word, const string &def);//функция добавления слова в словарь
	bool hasWord(const string &word) const;//функция проверки наличия слова в словаре
	void output();
	int findKey(const string &word)const;//функция нахождения слова в словаре
	void del(const string &word);//функция удаления слова
};