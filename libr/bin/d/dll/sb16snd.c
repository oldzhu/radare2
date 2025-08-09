// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 sb16snd.c ; ./a.out > sb16snd.h
	{"1", "WEP"},
	{"2", "DRIVERPROC"},
	{"3", "WODMESSAGE"},
	{"4", "WIDMESSAGE"},
	{"5", "MODMESSAGE"},
	{"6", "MIDMESSAGE"},
	{"7", "AUXMESSAGE"},
	{"8", "GETDMABUFFERVU"},
	{"9", "MXDMESSAGE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_sb16snd_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_sb16snd_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_sb16snd(x,y) gperf_sb16snd_hash(x)
const unsigned int gperf_sb16snd_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_sb16snd = {
  .name = "sb16snd",
  .get = &gperf_sb16snd_get,
  .hash = &gperf_sb16snd_hash,
  .foreach = &gperf_sb16snd_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_sb16snd.get)("foo");
	printf ("%s\n", s);
}
#endif
