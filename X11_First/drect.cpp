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

#include "drect.h"

dRect::dRect():origin(0.0,0.0),size(0,0)
{

}

dRect::dRect(const dRect& other)
{
    origin=other.origin;
    size=other.size;
}

dRect::~dRect()
{

}

dRect& dRect::operator=(const dRect& other)
{
    origin=other.origin;
    size=other.size;
    return *this;
}

bool dRect::operator==(const dRect& other)
{
    return origin==other.origin && size == other.size;
}

int dRect::getMinX() const
{
    return origin.x;
}
int dRect::getMinY() const
{
    return origin.y;
}
int dRect::getMaxX() const
{
    return origin.x+size.x;
}
int dRect::getMaxY() const
{
    return origin.y+size.y;
}
