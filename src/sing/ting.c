#include <stdio.h>
char *	iptr="/home/abal3/include/";
char *	otr;
char *	exa;
int	generate=0;
int	verbose=0;
unsigned char	tbuffer[80*24];
unsigned char	abuffer[80*24];
unsigned char	fbuffer[80*24];
unsigned char	bbuffer[80*24];
unsigned char	buffer[256];
unsigned char	xbuffer[256];

int	syntax_error(int v)
{
	printf("\n** failure : %u ** \n",v);
	return( v );
}


#include "anating.c"


void	start_program(FILE * h)
{
	fprintf(h,"PROGRAM %c %c\r\n",0x0022,0x0022);
	fprintf(h,"DCL K%c\r\n",0x0025);
	fprintf(h,"SEGMENT 0\r\n");
	return;
}

void	end_program(FILE * h)
{
	fprintf(h,"\tREPEAT :: OP NEXT,K :: UNTIL ( K <> 0)\r\n");
	fprintf(h,"ESEG 0\r\n");
	fprintf(h,"END\r\n");
	return;
}


int	exacute( char * nptr )
{
	int	i;
	sprintf(buffer,"%s",nptr);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".at");
			break;
			}
		}
	if ( verbose )
		printf("translating source : %s\r\n",buffer);
	sprintf(xbuffer,"%s %s",exa,buffer);
	if ( system( xbuffer ) == -1 )
		system_failure( xbuffer );
	return( 0 );
}

int	translate( char * nptr )
{
	int	i;
	sprintf(buffer,"%s",nptr);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".as");
			break;
			}
		}
	if ( verbose )
		printf("translating source : %s\r\n",buffer);
	if ( verbose )
		sprintf(xbuffer,"%s -I%s -m -sas -v %s",otr,iptr,buffer);
	else	sprintf(xbuffer,"%s -I%s -m -sas %s",otr,iptr,buffer);
	if ( system( xbuffer ) == -1) 
		system_failure( xbuffer );

	if ( exa )
		return( exacute( nptr ) );
	else	return( 0 );
}


int	generate_xml_source( char * nomfic )
{
	FILE	*	h;
	int	i;
	sprintf(buffer,"%s",nomfic);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".xml");
			break;
			}
		}
	if ( verbose )
		printf("writing xml source : %s\r\n",buffer);
	if (!( h = fopen( buffer, "w" )))
		return(syntax_error(46));
	else	{
		fclose(h);
		return(0);
		}

}

int	generate_abal_source( char * nomfic )
{
	FILE	*	h;
	int	i;
	sprintf(buffer,"%s",nomfic);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".as");
			break;
			}
		}
	if ( verbose )
		printf("writing abal source : %s\r\n",buffer);
	if (!( h = fopen( buffer, "w" )))
		return(syntax_error(46));
	else	{
		start_program(h);
		end_program(h);
		fclose(h);
		if (!( otr ))
			return( 0 );
		else 	return( translate( nomfic ) );
		}

}

int	generate_visual_source( char * nomfic )
{
	FILE	*	h;
	int	i;
	sprintf(buffer,"%s",nomfic);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".as");
			break;
			}
		}
	if ( verbose )
		printf("writing visual source : %s\r\n",buffer);
	if (!( h = fopen( buffer, "w" )))
		return(syntax_error(46));
	else	{
		fprintf(h,"#user visual\r\n");
		start_program(h);
		fprintf(h,"\tDcl fname$=64\r\n");
		fprintf(h,"\tDcl fh%c(10)\r\n",0x0025);
		fprintf(h,"\tEndLoc\r\n",0x0025);
		fprintf(h,"\tVisualInitialise(3+512)\r\n");
		fprintf(h,"fname = %cstandard.rgb%c\r\n",0x0022,0x0022);
		fprintf(h,"\tVisualPalette(fname,len$(fname))\r\n");
		fprintf(h,"fname = %cstandard.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(1) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %carial2.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(2) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %carial3.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(3) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %carial4.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(4) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %carial5.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(5) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %carial6.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(6) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %cfont7.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(7) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %cfont8.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(8) = VisualFont(fname,len$(fname))\r\n");
		fprintf(h,"fname = %cfont9.fmf%c\r\n",0x0022,0x0022);
		fprintf(h,"\tfh(9) = VisualFont(fname,len$(fname))\r\n");
		analyse(h,1,1,80,24,tbuffer,0,0);
		end_program(h);
		fclose(h);
		if (!( otr ))
			return( 0 );
		else 	return( translate( nomfic ) );
		}

}

