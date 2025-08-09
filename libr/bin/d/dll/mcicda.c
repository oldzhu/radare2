// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mcicda.c ; ./a.out > mcicda.h
	{"1", "WEP"},
	{"2", "DRIVERPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mcicda_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mcicda_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mcicda(x,y) gperf_mcicda_hash(x)
const unsigned int gperf_mcicda_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mcicda = {
  .name = "mcicda",
  .get = &gperf_mcicda_get,
  .hash = &gperf_mcicda_hash,
  .foreach = &gperf_mcicda_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mcicda.get)("foo");
	printf ("%s\n", s);
}
#endif
