#include <stdio.h>

#include "asb.h"

static	struct	asb_context {
	int	detected;
	int	strip;

	int	indent;
	int	nextindent;
	int	active;

	int	apostrophe;
	int	tokens;

	int	margin;
	int	marginsize;
	
	int	indentsize;
	int	collectdex;

	int	expression;
	int	ignore;

	char	* what;
	char 	* with;
	int	verbose;

	int	echo;
	int	doit;

	FILE *	source;
	FILE *	target;
	int	ungot;
	int	tokensize;
	char	commande[1024];
	char	token[2048];
	char	xtoken[2048];
	int	dorc;
	} F = 	{ 
		-1,
		0,
		0, 0, 0,
		0, 0, 
		0, 0,
		8, 0, 
		0, 0,
		(char *) 0, (char *) 0,
		0,0,
		1, 
		(FILE *)0,(FILE*)0,
		0 
		};

static	int	outputbyte(int c )
{
	if (!( c ))
		return(0);

	else if (!( F.target ))
		printf("%c",c);
	else	fprintf(F.target,"%c",c);
	return(0);
}

static	int	outputstring(char * sptr)
{
	int	status;
	while ( *sptr )
		if ((status = outputbyte( *(sptr++) )) != 0)	
			return(status);
	return(0);
}

void	asb_terminate()
{
	if ( F.source ) {
		fclose(F.source );
		F.source = (FILE*) 0;
		}	

	if ( F.target ) {
		fclose(F.target );
		F.target = (FILE*) 0;
		}	

	return;
}

static	int	compare(char * aptr, char * bptr )
{
	int	i;
	for ( i=0; *(aptr+i) != 0; i++ )
		if ( *(aptr+i) != *(bptr+i) )
			return(0);
	if ( *(aptr+i) != *(bptr+i) )
		return(0);
	else	return(1);
}

static	int	is_white_space( int c )
{
	switch ( c ) {
		case	'\r'	:
			F.dorc=1;
		case	' ' 	:
		case	'\t'	:
		case	'\n'	:
			return(1);
		default		:
			return(0);
		}
}

static	int	is_token_legal(int c)
{
	if ((c >= 'a') && (c <= 'z' ))
		return(1);
	else if ((c >= 'A') && (c <= 'Z' ))
		return(1);
	else if ((c >= '0') && (c <= '9' ))
		return(1);
	else if ((c == '_') || (c == '$' ))
		return(1);
	else	return(0);
}

static	void	ungetch(int c)
{
	F.ungot = c;
	return;
}

static	int	getch()
{
	int	c;
	if ((c = F.ungot) != 0)
		F.ungot = 0;
	else if ((c = fgetc(F.source)) == -1)
		c = 0;
	if ( F.echo )
		if ( c > 0 )
			printf("%c",c);
	return(c);
}

static	void	end_of_line()
{
	F.tokens = 0;
	F.margin = 0;
	F.active = 0;
	F.indent = F.nextindent;
	return;
}

static	int	soft_newline()
{
	if ( F.dorc )
		outputbyte('\r');
	outputbyte('\n');
	end_of_line();
	return(1);
}

static	void	activate(int how)
{
	int	i;
	int	j;
	if (!( F.active )) {
		switch ( how ) {
			case	1 :
				for (i=0; i < F.indent; i++ ) {
					if ( F.indentsize == 8 )
						outputbyte('\t');
					else	{
						for (j=0; j < F.indentsize; j++ )
							outputbyte(' ');
						}
					}
				break;				
			case	2	:
				for (i=0; i < F.marginsize; i++ ) {
					if ( F.indentsize == 8 )
						outputbyte('\t');
					else	{
						for (j=0; j < F.indentsize; j++ )
							outputbyte(' ');
						}
					}
				break;				

			}
		F.active = 1;
		}
	return;
}
static	int	strip_comment(int c)
{
	while ((c = getch()) != 0)
		if ( c == '\n' )
			break;
	end_of_line();
	return(c);
}

static	int	keep_comment(int c)
{
	if (!( F.active )) 
		activate(1);
	if ( c != 0x0027 )
		outputbyte(c);
	while ((c = getch()) != 0) {
		outputbyte(c);
		if ( c == '\n' )
			break;
		}
	end_of_line();
	return(c);
}

static	int	strip_new_comment(int c)
{
	while ((c = getch()) != 0)
		if ( c == '}' )
			break;
	end_of_line();
	return(c);
}

static	int	keep_new_comment(int c)
{
	if (!( F.active )) 
		activate(1);
	outputbyte(c);
	while ((c = getch()) != 0) {
		outputbyte(c);
		if ( c == '}' )
			break;
		}
	end_of_line();
	return(c);
}

