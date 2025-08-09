// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 deskcp16.c ; ./a.out > deskcp16.h
	{"1", "WEP"},
	{"10", "SCREENSAVERDLGPROC"},
	{"11", "CUSTOMFONTDLGPROC"},
	{"12", "GETDISPLAYSAVERPAGE"},
	{"13", "ADAPTERDLGPROC"},
	{"14", "GETDISPLAYFALLBACKPAGE"},
	{"15", "LOOKPREVIEWWNDPROC"},
	{"16", "BACKGROUNDDLGPROC"},
	{"17", "GETDISPLAYAPPEARANCEPAGE"},
	{"18", "GETDISPLAYBACKGROUNDPAGE"},
	{"19", "MONITORDLGPROC"},
	{"2", "COLORPICKDLGPROC"},
	{"3", "CPLAPPLET"},
	{"4", "DESKSETCURRENTSCHEME"},
	{"5", "BACKPREVIEWWNDPROC"},
	{"6", "GETDISPLAYSETTINGSPAGE"},
	{"7", "KEEPNEWDLGPROC"},
	{"8", "STATICSUBCLASSPROC"},
	{"9", "APPEARANCEDLGPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_deskcp16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_deskcp16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_deskcp16(x,y) gperf_deskcp16_hash(x)
const unsigned int gperf_deskcp16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_deskcp16 = {
  .name = "deskcp16",
  .get = &gperf_deskcp16_get,
  .hash = &gperf_deskcp16_hash,
  .foreach = &gperf_deskcp16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_deskcp16.get)("foo");
	printf ("%s\n", s);
}
#endif
