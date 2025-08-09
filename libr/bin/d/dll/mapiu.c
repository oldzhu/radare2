// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 mapiu.c ; ./a.out > mapiu.h
	{"1", "WEP"},
	{"109", "FINDCLOSE"},
	{"118", "GETSYSTEMTIME"},
	{"119", "GETFILESIZE"},
	{"131", "WRITEFILE"},
	{"137", "GETLASTERROR"},
	{"138", "HRALLOCADVISESINK"},
	{"147", "FINDFIRSTFILE"},
	{"148", "CREATEFILE"},
	{"163", "CLOSEHANDLE"},
	{"166", "_OPENTNEFSTREAM"},
	{"19", "SETFILEPOINTER"},
	{"2", "FBADREADPTR"},
	{"3", "___EXPORTEDSTUB"},
	{"31", "SYSTEMTIMETOFILETIME"},
	{"35", "CREATEDIRECTORY"},
	{"46", "FILETIMETOLOCALFILETIME"},
	{"56", "GETFULLPATHNAME"},
	{"57", "DELETEFILE"},
	{"59", "READFILE"},
	{"6", "_OPENSTREAMONFILE"},
	{"60", "FINDNEXTFILE"},
	{"68", "LOCALFILETIMETOFILETIME"},
	{"77", "FILETIMETODOSDATETIME"},
	{"83", "ULADDREF"},
	{"89", "SETTIMEZONEINFORMATION"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_mapiu_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_mapiu_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_mapiu(x,y) gperf_mapiu_hash(x)
const unsigned int gperf_mapiu_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_mapiu = {
  .name = "mapiu",
  .get = &gperf_mapiu_get,
  .hash = &gperf_mapiu_hash,
  .foreach = &gperf_mapiu_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_mapiu.get)("foo");
	printf ("%s\n", s);
}
#endif
