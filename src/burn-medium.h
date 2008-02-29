/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
/*
 * brasero
 * Copyright (C) Philippe Rouquier 2007 <bonfire-app@wanadoo.fr>
 * 
 * brasero is free software.
 * 
 * You may redistribute it and/or modify it under the terms of the
 * GNU General Public License, as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * brasero is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with brasero.  If not, write to:
 * 	The Free Software Foundation, Inc.,
 * 	51 Franklin Street, Fifth Floor
 * 	Boston, MA  02110-1301, USA.
 */

#include <glib-object.h>

#ifndef _BURN_MEDIUM_H_
#define _BURN_MEDIUM_H_

G_BEGIN_DECLS

/* rates are in Kio/sec */
#define CD_RATE 153600
#define DVD_RATE 1385000

typedef struct _BraseroDrive BraseroDrive;

#define BRASERO_SPEED_TO_RATE_CD(speed)		(guint) ((speed) * CD_RATE)
#define BRASERO_SPEED_TO_RATE_DVD(speed)	(guint) ((speed) * DVD_RATE)
#define BRASERO_RATE_TO_SPEED_CD(rate)		(guint) ((rate) / CD_RATE)
#define BRASERO_RATE_TO_SPEED_DVD(rate)		(guint) ((rate) / DVD_RATE)

#define BRASERO_TYPE_MEDIUM             (brasero_medium_get_type ())
#define BRASERO_MEDIUM(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), BRASERO_TYPE_MEDIUM, BraseroMedium))
#define BRASERO_MEDIUM_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), BRASERO_TYPE_MEDIUM, BraseroMediumClass))
#define BRASERO_IS_MEDIUM(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), BRASERO_TYPE_MEDIUM))
#define BRASERO_IS_MEDIUM_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), BRASERO_TYPE_MEDIUM))
#define BRASERO_MEDIUM_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), BRASERO_TYPE_MEDIUM, BraseroMediumClass))

typedef struct _BraseroMediumClass BraseroMediumClass;
typedef struct _BraseroMedium BraseroMedium;

struct _BraseroMediumClass
{
	GObjectClass parent_class;
};

struct _BraseroMedium
{
	GObject parent_instance;
};

GType brasero_medium_get_type (void) G_GNUC_CONST;

BraseroMedium *
brasero_medium_new (BraseroDrive *drive);

typedef enum {
	BRASERO_MEDIUM_UNSUPPORTED		= -2,
	BRASERO_MEDIUM_BUSY			= -1,
	BRASERO_MEDIUM_NONE			= 0,

	/* types */
	BRASERO_MEDIUM_FILE			= 1,

	BRASERO_MEDIUM_CD			= 1 << 1,

	BRASERO_MEDIUM_DVD			= 1 << 2,

	BRASERO_MEDIUM_RAM			= 1 << 3,

	BRASERO_MEDIUM_BD			= 1 << 4,

	/* DVD subtypes */
	BRASERO_MEDIUM_PLUS			= 1 << 5,
	BRASERO_MEDIUM_SEQUENTIAL		= 1 << 6,
	BRASERO_MEDIUM_RESTRICTED		= 1 << 7,

	BRASERO_MEDIUM_DL			= 1 << 8,

	/* BD subtypes */
	BRASERO_MEDIUM_JUMP			= 1 << 9,
	BRASERO_MEDIUM_RANDOM			= 1 << 10,

	/* discs attributes */
	BRASERO_MEDIUM_REWRITABLE		= 1 << 14,
	BRASERO_MEDIUM_WRITABLE			= 1 << 15,
	BRASERO_MEDIUM_ROM			= 1 << 16,

	/* status of the disc */
	BRASERO_MEDIUM_BLANK			= 1 << 17,
	BRASERO_MEDIUM_CLOSED			= 1 << 18,
	BRASERO_MEDIUM_APPENDABLE		= 1 << 19,

	BRASERO_MEDIUM_PROTECTED		= 1 << 20,
	BRASERO_MEDIUM_HAS_DATA			= 1 << 21,
	BRASERO_MEDIUM_HAS_AUDIO		= 1 << 22,
} BraseroMedia;

#define BRASERO_MEDIUM_ALL_TYPE		(BRASERO_MEDIUM_CD|		\
					 BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_DL|		\
					 BRASERO_MEDIUM_PLUS|		\
					 BRASERO_MEDIUM_RESTRICTED|	\
					 BRASERO_MEDIUM_SEQUENTIAL|	\
					 BRASERO_MEDIUM_ROM|	\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_REWRITABLE)
#define BRASERO_MEDIUM_CDROM		(BRASERO_MEDIUM_CD|		\
					 BRASERO_MEDIUM_ROM)
#define BRASERO_MEDIUM_CDR		(BRASERO_MEDIUM_CD|		\
					 BRASERO_MEDIUM_WRITABLE)
#define BRASERO_MEDIUM_CDRW		(BRASERO_MEDIUM_CD|		\
					 BRASERO_MEDIUM_REWRITABLE)
#define BRASERO_MEDIUM_DVD_RAM		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_RAM)
#define BRASERO_MEDIUM_DVD_ROM		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_ROM)
#define BRASERO_MEDIUM_DVDR		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_SEQUENTIAL|	\
					 BRASERO_MEDIUM_WRITABLE)
#define BRASERO_MEDIUM_DVDRW		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_SEQUENTIAL|	\
					 BRASERO_MEDIUM_REWRITABLE)
