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

#include "sockserver.h"

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <fcntl.h>
#include <iostream>
#include <time.h>
#include <string>

SockServer::SockServer ( time_t a_Dilay ) : dilay ( a_Dilay )
{
  sfd = -1;
  port = 0;
  connected = false;
}

bool SockServer::connect ( const char * Port )
{
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s;

  memset ( &hints, 0, sizeof ( struct addrinfo ) );
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
  hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
  hints.ai_protocol = 0;          /* Any protocol */
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  s = getaddrinfo ( NULL, Port, &hints, &result );

  if ( s != 0 ) {
    fprintf ( stderr, "getaddrinfo: %s\n", gai_strerror ( s ) );
    exit ( EXIT_FAILURE );
  }

  for ( rp = result; rp != NULL; rp = rp->ai_next ) {
    sfd = socket ( rp->ai_family, rp->ai_socktype, rp->ai_protocol );

    if ( sfd == -1 )
      continue;

    if ( bind ( sfd, rp->ai_addr, rp->ai_addrlen ) == 0 ) {
//            fcntl ( sfd, F_SETFL, O_NONBLOCK );
      break;                  /* Success */
    }

    close ( sfd );
  }

  if ( rp == NULL ) {             /* No address succeeded */
    fprintf ( stderr, "Could not bind\n" );
    exit ( EXIT_FAILURE );
  }

  freeaddrinfo ( result );        /* No longer needed */
  return true;
}

void SockServer::exec()
{
  int s;
  sockaddr_storage peer_addr;
  socklen_t peer_addr_len;
  ssize_t nread;

  for ( ;; ) {
    peer_addr_len = sizeof ( sockaddr_storage );
    nread = recvfrom ( sfd, buf_in, BUF_SIZE, 0, ( sockaddr * ) &peer_addr, &peer_addr_len );

    if ( nread == -1 )
      continue;               /* Ignore failed request */

    char host[NI_MAXHOST], service[NI_MAXSERV];
    s = getnameinfo ( ( sockaddr * ) &peer_addr, peer_addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV );

    if ( s == 0 ) {
      std::cout << "Received " << nread << " bytes from " << host << ":" << service << std::endl;
      SockAddr saddr ( peer_addr, host, service , dilay );
      set_Addr.erase ( saddr );
      set_Addr.insert ( saddr );

    } else
      std::cerr << "getnameinfo: " << gai_strerror ( s ) << std::endl;

    std::cout << *this;
    disconnectFromOverdue();
    sendToAll ( std::string ( host ), std::string ( service ) );
  }
}

SockServer::~SockServer()
{

}

void SockServer::sendToAll ( const std::string& form_host, const std::string& form_servise )
{
  std::cout << "SockServer::sendToAll() - start" << std::endl;

  for ( std::set<SockAddr>::iterator it = set_Addr.begin(); it != set_Addr.end(); ++it ) {
    std::string out = SockServer::ctime() + " " + form_host + "/" + form_servise + ": " + buf_in;
    strcpy ( buf_out, out.c_str() );
    std::cout << "Message :\"" << buf_out << "\"" << " Send to :" << it->host << ":" << it->service << std::endl;
    int nread = strlen ( buf_out ) + 1;

    if ( sendto ( sfd, buf_out, nread, 0, ( sockaddr * ) & ( it->addr ), sizeof ( sockaddr_storage ) ) != nread )
      std::cerr << "Error sending response" << std::endl;
  }

  std::cout << "SockServer::sendToAll() exit" << std::endl;
}

std::ostream& operator<< ( std::ostream& os, const SockServer &a )
{
  for ( std::set<SockAddr>::iterator it = a.set_Addr.begin(); it != a.set_Addr.end(); ++it )
    std::cout << *it << std::endl;
}

void SockServer::disconnectFromOverdue()
{
  std::set<SockAddr> to_erase;

  for ( std::set<SockAddr>::iterator it = set_Addr.begin(); it != set_Addr.end(); ++it )
    if ( it->isOverdue() ) {
      to_erase.insert ( *it );
      std::cout << *it << " - client removed from the mailing list." << std::endl;
    }

  for ( std::set<SockAddr>::iterator it = to_erase.begin(); it != to_erase.end(); ++it ) {
    set_Addr.erase ( *it );
  }

  to_erase.clear();
}


std::string SockServer::ctime()
{
  char buf[80];
  time_t rawtime = time ( NULL );
  struct tm * timeinfo = localtime ( &rawtime );
  strftime ( buf, 80, "%F %X", timeinfo );
  return std::string ( buf );
}
