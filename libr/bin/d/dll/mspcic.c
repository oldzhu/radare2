// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mspcic.c ; ./a.out > mspcic.h
	{"1", "CPLAPPLET"},
	{"2", "CLASSINSTALL"},
	{"3", "___EXPORTEDSTUB"},
	{"4", "ENUMCLASSPROPPAGES"},
	{"5", "PCMCIA_RUNDLL"},
	{"6", "EJECTSOCKET"},
	{"7", "EJECTWARNINGDLG"},
	{"999", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mspcic_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mspcic_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mspcic(x,y) gperf_mspcic_hash(x)
const unsigned int gperf_mspcic_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mspcic = {
  .name = "mspcic",
  .get = &gperf_mspcic_get,
  .hash = &gperf_mspcic_hash,
  .foreach = &gperf_mspcic_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mspcic.get)("foo");
	printf ("%s\n", s);
}
#endif
