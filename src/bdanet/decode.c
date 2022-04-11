#include <stdio.h>

char	SourceBuffer[2048];
char	TargetBuffer[2048];

int	echoin=0;
int	echout=0;

#include "base64.c"

int	sgetch( FILE * handle )
{
	int	c;
	if ((c = fgetc( handle )) > 0)
		if ( echoin )
			printf("%c",c);
	return(c);
}

int	triteline( FILE * handle, int nb )
{
	int	i;
	for (i=0; i < nb; i++) {
		if ( echout )
			printf("%02.1X ",TargetBuffer[i]);
		fputc((TargetBuffer[i] & 0x00FF) , handle );
		}
	return(i);
}

int	sreadline( FILE * handle )
{
	int	i,c;
	for (	i=0;
		i<2048;
		i++ ) {
		while ((c=sgetch(handle)) == 13);
		if ( c == 10 ) break;
		else	SourceBuffer[i] = c;
		}
	SourceBuffer[i] = 0;
	return(i);
}

void	decodefile( char * snptr, char * tnptr )
{
	FILE * 	shandle;
	FILE * 	thandle;
	char far * 	sbptr = SourceBuffer;
	char far * 	tbptr = TargetBuffer;
	int	sblen,fwlen;
	signed short int tblen;

	if ( *snptr == '?' )
		echoin = *(snptr++);

	if ( *tnptr == '?' )
		echout = *(tnptr++);

	if ((shandle = fopen( snptr, "rb"))) {

		if ((thandle = fopen( tnptr, "wb"))) {
	
			while (((sblen = sreadline( shandle )) != 0 )
			&&     ( DecodeBase64(sbptr,TargetBuffer, & tblen ) == 0 )
			&&     ((fwlen = triteline(thandle,tblen)) == tblen));

			fclose( thandle );
			}

		else	printf("\nerror creating targetfile:%s \n",tnptr);

		fclose( shandle );
		}

	else	printf("\nerror opening sourcefile:%s \n",snptr);
	return;
}

int main( int argc, char * argv[] )
{
	FILE * handle;
	int	argi;
	switch ( argc ) {

		case	3 :
			decodefile( argv[1] ,argv[2] );
			break;
			
		default	  :	printf("\n   ZAP, Decode Base 64 : Version 1.1a");
				printf("\n   Provisoire du 18/08/1999 ");
				printf("\n   Copyright (c) Amenesik / Sologic ");
				printf("\n   Usage : decode sourcefile targetfile \n");
				break;
		}
	return(0);
}

