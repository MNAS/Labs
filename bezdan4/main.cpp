
#include <iostream>
#include "hill.h"


//функция шифрования строки по методу Хилла
//принемает строку
//массив 3 на 3 - ключ
//возвращает зашифрованную строку
std::string encode(std::string s, std::string alf, key k)
{
    char ch;
    vector p;
    vector c;
    int size=k.keySize();
    int sSize=s.size();
    int ostatok=sSize%size;
    std::string sRes;
    if(ostatok!=0)
    {
      for(int i=0; i<size-ostatok; i++)
      {
	  s+=alf[0];
      }
    }
    for(int i=0; i<s.size()/size; i++)
    {
        for(int j=0; j<size; j++)
        {
            ch=s.at(j+i*size);
            p.setVector(j, alf.find(ch));
        }
	c=k.mult(p);
	c.mod(alf.size());
	for(int j=0;j<size;j++)
	{
	  char symb=alf.at(c.getSymb(j));
	  sRes=sRes+symb;
	}
    }
    return sRes;
}



int main(int argc, char **argv) {
    std::string S;
    std::cin>>S;
    std::string alf="abcdefghijklmnopqrstuvwxyz";
    std::string Sres;
    key k;
    Sres=encode(S, alf, k);
    std::cout<<Sres<<std::endl;
    key obrK(1);
    Sres=encode(Sres, alf, obrK);
    std::cout<<Sres<<std::endl;
    return 0;
 }





