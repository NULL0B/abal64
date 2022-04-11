unsigned char 	basefontbuffer[8192];
unsigned char * textfontbuffer=(BPTR) 0;
unsigned short	textfontsize=0;
unsigned short	textfontwidth=10;
unsigned short	textfontheight=23;
unsigned short  cellwidth=10;
unsigned short  cellheight=10;

int	extractint( char * bptr )
{
	return( ( 
		 (* bptr    & 0x00FF) +
		((*(bptr+1) & 0x00FF) << 8 )
		)
		);
}

int	loadbasefont( char * nptr )
{
	FILE	* handle;
	int	status = 0;
	if ((handle = fopen( nptr, "rb")) != (FILE *) 0) {
		if ( fread(basefontbuffer,8192,1,handle) == 1 ) {
			cicofont( basefontbuffer );
			use_base_font(0);
			}
		else	status = -1;
		fclose( handle );
		}			
	else	status = -1;
	return( status );
}

void	loadtextfont( char * nptr )
{
	FILE	* handle;
	int	status = 0;
	if ((handle = fopen( nptr, "rb")) != (FILE *) 0) {
		if ( fread(basefontbuffer,256,1,handle) == 1 ) {
			textfontsize = extractint( (basefontbuffer+16) );
			if ((textfontbuffer = allocate( textfontsize )) != (BPTR) 0 ) {
				memcpy( textfontbuffer, basefontbuffer, 256 );
				if ( fread((textfontbuffer+256),(textfontsize - 256),1,handle) != 1 ) {
					textfontbuffer = liberate( textfontbuffer );
					textfontsize   = 0;
					}
				}
			}
		fclose( handle );
		}
	return;
}


int	start_graphics()
{
	load_palette( "standard.rgb" );
	loadtextfont( "textfont.fmf" );

	calculate_server_conversion();

	if ( loadbasefont( "font8025.bmf" ) == -1 )
		return(0);

	// Calculate screen character and font dimensions
	// ----------------------------------------------
	if (( textfontsize )
	&&  ( textfontbuffer != (BPTR) 0)) {
		cellwidth  = textfontwidth  = extractint( (textfontbuffer+20) );
		cellheight = textfontheight = extractint( (textfontbuffer+18) );
		loadguifont( 1, textfontbuffer, textfontsize );
		use_base_font(1);
		}

	InitialRequest = 1;
	cicocolour(4,7);
	cicocurser(1,1);
	return(1);

}

