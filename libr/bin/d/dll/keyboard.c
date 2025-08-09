// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 keyboard.c ; ./a.out > keyboard.h
	{"1", "INQUIRE"},
	{"10", "TOASCIIEX"},
	{"100", "SCREENSWITCHENABLE"},
	{"11", "VKKEYSCANEX"},
	{"12", "MAPVIRTUALKEYEX"},
	{"126", "GETTABLESEG"},
	{"127", "NEWTABLE"},
	{"128", "OEMKEYSCAN"},
	{"129", "VKKEYSCAN"},
	{"13", "NEWTABLEEX"},
	{"130", "GETKEYBOARDTYPE"},
	{"131", "MAPVIRTUALKEY"},
	{"132", "GETKBCODEPAGE"},
	{"133", "GETKEYNAMETEXT"},
	{"134", "ANSITOOEMBUFF"},
	{"135", "OEMTOANSIBUFF"},
	{"136", "ENABLEKBSYSREQ"},
	{"137", "GETBIOSKEYPROC"},
	{"14", "___EXPORTEDSTUB"},
	{"2", "ENABLE"},
	{"3", "DISABLE"},
	{"4", "TOASCII"},
	{"5", "ANSITOOEM"},
	{"6", "OEMTOANSI"},
	{"7", "SETSPEED"},
	{"8", "WEP"},
	{"9", "INQUIREEX"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_keyboard_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_keyboard_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_keyboard(x,y) gperf_keyboard_hash(x)
const unsigned int gperf_keyboard_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_keyboard = {
  .name = "keyboard",
  .get = &gperf_keyboard_get,
  .hash = &gperf_keyboard_hash,
  .foreach = &gperf_keyboard_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_keyboard.get)("foo");
	printf ("%s\n", s);
}
#endif
