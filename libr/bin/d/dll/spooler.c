// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 spooler.c ; ./a.out > spooler.h
	{"1", "SPOOLERWNDPROC"},
	{"2", "ABOUT"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_spooler_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_spooler_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_spooler(x,y) gperf_spooler_hash(x)
const unsigned int gperf_spooler_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_spooler = {
  .name = "spooler",
  .get = &gperf_spooler_get,
  .hash = &gperf_spooler_hash,
  .foreach = &gperf_spooler_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_spooler.get)("foo");
	printf ("%s\n", s);
}
#endif
