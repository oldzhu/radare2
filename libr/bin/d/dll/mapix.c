// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mapix.c ; ./a.out > mapix.h
	{"1", "WEP"},
	{"11", "MAPILOGON"},
	{"111", "MAPILOGONA"},
	{"116", "_MAPIADMINPROFILES"},
	{"16", "MAPIADMINPROFILES"},
	{"18", "MAPIFREEBUFFER"},
	{"2", "___EXPORTEDSTUB"},
	{"290", "_MAPIALLOCATEBUFFER"},
	{"291", "MAPIALLOCATEBUFFER"},
	{"3", "MAPIINITIALIZE"},
	{"300", "_MAPIALLOCATEMORE"},
	{"301", "MAPIALLOCATEMORE"},
	{"5", "MAPIUNINITIALIZE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mapix_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mapix_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mapix(x,y) gperf_mapix_hash(x)
const unsigned int gperf_mapix_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mapix = {
  .name = "mapix",
  .get = &gperf_mapix_get,
  .hash = &gperf_mapix_hash,
  .foreach = &gperf_mapix_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mapix.get)("foo");
	printf ("%s\n", s);
}
#endif
