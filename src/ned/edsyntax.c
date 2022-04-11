#ifndef	_edsyntax_c
#define	_edsyntax_c

#define	_HASHCODE	57

#define	_BLACK	0
#define	_RED	1
#define	_GREEN	2
#define	_BROWN	3
#define	_NAVY 	4
#define	_PURPLE	5
#define	_CYAN	6
#define	_WHITE	7
#define	_GREY	8
#define	_PINK   9
#define	_LIME	10
#define	_YELLOW	11
#define	_BLUE	12
#define	_MAUVE	13
#define	_SKY	14
#define	_SNOW	15

#define	_SYNTAX_OFF	0
#define	_SYNTAX_ABAL	1
#define	_SYNTAX_C	2
#define	_SYNTAX_HTML	3
#define	_SYNTAX_SHELL	4
#define	_SYNTAX_PS	5

#define	_MAX_SYNTAX_NAME	20

static	BYTE *	syntax_name[]={
	(BYTE *) ".c",  (BYTE *) ".h",  (BYTE *) ".cpp",(BYTE *) ".hpp",
	(BYTE *) ".php",(BYTE *) ".js",
	(BYTE *) ".xsr",(BYTE *) ".xml",(BYTE *) ".htm",(BYTE *) ".html",
	(BYTE *) ".mf", (BYTE *) ".mak",(BYTE *) ".sh", (BYTE *) ".as",
	(BYTE *) ".s",	(BYTE *) ".ext",(BYTE *) ".dcl",(BYTE *) ".prc",
	(BYTE *) ".cls",
	(BPTR) ".ps"
	};

static	int	syntax_type[]={
	_SYNTAX_C,	_SYNTAX_C,	_SYNTAX_C,	_SYNTAX_C,
	_SYNTAX_C,	_SYNTAX_C,
	_SYNTAX_HTML,	_SYNTAX_HTML,	_SYNTAX_HTML,	_SYNTAX_HTML,
	_SYNTAX_SHELL,	_SYNTAX_SHELL,	_SYNTAX_SHELL,	_SYNTAX_ABAL,
	_SYNTAX_ABAL,	_SYNTAX_ABAL,	_SYNTAX_ABAL,	_SYNTAX_ABAL, 
	_SYNTAX_ABAL,
	_SYNTAX_PS
	};


static	int	_COLOUR_CONTROL=	_SYNTAX_ABAL;
static	int 	_COMMENT_COLOUR=	_GREEN;
static	int 	_KEYWORD_COLOUR=	_RED;
static	int 	_RAZ_COLOUR=		_WHITE;
static	int 	_QUOTE_COLOUR=		_BLUE;
static	int	_PUNCTUATE_COLOUR= 	_BLACK;

#define	MAX_SING_KEYWORDS 28

#define	MAX_KEYWORDS	227+MAX_SING_KEYWORDS


#define	PUNCTUATION "=*/+-&<>():'?,.!$#[]{}%%"

BYTE	tokeniser[256];
BYTE	atbshadow[1024];
BYTE *	tpunctuation=PUNCTUATION;
SWORD	thash=0;
SWORD	tindex=0;
SWORD	tstart=0;
SWORD	tquote=0;
SWORD	tcomment=0;
SWORD	tcuratb=-1;
SWORD	tcurligne=-1;
SWORD	hashready=0;

