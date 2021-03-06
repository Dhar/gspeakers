/*
 * Copyright (C) 2002 CodeFactory AB
 * Copyright (C) 2002 Richard Hult <rhult@codefactory.se>
 * Copyright (C) 2002 Mikael Hallendal <micke@codefactory.se>
 * Copyright (C) 2002 Jorn Baayen <jorn@nl.linux.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 * $Id$
 */

#ifndef __EGG_SIDEBAR_H
#define __EGG_SIDEBAR_H

#include <gtk/gtkframe.h>

#include "eggsidebarbutton.h"

G_BEGIN_DECLS

#define EGG_TYPE_SIDEBAR		   (egg_sidebar_get_type ())
#define EGG_SIDEBAR(obj)		   (G_TYPE_CHECK_INSTANCE_CAST ((obj), EGG_TYPE_SIDEBAR, EggSidebar))
#define EGG_SIDEBAR_CLASS(klass)	   (G_TYPE_CHECK_CLASS_CAST ((klass), EGG_TYPE_SIDEBAR, EggSidebarClass))
#define EGG_IS_SIDEBAR(obj)	   (G_TYPE_CHECK_INSTANCE_TYPE ((obj), EGG_TYPE_SIDEBAR))
#define EGG_IS_SIDEBAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((obj), EGG_TYPE_SIDEBAR))
#define EGG_SIDEBAR_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), EGG_TYPE_SIDEBAR, EggSidebarClass))

typedef struct _EggSidebar           EggSidebar;
typedef struct _EggSidebarClass      EggSidebarClass;
typedef struct _EggSidebarPriv       EggSidebarPriv;

struct _EggSidebar
{
	GtkFrame parent;

	EggSidebarPriv *priv;
};

struct _EggSidebarClass
{
	GtkFrameClass parent_class;
};

typedef enum
{
	EGG_SIDEBAR_DND_TYPE_NEW_BUTTON,
	EGG_SIDEBAR_DND_TYPE_BUTTON
} EggSidebarDNDType;

GType      egg_sidebar_get_type        (void);

GtkWidget *egg_sidebar_new             (void);

void       egg_sidebar_append          (EggSidebar *sidebar,
				       EggSidebarButton *button);

void       egg_sidebar_remove          (EggSidebar *sidebar,
				       EggSidebarButton *button);

void       egg_sidebar_save_layout     (EggSidebar *sidebar,
				       const char *filename);

void       egg_sidebar_load_layout     (EggSidebar *sidebar,
				       const char *filename);

G_END_DECLS

#endif /* __EGG_SIDEBAR_H */
