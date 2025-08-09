// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 iosclass.c ; ./a.out > iosclass.h
	{"1", "ENUMPROPPAGES"},
	{"2", "CDROMCLASSINSTALL"},
	{"3", "SCSIENUMPROPPAGES"},
	{"999", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_iosclass_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_iosclass_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_iosclass(x,y) gperf_iosclass_hash(x)
const unsigned int gperf_iosclass_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_iosclass = {
  .name = "iosclass",
  .get = &gperf_iosclass_get,
  .hash = &gperf_iosclass_hash,
  .foreach = &gperf_iosclass_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_iosclass.get)("foo");
	printf ("%s\n", s);
}
#endif
