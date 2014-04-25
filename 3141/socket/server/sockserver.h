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

#ifndef SOCKSERVER_H
#define SOCKSERVER_H

#include <sys/socket.h>
#include <set>

#ifndef BUF_SIZE
#define BUF_SIZE 500
#endif

class SockServer
{
private:
  int sfd; 		// Дескриптор открытого сокета.
  int port;		// Номер порта.
  bool connected;	// Состояние порта (соединен / не соединен).
  char buf[BUF_SIZE];	// Буфер обмена.
  std::set<sockaddr_storage>  set_sockaddr_storage;
public:
    SockServer();
    bool connect(const char * Port);
    void exec();
    ~SockServer();
};

#endif // SOCKSERVER_H

