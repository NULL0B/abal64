//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_macros_h
#define	_html_macros_h

#define	_HTML_MACRO_MAX		96

#ifndef	_html_language_c

extern	"C"	{
	extern 	char * macrotoken[ _HTML_MACRO_MAX ];
	};

#else

char * macrotoken[ _HTML_MACRO_MAX ] = {
	(char *)	"nbsp",	
	(char *)	"iexcl",
	(char *)	"cent",
	(char *)	"pound",
	(char *)	"curren",
	(char *)	"yen",
	(char *)	"brvbar",
	(char *)	"sect",
	(char *)	"uml",
	(char *)	"copy",
	(char *)	"ordf",
	(char *)	"laquo",
	(char *)	"not",
	(char *)	"shy",
	(char *)	"reg",
	(char *)	"macr",
	(char *)	"deg",
	(char *)	"plusmn",
	(char *)	"sup2",
	(char *)	"sup3",
	(char *)	"acute",
	(char *)	"micro",
	(char *)	"para",
	(char *)	"middot",
	(char *)	"cedil",
	(char *)	"sup1",
	(char *)	"ordm",
	(char *)	"raquo",
	(char *)	"frac14",
	(char *)	"frac12",
	(char *)	"frac34",
	(char *)	"iquest",
	(char *)	"Agrave",
	(char *)	"Aacute",
	(char *)	"Acirc",
	(char *)	"Atilde",
	(char *)	"Auml",
	(char *)	"Aring",
	(char *)	"AElig",
	(char *)	"Ccedil",
	(char *)	"Egrave",
	(char *)	"Eacute",
	(char *)	"Ecirc",
	(char *)	"Euml",
	(char *)	"Igrave",
	(char *)	"Iacute",
	(char *)	"Icirc",
	(char *)	"Iuml",
	(char *)	"ETH",
	(char *)	"Ntilde",
	(char *)	"Ograve",
	(char *)	"Oacute",
	(char *)	"Ocirc",
	(char *)	"Otilde",
	(char *)	"Ouml",
	(char *)	"times",
	(char *)	"Oslash",
	(char *)	"Ugrave",
	(char *)	"Uacute",
	(char *)	"Ucirc",
	(char *)	"Uuml",
	(char *)	"Yacute",
	(char *)	"THORN",
	(char *)	"szlig",
	(char *)	"agrave",
	(char *)	"aacute",
	(char *)	"acirc",
	(char *)	"atilde",
	(char *)	"auml",
	(char *)	"aring",
	(char *)	"aelig",
	(char *)	"ccedil",
	(char *)	"egrave",
	(char *)	"eacute",
	(char *)	"ecirc",
	(char *)	"euml",
	(char *)	"igrave",
	(char *)	"iacute",
	(char *)	"icirc",
	(char *)	"iuml",
	(char *)	"eth",
	(char *)	"ntilde",
	(char *)	"ograve",
	(char *)	"oacute",
	(char *)	"ocirc",
	(char *)	"otilde",
	(char *)	"ouml",
	(char *)	"divide",
	(char *)	"oslash",
	(char *)	"ugrave",
	(char *)	"uacute",
	(char *)	"ucirc",
	(char *)	"uuml",
	(char *)	"yacute",
	(char *)	"thorn",
	(char *)	"yuml"

	};

#endif	// _html_language_c

#endif	// _html_macros_h



