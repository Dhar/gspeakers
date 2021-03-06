/*
  $Id$
  
  freqrespeditor Copyright (C) 2002 Daniel Sundberg

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef __FREQ_RESPONSE_EDITOR_H
#define __FREQ_RESPONSE_EDITOR_H

#include "common.h"
#include <gtkmm/table.h>
#include <gtkmm/dialog.h>
#include <gtkmm/entry.h>

using namespace std;
using namespace sigc;

class FreqRespEditor : public Gtk::Dialog
{
public:
  FreqRespEditor(string filename = "");
  ~FreqRespEditor();
  string get_filename() { return m_filename; }
private:
  Gtk::Table m_table;
  vector<Gtk::Entry*> dbmag_entries;
  Gtk::Button m_save_button, m_saveas_button, m_close_button;
  
  string m_filename;
  
  /* callbacks */
  void on_save();
  void on_save_as();
  void on_close();
  vector<double> get_x_vector();
};

#endif
