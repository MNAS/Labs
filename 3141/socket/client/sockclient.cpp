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

#include "sockclient.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
#include <fcntl.h>

#define BUF_SIZE 500

SockClient::SockClient()
{
}

SockClient::~SockClient()
{
}

bool SockClient::connect ( char * host, char * port )
{
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int s, j;

  memset ( &hints, 0, sizeof ( struct addrinfo ) );
  hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
  hints.ai_flags = 0;
  hints.ai_protocol = 0;          /* Any protocol */

  s = getaddrinfo ( host, port, &hints, &result );

  if ( s != 0 ) {
    fprintf ( stderr, "getaddrinfo: %s\n", gai_strerror ( s ) );
    exit ( EXIT_FAILURE );
  }

//      getaddrinfo() returns a list of address structures.
//        try each address until we successfully connect(2).
//        if socket(2) (or connect(2)) fails, we (close the socket
//        and) try the next address.

  for ( rp = result; rp != NULL; rp = rp->ai_next ) {
    sfd = socket ( rp->ai_family, rp->ai_socktype, rp->ai_protocol );

    if ( sfd == -1 )
      continue;

    if ( ::connect ( sfd, rp->ai_addr, rp->ai_addrlen ) != -1 )
      break;                   //Success

    close ( sfd );
  }

  fcntl ( sfd, F_SETFL, O_NONBLOCK );

  if ( rp == NULL ) {              //No address succeeded
    fprintf ( stderr, "Could not connect\n" );
    exit ( EXIT_FAILURE );
  }

  freeaddrinfo ( result );         //No longer needed
  return true;

}

void SockClient::exec()
{
  int s, j;

  for ( ;; ) {
    std::string a_strl;
    std::cout << "Enter message:";
    std::cout.flush();
    std::getline ( std::cin, a_strl );
    std::cout << a_strl << "\n";
    std::cout.flush();

    if ( a_strl == std::string ( "exit" ) )
      exit ( EXIT_SUCCESS );

    else
      if ( a_strl == std::string ( "" ) )
        receive();

      else {
        send ( a_strl );
        receive();
      }
  }

  exit ( EXIT_SUCCESS );
}

void SockClient::receive()
{
  bool do_while = true;

  do {
    ssize_t nread = read ( sfd, buf, BUF_SIZE );

    if ( nread == -1 )
      do_while = false;

    else
      std::cout << buf << std::endl;
  } while ( do_while );
}

void SockClient::send ( const std::string & msg )
{
  strcpy ( buf, msg.c_str() );
  size_t len =  strlen ( buf ) + 1;

  if ( write ( sfd, buf, len ) != len ) {
    std::cerr<< "partial/failed write" <<std::endl;
    exit ( EXIT_FAILURE );
  }
}


//     for (j = 3; j < argc; j++) {
//         len = strlen(argv[j]) + 1;   // +1 for terminating null byte
//
//         if (len + 1 > BUF_SIZE) {
//             fprintf(stderr,
//                     "Ignoring long message in argument %d\n", j);
//             continue;
//         }
//
//         if (write(sfd, argv[j], len) != len) {
//             fprintf(stderr, "partial/failed write\n");
//             exit(EXIT_FAILURE);
//         }
//
//         nread = read(sfd, buf, BUF_SIZE);
//         if (nread == -1) {
//             perror("read");
//             exit(EXIT_FAILURE);
//         }
//
//         printf("Received %zd bytes: %s\n", nread, buf);
//     }
