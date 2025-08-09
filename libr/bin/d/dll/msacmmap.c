// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 msacmmap.c ; ./a.out > msacmmap.h
	{"1", "WEP"},
	{"2", "DRIVERPROC"},
	{"3", "___EXPORTEDSTUB"},
	{"4", "WODMESSAGE"},
	{"5", "WIDMESSAGE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_msacmmap_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_msacmmap_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_msacmmap(x,y) gperf_msacmmap_hash(x)
const unsigned int gperf_msacmmap_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_msacmmap = {
  .name = "msacmmap",
  .get = &gperf_msacmmap_get,
  .hash = &gperf_msacmmap_hash,
  .foreach = &gperf_msacmmap_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_msacmmap.get)("foo");
	printf ("%s\n", s);
}
#endif
