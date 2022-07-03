/*
 *
 *              E X E C U T E U R       A . B . A . L
 *              -------------------------------------
 *
 *              Copyright (c) 1987,2002 Amenesik / Sologic
 *
 *              Module  :       EXCLF3.C
 *              Version :       5.1a
 *              Date    :       14/10/2022
 */

#ifndef _EXCLF3_C
#define _EXCLF3_C

/*	-----------	*/
/*	clf3_string	*/
/*	-----------	*/
VOID	clf3_string(BPTR vptr, EXAWORD vlen)
{
	while ( vlen-- )
		x_putch( *(vptr++) & 0x00FF );	
	return;
}

/*	-----------	*/
/*	 clf3_word	*/
/*	-----------	*/

VOID	clf3_word(EXAWORD value)
{
	BYTE	vptr[64];
	sprintf(vptr,"%llu",value);
	clf3_string(vptr,strlen(vptr));
	return;
}

/*	----------------------------------------------------	*/
/*			c l f 3 _ c o l o r			*/
/*	----------------------------------------------------	*/
/*	DisplayColor( number%, red%, green%, blue%, alpha% )	*/
/*	----------------------------------------------------	*/
EXAWORD	clf3_color()
{
	EXAWORD	number=0;
	EXAWORD	red=0;
	EXAWORD	blue=0;
	EXAWORD	green=0;
	EXAWORD	alpha=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 );

	// colour number
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else 	number = workval2;
	
	// red value
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	red = workval2;

	// green value
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	green = workval2;
	
	// blue value
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	blue = workval2;

	// alpha value
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	alpha = workval2;

	// generate the palette colour
	x_putch(27);
	x_putch('H');
	clf3_word(number);
	x_putch(':');
	clf3_word(red);
	x_putch(':');
	clf3_word(green);
	x_putch(':');
	clf3_word(blue);
	x_putch(':');
	if ( alpha >= 100 )
	{
		x_putch('1');
	}
	else
	{
		x_putch('0');
		x_putch('.');
		clf3_word(alpha);
	}
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_label	*/
/*	----------	*/

