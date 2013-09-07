#include "stol.h"
#include <iostream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

int Stol::N_stopok = 7;

Stol::Stol(): k(0), dom(0), sd(0), selected(0), stopki(0)
{
    k = new Koloda;
    dom = new Dom;
    sd = new Sdacha;
    selected = new Stopka;

    stopki = new std::vector<Stopka *>;
    for (int i = 0; i < N_stopok ; ++i) {
        Stopka *s = new Stopka;
        stopki->push_back(s);
    }
    razdacha();
}

void Stol::razdacha()
{
    clear();
    k->peretosovat();
    k->cardsFaceDown();
    int kolN = 0; //
    for (int i = 0; i < N_stopok ; ++i) {
        for (int j = 0; j <= i; ++j) {
            stopki->at(i)->cards->push_back(k->getKoloda()->at(kolN++));
        }
        stopki->at(i)->openLastCard();
    }
    sd->opened->cards->push_back(k->getKoloda()->at(kolN++));//Добавление в открытую часть сдачи карт.
    sd->opened->openLastCard();
    while (kolN < k->getN()) {
        sd->closed->cards->push_back(k->getKoloda()->at(kolN++));//Добавление в склытую часть сдачи карт.
    }
}

void Stol::clear()
{
    for (int i = 0; i < N_stopok ; ++i) {
        stopki->at(i)->cards->clear();
    }
    sd->opened->cards->clear();
    sd->closed->cards->clear();
    dom->A->cards->clear();
    dom->B->cards->clear();
    dom->C->cards->clear();
    dom->D->cards->clear();
}

Stol::Stol(const Stol &other)
{

}

Stol::~Stol()
{

}

Stol &Stol::operator=(const Stol &other)
{

}

bool Stol::operator==(const Stol &other)
{
    return true;
}

std::ostream &operator<<(std::ostream &os, Stol &st)
{
    int sdClosedSize = st.sd->closed->cards->size();
    int sdOpenedSize = st.sd->opened->cards->size();
    os << (*st.sd);
    std::string k = "asdfghj";

    int size = st.stopki->size();
    for (int i = 0; i < size; i++) {
        os << "K" << i << " " << "{" << k.at(i) << "}" << " ";
        os << (*st.stopki->at(i));
    }
    os << (*st.dom);
    return os;
}

