#include <stdio.h>

char	buffer[256];

int	mode='p';
int	type='t';

int	convert_html(char * nptr)
{
	FILE * s;
	FILE * h;
	int	c;

	if (!( s = fopen(nptr,"r") ))
		return(40);
	else if (!( h = fopen( "/tmp/html.tmp", "w" ))) {
		fclose(s);
		return(46);
		}
	else	{
		while ((c = fgetc(s)) > 0) {

			if ( mode == 'p' ) {
				switch ( (c & 0x00FF) ) {
					case	0x0085 /* 'Ö' */	:	fprintf(h,"&agrave;"); continue;
					case	0x00A0 /* '†' */	:	fprintf(h,"&aacute;"); continue;
					case	0x0083 /* 'É' */	:	fprintf(h,"&acirc;" ); continue;
					case	0x008A /* 'ä' */	:	fprintf(h,"&egrave;"); continue;
					case	0x0082 /* 'Ç' */	:	fprintf(h,"&eacute;"); continue;
					case	0x0088 /* 'à' */	:	fprintf(h,"&ecirc;" ); continue;
					case	0x008D /* 'ç' */	:	fprintf(h,"&igrave;"); continue;
					case	0x00A1 /* '°' */	:	fprintf(h,"&iacute;"); continue;
					case	0x008C /* 'å' */	:	fprintf(h,"&icirc;" ); continue;
					case	0x0095 /* 'ï' */	:	fprintf(h,"&ograve;" ); continue;
					case	0x00A2 /* '¢' */	:	fprintf(h,"&oacute;" ); continue;
					case	0x0093 /* 'ì' */	:	fprintf(h,"&ocirc;" ); continue;
					case	0x0097 /* 'ó' */	:	fprintf(h,"&ugrave;" ); continue;
					case	0x00A3 /* '£' */	:	fprintf(h,"&uacute;" ); continue;
					case	0x0096 /* 'ñ' */	:	fprintf(h,"&ucirc;" ); continue;
					case	0x0087 /* 'á' */	:	fprintf(h,"&ccedil;" ); continue;
					default		:	fprintf(h,"%c",(c & 0x00FF)); continue;
					}
				}
			else if ( mode = 'a' ) {
				switch ( (c & 0x00FF) ) {
					case	0x00E0	:	fprintf(h,"&agrave;"); continue;
					case	0x00E1	:	fprintf(h,"&aacute;"); continue;
					case	0x00E2	:	fprintf(h,"&acirc;" ); continue;

					case	0x00E8	:	fprintf(h,"&egrave;"); continue;
					case	0x00E9	:	fprintf(h,"&eacute;"); continue;
					case	0x00EA	:	fprintf(h,"&ecirc;" ); continue;

					case	0x00EC	:	fprintf(h,"&igrave;"); continue;
					case	0x00ED	:	fprintf(h,"&iacute;"); continue;
					case	0x00EE	:	fprintf(h,"&icirc;" ); continue;

					case	0x00F2	:	fprintf(h,"&ograve;" ); continue;
					case	0x00F3	:	fprintf(h,"&oacute;" ); continue;
					case	0x00F4	:	fprintf(h,"&ocirc;" ); continue;

					case	0x00E7	:	fprintf(h,"&ccedil;" ); continue;
					default		:	fprintf(h,"%c",(c & 0x00FF)); continue;
					}
				}
			}
		fclose(s); fclose(h);
		sprintf(buffer,"mv %s %s.bak",nptr,nptr);
		system(buffer);
		sprintf(buffer,"mv /tmp/html.tmp %s",nptr);
		system(buffer);
		return(0);
		}

}

