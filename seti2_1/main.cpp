#include <stdio.h>
#include <string.h>
#include <iostream>

int decode(int i)
{
        switch(i)
    {
      case -2:
	return 0;
	break;
      case -1:
	return 1;
	break;
      case 1:
	return 2;
	break;
      case 2:
	return 3;
	break;
    }
}

int main(int argc, char **argv) {
  int symb1=-1;
  int symb2=1;
  int symb3=1;
  int symb4=-2;
  char bukva;
  while(std::cin.good())
  {
    std::cin>>symb1>>symb2>>symb3>>symb4;
    symb1=decode(symb1);
    symb2=decode(symb2);
    symb3=decode(symb3);
    symb4=decode(symb4);

    bukva=0;
    bukva=(symb1<<6)+(symb2<<4)+(symb3<<2)+symb4;
    std::cout<<bukva;
  }
  return 0;
}