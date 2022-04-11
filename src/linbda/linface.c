#ifndef	_linface_c
#define	_linface_c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <unistd.h>

struct	linterface {
	FILE * 	handle;
	char *	name;
	int	functions;
	int	maxfunctions;
	int	special;
	} LinFace = { (FILE *) 0, (char *) 0, 0, 0, 0 };

static	void	foot_linterface()
{
	fprintf(LinFace.handle,"\tdesrt.nombre = %u;\n",LinFace.maxfunctions+1);
	fprintf(LinFace.handle,"\treturn((VOID FAR PTR) &desrt);\n");
	fprintf(LinFace.handle,"}\n\n\n");
	return;
}

static	void	head_linterface()
{
	fprintf(LinFace.handle,"#include <stdio.h>\n");
	fprintf(LinFace.handle,"#include <setjmp.h>\n");
	fprintf(LinFace.handle,"#include %cbda.h%c\n",0x0022,0x0022);
	fprintf(LinFace.handle,"BDA\tdesrt;\n");
	fprintf(LinFace.handle,"void _cfltcvt() { return; }\n");
	fprintf(LinFace.handle,"void _cropzeros() { return; }\n");
	fprintf(LinFace.handle,"\nstatic VOID FAR banniere()\n"); 
	fprintf(LinFace.handle,"{\n");
	fprintf(LinFace.handle,"\treturn;\n");
	fprintf(LinFace.handle,"}\n");
	return;
}

int	flush_linterface()
{
	fprintf(LinFace.handle,"\nVOID FAR PTR InitRelais()\n");
	fprintf(LinFace.handle,"{\n");
	fprintf(LinFace.handle,"\tif (rt_init != (VOID FAR PTR) 0L)\n");
	fprintf(LinFace.handle,"\trt_init->ordinaire.signature = BDA_REDIRECT;\n");
	fprintf(LinFace.handle,"\tdesrt.banniere = (VOID (FAR PTR)()) banniere;\n");
	fprintf(LinFace.handle,"\tdesrt.fin = (VOID (FAR PTR)()) 0L;\n");
}

int	close_linterface()
{
	if ( LinFace.handle ) {
		foot_linterface();
		fclose( LinFace.handle );
		LinFace.handle = (FILE *) 0;
		}
	if ( LinFace.name ) {
		free( LinFace.name );
		LinFace.name = (char *) 0;
		}
	return(0);
}

static	char * notwhite( char * nptr )
{
	while (( *nptr == ' ' ) || ( *nptr == '\t' ))
		nptr++;
	return( nptr );
}

static	char *	step_over( char * nptr, int * iptr )
{
	char *	mptr=nptr;
	while ( *nptr != ':' ) {
		if (!( *nptr ))
			break;
		else	nptr++;
		}
	if ( *nptr == ':' ) {
		*iptr = atoi(mptr);
		nptr++;
		}
	else	nptr = mptr;

	nptr = notwhite(nptr);
	while (1) {
		switch ( *nptr ) {
			case	'#'	:
			case	'$'	:
			case	0x0025 	:
				nptr++;
				continue;
			}
		break;
		}
	nptr = notwhite(nptr);

	return( nptr );
}

static	char *	step_past( char * fptr, int * iptr )
{
	while ( *fptr != 0 ) {
		if ( *fptr == '(' )
			break;
		else	fptr++;
		}
	*iptr = *fptr;
	*fptr = 0;
	return( fptr );
}

void	table_linterface( char * nptr )
{
	int	i=LinFace.functions++;
	int	c;
	char *	fptr;
	nptr = step_over( nptr, &i );
	fptr = step_past( nptr, &c );
	if ( i > LinFace.maxfunctions )
		LinFace.maxfunctions = i;
	fprintf(LinFace.handle,"\tdesrt.fonction[%u] = (EXAWORD (FAR PTR)()) Dll_%s;\n",i,nptr);
	*fptr = c;
	return;
}

void	function_linterface( char * nptr )
{
	int	p;
	char *	fptr;
	int	c;
	int	i;
	int	t;
	int	a=0;
	fprintf(LinFace.handle,"\n/* %s */",nptr);
	nptr = step_over( nptr, &i );
	fptr = step_past( nptr, &c );
	fprintf(LinFace.handle,"\nstatic EXAWORD Dll_%s(",nptr);
	*(fptr++) = c;
	if ( LinFace.special ) {
		fprintf(LinFace.handle," VOID FAR PTR FAR pptr[] )");
		}
	else	{
	while (1) {
		p=0;
		fptr = notwhite(fptr);
		switch ((t =  *(fptr++))) {
			case	'$'	:
			case	'*'	:
				p=1;
			case	'#'	:
			case	0x0025	:
			case	'.'	:
				fptr = notwhite(fptr);
				if ( *fptr == '?' ) {
					fptr++;
					p=1;
					}					
				a++;
				switch ( t ) {
					case	'#'	:
					case	0x0025	:
						fprintf(LinFace.handle,"int ");
						break;
					case	'*'	:
					case	'$'	:
						fprintf(LinFace.handle,"char ");
						break;
					}
				if ( p )
					fprintf(LinFace.handle,"* ");
				fprintf(LinFace.handle,"a%u",a);
				continue;
			case	','	:
				fprintf(LinFace.handle,",");
				continue;
			case	')'	:
				fprintf(LinFace.handle,")");
				break;
			default		:
				break;
			}
		break;
		}
		}
	fprintf(LinFace.handle,"\n");
	fprintf(LinFace.handle,"{\n");
	fprintf(LinFace.handle,"\treturn(0);\n");
	fprintf(LinFace.handle,"}\n");
	return;
}

int	open_linterface( char * nptr, int special )
{
	if (!( nptr ))
		return(0);
	else if (!( *nptr ))
		return(0);
	else if (!( LinFace.name = malloc( strlen(nptr) + 1 )))
		return( 27 );
	else	{
		strcpy(LinFace.name,nptr);
		if (!( LinFace.handle = fopen( LinFace.name, "w"))) {
			close_linterface();
			return( 46 );
			}
		else	{
			LinFace.special = special;
			LinFace.functions=0;
			head_linterface();
			return(0);
			}
		}
}


#endif	/* _linface_c */
	/* ---------- */

