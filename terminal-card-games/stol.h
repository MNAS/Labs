#ifndef STOL_H
#define STOL_H

#include "koloda.h"
#include "dom.h"
#include "sdacha.h"
#include "stopka.h"
#include <vector>
#include <iostream>

class Stol
{
    friend std::ostream &operator<<(std::ostream &os, Stol &st);
public:
    static int N_stopok;						///<Количество стопок.
    Koloda *k;								///<Колода карт.
    Dom *dom;								///<Дом, состоящий из 4-х стопок.
    Sdacha *sd;								///<Раздача, состоящая из открытой и закрытой частей.
    std::vector<Stopka *> *stopki;					///<Вектор стопок.
    Stopka *selected;							///<Перетаскиваемые карты

private:
    bool isWin();							///<Возвращает true если игра закончилась победой.
    bool isLoose();							///<Возвращает true если игра закончилась поражением.
public:
    Stol();
    Stol(const Stol &other);
    ~Stol();
    Stol &operator=(const Stol &other);
    bool operator==(const Stol &other);

    void razdacha();							///<Выполняет раздачу карт на стопки.
    void clear();							///<Выполняет очистку стопок, раздачи и дома.
    void moveStopkaDom(Stopka *from, Stopka *to);			///<Перемещение карты из стопки в дом.
    void moveDomStopka(Stopka *from, Stopka *to);			///<Перемещение масти mast из дома в стопку s.
    void moveStopkaStopka(int sFrom, int sTo, int num);			///<Перемещение из количества карт num из стопки sFrom в стопку sTo.
    void moveStopkaStopka(Stopka *from, Stopka *to, int num = 1);	///<Перемещение из стопки ИЗ в стопку В количества карт num.
    void moveRazdachaStopka(Stopka *from, Stopka *to);
    void moveRazdachaDom(Stopka *from, Stopka *to);
    void openNext();							///<Открытие следующей карты.
    void loop();							///<Цикл выполнения команд.
    void help();							///<Вызов консольной справки.
};
#endif // STOL_H