static	int	not_white_space()
{
	int	c;

	while ((c = getch()) != 0) {
		switch (c) {

			case	0x0027	: /* apostrophe */
				F.apostrophe=1;
				if (!( strip_comment(c) ))
					return(0);
				else	continue;

			case	'{'	:
				if ( F.strip ) {
					if (!( strip_new_comment(c) ))
						return(0);
					else	continue;
					}
				else	{
					if (!( keep_new_comment(c) ))
						return(0);
					else	continue;
					}

			case	'*'	:
				if ( F.active )
					break;
			case	';'	:
				if ( F.strip ) {
					if (!( strip_comment(c) ))
						return(0);
					else	continue;
					}
				else	{
					if (!( keep_comment(c) ))
						return(0);
					else	continue;
					}

			case	'\r'	:
				F.dorc = 1;				
				if ( F.active )
					outputbyte(c);
				continue;
			case	'\n'	:
				if (!( F.apostrophe )) {
					if ( F.active )
						outputbyte(c);
					end_of_line();
					}
				continue;

			case	' '	:
				if ( F.active )
					outputbyte(' ');
				F.margin++;
				continue;

			case	'\t'	:
				do	{
					F.margin++;
					}
				while ((F.margin % F.indentsize) != 0);
				if ( F.active )
					outputbyte('\t');
				continue;
			}
		break;
		}
	F.apostrophe=0;
	return(c);
}

static	int	get_token()
{
	int	c;
	int	i=0;

	F.tokensize = 0;

	while ((c = getch()) != 0) {

		if (!( is_token_legal(c) )) {
			ungetch(c);
			break;
			}
		else	{

			/* detect and perform case conversion when ignoring case */
			/* ----------------------------------------------------- */
			if (( F.ignore ) &&  ((c >= 'a') && ( c <= 'z' ))) { c -= ('a'-'A'); }
			F.token[i++] = c;

			}
		}

	if (!( i ))
		return(0);
	else	{ 
		F.token[i++] = 0;
		F.tokens++;
		F.tokensize=i;
		return(i);
		}
}

static	int	handle_label()
{
	if (!( get_token() )) {
		return(0);
		}
	else	{
		outputbyte('&');
		outputstring(F.token);
		return(1);
		}

}

static	int	handle_directive()
{
	if (!( get_token() )) {
		return(0);
		}
	else	{
		outputbyte('#');
		outputstring(F.token);
		return(1);
		}

}

static	int	handle_quote()
{
	int	c;
	outputbyte('"');
	while ((c = getch()) != 0) {
		outputbyte(c);
		if ( c == '"' )
			break;
		}
	return(3);
}



static	int	punctuate(int c)
{
	int	cc;
	F.token[0] = c;
	F.token[1] = 0;
	if (( c == '&' ) && (!( F.tokens ))) {
		activate(0);
		return( handle_label() );
		}
	else if (( c == '#' ) && (!( F.tokens ))) {
		activate(2);
		return( handle_directive() );
		}
	else if ( c == '"' ) {
		activate(1);
		return( handle_quote() );
		}
	else 	{
		if ( c == ':' ) {
			if ((cc = getch()) == ':' )
				return( soft_newline() );
			else	ungetch(cc);
			}
		activate(1);
		outputbyte(c);
		return(1);
		}
}

static	int	detection()
{
	int	i;
	for (i=0; F.token[i] != 0; i++ ) {
		if (( F.token[i] >= 'a' )
		&&  ( F.token[i] <= 'z' ))
			F.xtoken[i] = (F.token[i] - ('a'-'A'));
		else	F.xtoken[i] = F.token[i];
		}
	F.xtoken[i] = 0;
	for ( i=0; i < _MAX_KEYWORDS; i++ )
		if (!( strcmp( keywords[i] , F.xtoken ) ))
			return(i);
	return(-1);
}

/*	Complicated case of detection of the BAL/ABAL single line IF expression		*/
/*	which does not require and endif 						*/

static	int	handle_if()
{
	int	quoting=0;
	int	c;
	while ((c = getch()) != 0) {
		if (( c == '\n' ) ||  ( c == '\r' )) {
			ungetch(c);
			return(2);
			}
		else if ( c == '"' ) {
			outputbyte(c);
			if ( quoting )
				quoting=0;
			else	quoting=1;
			continue;
			}
		else if ( quoting ) {
			outputbyte(c);
			continue;
			}
		else if ( ( c == ';' ) || ( c == '{' ) || ( c == 0x0027 )) {
			ungetch(c);
			return(2);
			}
		outputbyte(c);
		if (c != ':' )
			continue;
		else if (!(c = getch()))
			return(0);
		else if ( c == ':' ) {
			outputbyte(c);
			return(2);
			}
		else 	{
			ungetch(c);
			if ( F.nextindent )
				F.nextindent--;
			return(2);
			}
		}
	if (!( c ))
		return(0);
	else	return(2);
}


