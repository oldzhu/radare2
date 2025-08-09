// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 avicap.c ; ./a.out > avicap.h
	{"1", "WEP"},
	{"2", "CAPCREATECAPTUREWINDOW"},
	{"3", "CAPGETDRIVERDESCRIPTION"},
	{"4", "DLLENTRYPOINT"},
	{"5", "AVICAPF_THUNKDATA16"},
	{"6", "___EXPORTEDSTUB"},
	{"7", "CAPWNDPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_avicap_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_avicap_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_avicap(x,y) gperf_avicap_hash(x)
const unsigned int gperf_avicap_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_avicap = {
  .name = "avicap",
  .get = &gperf_avicap_get,
  .hash = &gperf_avicap_hash,
  .foreach = &gperf_avicap_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_avicap.get)("foo");
	printf ("%s\n", s);
}
#endif
