// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 netware.c ; ./a.out > netware.h
	{"1", "WEP"},
	{"1000", "NETWAREREQUEST"},
	{"1001", "PNETWAREREQUEST"},
	{"12", "WNETGETCONNECTION"},
	{"17", "WNETADDCONNECTION"},
	{"18", "WNETCANCELCONNECTION"},
	{"520", "ALWNETCOMMONDIALOG"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_netware_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_netware_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_netware(x,y) gperf_netware_hash(x)
const unsigned int gperf_netware_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_netware = {
  .name = "netware",
  .get = &gperf_netware_get,
  .hash = &gperf_netware_hash,
  .foreach = &gperf_netware_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_netware.get)("foo");
	printf ("%s\n", s);
}
#endif
