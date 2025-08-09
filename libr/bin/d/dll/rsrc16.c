// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 rsrc16.c ; ./a.out > rsrc16.h
	{"1", "THK_THUNKDATA16"},
	{"2", "DLLENTRYPOINT"},
	{"3", "MYGETFREESYSTEMRESOURCES16"},
	{"4", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_rsrc16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_rsrc16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_rsrc16(x,y) gperf_rsrc16_hash(x)
const unsigned int gperf_rsrc16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_rsrc16 = {
  .name = "rsrc16",
  .get = &gperf_rsrc16_get,
  .hash = &gperf_rsrc16_hash,
  .foreach = &gperf_rsrc16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_rsrc16.get)("foo");
	printf ("%s\n", s);
}
#endif
