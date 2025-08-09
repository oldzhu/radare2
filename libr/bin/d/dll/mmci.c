// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mmci.c ; ./a.out > mmci.h
	{"1", "WEP"},
	{"2", "CLASSINSTALL"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mmci_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mmci_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mmci(x,y) gperf_mmci_hash(x)
const unsigned int gperf_mmci_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mmci = {
  .name = "mmci",
  .get = &gperf_mmci_get,
  .hash = &gperf_mmci_hash,
  .foreach = &gperf_mmci_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mmci.get)("foo");
	printf ("%s\n", s);
}
#endif
