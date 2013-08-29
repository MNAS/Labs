#include "stol.h"
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

int Stol::N=7;

Stol::Stol():k(0),dom(0),sd(0),selected(0),stopki(0)
{
    k=new Koloda;
    dom=new Dom;
    sd=new Sdacha;
    selected=new Stopka;
    
    stopki=new std::vector<Stopka*>;
    for (int i=0; i<N ; ++i)
    {
        Stopka *s=new Stopka;
        stopki->push_back(s);
    }
    razdacha();
}

void Stol::razdacha()
{
    clear();
    k->peretosovat();
    k->cardsFaceDown();
    int kolN=0;//
    for (int i=0; i<N ; ++i)
    {
        for(int j=0; j<=i; ++j)
        {
            stopki->at(i)->cards->push_back(k->getKoloda()->at(kolN++));
        }
        stopki->at(i)->openLastCard();
    }
    sd->opened->cards->push_back(k->getKoloda()->at(kolN++));//Добавление в открытую часть сдачи карт.
    sd->opened->openLastCard();
    while(kolN<k->getN())
    {
        sd->closed->cards->push_back(k->getKoloda()->at(kolN++));//Добавление в склытую часть сдачи карт.
    }
}

void Stol::clear()
{
    for (int i=0; i<N ; ++i)
    {
        stopki->at(i)->cards->clear();
    }
    sd->opened->cards->clear();
    sd->closed->cards->clear();
    dom->A->cards->clear();
    dom->B->cards->clear(); 
    dom->C->cards->clear();
    dom->D->cards->clear();
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

std::ostream& operator<<(std::ostream &os, Stol &st)
{
    int sdClosedSize = st.sd->closed->cards->size();
    int sdOpenedSize = st.sd->opened->cards->size();
    os<<(*st.sd);
    std::string k="asdfghj";
    std::string K="ASDFGHJ";
    
    int size = st.stopki->size();
    for (int i=0; i<size; i++)
    {
        os<<"K"<<i<<" "<<"{"<<k.at(i)<<"}"<<"{"<<K.at(i)<<"}"<<" ";
        os<<(*st.stopki->at(i));
    }
    os<<(*st.dom);
    return os;
}

void Stol::moveStopkaDom(Stopka *from, Stopka *to)
{
    Card *cd=from->getLastCard();
    if(cd==NULL) 
	return;
    Card *a=to->getLastCard();
    if( (a==NULL && cd->getStarshinstvo()==1) ||
            (a && cd->getStarshinstvo()-a->getStarshinstvo()==1))
    {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end()-1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveDomStopka(Stopka *from, Stopka *to)
{
    Card *cd=from->getLastCard();
    if(cd==NULL) 
	return;
    Card *a=to->getLastCard();
    if(a && a->getStarshinstvo()-cd->getStarshinstvo()==1)
    {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end()-1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveStopkaStopka(Stopka *from, Stopka *to, int num )
{

    Card *cd=from->cards->at(from->cards->size()-num);//snimaem num ot kraya kart
    if(cd==NULL || cd->getSostoyanie()==0)
        return;
    Card *a=to->getLastCard();//karta iz stopki 2

    if((a==NULL && cd->getStarshinstvo()==13)
            || (a!=NULL && a->isBlack()!=cd->isBlack() &&
                a->getStarshinstvo()-cd->getStarshinstvo()==1))
    {
        int iFrom=from->cards->size()-num;
        int iTo=from->cards->size();
        for(int i=iFrom; i<iTo;++i)
        {
    	    to->cards->push_back(from->cards->at(i));
        }
        from->cards->erase(from->cards->begin()+iFrom, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveRazdachaStopka(Stopka *from, Stopka *to)
{
    Card *cd=from->getLastCard();
    if(cd==NULL) 
	return;
    Card *a=to->getLastCard();
    if(
	(!a && cd->getStarshinstvo()==13) ||
	(a && a->isBlack()!=cd->isBlack() && 
	a->getStarshinstvo()-cd->getStarshinstvo()==1))
    {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end()-1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveRazdachaDom(Stopka *from, Stopka *to)
{
    Card *cd=from->getLastCard();
    if(cd==NULL) return;
    Card *a=to->getLastCard();
    if( (!a && cd->getStarshinstvo()==1) ||
        (cd->getStarshinstvo()-a->getStarshinstvo()==1 &&
	 cd->getMast()==a->getMast()) 
        )
    {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end()-1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::openNext()
{
    Card *cd=sd->closed->getFirstCard();
    if(cd == NULL)
    {
        sd->closed->cards->swap(*sd->opened->cards);
//        sd->opened->cards->clear();
        sd->closed->closeCards();
    }
    else
    {
	sd->closed->cards->erase(sd->closed->cards->begin());
	sd->opened->cards->push_back(cd);
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
        ind=stopki.get(i).cards.indexOf(a);//nahodit index zadanoy karti po imeni v kolode
        if(ind!=-1 && a.getSostoyanie()!=0)
        {
            f.indOfStopka=i;
            f.indOfCard=ind;
            f.numCards=stopki.get(i).cards.size()-f.indOfCard;
            return f;
        }
    }
    if(sd.opened.getLastCard()!=null && sd.opened.getLastCard().name().equals(name)) {
        f.indOfStopka=11;
        f.indOfCard=sd.opened.cards.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.A.getLastCard()!=null && dom.A.getLastCard().name().equals(name)) {
        f.indOfStopka=7;
        f.indOfCard=dom.A.cards.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.B.getLastCard()!=null && dom.B.getLastCard().name().equals(name)) {
        f.indOfStopka=8;
        f.indOfCard=dom.B.cards.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.C.getLastCard()!=null && dom.C.getLastCard().name().equals(name)) {
        f.indOfStopka=9;
        f.indOfCard=dom.C.cards.size()-1;
        f.numCards=1;
        return f;
    }
    if(dom.D.getLastCard()!=null && dom.D.getLastCard().name().equals(name)) {
        f.indOfStopka=10;
        f.indOfCard=dom.D.cards.size()-1;
        f.numCards=1;
        return f;
    }
    return null;
}
*/

void Stol::loop()
{
    std::string t;
    std::vector<std::string> vt;
    bool doing=true;
    while(doing) 
    {
	std::cout<<*this;
	std::cout.flush();
	std::getline(std::cin,t);
	boost::split(vt,t,boost::is_any_of(" "), boost::token_compress_on);
	if(vt.size()==1 && vt.at(0)=="exit")
	    doing=false;
	else if(vt.size()==1 && vt.at(0)=="help")
	    help();
	else if(vt.size()==1 && vt.at(0)=="new")
	    razdacha();
	else if(vt.size()==1 && vt.at(0)=="q")
	    openNext();
	else if(vt.size()>=2)
	{
	    int numCards=1;
	    if(vt.size()==3)
		numCards=std::stoi(vt.at(2));
	    std::string st="asdfghj";
	    std::string ST="ASDFGHJ";
	    std::string d="zxcv";

	    int d_from=-1;
	    int d_to=-1;
	    
	    bool f_sdacha=false;
	    bool f_stopka=false;
	    bool t_stopka=false;
	    bool f_dom=false;
	    bool t_dom=false;

	    Stopka * from=NULL;
	    Stopka * to=NULL;
	    
	    if(vt.at(0)==std::string(1,'w'))
	    {
		f_sdacha=true;
		from=sd->opened;
	    }
	    for(int i=0; i<st.size(); ++i)
		if(vt.at(0)==std::string(1,st.at(i)))
		{    
		    from=stopki->at(i);
		    f_stopka=true;
		}
//	    if(from) std::cout<<*from;
	    for(int i=0; i<st.size(); ++i)
		if(vt.at(1)==std::string(1,st.at(i)))
		{
		    to=stopki->at(i);
		    t_stopka=true;
		}
	    if(to) std::cout<<*to;
	    
	    for(int i=0; i<d.size(); ++i)
		if(vt.at(0)==std::string(1,d.at(i)))
		    d_from=i;
	    for(int i=0; i<d.size();++i)
		if(vt.at(1)==std::string(1, d.at(i)))
		    d_to=i;
	    switch(d_from)
	    {
		case 0: from=dom->A; f_dom=true; break;
		case 1: from=dom->B; f_dom=true; break;
		case 2: from=dom->C; f_dom=true; break;
		case 3: from=dom->D; f_dom=true; break;
		default: break;
	    }
	    switch(d_to)
	    {
		case 0: to=dom->A; t_dom=true; break;
		case 1: to=dom->B; t_dom=true; break;
		case 2: to=dom->C; t_dom=true; break;
		case 3: to=dom->D; t_dom=true; break;
		default: break;
	    }
	    if ( f_stopka && t_stopka )
		moveStopkaStopka(from, to, numCards);
	    else if ( f_stopka && t_dom)
		moveStopkaDom(from, to);
	    else if ( f_dom && t_stopka)
		moveDomStopka(from,to);
	    else if ( f_sdacha && t_stopka )
		moveRazdachaStopka(from,to);
	    else if ( f_sdacha && t_dom)
		moveRazdachaDom(from, to);
	}
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

//    StructFind sFrom=null;
//    StructFind sTo=null;
    bool exit=true;
//    Scanner scan= new Scanner(System.in);
    while(exit) 
    {
        std::cout<<*this;
        std::cout<<"Menu:\nexit - Exit from program;";
        std::cout<<"From To - из в. To мб - home;";

        std::string from;
        std::string to;
        std::string a;
    }
//        scan.nextLine();
/*
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

void Stol::help()
{
    std::cout<<"Пасьянс косынка (консольная)"<<"\n"
	<<"Перечень доступных команд:"<<"\n"
	<<"exit - выход из пронраммы;"<<"\n"
	<<"help - вывод на экран данной справки;"<<"\n"
	<<"Команды перетаскивания карт:"<<"\n"
	<<"Из_стопки [В_стопку]"<<"\n"
	<<"Из_стопки - обозначение стопки (символ, заключенный в фигурные скобки)"<<"\n"
	<<"или обозначеие карты."<<"\n"
	<<"Обозначения старшинства карт:"<<"\n"
	<<"A - туз; 2, 3, 4, 5, 6, 7, 8, 9, T - десятка,"<<"\n"
	<<"J - валет, Q - дама, K король"<<"\n"
	<<"Обозначения мастей:"<<"\n"
	<<"s - пики, c - трефы, d - бубны, h - червы."<<"\n";
    std::cout.flush();
    std::string s;
    std::getline(std::cin, s);
}
