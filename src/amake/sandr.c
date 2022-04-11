#include <stdio.h>

struct	replacer {
	int	binary;
	int	keepit;
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
	int	hitcount;
	int	total;
	int	files;
	int	filehits;
	char	commande[1024];
	char	collector[1024];
	char	token[2048];
	} F = { 0, 0, 0, 0, 0, (char *) 0, (char *) 0,0,0,0, (FILE *)0,(FILE*)0,0,0,0,0,0 };

int	replaced(char * aptr, int status)
{
	printf("\n** error : %u : %s **\n",status,aptr);

	if ( F.source ) {
		fclose(F.source );
		F.source = (FILE*) 0;
		}	

	if ( F.target ) {
		fclose(F.target );
		F.target = (FILE*) 0;
		}	

	return(1);
}

int	compare(char * aptr, char * bptr )
{
	int	i;
	for ( i=0; *(aptr+i) != 0; i++ )
		if ( *(aptr+i) != *(bptr+i) )
			return(0);
	if ( *(aptr+i) != *(bptr+i) )
		return(0);
	else	return(1);
}

int	is_token_legal(int c)
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

void	ungetch(int c)
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

int	push_white_space()
{
	int	c;
	while ((c = getch()) != 0) {
		switch (c) {
			case	' '	:
			case	'\t'	:
			case	'\n'	:
			case	'\r'	:
				if ( F.target )
					fprintf(F.target,"%c",c);
				continue;
			}
		break;
		}
	return(c);
}

int	punctuate(int c)
{
	F.token[0] = c;
	F.token[1] = 0;
	return(1);
}

int	convertor()
{
	if ( F.what != (char *) 0 ) {
		if ( compare( F.token,F.what ) ) {
			F.hitcount++;
			if ( F.with != (char *) 0 )
				strcpy(F.token,F.with);
			}
		}
	return( strlen( F.token ) );
}

int	collector( int c )
{
	int	i=0;
	while (1) {
		if (!( is_token_legal(c) )) {
			ungetch(c);
			break;
			}
		else	{

			/* detect and perform case conversion when ignoring case */
			/* ----------------------------------------------------- */
			if (( F.ignore ) &&  ((c >= 'a') && ( c <= 'z' ))) { c -= ('a'-'A'); }
			F.token[i++] = c;
			if (!(c = getch()))
				break;
			}
		}
	if (!( i ))
		return(0);
	else	{ 
		F.token[i++] = 0;
		return( convertor() );
		}
}


int	put_token()
{
	if (!( F.target ))
		return(0);
	fprintf(F.target,"%s",F.token);
	return(0);
}

int	get_token()
{
	int	c;
	if (!(c = push_white_space() ))
		return(0);
	else if ( is_token_legal( c ) )
		return( collector(c) );
	else 	return( punctuate(c) );
}


static	int	RemoveWhiteSpace()
{
	int	c;
	while ((c = getch()) != 0) {
		switch (c) {
			case	' '	:
			case	'\t'	:
			case	'\n'	:
			case	'\r'	:
				if (!( F.collectdex )) {
					if ( F.target )
						fprintf(F.target,"%c",c);
					}
				else	{
					F.collector[F.collectdex++] = c;
					F.collector[F.collectdex]   =0;
					}
				continue;
			}
		break;
		}
	return(c);
}

static	int	GetToken(int c)
{
	int	i=0;
	while (1) {
		if (!( is_token_legal(c) )) {
			break;
			}
		else	{

			/* detect and perform case conversion when ignoring case */
			/* ----------------------------------------------------- */
			if (( F.ignore ) &&  ((c >= 'a') && ( c <= 'z' ))) { c -= ('a'-'A'); }
			F.token[i++] = c;
			if (!(c = getch()))
				break;
			}
		}
	if (!( i ))
		return(0);
	else	{ 
		if ( c != 0 )
			ungetch(c);
		F.token[i++] = 0;
		return(i);
		}

}

static	int	is_white_space( int c )
{
	switch ( c ) {
		case	' ' 	:
		case	'\t'	:
		case	'\r'	:
		case	'\n'	:
			return(1);
		default		:
			return(0);
		}
}

static	int	compare_expressions()
{
	char	*	sptr;
	char	*	xptr;

	xptr = F.what;
	sptr = F.collector;

	while (( *xptr != 0 )
	&&     ( *sptr != 0 )) {
		if ( *xptr != *sptr ) {
			if (!(is_white_space( *xptr )))
				break;
			else if (!( is_white_space( *sptr ))) 
					break;
			else 	{
				while ( is_white_space( *sptr ) )
					sptr++;
				while ( is_white_space( *xptr ) )
					xptr++;
				continue;
				}
			}
		else	{
			xptr++;
			sptr++;
			continue;
			}
		}

	if ((!( *sptr )) 
	&&  (!( *xptr )))  {
		/* ----------- */
		/* Yes Yes Yes */
		/* ----------- */
		F.hitcount++;
		if ( F.target )
			fprintf(F.target,"%s",F.with);

		}
	else if (!( *sptr )) {
		/* it all compares till now so continue */
		/* and collect some more 		*/
		return(0);
		}
	else 	{
		/* --------------------- */
		/* total compare failure */
		/* nothing matches	 */
		/* --------------------- */
		if ( F.target )
			fprintf(F.target,"%s",F.collector);
		}
	F.collector[(F.collectdex=0)] = 0;
	return(0);
}


static	int	UseToken()
{
	strcat(&F.collector[F.collectdex],F.token);
	F.collectdex += strlen( F.token );
	return(compare_expressions());
}

