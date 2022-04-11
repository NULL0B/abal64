#ifndef	_HTTPFILE_C
#define _HTTPFILE_C

INT	trace_active=0;
INT	TraceHandle=0;

#ifdef	UNIX

extern INT errno;
#define	SocketRead(a,b,c) 	read(a,b,c)
#define	SocketWrite(a,b,c) 	write(a,b,c)
#define	SocketClose(a) 		close(a)
#define	FileOpen(a,b)   	open(a,b)
#define	FileRead(a,b,c) 	read(a,b,c)
#define	FileWrite(a,b,c) 	write(a,b,c)
#define	FileClose(a)	 	close(a)
#define	FileFlush(a)		close(a)
#define	FilePurge(a)		close(a)
#define	FileCreate(a)		creat(a,0666)

	/* ------ */
#else	/* ! UNIX */
	/* ------ */

#ifdef	PROLOGUE

#define	SocketRead(a,b,c) 	sread(a,b,c)
#define	SocketWrite(a,b,c) 	swrite(a,b,c)
#define	SocketClose(a) 		sclose(a)

INT	FileIndent=0;
BYTE	FileBuffer[256];

INT	WriteIndent=0;
BYTE	WriteBuffer[256];


INT	FileOpen( nptr, option )
BPTR  	nptr;
INT     option;
{
	INT	handle;
	if ((handle = open( nptr, option )) >= 0 )
		FileIndent = 256;		
	return( handle );
}

INT	FileCreate( nptr )
BPTR  	nptr;
{
	INT	handle;
	BPTR	pptr;
#ifdef	UNIX
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '\\' )
			*pptr = '/';
		}
	if (*nptr == '/') nptr++;
#endif
#ifdef	PROLOGUE
	for ( pptr = nptr; *pptr; pptr++ ) {
		if ( *pptr == '/' )
			*pptr = '\\';
		}
	if (*nptr == '\\') nptr++;
#endif
	unlink( nptr );
	if ((handle = creat(nptr, 0666)) >= 0 ) {
		close( handle );
		handle = -1;
		if ((handle = open( nptr, (O_RDWR | O_BINARY) )) >= 0 )
			WriteIndent = 0;
		}
	return( handle );
}

INT    	FileRead( handle, buffer, length )
INT	handle;
BPTR  	buffer;
INT     length;
{
	INT	status;
	INT	xfer=0;
	while ( xfer < length ) {
		if ( FileIndent >= 256 ) {
			if ( read( handle, FileBuffer, 256 ) != 256 )
				break;
			else	FileIndent = 0;
			}
		*(buffer++) = FileBuffer[FileIndent++];
		xfer ++;
		}
	return( xfer );
}

INT    	FileWrite( handle, buffer, length )
INT	handle;
BPTR  	buffer;
INT     length;
{
	INT	transfer=0;
	INT	transfered=0;

	if ( handle < 0 )
		return( length );
	while (length > 0) {

		if (WriteIndent >= 256) {
			WriteIndent = 0;
			if ( write( handle, WriteBuffer, 256 ) != 256 )
				break;
			else	memset(WriteBuffer,0x001A,256);
			}

		if ((transfer = (256 - WriteIndent)) > length )
			transfer = length;

		memcpy((WriteBuffer + WriteIndent),buffer,transfer);
		length -= transfer;
		buffer += transfer;
		WriteIndent += transfer;
		transfered += transfer;
		}
	return( transfered );
}


INT	FileClose( handle )
INT	handle;
{
	close( handle );
	return(0);
}

INT	FileFlush( handle )
INT	handle;
{
	if ( handle > 0 ) {
		if ( WriteIndent < 256) 
			memset((WriteBuffer+WriteIndent),0x001A,(256 - WriteIndent));
		(void) write( handle, WriteBuffer, 256 );
		(void) FileClose(handle);
		}
	WriteIndent = 0;
	return( 0 );
}

