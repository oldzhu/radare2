// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 awdevl16.c ; ./a.out > awdevl16.h
	{"1", "DLLENTRYPOINT"},
	{"10", "ATWKFAX_OPEN"},
	{"11", "ATWKFAX_STARTDOC"},
	{"12", "ATWKFAX_SETCOPYCOUNT"},
	{"13", "ATWKFAX_STARTPAGE"},
	{"14", "ATWKFAX_WRITEDATA"},
	{"15", "ATWKFAX_ENDPAGE"},
	{"16", "ATWKFAX_ENDDOC"},
	{"17", "ATWKFAX_CLOSE"},
	{"18", "ATWKFAX_ABORT"},
	{"19", "ATWKFAX_EXTDEVICEMODE"},
	{"2", "THUNKS_THUNKDATA16"},
	{"20", "ATWKFAX_RESETDEVICE"},
	{"3", "HIDDENDLGPROC"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_awdevl16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_awdevl16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_awdevl16(x,y) gperf_awdevl16_hash(x)
const unsigned int gperf_awdevl16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_awdevl16 = {
  .name = "awdevl16",
  .get = &gperf_awdevl16_get,
  .hash = &gperf_awdevl16_hash,
  .foreach = &gperf_awdevl16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_awdevl16.get)("foo");
	printf ("%s\n", s);
}
#endif
