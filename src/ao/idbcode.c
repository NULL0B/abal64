#ifndef	_idbcode_c
#define	_idbcode_c

#define	ABAL12
#define	ABAL14
#define	ABAL21
#define VISUAL_DEBUGER

#include "aotcode.c"		/* AO Tcode List routines 		*/


BPTR	StreamBuffer=(BPTR) 0;
EXAWORD	StreamCno=0;
EXAWORD	StreamLno=0;
EXAWORD	StreamNbl=0;
EXAWORD	StreamNbc=0;

EXAWORD	TOGLOBAL=0;
EXAWORD	ISLOCAL=0;
EXAWORD	statix=0;
EXAWORD	IDBWORDSIZE=0;
extern	EXAWORD	LastTcode;
BYTE	ControlZone[256];

EXAWORD	TcodeGetWord( BPTR mptr )
{
	EXAWORD	v=0;
	if ( IDBWORDSIZE > 2 ) {
		v = 	(	(*mptr & 0x00FF) 
			| 	(( *(mptr+1) & 0x00FF ) << 8)
			|	(( *(mptr+2) & 0x00FF ) << 16)
			|	(( *(mptr+3) & 0x00FF ) << 24));

		}
	else	{
		v = 	(	(*mptr & 0x00FF) | (( *(mptr+1) & 0x00FF ) << 8));
		}
	return( v );
}

void	StreamTarget(BPTR sptr, EXAWORD nbl, EXAWORD nbc)
{
	StreamBuffer = sptr;
	StreamLno = StreamCno = 0;
	StreamNbl = nbl;
	StreamNbc = nbc;
	return;
}

void	StreamLine()
{
	if ( StreamLno < StreamNbl ) {
		while ( StreamCno < StreamNbc ) {
			StreamByte(' ');
			}
		StreamBuffer += StreamNbc;
		StreamCno = 0;
		StreamLno++;
		}
	return;
}

void	StreamByte( EXAWORD c )
{
	if ( StreamLno < StreamNbl ) {
		if ( StreamCno < StreamNbc ) {
			*(StreamBuffer+StreamCno) = (c & 0x00FF);
			StreamCno++;
			}
		}
	return;
}

void	StreamString( BPTR mptr )
{
	if ( mptr != (BPTR) 0)
		while ( *mptr )
			StreamByte( *(mptr++) );
	return;
}

void	DecimalWord( EXAWORD v)
{
	BYTE	buffer[32];
	if ( IDBWORDSIZE > 2 )
		sprintf(buffer,"%lu",v);
	else	sprintf(buffer,"%u",(v &0x0FFFF));
	StreamString( buffer );
	return;
}

void	HexWord( EXAWORD v)
{
	BYTE	buffer[32];
	EXAWORD	n,l;
	if ( IDBWORDSIZE > 2 )
		sprintf(buffer,"%lx",v);
	else	sprintf(buffer,"%x",(v&0x0FFFF));
	n = (IDBWORDSIZE * 2);
	for ( l=strlen(buffer); l < n; l++ )
		StreamByte('0');
	StreamString( buffer );
	return;
}

void	HexaOctet( EXAWORD v )
{
	BYTE	buffer[8];
	sprintf(buffer,"%x",(v&0x000FF));
	if ( strlen(buffer) < 2 )
		StreamByte('0');
	StreamString( buffer );
	return;
}

extern	BPTR	fdex;
extern	BPTR	TcodeSegment;
extern	BPTR	TcodeConstants;
extern	BPTR	GlobalConstants;

EXAWORD	Disassembler(char * buffer, EXAWORD blen,EXAWORD nblin, EXAWORD nbcol )
{
	BPTR	sptr=TcodeSegment;
	EXAWORD	whoops=0;
	EXAWORD	si;
	EXAWORD	bytes=0;
	EXAWORD	l;

	TOGLOBAL 	= get_to_global();
	ISLOCAL  	= get_is_local();
	IDBWORDSIZE	= get_word_size();

	si = (fdex - TcodeSegment);
	if ( LastTcode != MOINS_UN )
		if ( si > 0 )
			si--;
	
	StreamTarget(buffer,nblin,nbcol);
	while ( StreamLno < StreamNbl ) {
		if ((*(sptr+si) == _tc_NOP )
		&&  ( LastTcode != MOINS_UN )) {
			*(sptr+si) = (LastTcode | 0x0080);
			whoops = 1;
			}
		else	whoops = 0;
		bytes = TcodeList(sptr, si , 0  );
		if ( whoops ) *(sptr+si) = _tc_NOP;
		if (!( bytes ))	break;
		else	{
			si += bytes;
			}
		}
	return(0);
}


#endif	/* _idbcode_c */
	/* ---------- */


