// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 whlp16t.c ; ./a.out > whlp16t.h
	{"1", "THK_THUNKDATA16"},
	{"10", "MAKEINFORMCALL"},
	{"11", "THUNKEMBEDCREATE"},
	{"12", "GETMODULEFILENAME16"},
	{"2", "DLLENTRYPOINT"},
	{"3", "THKR_THUNKDATA16"},
	{"4", "WEP"},
	{"5", "IMTDISPATCHPROC"},
	{"8", "MAKECALLDATA"},
	{"9", "MAKECALLSTR"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_whlp16t_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_whlp16t_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_whlp16t(x,y) gperf_whlp16t_hash(x)
const unsigned int gperf_whlp16t_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_whlp16t = {
  .name = "whlp16t",
  .get = &gperf_whlp16t_get,
  .hash = &gperf_whlp16t_hash,
  .foreach = &gperf_whlp16t_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_whlp16t.get)("foo");
	printf ("%s\n", s);
}
#endif
