// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 typelib.c ; ./a.out > typelib.h
	{"1", "WEP"},
	{"10", "REGISTERTYPELIB"},
	{"11", "LOADREGTYPELIB"},
	{"12", "___EXPORTEDSTUB"},
	{"14", "QUERYPATHOFREGTYPELIB"},
	{"15", "OABUILDVERSION"},
	{"2", "CREATETYPELIB"},
	{"3", "LOADTYPELIB"},
	{"4", "LHASHVALOFNAMESYS"},
	{"5", "_IID_ICREATETYPEINFO"},
	{"6", "_IID_ICREATETYPELIB"},
	{"7", "_IID_ITYPECOMP"},
	{"8", "_IID_ITYPEINFO"},
	{"9", "_IID_ITYPELIB"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_typelib_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_typelib_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_typelib(x,y) gperf_typelib_hash(x)
const unsigned int gperf_typelib_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_typelib = {
  .name = "typelib",
  .get = &gperf_typelib_get,
  .hash = &gperf_typelib_hash,
  .foreach = &gperf_typelib_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_typelib.get)("foo");
	printf ("%s\n", s);
}
#endif
