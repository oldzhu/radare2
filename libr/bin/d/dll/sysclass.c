// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 sysclass.c ; ./a.out > sysclass.h
	{"1", "ENUMPROPPAGES"},
	{"2", "DMAPROBLEMHANDLER"},
	{"3", "CLASSINSTALL"},
	{"4", "DMAENUMPROPPAGES"},
	{"6", "FPUENUMPROPPAGES"},
	{"7", "APMENUMPROPPAGES"},
	{"999", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_sysclass_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_sysclass_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_sysclass(x,y) gperf_sysclass_hash(x)
const unsigned int gperf_sysclass_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_sysclass = {
  .name = "sysclass",
  .get = &gperf_sysclass_get,
  .hash = &gperf_sysclass_hash,
  .foreach = &gperf_sysclass_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_sysclass.get)("foo");
	printf ("%s\n", s);
}
#endif
