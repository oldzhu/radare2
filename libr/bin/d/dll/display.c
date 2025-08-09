// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 display.c ; ./a.out > display.h
	{"1", "BITBLT"},
	{"10", "REALIZEOBJECT"},
	{"101", "INQUIRE"},
	{"102", "SETCURSOR"},
	{"103", "MOVECURSOR"},
	{"104", "CHECKCURSOR"},
	{"11", "STRBLT"},
	{"12", "SCANLR"},
	{"13", "DEVICEMODE"},
	{"14", "EXTTEXTOUT"},
	{"15", "GETCHARWIDTH"},
	{"16", "DEVICEBITMAP"},
	{"17", "FASTBORDER"},
	{"18", "SETATTRIBUTE"},
	{"19", "DEVICEBITMAPBITS"},
	{"2", "COLORINFO"},
	{"20", "CREATEBITMAP"},
	{"21", "DIBSCREENBLT"},
	{"3", "CONTROL"},
	{"4", "DISABLE"},
	{"5", "ENABLE"},
	{"500", "USERREPAINTDISABLE"},
	{"6", "ENUMDFONTS"},
	{"600", "INKREADY"},
	{"601", "GETLPDEVICE"},
	{"7", "ENUMOBJ"},
	{"8", "OUTPUT"},
	{"9", "PIXEL"},
	{"90", "DO_POLYLINES"},
	{"91", "DO_SCANLINES"},
	{"92", "SAVESCREENBITMAP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_display_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_display_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_display(x,y) gperf_display_hash(x)
const unsigned int gperf_display_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_display = {
  .name = "display",
  .get = &gperf_display_get,
  .hash = &gperf_display_hash,
  .foreach = &gperf_display_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_display.get)("foo");
	printf ("%s\n", s);
}
#endif
