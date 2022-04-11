/*
 *	This file provides Data Type Transfer operations into and out
 *	from the Construction/Destruction routines or functions
 *	generated for visual object requirements by SING.
 *
 *	The transfer signatures may be composed of letters defined in
 *	the VWIDGET.H file.
 *
 *	Unrecognised characters are simply ignored and no transfer is
 *	performed.
 */

#include "vwidget.h"
#include "singedit.h"

private	char *	isignature=(char *) 0;
private	char *	osignature=(char *) 0;

private int filecounter=0;

public	void	transfer_signature( char * iptr, char * optr )
{
	char	*	merde="\1merde";
	if ( *merde != 0 ) {
		isignature = iptr;
		osignature = optr;
		}
	return;
}

public	void	visual_signature( char * iptr, char * optr )
{
	isignature = iptr;
	osignature = optr;
	return;
}

public	char *	normalise_method_text( char * eptr )
{
	int	j;
	int	i;
	int	n;
	int	l;
	char *	sptr;
	char *	rptr;
	char *	wptr;
	if (!( sptr = eptr ))	
		return((char *) 0);
	else if (!(l = strlen( eptr  )))
		return((char *) 0);
	else if (!( rptr = allocate( (((l / EDITOR_COLUMNS) + 16)+l) )))
		return( eptr );
	else	{
		wptr = rptr;
		do	{
			if ((n = l) > EDITOR_COLUMNS)
				n = EDITOR_COLUMNS;
			if (!( *eptr ))
				break;
			for ( j=0,i=0; i < n; i++)
				if ((*(rptr+i) = *(eptr+i)) != ' ')
					j=i+1;
			*(rptr+j) = '\n';
			rptr += (j+1);	
			l -= n; eptr += n;
			}
		while ( l > 0 );
		*rptr = 0;
		liberate( sptr );
		return( wptr );
		}
		

}

private	void	string_to_file( FILE * fptr, char * eptr )
{
#ifdef	NO_NORMALISATION
	int	i;
	int	n;
	char	namebuffer[EDITOR_COLUMNS+1];
#endif
	int	l;

	if (( eptr != (char *) 0) 
	&&  ((l = strlen( eptr )) != 0)) {
#ifdef	NO_NORMALISATION
		do	{
			if ((n = l) > EDITOR_COLUMNS)
				n = EDITOR_COLUMNS;
			if (!( *eptr ))
				break;
			for ( i=0; i < n; i++)
				namebuffer[i] = *(eptr+i);
			namebuffer[i] = 0;
			fprintf(fptr,"\t%s\r\n",namebuffer);
			l -= n; eptr += n;
			}
		while ( l > 0 );
#else
		fwrite(eptr,l,1,fptr);
#endif
		}
	return;
}

public	char * file_to_string( char * nptr )
{
	int	filesize=0;
	int	rlen=0;
	int	xlen=0;
	char * rptr=(char *) 0;
	char * wptr=(char *) 0;
	char * xptr=(char *) 0;
	FILE *	h;

	if (!( nptr ))
		return( rptr );
	
	if (!(h	= fopen( nptr, "r" ) ))
		return( rptr );
	
	else if (( wptr = allocate(1024)) != (char *) 0) {
		while ((xlen = fread(wptr,1,1024,h)) > 0 ) {
			if (!( xptr = allocate( (rlen + xlen + 1) )))
				break;
			if ( rlen ) {
				memcpy(xptr,rptr,rlen);
				liberate( rptr );
				}
			if ( xlen )
				memcpy((xptr+rlen),wptr,xlen);
			*(xptr+xlen+rlen)=0;
			rptr =  xptr;
			rlen += xlen;
			if ( xlen < 1024 )
				break;
			}
		liberate( wptr );
		fclose(h);
		return( rptr );
		}
return( rptr );//FCH
}

public	void	filetransferdrop( char * nptr )
{
	if ( nptr ) {	
		unlink( nptr );
		liberate( nptr );
		}
	return;
}

public	void	filetransferout( char ** nptr, char ** pptr )
{
	char *	rptr;

	if ( *nptr != (char *) 0 )
		rptr = file_to_string( *nptr );

	if ( *pptr != (char *) 0)
		liberate( *pptr );

	*pptr = rptr;

	filetransferdrop( *nptr );
	return;
}

public	void	unique_filename(char * buffer)
{
	FILE	*	h=(FILE *) 0;
	while (1) {
#if defined(UNIX)
		sprintf(buffer,"/tmp/%x%u.tmp",time((long*)0),++filecounter);
#elif defined(WIN32)
		sprintf(buffer,"%x-%u.tmp",time((long*)0),++filecounter);
#else
		sprintf(buffer,"%04.1x%04.1x.tmp",((unsigned short)(time((long*)0)&0xFFFF)),((unsigned short)(++filecounter&0xFFFF)));
#endif
		if (!(h = fopen(buffer,"r")))
			break;
		else	fclose(h);
		}
	return;
}

