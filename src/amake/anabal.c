#ifndef	_anabal_c
#define	_anabal_c

#include "anabal.h"

struct	item_list	files;

int	options=0;
int	_bytes_before=3;
int	_bytes_after=4;

char	marginiser[256];

struct	analyser {
	int	verbose;
	int	echo;
	int	doit;
	FILE *	source;
	int	ungot;
	int	hitcount;
	int	total;
	int	files;
	int	state;
	int	modifier;
	char	commande[1024];
	char	token[2048];
	} F = { (char *) 0, (char *) 0,0,0,0, (FILE *)0,(FILE*)0,0,0,0,0,0,0 };

/*	Input Routines		*/
/*	--------------		*/


public	char * drop_string( char * sptr )
{
	liberate( sptr );
	return((char *) 0);
}

public	char *	allocate_string( char * sptr )
{
	char *	rptr;
	if (!( sptr ))
		return( sptr );
	else if (!( rptr = allocate( strlen( sptr ) + 1 ) ))
		return( rptr );
	else	{
		strcpy( rptr, sptr );
		return( rptr );
		}
}	

private	int	analysed(char * aptr, int status)
{
	printf("\n** error : %u : %s **\n",status,aptr);

	if ( F.source ) {
		fclose(F.source );
		F.source = (FILE*) 0;
		}	
	return(1);
}

private	int	is_token_legal(int c)
{
	if ((c >= 'a') && (c <= 'z' ))
		return(1);
	else if ((c >= 'A') && (c <= 'Z' ))
		return(1);
	else if ((c >= '0') && (c <= '9' ))
		return(1);
	else if ((c == '_') || (c == '$' ) || ( c == '#' ))
		return(1);
	else if ( c == '.' )
		return(1);
	else	return(0);
}

private	void	ungetch(int c)
{
	F.ungot = c;
	return;
}

int	getch()
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

private	void	push_comment(int final)
{
	int	c;
	while ((c = getch()) != 0)
		if ( c == final )
			break;
	return;
}
	
	
private	void	push_newline()
{
	int 	c;
	while ((c = getch()) != 0) {
		switch (c) {
			case	'{'	:
				push_comment('}');
				continue;

			case	0x0027	: /* single quote  */
			case	';'	:
				push_comment('\n');
			case	' '	:
			case	'\t'	:
			case	'\r'	:
			case	'\n'	:
				continue;
			case	'*'	:
				push_comment('\n');
				continue;
			}
		break;
		}
	ungetch(c);
	return;
}

private	int	push_white_space()
{
	int	c;
	while ((c = getch()) != 0) {
		switch (c) {
			case	'{'	:
				push_comment('}');
				continue;
			case	0x0027	: /* single quote  */
				push_comment('\n');
				continue;
			case	';'	:
				push_comment('\n');
			case	'\n'	:
				push_newline();
			case	' '	:
			case	'\t'	:
			case	'\r'	:
				continue;
			}
		break;
		}
	return(c);
}

private	int	punctuate(int c)
{
	F.token[0] = c;
	F.token[1] = 0;
	return(1);
}


/*	Output Routines		*/
/*	---------------		*/


private	void	indent(int margin)
{
	int	i;
	int	n;
	for (i=0; i < margin; i++ ) {
		if ( marginiser[i] == '+' ) {
			marginiser[i] = '|';
			for (n=0; n < _bytes_before; n++)
				printf(" ");
			printf("+");
			for (n=0; n < _bytes_after; n++)
				printf("-");
			}
		else if ( marginiser[i] == '-' ) {
			for (n=0; n < _bytes_before; n++)
				printf(" ");
			printf("+");
			for (n=0; n < _bytes_after; n++)
				printf("-");
			marginiser[i] = 0;
			}
		else if (!( marginiser[i] ))
			printf("\t");
		else	{
			for (n=0; n < _bytes_before; n++)
				printf(" ");
			printf("%c",marginiser[i]);
			for (n=0; n < _bytes_after; n++)
				printf(" ");
			}
		}
	return;
}

private	void	set_margin(int level, int c )
{
	marginiser[level] = c;
	return;
}

private	void	reset_margins()
{
	int	i;
	for (	i=0; i < 256; i++ )
		marginiser[i] = 0;
	return;
}


	
private	int	compare(char * aptr, char * bptr )
{
	int	i;
	for ( i=0; *(aptr+i) != 0; i++ )
		if ( *(aptr+i) != *(bptr+i) )
			return(0);
	if ( *(aptr+i) != *(bptr+i) )
		return(0);
	else	return(1);
}

#include "anafile.c"
#include "anacode.c"
#include "anacall.c"
#include "anaincl.c"
#include "analist.c"
#include "anaitem.c"

