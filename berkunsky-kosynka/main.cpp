#include <QtGui/QApplication>
#include "berkunsky-kosynka.h"


// int main(int argc, char** argv)
// {
//     QApplication app(argc, argv);
//     berkunsky_kosynka foo;
//     foo.show();
//     return app.exec();
// }

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

#include <string>
#include <iostream>
#include <ctime>
#include "stol.h"


int main() {
//     boost::random::mt19937 gen(std::time(0));
//     boost::random::uniform_int_distribution<> dist(1, 52);
    Koloda* k=new Koloda;
    k->cardsFaceUp();
    std::cout<<(*k);
    k->peretosovat();
    std::cout<<(*k);
//     Stol *st=new Stol;
    
//     for(int i = 0; i < 52; ++i) 
//     {
//       std::cout << dist(gen)<<"\n";
//     }
//     std::cout << std::endl;
}