BYTE	keyhash[MAX_KEYWORDS];
BYTE *	keywords[MAX_KEYWORDS]={

 	/* Abal And C Language Compatible Keywords */
	/* --------------------------------------- */
	/* 0 -> 25 */
	/* ------- */
	(BYTE *)"IF",		(BYTE *)"ELSE",	
	(BYTE *)"BREAK",	(BYTE *)"ENDIF",
	(BYTE *)"IFDEF",	(BYTE *)"IFNDEF",
	(BYTE *)"INCLUDE",	(BYTE *)"CONST",
	(BYTE *)"FOR",		(BYTE *)"WHILE",
	(BYTE *)"DEFAULT",	(BYTE *)"CASE",
	(BYTE *)"GOTO",		(BYTE *)"EXIT",	
	(BYTE *)"EXTERN",	(BYTE *)"CONTINUE",
	(BYTE *)"RETURN",	(BYTE *)"INT",	
	(BYTE *)"OPEN",		(BYTE *)"CLOSE",
	(BYTE *)"READ",		(BYTE *)"WRITE",
	(BYTE *)"DEFINE",	(BYTE *)"UNDEF", 
	(BYTE *)"STRUCT",	(BYTE *)"UNION",
	(BYTE *)"DO",		

	/* C Language Extensions */
	/* --------------------- */
	/* 27 -> 37 */
	/* -------- */
	(BYTE *)"SWITCH",	(BYTE *)"CHAR",
	(BYTE *)"SHORT",	(BYTE *)"LONG",
	(BYTE *)"SIZEOF",	(BYTE *)"FLOAT",
	(BYTE *)"SIGNED",	(BYTE *)"UNSIGNED",
	(BYTE *)"STATIC",	(BYTE *)"REGISTER",
	(BYTE *)"VOID",

	/* ABAL Langauge Extensions */
	/* ------------------------ */
	/* 38 -> 155 */
	/* --------- */
	(BYTE *)"WEND",		(BYTE *)"TO", 	
	(BYTE *)"DCL",		(BYTE *)"PTR",	
	(BYTE *)"FILLER",	(BYTE *)"FIELD",
	(BYTE *)"LOOP",
	(BYTE *)"STEP", 	(BYTE *)"NEXT",
	(BYTE *)"REPEAT",	(BYTE *)"UNTIL",
	(BYTE *)"SELECT",	(BYTE *)"ENDSEL",
	(BYTE *)"PROC",		(BYTE *)"ENDPROC",
	(BYTE *)"SEGMENT",	(BYTE *)"ESEG",
	(BYTE *)"ENDLOC",	(BYTE *)"STOP",
	(BYTE *)"GOSUB",	(BYTE *)"RET",
	(BYTE *)"SEG",		(BYTE *)"LDGO",
	(BYTE *)"CREATE",	(BYTE *)"REMOVE",
	(BYTE *)"FORGET",	(BYTE *)"ALTER",
	(BYTE *)"ATTACH",	(BYTE *)"DETACH",
	(BYTE *)"VALIDPTR",	(BYTE *)"ALIAS",
	(BYTE *)"FORWARD",	(BYTE *) "USER",	
	(BYTE *)"ASSIGN",	(BYTE *)"INSERT",
	(BYTE *)"SEARCH",	(BYTE *)"MODIF",
	(BYTE *)"DELETE",	(BYTE *)"UP",
	(BYTE *)"DOWN",		(BYTE *)"RENAME",
	(BYTE *)"PRINT",	(BYTE *)"ASK",
	(BYTE *)"ATB",		(BYTE *)"TAB",
	(BYTE *)"PAINT",	(BYTE *)"HOTKEY",
	(BYTE *)"CONF",		(BYTE *)"CONV",
	(BYTE *)"MOVE",		(BYTE *)"SWAP",
	(BYTE *)"LEFT",		(BYTE *)"RIGHT",
	(BYTE *)"SUBSTR",	(BYTE *)"INCLUD",
	(BYTE *)"FIX",		(BYTE *)"ROUN",
	(BYTE *)"FP",		(BYTE *)"CHECKFMT",
	(BYTE *)"CHR",		(BYTE *)"GENER",
	(BYTE *)"SPACE",	(BYTE *)"KBF",
	(BYTE *)"DATE",		(BYTE *)"TRANS",
	(BYTE *)"STOP",		(BYTE *)"OP",
	(BYTE *)"ON",		(BYTE *)"OF",
	(BYTE *)"LOCAL",	(BYTE *)"ERROR",
	(BYTE *)"EVENT",	(BYTE *)"CALL",
	(BYTE *)"LARGE",	(BYTE *)"SMALL",
	(BYTE *)"LEN",		(BYTE *)"STRN",
	(BYTE *)"AND",		(BYTE *)"OR",
	(BYTE *)"OX",		(BYTE *)"ARG",
	(BYTE *)"ABORT",	(BYTE *)"RESUME",
	(BYTE *)"SHL",		(BYTE *)"SHR",
	(BYTE *)"INV",		(BYTE *)"DATA",
	(BYTE *)"RESTORE",	(BYTE *)"PAUSE",
	(BYTE *)"TABV",		(BYTE *)"CLEAR",
	(BYTE *)"PAGE",		(BYTE *)"FMT",
	(BYTE *)"COL",		(BYTE *)"LIN",
	(BYTE *)"LOAD",		(BYTE *)"CHAIN",
	(BYTE *)"GO",		(BYTE *)"END",
	(BYTE *)"NAME",		(BYTE *)"FIND",
	(BYTE *)"PARSE",	(BYTE *)"REWIND",
	(BYTE *)"MASK",		(BYTE *)"BELL",

	(BYTE *)"CURDIR",	(BYTE *)"CURVOL",
	(BYTE *)"ASKCOLOR",	(BYTE *)"ASKATB",
	(BYTE *)"HEX",		(BYTE *)"DEC",
	(BYTE *)"SGN",		(BYTE *)"RND",
	(BYTE *)"INDEX",	(BYTE *)"INSTR",

	(BYTE *)"ABS",		(BYTE *)"VPTR",
	(BYTE *)"FMINT",	(BYTE *)"FMFP",
	(BYTE *)"POWER",	(BYTE *)"REAL",
	(BYTE *)"LONG",		(BYTE *)"TRAN",
	(BYTE *)"VAL",		(BYTE *)"ENV",

	(BYTE *)"FM",		(BYTE *)"LANG",
	(BYTE *)"ASCIIFM",	(BYTE *)"STDFORM",
	(BYTE *)"SYSERROR",	(BYTE *)"ABALANFC",
	(BYTE *)"REPSTR",	(BYTE *)"CRYPT",
	(BYTE *)"PROCESS",	(BYTE *)"RUNTIME",

	(BYTE *)"DAYS",		(BYTE *)"LOADUSER",
	(BYTE *)"INITLOCAL",	(BYTE *)"INITGLOBAL",
	(BYTE *)"WAIT",		(BYTE *)"HASH",
	(BYTE *)"ERRADR",	(BYTE *)"EVENTADR",
	(BYTE *)"LOADGO",	(BYTE *)"SIZEOF",


	/* ABAL ++ Object extensions */
	/* ------------------------- */
	(BYTE *) "STRUCT",	(BYTE *) "UNION",
	(BYTE *) "ENDSTRUCT",	(BYTE *) "ENDUNION",
	(BYTE *) "CLASS",	(BYTE *) "ENDCLASS",
	(BYTE *) "PUBLIC",	(BYTE *) "PRIVATE",
	(BYTE *) "COMMON",	(BYTE *) "STATIC",
	(BYTE *) "DYNAMIC",	(BYTE *) "STRICT",
	(BYTE *) "INLINE",	(BYTE *) "ROUTINE",
	(BYTE *) "OVERLAY",	(BYTE *) "FUNCTION",
	(BYTE *) "METHOD",	(BYTE *) "POINTER",
	(BYTE *) "INTEGER",	(BYTE *) "STRING",
	(BYTE *) "NUMERIC",	(BYTE *) "INHERIT",
	(BYTE *) "INDIRECT",	(BYTE *) "VIRTUAL",
	(BYTE *) "OVERLOAD",	(BYTE *) "EXCEPTION",
	(BYTE *) "CONSTRUCTOR", (BYTE *) "DESTRUCTOR",
	(BYTE *) "CLASS_NAME",  (BYTE *) "OBJECT_NAME",
	(BYTE *) "CLASS_NUMBER",  (BYTE *) "OBJECT_NUMBER",

	/* ABAL ++ Packaging */
	/* ----------------- */
	(BYTE *) "LIBRARY",	(BYTE *) "ALL",
 	(BYTE *) "PROGRAM",	(BYTE *) "MODULE",
	(BYTE *) "DFILE",
	(BYTE *) "CFILE",
	(BYTE *) "EXTEND",
	(BYTE *) "BACKSPACE",
	(BYTE *) "MOD",

	/* SING keywords */
	/* ------------- */
	(BYTE *) "FIRST",	(BYTE *) "LAST",
	(BYTE *) "COLLECT",	(BYTE *) "LOCATE",
	(BYTE *) "UPDATE",	(BYTE *) "LOCK",
	(BYTE *) "SHOW",	(BYTE *) "HIDE",
	(BYTE *) "FOCUS",	(BYTE *) "LOSEFOCUS",
	(BYTE *) "PRESS",	(BYTE *) "TRIGGER",
	(BYTE *) "FREEZE",	(BYTE *) "THAW",
	(BYTE *) "VIEWPORT",	(BYTE *) "ONFOCUS",	
	(BYTE *) "ONSHOW",	(BYTE *) "ONHIDE",
	(BYTE *) "ONCREATE",	(BYTE *) "ONREMOVE",
	(BYTE *) "ONATTACH",	(BYTE *) "ONDETACH",
	(BYTE *) "QUESTION",	(BYTE *) "RESPONSE",
	(BYTE *) "BUFFER",	(BYTE *) "VALUE",
	(BYTE *) "COLUMN",	(BYTE *) "LINE",

	(BYTE *) 0, (BYTE *) 0
		
	};


