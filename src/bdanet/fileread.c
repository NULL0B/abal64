int	FileIndent=0;
char	FileBuffer[256];

int	FileOpen( nptr, option )
char *  nptr;
int     option;
{
	int	handle;
	if ((handle = open( nptr, option )) >= 0 )
		FileIndent = 256;		
	return( handle );
}

int    FileRead( handle, buffer, length )
int	handle;
char *  buffer;
int     length;
{
	int	status;
	int	xfer=0;
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

int	FileClose( handle )
int	handle;
{
	close( handle );
	return(0);
}