int	convert_text(char * nptr)
{
	FILE * s;
	FILE * h;
	int	c;

	if (!( s = fopen(nptr,"r") ))
		return(40);
	else if (!( h = fopen( "/tmp/text.tmp", "w" ))) {
		fclose(s);
		return(46);
		}
	else	{
		while ((c = fgetc(s)) > 0) {

			if ( mode == 'p' ) {
				switch ( (c & 0x00FF) ) {
					case	0x0085 /* 'Ö' */	:	fprintf(h,"%c",0x00E0);  continue;
					case	0x00A0 /* '†' */	:	fprintf(h,"%c",0x00E1);  continue;
					case	0x0083 /* 'É' */	:	fprintf(h,"%c",0x00E2);  continue;
					case	0x008A /* 'ä' */	:	fprintf(h,"%c",0x00E8);  continue;
					case	0x0082 /* 'Ç' */	:	fprintf(h,"%c",0x00E9);  continue;
					case	0x0088 /* 'à' */	:	fprintf(h,"%c",0x00EA);  continue;
					case	0x008D /* 'ç' */	:	fprintf(h,"%c",0x00EC);  continue;
					case	0x00A1 /* '°' */	:	fprintf(h,"%c",0x00ED);  continue;
					case	0x008C /* 'å' */	:	fprintf(h,"%c",0x00EE);  continue;
					case	0x0095 /* 'ï' */	:	fprintf(h,"%c",0x00F2);  continue;
					case	0x00A2 /* '¢' */	:	fprintf(h,"%c",0x00F3);  continue;
					case	0x0093 /* 'ì' */	:	fprintf(h,"%c",0x00F4);  continue;
					case	0x0097 /* 'ó' */	:	fprintf(h,"%c",0x00F9);  continue;
					case	0x00A3 /* '£' */	:	fprintf(h,"%c",0x00FA);  continue;
					case	0x0096 /* 'ñ' */	:	fprintf(h,"%c",0x00FB);  continue;
					case	0x0087 /* 'á' */	:	fprintf(h,"%c",0x00E7);  continue;

					default		:	fprintf(h,"%c",(c & 0x00FF)); continue;
					}
				}
			else if ( mode = 'a' ) {
				switch ( (c & 0x00FF) ) {
					case	0x00E0	:	fprintf(h,"%c",    0x0085	); continue;	
					case	0x00E1	:	fprintf(h,"%c",    0x00A0	); continue;	
					case	0x00E2	:	fprintf(h,"%c",    0x0083	); continue;
					case	0x00E8	:	fprintf(h,"%c",    0x008A	); continue;
					case	0x00E9	:	fprintf(h,"%c",    0x0082	); continue;
					case	0x00EA	:	fprintf(h,"%c",    0x0088	); continue;
					case	0x00EC	:	fprintf(h,"%c",    0x008D	); continue;
					case	0x00ED	:	fprintf(h,"%c",    0x00A1	); continue;
					case	0x00EE	:	fprintf(h,"%c",    0x008C	); continue;
					case	0x00F2	:	fprintf(h,"%c",    0x0095	); continue;
					case	0x00F3	:	fprintf(h,"%c",    0x00A2	); continue;
					case	0x00F4	:	fprintf(h,"%c",    0x0093	); continue;
					case	0x00F9	:	fprintf(h,"%c",    0x0097	); continue;
					case	0x00FA	:	fprintf(h,"%c",    0x00A3	); continue;
					case	0x00FB	:	fprintf(h,"%c",    0x0096	); continue;
					case	0x00E7	:	fprintf(h,"%c",    0x0087	); continue;

					default		:	fprintf(h,"%c",(c & 0x00FF)); continue;
					}
				}
			}
		fclose(s); fclose(h);
		sprintf(buffer,"mv %s %s.bak",nptr,nptr);
		system(buffer);
		sprintf(buffer,"mv /tmp/text.tmp %s",nptr);
		system(buffer);
		return(0);
		}

}

int	convert(char * nptr)
{
	if ( type =='t' )
		return( convert_text( nptr ) );
	else if ( type == 'h' )
		return( convert_html( nptr ) );
	else	return(0);
}

int	option(char * aptr)
{
	if ( *aptr == 'p' )
		mode = *aptr;
	else if ( *aptr == 'a' )
		mode = *aptr;	
	else if ( *aptr == 't' )
		type = *aptr;
	else if ( *aptr == 'h' )
		type = *aptr;

	return(0);
}

int	doit( int argc, char * argv[] )
{
	int	status=0;
	int	argi;
	char *	aptr;
	for (argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr != '-' ) {
			if (!(status = convert(aptr)))
				continue;
			else 	break;
			}
		else if (!( status = option((aptr+1) )))
			continue;
		else	break;	
		}
	return(status);
}

int	banner()
{
	printf("\n   Text Accented Character Conversion : Version 1.1a.0.02");
	printf("\n   Provisoire du 12/10/2004 ");
	printf("\n   Copyright (c) 2003,2004 Amenesik / Sologic \n");
	printf("\n   Syntax : accentconv [ -h ] [ -t ] [ -p ] [ -w ] files");
	printf("\n                -h              : conversion to html macros");
	printf("\n                -t              : conversion of text file  ");
	printf("\n                -p              : conversion from prologue to ansi ");
	printf("\n                -a              : conversion from ansi to prologue \n\n");
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(doit(argc,argv));
}


