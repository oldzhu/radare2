// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 sysedit.c ; ./a.out > sysedit.h
	{"1", "MPFRAMEWNDPROC"},
	{"2", "MPMDICHILDWNDPROC"},
	{"4", "FINDDLGPROC"},
	{"5", "SAVEASDLGPROC"},
	{"6", "PRINTDLGPROC"},
	{"7", "ABORTPROC"},
	{"8", "FILEOPENDLGPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_sysedit_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_sysedit_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_sysedit(x,y) gperf_sysedit_hash(x)
const unsigned int gperf_sysedit_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_sysedit = {
  .name = "sysedit",
  .get = &gperf_sysedit_get,
  .hash = &gperf_sysedit_hash,
  .foreach = &gperf_sysedit_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_sysedit.get)("foo");
	printf ("%s\n", s);
}
#endif
