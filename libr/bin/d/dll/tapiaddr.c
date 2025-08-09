// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 tapiaddr.c ; ./a.out > tapiaddr.h
	{"1", "WEP"},
	{"10", "TAPIADDR_INICHANGED"},
	{"100", "GETDIALANDDISPLAYDLG"},
	{"2", "TAPIADDR_SETCURRENTLOCATION"},
	{"3", "TAPIADDR_SETTOLLLIST"},
	{"4", "TAPIADDR_TRANSLATEADDRESS"},
	{"5", "TAPIADDR_GETTRANSLATECAPS"},
	{"6", "LGETCOUNTRYCODEFROMID"},
	{"7", "___EXPORTEDSTUB"},
	{"8", "GETTOLLPREFIX"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_tapiaddr_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_tapiaddr_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_tapiaddr(x,y) gperf_tapiaddr_hash(x)
const unsigned int gperf_tapiaddr_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_tapiaddr = {
  .name = "tapiaddr",
  .get = &gperf_tapiaddr_get,
  .hash = &gperf_tapiaddr_hash,
  .foreach = &gperf_tapiaddr_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_tapiaddr.get)("foo");
	printf ("%s\n", s);
}
#endif
