// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 ole2nls.c ; ./a.out > ole2nls.h
	{"1", "GETUSERDEFAULTLCID"},
	{"10", "WEP"},
	{"11", "LIBMAIN"},
	{"12", "NOTIFYWINDOWPROC"},
	{"2", "GETSYSTEMDEFAULTLCID"},
	{"3", "GETUSERDEFAULTLANGID"},
	{"4", "GETSYSTEMDEFAULTLANGID"},
	{"5", "GETLOCALEINFOA"},
	{"6", "LCMAPSTRINGA"},
	{"7", "GETSTRINGTYPEA"},
	{"8", "COMPARESTRINGA"},
	{"9", "REGISTERNLSINFOCHANGED"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_ole2nls_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_ole2nls_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_ole2nls(x,y) gperf_ole2nls_hash(x)
const unsigned int gperf_ole2nls_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_ole2nls = {
  .name = "ole2nls",
  .get = &gperf_ole2nls_get,
  .hash = &gperf_ole2nls_hash,
  .foreach = &gperf_ole2nls_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_ole2nls.get)("foo");
	printf ("%s\n", s);
}
#endif
