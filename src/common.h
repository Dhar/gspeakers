/*
  $Id$

  common Copyright (C) 2002 Daniel Sundberg

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

#ifndef __GFILTER_COMMON_H
#define __GFILTER_COMMON_H

#include "settings.h"

#include <glibmm/ustring.h>

#include <gdkmm/color.h>
#include <gtkmm/stock.h>
#include <gtkmm/tooltip.h>
#include <gtkmm/widget.h>

#include <libintl.h>
#include <sigc++/sigc++.h>

#include <string>
#include <utility>
#include <vector>

#define _(string) gettext(string)
#define gettext_noop(string) string
#define N_(string) gettext_noop(string)

namespace GSpeakers {
class Point;
Glib::ustring double_to_ustring(double d);
Glib::ustring double_to_ustring(double d, int format_len, int format_dec);
Glib::ustring int_to_ustring(int d);

Gtk::Widget& image_widget(const std::string& filename);

Glib::ustring short_filename(const Glib::ustring& filename, unsigned length = 30);

Gtk::Tooltip& tooltips();

bool& driverlist_modified();
bool& enclosurelist_modified();
bool& crossoverlist_modified();
bool& meassurementlist_modified();
} // namespace GSpeakers

class Box;
class Speaker;
class Crossover;
class Net;
class SpeakerList;

/// Define a Exception class for our program just for fun (and consistency)
class GSpeakersException {
  std::string _what;

public:
  GSpeakersException(std::string what_arg) : _what(std::move(what_arg)) {}

  virtual const char* what() const { return _what.c_str(); }
};

extern Settings g_settings;

/*
 * signal_crossover_selected
 *
 * Emit this signal when you want to change current crossover.
 *
 * SigC::Object is the new crossover
 */
// extern sigc::signal1<void, SigC::Object *> signal_crossover_selected;
extern sigc::signal1<void, Crossover*> signal_crossover_selected;

/*
 * signal_speakerlist_loaded
 *
 * Emit this signal when you want to change current speakerlist.
 *
 * SpeakerList arg is the new SpeakerList
 */
// extern sigc::signal1<void,std::string> signal_speakerlist_loaded;
extern sigc::signal1<void, SpeakerList*> signal_speakerlist_loaded;

/*
 * signal_box_selected
 *
 * Emit this signal when you want to change the current box
 *
 * Box * is a ptr to the new box
 */
extern sigc::signal1<void, Box*> signal_box_selected;
extern sigc::signal1<void, Box*> signal_box_modified;
extern sigc::signal1<void, Box*> signal_add_to_boxlist;
extern sigc::signal3<void, Box*, Speaker*, Gdk::Color&> signal_add_plot;
extern sigc::signal2<int, std::vector<GSpeakers::Point>&, Gdk::Color&> signal_add_box_plot;
extern sigc::signal1<void, int> signal_remove_box_plot;
extern sigc::signal1<void, int> signal_hide_box_plot;
extern sigc::signal1<void, int> signal_select_plot;
/* Define two signals for crossover parts updates */
extern sigc::signal0<void> signal_net_modified_by_wizard; // listen to this in crossover treeview
extern sigc::signal1<void, Net*> signal_net_modified_by_user; // listan to this in filter wizard
extern sigc::signal1<void, int> signal_new_crossover;
extern sigc::signal0<void> signal_plot_crossover;
extern sigc::signal4<int, std::vector<GSpeakers::Point>&, Gdk::Color&, int*, Net*>
    signal_add_crossover_plot;
extern sigc::signal0<void> signal_save_open_files;

#endif //__GFILTER_COMMON_H
