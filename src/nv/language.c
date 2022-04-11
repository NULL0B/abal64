//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_language_c
#define _html_language_c

#include "tokenmax.h"

#include "macros.h"
#include "tagwords.h"
#include "csswords.h"
#include "mimeword.h"
#include "fields.h"
#define	_HTML_SERVICE_MAX 	12

const char * colours[ _HTML_COLOUR_MAX ] = {
	(const char *) "BLACK",
	(const char *) "RED",
	(const char *) "GREEN",
	(const char *) "BROWN",
	(const char *) "NAVY",
	(const char *) "PURPLE",
	(const char *) "CYAN",
	(const char *) "SILVER",
	(const char *) "GREY",
	(const char *) "PINK",
	(const char *) "LIME",
	(const char *) "YELLOW",
	(const char *) "BLUE",
	(const char *) "MAGENTA",
	(const char *) "SKY",
	(const char *) "WHITE"
	};

const char * shapekeyword[ _HTML_SHAPE_MAX ] = {
	(const char *) "RECT",
	(const char *) "CIRCLE",
	(const char *) "POLY",
	(const char *) "DEFAULT",
	(const char *) "POLYGON",
	(const char *) "RECTANGLE"
	};

const char * inputkeyword[ _HTML_INPUT_MAX ] = {
	(const char *) "TEXT",
	(const char *) "PASSWORD",
	(const char *) "CHECKBOX",
	(const char *) "RADIO",
	(const char *) "SUBMIT",
	(const char *) "RESET",
	(const char *) "FILE",
	(const char *) "HIDDEN",
	(const char *) "IMAGE",
	(const char *) "SELECT",
	(const char *) "TEXTAREA",
	(const char *) "BUTTON"
	};

const char * mediakeyword[ _HTML_MEDIA_MAX ] = {
	(const char *)	"ALL",
	(const char *)	"SCREEN",
	(const char *)	"TTY",
	(const char *)	"TV",
	(const char *)	"PROJECTION",
	(const char *)	"HANDHELD",
	(const char *)	"PRINT",
	(const char *)	"BRAILLE",
	(const char *)	"AURAL"
	};

const char * relations[ _LINK_REL_MAX ] = {
	(const char *)	"NEXT",
	(const char *)	"PREVIOUS",	
	(const char *)	"CONTENTS",	
	(const char *)	"STYLESHEET",	
	(const char *)	"ALTERNATE",
	(const char *)	"START",
	(const char *)	"INDEX",
	(const char *)	"GLOSSARY",
	(const char *)	"COPYRIGHT",
	(const char *)	"CHAPTER",
	(const char *)	"SECTION",
	(const char *)	"SUBSECTION",
	(const char *)	"APPENDIX",
	(const char *)	"HELP",
	(const char *)	"BOOKMARK",
	(const char *)	"PREV",
	(const char *)	"ALT"
	};


const char * servicekeyword[ _HTML_SERVICE_MAX ] = {
	(const char *) /* _HTTP_SERVICE	     */	"http:",
	(const char *) /* _FILE_SERVICE	     */	"file:",
	(const char *) /* _CONFIGURE_SERVICE */	"configure:",
	(const char *) /* _PRINT_SERVICE     */	"print:",
	(const char *) /* _FTP_SERVICE	     */	"ftp:",
	(const char *) /* _HTTPS_SERVICE     */	"https",
	(const char *) /* _FETCH_SERVICE     */	"fetch:",
	(const char *) /* _CACHE_SERVICE     */	"cache:",
	(const char *) /* _MAILTO_SERVICE    */	"mailto:",
	(const char *) /* _MAILSEND_SERVICE  */	"sendmail:",
	(const char *) /* _JAVASCRIPT_SERVICE*/ "javascript:",
	(const char *) /* _BOOKMARK_SERVICE  */ "bookmark:"
	};


#endif	// _html_language_c