void Stol::moveStopkaDom(Stopka *from, Stopka *to)
{
    Card *cd = from->getLastCard();
    if (cd == NULL)
        return;
    Card *a = to->getLastCard();
    if ((a == NULL && cd->getStarshinstvo() == 1) ||
            (a && cd->getStarshinstvo() - a->getStarshinstvo() == 1) &&
            cd->getMast() == a->getMast()
       ) {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end() - 1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveDomStopka(Stopka *from, Stopka *to)
{
    Card *cd = from->getLastCard();
    if (cd == NULL)
        return;
    Card *a = to->getLastCard();
    if (a && a->getStarshinstvo() - cd->getStarshinstvo() == 1 &&
            cd->isBlack() != a->isBlack()
       ) {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end() - 1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveStopkaStopka(Stopka *from, Stopka *to, int num)
{

    Card *cd = from->cards->at(from->cards->size() - num); //snimaem num ot kraya kart
    if (cd == NULL || cd->getSostoyanie() == 0)
        return;
    Card *a = to->getLastCard(); //karta iz stopki 2

    if ((a == NULL && cd->getStarshinstvo() == 13)
            || (a != NULL && a->isBlack() != cd->isBlack() &&
                a->getStarshinstvo() - cd->getStarshinstvo() == 1)) {
        int iFrom = from->cards->size() - num;
        int iTo = from->cards->size();
        for (int i = iFrom; i < iTo; ++i) {
            to->cards->push_back(from->cards->at(i));
        }
        from->cards->erase(from->cards->begin() + iFrom, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveRazdachaStopka(Stopka *from, Stopka *to)
{
    Card *cd = from->getLastCard();
    if (cd == NULL)
        return;
    Card *a = to->getLastCard();
    if (
        (!a && cd->getStarshinstvo() == 13) ||
        (a && a->isBlack() != cd->isBlack() &&
         a->getStarshinstvo() - cd->getStarshinstvo() == 1)) {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end() - 1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::moveRazdachaDom(Stopka *from, Stopka *to)
{
    Card *cd = from->getLastCard();
    if (cd == NULL) return;
    Card *a = to->getLastCard();
    if ((!a && cd->getStarshinstvo() == 1) ||
            (cd->getStarshinstvo() - a->getStarshinstvo() == 1 &&
             cd->getMast() == a->getMast())
       ) {
        to->cards->push_back(cd);
        from->cards->erase(from->cards->end() - 1, from->cards->end());
        from->openLastCard();
    }
}

void Stol::openNext()
{
    Card *cd = sd->closed->getFirstCard();
    if (cd == NULL) {
        sd->closed->cards->swap(*sd->opened->cards);
        sd->closed->closeCards();
    } else {
        sd->closed->cards->erase(sd->closed->cards->begin());
        sd->opened->cards->push_back(cd);
        cd->setSostoyanie(1);
    }
}

void Stol::loop()
{
    std::string t;
    std::vector<std::string> vt;
    bool doing = true;
    while (doing) {
        std::cout << *this;
        std::cout.flush();
        std::getline(std::cin, t);
        t = boost::trim_copy(t);

        boost::split(vt, t, boost::is_any_of(" "), boost::token_compress_on);
        if (vt.size() == 1 && vt.at(0) == "exit")
            doing = false;
        else if (vt.size() == 1 && vt.at(0) == "help")
            help();
        else if (vt.size() == 1 && vt.at(0) == "new")
            razdacha();
        else if (vt.size() == 1 && vt.at(0) == "q")
            openNext();
        else if (vt.size() >= 2) {
            int numCards = 1;
            try {
                if (vt.size() == 3)
                    numCards = std::stoi(vt.at(2));
            } catch (...) {
                std::cout << "Replacing :" << t << "\n"
                          << "to :" << vt.at(0) << " " << vt.at(1) << " " << 1 << std::endl;
                numCards = 1;
            }
            std::string st = "asdfghj";
//            std::string ST = "ASDFGHJ";
            std::string d = "zxcv";

            int d_from = -1;
            int d_to = -1;

            bool f_sdacha = false;
            bool f_stopka = false;
            bool t_stopka = false;
            bool f_dom = false;
            bool t_dom = false;

            Stopka *from = NULL;
            Stopka *to = NULL;

            if (vt.at(0) == std::string(1, 'w')) {
                f_sdacha = true;
                from = sd->opened;
            }
            for (int i = 0; i < st.size(); ++i)
                if (vt.at(0) == std::string(1, st.at(i))) {
                    from = stopki->at(i);
                    f_stopka = true;
                }
            for (int i = 0; i < st.size(); ++i)
                if (vt.at(1) == std::string(1, st.at(i))) {
                    to = stopki->at(i);
                    t_stopka = true;
                }
            if (to) std::cout << *to;

            for (int i = 0; i < d.size(); ++i)
                if (vt.at(0) == std::string(1, d.at(i)))
                    d_from = i;
            for (int i = 0; i < d.size(); ++i)
                if (vt.at(1) == std::string(1, d.at(i)))
                    d_to = i;
            switch (d_from) {
            case 0:
                from = dom->A;
                f_dom = true;
                break;
            case 1:
                from = dom->B;
                f_dom = true;
                break;
            case 2:
                from = dom->C;
                f_dom = true;
                break;
            case 3:
                from = dom->D;
                f_dom = true;
                break;
            default:
                break;
            }
            switch (d_to) {
            case 0:
                to = dom->A;
                t_dom = true;
                break;
            case 1:
                to = dom->B;
                t_dom = true;
                break;
            case 2:
                to = dom->C;
                t_dom = true;
                break;
            case 3:
                to = dom->D;
                t_dom = true;
                break;
            default:
                break;
            }
            if (!f_stopka && !f_sdacha && !f_dom) {
                for (int i = 0; i < N_stopok; ++i) {
                    for (int j = 0; j < stopki->at(i)->cards->size(); ++j) {
                        Card &ref = *stopki->at(i)->cards->at(j);
                        if (ref == Card(std::string(vt.at(0))) &&
                                ref.isFaceUp()) {
                            numCards = stopki->at(i)->cards->size() - j;
                            std::cout << i << " " << j << " " << numCards << " " << ref << std::endl;
                            from = stopki->at(i);
                            f_stopka = true;
                        }
                    }
                }

                Card *c = sd->opened->getLastCard();
                if (c && *c == Card(std::string(vt.at(0))) && c->isFaceUp()) {
                    from = sd->opened;
                    f_sdacha = true;
                }
                
            }

            if (!t_stopka && !t_dom) {
                for (int i = 0; i < N_stopok; ++i) {
                    for (int j = 0; j < stopki->at(i)->cards->size(); ++j) {
                        Card &ref = *stopki->at(i)->cards->at(j);
                        if (ref == Card(std::string(vt.at(1))) &&
                                ref.isFaceUp()) {
                            std::cout << i << " " << j << " " << numCards << " " << ref << std::endl;
                            to = stopki->at(i);
                            t_stopka = true;
                        }
                    }
                }
            }


            if (!t_stopka && !t_dom) {
                std::cout << "Not recognised to." << std::endl;
            }

            if (f_stopka && t_stopka)
                moveStopkaStopka(from, to, numCards);
            else if (f_stopka && t_dom)
                moveStopkaDom(from, to);
            else if (f_dom && t_stopka)
                moveDomStopka(from, to);
            else if (f_sdacha && t_stopka)
                moveRazdachaStopka(from, to);
            else if (f_sdacha && t_dom)
                moveRazdachaDom(from, to);
        }
    }
}

void Stol::help()
{
    std::cout << "Пасьянс косынка (консольная)." << "\n"
              << "Перечень доступных команд:" << "\n"
              << "exit - выход из программы;" << "\n"
              << "help - вывод на экран данной справки;" << "\n"
              << "Команды перетаскивания карт:" << "\n"
              << "Из_стопки [В_стопку] [Количество_карт]" << "\n"
              << "Из_стопки - обозначение стопки (символ, заключенный в фигурные скобки) или обозначение карты." << "\n"
              << "В_стопку  - обозначение стопки (символ, заключенный в фигурные скобки) или обозначение карты." << "\n"
              << "Обозначения старшинства карт:" << "\n"
              << "A - туз; 2-9; T - десятка; J - валет; Q - дама; K - король." << "\n"
              << "Обозначения мастей:" << "\n"
              << "s - пики; c - трефы; d - бубны; h - червы." << "\n";
    std::cout.flush();
    std::string s;
    std::getline(std::cin, s);
}
