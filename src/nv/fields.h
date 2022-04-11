//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_field_words_h
#define _html_field_words_h

#ifdef	NVV2
#define	_FIELD_NAME_MAX		88	// Six more events added
#else
#define	_FIELD_NAME_MAX		82
#endif

#define	_FIELD_NAME_ALIGN	fieldnames[0]
#define	_FIELD_NAME_VALUE	fieldnames[1]
#define	_FIELD_NAME_SRC		fieldnames[2]
#define	_FIELD_NAME_HREF	fieldnames[3]
#define	_FIELD_NAME_WIDTH	fieldnames[4]
#define	_FIELD_NAME_HEIGHT	fieldnames[5]
#define	_FIELD_NAME_NAME	fieldnames[6]
#define	_FIELD_NAME_ALT		fieldnames[7]
#define	_FIELD_NAME_BORDER	fieldnames[8]
#define	_FIELD_NAME_HSPACE	fieldnames[9]

#define	_FIELD_NAME_VSPACE	fieldnames[10]
#define	_FIELD_NAME_USEMAP	fieldnames[11]
#define	_FIELD_NAME_ISMAP	fieldnames[12]
#define	_FIELD_NAME_VALIGN	fieldnames[13]
#define	_FIELD_NAME_BGCOLOR	fieldnames[14]
#define	_FIELD_NAME_CELLSPACING	fieldnames[15]
#define	_FIELD_NAME_CELLPADDING fieldnames[16]
#define	_FIELD_NAME_NOWRAP	fieldnames[17]
#define	_FIELD_NAME_ROWSPAN	fieldnames[18]
#define	_FIELD_NAME_COLSPAN	fieldnames[19]

#define	_FIELD_NAME_TEXT	fieldnames[20]
#define	_FIELD_NAME_SIZE	fieldnames[21]
#define	_FIELD_NAME_NOSHADE	fieldnames[22]
#define	_FIELD_NAME_MAXLENGTH	fieldnames[23]
#define	_FIELD_NAME_CHECKED	fieldnames[24]
#define	_FIELD_NAME_ACCEPT	fieldnames[25]
#define	_FIELD_NAME_TYPE	fieldnames[26]
#define	_FIELD_NAME_DATESTAMP	fieldnames[27]
#define	_FIELD_NAME_BACKGROUND	fieldnames[28]
#define	_FIELD_NAME_LINK	fieldnames[29]

#define	_FIELD_NAME_VLINK	fieldnames[30]
#define	_FIELD_NAME_ALINK	fieldnames[31]
#define	_FIELD_NAME_FACE	fieldnames[32]
#define	_FIELD_NAME_COLOR	fieldnames[33]
#define	_FIELD_NAME_DATA	fieldnames[34]
#define	_FIELD_NAME_CLASSID	fieldnames[35]
#define	_FIELD_NAME_CODEBASE	fieldnames[36]
#define	_FIELD_NAME_CODETYPE	fieldnames[37]
#define	_FIELD_NAME_ARCHIVE	fieldnames[38]
#define	_FIELD_NAME_STANDBY	fieldnames[39]

#define	_FIELD_NAME_DECLARE	fieldnames[40]
#define	_FIELD_NAME_SELECTED	fieldnames[41]
#define	_FIELD_NAME_CODE	fieldnames[42]
#define	_FIELD_NAME_CLASS	fieldnames[43]
#define	_FIELD_NAME_STYLE	fieldnames[44]
#define	_FIELD_NAME_DIR		fieldnames[45]
#define	_FIELD_NAME_LANG	fieldnames[46]
#define	_FIELD_NAME_ID		fieldnames[47]
#define	_FIELD_NAME_TITLE	fieldnames[48]
#define	_FIELD_NAME_LANGUAGE	fieldnames[49]

#define	_FIELD_NAME_DEFER	fieldnames[50]
#define	_FIELD_NAME_CITE	fieldnames[51]
#define	_FIELD_NAME_DATETIME	fieldnames[52]
#define	_FIELD_NAME_SHAPE	fieldnames[53]
#define	_FIELD_NAME_COORDS	fieldnames[54]
#define	_FIELD_NAME_NOHREF	fieldnames[55]
#define	_FIELD_NAME_SPAN	fieldnames[56]
#define	_FIELD_NAME_ACTION	fieldnames[57]
#define	_FIELD_NAME_METHOD	fieldnames[58]
#define	_FIELD_NAME_ENCTYPE	fieldnames[59]

#define	_FIELD_NAME_ROWS		fieldnames[60]
#define	_FIELD_NAME_COLS		fieldnames[61]
#define	_FIELD_NAME_FRAMEBORDER 	fieldnames[62]
#define	_FIELD_NAME_FRAMESPACING	fieldnames[63]
#define	_FIELD_NAME_NORESIZE		fieldnames[64]
#define	_FIELD_NAME_MEDIA		fieldnames[65]
#define	_FIELD_NAME_REV			fieldnames[66]
#define	_FIELD_NAME_REL			fieldnames[67]
#define	_FIELD_NAME_HREFLANG		fieldnames[68]
#define	_FIELD_NAME_TARGET		fieldnames[69]

