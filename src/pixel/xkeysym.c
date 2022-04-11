#ifndef	_xkeysym_c
#define _xkeysym_c

private	unsigned char macrovalue[256] = {

	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,

	0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
	0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F,

	0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
	0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F,

	0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
	0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D, 0x3E, 0x3F,

	0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
	0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,

	0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
	0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F,

	0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
	0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F,

	0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
	0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0xB0,
	
	' ', ' ', 0x2C, 0x9F, 0x22, 0xF7, 0xC5, 0xD8,	/* 80 - 8F */
	0x5E, 0x25, 0x53, 0x3C, 0x99, ' ', ' ', ' ',

	' ', 0x60, 0x27, 0x22, 0x22, 0xF8, 0x2D, 0xC4,
	0x7E, 0x54, 0x73, 0x3E, 0x99, ' ', ' ', 0x98,

	' ', 0xAD, 0x9B, 0x9C, 0x24, 0x9D, 0x7C, 0xD2,	/* A0 - AF */
	0x22, 0x03, 0xA6, 0xAE, 0xAA, 0xF7, 0x12, 0x4D,

	0xF8, 0xF1, 0xFD, 0x33, 0x2F, 0xE6, 0xD2, 0xF9,
	0xF5, 0x31, 0xA7, 0xAF, 0xAC, 0xAB, 0xF0, 0xA8,

	0x41, 0x41, 0x8F, 0x41, 0x8E, 0x41, 0x92, 0x80, /* C0 - CF */
	0x45, 0x90, 0x45, 0x45, 0x49, 0x49, 0x49, 0x49,

	0xE4, 0xA5, 0x4F, 0x4F, 0x4F, 0x4F, 0x99, 0x78,
	0xE9, 0x55, 0x55, 0x55, 0x9A, 0x59, 0xE2, 0xE1,

	0x85, 0xA0, 0x83, 0x61, 0x84, 0x86, 0x91, 0x87, /* E0 - EF */
	0x8A, 0x82, 0x88, 0x89, 0x8D, 0xA1, 0x8C, 0x8B,

	0xE4, 0xA4, 0x95, 0xA2, 0x93, 0x6F, 0x94, 0xF6,
	0xED, 0x97, 0xA3, 0x96, 0x81, 0x79, 0xE2, 0x98
	};

private	int	accentmodifier=0;

/* -------------------------------------------------------- */
/* these functions allow redirection of cyrillic codes to a */
/* different base region of the standard abal font table    */
/* -------------------------------------------------------- */
private	int	CyrillicBase=0x0E0;
private	int	PolishBase=0;

public	void	set_cyrillic_base(int v)
{
	CyrillicBase= (v & 0x00FF);
	return;
}

public	int	get_cyrillic_base()
{
	return( CyrillicBase );
	return;
}
/* -------------------------------------------------------- */
/* end of cyrillic base redirection functions		    */ 
/* -------------------------------------------------------- */

