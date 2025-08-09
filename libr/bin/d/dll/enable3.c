// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 enable3.c ; ./a.out > enable3.h
	{"1", "WEP"},
	{"2", "HELPER_FLASHITEM"},
	{"3", "HELPER_CLEARHIGHCONTRAST"},
	{"4", "HELPER_SETHIGHCONTRAST"},
	{"5", "HELPER_CREATETRANSLATIONTABLE"},
	{"6", "HELPER_DISPLAYWARNING"},
	{"7", "HELPER_SPAWNSTATUSAPP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_enable3_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_enable3_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_enable3(x,y) gperf_enable3_hash(x)
const unsigned int gperf_enable3_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_enable3 = {
  .name = "enable3",
  .get = &gperf_enable3_get,
  .hash = &gperf_enable3_hash,
  .foreach = &gperf_enable3_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_enable3.get)("foo");
	printf ("%s\n", s);
}
#endif