int	generate_print_source( char * nomfic )
{
	FILE * h;
	int	i;
	int	d;
	int	l;
	int	c;
	int	fgbg;
	char	bindex=0;

	sprintf(buffer,"%s",nomfic);

	for (i=0; buffer[i] != 0; i++ ) {
		if ( buffer[i] == '.' ) {
			strcpy(&buffer[i],".as");
			break;
			}
		}
	if ( verbose )
		printf("writing print source : %s\r\n",buffer);
	if (!( h = fopen( buffer, "w" )))
		return(syntax_error(46));
	start_program(h);
	for (l=0; l < 24; l++) {
		fprintf(h,"\tPRINT=1:TAB(1,%u)\r\n",l+1);
		for ( d=-1,bindex=0,c=0; c < 80; c++ ) {
			fgbg = ( (fbuffer[ (l*80)+c ] & 0x00FF) | ( (bbuffer[ (l*80)+c ] & 0x00FF) << 8));
			if ( d == -1 )
				d = fgbg;
				else if ( d != fgbg ) {
				buffer[bindex++]=0;
				fprintf(h,"\tPRINT=1:PAINT(%u,%u),%c%s%c\r\n",
					(d & 0x00FF),((d >> 8) & 0x00FF),
					0x0022,buffer,0x0022);					
				d = fgbg;
				bindex=0;
				}
				buffer[bindex++]=(tbuffer[ (l*80)+c ] & 0x00FF);
			}		
		if ( bindex != 0 ) {
			buffer[bindex++]=0;
			fprintf(h,"\tPRINT=1:PAINT(%u,%u),%c%s%c\r\n",
				(d & 0x00FF),((d >> 8) & 0x00FF),
				0x0022,buffer,0x0022);					
			bindex=0;
			}
		}
	end_program(h);
	fprintf(h,"\tREPEAT :: OP NEXT,K :: UNTIL ( K <> 0)\r\n");
	fprintf(h,"ESEG 0\r\n");
	fprintf(h,"END\r\n");
	fclose(h);
	if (!( otr ))
		return( 0 );
	else 	return( translate( nomfic ) );
}

int	conversion(char * nomfic)
{
	FILE * h;
	int	i;
	int	d;
	int	l;
	int	c;
	int	fgbg;
	char	bindex=0;

	sprintf(buffer,"%s",nomfic);
	if ( verbose )
		printf("loading : %s\r\n",buffer);

	if (!( h = fopen( buffer, "rb" )))
		return(syntax_error(40));
	else 	{
		memset(tbuffer,' ',80*24);
		memset(abuffer, 0,80*24);
		memset(fbuffer, 0,80*24);
		memset(bbuffer, 0,80*24);
		fread(tbuffer,80,24,h);
		fread(abuffer,80,24,h);
		fread(fbuffer,80,24,h);
		fread(bbuffer,80,24,h);
		fclose(h);
		switch ( generate ) {
			case	'p'	:
				return( generate_print_source( nomfic ) );
			case	'x'	:
				return( generate_xml_source( nomfic ) );
			case	'a'	:
				return( generate_abal_source( nomfic ) );
			case	'v'	:
				generate_print_source( nomfic );
				generate_visual_source( nomfic );
				return( generate_print_source( nomfic ) );
			default	  :
				return(0);
			}

		}
}



int	option( char * aptr )
{
	switch ( *(aptr++) ) {
		case	'x'	:
			exa = aptr;
			return(0);
		case	't'	:
			otr = aptr;
			return(0);

		case	'i'	:
			iptr = aptr;
			return(0);

		case	'g'	:

			switch ((generate = *aptr)) {
				case	'a'	:
				case	'x'	:
				case	'p'	:
				case	'v'	:
					return(0);
				default		:
					return( syntax_error( 31 ) );
				}

		case	'v'	:
		case	'V'	:
			verbose++;
			return(0);
		default		:
			return( syntax_error(30) );
		}
}	


int	operation(int argc, char * argv[] )
{
	int	argi;
	char *	aptr;
	int	status=0;

	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if ((status = option( (aptr+1) )) != 0)
				break;
			else	continue;
			}
		else if ((status = conversion( aptr )) != 0)
			break;
		else	continue;
		}
	return(status);

}

int	banner()
{
	printf("\n   Abal Text Screen Conversion Utility : Version 1.0a.0.01 ");
	printf("\n   Provisoire du 21/04/2004 ");
	printf("\n   Copright (c) 2004,2006 Amenesik / Sologic \n\n");
	return(0);
}


int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation(argc,argv) );
}