private	int	TranscodeXkeysymbol(XKeyEvent * eptr, int isdown)
{
	int		count;
	KeySym		xkeycode;
	XComposeStatus 	compose;
	char		buffer[64];
	int		bufsize=64;
	count = XLookupString(eptr,buffer,bufsize,
		&xkeycode, & compose );

#ifdef	GIGOXTRACE
		if ( GigoXtrace & 64 )  {
			printf("x key symbol : %u( 0x0%x,%u) \r\n",xkeycode,xkeycode,isdown );
			}
#endif

	switch ( xkeycode ) {
		case  XK_Clear		: // FF0C	*/
			accentmodifier=0;
			return( xgr_usfo(6) );

		case  XK_ISO_Left_Tab	: // 0xFE20 	*/
			accentmodifier=0;
			return(0);

		case  XK_Tab		: // FF09	*/
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_TAB );
			else if (!( XGC.shift ))
				return((xkeycode & 0x007F));
			else if ( isdown )
				return(-1);
			else	return( 0);

		case  XK_BackSpace	: // FF08	back space, back char */
			if ( XGC.control )
				return( 127 );
			else	return( 8 );

		case  XK_KP_Enter	: // FF8D
		case  XK_Return		: // FF0D	Return, enter */
			if ( XGC.control )
				return( 10 );
		case XK_KP_Tab		: // FF89
		case  XK_Linefeed	: // FF0A	Linefeed, LF */

		case  XK_Escape		: // FF1B 	*/
			accentmodifier=0;
			return((xkeycode & 0x007F));

		case XK_KP_Delete	: // FF9F
		case  XK_Delete		: // FFFF Delete, rubout */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_DEL );
			else	return( 0x007F );

		case XK_KP_Home		: // 0xFF95
		case XK_Home		: // 0xFF50		*/
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_HOME );
			else	return( 0x001C );

		case XK_KP_Left		: // FF96
		case XK_Left		: // 0xFF51	 Move left, left arrow */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_LEFT );
			else	return( xgr_usfo(2) );
		case XK_KP_Up		: // FF97
		case XK_Up		: // 0xFF52	 Move up, up arrow */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_UP );
			else	return( xgr_usfo(3) );
		case XK_KP_Right	: // FF98
		case XK_Right		: // 0xFF53	 Move right, right arrow */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_RIGHT );
			else	return( xgr_usfo(1) );
		case XK_KP_Down		: // FF99
		case XK_Down		: // 0xFF54	 Move down, down arrow */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_DOWN );
			else	return( xgr_usfo(4) );

		case XK_KP_Page_Up	: // FF9A
		case XK_Page_Up		: // 0xFF55		*/
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_PAGE_UP );
			else	return( 0x0012 );

		case XK_Page_Down	: // 0xFF56	PGDN : CTRL C */
		case XK_KP_Page_Down	: // FF9B
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_PAGE_DOWN );
			else	return( 0x0003 );

		case XK_KP_End		: // FF9C
		case XK_End		: // 0xFF57	 EOL : CTRL B */
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_END );
			else	return( 0x0002 );

		case XK_KP_Begin	: // FF9D
		case XK_Begin		: // 0xFF58	 BOL : CTRL A */
			accentmodifier=0;
			return( 0x0001 );


		case XK_KP_Insert	: // FF9E
		case XK_Insert		: // 0xFF63	Insert, insert here */
			accentmodifier=0;
			if (!( XGC.alt )) {
				if ( XGC.control )
					return( _CTRL_INSERT );
				else	return( 0x000F );
				}
			else if ( isdown )
				return(-1);
			else	{
				XGC.altcompose = request_clipboard();
				return( -1 );
				}
		case XK_Print		: // 0xFF61 Ctrl P */
			if ( isdown )
				return(-1);
			else if (!( esc_Q() ))
				return( 0x0010 );
			else	return( -1 );

		case XK_Undo		: // 0xFF65 Undo, oops */
		case XK_Redo		: // 0xFF66 redo, again */
			accentmodifier=0;
			return( 0x0016 );


		case XK_Cancel	  	: // 0xFF69	Cancel, stop, abort, exit */
			accentmodifier=0;
			return( 0x0001 );

		/* Keypad Functions, keypad numbers cleverly chosen to map to ascii */

		case XK_KP_Space	: // FF80	/* space */
			accentmodifier=0;
			return( ' ');
		case XK_KP_Equal	: // FFBD
			accentmodifier=0;
			return('=');
		case XK_KP_Multiply	: // FFAA
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_STAR );
			else	return('*');
		case XK_KP_Add		: // FFAB
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_PLUS );
			else	return('+');
		case XK_KP_Separator	: // FFAC
			accentmodifier=0;
			return('.');
		case XK_KP_Subtract	: // FFAD
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_MINUS );
			else	return('-');
		case XK_KP_Decimal	: // FFAE
			accentmodifier=0;
			if ( XGC.control )
				return( _CTRL_DEL );
			else	return('.');
		case XK_KP_Divide	: // FFAF
			accentmodifier=0;
			return('/');

		case XK_KP_0			: // FFB0
		case XK_KP_1			: // FFB1
		case XK_KP_2			: // FFB2
		case XK_KP_3			: // FFB3
		case XK_KP_4			: // FFB4
		case XK_KP_5			: // FFB5
		case XK_KP_6			: // FFB6
		case XK_KP_7			: // FFB7
		case XK_KP_8			: // FFB8
		case XK_KP_9			: // FFB9
			accentmodifier=0;
			if ( XGC.alt ) {
				if ( isdown ) {
					XGC.altcompose *= 10;
					XGC.altcompose += (xkeycode & 0x000F);
					}
				return(-1);
				}
			else if (!( XGC.control )) {
				return((xkeycode & 0x003F));
				}
			else	{
				switch ( xkeycode ) {
					case XK_KP_0			: // FFB0
						return( _CTRL_INSERT );
					case XK_KP_1			: // FFB1
						return( _CTRL_END    );
					case XK_KP_2			: // FFB2
						return( _CTRL_DOWN   );
					case XK_KP_3			: // FFB3
						return( _CTRL_PAGE_DOWN );
					case XK_KP_4			: // FFB4
						return( _CTRL_LEFT   );
					case XK_KP_5			: // FFB5
						return( _CTRL_FIVE   );
					case XK_KP_6			: // FFB6
						return( _CTRL_RIGHT  );
					case XK_KP_7			: // FFB7
						return( _CTRL_HOME   );
					case XK_KP_8			: // FFB8
						return( _CTRL_UP     );
					case XK_KP_9			: // FFB9
						return( _CTRL_PAGE_UP );

					}
				return((xkeycode & 0x003F));
				}
		case XK_KP_F1		: // FF91
		case XK_KP_F2		: // FF92
		case XK_KP_F3		: // FF93
		case XK_KP_F4		: // FF94
			accentmodifier=0;
			return( xgr_usfo( 
					(((xkeycode & 0x00FF) - 0x0091)+128)
					)
				);

		case XK_F1			: // FFBE
		case XK_F2			: // FFBF
		case XK_F3			: // FFC0
		case XK_F4			: // FFC1
		case XK_F5			: // FFC2
		case XK_F6			: // FFC3
		case XK_F7			: // FFC4
		case XK_F8			: // FFC5
		case XK_F9			: // FFC6
		case XK_F10			: // FFC7

			if ( XGC.shift ) {
				accentmodifier=0;
				return(	xgr_usfo(
					((((xkeycode & 0x00FF) - 0x00BE)+10) + 128))
					);

				}
			else if ( XGC.control ) {
				accentmodifier=0;
				return(	xgr_usfo(
					((((xkeycode & 0x00FF) - 0x00BE)+20) + 128))
					);
				}

			else if ( XGC.alt ) {
				accentmodifier=0;
				return(	xgr_usfo(
					((((xkeycode & 0x00FF) - 0x00BE)+30) + 128))
					);
				}

		case XK_F11			: // FFC8
		case XK_F12			: // FFC9
		case XK_F13			: // FFCA
		case XK_F14			: // FFCB
		case XK_F15			: // FFCC
		case XK_F16			: // FFCD
		case XK_F17			: // FFCE
		case XK_F18			: // FFCF
		case XK_F19			: // FFD0
		case XK_F20			: // FFD1
		case XK_F21			: // FFD2
		case XK_F22			: // FFD3
		case XK_F23			: // FFD4
		case XK_F24			: // FFD5
		case XK_F25			: // FFD6
		case XK_F26			: // FFD7
		case XK_F27			: // FFD8
		case XK_F28			: // FFD9
		case XK_F29			: // FFDA
		case XK_F30			: // FFDB
		case XK_F31			: // FFDC
		case XK_F32			: // FFDD
		case XK_F33			: // FFDE
		case XK_F34			: // FFDF
		case XK_F35			: // FFE0

			accentmodifier=0;
			return(	xgr_usfo(
					(((xkeycode & 0x00FF) - 0x00BE) + 128)
					) 
				);

		/* ----------------------------------------------------- */
		/* preallocation of alternative character set : cyrillic */
		/* ----------------------------------------------------- */
		case	0x6C0			: return( CyrillicBase + 0x001E );
		case	0x6C1			: return( CyrillicBase + 0x0000 );
		case	0x6C2			: return( CyrillicBase + 0x0001 );
		case	0x6C3			: return( CyrillicBase + 0x0016 );
		case	0x6C4			: return( CyrillicBase + 0x0004 );
		case	0x6C5			: return( CyrillicBase + 0x0005 );
		case	0x6C6			: return( CyrillicBase + 0x0014 );
		case	0x6C7			: return( CyrillicBase + 0x0003 );
		case	0x6C8			: return( CyrillicBase + 0x0015 );
		case	0x6C9			: return( CyrillicBase + 0x0008 );
		case	0x6CA			: return( CyrillicBase + 0x0009 );
		case	0x6CB			: return( CyrillicBase + 0x000A );
		case	0x6CC			: return( CyrillicBase + 0x000B );
		case	0x6CD			: return( CyrillicBase + 0x000C );
		case	0x6CE			: return( CyrillicBase + 0x000D );
		case	0x6CF			: return( CyrillicBase + 0x000E );
		case	0x6D0			: return( CyrillicBase + 0x000F );
		case	0x6D1			: return( CyrillicBase + 0x001F );
		case	0x6D2			: return( CyrillicBase + 0x0010 );
		case	0x6D3			: return( CyrillicBase + 0x0011 );
		case	0x6D4			: return( CyrillicBase + 0x0012 );
		case	0x6D5			: return( CyrillicBase + 0x0013 );
		case	0x6D6			: return( CyrillicBase + 0x0006 );
		case	0x6D7			: return( CyrillicBase + 0x0002 );
		case	0x6D8			: return( CyrillicBase + 0x001C );
		case	0x6D9			: return( CyrillicBase + 0x001B );
		case	0x6DA			: return( CyrillicBase + 0x0007 );
		case	0x6DB			: return( CyrillicBase + 0x0018 );
		case	0x6DC			: return( CyrillicBase + 0x001D );
		case	0x6DD			: return( CyrillicBase + 0x0019 );
		case	0x6DE			: return( CyrillicBase + 0x0017 );
		case	0x6DF			: return( CyrillicBase + 0x001A );
		case	0x6A3			: return( 0x0090 );
		/* ----------------------------------------------------- */
		/* End of Cyrillic alternative character set Codes	 */
		/* ----------------------------------------------------- */
			
		case XK_Shift_L			: // FFE1	/* Left shift */
		case XK_Shift_R			: // FFE2	/* Right shift */
			return(-1);

		case XK_ISO_Level3_Shift	:		/* Alt Gr ?????? */
		case XK_Alt_R			:		/* Right alt	 */
		case XK_Control_R		: // FFE4	/* Right control */
			if ( isdown ) 	{ accentmodifier=0; }
			return( xkeycode );
			
		case XK_Alt_L			:
		case XK_Control_L		: // FFE3	/* Left control */
		case XK_Caps_Lock		: // FFE5	/* Caps lock */
		case XK_Shift_Lock		: // FFE6	/* Shift lock */
			if ( isdown ) 	{ accentmodifier=0; }
			return( xkeycode );


		case	XK_Pointer_Left					: // FEE0
		case	XK_Pointer_Right				: // FEE1
		case	XK_Pointer_Up					: // FEE2
		case	XK_Pointer_Down					: // FEE3
		case	XK_Pointer_UpLeft				: // FEE4
		case	XK_Pointer_UpRight				: // FEE5
		case	XK_Pointer_DownLeft				: // FEE6
		case	XK_Pointer_DownRight				: // FEE7
		case	XK_Pointer_Button_Dflt				: // FEE8
		case	XK_Pointer_Button1				: // FEE9
		case	XK_Pointer_Button2				: // FEEA
		case	XK_Pointer_Button3				: // FEEB
		case	XK_Pointer_Button4				: // FEEC
		case	XK_Pointer_Button5				: // FEED
		case	XK_Pointer_DblClick_Dflt			: // FEEE
		case	XK_Pointer_DblClick1				: // FEEF
		case	XK_Pointer_DblClick2				: // FEF0
		case	XK_Pointer_DblClick3				: // FEF1
		case	XK_Pointer_DblClick4				: // FEF2
		case	XK_Pointer_DblClick5				: // FEF3
		case	XK_Pointer_Drag_Dflt				: // FEF4
		case	XK_Pointer_Drag1				: // FEF5
		case	XK_Pointer_Drag2				: // FEF6
		case	XK_Pointer_Drag3				: // FEF7
		case	XK_Pointer_Drag4				: // FEF8
		case	XK_Pointer_Drag5				: // FEFD
			accentmodifier=0;
			return(-1);

		/* Accent modifiers	*/
		case XK_slash               		: // 02f
		case XK_backslash               	: // 02f
			return( xkeycode );

		case	XK_dead_tilde			: 
		case	XK_dead_grave			:
		case	XK_dead_acute			:
		case	XK_dead_circumflex		:
		case	XK_dead_diaeresis		:
			if (!( isdown ))	return(-1);
