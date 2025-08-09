// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 comm.c ; ./a.out > comm.h
	{"1", "INICOM"},
	{"10", "CFLUSH"},
	{"100", "ENABLENOTIFICATION"},
	{"11", "CEVT"},
	{"12", "CEVTGET"},
	{"13", "CSETBRK"},
	{"14", "CCLRBRK"},
	{"15", "GETDCB"},
	{"16", "WEP"},
	{"19", "COMMWRITESTRING"},
	{"2", "SETCOM"},
	{"20", "READCOMMSTRING"},
	{"3", "SETQUE"},
	{"4", "RECCOM"},
	{"5", "SNDCOM"},
	{"6", "CTX"},
	{"7", "TRMCOM"},
	{"8", "STACOM"},
	{"9", "CEXTFCN"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_comm_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_comm_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_comm(x,y) gperf_comm_hash(x)
const unsigned int gperf_comm_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_comm = {
  .name = "comm",
  .get = &gperf_comm_get,
  .hash = &gperf_comm_hash,
  .foreach = &gperf_comm_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_comm.get)("foo");
	printf ("%s\n", s);
}
#endif
