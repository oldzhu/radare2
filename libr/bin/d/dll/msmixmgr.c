// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 msmixmgr.c ; ./a.out > msmixmgr.h
	{"1", "WEP"},
	{"10", "MIXERGETNUMDEVS"},
	{"11", "MIXERGETDEVCAPS"},
	{"12", "MIXERGETID"},
	{"13", "MIXEROPEN"},
	{"14", "MIXERCLOSE"},
	{"15", "MIXERMESSAGE"},
	{"16", "MIXERGETLINEINFO"},
	{"17", "MIXERGETLINECONTROLS"},
	{"18", "MIXERGETCONTROLDETAILS"},
	{"19", "MIXERSETCONTROLDETAILS"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_msmixmgr_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_msmixmgr_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_msmixmgr(x,y) gperf_msmixmgr_hash(x)
const unsigned int gperf_msmixmgr_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_msmixmgr = {
  .name = "msmixmgr",
  .get = &gperf_msmixmgr_get,
  .hash = &gperf_msmixmgr_hash,
  .foreach = &gperf_msmixmgr_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_msmixmgr.get)("foo");
	printf ("%s\n", s);
}
#endif
