// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 olesvr.c ; ./a.out > olesvr.h
	{"1", "WEP"},
	{"10", "OLESAVEDSERVERDOC"},
	{"11", "OLEREVOKEOBJECT"},
	{"12", "OLEQUERYSERVERVERSION"},
	{"2", "OLEREGISTERSERVER"},
	{"21", "SRVRWNDPROC"},
	{"22", "DOCWNDPROC"},
	{"23", "ITEMWNDPROC"},
	{"24", "SENDDATAMSG"},
	{"25", "FINDITEMWND"},
	{"26", "ITEMCALLBACK"},
	{"27", "TERMINATECLIENTS"},
	{"28", "TERMINATEDOCCLIENTS"},
	{"29", "DELETECLIENTINFO"},
	{"3", "OLEREVOKESERVER"},
	{"30", "SENDRENAMEMSG"},
	{"31", "ENUMFORTERMINATE"},
	{"4", "OLEBLOCKSERVER"},
	{"5", "OLEUNBLOCKSERVER"},
	{"6", "OLEREGISTERSERVERDOC"},
	{"7", "OLEREVOKESERVERDOC"},
	{"8", "OLERENAMESERVERDOC"},
	{"9", "OLEREVERTSERVERDOC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_olesvr_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_olesvr_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_olesvr(x,y) gperf_olesvr_hash(x)
const unsigned int gperf_olesvr_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_olesvr = {
  .name = "olesvr",
  .get = &gperf_olesvr_get,
  .hash = &gperf_olesvr_hash,
  .foreach = &gperf_olesvr_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_olesvr.get)("foo");
	printf ("%s\n", s);
}
#endif
