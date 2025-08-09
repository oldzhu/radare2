// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 dciman.c ; ./a.out > dciman.h
	{"1", "DCIOPENPROVIDER"},
	{"10", "WINWATCHOPEN"},
	{"11", "WINWATCHCLOSE"},
	{"12", "WINWATCHDIDSTATUSCHANGE"},
	{"13", "WINWATCHNOTIFY"},
	{"14", "WINWATCHGETCLIPLIST"},
	{"15", "DLLENTRYPOINT"},
	{"16", "DCITHK_THUNKDATA16"},
	{"2", "DCICLOSEPROVIDER"},
	{"20", "GETWINDOWREGIONDATA"},
	{"21", "GETDCREGIONDATA"},
	{"3", "DCICREATEPRIMARY"},
	{"30", "DCIDESTROY"},
	{"31", "DCIENDACCESS"},
	{"32", "DCIBEGINACCESS"},
	{"33", "DCIDRAW"},
	{"34", "DCISETCLIPLIST"},
	{"35", "DCISETDESTINATION"},
	{"4", "DCICREATEOFFSCREEN"},
	{"40", "DCICREATEPRIMARY32"},
	{"5", "DCICREATEOVERLAY"},
	{"6", "DCIENUM"},
	{"7", "DCISENDCOMMAND"},
	{"8", "DCISETSRCDESTCLIP"},
	{"9", "WEP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_dciman_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_dciman_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_dciman(x,y) gperf_dciman_hash(x)
const unsigned int gperf_dciman_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_dciman = {
  .name = "dciman",
  .get = &gperf_dciman_get,
  .hash = &gperf_dciman_hash,
  .foreach = &gperf_dciman_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_dciman.get)("foo");
	printf ("%s\n", s);
}
#endif
