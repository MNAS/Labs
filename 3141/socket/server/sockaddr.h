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

#ifndef SOCKADDR_H
#define SOCKADDR_H

#include <sys/socket.h>
#include <string>
#include <iostream>

class SockAddr
{
  friend class SockServer;
private:
  sockaddr_storage addr;
  std::string host;
  std::string service;
//   std::string discTime;
  time_t DisconnectTime;        // Время после, которого клиенту не будут отсылаться сообщения.

//    time ( &rawtime );
  
public:
  SockAddr();
  SockAddr( const sockaddr_storage& p_addr, char* a_host, char* a_service, time_t delta );
  SockAddr & init( const sockaddr_storage& p_addr, char* a_host, char* a_service, time_t delta );
  SockAddr(const SockAddr & other);
  
  ~SockAddr();
  
  SockAddr& operator= (const SockAddr & other);
  bool operator== (const SockAddr & other) const;
  bool operator< (const SockAddr & other) const;
  
  friend std::ostream& operator<<(std::ostream& os, const SockAddr &a );
  
//   void cDisconnectTime() const;
  
  bool isOverdue() const;
};

#endif // SOCKSERVER_H

