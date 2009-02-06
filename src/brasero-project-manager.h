/***************************************************************************
 *            brasero-project-manager.h
 *
 *  mer mai 24 14:22:56 2006
 *  Copyright  2006  Rouquier Philippe
 *  brasero-app@wanadoo.fr
 ***************************************************************************/

/*
 *  Brasero is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Brasero is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#ifndef BRASERO_PROJECT_MANAGER_H
#define BRASERO_PROJECT_MANAGER_H

#include <glib.h>
#include <glib-object.h>

#include <gtk/gtk.h>

#include "brasero-medium.h"
#include "brasero-project-parse.h"
#include "brasero-project-type-chooser.h"

G_BEGIN_DECLS

#define BRASERO_TYPE_PROJECT_MANAGER         (brasero_project_manager_get_type ())
#define BRASERO_PROJECT_MANAGER(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), BRASERO_TYPE_PROJECT_MANAGER, BraseroProjectManager))
#define BRASERO_PROJECT_MANAGER_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), BRASERO_TYPE_PROJECT_MANAGER, BraseroProjectManagerClass))
#define BRASERO_IS_PROJECT_MANAGER(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), BRASERO_TYPE_PROJECT_MANAGER))
#define BRASERO_IS_PROJECT_MANAGER_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), BRASERO_TYPE_PROJECT_MANAGER))
#define BRASERO_PROJECT_MANAGER_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), BRASERO_TYPE_PROJECT_MANAGER, BraseroProjectManagerClass))

typedef struct BraseroProjectManagerPrivate BraseroProjectManagerPrivate;

typedef struct {
	GtkNotebook parent;
	BraseroProjectManagerPrivate *priv;
} BraseroProjectManager;

typedef struct {
	GtkNotebookClass parent_class;	
} BraseroProjectManagerClass;

GType brasero_project_manager_get_type ();
GtkWidget *brasero_project_manager_new ();

void
brasero_project_manager_set_oneshot (BraseroProjectManager *manager,
				     gboolean oneshot);

void
brasero_project_manager_audio (BraseroProjectManager *manager,
			       GSList *uris);
void
brasero_project_manager_data (BraseroProjectManager *manager,
			      GSList *uris);
void
brasero_project_manager_video (BraseroProjectManager *manager,
			       GSList *uris);
void
brasero_project_manager_copy (BraseroProjectManager *manager,
			      const gchar *device,
			      const gchar *cover);
void
brasero_project_manager_iso (BraseroProjectManager *manager,
			     const gchar *uri);

BraseroProjectType
brasero_project_manager_open_project (BraseroProjectManager *manager,
				      BraseroDiscTrack *track,
				      const gchar *uri,
				      gboolean burn);

BraseroProjectType
brasero_project_manager_open_by_mime (BraseroProjectManager *manager,
				      const gchar *uri,
				      const gchar *mime);

BraseroProjectType
brasero_project_manager_open_uri (BraseroProjectManager *manager,
				  const gchar *uri_arg);

void
brasero_project_manager_empty (BraseroProjectManager *manager);

/**
 * returns the path of the project that was saved. NULL otherwise.
 */

gboolean
brasero_project_manager_save_session (BraseroProjectManager *manager,
				      const gchar *path,
				      gchar **saved_uri,
				      gboolean cancellable);
gboolean
brasero_project_manager_load_session (BraseroProjectManager *manager,
				      const gchar *path);

void
brasero_project_manager_register_ui (BraseroProjectManager *manager,
				     GtkUIManager *ui_manager);

G_END_DECLS

#endif /* BRASERO_PROJECT_MANAGER_H */
