// SDB-CGEN V2.1.0
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct kv { const char *name; const char *value; };
static const struct kv kvs[] = {
// gcc -DMAIN=1 msvideo.c ; ./a.out > msvideo.h
	{"1", "WEP"},
	{"102", "DRAWDIBOPEN"},
	{"103", "DRAWDIBCLOSE"},
	{"104", "DRAWDIBBEGIN"},
	{"105", "DRAWDIBEND"},
	{"106", "DRAWDIBDRAW"},
	{"108", "DRAWDIBGETPALETTE"},
	{"110", "DRAWDIBSETPALETTE"},
	{"111", "DRAWDIBCHANGEPALETTE"},
	{"112", "DRAWDIBREALIZE"},
	{"113", "DRAWDIBTIME"},
	{"114", "DRAWDIBPROFILEDISPLAY"},
	{"115", "STRETCHDIB"},
	{"118", "DRAWDIBSTART"},
	{"119", "DRAWDIBSTOP"},
	{"120", "DRAWDIBGETBUFFER"},
	{"2", "VIDEOFORWINDOWSVERSION"},
	{"20", "VIDEOGETNUMDEVS"},
	{"200", "ICINFO"},
	{"201", "ICINSTALL"},
	{"202", "ICREMOVE"},
	{"203", "ICOPEN"},
	{"204", "ICCLOSE"},
	{"205", "ICSENDMESSAGE"},
	{"206", "ICOPENFUNCTION"},
	{"207", "_ICMESSAGE"},
	{"21", "VIDEOGETERRORTEXT"},
	{"212", "ICGETINFO"},
	{"213", "ICLOCATE"},
	{"22", "VIDEOCAPDRIVERDESCANDVER"},
	{"224", "_ICCOMPRESS"},
	{"230", "_ICDECOMPRESS"},
	{"232", "_ICDRAWBEGIN"},
	{"234", "_ICDRAW"},
	{"239", "ICGETDISPLAYFORMAT"},
	{"240", "ICIMAGECOMPRESS"},
	{"241", "ICIMAGEDECOMPRESS"},
	{"242", "ICCOMPRESSORCHOOSE"},
	{"243", "ICCOMPRESSORFREE"},
	{"244", "ICSEQCOMPRESSFRAMESTART"},
	{"245", "ICSEQCOMPRESSFRAMEEND"},
	{"246", "ICSEQCOMPRESSFRAME"},
	{"250", "_MCIWNDCREATE"},
	{"251", "_MCIWNDREGISTERCLASS"},
	{"252", "GETOPENFILENAMEPREVIEW"},
	{"253", "GETSAVEFILENAMEPREVIEW"},
	{"28", "VIDEOOPEN"},
	{"29", "VIDEOCLOSE"},
	{"3", "DLLENTRYPOINT"},
	{"30", "VIDEODIALOG"},
	{"31", "VIDEOFRAME"},
	{"32", "VIDEOCONFIGURE"},
	{"33", "VIDEOCONFIGURESTORAGE"},
	{"34", "VIDEOGETCHANNELCAPS"},
	{"35", "VIDEOUPDATE"},
	{"4", "SL_THUNKDATA16"},
	{"40", "VIDEOSTREAMADDBUFFER"},
	{"41", "VIDEOSTREAMFINI"},
	{"42", "VIDEOSTREAMGETERROR"},
	{"43", "VIDEOSTREAMGETPOSITION"},
	{"44", "VIDEOSTREAMINIT"},
	{"46", "VIDEOSTREAMPREPAREHEADER"},
	{"47", "VIDEOSTREAMRESET"},
	{"49", "VIDEOSTREAMSTART"},
	{"5", "LS_THUNKDATA16"},
	{"50", "VIDEOSTREAMSTOP"},
	{"51", "VIDEOSTREAMUNPREPAREHEADER"},
	{"52", "VIDEOSTREAMALLOCHDRANDBUFFER"},
	{"53", "VIDEOSTREAMFREEHDRANDBUFFER"},
	{"60", "VIDEOMESSAGE"},
  {NULL, NULL}
};
typedef int (*GperfForeachCallback)(void *user, const char *k, const char *v);
int gperf_msvideo_foreach(GperfForeachCallback cb, void *user) {
  int i = 0; while (kvs[i].name) {
  cb (user, kvs[i].name, kvs[i].value);
  i++;}
  return 0;
}
const char *gperf_msvideo_get(const char *s) {
  int i = 0; while (kvs[i].name) {
  if (!strcmp (s, kvs[i].name)) return kvs[i].value;
  i++;}
  return NULL;
}
#define sdb_hash_c_msvideo(x,y) gperf_msvideo_hash(x)
const unsigned int gperf_msvideo_hash(const char *s) {
  int sum = strlen (s);
  while (*s) { sum += *s; s++; }
  return sum;
}
struct {const char *name;void *get;void *hash;void *foreach;} gperf_msvideo = {
  .name = "msvideo",
  .get = &gperf_msvideo_get,
  .hash = &gperf_msvideo_hash,
  .foreach = &gperf_msvideo_foreach
};

#if MAIN
int main () {
	const char *s = ((char*(*)(char*))gperf_msvideo.get)("foo");
	printf ("%s\n", s);
}
#endif
