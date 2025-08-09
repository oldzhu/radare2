// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 commctrl.c ; ./a.out > commctrl.h
	{"1", "WEP"},
	{"10", "TV_EDITWNDPROC"},
	{"11", "LISTVIEW_EDITWNDPROC"},
	{"12", "TV_WNDPROC"},
	{"13", "MAKEDRAGLIST"},
	{"14", "LBITEMFROMPT"},
	{"15", "DRAWINSERT"},
	{"159", "PROPERTYSHEET"},
	{"16", "CREATEUPDOWNCONTROL"},
	{"160", "CREATEPROPERTYSHEETPAGE"},
	{"161", "DESTROYPROPERTYSHEETPAGE"},
	{"17", "INITCOMMONCONTROLS"},
	{"2", "MENUHELP"},
	{"20", "CREATETOOLBAREX"},
	{"3", "SHOWHIDEMENUCTL"},
	{"300", "DLLENTRYPOINT"},
	{"301", "CCTL1632_THUNKDATA16"},
	{"328", "DPA_CREATE"},
	{"329", "DPA_DESTROY"},
	{"330", "DPA_GROW"},
	{"331", "DPA_CLONE"},
	{"332", "DPA_GETPTR"},
	{"333", "DPA_GETPTRINDEX"},
	{"334", "DPA_INSERTPTR"},
	{"335", "DPA_SETPTR"},
	{"336", "DPA_DELETEPTR"},
	{"337", "DPA_DELETEALLPTRS"},
	{"338", "DPA_SORT"},
	{"339", "DPA_SEARCH"},
	{"4", "GETEFFECTIVECLIENTRECT"},
	{"40", "IMAGELIST_CREATE"},
	{"41", "IMAGELIST_DESTROY"},
	{"42", "IMAGELIST_GETIMAGECOUNT"},
	{"43", "IMAGELIST_SETOVERLAYIMAGE"},
	{"44", "IMAGELIST_SETBKCOLOR"},
	{"45", "IMAGELIST_GETBKCOLOR"},
	{"46", "IMAGELIST_ADD"},
	{"49", "IMAGELIST_DRAW"},
	{"5", "DRAWSTATUSTEXT"},
	{"53", "IMAGELIST_ADDICON"},
	{"54", "IMAGELIST_REPLACEICON"},
	{"6", "CREATESTATUSWINDOW"},
	{"7", "CREATETOOLBAR"},
	{"8", "CREATEMAPPEDBITMAP"},
	{"9", "LISTVIEW_WNDPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_commctrl_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_commctrl_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_commctrl(x,y) gperf_commctrl_hash(x)
const unsigned int gperf_commctrl_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_commctrl = {
  .name = "commctrl",
  .get = &gperf_commctrl_get,
  .hash = &gperf_commctrl_hash,
  .foreach = &gperf_commctrl_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_commctrl.get)("foo");
	printf ("%s\n", s);
}
#endif
