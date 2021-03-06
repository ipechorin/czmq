/*  =========================================================================
    zstr - sending and receiving strings

    -------------------------------------------------------------------------
    Copyright (c) 1991-2014 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of CZMQ, the high-level C binding for 0MQ:
    http://czmq.zeromq.org.

    This is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the 
    Free Software Foundation; either version 3 of the License, or (at your 
    option) any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABIL-
    ITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General 
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License 
    along with this program. If not, see <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __ZSTR_H_INCLUDED__
#define __ZSTR_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Receive C string from socket. Caller must free returned string using
//  zstr_free(). Returns NULL if the context is being terminated or the
//  process was interrupted.
CZMQ_EXPORT char *
    zstr_recv (void *socket);

//  Receive C string from socket, if socket had input ready. Caller must
//  free returned string using zstr_free. Returns NULL if there was no input
//  waiting, or if the context was terminated. Use zctx_interrupted to exit
//  any loop that relies on this method.
CZMQ_EXPORT char *
    zstr_recv_nowait (void *socket);

//  Send a C string to a socket, as a frame. The string is sent without
//  trailing null byte; to read this you can use zstr_recv, or a similar
//  method that adds a null terminator on the received string.
CZMQ_EXPORT int
    zstr_send (void *socket, const char *string);

//  Send a C string to a socket, as zstr_send(), with a MORE flag, so that
//  you can send further strings in the same multi-part message.
CZMQ_EXPORT int
    zstr_sendm (void *socket, const char *string);

//  Send a formatted string to a socket. Note that you should NOT use
//  user-supplied strings in the format (they may contain '%' which
//  will create security holes).
CZMQ_EXPORT int
    zstr_sendf (void *socket, const char *format, ...);

//  Send a formatted string to a socket, as for zstr_sendf(), with a
//  MORE flag, so that you can send further strings in the same multi-part
//  message.
CZMQ_EXPORT int
    zstr_sendfm (void *socket, const char *format, ...);

//  Send a series of strings (until NULL) as multipart data
//  Returns 0 if the strings could be sent OK, or -1 on error.
CZMQ_EXPORT int
    zstr_sendx (void *socket, const char *string, ...);

//  Receive a series of strings (until NULL) from multipart data.
//  Each string is allocated and filled with string data; if there
//  are not enough frames, unallocated strings are set to NULL.
//  Returns -1 if the message could not be read, else returns the
//  number of strings filled, zero or more. Free each returned string
//  using zstr_free().
CZMQ_EXPORT int
    zstr_recvx (void *socket, char **string_p, ...);

//  Free a provided string, and nullify the parent pointer. Safe to call on
//  a null pointer.
CZMQ_EXPORT void
    zstr_free (char **string_p);

//  Self test of this class
CZMQ_EXPORT int
    zstr_test (bool verbose);
//  @end

//  Compiler hints
CZMQ_EXPORT int zstr_sendf (void *socket, const char *format, ...) CHECK_PRINTF (2);

#ifdef __cplusplus
}
#endif

#endif
