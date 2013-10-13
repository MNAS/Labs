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

#ifndef WINDOWPARAMS_H
#define WINDOWPARAMS_H

#include "drect.h"
#include "irect.h"

class WindowParams
{
public:
    WindowParams();
    WindowParams(double minX, double maxX, double minY, double maxY, int i1, int i2, int j1, int j2);
    WindowParams(dRect dR, iRect iR);
    WindowParams(const WindowParams& other);
    ~WindowParams();
private:
    dRect dR;
    iRect iR;
public:
  iPoint toScreen(dPoint dP) const;
  dPoint toReal(iPoint iP) const;
  void draw() const;
};

#endif // WINDOWPARAMS_H
