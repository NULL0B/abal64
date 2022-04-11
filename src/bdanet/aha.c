#ifndef	_aha_c
#define	_aha_c

#include <stdio.h>

static	char 	StubName[256];
static	char 	SourceName[256];
static	char 	ProgramName[256];
static	char *	TranslatorName="/opt/prologue/bin/otr32";
static	char *	RuntimeName="/opt/prologue/bin/exa32";
static	char *	CicoVariable="cgi:/opt/prologue/lib/cico:1";
static	char 	CommandBuffer[1024];

static	int	banner()
{
	printf("\n   Abal Host Apache : Version 1.1a.0.01");
	printf("\n   Provisoire du 24/02/2006");
	printf("\n   Copyright(c) 2006 Amenesik / Sologic \n\n");
	return(0);
}

static	int	failure(char * message, char * other )
{
	printf("Content-Type: text/plain\r\n\r\nAbalHostApache:%s:%s\r\n",message,other);
	return(0);
}

int main(int argc, char * argv[])
{
	int	state=1;
	int	c;
	FILE * 	s;
	FILE * 	h;

	if ( argc == 1 )
		return( banner() );

	sprintf(StubName,"/tmp/aha%u",getpid());
	sprintf(SourceName,"%s.as",StubName);
	sprintf(ProgramName,"%s.at",StubName);
	if (!( s = fopen( argv[1] ,"r" )))
		return( failure("error opening file", argv[1]) );
	else if (!( h = fopen( SourceName,"w" )))
		return( failure("error creating",SourceName) );
	else	{
		state = 0;
		while ((c = fgetc(s)) > 0 ) {
			switch ( state ) {
				case	0 :
					if ( c == '#' ) state++;
					continue;
				case	1 :
					if ( c == '!' )
						state++;
					else if ( state == '#' )
						state++;
					else	{
						fputc('#',h);
						fputc(c,h);
						state = 3;
						}
					continue;
				case	2 :
					if ( c == '\n' )
						state++;
					continue;
				case	3 :
					fputc(c,h);
					continue;
				}	
			}
		fclose(h);
		fclose(s);
		sprintf(CommandBuffer,"%s -sas -d%s %s",TranslatorName,ProgramName,SourceName);
		if (!( system(CommandBuffer) )) {
			sprintf(CommandBuffer,"export GRAPHOFF=1; export CICO=%s; %s %s",CicoVariable,RuntimeName,ProgramName);
			if (!( system(CommandBuffer) ))
				return(0);
			else	return(failure("Execution Failure",CommandBuffer) );
			}
		else	return(failure("Translation Failure",CommandBuffer) );
		}
}

#endif	/* _aha_c */
	/* ------ */


