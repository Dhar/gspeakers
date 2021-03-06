/*
  $Id$
  
  crossoverpaned Copyright (C) 2002-2004 Daniel Sundberg

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

#ifndef __CROSSOVER_PANED_H
#define __CROSSOVER_PANED_H

#include <gtkmm/notebook.h>
#include <gtkmm/menu.h>
#include "common.h"
#include "crossovertreeview.h"
#include "crossoverhistory.h"
#include "crossoverwizard.h"
#include "gspeakersfilterplot.h"
#include "totalfilterplot.h"
#include "summedfreqrespplot.h"
#include "crossoverimageview.h"

class CrossoverPaned : public Gtk::HPaned
{
public:
  CrossoverPaned();
  virtual ~CrossoverPaned();
  Gtk::Menu& get_menu();
  Gtk::Widget& get_toolbar();
  void select_first_crossover();

protected:
  void on_settings_changed(const string&);
  void on_plot_crossover();
  void on_new_crossover_menu_action(int);
  void set_save_state(bool b);
  
private:
  //  Gtk::VBox m_notebook_vbox;
  Gtk::Notebook m_crossover_notebook, m_plot_notebook;  
  CrossoverWizard crossover_wizard;
  CrossoverTreeView crossover_treeview;
  CrossoverHistory crossover_history;  
  GSpeakersFilterPlot filter_plot;
  TotalFilterPlot total_filter_plot;
  SummedFreqRespPlot summed_freq_resp_plot;
  CrossoverImageView crossover_image_view;

  //  Gtk::HPaned m_hpaned2;
  //  Gtk::VPaned m_vpaned;

  Gtk::Menu m_menu;
  Gtk::HandleBox m_toolbar;
  Gtk::Toolbar *m_tbar;
};

#endif
