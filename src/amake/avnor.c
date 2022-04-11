#ifndef	_avnor_c
#define	_avnor_c

#include <stdio.h>

int	verbose=0;
int	verify=0;
int	update=0;

#include "avnfile.h"

int	banner()
{
	printf("\n   Abal Non Regression Check : Version 1.0a.0.05 ");
	printf("\n   Provisoire du 22/10/2004 ");
	printf("\n   Copyright (c) 2003,2004 Amenesik / Sologic \n");
	printf("\n   Syntax : \n");
	printf("\n          avnor [ -v | -u | -x ] newfile reference \n");
	printf("\n          -v        : verify non regression ");
	printf("\n          -x        : trace differences     ");
	printf("\n          -u        : update reference      ");
	printf("\n          -i        : inhibit information   \n\n");
	return(0);
}

int	failure(int v)
{
	if ( v )
		printf("** error : file check : %u **\n",v);
	else	printf("success\n");
	return(v);
}

char	workbuffer[1024];
char	sourceline[2048];
char	resultline[2048];

int	perform_update( char * aptr, char * bptr )
{
	sprintf(workbuffer,"cp %s %s",aptr,bptr);
	system( workbuffer );
	return(failure(0));
}

int	get_line( FILE * h, char * rptr, int * nbline )
{
	int	c=0;
	int	i=0;
	int	last=0;
	*nbline += 1;
	while (( c = fgetc(h) ) != -1) {
		if ( c == '\r' )
			continue;
		else if ( c == 0 )
			break;
		else if ( c == '\n' ) {
			if (!( i )) {
				*nbline += 1;
				continue;
				}
			else	break;
			}
		else if ( c == '\t' )
			c == ' ';
		if (( c == ' ' ) && ( last == ' '))
			continue;
		*(rptr+i) = c;
		last = c;
		i++;
		}
	*(rptr+i) = 0;
	return(i);
}

int	whoops( char * aptr, char * sptr, int slin, char * bptr, char * rptr, int rlin )
{
	if ( verify != 2 )
		printf("\n%s(%u):%s\n%s(%u):%s\n",aptr,slin,sptr,bptr,rlin,rptr);
	return(1);
}

int	old_trace(char * aptr, int alin, char * bptr, int blin, int status )
{
	FILE	*	h;
	if (!( h = fopen("avnor.err","w")))	return( failure(status ) );
	else	{
		fprintf(h,"%s %lu 1 avnor file A failure : %u \r\n",aptr,alin,status);
		fprintf(h,"%s %lu 1 avnor file B failure : %u \r\n",bptr,blin,status);
		fclose(h);
		system("aed -tavnor");
		return( status );
		}
}

int	trace(char * aptr, char * bptr, int status )
{
	FILE	*	h;
	int		event=0;
	struct	avnor_diff * dptr;
	if (!( h = fopen("avnor.err","w")))	return( failure(status ) );
	else	{
		for (	dptr=select_difference(12);
			dptr != (struct	avnor_diff *) 0;
			dptr = select_difference(5) ) {
			fprintf(h,"%s %lu 1 event %u.a : %u lines ",aptr,dptr->lline+1,++event,dptr->lines);
			switch ( dptr->type ) {
				case	_AVNOR_MODIFIED : fprintf(h," modified\n"); break;
				case	_AVNOR_INSERTED : fprintf(h," inserted\n"); break;
				case	_AVNOR_DELETED  : fprintf(h," deleted \n"); break;
				}
			fprintf(h,"%s %lu 1 event %u.b : %u lines ",bptr,dptr->rline+1,event,dptr->lines);
			switch ( dptr->type ) {
				case	_AVNOR_MODIFIED : fprintf(h," modified\n"); break;
				case	_AVNOR_INSERTED : fprintf(h," inserted\n"); break;
				case	_AVNOR_DELETED  : fprintf(h," deleted \n"); break;
				}
			}
		fclose(h);
		system("aed -tavnor");
		release_differences();
		return( status );
		}
}



int	old_compare( char * aptr, char * bptr )
{
	FILE * sh;
	FILE * rh;
	int	status=0;
	int	i;
	int	slen;
	int	rlen;
	int	slines=0;
	int	rlines=0;

	printf("%s and %s : ",aptr,bptr);

	if (( sh = fopen( aptr, "r" )) != (FILE *) 0) {
	
		if (( rh = fopen( bptr, "r" )) != (FILE *) 0) {
			while (1) {
				if ((slen = get_line(sh, sourceline, &slines )) != (rlen = get_line( rh, resultline, &rlines ))) {
					status = whoops(aptr,sourceline,slines,bptr,resultline,rlines);
					break;
					}
				else if (!( slen )) {
					status = 0;
					break;
					}
				else	{
					for ( i=0; i < slen; i++ )
						if ( sourceline[i] != resultline[i] )
							break;

					if ( sourceline[i] != resultline[i] ) {
						status = whoops(aptr,sourceline,slines,bptr,resultline,rlines);
						break;
						}
					}
				}
			fclose(sh);	fclose(rh);

			if (!( update )) {
				if ( verify == 2 ) {
					if (!( status ))
						return( failure(0) );
					else	return( old_trace(aptr,slines,bptr,rlines, status) );
					}
				else if (!( status ))	return( failure(0) );
				else			return( failure(6) );
				}
			else	return( perform_update( aptr, bptr ) );
			}
		fclose(sh);
		if (!( update ))
			return( failure(5));
		else	return( perform_update( aptr, bptr ) );
		}
	return( failure(4) );
}

int	compare( char * aptr, char * bptr )
{
	int	status;
	status = difference(aptr,bptr,update);
	if ( verify != 2 ) {
		printf("%s and %s : ",aptr,bptr);
		}
	if (!( update )) {
		if ( verify == 2 ) {
			if (!( status )) {
				printf("%s and %s : ",aptr,bptr);
				return( failure(0) );
				}
			else	return( trace(aptr,bptr,status) );
			}
		else if (!( status ))	return( failure(0) );
		else			return( failure(6) );
		}
	else	return( perform_update( aptr, bptr ) );
}




int	operation( int argc, char * argv[] )
{
	char * 	sname=(char *) 0;
	char *	rname=(char *) 0;
	char *	aptr;
	int	argi;
	for ( argi=1; argi < argc; argi++ ) {
		if (!(aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			switch ( *(aptr+1) ) {
				case	'i'	:
				case	'I'	:
					verbose=2;
					continue;

				case	'u'	:
				case	'U'	:
					if ( verify )
						return(failure(30));
					else	{
						update = 1;
						continue;
						}
				case	'x'	:
				case	'X'	:
					if ( update )
						return(failure(30));
					else	{
						verbose=0;
						verify=2;
						continue;
						}
				case	'v'	:
				case	'V'	:
					if ( update )
						return(failure(30));
					else	{
						verbose=1;
						verify=1;
						continue;
						}
				default		:
					return( failure(1) );
				}
			}
		else if (!( sname ))
			sname = aptr;

		else if (!( rname ))
			rname = aptr;
		else	return( failure(2) );
		}
	if ((!( verify )) && (!( update ))) 
		return(0);
	else if ((!( sname )) || (!( rname )))
		return( failure(3) );
	else	return( compare( sname, rname ) );
	return(0);
}

int	main( int argc, char * argv[] )
{
	if ( argc == 1 )
		return( banner() );
	else	return( operation( argc, argv ) );
}

#endif	/* _avnor_c */










