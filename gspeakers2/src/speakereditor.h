/*
  speakereditor Copyright (C) 2002 Daniel Sundberg

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

#ifndef __GSPEAKERS_SPEAKEREDITOR
#define __GSPEAKERS_SPEAKEREDITOR

#include <gtkmm.h>
#include "speaker.h"
#include "speakerlist.h"

using namespace SigC;
using namespace std;

/* Prepare for future features */
#define ENABLE_BROWSE_FILES 1

class Speaker_ListStore : public Gtk::Window
{
public:
  Speaker_ListStore(SpeakerList *speaker_list, const string &filename);
  virtual ~Speaker_ListStore();

protected:
  /* callbacks */
  void on_cell_fixed_toggled(const Glib::ustring& path_string);
  void on_open_xml();
  void on_append_xml();
  void on_open_ok(Gtk::FileSelection *f);
  void on_append_ok(Gtk::FileSelection *f);
  void on_clear();
  void on_selection_changed();
  void on_new();
  void on_new_xml();
  void on_entry_changed(int i);
  void on_save();
  void on_save_as();
  void on_save_as_ok(Gtk::FileSelection *f);
  void on_remove();
  void on_close();

  /* Helper funtions */
  virtual void create_model();
  virtual void add_columns();
  virtual void add_items(SpeakerList slist);
  virtual void liststore_add_item(Speaker foo);

  //Member widgets:
  Gtk::VBox m_VBox;
  Gtk::HBox m_HBox;
  Gtk::Table m_Table;
  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::Label m_Label;
  Gtk::TreeView m_TreeView;
  Glib::RefPtr<Gtk::ListStore> m_refListStore;
  Gtk::Button m_NewButton, m_NewXmlButton, m_AppendXmlButton, m_OpenXmlButton, m_CloseButton;
  Gtk::Button m_BrowseFreqRespButton, m_BrowseImpRespButton, m_SaveButton, m_SaveAsButton, m_RemoveButton;
  Gtk::Entry m_IdStringEntry, m_QtsEntry, m_FsEntry, m_VasEntry, m_RdcEntry, m_LvcEntry, m_QmsEntry, m_QesEntry;
  Gtk::Entry m_ImpEntry, m_SensEntry, m_FreqRespFileEntry, m_ImpRespFileEntry;
  Gtk::CheckButton m_BassCheckButton, m_MidrangeCheckButton, m_TweeterCheckButton;
  
  Gtk::FileSelection *f_open, *f_save_as, *f_append;
  
  /* Data container */
  SpeakerList *m_speaker_list;

  struct ModelColumns : public Gtk::TreeModelColumnRecord
  {
    Gtk::TreeModelColumn<int>           id;
    Gtk::TreeModelColumn<int>           type;
    Gtk::TreeModelColumn<Glib::ustring> id_string;
    Gtk::TreeModelColumn<double>        qts;
    Gtk::TreeModelColumn<double>        fs;
    Gtk::TreeModelColumn<double>        vas;
    Gtk::TreeModelColumn<double>        rdc;
    Gtk::TreeModelColumn<double>        lvc;
    Gtk::TreeModelColumn<double>        qms;
    Gtk::TreeModelColumn<double>        qes;
    Gtk::TreeModelColumn<double>        imp;
    Gtk::TreeModelColumn<double>        sens;

    ModelColumns() { add(id); add(type); add(id_string); add(qts); add(fs); add(vas); 
                     add(rdc); add(lvc); add(qms); add(qes); add(imp); add(sens); }
  };
  
  /* vaious helper varaibles */
  bool changed, new_xml_pressed;
  int index;
  ModelColumns m_columns;
  //Glib::RefPtr<Gtk::TreeSelection> old_refSelection;
  void set_entries_sensitive(bool value);
  string m_filename;
};

#endif