INT	FilePurge( handle )
INT	handle;
{
	if ( handle > 0 ) {
		if ( WriteIndent > 0 )
			(void) write( handle, WriteBuffer, 256 );
		(void) FileClose(handle);
		}
	WriteIndent = 0;
	return( 0 );
}

	/* -------- */
#endif	/* PROLOGUE */
	/* -------- */
#endif	/* UNIX     */
	/* -------- */

INT	FileGetLine( handle, bptr, blen )
INT	handle;
BPTR 	bptr;
INT	blen;
{
	INT	i=0;
	BYTE	c;
	while ( i < blen ) {
		if ( FileRead(handle, (BPTR) & c, 1) != 1 )
			break;
		else 	{
			switch ( c ) {
				case	'\r'	: continue;
				case	'\n'	: if (!( i )) 
							continue;
				case	0	:
				case	0x001A	: break;
				case	'\t'	: c = ' ';
				default		: *(bptr + i) = c;
						  i++;
						  continue;
				}
			break;
			}
		}
	*(bptr + i) = 0;
	return(i);
}

void	activate_trace( nptr )
BPTR nptr;
{
	if ((TraceHandle = FileCreate( nptr )) > 0)
		trace_active = 1;
	else	{
		TraceHandle = 0;
		trace_active = 0;
		}
	return;
}

void	terminate_trace()
{
	if ( trace_active ) {
		FileFlush( TraceHandle );
		TraceHandle  = 0;
		trace_active = 0;
		}
	return;
}

void	trace_puts( sptr )
BPTR	sptr;
{
	INT	l=strlen(sptr);
	if ( trace_active )
		if ( FileWrite( TraceHandle, sptr, l ) != l)
			terminate_trace();
	return;
}

void	trace_line()
{
	if ( trace_active )
		trace_puts("\r\n");
	return;
}

void	trace_putw( v )
INT	v;
{
	BYTE	buffer[16];
	if ( trace_active ) {
		sprINTf(buffer,"%u",v);
		trace_puts( buffer );
		}
	return;
}





INT	analyse_filetype( nptr )
BPTR	nptr;
{
	INT	i=0;
	for( i = strlen(nptr); i > 0; i-- )
		if ( *(nptr + (i-1)) == '.' )
			break;
	if ( i > 0 ) {
		if (( compare_tokens( (nptr + i), "htm" ) != 0 )
		||  ( compare_tokens( (nptr + i), "html" ) != 0 ))
			return( _HTML_FILE );
		else if ( compare_tokens( (nptr + i), "bmp" ) != 0 )
			return( _BMP_FILE );
		else if ( compare_tokens( (nptr + i), "gif" ) != 0 )
			return( _GIF_FILE );
		else if ( compare_tokens( (nptr + i), "wav" ) != 0 )
			return( _WAV_FILE );
		else if ( compare_tokens( (nptr + i), "mov" ) != 0 )
			return( _MOV_FILE );
		else if ( compare_tokens( (nptr + i), "bmf" ) != 0 )
			return( _BMF_FILE );
		else if ( compare_tokens( (nptr + i), "at" ) != 0 )
			return( _AT_FILE );
		else if ( compare_tokens( (nptr + i), "xp" ) != 0 )
			return( _XP_FILE );
		else if ( compare_tokens( (nptr + i), "exe" ) != 0 )
			return( _EXE_FILE );
		else if ( compare_tokens( (nptr + i), "dns" ) != 0 )
			return( _DNS_FILE );
		else if ( compare_tokens( (nptr + i), "ico" ) != 0 )
			return( _ICO_FILE );
		else if (( compare_tokens( (nptr + i), "jpg" ) != 0 )
		     ||  ( compare_tokens( (nptr + i), "jpeg" ) != 0 ))
			return( _JPEG_FILE );
		}
	return(-1);
}

#endif	/* _HTTPFILE_C */
	/* ----------- */

