/* gspeakersplot.h
 *
 * $Id$
 *
 * Copyright (C) 2001-2002 Daniel Sundberg <dss@home.se>
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

#ifndef __GSPEAKERS_PLOT_H
#define __GSPEAKERS_PLOT_H

#include <gtkmm.h>
#include <iostream>
#include <vector>
#include <string>

/* This is max and min y-axis-values */
#define MAX_NEG_VALUE -40
#define MAX_POS_VALUE 10
/* 30 is a nice little space to have between the graph and the window-border, especially if 
   you're on aa fonts */
#define BOX_FRAME_SIZE 30
/* We want vertical lines on every 5 dB */
#define N_VERTICAL_LINES ( 2 * ( -MAX_NEG_VALUE + MAX_POS_VALUE ) / 10 ) - 1
/* Upper frequency limit */
#define UPPER_LIMIT 1000

using namespace std;

/*
 * Declare my own Point class which i can use to exchange 
 * plot coordinates between classes.
 * 
 * I need a double on the y-axis since i need decimal values 
 * in the conversion to axis mappes coordinates
 */
namespace GSpeakers {
  class Point {
  public:
    Point() { };
    
    Point(int x, double y) {
      m_x = x;
      m_y = y;
    }
    
    int get_x() {
      return m_x;
    }
    
    double get_y() {
      return m_y;
    }
    
    void set_x(int x) {
      m_x = x;
    }
    
    void set_y(double y) {
      m_y = y;
    }
    
    static struct _CompareX
    {
		bool operator() (const Point & left, const Point & right)
		{
			return left.m_x <= right.m_x;
		}
		bool operator() (const Point & left, int right)
		{
			return left.m_x <= right;
		}
		bool operator() (int left, const Point & right)
		{
			return left <= right.m_x;
		}
    } _CompareX;

  private:
    int m_x;
    double m_y;
  };
}

/*
 * This is a class that can draw plots. It has add_plot, remove_plot 
 * and a few other methods you can use. It has logarithmic x-axis and 
 * a flat y-axis. The x-axis is supposed to be used for frequency and 
 * the y-axis can be used for something linear, for example dB.
 */
class GSpeakersPlot : public Gtk::DrawingArea {
  
public:
  /*
   * lower_x: x axis lower limit
   * upper_x: x axis upper limit
   * lower_y: y axis lower limit
   * upper_y: y axis upper limit
   * logx:    logarithmic x axis
   * y_zero_freq: draw a thicker horizontal line on this y-value
   */
  GSpeakersPlot(int lower_x = 20, 
                int upper_x = 1000, 
                int lower_y = -40, 
                int upper_y = 10, 
                bool logx = true, 
                int y_zero_freq = 0, 
                bool enable_sec_scale = false);
  int add_plot(vector<GSpeakers::Point> &p, Gdk::Color& ref_color);
  void remove_plot(int n);
  void hide_plot(int n);
  void remove_all_plots();
  
  void redraw();
  
  void set_font( const string& font );
  void set_line_style( Gdk::LineStyle &style );
  void set_line_size( int size );

  void select_plot(int index);

  void replace_plot(int index, vector<GSpeakers::Point> &p, Gdk::Color& ref_color);
  void set_y_label(const string& text);
  void set_y_label2(const string& text);
  
protected:
  /* This is the function that draws the graphics */
  
  bool on_expose_event(GdkEventExpose* event);
  //void on_show();
  bool on_configure_event(GdkEventConfigure* event);
  
  /* Vectors that hold the y magnitude points for the plots (dbmag) and 
     the corresponding colors (colors) */
  vector< vector<GSpeakers::Point> > m_points;
  vector<Gdk::Color> m_colors;
  vector<bool> m_visible_plots;
 private:
  Glib::ustring int_to_ustring(int d);
  Glib::ustring int_to_ustring3(int d);
  
  void draw_log_grid();
  void draw_lin_grid();
  void draw_horz_grid();
  int m_linesize;
  Gdk::LineStyle line_style;
  int m_lower_x, m_upper_x, m_lower_y, m_upper_y, m_y_zero_freq, m_enable_sec_scale;
  bool m_logx, visible;
  int m_selected_plot;
  string m_y_label1, m_y_label2;
  
  Glib::RefPtr<Gdk::Pixmap> m_refPixmap;
  Glib::RefPtr<Gdk::GC> m_refGC;
  Glib::RefPtr<Gdk::Colormap> m_refColormap;
  //Glib::RefPtr<Pango::Font> m_refFont;
  Glib::RefPtr<Pango::Layout> m_refLayout;
  Gdk::Color black, white;
};

#endif
