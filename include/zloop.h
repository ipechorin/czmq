/*  =========================================================================
    zloop - working with 0MQ contexts

    -------------------------------------------------------------------------
    Copyright (c) 1991-2011 iMatix Corporation <www.imatix.com>
    Copyright other contributors as noted in the AUTHORS file.

    This file is part of zapi, the C binding for 0MQ: http://zapi.zeromq.org.

    This is free software; you can redistribute it and/or modify it under the
    terms of the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your option)
    any later version.

    This software is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABIL-
    ITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General
    Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.
    =========================================================================
*/

#ifndef __ZLOOP_H_INCLUDED__
#define __ZLOOP_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _zloop_t zloop_t;

//  Callback function for zhash_foreach method
typedef int (zloop_fn) (void *socket, int flags, void *argument);

#define ZEVENTS_IN      1
#define ZEVENTS_OUT     2
#define ZEVENTS_ALARM   4

zloop_t *
    zloop_new (void);
void
    zloop_destroy (zloop_t **self_p);
int
    zloop_register (zloop_t *self, void *socket, int flags, zloop_fn handler, void *argument);
int
    zloop_alarm (zloop_t *self, size_t alarm_msecs, zloop_fn handler, void *argument);
int
    zloop_clock (zloop_t *self, size_t clock_msecs, zloop_fn handler, void *argument);
int
    zloop_start (zloop_t *self);
int
    zloop_test (int verbose);

#ifdef __cplusplus
}
#endif

#endif
