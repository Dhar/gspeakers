/*
  crossoverlist Copyright (C) 2002 Daniel Sundberg

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

#ifndef __GFILTER_CROSSOVERLIST_H
#define __GFILTER_CROSSOVERLIST_H

#include <iostream>
#include <vector>
#include <string>
#include <libxml/tree.h>
#include <libxml/parser.h>
#include "crossover.h"
#include "common.h"

using namespace std;

/*
 * This is a class that pretty much just contains a list of crossovers.
 *
 * All operations on the list will be made on the list, maybe this class 
 * will provide some conveniance methods...
 *
 * The class also contains some xml-writing functions
 */
class CrossoverList
{
public:
  CrossoverList();

  /* Construct a part from an xml node */
  CrossoverList(string filename);
  
  /* Convert data for a part to an xml node, throws GSpeakersException on failure */
  void to_xml(string filename);   // Maybe this one should throw an exception

  /* Print part data to stdout */
  friend ostream& operator<< (ostream& o, const CrossoverList& crossover_list);

  /* return a pointer to the crossover list */
  vector<Crossover> *crossover_list();

  /* Remove all items from the corssover list */
  void clear();

protected:
  /* Member variables */
  vector<Crossover> m_crossover_list;
};

#endif
