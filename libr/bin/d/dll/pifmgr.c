// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 pifmgr.c ; ./a.out > pifmgr.h
	{"1", "WEP"},
	{"10", "LOADPROPERTYLIB"},
	{"11", "ENUMPROPERTYLIBS"},
	{"12", "FREEPROPERTYLIB"},
	{"13", "ADDPROPERTYSHEET"},
	{"14", "REMOVEPROPERTYSHEET"},
	{"15", "LOADPROPERTYSHEETS"},
	{"16", "ENUMPROPERTYSHEETS"},
	{"17", "FREEPROPERTYSHEETS"},
	{"18", "PIFPROPGETPAGES"},
	{"19", "DLLCANUNLOADNOW"},
	{"2", "OPENPROPERTIES"},
	{"20", "CREATESTARTUPPROPERTIES"},
	{"21", "DELETESTARTUPPROPERTIES"},
	{"22", "INITPIFREGENTRIES"},
	{"23", "PROCESSSTARTUPPROPERTIES"},
	{"3", "GETPROPERTIES"},
	{"4", "SETPROPERTIES"},
	{"5", "EDITPROPERTIES"},
	{"6", "FLUSHPROPERTIES"},
	{"7", "ENUMPROPERTIES"},
	{"8", "ASSOCIATEPROPERTIES"},
	{"9", "CLOSEPROPERTIES"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_pifmgr_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_pifmgr_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_pifmgr(x,y) gperf_pifmgr_hash(x)
const unsigned int gperf_pifmgr_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_pifmgr = {
  .name = "pifmgr",
  .get = &gperf_pifmgr_get,
  .hash = &gperf_pifmgr_hash,
  .foreach = &gperf_pifmgr_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_pifmgr.get)("foo");
	printf ("%s\n", s);
}
#endif
