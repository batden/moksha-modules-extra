#ifndef E_MOD_MAIN_H
#define E_MOD_MAIN_H

#include "config.h"

#ifdef HAVE_GETTEXT
# include <libintl.h>
# define D_(string) dgettext(LOCALEDOMAIN, string)
#else
# define bindtextdomain(domain,dir)
# define bind_textdomain_codeset(domain,codeset)
# define D_(string) (string)
#endif
#define N_(string) (string)


typedef struct _Config Config;
typedef struct _Config_Item Config_Item;

struct _Config
{
   E_Module        *module;
   E_Menu          *menu_firstweekday;
   Ecore_Timer     *timer;
   Eina_List       *instances;
   Eina_List       *items;
};

struct _Config_Item
{
   const char *id;
   int firstweekday;
};

EAPI extern E_Module_Api e_modapi;

EAPI void *e_modapi_init     (E_Module *m);
EAPI int   e_modapi_shutdown (E_Module *m);
EAPI int   e_modapi_save     (E_Module *m);

#endif
