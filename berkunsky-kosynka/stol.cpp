/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2013  <copyright holder> <email>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "stol.h"
#include <iostream>

int Stol::N=7;

Stol::Stol():k(0),dom(0),sd(0),selected(0),stopki(0)
{
    k=new Koloda;
    dom=new Dom;
    sd=new Sdacha;
    selected=new Stopka;
    stopki=new std::vector<Stopka*>;

    k->peretosovat();
    int kolN=0;//
    for (int i=0; i<N ; ++i)
    {
        Stopka *s=new Stopka;
        stopki->push_back(s);
        for(int j=0; j<=i; ++j)
        {
            stopki->at(i)->stopka->push_back(k->getKoloda()->at(kolN++));
        }
        stopki->at(i)->openLastCard();
    }
    sd->opened->stopka->push_back(k->getKoloda()->at(kolN++));//Добавление в открытую часть сдачи карт.
    sd->opened->openLastCard();
    while(kolN<k->getN())
    {
        sd->closed->stopka->push_back(k->getKoloda()->at(kolN++));//Добавление в склытую часть сдачи карт.
    }

}

Stol::Stol(const Stol& other)
{

}

Stol::~Stol()
{

}

Stol& Stol::operator=(const Stol& other)
{

}

bool Stol::operator==(const Stol& other)
{
    return true;
}


/*****************************************************************************/

void Stol::output()
{
    int sdClosedSize = sd->closed->stopka->size();
    int sdOpenedSize = sd->opened->stopka->size();

    std::cout<<"Стол"<<"\n";
    sd->output();

    int size = stopki->size();
    std::cout<<"Стол.Стопки\n";
    for (int i=0; i<size; i++) {
        std::cout<<"Стопка "<<i;
        stopki->at(i)->output();
    }
    dom->output();
}

void Stol::moveStopkaDom(int s)
{
    Stopka *stDom = NULL;

    Card *cd=stopki->at(s)->getLastCard();
    if(cd==NULL) return;
    else {
        switch(cd->getMast())
        {
        case 0:
            stDom=dom->A;
            break;
        case 1:
            stDom=dom->B;
            break;
        case 2:
            stDom=dom->C;
            break;
        case 3:
            stDom=dom->D;
            break;
        }
        Card *a=stDom->getLastCard();
        if( (a==NULL && cd->getStarshinstvo()==0) ||
                (cd->getStarshinstvo()-a->getStarshinstvo()==1))
        {
///            stopki->at(s)->stopka->erase(stopki->at(s)->stopka->begin()+cd);
            stDom->stopka->push_back(cd);
            stopki->at(s)->openLastCard();
        }

    }
}

void Stol::moveDomStopka(int mast, int s )
{
    Card *cd=NULL;
    Stopka *a=NULL;
    switch(mast) {
    case 0:
        a=dom->A;
        break;
    case 1:
        a=dom->B;
        break;
    case 2:
        a=dom->C;
        break;
    case 3:
        a=dom->D;
        break;
    }
    if(a!=NULL)
    {
        cd=a->getFirstCard();
        if(cd!=NULL)
	{
 //           a->stopka->erase(cd);//////////////////////
	}
        stopki->at(s)->stopka->push_back(cd);
    }

}

void Stol::moveStopkaStopka(int sFrom, int sTo, int num )
{

    Card *cd=stopki->at(sFrom)->stopka->at(stopki->at(sFrom)->stopka->size()-num);//snimaem num ot kraya kart
    if(cd==NULL || cd->getSostoyanie()==0)
        return;
    Card *a=stopki->at(sTo)->getLastCard();//karta iz stopki 2

    if((a==NULL && cd->getStarshinstvo()==12)
            || (a!=NULL && a->isBlack()!=cd->isBlack() &&
                a->getStarshinstvo()-cd->getStarshinstvo()==1))
    {
        int iFrom=stopki->at(sFrom)->stopka->size()-num;
        int iTo=stopki->at(sFrom)->stopka->size();


//        std::vector<Card*> subList = stopki->at(sFrom)->stopka->subList(iFrom,iTo);
//        stopki->at(sTo)->stopka->addAll(subList);
//        stopki->at(sFrom)->stopka->removeAll(subList);
        stopki->at(sFrom)->openLastCard();
    }
}

