#include "hash.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    string a,b;//промежуточная строка
    HashDictionary A(9,3,7);
    fstream fs;
    fs.open (argv[1],fstream::in);
    cout<<endl;
    cout<<"Add words"<<endl;

    while(fs.good())
    {
        fs>>a>>b;//все нечетные в а,все четные в b
        if(fs.good())
            A.add(a,b);
    }
    A.output();
    fs.close();

    cout<<endl;
    cout<<"Find word"<<endl;
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
        cout<<A.findKey(a)<<" "<<a<<endl;
    }
    cout<<A.findKey("blablabla")<<" blablabla"<<endl;
    fs.close();

    cout<<endl;
    cout<<"Existance of the word"<<endl;
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a;
        cout<<A.hasWord(a)<<" "<<a<<endl;
    }
    cout<<A.hasWord("blablabla")<<" blablabla"<<endl;
    fs.close();

    cout<<endl;
    cout<<"Delete word"<<endl;
    fs.open (argv[1],fstream::in);
    while(fs.good())
    {
        fs>>a>>b;
        if(fs.good())
            A.del(a);
        A.output();
        cout<<endl;
    }
    fs.close();
    return 0;
}
