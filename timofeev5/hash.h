
#include <iostream>
#include <string.h>
using namespace std;


//�����, �������������� ������� � ���� ���-�������


class HashDictionary{
private:
	static const int P=7549;
	static const int Q=4639;
	static const int LENGTH=8193;
	
	string *dict[10000];// ��������� �� 1000 ����
	
	static int code(const char c);//������� ���������� ��� ����� ��� �� ���������� ����� � ��������� ��������
	int findPos(const string &word) const;//���������� ������� ������ ������� ����� � �������
public:
	HashDictionary(){memset(dict,0,sizeof(dict));};//����������� ���������� � ������� ������ ������
	static int hash(const string &str);//������� �����������, ���������� �� �������� ����� ���� �� ���������, ��������������� �� �������
	void add(const string &word);//������� ���������� ����� � �������
	bool hasWord(const string &word) const;//������� �������� ������� ����� � �������
	void output();
};