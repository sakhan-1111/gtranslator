/*
 * Copyright (C) 2008  Ignacio Casal Quinteiro <nacho.resa@gmail.com>
 * 
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __DB_WORDS_H__
#define __DB_WORDS_H__

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include "gtr-db-base.h"
#include "gtr-db-keys.h"

G_BEGIN_DECLS
/*
 * Type checking and casting macros
 */
#define GTR_TYPE_DB_WORDS		(gtr_db_words_get_type ())
#define GTR_DB_WORDS(o)		(G_TYPE_CHECK_INSTANCE_CAST ((o), GTR_TYPE_DB_WORDS, GtrDbWords))
#define GTR_DB_WORDS_CLASS(k)	(G_TYPE_CHECK_CLASS_CAST((k), GTR_TYPE_DB_WORDS, GtrDbWordsClass))
#define GTR_IS_DB_WORDS(o)		(G_TYPE_CHECK_INSTANCE_TYPE ((o), GTR_TYPE_DB_WORDS))
#define GTR_IS_DB_WORDS_CLASS(k)	(G_TYPE_CHECK_CLASS_TYPE ((k), GTR_TYPE_DB_WORDS))
#define GTR_DB_WORDS_GET_CLASS(o)	(G_TYPE_INSTANCE_GET_CLASS ((o), GTR_TYPE_DB_WORDS, GtrDbWordsClass))
/* Private structure type */
typedef struct _GtrDbWordsPrivate GtrDbWordsPrivate;

/*
 * Main object structure
 */
typedef struct _GtrDbWords GtrDbWords;

struct _GtrDbWords
{
  GtrDbBase parent_instance;

  /*< private > */
  GtrDbWordsPrivate *priv;
};

/*
 * Class definition
 */
typedef struct _GtrDbWordsClass GtrDbWordsClass;

struct _GtrDbWordsClass
{
  GtrDbBaseClass parent_class;
};

/*
 * Public methods
 */
GType
gtr_db_words_get_type (void)
  G_GNUC_CONST;

     GType gtr_db_words_register_type (GTypeModule * module);

     GtrDbWords *gtr_db_words_new (void);

     gboolean gtr_db_words_append (GtrDbWords * db_words,
                                   const gchar * word,
                                   guint sentence_size, db_recno_t value);

     GtrDbKeys *gtr_db_words_read (GtrDbWords *
                                   db_words,
                                   const gchar * word, guint sentence_size);

G_END_DECLS
#endif /* __DB_WORDS_H__ */