void Stol::moveRazdachaStopka(int sTo)
{

    Card *cd=sd->opened->getLastCard();//karta iz razdachi
    if(cd==NULL) return;
    Card *a=stopki->at(sTo)->getLastCard();//karta iz stopki
    if((a==NULL && cd->getStarshinstvo()==12)
            ||(a!=NULL && a->isBlack()!=cd->isBlack() && a->getStarshinstvo()-cd->getStarshinstvo()==1))
    {
//        sd->opened->stopka->remove(cd);
        stopki->at(sTo)->stopka->push_back(cd);

    }

}

void Stol::moveRazdachaDom()
{
    Stopka *stDom = NULL;

    Card *cd=sd->opened->getLastCard();
    if(cd==NULL) return;
    else {
        switch(cd->getMast()) {
        case 0:
            stDom=dom->A;
            break;
        case 1:
            stDom=dom->B;
            break;
        case 2:
            stDom=dom->C;
            break;
        case 3:
            stDom=dom->D;
            break;
        }
        Card *a=stDom->getLastCard();
        if( (a==NULL && cd->getStarshinstvo()==0) ||
                (cd->getStarshinstvo()-a->getStarshinstvo()==1)) {
//            sd->opened->stopka.remove(cd);
            stDom->stopka->push_back(cd);
        }
    }
}

void Stol::openNext()
{
    Card *cd=sd->closed->getFirstCard();
    if(cd == NULL)
    {
 //       sd->closed->stopka->addAll(sd->opened->stopka);
        sd->opened->stopka->clear();
        sd->closed->closeCards();
    }
    else
    {
 //       sd->closed->stopka->remove(cd);
        sd->opened->stopka->push_back(cd);
        cd->setSostoyanie(1);
    }

}


/*
StructFind Stol::findByName(String name)
{
    StructFind f=new StructFind();
    if(name.equals("0") || name.equals("1") || name.equals("2") ||
            name.equals("3") || name.equals("4") || name.equals("5") || name.equals("6") ||
            name.equals("7") || name.equals("8") || name.equals("9") || name.equals("10"))
    {
        f.indOfStopka=Integer.parseInt(name);
        f.indOfCard=0;
        f.numCards=0;
        return f;
    }
    Card a=null;
    int ind=0;
    for(int i=0; i<k.getN(); ++i) {
        if(k.getKoloda()[i].name().equals(name))
        {
            a=k.getKoloda()[i];
            break;
        }
    }
    for(int i=0; i<stopki.size(); ++i) {
        ind=stopki.get(i).stopka.indexOf(a);//nahodit index zadanoy karti po imeni v kolode
        if(ind!=-1 && a.getSostoyanie()!=0)
        {
            f.indOfStopka=i;
            f.indOfCard=ind;
            f.numCards=stopki.get(i).stopka.size()-f.indOfCard;
            return f;
        }
    }
    if(sd.opened.getLastCard()!=null && sd.opened.getLastCard().name().equals(name)) {
        f.indOfStopka=11;
        f.indOfCard=sd.opened.stopka.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.A.getLastCard()!=null && dom.A.getLastCard().name().equals(name)) {
        f.indOfStopka=7;
        f.indOfCard=dom.A.stopka.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.B.getLastCard()!=null && dom.B.getLastCard().name().equals(name)) {
        f.indOfStopka=8;
        f.indOfCard=dom.B.stopka.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.C.getLastCard()!=null && dom.C.getLastCard().name().equals(name)) {
        f.indOfStopka=9;
        f.indOfCard=dom.C.stopka.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.D.getLastCard()!=null && dom.D.getLastCard().name().equals(name)) {
        f.indOfStopka=10;
        f.indOfCard=dom.D.stopka.size()-1;
        f.numCards=1;
        return f;
    }
    return null;
}
*/

