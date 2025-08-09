// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 lzexpand.c ; ./a.out > lzexpand.h
	{"1", "LZCOPY"},
	{"10", "GETEXPANDEDNAME"},
	{"11", "WEP"},
	{"12", "___EXPORTEDSTUB"},
	{"2", "LZOPENFILE"},
	{"3", "LZINIT"},
	{"4", "LZSEEK"},
	{"5", "LZREAD"},
	{"6", "LZCLOSE"},
	{"7", "LZSTART"},
	{"8", "COPYLZFILE"},
	{"9", "LZDONE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_lzexpand_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_lzexpand_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_lzexpand(x,y) gperf_lzexpand_hash(x)
const unsigned int gperf_lzexpand_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_lzexpand = {
  .name = "lzexpand",
  .get = &gperf_lzexpand_get,
  .hash = &gperf_lzexpand_hash,
  .foreach = &gperf_lzexpand_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_lzexpand.get)("foo");
	printf ("%s\n", s);
}
#endif
