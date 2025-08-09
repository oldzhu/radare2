// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 commdlg.c ; ./a.out > commdlg.h
	{"1", "GETOPENFILENAME"},
	{"11", "FINDTEXT"},
	{"12", "REPLACETEXT"},
	{"15", "CHOOSEFONT"},
	{"16", "FORMATCHARDLGPROC"},
	{"2", "GETSAVEFILENAME"},
	{"20", "PRINTDLG"},
	{"26", "COMMDLGEXTENDEDERROR"},
	{"27", "GETFILETITLE"},
	{"28", "WEP"},
	{"40", "DLGTHKCONNECTIONDATALS"},
	{"5", "CHOOSECOLOR"},
	{"9", "LOADALTERBITMAP"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_commdlg_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_commdlg_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_commdlg(x,y) gperf_commdlg_hash(x)
const unsigned int gperf_commdlg_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_commdlg = {
  .name = "commdlg",
  .get = &gperf_commdlg_get,
  .hash = &gperf_commdlg_hash,
  .foreach = &gperf_commdlg_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_commdlg.get)("foo");
	printf ("%s\n", s);
}
#endif
