// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 msprint.c ; ./a.out > msprint.h
	{"1", "DLLENTRYPOINT"},
	{"2", "MSPTHK_THUNKDATA16"},
	{"3", "MSPFTHK_THUNKDATA16"},
	{"4", "CLASSINSTALL"},
	{"5", "SETUPENTRY"},
	{"6", "___EXPORTEDSTUB"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_msprint_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_msprint_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_msprint(x,y) gperf_msprint_hash(x)
const unsigned int gperf_msprint_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_msprint = {
  .name = "msprint",
  .get = &gperf_msprint_get,
  .hash = &gperf_msprint_hash,
  .foreach = &gperf_msprint_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_msprint.get)("foo");
	printf ("%s\n", s);
}
#endif
