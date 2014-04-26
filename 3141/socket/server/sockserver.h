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

#include "sockaddr.h"
#include <string>


class SockServer
{
private:
  int sfd; 			// Дескриптор открытого сокета.
  int port;			// Номер порта.
  bool connected;		// Состояние порта (соединен / не соединен).
  char buf_in[BUF_SIZE];	// Буфер обмена для входящих сообщений.
  char buf_out[BUF_SIZE];        // Буфер обмена для исходящих сообщений.
  std::set<SockAddr> set_Addr;	// Set of connected clients.
  time_t dilay;                 // Время задержки в секундах исключением от списка рассылки сообщений сервера.
public:
    SockServer(time_t a_Dilay = 60);
    bool connect(const char * Port);
    void exec();
    ~SockServer();
    void sendToAll(const std::string & form_host, const std::string & form_servise );		//Направление сообщения всем подключенным клиентам.
    friend std::ostream& operator<<(std::ostream& os, const  SockServer &a );
    static std::string ctime();
    void disconnectFromOverdue();
};

#endif // SOCKSERVER_H

