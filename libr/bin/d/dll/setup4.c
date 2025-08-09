// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 setup4.c ; ./a.out > setup4.h
	{"1", "WEP"},
	{"200", "DIGETCLASSIMAGELIST"},
	{"201", "DIGETCLASSIMAGEINDEX"},
	{"300", "DIGETCLASSDEVPROPERTYSHEETS"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_setup4_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_setup4_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_setup4(x,y) gperf_setup4_hash(x)
const unsigned int gperf_setup4_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_setup4 = {
  .name = "setup4",
  .get = &gperf_setup4_get,
  .hash = &gperf_setup4_hash,
  .foreach = &gperf_setup4_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_setup4.get)("foo");
	printf ("%s\n", s);
}
#endif