private	int	collector( int c )
{
	int	i=0;
	int	quoting=0;
	while (1) {
		if ( quoting ) {
			if ( c == '"' )
				break;
			else	F.token[i++] = c;
			}
		else if ( c == '"' ) {
			if (!( i )) {
				quoting=1;
				}
			else	{
				ungetch(c);
				break;
				}
			}
		else if (!( is_token_legal(c) )) {
			ungetch(c);
			break;
			}
		else	{
			if ((c >= 'a') && ( c <= 'z'))
				c -= ('a'-'A');
			F.token[i++] = c;
			}
		if (!(c = getch()))
			break;
		}
	if (!( i ))
		return(0);
	else	{ 
		F.token[i++] = 0;
		switch ( F.state ) {
			case	0 :
				if ( compare( F.token, "PROC" ) )
					F.state=1;
				else if ( compare( F.token, "SEGMENT" ) )
					F.state=10;
				else if ( compare( F.token, "EXTERN" ) )
					F.modifier=2;
				else if ( compare( F.token, "FORWARD" ) )
					F.modifier=1;
				else if ( compare( F.token, "#INCLUDE" ) )
					F.state = 9;
				else if ( compare( F.token, "PROGRAM" ) )
					F.state=100;
				else if ( compare( F.token, "MODULE" ) )
					F.state=101;
				break;

			case	9 :
				if ( F.verbose > 1 )
					printf("\t#INCLUDE %s\n",F.token);
				add_include(&files, F.token );
				F.state = 0;
				break;

			case	100 :
				if ( F.verbose > 1 )
					printf("\t#PROGRAM %s\n",F.token);
				program_file( F.token );
				F.state = 0;
				break;

			case	101 :
				if ( F.verbose > 1 )
					printf("\t#MODULE %s\n",F.token);
				module_file( F.token );
				F.state = 0;
				break;

			case	1 :
				switch ( F.modifier ) {
					case	0 :
						if ( F.verbose > 1 )
							printf("PROC %s\n",F.token);
						add_code(&files, F.token,_code_procedure );
						break;
					case	1 :
						if ( F.verbose > 1 )
							printf("FORWARD PROC %s\n",F.token);
						break;
					case	2 :
						if ( F.verbose > 1 )
							printf("EXTERN PROC %s\n",F.token);
						break;
					}
				if ( F.modifier ) {
					F.state = 0;
					F.modifier = 0;
					}
				else	{
					F.state = 2;
					}
				break;
			case	2 :
				if ( compare( F.token, "ENDPROC" ) ) {
					close_code(&files);
					F.state = 0;
					}
				else if ( compare( F.token, "CALL" ) )
					F.state = 3;
				else if ( compare( F.token, "#INCLUDE" ) )
					F.state = 4;
				break;
			case	3 :
				if ( F.verbose > 1 )
					printf("\tCALL %s\n",F.token);
				add_call(&files, F.token,_code_procedure );
				F.state = 2;
				break;

			case	4 :
				if ( F.verbose  )
					printf("\t#INCLUDE %s\n",F.token);
				add_include(&files, F.token );
				F.state = 2;
				break;


			case	10 :
				switch ( F.modifier ) {
					case	0 :
						if ( F.verbose > 1 )
							printf("SEGMENT %s\n",F.token);
						add_code(&files, F.token,_code_segment);
						break;
					case	1 :
						if ( F.verbose > 1 )
							printf("FORWARD SEGMENT %s\n",F.token);
						break;
					case	2 :
						if ( F.verbose > 1 )
							printf("EXTERN SEGMENT %s\n",F.token);
						break;
					}
				if ( F.modifier ) {
					F.state = 0;
					F.modifier = 0;
					}
				else	{
					F.state = 11;
					}
				break;

			case	11 :
				if ( compare( F.token, "ESEG" ) ) {
					close_code(&files);
					F.state = 0;
					}
				else if ( compare( F.token, "CALL" ) )
					F.state = 13;
				else if ( compare( F.token, "LDGO.SEG" ) )
					F.state = 14;
				else if ( compare( F.token, "#INCLUDE" ) )
					F.state = 16;
				break;

			case	13 :
				if ( F.verbose > 1 )
					printf("\tCALL %s\n",F.token);
				add_call(&files, F.token,_code_procedure );
				F.state = 11;
				break;

			case	14 :
				if ( F.verbose > 1 )
					printf("\tLDGO.SEG %s\n",F.token);
				add_call(&files, F.token,_code_segment );
				F.state = 11;
				break;
			case	16 :
				if ( F.verbose )
					printf("\t#INCLUDE %s\n",F.token);
				add_include(&files, F.token );
				F.state = 2;
				break;

			}
		return(1);
		}
}


private	int	get_token()
{
	int	c;
	if (!(c = push_white_space() ))
		return(0);
	else if ( is_token_legal( c ) )
		return( collector(c) );
	else 	return( punctuate(c) );
}


char	wbuffer[256];

char *	globalextension=(char *) 0;

public	void	set_global_extension(char * sptr)
{
	globalextension = sptr;
	return;
}

private	char *	add_extension(char * nptr )
{
	if (!( globalextension ))
		sprintf(wbuffer,"%s.s",nptr);
	else 	sprintf(wbuffer,"%s.%s",nptr,globalextension);
	return( wbuffer );
}

private	int	analyseit(char *nptr)
{
	int	status;
	int	c;
	F.hitcount=0;
	F.ungot=0;
	if ( F.verbose  )
		printf("\nfile : %s \n",nptr);

	if ((!(F.source = fopen( nptr, "r")))
	&&  (!(F.source = fopen((nptr = add_extension(nptr)), "r"))))
		return(40);
	else	{
		F.ungot = 0;

		add_file(&files, nptr );

		/* handle initial star comment */
		while ((c = push_white_space()) == '*')
			push_comment('\n');

		ungetch(c);

		while ( get_token() ) ;

		if (( F.verbose > 1 )
		&&  ( F.hitcount))
			printf("\thits : %u ",F.hitcount);

		F.total += F.hitcount;
		F.hitcount = 0;

		fclose(F.source);

		}
}

public	void	initialise_analyser()
{
	reset_list( &files );
	return;
}

public	void	terminate_analyser()
{
	/* liberate_list( &files ); */
	return;
}


#endif	/* _anabal_c */


