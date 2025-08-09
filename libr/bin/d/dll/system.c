// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 system.c ; ./a.out > system.h
	{"1", "INQUIRESYSTEM"},
	{"10", "WEP"},
	{"13", "INQUIRELONGINTS"},
	{"2", "CREATESYSTEMTIMER"},
	{"20", "A20_PROC"},
	{"21", "KILLSYSTEMTIMERCS"},
	{"22", "__GP"},
	{"3", "KILLSYSTEMTIMER"},
	{"4", "ENABLESYSTEMTIMERS"},
	{"5", "DISABLESYSTEMTIMERS"},
	{"6", "GETSYSTEMMSECCOUNT"},
	{"7", "GET80X87SAVESIZE"},
	{"8", "SAVE80X87STATE"},
	{"9", "RESTORE80X87STATE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_system_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_system_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_system(x,y) gperf_system_hash(x)
const unsigned int gperf_system_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_system = {
  .name = "system",
  .get = &gperf_system_get,
  .hash = &gperf_system_hash,
  .foreach = &gperf_system_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_system.get)("foo");
	printf ("%s\n", s);
}
#endif