#ifdef	GIGOXTRACE
			if ( GigoXtrace & 64 )  {
				printf("accent modifier : %u : %u \r\n",xkeycode,accentmodifier);
				}
#endif

			if (!( accentmodifier )) {
				accentmodifier = xkeycode;
				return(-1);
				}
			else if ( accentmodifier == xkeycode ) {
				accentmodifier = 0;
				switch ( xkeycode ) {
					case	XK_dead_tilde		: 
						return( '~' );
					case	XK_dead_circumflex	:
						return( '^' );
					case	XK_dead_diaeresis	:

					case	XK_dead_grave		:
					case	XK_dead_acute		:
					default				:
						return( -1 );
					}
				}
			else	{
				if ( GigoXtrace & 64 )  {
					printf("reset accent \r\n");
					}
				accentmodifier = 0;
				return(-1);
				}

		case XK_a                   : // 061
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_acircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_adiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_agrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_aacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_agrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_aacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}
			
		case XK_e                   : // 065
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_ecircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_ediaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_egrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_eacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_egrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_eacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_i                   : // 069
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_icircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_idiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_igrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_iacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_igrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_iacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_o                   : // 06f
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_ocircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_odiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_ograve ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_oacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_ograve ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_oacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_u                   : // 069
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_ucircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_udiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_ugrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_uacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_ugrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_uacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_A                   : // 041
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_Acircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Adiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Agrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Aacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Agrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Aacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_E                   : // 045
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ecircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ediaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Egrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Eacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Egrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Eacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_I                   : // 049
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_Icircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Idiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Igrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Iacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Igrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Iacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_O                   : // 04f
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ocircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Odiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ograve ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Oacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ograve ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Oacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}

		case XK_U                   : // 055
			if (!( isdown ))	return(-1);
			if (!( accentmodifier ))
				return( xkeycode );
			else if ( accentmodifier == XK_dead_circumflex ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ucircumflex ] );
				}
			else if ( accentmodifier == XK_dead_diaeresis   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Udiaeresis ] );
				}
			else if ( accentmodifier == XK_dead_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ugrave ] );
				}
			else if ( accentmodifier == XK_dead_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Uacute ] );
				}
			else if ( accentmodifier == XK_grave   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Ugrave ] );
				}
			else if ( accentmodifier == XK_acute   ) {
				accentmodifier=0;
				return( macrovalue[ XK_Uacute ] );
				}
			else	{
				accentmodifier=0;
				return( xkeycode );
				}


		case XK_space               : // 020
		case XK_exclam              : // 021
		case XK_quotedbl            : // 022
		case XK_numbersign          : // 023
		case XK_dollar              : // 024
		case XK_percent             : // 025
		case XK_ampersand           : // 026
		case XK_apostrophe          : // 027
		case XK_parenleft           : // 028
		case XK_parenright          : // 029
		case XK_asterisk            : // 02a
		case XK_plus                : // 02b
		case XK_comma               : // 02c
		case XK_minus               : // 02d
		case XK_period              : // 02e
		case XK_0                   : // 030
		case XK_1                   : // 031
		case XK_2                   : // 032
		case XK_3                   : // 033
		case XK_4                   : // 034
		case XK_5                   : // 035
		case XK_6                   : // 036
		case XK_7                   : // 037
		case XK_8                   : // 038
		case XK_9                   : // 039
		case XK_colon               : // 03a
		case XK_semicolon           : // 03b
		case XK_less                : // 03c
		case XK_equal               : // 03d
		case XK_greater             : // 03e
		case XK_question            : // 03f
		case XK_at                  : // 040
		case XK_B                   : // 042
		case XK_C                   : // 043
		case XK_D                   : // 044
		case XK_F                   : // 046
		case XK_G                   : // 047
		case XK_H                   : // 048
		case XK_J                   : // 04a
		case XK_K                   : // 04b
		case XK_L                   : // 04c
		case XK_M                   : // 04d
		case XK_N                   : // 04e
		case XK_P                   : // 050
		case XK_Q                   : // 051
		case XK_R                   : // 052
		case XK_S                   : // 053
		case XK_T                   : // 054
		case XK_V                   : // 056
		case XK_W                   : // 057
		case XK_X                   : // 058
		case XK_Y                   : // 059
		case XK_Z                   : // 05a
		case XK_bracketleft         : // 05b
		case XK_bracketright        : // 05d
		case XK_asciicircum         : // 05e
		case XK_underscore          : // 05f
		case XK_grave               : // 060
		case XK_b                   : // 062
		case XK_c                   : // 063
		case XK_d                   : // 064
		case XK_f                   : // 066
		case XK_g                   : // 067
		case XK_h                   : // 068
		case XK_j                   : // 06a
		case XK_k                   : // 06b
		case XK_l                   : // 06c
		case XK_m                   : // 06d
		case XK_n                   : // 06e
		case XK_p                   : // 070
		case XK_q                   : // 071
		case XK_r                   : // 072
		case XK_s                   : // 073
		case XK_t                   : // 074
		case XK_v                   : // 069
		case XK_w                   : // 069
		case XK_x                   : // 078
		case XK_y                   : // 079
		case XK_z                   : // 07a
		case XK_braceleft           : // 07b
		case XK_bar                 : // 07c
		case XK_braceright          : // 07d
		case XK_asciitilde          : // 07e
			accentmodifier=0;
			return( xkeycode );
		case XK_nobreakspace        : // 0a0
		case XK_exclamdown          : // 0a1
		case XK_cent        	    : // 0a2
		case XK_sterling            : // 0a3
		case XK_currency            : // 0a4
		case XK_yen                 : // 0a5
		case XK_brokenbar           : // 0a6
		case XK_section             : // 0a7
		case XK_copyright           : // 0a9
		case XK_ordfeminine         : // 0aa
		case XK_guillemotleft       : // 0ab	/* left angle quotation mark */
		case XK_notsign             : // 0ac
		case XK_hyphen              : // 0ad
		case XK_registered          : // 0ae
		case XK_macron              : // 0af
		case XK_degree              : // 0b0
		case XK_plusminus           : // 0b1
		case XK_twosuperior         : // 0b2
		case XK_threesuperior       : // 0b3
		case XK_acute               : // 0b4
		case XK_mu                  : // 0b5
		case XK_paragraph           : // 0b6
		case XK_periodcentered      : // 0b7
		case XK_cedilla             : // 0b8
		case XK_onesuperior         : // 0b9
		case XK_masculine           : // 0ba
		case XK_guillemotright      : // 0bb	/* right angle quotation mark */
		case XK_onequarter          : // 0bc
		case XK_onehalf             : // 0bd
		case XK_threequarters       : // 0be
		case XK_questiondown        : // 0bf
		case XK_Agrave              : // 0c0
		case XK_Aacute              : // 0c1
		case XK_Acircumflex         : // 0c2
		case XK_Atilde              : // 0c3
		case XK_Adiaeresis          : // 0c4
		case XK_Aring               : // 0c5
		case XK_AE                  : // 0c6
		case XK_Ccedilla            : // 0c7
		case XK_Egrave              : // 0c8
		case XK_Eacute              : // 0c9
		case XK_Ecircumflex         : // 0ca
		case XK_Ediaeresis          : // 0cb
		case XK_Igrave              : // 0cc
		case XK_Iacute              : // 0cd
		case XK_Icircumflex         : // 0ce
		case XK_Idiaeresis          : // 0cf
		case XK_ETH                 : // 0d0
		case XK_Ntilde              : // 0d1
		case XK_Ograve              : // 0d2
		case XK_Oacute              : // 0d3
		case XK_Ocircumflex         : // 0d4
		case XK_Otilde              : // 0d5
		case XK_Odiaeresis          : // 0d6
		case XK_multiply            : // 0d7
		case XK_Ooblique            : // 0d8
		case XK_Ugrave              : // 0d9
		case XK_Uacute              : // 0da
		case XK_Ucircumflex         : // 0db
		case XK_Udiaeresis          : // 0dc
		case XK_Yacute              : // 0dd
		case XK_THORN               : // 0de
		case XK_ssharp              : // 0df
		case XK_agrave              : // 0e0
		case XK_aacute              : // 0e1
		case XK_acircumflex         : // 0e2
		case XK_atilde              : // 0e3
		case XK_adiaeresis          : // 0e4
		case XK_aring               : // 0e5
		case XK_ae                  : // 0e6
		case XK_ccedilla            : // 0e7
		case XK_egrave              : // 0e8
		case XK_eacute              : // 0e9
		case XK_ecircumflex         : // 0ea
		case XK_ediaeresis          : // 0eb
		case XK_igrave              : // 0ec
		case XK_iacute              : // 0ed
		case XK_icircumflex         : // 0ee
		case XK_idiaeresis          : // 0ef
		case XK_eth                 : // 0f0
		case XK_ntilde              : // 0f1
		case XK_ograve              : // 0f2
		case XK_oacute              : // 0f3
		case XK_ocircumflex         : // 0f4
		case XK_otilde              : // 0f5
		case XK_odiaeresis          : // 0f6
		case XK_division            : // 0f7
		case XK_oslash              : // 0f8
		case XK_ugrave              : // 0f9
		case XK_uacute              : // 0fa
		case XK_ucircumflex         : // 0fb
		case XK_udiaeresis          : // 0fc
		case XK_yacute              : // 0fd
		case XK_thorn               : // 0fe
		case XK_ydiaeresis          : // 0ff
			accentmodifier=0;
			return( macrovalue[ xkeycode ] );

		case XK_FFrancSign					: // 20a3
			accentmodifier=0;
			return( 'f' );

		case XK_PesetaSign					: // 20a7
			accentmodifier=0;
			return( 'ž' );

		case XK_EuroSign					: // 20ac
			accentmodifier=0;
			return( '›' );

		default			:
			accentmodifier=0;
			return( -1 );

		}

}

#endif	/* _xkeysym_c */