BYTE	calculate_hashcode(BYTE * sptr)
{
	SWORD	r=0;
	while ( *sptr )	r += *(sptr++);
	return(((r % _HASHCODE) & 0x00FF));
}

VOID	calculate_keyhash()
{
	SWORD	i;
	for (	i=0; i < MAX_KEYWORDS;	i++ ) {
		if (!(  keywords[i] ))
			keyhash[i] = (_HASHCODE+1);
		else	keyhash[i] = calculate_hashcode(keywords[i]);
		}
	hashready = 1;
	return;
}

VOID	toggle_colour_control(int mode)
{
	switch ( mode ) {
		case	'P'	:
		case	'p'	:
			_COLOUR_CONTROL = _SYNTAX_PS;
			break;
		case	'A'	:
		case	'a'	:
			_COLOUR_CONTROL = _SYNTAX_ABAL;
			break;
		case	'C'	:
		case	'c'	:
			_COLOUR_CONTROL = _SYNTAX_C;
			break;
		case	'H'	:
		case	'h'	:
			_COLOUR_CONTROL = _SYNTAX_HTML;
			break;
		case	'S'	:
		case	's'	:
			_COLOUR_CONTROL = _SYNTAX_SHELL;
			break;
		default		:
			_COLOUR_CONTROL = _SYNTAX_OFF;
			break;
		}
	return;
}

