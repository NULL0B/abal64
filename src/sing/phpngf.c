#ifndef	_phpngf_c
#define	_phpngf_c

#include "abalngf.h"

private	int	is_abal_ngf( char * tptr )
{
	int	i;
	for ( i=0; abal_ngf_keyword[i] != (char *) 0; i++ )
		if ( upper_compare( abal_ngf_keyword[i] , tptr ) )
			return((i+1));
	return(0);
}

private	char *	abal_php_expression( char * pptr, int * term )
{
	char *	tptr;
	char 	result[8192];
	int	c;
	int	i;
	result[0]=0;
	while (1) {
		if (!(c = abal_get_punctuation())) {
			if (!( tptr = abal_get_token(0))) {
				*term= c;
				return( allocate_string( result ) );
				}
			else	strcat( result, tptr);
			}
		else 	{
			for ( i=0; *(pptr+i) != 0; i++ ) {
				if ( *(pptr+i) == c ) {
					parser_ungetch();
					*term = c;
					return( allocate_string( result ) );
					}		
				}
			i = strlen( result );
			result[i++] = c;
			result[i] = 0;
			}
		}
	*term = 0;
	return( allocate_string( result ) );
}


private	int	abal_php_ngf( FILE * h, char * tptr, int keyword )
{
	int	isendofline=0;
	int	i;
	int	c;
	char *	hx=(char *) 0;
	char *	bx=(char *) 0;
	char *	ex=(char *) 0;
	char *	ax=(char *) 0;
	char *	lx=(char *) 0;
	int	nbavant=0;
	char *	avant[10];
	int	nbapres=0;
	char *	apres[10];

	/* ---------------------------------------------------------------- */
	/* Keyword = Handle [ , parameters ] [ : [ error ] [ parameters ] ] */
	/* ---------------------------------------------------------------- */

	if ((c = abal_get_punctuation()) !=  '=') {
		if ( c ) parser_ungetch();
		return(0);
		}

	else if (!( hx = abal_php_expression(",:",&c) ))
		return(0);

	if ( c == ',' ) {
		while ((c = abal_get_punctuation()) == ',' ) {
			if (!( bx = abal_php_expression(",:",&c) ))
				return(0);
			else	avant[nbavant++] = bx;
			}
		if ( c ) parser_ungetch();
		}
	if ((c = abal_get_punctuation()) !=  ':') {
		if ( c ) parser_ungetch();
		return(0);
		}
	else if ((c = abal_get_punctuation()) !=  '&') {
		if ( c == ':' ) 
			isendofline=1;
		else	{
			if ( c ) parser_ungetch();
			if (!( tptr = abal_get_token(0)))
				return(0);
			else if (!( upper_compare( tptr, "NEXT" ) ))
				return(0);
			else if ((c = parser_getch()) != ',' )
				return(0);
			else if (!( ex = abal_php_expression(",:",&c) ))
				return(0);
			}
		}
	else	{
		/* collect explicite label */
		if (!( tptr = abal_get_token(0)))
			return(0);
		else if (!( lx = allocate_string( tptr ) ))
			return(0);
		else if ((c = parser_getch()) != ',' )
			return(0);
		else if (!( ex = abal_php_expression(",:",&c) ))
			return(0);
		}

	if ( c == ',' ) {
		while ((c = abal_get_punctuation()) == ',' ) {
			if (!( bx = abal_php_expression(",:",&c) ))
				return(0);
			else	apres[nbapres++] = bx;
			}
		if ( c ) parser_ungetch();
		}

	if ( ex ) {
		/* reset error variable */
		/* -------------------- */
		fprintf(h,"\ttry {\n\t");
		abal_php_macro_conversion(h, ex,(char *) 0 );
		fprintf(h," = 0;\n");
		}

	switch ( keyword ) {

		case	_NGF_ASSIGN	:
			fprintf(h,"$this->abal->ngf_ASSIGN(");
			abal_php_macro_conversion(h, hx,(char *) 0  );
			fprintf(h,",");
			abal_php_macro_conversion(h, avant[0],(char *) 0  );
			if ( nbavant > 1 ) {
				fprintf(h,",%c",__QUOTE);
				for (i=1; i < nbavant; i++ ) {
					if ( i > 1 )
						fprintf(h,",");
					fprintf(h,"%s",avant[i]);
					}
				fprintf(h,"%c",__QUOTE);
				}
			else	fprintf(h,",%c%c",__QUOTE,__QUOTE);
			fprintf(h,");\n");
			break;

		case	_NGF_OPEN	:
		case	_NGF_CLOSE	:
		case	_NGF_DFILE	:
			fprintf(h,"$this->abal->ngf_%s(",abal_ngf_keyword[keyword]);
			abal_php_macro_conversion(h, hx,(char *) 0  );
			fprintf(h,");\n");
			break;

		case	_NGF_RENAME	:
			fprintf(h,"$this->abal->ngf_%s(",abal_ngf_keyword[keyword]);
			abal_php_macro_conversion(h, hx,(char *) 0  );
			fprintf(h,",");
			abal_php_macro_conversion(h, avant[0],(char *) 0  );
			fprintf(h,");\n");
			break;

		case	_NGF_READ	:
		case	_NGF_WRITE	:

			fprintf(h,"$this->abal->ngf_%s(",abal_ngf_keyword[keyword]);
			abal_php_macro_conversion(h, hx,(char *) 0  );
			switch ( nbavant ) {
				case	0	:
					fprintf(h,",0,0");
					break;
				case	1	:
					abal_php_macro_conversion(h, avant[0],(char *) 0  );
					fprintf(h,",0");
					break;
				case	2	:
					abal_php_macro_conversion(h, avant[0],(char *) 0  );
					fprintf(h,",");
					abal_php_macro_conversion(h, avant[1],(char *) 0  );
					break;
				}

			switch ( nbapres ) {
				case	0	:
					fprintf(h,","",0");
					break;
				case	1	:
					abal_php_macro_conversion(h, apres[0],(char *) 0  );
					fprintf(h,",0");
					break;
				case	2	:
					abal_php_macro_conversion(h, apres[0],(char *) 0  );
					fprintf(h,",");
					abal_php_macro_conversion(h, apres[1],(char *) 0  );
					break;
				}

			fprintf(h,");\n");
			break;

		}

	/* release expression buffers */
	/* -------------------------- */
	liberate( hx );
	for ( i=0; i < nbavant; i++ )
		liberate( avant[i] );

	if ( ex ) {
		/* catch exception in error variable */
		/* --------------------------------- */
		fprintf(h,"\t} catch ( Exception ");
		abal_php_macro_conversion(h, ex,(char *) 0 );
		liberate( ex );
		fprintf(h," ) { ");

		if ( lx ) {
			fprintf(h,"goto %s;",lx);
			liberate( lx );
			}
		fprintf(h," } \n");
		}

	if ( isendofline ) {
		php_line_termination(h);
		}		

	return(1);
}

	/* --------- */
#endif	/* _phpngf_c */
	/* --------- */





