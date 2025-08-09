// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 umdm16.c ; ./a.out > umdm16.h
	{"1", "WEP"},
	{"100", "DLLENTRYPOINT"},
	{"101", "UMDMTHK_THUNKDATA16"},
	{"2", "OPENMODEM"},
	{"3", "DUPLICATEMODEMHANDLE"},
	{"4", "CLOSEMODEM"},
	{"5", "GETSETMODEMCONFIG"},
	{"6", "COMMCONFIGDIALOG"},
	{"7", "GETDEFAULTCOMMCONFIG"},
	{"8", "SETDEFAULTCOMMCONFIG"},
	{"9", "LAUNCHMODEMLIGHT"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_umdm16_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_umdm16_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_umdm16(x,y) gperf_umdm16_hash(x)
const unsigned int gperf_umdm16_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_umdm16 = {
  .name = "umdm16",
  .get = &gperf_umdm16_get,
  .hash = &gperf_umdm16_hash,
  .foreach = &gperf_umdm16_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_umdm16.get)("foo");
	printf ("%s\n", s);
}
#endif
