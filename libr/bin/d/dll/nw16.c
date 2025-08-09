// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 nw16.c ; ./a.out > nw16.h
	{"1", "WEP"},
	{"2", "___EXPORTEDSTUB"},
	{"3", "NWSDSCANBINDERYOBJECT"},
	{"701", "FT_NWNPFTHKTHKCONNECTIONDATA"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_nw16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_nw16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_nw16(x,y) gperf_nw16_hash(x)
const unsigned int gperf_nw16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_nw16 = {
  .name = "nw16",
  .get = &gperf_nw16_get,
  .hash = &gperf_nw16_hash,
  .foreach = &gperf_nw16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_nw16.get)("foo");
	printf ("%s\n", s);
}
#endif