public	void	filetransferin( char ** nptr, char ** pptr )
{
	char	tempname[64];
	FILE *	h;
	char *	sptr;

	/* build a unique filename here */
	unique_filename(tempname);
	/* got a new unique file here */
	*nptr = allocate_string( tempname );
	if (!(h = fopen( tempname,"w" ) ))
		return;
	else 	{
		if ((sptr = *pptr) != (char *) 0 ) 
			string_to_file(h,sptr);
		fclose(h);
		}
	return;
}

public void	visual_transferin( char * tptr, int tlen, char ** pptr )
{
	char *	sptr;
	int	slen;
	long *  lptr;
	unsigned int  *	wptr;
	
	if ( tlen ) {
		if (( isignature != (char *) 0)
		&&  ( *isignature == _SYMBOLIC_TEXTFILE ))
			memset( tptr, 0, sizeof(char*));
		else	memset( tptr, ' ', tlen );
		}

	if ((!( isignature  ))
	||  (!( *isignature ))) {

		if (!( tlen ))
			return;

		if ((  pptr  		!= (char **) 0)
		&&  (( sptr = *pptr ) 	!= (char *) 0)
		&&  (( slen = strlen( sptr )) != 0))
			memcpy(tptr, sptr,(slen > tlen ? tlen : slen));

		}

	else if (!( tlen )) 
		isignature++;
	else	{
		switch ( *(isignature++) ) {
				
			case	_SYMBOLIC_KONSTANT	:
				if (((sptr = (char *) pptr) != (char *) 0) 
				&&  (( slen = strlen( sptr )) != 0))
					memcpy(tptr, sptr,(slen > tlen ? tlen : slen));
				break;
			case	_SYMBOLIC_TEXTFILE	:
				filetransferin((char **) tptr, pptr );
				break;
				
			case	_SYMBOLIC_STRING	:
				if ((  pptr  		!= (char **) 0)
				&&  (( sptr = *pptr ) 	!= (char *) 0)
				&&  (( slen = strlen( sptr )) != 0))
					memcpy(tptr, sptr,(slen > tlen ? tlen : slen));
				break;

			case	_SYMBOLIC_LONG	:
				if ((lptr = (long *) pptr) != (long *) 0)
					sprintf(tptr,"%ld",*lptr);
				break;

			case	_SYMBOLIC_WORD	:
				if ((wptr = (unsigned int *) pptr) != (unsigned int *) 0)
					sprintf(tptr,"%u",*wptr);
				break;

			case	_SYMBOLIC_BYTE	:
				if ((sptr = (char *) pptr) != (char *) 0) 
					*tptr = *sptr;
				break;

			}
		}	
	return;

}

private	void	stringstorage( char * tptr, int tlen, char ** pptr )
{
	char	* sptr;
	char 	* wptr;
	int	slen;
	int	i;

	if (!(  pptr ))
		return;
	else	wptr = *pptr;

	for (slen=0,i=0; i < tlen; i++ )
		if ( *(tptr + i) != ' ')
			slen = (i+1);

	if (!(sptr = allocate( slen+16 )))
		return;

	memcpy( sptr, tptr, slen );

	*(sptr+slen) = 0;

	if ( wptr )
		wptr =liberate( wptr );



	*pptr = sptr;
	return;
}


public void	visual_transferout( char * tptr, int tlen, char ** pptr )
{
	char	* sptr;
	int	* iptr;
	long 	* lptr;
	int	i;


	if ((!( osignature  ))
	||  (!( *osignature ))) {
		if ( tlen )
			stringstorage( tptr, tlen, pptr );
		}
	else if (!( tlen )) 
		osignature++;
	else	{
		switch ( *(osignature++) ) {
			case	_SYMBOLIC_KONSTANT	:
				break;
			case	_SYMBOLIC_TEXTFILE	:
				filetransferout((char **) tptr, pptr );
				break;
				
			case	_SYMBOLIC_STRING	:
				stringstorage( tptr, tlen, pptr );
				break;

			case	_SYMBOLIC_WORD	:
				if ((iptr = (int *) pptr) != (int *) 0) {
					for (*iptr=0,i=0; i < tlen; i++ ) {
						if ((*(tptr+i) >= '0' )
						&&  (*(tptr+i) <= '9' ))
							*iptr = (( *iptr * 10 ) + ( *(tptr+i) - '0' ));
						else	break;
						}
					}
				break;

			case	_SYMBOLIC_LONG	:
				if ((lptr = (long *) pptr) != (long *) 0) {
					for (*lptr=0,i=0; i < tlen; i++ ) {
						if ((*(tptr+i) >= '0' )
						&&  (*(tptr+i) <= '9' ))
							*lptr = (( *lptr * 10 ) + ( *(tptr+i) - '0' ));
						else	break;
						}
					}
				break;

			case	_SYMBOLIC_BYTE	:
				if ((sptr = (char *) pptr) != (char *) 0) 
					*sptr = *tptr;
				break;

			}
		}	

	return;

}

#include "vexpcomp.c"