VOID	editorOnColour(int active, int nc, int qc, int kc, int cc, int pc )
{
	if ( active != -1 )
		_COLOUR_CONTROL = active;
	_RAZ_COLOUR = nc;
	_QUOTE_COLOUR = qc;
	_KEYWORD_COLOUR = kc;
	_COMMENT_COLOUR = cc;
	_PUNCTUATE_COLOUR = pc;
	return;
}

static	VOID	editorEnvColour( char * eptr, int normal, int quote, int keyword, int comment ,int punctuation )
{
	if ( eptr != (char *) 0) {

		if (( *eptr >= '0' ) &&  ( *eptr <= '9' )) {
			normal = 0;
			while (( *eptr >= '0' ) &&  ( *eptr <= '9' ))
				normal = ((normal * 10) + (*(eptr++) - '0'));
			if ( *eptr == ':' )
				eptr++;	
			}
		if (( *eptr >= '0' ) &&  ( *eptr <= '9' )) {	
			quote = 0;
			while (( *eptr >= '0' ) &&  ( *eptr <= '9' ))
				quote = ((quote * 10) + (*(eptr++) - '0'));
			if ( *eptr == ':' )
				eptr++;	
			}
		if (( *eptr >= '0' ) &&  ( *eptr <= '9' )) {
			keyword = 0;
			while (( *eptr >= '0' ) &&  ( *eptr <= '9' ))
					keyword = ((keyword * 10) + (*(eptr++) - '0'));
			if ( *eptr == ':' )
				eptr++;	
			}
		if (( *eptr >= '0' ) &&  ( *eptr <= '9' )) {
			comment = 0;
			while (( *eptr >= '0' ) &&  ( *eptr <= '9' ))
				comment = ((comment * 10) + (*(eptr++) - '0'));
			if ( *eptr == ':' )
				eptr++;	
			}
		if (( *eptr >= '0' ) &&  ( *eptr <= '9' )) {
			punctuation = 0;
			while (( *eptr >= '0' ) &&  ( *eptr <= '9' ))
				punctuation = ((punctuation * 10) + (*(eptr++) - '0'));
			if ( *eptr == ':' )
				eptr++;	
			}
		}
	editorOnColour(-1, normal,quote,keyword,comment,punctuation);
	return;
}


