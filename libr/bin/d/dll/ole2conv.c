// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 ole2conv.c ; ./a.out > ole2conv.h
	{"1", "GETFILTERINFO"},
	{"2", "IMPORTGR"},
	{"3", "GETFILTERPREF"},
	{"4", "IMPORTEMBEDDEDGR"},
	{"5", "QD2GDI"},
	{"6", "STATUSPROC"},
	{"7", "ENUMFONTFUNC"},
	{"8", "WEP"},
	{"9", "___EXPORTEDSTUB"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_ole2conv_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_ole2conv_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_ole2conv(x,y) gperf_ole2conv_hash(x)
const unsigned int gperf_ole2conv_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_ole2conv = {
  .name = "ole2conv",
  .get = &gperf_ole2conv_get,
  .hash = &gperf_ole2conv_hash,
  .foreach = &gperf_ole2conv_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_ole2conv.get)("foo");
	printf ("%s\n", s);
}
#endif
