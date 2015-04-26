/*
 * avrdude - A Downloader/Uploader for AVR device programmers
 * Copyright (C) 2002-2004  Brian S. Dean <bsd@bsdhome.com>
 * Copyright 2007 Joerg Wunsch <j@uriah.heep.sax.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* $Id: pgm.c 976 2011-08-23 21:03:36Z joerg_wunsch $ */

#include "ac_cfg.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avrdude.h"
#include "pgm_type.h"

#include "arduino.h"
#include "avr.h"

const PROGRAMMER_TYPE const programmers_types[] = {
  {"arduino", arduino_initpgm, arduino_desc},
};

const PROGRAMMER_TYPE * locate_programmer_type(const char * id)
{
  const PROGRAMMER_TYPE * p = NULL;
  int i;
  int found;

  found = 0;

  for (i = 0; i < sizeof(programmers_types)/sizeof(programmers_types[0]) && !found; i++) {
    p = &(programmers_types[i]);
    if (strcasecmp(id, p->id) == 0)
        found = 1;
  }

  if (found)
    return p;

  return NULL;
}

/*
 * Iterate over the list of programmers given as "programmers", and
 * call the callback function cb for each entry found.  cb is being
 * passed the following arguments:
 * . the name of the programmer (for -c)
 * . the descriptive text given in the config file
 * . the name of the config file this programmer has been defined in
 * . the line number of the config file this programmer has been defined at
 * . the "cookie" passed into walk_programmers() (opaque client data)
 */
 /*
void walk_programmer_types(LISTID programmer_types, walk_programmer_types_cb cb, void *cookie)
{
  LNODEID ln1;
  PROGRAMMER * p;

  for (ln1 = lfirst(programmers); ln1; ln1 = lnext(ln1)) {
    p = ldata(ln1);
      cb(p->id, p->desc, cookie);
    }
  }
}*/

void walk_programmer_types(walk_programmer_types_cb cb, void *cookie)
{
  const PROGRAMMER_TYPE * p;
  int i;

  for (i = 0; i < sizeof(programmers_types)/sizeof(programmers_types[0]); i++) {
    p = &(programmers_types[i]);
    cb(p->id, p->desc, cookie);
  }
}