VOID	editorOnGraphic()
{
	char *	eptr;
	if (!( eptr = getenv("AEDGRCOLOUR")))
		editorOnColour(-1, _BLACK, _BLUE, _PINK, _GREEN, _NAVY);
	else	editorEnvColour(eptr,_BLACK, _BLUE, _PINK, _GREEN, _NAVY);
}

VOID	editorOnText()
{
	char *	eptr;
	if (!( eptr = getenv("AEDTEXTCOLOUR")))
		editorOnColour(-1, _WHITE, _NAVY, _RED, _GREEN, _GREY);
	else	editorEnvColour(eptr, _WHITE, _NAVY, _RED, _GREEN, _GREY);
}

VOID	colorise()
{
	BYTE *	tptr;
	SWORD	i,j;
	BYTE	h;

	tokeniser[tindex]=0;

	if (( _COLOUR_CONTROL == _SYNTAX_HTML ) 
	||  ( _COLOUR_CONTROL == _SYNTAX_PS  )
	||  ( _COLOUR_CONTROL == _SYNTAX_SHELL)) {
		for ( i=0; i < tindex; i++ )
			atbshadow[(i+tstart)] = _RAZ_COLOUR;
		return;
		}
	if (!( hashready )) calculate_keyhash();

	thash %= _HASHCODE;

	for (i=0; i < MAX_KEYWORDS; i++ ) {
		if ( _COLOUR_CONTROL == _SYNTAX_C ) {
			if ( i > 37 ) break;
			}
		else if (( i > 27 ) && ( i < 38 ))
			continue;		
		if ( keyhash[i] != thash )
			continue;
		else if (!( tptr=keywords[i]))
			break;
		else	j=0;
		while ( *(tptr+j) != 0 ) {
			if ( *(tptr+j) != tokeniser[j] )
				break;
			else	j++;
			}
		if  (( *(tptr+j) != 0 ) || ( tokeniser[j] != 0))
			continue;
		for ( i=0; i < tindex; i++ )
			atbshadow[(i+tstart)] = _KEYWORD_COLOUR;
		break;
		}			
	thash = tindex = tstart = 0;
	return;
}

SWORD	ispunctuation( BYTE c )
{
	int	i;
	for ( i=0; *(tpunctuation+i) != 0; i++ )
		if ( *(tpunctuation+i) == c )
			return(c);
	return(0);
} 
		
VOID	determine_syntax_control( BYTE * nomfic )
{
	BYTE	nptr[64];
	SWORD	i;
	SWORD	s;
	BYTE *	sptr;
	if (!( 	fn_parser( nomfic,nptr, 16 ) ))
		_COLOUR_CONTROL = _SYNTAX_SHELL;
	else	{
		_COLOUR_CONTROL = _SYNTAX_ABAL;
		for ( i=0; nptr[i] != 0; i++ ) {
			if (( nptr[i] >= 'A' )
			&&  ( nptr[i] <= 'Z' ))
				nptr[i] += ('a' - 'A');
			}
		for ( s=0; s < _MAX_SYNTAX_NAME; s++ ) {
			if (!( sptr = syntax_name[s] ))
				continue;
			for ( i=0; *(sptr+i) != 0; i++ ) {
				if (!( nptr[i] ))
					break;
				else if ( nptr[i] != *(sptr+i) )
					break;
				}
			if ( nptr[i] != *(sptr+i) )
				continue;
			else	{
				_COLOUR_CONTROL = syntax_type[s];
				break;
				}
			}
		}
	return;
}


