/*      ---------------------------------       */
/*      Android Forms Production for SING       */
/*      ---------------------------------       */
/*      Copyright (c) 2015 Amenesik             */
/*      ---------------------------------       */
/*      Author    Iain James Marshall           */
/*      ---------------------------------       */
#ifndef	_androform_h
#define	_androform_h

#define	_MAX_WIDGETS		64
#define	_LINEAR_LAYOUT		0
#define	_RELATIVE_LAYOUT	1
#define	_ABSOLUTE_LAYOUT	2
#define	_SCROLL_LAYOUT		3
#define	_JAVA_IMPORT		"singAndroidJavaImport"
#define	_NDEF_EVENT		"singAndroidNdefEvent"
#define	_TECH_EVENT		"singAndroidTechEvent"
#define	_TAG_EVENT		"singAndroidTagEvent"
#define	_JAVA_MEMBER		"SINGANDROIDMEMBER:"
#define	_JAVA_ASYNC		"SINGANDROIDASYNC:"
#define	_JAVA_BEFORE		"SINGANDROIDBEFORE:"
#define	_JAVA_DURING		"SINGANDROIDDURING:"
#define	_JAVA_AFTER 		"SINGANDROIDAFTER:"
#define	_JAVA_SEARCH		"singAndroidSearch"
#define	_JAVA_FINDER   		"singAndroidFinder"
#define	_JAVA_CIPHER   		"singAndroidSQLCipher"
#define	_JAVA_SQLITE   		"singAndroidSQLite"
#define	_SING_CIPHER   		"singAutoCrypt"
#define	_JAVA_PARENT   		"singAndroidParent:"
#define	_JAVA_DOMAIN   		"singAndroidDomain:"
#define	_JAVA_VERSION  		"singAndroidVersion:"
#define	_JAVA_WAKELOCK 		"singAndroidWakeLock"
#define	_JAVA_RECORD   		"singAndroidRecordAudio"
#define	_JAVA_ORIENTATION	"singAndroidOrientation:"
#define	_JAVA_MAP		"singAndroidMap"
#define	_JAVA_VISUAL		"singAndroidVisualStyle"
#define	_JAVA_SCROLL		"singAndroidLayoutScroll"
#define	_JAVA_FIXED		"singAndroidLayoutFixed"
#define	_JAVA_RELATIVE		"singAndroidLayoutRelative"
#define	_JAVA_LINEAR		"singAndroidLayoutLinear"
#define	_JAVA_GPS		"singAndroidGps"
#define	_JAVA_API_KEY		"singAndroidApiKey:"

#define	AMENESIK_DOMAIN		"com.amenesik"

struct  android_import
{
        char *  name;
        struct  android_import * next;
};

struct  android_activity
{
        char *  name;
        struct  android_activity * next;
};

struct  android_options
{
	char *	apiKey;
	int	sqlcipher;
	int	inherit;
	int	version;
	int	handle_camera;
	int	handle_gps;
        int     handle_files;
        int     handle_layout;
        int     handle_network;
        int     handle_nfd;
	char *	domain;
	char *	style;
	char *	icon;
	char *	versionName;
	int	versionCode;
	int	visualStyle;
	int	widgets[_MAX_WIDGETS];
	char	master[4096];
};

private     FILE *  create_android_file(FILE * h,char * domain,struct form_control * fptr,char * path,char * name,char * suffix);
private	int	generate_android_license( FILE * h, char * domain );

#endif

