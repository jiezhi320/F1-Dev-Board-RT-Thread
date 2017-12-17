# Makefile for NETIO
#
# Author:  Kai Uwe Rommel <rommel@ars.de>
# Created: Wed Sep 25 1996
#
# $Id: Makefile,v 1.10 2010/10/14 13:03:35 Rommel Exp Rommel $
# $Revision: 1.10 $
#
# $Log: Makefile,v $
# Revision 1.10  2010/10/14 13:03:35  Rommel
# removed NetBIOS code
#
# Revision 1.9  2005/08/30 14:45:58  Rommel
# targets updated
#
# Revision 1.8  2003/08/17 16:59:22  Rommel
# separated Unix and Linux targets
#
# Revision 1.7  2003/07/12 17:28:31  Rommel
# switched to gcc for Win32
#
# Revision 1.6  2001/04/19 12:21:14  Rommel
# added fixes for Unix systems
#
# Revision 1.5  1999/10/24 19:08:49  rommel
# imported DOS support from G. Vanem <giva@bgnett.no>
#
# Revision: 1.5  1999/10/12 11:02:00 giva
# added Watt-32 + djgpp support
#
# $Log: Makefile,v $
# Revision 1.10  2010/10/14 13:03:35  Rommel
# removed NetBIOS code
#
# Revision 1.9  2005/08/30 14:45:58  Rommel
# targets updated
#
# Revision 1.8  2003/08/17 16:59:22  Rommel
# separated Unix and Linux targets
#
# Revision 1.1  2003/08/17 16:58:28  Rommel
# Initial revision
#
# Revision 1.7  2003/07/12 17:28:31  Rommel
# switched to gcc for Win32
#
# Revision 1.6  2001/04/19 12:21:14  Rommel
# added fixes for Unix systems
#
# Revision 1.5  1999/10/24 19:08:49  rommel
# imported DOS support from G. Vanem <giva@bgnett.no>
#
# Revision 1.4  1999/06/13 18:53:42  rommel
# added Linux port
#
# Revision 1.3  1998/10/12 11:14:58  rommel
# change to malloc'ed (and tiled) memory for transfer buffers
# (hint from Guenter Kukkukk <kukuk@berlin.snafu.de>)
# for increased performance
#
# Revision 1.2  1998/07/31 14:16:06  rommel
# *** empty log message ***
#
# Revision 1.1  1998/01/03 17:30:01  rommel
# Initial revision
#

win32:
	$(MAKE) all CC="gcc -O -s" O=.o X=.exe \
        CFLAGS="-DWIN32" LFLAGS="" \
	LIBS="-lwsock32 -lnetapi32" OUT=-o
win32-debug:
	$(MAKE) all CC="gcc -g" O=.o X=.exe \
        CFLAGS="-DWIN32" LFLAGS="" \
	LIBS="-lwsock32 -lnetapi32" OUT=-o
os2:
	$(MAKE) all CC="icc -q -Gm -Gt -O" O=.obj X=.exe \
        CFLAGS="-DOS2 -Ic:/os2tk45/h/stack16" \
        LFLAGS="/B/ST:0x100000" LIBS="tcp32dll.lib so32dll.lib" OUT=-Fe
unix:
	$(MAKE) all CC="gcc -O -s" O=.o X= \
	CFLAGS="-DUNIX" LFLAGS="" LIBS="-lsocket -lpthread" OUT=-o
solaris:
	$(MAKE) all CC="gcc -O -s" O=.o X= \
	CFLAGS="-DUNIX" LFLAGS="" LIBS="-lsocket -lpthread -lnsl" OUT=-o
linux:
	$(MAKE) all CC="gcc -O -s" O=.o X= \
	CFLAGS="-DUNIX" LFLAGS="" LIBS="-lpthread" OUT=-o
macosx:
	$(MAKE) all CC="gcc -O" O=.o X= \
	CFLAGS="-DUNIX -DSOCKLEN_T" LFLAGS="" LIBS="-lpthread" OUT=-o
freebsd:
	$(MAKE) all CC="gcc -O -s" O=.o X= \
	CFLAGS="-DUNIX" LFLAGS="-L/usr/local/lib" LIBS="-lpthread" OUT=-o

INC = -I.

all: netio$X

netio$X: netio$O getopt$O
	$(CC) $(OUT) $@ netio$O getopt$O $(LFLAGS) $(LIBS)

.SUFFIXES: .c $O
.c$O:
	$(CC) $(CFLAGS) $(INC) -c $*.c

netio$O: netio.c getopt.h
getopt$O: getopt.c getopt.h
