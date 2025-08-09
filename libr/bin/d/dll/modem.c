// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 modem.c ; ./a.out > modem.h
	{"1", "CPLAPPLET"},
	{"2", "WEP"},
	{"3", "CLASSINSTALL"},
	{"4", "INSTALLLOCALCONNECTIONS"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_modem_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_modem_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_modem(x,y) gperf_modem_hash(x)
const unsigned int gperf_modem_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_modem = {
  .name = "modem",
  .get = &gperf_modem_get,
  .hash = &gperf_modem_hash,
  .foreach = &gperf_modem_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_modem.get)("foo");
	printf ("%s\n", s);
}
#endif
