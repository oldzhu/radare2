// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 dibeng.c ; ./a.out > dibeng.h
	{"1", "DIB_BITBLT"},
	{"10", "DIB_REALIZEOBJECT"},
	{"101", "DIB_INQUIRE"},
	{"102", "DIB_SETCURSOREXT"},
	{"103", "DIB_MOVECURSOREXT"},
	{"104", "DIB_CHECKCURSOREXT"},
	{"105", "DIB_BEGINACCESS"},
	{"106", "DIB_ENDACCESS"},
	{"11", "DIB_STRBLT"},
	{"12", "DIB_SCANLR"},
	{"13", "DIB_DEVICEMODE"},
	{"14", "DIB_EXTTEXTOUT"},
	{"15", "DIB_GETCHARWIDTH"},
	{"16", "DIB_DEVICEBITMAP"},
	{"17", "DIB_FASTBORDER"},
	{"18", "DIB_SETATTRIBUTE"},
	{"19", "DIB_DIBBLT"},
	{"2", "DIB_COLORINFO"},
	{"20", "DIB_CREATEDIBITMAP"},
	{"21", "DIB_DIBTODEVICE"},
	{"22", "DIB_SETPALETTE"},
	{"23", "DIB_GETPALETTE"},
	{"24", "DIB_SETPALETTETRANSLATE"},
	{"25", "DIB_GETPALETTETRANSLATE"},
	{"26", "DIB_UPDATECOLORS"},
	{"27", "DIB_STRETCHBLT"},
	{"28", "DIB_STRETCHDIBITS"},
	{"29", "DIB_SELECTBITMAP"},
	{"3", "DIB_CONTROL"},
	{"30", "DIB_BITMAPBITS"},
	{"300", "CREATEDIBPDEVICE"},
	{"4", "DIB_DISABLE"},
	{"400", "DIB_REALIZEOBJECTEXT"},
	{"401", "DIB_DIBBLTEXT"},
	{"402", "DIB_ENUMOBJEXT"},
	{"403", "DIB_EXTTEXTOUTEXT"},
	{"404", "DIB_UPDATECOLORSEXT"},
	{"405", "DIB_SETPALETTEEXT"},
	{"406", "DIB_GETPALETTEEXT"},
	{"407", "DIB_SETPALETTETRANSLATEEXT"},
	{"408", "DIB_GETPALETTETRANSLATEEXT"},
	{"5", "DIB_ENABLE"},
	{"6", "DIB_ENUMDFONTS"},
	{"7", "DIB_ENUMOBJ"},
	{"8", "DIB_OUTPUT"},
	{"9", "DIB_PIXEL"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_dibeng_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_dibeng_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_dibeng(x,y) gperf_dibeng_hash(x)
const unsigned int gperf_dibeng_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_dibeng = {
  .name = "dibeng",
  .get = &gperf_dibeng_get,
  .hash = &gperf_dibeng_hash,
  .foreach = &gperf_dibeng_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_dibeng.get)("foo");
	printf ("%s\n", s);
}
#endif
