// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 storage.c ; ./a.out > storage.h
	{"1", "STGCREATEDOCFILE"},
	{"103", "DLLGETCLASSOBJECT"},
	{"2", "STGCREATEDOCFILEONILOCKBYTES"},
	{"3", "STGOPENSTORAGE"},
	{"4", "STGOPENSTORAGEONILOCKBYTES"},
	{"5", "STGISSTORAGEFILE"},
	{"6", "STGISSTORAGEILOCKBYTES"},
	{"7", "STGSETTIMES"},
	{"8", "WEP"},
	{"9", "___EXPORTEDSTUB"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_storage_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_storage_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_storage(x,y) gperf_storage_hash(x)
const unsigned int gperf_storage_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_storage = {
  .name = "storage",
  .get = &gperf_storage_get,
  .hash = &gperf_storage_hash,
  .foreach = &gperf_storage_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_storage.get)("foo");
	printf ("%s\n", s);
}
#endif
