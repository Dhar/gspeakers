/*
  gtkmm_hello Copyright (C) 2001 Murray Cumming

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

#ifndef GFILTER_H
#define GFILTER_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <libintl.h>

class GFilter : public Gtk::Window
{
public:
  GFilter();
  virtual ~GFilter();

  //Signal handlers:
  virtual void on_button_clicked();

protected:
  //Member widgets:
  Gtk::Button m_Button1;
  Gtk::Button m_Button2;
};

#endif //GFILTER_H