static	int	analyser()
{
	if (!( F.tokensize ))
		return(0);
	else	{
		if (!( F.active )) {

			switch ((F.detected = detection())) {

				case	_KEYWORD_PROGRAM	:
				case	_KEYWORD_MODULE		:
				case	_KEYWORD_LIBRARY	:
					F.indent = F.marginsize;
					F.nextindent = F.indent;
					break;

				case	_KEYWORD_SEGMENT	:
				case	_KEYWORD_PROC		:
					F.indent = F.marginsize;
					F.nextindent = (F.indent+1);
					break;

				case	_KEYWORD_ESEG		:
				case	_KEYWORD_ENDPROC	:
				case	_KEYWORD_CONST		:
				case	_KEYWORD_FORWARD	:
				case	_KEYWORD_EXTERN		:
					F.indent = F.marginsize;
					F.nextindent = F.indent;
					break;

				case	_KEYWORD_DEFAULT	:
				case	_KEYWORD_CASE		: 
				case	_KEYWORD_ELSE		: 
					if ( F.indent > F.marginsize )
						F.indent--;
					break;

				case	_KEYWORD_ENDIF		: 
				case	_KEYWORD_NEXT		: 
				case	_KEYWORD_WEND		: 
				case	_KEYWORD_UNTIL		: 
				case	_KEYWORD_ENDSEL		: 
				case	_KEYWORD_LOOP		: 
					if ( F.indent > F.marginsize )
						F.indent--;
					F.nextindent = F.indent;
					break;

				case	_KEYWORD_IF		: 
					F.nextindent = (F.indent+1);
					activate(1);
					outputstring(F.token);
					return(handle_if());

				case	_KEYWORD_FOR		: 
				case	_KEYWORD_WHILE		: 
				case	_KEYWORD_REPEAT		: 
				case	_KEYWORD_SELECT		: 
				case	_KEYWORD_DO		: 
					F.nextindent = (F.indent+1);
					break;

				case	_KEYWORD_FIELD		: 
				case	_KEYWORD_DCL		: 
				case	_KEYWORD_PTR		: 
					break;
				}
			activate(1);
			}
		else	{
			switch ( detection() ) {

				case	_KEYWORD_NEXT		: 
					if ( F.detected != _KEYWORD_FOR )
						break;
				case	_KEYWORD_ENDIF		: 
				case	_KEYWORD_WEND		: 
				case	_KEYWORD_UNTIL		: 
				case	_KEYWORD_ENDSEL		: 
				case	_KEYWORD_LOOP		: 
					if ( F.nextindent > F.marginsize )
						F.nextindent--;
					break;

				case	_KEYWORD_IF		: 
				case	_KEYWORD_FOR		: 
				case	_KEYWORD_WHILE		: 
				case	_KEYWORD_REPEAT		: 
				case	_KEYWORD_SELECT		: 
				case	_KEYWORD_DO		: 
					F.nextindent = (F.nextindent+1);
					break;

				}
			}


		outputstring(F.token);

		return(2);
		}
}

static	int	lexical()
{
	int	i=0;
	int	c;

	if (!(c = not_white_space() ))
		return(0);

	else if (!( is_token_legal( c ) ))
		return( punctuate(c) );

	else	ungetch(c);

	if (!( get_token() ))
		return(0);
	else	return( analyser() );
}

static	void	initialise()
{
	F.nextindent = F.indent = F.marginsize;
	F.detected = -1;
	F.margin = 0;
	F.tokens = 0;
	F.ungot	 = 0;
	F.active = 0;
	F.target = 
	F.source = (FILE *) 0;
	return;
}

int	asb_operation(char *nptr)
{
	int	status;
	int	iteration=1;
	char	tempname[64];

	initialise();

	if ( F.verbose ) printf("\nfile : %s ",nptr);

	if (!(F.source = fopen( nptr, "r"))) return(40);

	sprintf(tempname,"ab%x.%u.tmp",time((long *)0),iteration);

	if (F.doit) {
		while  (( F.target = fopen(tempname,"r")) != (FILE *) 0) {
			fclose(F.target);
			sprintf(tempname,"sandr%x.%u.tmp",time((long *)0),++iteration);
			}
		if (!( F.target = fopen(tempname,"w"))) {
			fclose(F.source);
			return(46);
			}
		else if ( F.verbose )
			printf(" to : %s ",tempname);

		}
	else	F.target = (FILE *) 0;

	F.ungot = 0;

	/* perform lexical analysis */
	/* ------------------------ */
	while ( lexical() );

	fclose(F.source);

	if (F.target) {
		fclose(F.target);
		if ( F.doit )  {
			sprintf(F.commande,"mv %s %s.bak",nptr,nptr);
			system(F.commande);
			sprintf(F.commande,"mv %s %s",tempname,nptr);
			system(F.commande);
			}				
		else	{
			sprintf(F.commande,"rm %s",tempname);
			system(F.commande);
			}
		}
	return(0);
}

void	asb_option_g(int v) { F.doit = v;	return; }
void	asb_option_s(int v) { F.strip= v;	return; }
void	asb_option_m(int v) { F.marginsize = v;	return; }
void	asb_option_i(int v) { F.indentsize = v; return; }
void	asb_option_v(int v) { F.verbose = v; 	return; }
void	asb_option_e(int v) { F.echo    = v; 	return; }

void	asb_initialise()
{
	asb_option_g(1);
	asb_option_s(0);
	asb_option_i(8);
	asb_option_m(0);
	asb_option_v(0);
	return;
}


