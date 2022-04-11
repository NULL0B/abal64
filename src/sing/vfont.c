#ifndef	_vfont_c
#define	_vfont_c


#define		VFONT_MAXFILE	256

private	int	fontdimensions[VFONT_MAXFILE][2];
private	int	fontsready=0;
private	int	firstfont=0;
public	void	set_first_font(int v ) { firstfont=v; }

public	int	vfontwidth ( int n ) { return( fontdimensions[n][0] ); }
public	int	vfontheight( int n ) { return( fontdimensions[n][1] ); }


/*	--------------------------------------		*/
/*	V I S U A L _ F O N T ( nptr, nlen )		*/
/*	------------------------------------		*/

public	int	visual_font(char * nptr,int nlen )
{
	int	number=1;
	FILE	* handle;
	int	status = 0;
	int	filesize=0;
	int	width=0;
	int	height=0;
	int	i;
	char *	fnptr;
	char *	buffer=(char *) 0;

	/* Check font name manager for initialisation */
	/* ------------------------------------------ */
	if (!( fontsready )) {
		for (i=0; i < VFONT_MAXFILE; i++ ) {
			fontdimensions[i][0] = 
			fontdimensions[i][1] = 0;
			}
		fontsready=1;
		}		

	/* Check for initialisation of fontpath string */
	/* ------------------------------------------- */
	if (!( system_fontpath ))
		system_fontpath = configuration_item("FONTPATH");
	
	/* Construct normalised font filename */
	/* ---------------------------------- */
#ifdef WIN32

	{
	int ret = 0;

	if (!ret &&  (*nptr == '{' ))
		{
		strcpy(fontbuffer,nptr);
		ret = 1;
		}

	if (!ret && ( system_fontpath ))
		{
		sprintf(fontbuffer,"%s%s",system_fontpath,nptr);
		ret = find_font_byexa( fontbuffer, fontbuffer );
		}

	if (!ret)
		ret = find_font_byexa( nptr, fontbuffer );
	}

#else

	if ( *nptr == '{' )
		strcpy(fontbuffer,nptr);
	else if ( fn_parser( nptr, fontbuffer, 0x0007 ) != 0)
		strcpy(fontbuffer,nptr);
	else if ( system_fontpath )
		sprintf(fontbuffer,"%s%s",system_fontpath,nptr);
	else	strcpy(fontbuffer,nptr);

#endif

	/* Attempt font loading with new font loader */
	/* ----------------------------------------- */
	if (!(number = standard_load_font( fontbuffer )))
		return(number);
	else 	{
		width = guifontsize(number);
		fontdimensions[number][0]=(width & 0x00FF);
		fontdimensions[number][1]=((width << 8) & 0x00FF);
		return( number );
		}
}



#endif	/* _vfont_c */

