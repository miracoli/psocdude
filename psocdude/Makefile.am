#
# psocdude - A Downloader/Uploader for PSoC device programmers
# Copyright (C) 2015  Dirk Petrautzki <dirk@dirk-petrautzki.de>
# 
# Derived from avrdude code which is under copyright 
# of the respective programmer (see AUTHORS_AVRDUDE)
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

#
# $Id$
#

EXTRA_DIST   = \
	ChangeLog \
	ChangeLog-2001 \
	ChangeLog-2002 \
	ChangeLog-2003 \
	ChangeLog-2004-2006 \
	ChangeLog-2007 \
	ChangeLog-2008 \
	ChangeLog-2009 \
	ChangeLog-2010 \
	ChangeLog-2011 \
	ChangeLog-2012 \
	psocdude.1 \
	psocdude.spec \
	bootstrap

CLEANFILES = \
	config_gram.c \
	config_gram.h \
	lexer.c

BUILT_SOURCES = $(CLEANFILES)

#SUBDIRS      = doc @WINDOWS_DIRS@
#DIST_SUBDIRS = doc windows

# . lets build this directory before the following in SUBDIRS
SUBDIRS = .
# doc comes here, and we want to use the built psocdude to generate the parts list
SUBDIRS += @SUBDIRS_AC@
SUBDIRS += @WINDOWS_DIRS@
DIST_SUBDIRS = @DIST_SUBDIRS_AC@

AM_YFLAGS    = -d

psocdude_CPPFLAGS = -DCONFIG_DIR=\"$(sysconfdir)\"

libpsocdude_a_CPPFLAGS = -DCONFIG_DIR=\"$(sysconfdir)\"

psocdude_CFLAGS   = @ENABLE_WARNINGS@

libpsocdude_a_CFLAGS   = @ENABLE_WARNINGS@

psocdude_LDADD  = $(top_builddir)/$(noinst_LIBRARIES) @LIBUSB_1_0@ @LIBUSB@ @LIBFTDI1@ @LIBFTDI@ @LIBHID@ @LIBELF@ @LIBPTHREAD@ -lm

bin_PROGRAMS = psocdude

noinst_LIBRARIES = libpsocdude.a

# automake thinks these generated files should be in the distribution,
# but this might cause trouble for some users, so we rather don't want
# to have them there.
#
# See
#
# https://savannah.nongnu.org/bugs/index.php?func=detailitem&item_id=15536
#
# for why we don't want to have them.
dist-hook:
	rm -f \
	$(distdir)/lexer.c \
	$(distdir)/config_gram.c \
	$(distdir)/config_gram.h

libpsocdude_a_SOURCES = \
	config_gram.y \
	lexer.l \
	arduino.h \
	arduino.c \
	avr.c \
	avr.h \
	psocdude.h \
	avrpart.c \
	avrpart.h \
	config.c \
	config.h \
	confwin.c \
	confwin.h \
	fileio.c \
	fileio.h \
	lists.c \
	lists.h \
	pgm.c \
	pgm.h \
	pgm_type.c \
	pgm_type.h \
	pindefs.c \
	pindefs.h \
	safemode.c \
	safemode.h \
	serial.h \
	ser_posix.c \
	ser_win32.c \
	solaris_ecpp.h \
	stk500.c \
	stk500.h \
	stk500_private.h \
	tpi.h \
	usbdevs.h \
	update.h \
	update.c 

psocdude_SOURCES = \
	main.c 

#man_MANS = psocdude.1

sysconf_DATA = psocdude.conf

install-exec-local: backup-psocdude-conf

distclean-local:
	rm -f psocdude.conf

# This will get run before the config file is installed.
backup-psocdude-conf:
	@echo "Backing up psocdude.conf in ${DESTDIR}${sysconfdir}"
	@if test -e ${DESTDIR}${sysconfdir}/psocdude.conf; then \
		cp -pR ${DESTDIR}${sysconfdir}/psocdude.conf \
			${DESTDIR}${sysconfdir}/psocdude.conf.bak; \
	fi