#define BRASERO_MEDIUM_DVDRW_RESTRICTED	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_REWRITABLE|	\
					 BRASERO_MEDIUM_RESTRICTED)
#define BRASERO_MEDIUM_DVDR_DL		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_SEQUENTIAL|	\
					 BRASERO_MEDIUM_DL)
#define BRASERO_MEDIUM_DVDR_JUMP_DL	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_JUMP|		\
					 BRASERO_MEDIUM_DL)
#define BRASERO_MEDIUM_DVDR_PLUS	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_PLUS)
#define BRASERO_MEDIUM_DVDRW_PLUS	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_REWRITABLE|	\
					 BRASERO_MEDIUM_PLUS)
#define BRASERO_MEDIUM_DVDR_PLUS_DL	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_PLUS|		\
					 BRASERO_MEDIUM_DL)
#define BRASERO_MEDIUM_DVDRW_PLUS_DL	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_REWRITABLE|	\
					 BRASERO_MEDIUM_PLUS|		\
					 BRASERO_MEDIUM_DL)
#define BRASERO_MEDIUM_BD_ROM		(BRASERO_MEDIUM_BD|		\
					 BRASERO_MEDIUM_ROM)
#define BRASERO_MEDIUM_BDR		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_BD)
#define BRASERO_MEDIUM_BDR_RANDOM	(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_WRITABLE|	\
					 BRASERO_MEDIUM_RANDOM|		\
					 BRASERO_MEDIUM_BD)
#define BRASERO_MEDIUM_BDRW		(BRASERO_MEDIUM_DVD|		\
					 BRASERO_MEDIUM_REWRITABLE|	\
					 BRASERO_MEDIUM_PLUS|		\
					 BRASERO_MEDIUM_BD)

#define BRASERO_MEDIUM_VALID(media)	((media) != BRASERO_MEDIUM_NONE		\
					&& (media) != BRASERO_MEDIUM_BUSY	\
					&& (media) != BRASERO_MEDIUM_UNSUPPORTED)


#define BRASERO_MEDIUM_TYPE(media)	((media) & 0x001F)
#define BRASERO_MEDIUM_ATTR(media)	((media) & 0x1C000)
#define BRASERO_MEDIUM_STATUS(media)	((media) & 0xE0000)
#define BRASERO_MEDIUM_SUBTYPE(media)	((media) & 0x07E0)
#define BRASERO_MEDIUM_INFO(media)	((media) & 0x700000)

#define BRASERO_MEDIUM_IS(media, type)	(((media)&(type))==(type))

typedef enum {
	BRASERO_MEDIUM_TRACK_NONE		= 0,
	BRASERO_MEDIUM_TRACK_DATA		= 1,
	BRASERO_MEDIUM_TRACK_AUDIO		= 1 << 1,
	BRASERO_MEDIUM_TRACK_COPY		= 1 << 2,
	BRASERO_MEDIUM_TRACK_PREEMP		= 1 << 3,
	BRASERO_MEDIUM_TRACK_4_CHANNELS		= 1 << 4,
	BRASERO_MEDIUM_TRACK_INCREMENTAL	= 1 << 5,
	BRASERO_MEDIUM_TRACK_LEADOUT		= 1 << 6
} BraseroMediumTrackType;

struct _BraseroMediumTrack {
	guint session;
	BraseroMediumTrackType type;
	guint64 start;
	guint64 blocks_num;
};
typedef struct _BraseroMediumTrack BraseroMediumTrack;

BraseroMedia
brasero_medium_get_status (BraseroMedium *medium);

GSList *
brasero_medium_get_tracks (BraseroMedium *medium);

gboolean
brasero_medium_get_last_data_track_space (BraseroMedium *medium,
					  gint64 *size,
					  gint64 *blocks);

gboolean
brasero_medium_get_last_data_track_address (BraseroMedium *medium,
					    gint64 *byte,
					    gint64 *sector);
guint
brasero_medium_get_track_num (BraseroMedium *medium);

gboolean
brasero_medium_get_track_space (BraseroMedium *medium,
				guint num,
				gint64 *size,
				gint64 *blocks);

gboolean
brasero_medium_get_track_address (BraseroMedium *medium,
				  guint num,
				  gint64 *byte,
				  gint64 *sector);

gint64
brasero_medium_get_next_writable_address (BraseroMedium *medium);

gint64
brasero_medium_get_max_write_speed (BraseroMedium *medium);

void
brasero_medium_get_free_space (BraseroMedium *medium,
			       gint64 *size,
			       gint64 *blocks);

void
brasero_medium_get_capacity (BraseroMedium *medium,
			     gint64 *size,
			     gint64 *blocks);

void
brasero_medium_get_data_size (BraseroMedium *medium,
			      gint64 *size,
			      gint64 *blocks);

gboolean
brasero_medium_can_be_rewritten (BraseroMedium *medium);

gboolean
brasero_medium_can_be_written (BraseroMedium *medium);

const gchar *
brasero_medium_get_type_string (BraseroMedium *medium);

const gchar *
brasero_medium_get_icon (BraseroMedium *medium);

gchar *
brasero_medium_get_label (BraseroMedium *medium,
			  gboolean with_markup);

BraseroDrive *
brasero_medium_get_drive (BraseroMedium *self);

G_END_DECLS

#endif /* _BURN_MEDIUM_H_ */
