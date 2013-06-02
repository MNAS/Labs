#include "hash.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    string a;//промежуточная строка
    HashDictionary A(25,23,19);
    fstream fs;
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
        A.add(a);
    }
    A.output();
    fs.close();
    
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
        cout<<A.findKey(a)<<" "<<a<<endl;
    }
    fs.close();
    
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
        cout<<A.hasWord(a)<<" "<<a<<endl;
    }
    fs.close();
    
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
	A.del(a);
	A.output();
        
    }
    fs.close();
    return 0;
}
