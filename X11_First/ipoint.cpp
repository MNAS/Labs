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

#include "ipoint.h"

iPoint::iPoint():x(0),y(0)
{
}

iPoint::iPoint(int x, int y)
{
    this->x=x;
    this->y=y;
}

iPoint::iPoint(const iPoint& other)
{
    x=other.x;
    y=other.y;
}

iPoint::~iPoint()
{

}

iPoint& iPoint::operator=(const iPoint& other)
{
    x=other.x;
    y=other.y;
    return *this;
}

bool iPoint::operator==(const iPoint& other)
{
    return x==other.x&&y==other.y;
}
