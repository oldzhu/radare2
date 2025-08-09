// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 wpsunire.c ; ./a.out > wpsunire.h
	{"1", "WEP"},
	{"2", "HHREOPEN"},
	{"3", "UIHREWRITE"},
	{"5", "UIHREEXECUTE"},
	{"6", "UIHRECLOSE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_wpsunire_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_wpsunire_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_wpsunire(x,y) gperf_wpsunire_hash(x)
const unsigned int gperf_wpsunire_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_wpsunire = {
  .name = "wpsunire",
  .get = &gperf_wpsunire_get,
  .hash = &gperf_wpsunire_hash,
  .foreach = &gperf_wpsunire_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_wpsunire.get)("foo");
	printf ("%s\n", s);
}
#endif