static	int	UsePunctuation(int c)
{
	F.collector[F.collectdex++] = c;
	F.collector[F.collectdex] = 0;
	return(compare_expressions());
}


static	int	expression_parser()
{
	int	c;
	int	status=0;

	F.collector[(F.collectdex=0)] = 0;

	/* Parse until end of source */
	/* ------------------------- */
	while ((c = RemoveWhiteSpace()) != 0) {
		if ( GetToken(c) ) {
			if ((status = UseToken()) != 0)
				break;
			}
		else if ((status = UsePunctuation(c)) != 0)
			break;
		}
	return(status);
}

int	search_and_replace_binary()
{
	return(0);
}


int	replaceit(char *nptr)
{
	int	status;
	int	iteration=1;
	char	tempname[64];
	F.hitcount=0;
	F.ungot=0;

	if ( F.verbose )
		printf("\nfile : %s ",nptr);

	sprintf(tempname,"sandr%x.%u.tmp",time((long *)0),iteration);

	if ( F.binary ) {
		if (!(F.source = fopen( nptr, "rb")))
			return(40);
		}
	else if (!(F.source = fopen( nptr, "r")))
		return(40);

	if (F.doit) {
		while  (( F.target = fopen(tempname,"r")) != (FILE *) 0) {
			fclose(F.target);
			sprintf(tempname,"sandr%x.%u.tmp",time((long *)0),++iteration);
			}
		if ( F.binary ){
			if (!( F.target = fopen(tempname,"wb"))) {
				fclose(F.source);
				return(46);
				}
			else if ( F.verbose )
				printf(" to : %s ",tempname);
			}
		else if (!( F.target = fopen(tempname,"w"))) {
			fclose(F.source);
			return(46);
			}
		else if ( F.verbose )
			printf(" to : %s ",tempname);

		}
	else	F.target = (FILE *) 0;

	F.files++;
	F.files++;
	if (!( F.expression )) {
		if ( F.binary ) {
			status = search_and_replace_binary();
			}
		else	{
			/* standard replace token with token */
			/* --------------------------------- */
			F.ungot = 0;
			while ( get_token() ) 
				if ((status = put_token()) != 0) 
					return(replaced(F.token,status));
			}
		}
	/* extension replace expression with expression */
	/* -------------------------------------------- */
	else if ((status = expression_parser()) != 0)
		return(status );

	if (( F.verbose )
	&&  ( F.hitcount))
		printf("\thits : %u ",F.hitcount);

	F.total += F.hitcount;

	if ( F.hitcount ) { F.filehits++; }

	fclose(F.source);

	if (F.target) {
		fclose(F.target);
		if ( F.doit )  {
			if (!( F.hitcount )) {
				sprintf(F.commande,"rm %s",tempname);
				system(F.commande);
				}
			else	{
				sprintf(F.commande,"mv %s %s.bak",nptr,nptr);
				system(F.commande);
				sprintf(F.commande,"mv %s %s",tempname,nptr);
				system(F.commande);
				}
			}				
		else	{
			sprintf(F.commande,"rm %s",tempname);
			system(F.commande);
			}
		}
	F.hitcount = 0;
	return(0);
}

int	how(char *nptr)
{
	while (*nptr) {
		switch ( *(nptr++) ) {
			case	'I'	:
			case	'i'	:
				F.ignore=1;
				continue;

			case	'X'	:
			case	'x'	:
				F.expression=1;
				continue;

			case	'K'	:
			case	'k'	:
				F.keepit=1;
				continue;

			case	'V'	:
			case	'v'	:
				F.verbose = 1;
				continue;
			case	'E'	:
			case	'e'	:
				F.echo = 1;
				continue;
				
			case	'Y'	:
			case	'y'	:
				F.doit = 1;
				continue;
			
			case	'S'	:
			case	's'	:
				F.what = nptr;
				return(0);

			case	'R'	:
			case	'r'	:
				if (!( *nptr ))
					F.with = " ";
				else	F.with = nptr;

				return(0);

			default		:
				return(30);
			}
		}
	return(0);

}



int	replace(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (!(status = replaceit(aptr)))
				continue;
			else	return( replaced(aptr,status) );
			}
		else if (!(status = how((aptr+1)) ))
			continue;
		else	return( replaced(aptr,status) );
		}
	if ( F.verbose ) {
		printf("\nTotal Number of Files      : %u",	F.files    );
		printf("\nNumber of Files Modified   : %u",	F.filehits );
		printf("\nTotal Number of Occurances : %u\n",	F.total	   );
		}
	return(0);
}
		
int	main(int argc, char * argv[] )
{
	if ( argc == 1 ) {
		printf("\n   SandR : Search and Replace : Version 1.1a.0.02 ");
		printf("\n   Provisoire du 26/11/2003 ");
		printf("\n   Copyright (c) 2003 Amenesik / Sologic \n");
		printf("\n   Usage : \n");
		printf("\n       sandr [ ");
		printf("\n             -s<token>      : search token/expression ");
		printf("\n             -r<token>      : replace by token/expression ");
		printf("\n             -v             : activate messages ");
		printf("\n             -e             : echo sources to stdout ");
		printf("\n             -i             : ignore case ");
		printf("\n             -x             : replace expression ");
		printf("\n             -y             : confirm operation ");
		printf("\n             ] <filelist> \n");
		printf("\n   Examples : \n");
		printf("\n       sandr -stest -ressai -v -y *.as\n\n");
		printf("\n       sandr -x %c-sexpression%c %c-rexpression%c -v -y *.as\n\n",
					0x0022,0x0022,0x0022,0x0022);
		return(0);
		}
	else	return(replace(argc,argv));
}

