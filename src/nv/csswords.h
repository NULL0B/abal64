//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_csswords_h
#define _html_csswords_h

#define _CSS_MAX		0x0017

#ifndef	_html_language_c

extern	"C"	{
	extern const char * csskeywords[ _CSS_MAX ];
	};

#else

const char * csskeywords[ _CSS_MAX ] = {
	(const char *)	"COLOR",
	(const char *)	"BACKGROUND",
	(const char *)	"BACKGROUND-COLOR",
	(const char *)	"HEIGHT",
	(const char *)	"WIDTH",
	(const char *)	"FONT-WEIGHT",
	(const char *)	"FONT-STYLE",
	(const char *)	"FONT-SIZE",
	(const char *)	"FONT-FAMILY",
	(const char *)	"MARGIN",
	(const char *)	"MARGIN-TOP",
	(const char *)	"MARGIN-LEFT",
	(const char *)	"MARGIN-RIGHT",
	(const char *)	"MARGIN-BOTTOM",
	(const char *)	"LIST-STYLE-TYPE",
	(const char *)	"EFT",
	(const char *)	"PADDING",
	(const char *)	"BORDER",
	(const char *)	"ALIGN",
	(const char *)	"TEXT-TRANSFORM",
	(const char *)	"TEXT-DECORATION",
	(const char *)	"TEXT-ALIGN",
	(const char *)	"VERTICAL-ALIGN"
	};
#endif

#endif	// _html_csswords_h


