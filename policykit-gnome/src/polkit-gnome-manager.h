/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2007 David Zeuthen <david@fubar.dk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef POLKIT_GNOME_MANAGER_H
#define POLKIT_GNOME_MANAGER_H

#include <glib-object.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#define POLKIT_GNOME_TYPE_MANAGER         (polkit_gnome_manager_get_type ())
#define POLKIT_GNOME_MANAGER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), POLKIT_GNOME_TYPE_MANAGER, PolKitGnomeManager))
#define POLKIT_GNOME_MANAGER_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), POLKIT_GNOME_TYPE_MANAGER, PolKitGnomeManagerClass))
#define POLKIT_GNOME_IS_MANAGER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), POLKIT_GNOME_TYPE_MANAGER))
#define POLKIT_GNOME_IS_MANAGER_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), POLKIT_GNOME_TYPE_MANAGER))
#define POLKIT_GNOME_MANAGER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), POLKIT_GNOME_TYPE_MANAGER, PolKitGnomeManagerClass))

typedef struct PolKitGnomeManagerPrivate PolKitGnomeManagerPrivate;

typedef struct
{
        GObject        parent;
        PolKitGnomeManagerPrivate *priv;
} PolKitGnomeManager;

typedef struct
{
        GObjectClass   parent_class;
} PolKitGnomeManagerClass;

typedef enum
{
        POLKIT_GNOME_MANAGER_ERROR_GENERAL,
        POLKIT_GNOME_MANAGER_ERROR_AUTH_IN_PROGRESS
} PolKitGnomeManagerError;

#define POLKIT_GNOME_MANAGER_ERROR polkit_gnome_manager_error_quark ()

GQuark              polkit_gnome_manager_error_quark         (void);
GType               polkit_gnome_manager_get_type            (void);
PolKitGnomeManager *polkit_gnome_manager_new                 (gboolean no_exit);

/* exported methods */
gboolean            polkit_gnome_manager_show_dialog (PolKitGnomeManager    *manager,
                                                      const char            *action_id,
                                                      guint32                xid,
                                                      DBusGMethodInvocation *context);

gboolean            polkit_gnome_manager_obtain_authorization (PolKitGnomeManager    *manager,
                                                               const char            *action_id,
                                                               guint32                xid,
                                                               guint32                pid,
                                                               DBusGMethodInvocation *context);

G_END_DECLS

#endif /* POLKIT_GNOME_MANAGER_H */