EXAWORD	clf3_label()
{
	EXAWORD	atcol=0;
	EXAWORD	atlin=0;
	EXAWORD	nbcol=0;
	EXAWORD	nblin=0;
	EXAWORD	fsize=0;
	BPTR	aptr;
	EXAWORD	alen=0;
	BPTR	nptr;
	EXAWORD	nlen=0;
	BPTR	mptr;
	EXAWORD	mlen=0;
	BPTR	fptr;
	EXAWORD	flen=0;
	BPTR	bptr;
	EXAWORD	blen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 );

	// column position
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	atcol = workval2;
	
	// line position
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	atlin = workval2;

	// column count
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	nbcol = workval2;
	
	// line count
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	nblin = workval2;

	// font size
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	fsize = workval2;
	
	// family
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	{ nptr = workptr2; nlen = lenuze(workptr2,worklen2); }

	// align
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ aptr = workptr2; alen = lenuze(workptr2,worklen2); }

	// foreground colour
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	{ fptr = workptr2; flen = lenuze(workptr2,worklen2); }

	// back ground
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ bptr = workptr2; blen = lenuze(workptr2,worklen2); }

	// message
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	{ mptr = workptr2; mlen = lenuze(workptr2,worklen2); }

	if (!( x_esc_option( 'X' ) )) return( GOODRESULT ); 

	// generate ESC f cursor position 

	if ( (atcol > 0) && ( atlin > 0))
	{
		x_putch(27);
		x_putch('f');
		x_putch(atcol+0x001F);
		x_putch(atlin+0x001F);
	}	

	// generate ESC X Label

	x_putch(27);
	x_putch('X');
	clf3_word(nbcol);
	x_putch(',');
	clf3_word(nblin);
	x_putch(',');
	clf3_word(fsize);
	x_putch(',');
	clf3_string(nptr,nlen);
	x_putch(',');
	clf3_string(aptr,alen);
	x_putch(',');
	clf3_string(fptr,flen);
	x_putch(',');
	clf3_string(bptr,blen);
	x_putch(',');
	clf3_string(mptr,mlen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_image	*/
/*	----------	*/

EXAWORD	clf3_image()
{
	EXAWORD	atcol=0;
	EXAWORD	atlin=0;
	EXAWORD	nbcol=0;
	EXAWORD	nblin=0;
	EXAWORD	option=0;
	BPTR	uptr;
	EXAWORD	ulen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// column position
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	atcol = workval2;
	
	// line position
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	atlin = workval2;

	// column count
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	nbcol = workval2;
	
	// line count
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	nblin = workval2;

	// option
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	option = workval2;
	
	// image URL
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	{ uptr = workptr2; ulen = lenuze(workptr2,worklen2); }

	if (!( x_esc_option( 'I' ) )) return( GOODRESULT ); 

	// generate ESC f cursor position 

	if ( (atcol > 0) && ( atlin > 0))
	{
		x_putch(27);
		x_putch('f');
		x_putch(atcol+0x001F);
		x_putch(atlin+0x001F);
	}	

	// generate ESC I Image

	x_putch(27);
	x_putch('I');
	clf3_word(nbcol);
	x_putch(',');
	clf3_word(nblin);
	x_putch(',');
	clf3_word(option);
	x_putch(',');
	clf3_string(uptr,ulen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_video	*/
/*	----------	*/

EXAWORD	clf3_video()
{
	EXAWORD	atcol=0;
	EXAWORD	atlin=0;
	EXAWORD	nbcol=0;
	EXAWORD	nblin=0;
	EXAWORD	option=0;
	BPTR	uptr;
	EXAWORD	ulen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// column position
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	atcol = workval2;
	
	// line position
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	atlin = workval2;

	// column count
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	nbcol = workval2;
	
	// line count
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	nblin = workval2;

	// option
        if (!( desc & 0x0001 )) 
		return(SOFTERROR);
	else	desc = (EXAWORD) *(adex++);

        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	option = workval2;
	
	// video URL
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	{ uptr = workptr2; ulen = lenuze(workptr2,worklen2); }

	if (!( x_esc_option( 'V' ) )) return( GOODRESULT ); 

	// generate ESC f cursor position 

	if ( (atcol > 0) && ( atlin > 0))
	{
		x_putch(27);
		x_putch('f');
		x_putch(atcol+0x001F);
		x_putch(atlin+0x001F);
	}	

	// generate ESC V video

	x_putch(27);
	x_putch('V');
	clf3_word(nbcol);
	x_putch(',');
	clf3_word(nblin);
	x_putch(',');
	clf3_word(option);
	x_putch(',');
	clf3_string(uptr,ulen);
	x_putch(';');
	return( GOODRESULT );
}

/*	-----------	*/
/*	clf3_upload	*/
/*	-----------	*/

EXAWORD	clf3_upload()
{
	BPTR	uptr;
	EXAWORD	mode;
	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;
	// upload window state (0 or 1)
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else if (!( x_esc_option( '!' ) )) 
		return( GOODRESULT ); 
	else
	{
		x_putch(27);
		x_putch('!');
		x_putch(workval2+'0');
		return( GOODRESULT );
	}
}


/*	----------	*/
/*	clf3_popup	*/
/*	----------	*/

EXAWORD	clf3_popup()
{
	BPTR	uptr;
	EXAWORD	plen=0;
	EXAWORD	ulen=0;
	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// URL for Popup Window
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ uptr = workptr2; ulen = lenuze(workptr2,worklen2); }
	
	// generate ESC T ESC U popup

	plen = ulen + 3;
	x_putch(27);
	x_putch('T');
	x_putch(plen & 0x00FF);
	x_putch((plen >> 8) & 0x00FF);
	x_putch(27);
	x_putch('U');
	clf3_string(uptr,ulen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_size 	*/
/*	----------	*/

EXAWORD	clf3_size()
{
	EXAWORD	nbcol=0;
	EXAWORD	nblin=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// column count
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	nbcol = workval2;
	
	// line count
        if (!( desc & 0x0010 )) 
		return(SOFTERROR);
        else if ( argset(((desc & 0x0006) >> 1),0,2) == SOFTERROR ) 
                return(SOFTERROR);
	else	nblin = workval2;

	if (!( x_esc_option( 'N' ) )) return( GOODRESULT ); 

	// generate ESC N Window Size

	x_putch(27);
	x_putch('N');
	clf3_word(nblin);
	x_putch(',');
	clf3_word(nbcol);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_font	*/
/*	----------	*/

EXAWORD	clf3_font()
{
	BPTR	uptr;
	EXAWORD	ulen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// Font Family
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ uptr = workptr2; ulen = lenuze(workptr2,worklen2); }
	
	if (!( x_esc_option( 'Y' ) )) return( GOODRESULT ); 

	// generate ESC Y Text Font

	x_putch(27);
	x_putch('Y');
	clf3_string(uptr,ulen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_fore	*/
/*	----------	*/

EXAWORD	clf3_fore()
{
	BPTR	cptr;
	EXAWORD	clen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// Font Family
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ cptr = workptr2; clen = lenuze(workptr2,worklen2); }
	
	if (!( x_esc_option( 'R' ) )) return( GOODRESULT ); 

	// generate ESC R sequence

	x_putch(27);
	x_putch('R');
	clf3_string(cptr,clen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	clf3_back	*/
/*	----------	*/

EXAWORD	clf3_back()
{
	BPTR	cptr;
	EXAWORD	clen=0;

	EXAWORD desc=0;

	BPTR	adex;
	adex = fdex; 
	while ( *(fdex++) & 1 ) ;

	// Font Family
	desc = (EXAWORD) *(adex++);
        if ( argset(((desc & 0x0060) >> 5),0,2) == SOFTERROR )
                return(SOFTERROR);
	else	{ cptr = workptr2; clen = lenuze(workptr2,worklen2); }
	
	if (!( x_esc_option( 'S' ) )) return( GOODRESULT ); 

	// generate ESC S sequence

	x_putch(27);
	x_putch('S');
	clf3_string(cptr,clen);
	x_putch(';');
	return( GOODRESULT );
}

/*	----------	*/
/*	  f_clf3	*/
/*	----------	*/

EXAWORD f_clf3( EXAWORD opcode )
{
        switch ( opcode ) 
	{
        case    4       : return( clf3_label() );
        case    5       : return( clf3_image() );
        case    6       : return( clf3_video() );
        case    7       : return( clf3_popup() );
        case    8       : return( clf3_size() );
        case    9       : return( clf3_font() );
        case    10      : return( clf3_fore() );
        case    11      : return( clf3_back() );
        case    12      : return( clf3_color() );
        case    13      : return( clf3_upload() );
        default         : err_val = 56; return( SOFTERROR );
        }
}

#endif	/* _EXCLF3_C */

