/* 
 * gspeakerscfg.cc
 *
 * Copyright (C) 2001 Daniel Sundberg <dss@home.se>
 *
 * http://sumpan.campus.luth.se/software/gspeakers
 *
 * This program is free software; you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 * USA
 */

#include <string>
#include "gspeakerscfg.h"

string cfg_file = string( getenv("HOME") ) + string("/.gspeakers/gspeakers.conf");

GSpeakersCFG::GSpeakersCFG() : CConfig( (char *)cfg_file.c_str() ) {

};

string GSpeakersCFG::get_font() {
  string s = string( getConfigKey( "plotfont" ) );
  if ( s.size() > 0 ) {
    return s;
  } else {
    /* Default font */
    return "-adobe-helvetica-medium-o-normal-*-*-*-*-*-*-*-*-*";
  }
}

int GSpeakersCFG::get_line_style() {
  return 0;
}

int GSpeakersCFG::get_line_size() {
  return 0;
}

void GSpeakersCFG::set_font( string newfont ) {
  writeConfigKey( (char *)("plotfont"), (char *)(newfont.c_str()) );
}
