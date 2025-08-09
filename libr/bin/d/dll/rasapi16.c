// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 rasapi16.c ; ./a.out > rasapi16.h
	{"1", "WEP"},
	{"2", "DLLENTRYPOINT"},
	{"3", "RNA1632_THUNKDATA16"},
	{"4", "RASGETERRORSTRING"},
	{"5", "RASENUMCONNECTIONS"},
	{"6", "RASHANGUP"},
	{"7", "RASENUMENTRIES"},
	{"8", "RASGETCONNECTSTATUS"},
	{"9", "RASDIAL"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_rasapi16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_rasapi16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_rasapi16(x,y) gperf_rasapi16_hash(x)
const unsigned int gperf_rasapi16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_rasapi16 = {
  .name = "rasapi16",
  .get = &gperf_rasapi16_get,
  .hash = &gperf_rasapi16_hash,
  .foreach = &gperf_rasapi16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_rasapi16.get)("foo");
	printf ("%s\n", s);
}
#endif
