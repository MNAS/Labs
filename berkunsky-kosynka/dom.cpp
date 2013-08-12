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

#include "dom.h"
#include <iostream>

Dom::Dom()
{
    A=new Stopka;
    B=new Stopka;
    C=new Stopka;
    D=new Stopka;
}

Dom::Dom(const Dom& other)
{

}

Dom::~Dom()
{

}

Dom& Dom::operator=(const Dom& other)
{

}

bool Dom::operator==(const Dom& other)
{

}

void Dom::output()
{
    std::cout<<"\nDom";

    if(A->stopka.empty()) std::cout<<"--";
    else A->output();

    if(B->stopka.empty()) std::cout<<"--";
    else B->output();

    if(C->stopka.empty())  std::cout<<"--";
    else C->output();

    if(D->stopka.empty())  std::cout<<"--";
    else D->output();

    std::cout<<"\n";
    std::cout.flush();
}
