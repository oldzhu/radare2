// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 modemui.c ; ./a.out > modemui.h
	{"1", "WEP"},
	{"10", "MDM_COMMCONFIGDIALOG"},
	{"12", "ENUMPROPPAGES"},
	{"20", "DRVCOMMCONFIGDIALOG"},
	{"21", "DRVSETDEFAULTCOMMCONFIG"},
	{"22", "DRVGETDEFAULTCOMMCONFIG"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_modemui_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_modemui_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_modemui(x,y) gperf_modemui_hash(x)
const unsigned int gperf_modemui_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_modemui = {
  .name = "modemui",
  .get = &gperf_modemui_get,
  .hash = &gperf_modemui_hash,
  .foreach = &gperf_modemui_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_modemui.get)("foo");
	printf ("%s\n", s);
}
#endif
