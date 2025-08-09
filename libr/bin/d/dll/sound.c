// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 sound.c ; ./a.out > sound.h
	{"1", "OPENSOUND"},
	{"10", "STOPSOUND"},
	{"11", "WAITSOUNDSTATE"},
	{"12", "SYNCALLVOICES"},
	{"13", "COUNTVOICENOTES"},
	{"14", "GETTHRESHOLDEVENT"},
	{"15", "GETTHRESHOLDSTATUS"},
	{"16", "SETVOICETHRESHOLD"},
	{"17", "DOBEEP"},
	{"18", "WEP"},
	{"2", "CLOSESOUND"},
	{"3", "SETVOICEQUEUESIZE"},
	{"4", "SETVOICENOTE"},
	{"5", "SETVOICEACCENT"},
	{"6", "SETVOICEENVELOPE"},
	{"7", "SETSOUNDNOISE"},
	{"8", "SETVOICESOUND"},
	{"9", "STARTSOUND"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_sound_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_sound_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_sound(x,y) gperf_sound_hash(x)
const unsigned int gperf_sound_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_sound = {
  .name = "sound",
  .get = &gperf_sound_get,
  .hash = &gperf_sound_hash,
  .foreach = &gperf_sound_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_sound.get)("foo");
	printf ("%s\n", s);
}
#endif
