// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 ver.c ; ./a.out > ver.h
	{"1", "DLLENTRYPOINT"},
	{"10", "VERLANGUAGENAME"},
	{"11", "VERQUERYVALUE"},
	{"2", "GETFILERESOURCESIZE"},
	{"20", "GETFILEVERSIONINFORAW"},
	{"21", "VERFTHK_THUNKDATA16"},
	{"22", "VERTHKSL_THUNKDATA16"},
	{"3", "GETFILERESOURCE"},
	{"6", "GETFILEVERSIONINFOSIZE"},
	{"7", "GETFILEVERSIONINFO"},
	{"8", "VERFINDFILE"},
	{"9", "VERINSTALLFILE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_ver_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_ver_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_ver(x,y) gperf_ver_hash(x)
const unsigned int gperf_ver_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_ver = {
  .name = "ver",
  .get = &gperf_ver_get,
  .hash = &gperf_ver_hash,
  .foreach = &gperf_ver_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_ver.get)("foo");
	printf ("%s\n", s);
}
#endif
