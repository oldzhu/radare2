// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 win87em.c ; ./a.out > win87em.h
	{"1", "__FPMATH"},
	{"2", "WEP"},
	{"3", "__WIN87EMRESTORE"},
	{"4", "__WIN87EMSAVE"},
	{"5", "__WIN87EMINFO"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_win87em_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_win87em_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_win87em(x,y) gperf_win87em_hash(x)
const unsigned int gperf_win87em_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_win87em = {
  .name = "win87em",
  .get = &gperf_win87em_get,
  .hash = &gperf_win87em_hash,
  .foreach = &gperf_win87em_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_win87em.get)("foo");
	printf ("%s\n", s);
}
#endif
