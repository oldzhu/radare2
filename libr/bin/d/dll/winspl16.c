// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 winspl16.c ; ./a.out > winspl16.h
	{"1", "WEP"},
	{"13", "DEVICEMODE"},
	{"90", "EXTDEVICEMODE"},
	{"91", "DEVICECAPABILITIES"},
	{"93", "ADVANCEDSETUPDIALOG"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_winspl16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_winspl16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_winspl16(x,y) gperf_winspl16_hash(x)
const unsigned int gperf_winspl16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_winspl16 = {
  .name = "winspl16",
  .get = &gperf_winspl16_get,
  .hash = &gperf_winspl16_hash,
  .foreach = &gperf_winspl16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_winspl16.get)("foo");
	printf ("%s\n", s);
}
#endif
