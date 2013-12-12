#include <stdio.h>
#include <string.h>
#include <iostream>

void encode(char c)
{
      switch(c)
    {
      case 0:
	std::cout<<" -2";
	break;
      case 1:
	std::cout<<" -1";
	break;
      case 2:
	std::cout<<" +1";
	break;
      case 3:
	std::cout<<" +2";
	break;
    }
}


int main(int argc, char **argv) {
  char symb1;
  char symb2;
  std::string s;
  std::cin>>s;
  for(int i=0; i<s.size();i++)
  {
    symb1=s.at(i);
    symb2=(symb1&0xC0)>>6;//наложидли маску(11000000) на рассматриваемый байт и сдвинули вправо на 6 разрядов
    encode(symb2);
    symb2=(symb1&0x30)>>4;
    encode(symb2);
    symb2=(symb1&0xC)>>2;
    encode(symb2);
    symb2=symb1&0x3;
    encode(symb2);
  }
  return 0;
}
