// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mcimidi.c ; ./a.out > mcimidi.h
	{"1", "DRIVERPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mcimidi_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mcimidi_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mcimidi(x,y) gperf_mcimidi_hash(x)
const unsigned int gperf_mcimidi_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mcimidi = {
  .name = "mcimidi",
  .get = &gperf_mcimidi_get,
  .hash = &gperf_mcimidi_hash,
  .foreach = &gperf_mcimidi_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mcimidi.get)("foo");
	printf ("%s\n", s);
}
#endif