void Stol::loop()
{
    bool exit=true;
    while(exit) {
        output();
        std::cout<<"Menu:"<<"\n"
	<<"0 - Exit;\n"<<"1 - Next Card;"<<"\n"
	<<"2 [Из_стопки] [В_стопку] [К-во_карт]"<<"\n"
	<<"3 [Из_стопки] - из стопки в дом"<<"\n"
        <<"4 [Из_дома_масть] [В_стопку номер] - из дома в стопку"<<"\n"
        <<"5 [В_стопку номер] - из раздачи в стопку"<<"\n"
        <<"6 - из раздачи в дом"<<"\n";
	std::cout.flush();
    }
/*
        String a=scan.nextLine();
        if(a.equals("0"))
            exit=false;
        else if(a.equals("1"))
            openNext();
        else if(a.equals("3"))
        {
            int sForm=scan.nextInt();
            moveStopkaDom(sForm);
        }
        else if(a.equals("6"))
            moveRazdachaDom();
        else if(a.equals("5")) {
            int sTo=scan.nextInt();
            moveRazdachaStopka(sTo);
        }

        else if(a.equals("2")) {
            int sFrom=scan.nextInt();
            int sTo=scan.nextInt();
            int num=scan.nextInt();
            moveStopkaStopka(sFrom,sTo,num);
        }
    }
*/    
}

void Stol::loop1()
{
/*
  StructFind sFrom=null;
    StructFind sTo=null;
    boolean exit=true;
    Scanner scan= new Scanner(System.in);
    while(exit) {
        output();
        System.out.println("Menu:\nExit - Exit from program;");
        System.out.println("N - Next Card;");
        System.out.println("From  To - из в. Из мб - Дом;");

        String from = null;
        String to = null;
        String a=scan.nextLine();
        String[] split = a.split(" ");
        System.out.println(a);
        if(split.length==1) {
            from=split[0];
            sFrom=findByName(from);
        }
        else if(split.length==2) {
            from=split[0];
            to=split[1];
            sFrom=findByName(from);
            sTo=findByName(to);
        }

        if(from.equals("выход"))
            exit=false;
        else if(to!=NULL && to.equals("0")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 0, sFrom.numCards);
        else if(to!=NULL && to.equals("1")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 1, sFrom.numCards);
        else if(to!=NULL && to.equals("2")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 2, sFrom.numCards);
        else if(to!=NULL && to.equals("3")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 3, sFrom.numCards);
        else if(to!=NULL && to.equals("4")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 4, sFrom.numCards);
        else if(to!=NULL && to.equals("5")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 5, sFrom.numCards);
        else if(to!=NULL && to.equals("6")&& sFrom!=NULL && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7))
            moveStopkaStopka(sFrom.indOfStopka, 6, sFrom.numCards);

        else if(from.equals("н"))
            openNext();

        else if(sTo!=NULL && sFrom!=NULL && (sTo.indOfStopka>=0 && sTo.indOfStopka<7) && sFrom.indOfStopka==11) {
            moveRazdachaStopka(sTo.indOfStopka);
        }
        else if(sTo!=NULL && sFrom!=NULL && (sTo.indOfStopka>=0 && sTo.indOfStopka<7) && (sFrom.indOfStopka>=0 && sFrom.indOfStopka<7)) {
            moveStopkaStopka(sFrom.indOfStopka, sTo.indOfStopka, sFrom.numCards);
        }
        else if(sFrom!=NULL &&(sFrom.indOfStopka>=0 && sFrom.indOfStopka<7) && to.equals("дом")) {
            moveStopkaDom(sFrom.indOfStopka);
        }
        else if(sFrom!=NULL && sFrom.indOfStopka==11  && to.equals("дом")) {
            moveRazdachaDom();
        }
        else if(sTo!=NULL && sFrom!=NULL && (sTo.indOfStopka>=0 && sTo.indOfStopka<7)  && (sFrom.indOfStopka>=7 && sFrom.indOfStopka<=10)) {
            moveDomStopka(sFrom.indOfStopka-7, sTo.indOfStopka);
        }
    }
*/    
}

