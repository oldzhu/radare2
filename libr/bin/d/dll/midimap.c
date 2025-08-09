// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 midimap.c ; ./a.out > midimap.h
	{"2", "DRIVERPROC"},
	{"3", "MODMESSAGE"},
	{"4", "MODMCALLBACK"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_midimap_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_midimap_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_midimap(x,y) gperf_midimap_hash(x)
const unsigned int gperf_midimap_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_midimap = {
  .name = "midimap",
  .get = &gperf_midimap_get,
  .hash = &gperf_midimap_hash,
  .foreach = &gperf_midimap_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_midimap.get)("foo");
	printf ("%s\n", s);
}
#endif
