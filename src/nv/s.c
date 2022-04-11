
//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef _html_syntax_cpp
#define _html_syntax_cpp

#include "tagvalue.h"

#define	_HTML_COLOUR_MAX	0x0010
#define	_HTML_SHAPE_RECT		0x0000
#define	_HTML_SHAPE_CIRCLE		0x0001
#define	_HTML_SHAPE_POLY		0x0002
#define	_HTML_SHAPE_DEFAULT		0x0003
#define	_HTML_SHAPE_POLYGON		0x0004
#define	_HTML_SHAPE_RECTANGLE		0x0005

#define	_HTML_SHAPE_MAX			0x0006

#define	_HTML_INPUT_TEXT		0x0000
#define	_HTML_INPUT_PASSWORD		0x0001
#define	_HTML_INPUT_CHECKBOX		0x0002
#define	_HTML_INPUT_RADIO		0x0003
#define	_HTML_INPUT_SUBMIT		0x0004
#define	_HTML_INPUT_RESET		0x0005
#define	_HTML_INPUT_FILE		0x0006
#define	_HTML_INPUT_HIDDEN		0x0007
#define	_HTML_INPUT_IMAGE		0x0008
#define	_HTML_INPUT_SELECT		0x0009
#define	_HTML_INPUT_TEXTAREA		0x000A

#define	_HTML_INPUT_MAX			0x000B

#include "media.h"
#include "relation.h"

static const char * colours[ _HTML_COLOUR_MAX ] = {
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

static const char * shapekeyword[ _HTML_SHAPE_MAX ] = {
	(const char *) "RECT",
	(const char *) "CIRCLE",
	(const char *) "POLY",
	(const char *) "DEFAULT",
	(const char *) "POLYGON",
	(const char *) "RECTANGLE"
	};

static const char * inputkeyword[ _HTML_INPUT_MAX ] = {
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
	(const char *) "TEXTAREA"
	};

static const char * mediakeyword[ _HTML_MEDIA_MAX ] = {
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

static const char * relations[ _LINK_REL_MAX ] = {
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

#include "tagwords.h"



#endif // _html_syntax_cpp


