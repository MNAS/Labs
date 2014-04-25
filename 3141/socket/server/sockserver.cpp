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

SockServer::SockServer()
{
  sfd=-1;
  port=0;
  connected = false;
}

bool SockServer::connect(const char * Port)
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
        nread = recvfrom ( sfd, buf, BUF_SIZE, 0, ( sockaddr * ) &peer_addr, &peer_addr_len );
	set_sockaddr_storage.insert(peer_addr);
        if ( nread == -1 )
            continue;               /* Ignore failed request */
        char host[NI_MAXHOST], service[NI_MAXSERV];
        s = getnameinfo ( ( sockaddr * ) &peer_addr, peer_addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICSERV );
        if ( s == 0 )
            printf ( "Received %zd bytes from %s:%s\n", nread, host, service );
        else
            fprintf ( stderr, "getnameinfo: %s\n", gai_strerror ( s ) );


        if ( sendto ( sfd, buf, nread, 0, ( sockaddr * ) &peer_addr, peer_addr_len ) != nread )
            fprintf ( stderr, "Error sending response\n" );

    }
}

SockServer::~SockServer()
{

}
