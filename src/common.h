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

#pragma once

#include "settings.h"

#include <glibmm/ustring.h>

#include <gdkmm/color.h>
#include <gtkmm/widget.h>

#include <libintl.h>
#include <sigc++/sigc++.h>

#include <string>
#include <utility>
#include <vector>

#define _(string) gettext(string)
#define gettext_noop(string) string
#define N_(string) gettext_noop(string)

namespace gspk
{
class point;
}

namespace GSpeakers
{
auto double_to_ustring(double d) -> Glib::ustring;
auto double_to_ustring(double d, int format_len, int format_dec) -> Glib::ustring;
auto int_to_ustring(int d) -> Glib::ustring;

auto image_widget(const std::string& filename) -> Gtk::Widget&;

auto short_filename(const Glib::ustring& filename, unsigned length = 30) -> Glib::ustring;

auto driverlist_modified() -> bool&;
auto enclosurelist_modified() -> bool&;
auto crossoverlist_modified() -> bool&;
auto measurementlist_modified() -> bool&;
} // namespace GSpeakers

class Box;
class Speaker;
class Crossover;
class Net;
class speaker_list;

extern Settings g_settings;

/*
 * signal_crossover_selected
 * Emit this signal when you want to change current crossover.
 * SigC::Object is the new crossover
 */
extern sigc::signal1<void, Crossover*> signal_crossover_selected;

/*
 * signal_speakerlist_loaded
 * Emit this signal when you want to change current speakerlist.
 * speaker_list arg is the new speaker_list
 */
extern sigc::signal1<void, speaker_list*> signal_speakerlist_loaded;

/*
 * signal_box_selected
 * Emit this signal when you want to change the current box
 * Box * is a ptr to the new box
 */
extern sigc::signal1<void, Box*> signal_box_selected;
extern sigc::signal1<void, Box*> signal_box_modified;
extern sigc::signal1<void, Box*> signal_add_to_boxlist;
extern sigc::signal3<void, Box*, Speaker*, Gdk::Color&> signal_add_plot;
extern sigc::signal2<int, std::vector<gspk::point>&, Gdk::Color&> signal_add_box_plot;
extern sigc::signal1<void, int> signal_remove_box_plot;
extern sigc::signal1<void, int> signal_hide_box_plot;
extern sigc::signal1<void, int> signal_select_plot;

/* Define two signals for crossover parts updates */
extern sigc::signal0<void> signal_net_modified_by_wizard; // listen to this in crossover treeview
extern sigc::signal1<void, Net*> signal_net_modified_by_user; // listan to this in filter wizard
extern sigc::signal1<void, int> signal_new_crossover;
extern sigc::signal0<void> signal_plot_crossover;
extern sigc::signal4<int, std::vector<gspk::point> const&, Gdk::Color const&, int&, Net*>
    signal_add_crossover_plot;
extern sigc::signal0<void> signal_save_open_files;
