// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 wpsuni.c ; ./a.out > wpsuni.h
	{"1", "DEVBITBLT"},
	{"10", "REALIZEOBJECT"},
	{"11", "STRBLT"},
	{"12", "SCANLR"},
	{"13", "DEVICEMODE"},
	{"14", "JEXTTEXTOUT"},
	{"15", "DEVGETCHARWIDTH"},
	{"16", "DEVICEBITMAP"},
	{"17", "FASTBORDER"},
	{"18", "SETATTRIBUTE"},
	{"19", "DIALOGFN"},
	{"2", "COLORINFO"},
	{"20", "ABORTDLGPROC"},
	{"21", "DIBTODEVICE"},
	{"22", "WEP"},
	{"23", "LOWMEMDIALOG"},
	{"24", "NEWDRIVERDIALOG"},
	{"25", "ABOUTDIALOG"},
	{"26", "JSTATICCONTROLPROC"},
	{"27", "DEVSTRETCHBLT"},
	{"28", "STRETCHDIB"},
	{"29", "BASEOPTIONDIALOG"},
	{"3", "CONTROL"},
	{"30", "GRAPHICSDIALOG"},
	{"31", "BASEPAPERDIALOG"},
	{"32", "JBUTTONCONTROLPROC"},
	{"33", "NOPRINTERMEMDIALOG"},
	{"34", "RUNSETUPDIALOG"},
	{"35", "NOHOSTMEMDIALOG"},
	{"36", "LIBMAIN"},
	{"37", "___EXPORTEDSTUB"},
	{"38", "MISCDIALOG"},
	{"39", "DUPSRCDIALOG"},
	{"4", "DISABLE"},
	{"40", "ENDDEVMODE"},
	{"41", "FILTERFUNC"},
	{"5", "ENABLE"},
	{"6", "ENUMDFONTS"},
	{"7", "ENUMOBJ"},
	{"8", "OUTPUT"},
	{"9", "PIXEL"},
	{"90", "EXTDEVICEMODE"},
	{"91", "DEVICECAPABILITIES"},
	{"95", "EXTDEVICEMODEPROPSHEET"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_wpsuni_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_wpsuni_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_wpsuni(x,y) gperf_wpsuni_hash(x)
const unsigned int gperf_wpsuni_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_wpsuni = {
  .name = "wpsuni",
  .get = &gperf_wpsuni_get,
  .hash = &gperf_wpsuni_hash,
  .foreach = &gperf_wpsuni_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_wpsuni.get)("foo");
	printf ("%s\n", s);
}
#endif
