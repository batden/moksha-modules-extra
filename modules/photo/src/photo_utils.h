#ifdef E_MOD_PHOTO_TYPEDEFS



#else

#ifndef PHOTO_UTILS_H_INCLUDED
#define PHOTO_UTILS_H_INCLUDED

#define UTIL_TEST_PARENT(son, parent, label, default) \
( (son == label) ||                                   \
  ((son == default) &&                                \
   (parent == label)) )

void photo_util_edje_set(Evas_Object *obj, char *key);
void photo_util_icon_set(Evas_Object *ic, char *key);
void photo_util_menu_icon_set(E_Menu_Item *mi, char *key);
Eina_Bool photo_util_image_size(const char *path, int *w, int *h);
char * photo_util_pictures_dir();

#endif
#endif
