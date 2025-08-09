// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mouse.c ; ./a.out > mouse.h
	{"1", "INQUIRE"},
	{"10", "MOUSEREDETECT"},
	{"2", "ENABLE"},
	{"3", "DISABLE"},
	{"4", "MOUSEGETINTVECT"},
	{"5", "GETSETMOUSEDATA"},
	{"6", "CPLAPPLET"},
	{"7", "POWEREVENTPROC"},
	{"8", "EXTRAPOINTS"},
	{"9", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mouse_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mouse_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mouse(x,y) gperf_mouse_hash(x)
const unsigned int gperf_mouse_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mouse = {
  .name = "mouse",
  .get = &gperf_mouse_get,
  .hash = &gperf_mouse_hash,
  .foreach = &gperf_mouse_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mouse.get)("foo");
	printf ("%s\n", s);
}
#endif
