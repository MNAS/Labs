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
private:
    static int N;
    Koloda *k; ///<Колода карт.
    Dom *dom;  ///<Дом, состоящий из 4-х стопок.
    Sdacha *sd; ///<
    std::vector<Stopka*> *stopki;
    Stopka *selected;///<Перетаскиваемые карты
public:
    Stol();
    Stol(const Stol& other);
    ~Stol();
    Stol& operator=(const Stol& other);
    bool operator==(const Stol& other);
    
    void output();
    friend std::ostream& operator<<(std::ostream &os, Stol& st);
    void moveStopkaDom(int s);
    void moveDomStopka(int mast, int s );///<Перемещение масти mast из дома в стопку s.
    void moveStopkaStopka(int sFrom, int sTo, int num );///<Перемещение из количества карт num из стопки sFrom в стопку sTo.
    void moveRazdachaStopka(int sTo);
    void moveRazdachaDom();
    void openNext();
///    StructFind findByName(String name);
    void loop();
    void loop1();
};


#endif // STOL_H