#define	_FIELD_NAME_CHARSET		fieldnames[70]
#define	_FIELD_NAME_START		fieldnames[71]
#define	_FIELD_NAME_COMPACT		fieldnames[72]
#define	_FIELD_NAME_MULTIPLE		fieldnames[73]
#define	_FIELD_NAME_MARGIN		fieldnames[74]
#define	_FIELD_NAME_MARGINWIDTH		fieldnames[75]
#define	_FIELD_NAME_SCROLLING		fieldnames[76]

#define	_FIELD_NAME_CONTENT		fieldnames[77]
#define	_FIELD_NAME_SCHEME		fieldnames[78]
#define	_FIELD_NAME_HTTP_EQUIV		fieldnames[79]
#define	_FIELD_NAME_DISABLED  		fieldnames[80]
#define	_FIELD_NAME_READONLY  		fieldnames[81]

#ifdef	NVV2
#define	_FIELD_NAME_ONFOCUS		fieldnames[82]
#define	_FIELD_NAME_ONBLUR		fieldnames[83]
#define	_FIELD_NAME_ONSELECT		fieldnames[84]
#define	_FIELD_NAME_ONCHANGE		fieldnames[85]
#define	_FIELD_NAME_ONCLICK 		fieldnames[86]
#define	_FIELD_NAME_ONMOUSEOVER		fieldnames[87]
#endif

#ifndef	_html_language_c

extern	"C"	{
	extern	char * fieldnames[ _FIELD_NAME_MAX ];
	}
#else

char * fieldnames[ _FIELD_NAME_MAX ] = {
	(char *) "ALIGN",
	(char *) "VALUE",
	(char *) "SRC",
	(char *) "HREF",
	(char *) "WIDTH",
	(char *) "HEIGHT",
	(char *) "NAME",
	(char *) "ALT",
	(char *) "BORDER",
	(char *) "HSPACE",
	(char *) "VSPACE",
	(char *) "USEMAP",
	(char *) "ISMAP",
	(char *) "VALIGN",
	(char *) "BGCOLOR",
	(char *) "CELLSPACING",
	(char *) "CELLPADDING",
	(char *) "NOWRAP",
	(char *) "ROWSPAN",
	(char *) "COLSPAN",
	(char *) "TEXT",
	(char *) "SIZE",
	(char *) "NOSHADE",
	(char *) "MAXLENGTH",
	(char *) "CHECKED",
	(char *) "ACCEPT",
	(char *) "TYPE",

	(char *) "DATESTAMP",
	(char *) "BACKGROUND",
	(char *) "LINK",
	(char *) "VLINK",
	(char *) "ALINK",
	(char *) "FACE",
	(char *) "COLOR",

	(char *) "DATA",
	(char *) "CLASSID",
	(char *) "CODEBASE",
	(char *) "CODETYPE",
	(char *) "ARCHIVE",
	(char *) "STANDBY",
	(char *) "DECLARE",
	(char *) "SELECTED",

	(char *) "CODE",

	(char *) "CLASS",
	(char *) "STYLE",
	(char *) "DIR",
	(char *) "LANG",
	(char *) "ID",
	(char *) "TITLE",

	(char *) "LANGUAGE",
	(char *) "DEFER",

	(char *) "CITE",
	(char *) "DATETIME",

	(char *) "SHAPE",
	(char *) "COORDS",
	(char *) "NOHREF",
	(char *) "SPAN",

	(char *) "ACTION",
	(char *) "METHOD",
	(char *) "ENCTYPE",

	(char *) "ROWS",
	(char *) "COLS",
	(char *) "FRAMEBORDER",
	(char *) "FRAMESPACING",
	(char *) "NORESIZE",
	(char *) "MEDIA",
	(char *) "REV",
	(char *) "REL",

	(char *) "HREFLANG",
	(char *) "TARGET",
	(char *) "CHARSET",
	(char *) "START",
	(char *) "COMPACT",
	(char *) "MULTIPLE",

	(char *) "MARGIN",
	(char *) "MARGINWIDTH",
	(char *) "SCROLLING",

	(char *) "CONTENT",
	(char *) "SCHEME",
	(char *) "HTTP-EQUIV",
	(char *) "DISABLED",
	(char *) "READONLY"
#ifdef	NVV2
	, 
	(char *) "ONFOCUS",
	(char *) "ONBLUR",
	(char *) "ONSELECT",
	(char *) "ONCHANGE",
	(char *) "ONCLICK",
	(char *) "ONMOUSEOVER"
#endif
	
	};


#endif


#endif	// _html_field_words_h


