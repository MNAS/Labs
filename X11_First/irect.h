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

#ifndef IRECT_H
#define IRECT_H

class iRect
{
public:
    iRect();
    iRect(const iRect& other);
    ~iRect();
    iRect& operator=(const iRect& other);
    bool operator==(const iRect& other);
public:
  int getMinX() const;
  int getMinY() const;
  int getMaxX() const;
  int getMaxY() const;
private:
    iPoint origin;
    iPoint size;
};

#endif // IRECT_H
