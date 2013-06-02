#include "hash.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	string a;//промежуточная строка
	HashDictionary A;
	std::cout<<argv[1]<<" "<<A.hash(argv[1])<<std::endl;
	/*fstream fs;
	fs.open (argv[1],fstream::in);
	while(fs)
	{
		fs>>a;
		cout<<a<<endl;
		A.add(a);
	}
	A.output();
	fs.close();*/
	A.add("sonia");
	A.output();
	return 0;
}