/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
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

#include "sockaddr.h"
#include <string.h>
#include <time.h>

SockAddr::SockAddr() : host ( "" ), service ( "" )
{
  memset ( & addr, 0, sizeof ( addr ) );
  DisconnectTime = time ( NULL ) + 60.;
}

SockAddr::SockAddr ( const sockaddr_storage& p_addr, char* a_host, char* a_service, time_t delta )
{
  memset ( & addr, 0, sizeof ( addr ) );
  addr = p_addr;
  host = a_host;
  service = a_service;
  DisconnectTime = time ( NULL ) + delta;
}


SockAddr & SockAddr::init ( const sockaddr_storage& p_addr, char* a_host, char* a_service, time_t delta )
{
  addr = p_addr;
  host = a_host;
  service = a_service;
  DisconnectTime = time ( NULL ) + delta;
  return *this;
}

SockAddr::SockAddr ( const SockAddr & other )
{
  addr = other.addr ;
  host = other.host ;
  service = other.service ;
  DisconnectTime = other.DisconnectTime;
}

SockAddr& SockAddr::operator= ( const SockAddr & other )
{
  addr = other.addr ;
  host = other.host ;
  service = other.service ;
  DisconnectTime = other.DisconnectTime;
}

SockAddr::~SockAddr()
{
}

bool SockAddr::operator== ( const SockAddr & other ) const
{
  return host == other.host && service == other.service;
}

bool SockAddr::operator< ( const SockAddr & other ) const
{
  if ( host < other.host )
    return true;

  return service < other.service;
}

std::ostream& operator<< ( std::ostream& os, const SockAddr &a )
{
  char out[80];
  struct tm * timeinfo;
  timeinfo = localtime ( &a.DisconnectTime );
  strftime ( out, 80, "%F %X", timeinfo );
  
  os << a.host << " " << a.service << " Will disconnect at: " << out;
}

// void SockAddr::cDisconnectTime() const
// {
//   char out[80];
//   struct tm * timeinfo;
//   timeinfo = localtime ( &DisconnectTime );
//   strftime ( out, 80, "%F %X", timeinfo );
//   discTime = std::string(out);
// }

bool SockAddr::isOverdue() const
{
  return time(NULL) > DisconnectTime;
}
