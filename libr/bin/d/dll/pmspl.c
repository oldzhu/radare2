// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 pmspl.c ; ./a.out > pmspl.h
	{"1", "WEP"},
	{"101", "DOSPRINTDESTADD"},
	{"102", "DOSPRINTDESTSETINFO"},
	{"103", "DOSPRINTDESTDEL"},
	{"104", "DOSPRINTQPURGE"},
	{"105", "DOSPRINTJOBGETID"},
	{"80", "DOSPRINTDESTCONTROL"},
	{"81", "DOSPRINTDESTGETINFO"},
	{"82", "DOSPRINTDESTENUM"},
	{"84", "DOSPRINTJOBCONTINUE"},
	{"85", "DOSPRINTJOBPAUSE"},
	{"86", "DOSPRINTJOBDEL"},
	{"90", "DOSPRINTJOBGETINFO"},
	{"91", "DOSPRINTJOBSETINFO"},
	{"92", "DOSPRINTJOBENUM"},
	{"93", "DOSPRINTQADD"},
	{"94", "DOSPRINTQPAUSE"},
	{"95", "DOSPRINTQCONTINUE"},
	{"96", "DOSPRINTQDEL"},
	{"97", "DOSPRINTQGETINFO"},
	{"98", "DOSPRINTQSETINFO"},
	{"99", "DOSPRINTQENUM"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_pmspl_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_pmspl_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_pmspl(x,y) gperf_pmspl_hash(x)
const unsigned int gperf_pmspl_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_pmspl = {
  .name = "pmspl",
  .get = &gperf_pmspl_get,
  .hash = &gperf_pmspl_hash,
  .foreach = &gperf_pmspl_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_pmspl.get)("foo");
	printf ("%s\n", s);
}
#endif
