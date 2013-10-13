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

#include <math.h>
#include "windowparams.h"

WindowParams::WindowParams()
{

}

WindowParams::WindowParams(const WindowParams& other)
{

}

WindowParams::~WindowParams()
{

}

iPoint WindowParams::toScreen(dPoint dP) const
{
    return iPoint
           (iR.getMinX()+
            round((dP.x-dR.getMinX())*
                  (iR.getMaxX()-iR.getMinX())/(dR.getMaxX()-dR.getMinX())),
            iR.getMinY()+
            round((dP.y-dR.getMinY())*
                  (iR.getMaxY()-iR.getMinY())/(dR.getMaxY()-dR.getMinY()))
           );
}

dPoint WindowParams::toReal(iPoint iP) const
{
    return dPoint
           (dR.getMinX()+
            round((iP.x-iR.getMinX())*
                  (dR.getMaxX()-dR.getMinX())/(iR.getMaxX()-iR.getMinX())),
            dR.getMinY()+
            round((iP.y-iR.getMinY())*
                  (dR.getMaxY()-dR.getMinY())/(iR.getMaxY()-iR.getMinY()))
           );
}

void WindowParams::draw() const
{
  
}
