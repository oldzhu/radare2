// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 winaspi.c ; ./a.out > winaspi.h
	{"1", "SENDASPICOMMAND"},
	{"2", "GETASPISUPPORTINFO"},
	{"3", "INSERTINASPICHAIN"},
	{"4", "GETASPIDLLVERSION"},
	{"5", "___EXPORTEDSTUB"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_winaspi_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_winaspi_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_winaspi(x,y) gperf_winaspi_hash(x)
const unsigned int gperf_winaspi_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_winaspi = {
  .name = "winaspi",
  .get = &gperf_winaspi_get,
  .hash = &gperf_winaspi_hash,
  .foreach = &gperf_winaspi_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_winaspi.get)("foo");
	printf ("%s\n", s);
}
#endif