SWORD	build_shadow_colour(int nligne)
{
	SWORD	i;
	BYTE	c;

	tcuratb = -1; tcurligne = nligne;

	switch ( _COLOUR_CONTROL ) {
		case	_SYNTAX_OFF	:
			return(0);
		case	_SYNTAX_PS	:
		case	_SYNTAX_ABAL	:
		case	_SYNTAX_C	:
		case	_SYNTAX_HTML	:
		case	_SYNTAX_SHELL	:
			break;
		default			:
			return(0);
		}

	/* 'colouration syntaxique' requires lookahead */
	/* ------------------------------------------- */
	thash = tcomment = tquote = tindex = i = 0;

	if ( _COLOUR_CONTROL == _SYNTAX_HTML ) {
		tcomment = _RAZ_COLOUR;
		while (1) {
			switch ((c = getmemchar(nligne,i))) {
				case	EOSTR	:
					break;
				case	'\t'	:
				case	' '	:
					atbshadow[i++] = _RAZ_COLOUR;
					continue;
				case	'<'	:
					tcomment = _KEYWORD_COLOUR;
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
				case	'"'	:
				case	'='	:
				case	'/'	:
					if ( tcomment == _KEYWORD_COLOUR )
						atbshadow[i++] = _QUOTE_COLOUR;
					else	atbshadow[i++] = _RAZ_COLOUR;
					continue;
				case	'>'	:
					atbshadow[i++] = _QUOTE_COLOUR;
					tcomment = _RAZ_COLOUR;
					continue;
				default		:
					atbshadow[i++] = tcomment;
					continue;
				}
			break;
			}				
		}
	else if ( _COLOUR_CONTROL == _SYNTAX_SHELL ) {
		tcomment = _RAZ_COLOUR;
		while (1) {
			switch ((c = getmemchar(nligne,i))) {
				case	EOSTR	:
					break;
				case	'\t'	:
					if ( tcomment != _COMMENT_COLOUR ) {
						atbshadow[i++] = tcomment = _KEYWORD_COLOUR;
						}
					else	atbshadow[i++] = tcomment;
					continue;
				case	'!'	:
					if ( tcomment != _COMMENT_COLOUR ) {
						atbshadow[i++] = tcomment = _QUOTE_COLOUR;
						}
					else	atbshadow[i++] = tcomment;
					continue;
				case	'#'	:
					atbshadow[i++] = tcomment = _COMMENT_COLOUR;
					continue;
				default		:
					atbshadow[i++] = tcomment;
					continue;
				}
			break;
			}				
		}
	else if ( _COLOUR_CONTROL == _SYNTAX_PS ) {
		tcomment = _RAZ_COLOUR;
		while (1) {
			switch ((c = getmemchar(nligne,i))) {
				case	EOSTR	:
					break;
				case	'<'	:
				case	'('	:
					if ( tcomment ) {
						atbshadow[i++] = tcomment;
						continue;
						}
					else	{
						tquote=_QUOTE_COLOUR;
						atbshadow[i++] = _QUOTE_COLOUR;
						continue;
						}
				case	'{'	:
					if ( tcomment ) {
						atbshadow[i++] = tcomment;
						continue;
						}
					else	{
						tquote =_KEYWORD_COLOUR;
						atbshadow[i++] = _KEYWORD_COLOUR;
						continue;
						}
				case	'>'	:
				case	')'	:
					if ( tcomment ) {
						atbshadow[i++] = tcomment;
						continue;
						}
					else	{
						atbshadow[i++] = _QUOTE_COLOUR;
						tquote=0;
						continue;
						}

				case	'}'	:
					if ( tcomment ) {
						atbshadow[i++] = tcomment;
						continue;
						}
					else	{
						atbshadow[i++] = _KEYWORD_COLOUR;
						tquote=0;
						continue;
						}

				case	0x0025	:
					atbshadow[i++] = tcomment = _COMMENT_COLOUR;
					continue;
				default		:
					if ( tquote ) {
						atbshadow[i++] = tquote;
						}
					else	{
						atbshadow[i++] = tcomment;
						}
					continue;
				}
			break;
			}				
		}
	else	{
		/* Syntax ABAL and C */
		/* ----------------- */
		while (1) {
		switch ((c = getmemchar(nligne,i))) {
			case	EOSTR	:
				if ( tindex ) colorise();
				break;
			case	'\t'	:
			case	' '	:
				if ( tindex ) colorise();
				atbshadow[i++] = _RAZ_COLOUR;
				continue;
			case	'<'	:
				if ( tquote ) {
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
					}
				else if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				if ( tindex ) colorise();
				atbshadow[i++] = _PUNCTUATE_COLOUR;
				continue;

			case	'>'	:
				if ( tquote ) {
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
					}
				else if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				else	{
					if ( tindex ) colorise();
					atbshadow[i++] = _PUNCTUATE_COLOUR;
					continue;
					}

			case	'/'	:
				if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				else if ( tquote ) {
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
					}
				else if ( _COLOUR_CONTROL == _SYNTAX_C ) {
					if (((c = getmemchar(nligne,(i+1))) == '*') 
					||   ( c == '/' )) {
						if ( tindex ) colorise();
						atbshadow[i++] = _COMMENT_COLOUR;
						atbshadow[i++] = _COMMENT_COLOUR;
						tcomment = _COMMENT_COLOUR;
						continue;
						}
					}
				if ( tindex ) colorise();
				atbshadow[i++] = _PUNCTUATE_COLOUR;
				continue;

			case	'*'	:
				if ( tquote ) {
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
					}
				else if (!( tcomment )) {
					if ( tindex ) colorise();
					atbshadow[i++] = _PUNCTUATE_COLOUR;
					continue;
					}
				else if ( _COLOUR_CONTROL == _SYNTAX_C ) {
					if ((c = getmemchar(nligne,(i+1)) == '/')) {
						if ( tindex ) colorise();
						atbshadow[i++] = _COMMENT_COLOUR;
						tcomment=0;
						}
					}
				atbshadow[i++] = _COMMENT_COLOUR;
				continue;

			case	'"'	:
				if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				else	{
					if ( tindex ) colorise();
					if ( tquote ) {
						atbshadow[i++] = _QUOTE_COLOUR;
						tquote=0;
						}
					else	{
						tquote=_QUOTE_COLOUR;
						atbshadow[i++] = _QUOTE_COLOUR;
						}
					continue;
					}
				
			case	';'	:
				if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				else if ( _COLOUR_CONTROL == _SYNTAX_ABAL ) {
					if (!( tquote )) {
						if ( tindex ) colorise();
						tcomment = _COMMENT_COLOUR;
						}
					}
				else	{					
					if ( tindex ) colorise();
					atbshadow[i++] = _PUNCTUATE_COLOUR;
					continue;
					}
			default		:
				if ( tcomment ) {
					atbshadow[i++] = tcomment;
					continue;
					}
				else if ( tquote ) {
					atbshadow[i++] = _QUOTE_COLOUR;
					continue;
					}
				else if ( ispunctuation(c) ) {
					if ( tindex ) colorise();
					atbshadow[i++] = _PUNCTUATE_COLOUR;
					continue;
					}
				if (((c >= 'a') && (c <= 'z'))
				||  ( c == '_' )
				||  ((c >= 'A') && (c <= 'Z'))) {
					if (!( tindex ))
						tstart = i;

					atbshadow[i++] = _RAZ_COLOUR;
					if ( c != '_' ) c &= 0x05F;
					thash += c;
					tokeniser[tindex++] = c;
					continue;
					}
				else 	{
					if ( tindex ) colorise();
					atbshadow[i++] = _RAZ_COLOUR;
					continue;
					}
			}					
		break;
		}
		}
	return(1);
}
				
#define	use_shadow_colour(iii) { \
	if (( _COLOUR_CONTROL ) \
	&&  ( atbshadow[iii] != tcuratb )) {\
		foregr((tcuratb = atbshadow[iii])); \
		} \
	}\

SWORD	check_shadow_colour(int nligne, int  ncolumn )
{
	if (!( _COLOUR_CONTROL ))
		return(0);
	else if (( nligne != tcurligne )
	     &&  (!( build_shadow_colour(nligne) )))
		return(0);
	else	{
		foregr((tcuratb = atbshadow[ncolumn]));
		return( _COLOUR_CONTROL );
		}
}


#endif	/* _edsyntax_c */
	/* ----------- */

