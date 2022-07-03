#ifndef	_stdmimo_c
#define	_stdmimo_c

#include "guimouse.h"

extern	int GigoXtrace;

static	struct	mimo_event	
{
	int	active;
	int	buttons;

	int	mask;
	int	type;

	int	parameter;
	int	textlin;

	int	textcol;
	int	grafrow;

	int	grafcol;

	Time	stamp;
	Time	down;

	Time	up;
	Time	clicktime;

	Time	doubletime;
} 	MimoEvent = 
{ 	0,0,	0,0,	0,0,	0,0,	0,
	0,0,	0,	100,	250 
};

/*	 ---------------	*/
/*	 mimo_save_event	*/
/*	 ---------------	*/
int	mimo_save_event( int	mode, int x, int y, int b, Time t)
{
	MimoEvent.buttons = 0;

	if (b & Button1Mask )
		MimoEvent.buttons |= 1;

	if (b & Button2Mask )
		MimoEvent.buttons |= 2;

	if (b & Button3Mask )
		MimoEvent.buttons |= 4;

	if (b & Button4Mask )
		MimoEvent.buttons |= 8;

	if (b & Button5Mask )
		MimoEvent.buttons |= 16;

	MimoEvent.grafcol = x;
	MimoEvent.grafrow = y;
	MimoEvent.stamp   = t;
	return(-1);
}

/*	------------------	*/
/*	mimo_restore_event	*/
/*	------------------	*/
int	mimo_restore_event( int	mode, int x, int y, int b, Time t)
{
	MimoEvent.buttons = 0;

	if (b & Button1Mask )
		MimoEvent.buttons |= 1;

	if (b & Button2Mask )
		MimoEvent.buttons |= 2;

	if (b & Button3Mask )
		MimoEvent.buttons |= 4;

	if (b & Button4Mask )
		MimoEvent.buttons |= 8;

	if (b & Button5Mask )
		MimoEvent.buttons |= 16;

	MimoEvent.grafcol = x;
	MimoEvent.grafrow = y;
	MimoEvent.stamp   = t;
	return(-1);
}

/*	--------------	*/
/*	mimo_key_event	*/
/*	--------------	*/
int	mimo_key_event( int keycode )
{
	if (!((	MimoEvent.parameter = keycode ) & _MIMO_ALT))
		MimoEvent.type =  _MIMO_KEYBOARD;
	else if (!( MimoEvent.mask & _MIMO_ALT ))
		MimoEvent.type =  _MIMO_KEYBOARD;
	else	
	{
		keycode = 256;
		MimoEvent.type =  (MimoEvent.mask & (_MIMO_DOWN | _MIMO_UP | _MIMO_ALT));
	}
	MimoEvent.textcol = MimoEvent.textlin = 0;
	MimoEvent.grafrow = MimoEvent.grafcol = 0;
	return( keycode );
}

/*	-----------------	*/
/*	mimo_signal_event	*/
/*	-----------------	*/
int	mimo_signal_event( int sigid )
{
	MimoEvent.type = _MIMO_SIGNAL;
	MimoEvent.parameter = sigid;
	MimoEvent.textcol = MimoEvent.textlin = 0;
	MimoEvent.grafrow = MimoEvent.grafcol = 0;
	if (!(MimoEvent.type & MimoEvent.mask))
		return(0);
	else	return(256);
}

/*	-----------------	*/
/*	 mimo_task_event	*/
/*	-----------------	*/
int	mimo_task_event( int sigid )
{
	MimoEvent.type = _MIMO_INTERRUPT;
	MimoEvent.parameter = sigid;
	MimoEvent.textcol = MimoEvent.textlin = 0;
	MimoEvent.grafrow = MimoEvent.grafcol = 0;
	if (!(MimoEvent.type & MimoEvent.mask))
		return(0);
	else	return(256);
}

/*	----------------	*/
/*	 mimo_use_event 	*/
/*	----------------	*/
int	mimo_use_event( int	mode, int x, int y, int b, Time t)
{
	if ( GigoXtrace & 16 ) 
	{
		printf("buttonmap L=%u, R=%u, M=%u\r\n",XGC.leftbutton,XGC.rightbutton,XGC.middlebutton);
		printf("mimo_use_event(%x,x=%u,y=%u,b=%x)\r\n",mode,x,y,b);
		printf("mimo state    (%x,x=%u,y=%u,b=%x)\r\n",
			MimoEvent.type,MimoEvent.grafcol,MimoEvent.grafrow,
			MimoEvent.buttons );
	}

	/* if not simple motion set the button value */
	/* ----------------------------------------- */
	if ( b != _MIMO_MOVE ) 
	{
		if ( b == XGC.leftbutton )
			b = _MIMO_LEFT;
		else if ( b == XGC.rightbutton )
			b = _MIMO_RIGHT;
		else if ( b == XGC.middlebutton )
			b = _MIMO_MIDDLE;
		else if ( b == XGC.upwheel )
			b = _MIMO_WHEELUP;
		else if ( b == XGC.downwheel )
			b = _MIMO_WHEELDOWN;
		else	b = 0;
	}

	if (!( MimoEvent.active ))
		return(-1);

	else if ( mode == _MIMO_MOVE ) 
	{
		if ( MimoEvent.buttons ) 
		{
			mode = _MIMO_WHILE_DOWN;
			b    = MimoEvent.buttons;
		}
		else	b = 0;
	}
	else if ( mode == _MIMO_DOWN ) 
		MimoEvent.buttons |= b;

	else if ( mode == _MIMO_UP ) 
	{
		MimoEvent.buttons &= (b ^ 0xFFFF);
	}

	/* save these now */
	/* -------------- */
	MimoEvent.parameter = b;
	MimoEvent.grafrow = y;
	MimoEvent.grafcol = x;

	/* Calculate Text Coordinates */
	/* -------------------------- */
	if ( Gigo.fontwidth ) 
	{
		if ( x < Gigo.leftmargin )
			MimoEvent.textcol = 0;
		else if (x > (Gigo.leftmargin+Gigo.width) )
			MimoEvent.textcol = 0;
#ifdef	_ABAL_DTI
		else if ( Gigo.direction & _GIGO_R2L )
		 	MimoEvent.textcol = (Gigo.columns - ((x-Gigo.leftmargin) / Gigo.fontwidth));
#endif
		else 	MimoEvent.textcol = (((x-Gigo.leftmargin) / Gigo.fontwidth)+1);
	}
	else	MimoEvent.textcol = 1;

	if ( Gigo.fontheight ) 
	{
		if ( y < Gigo.topmargin )
			MimoEvent.textlin = 0;
		else if (y > (Gigo.topmargin+Gigo.height) )
			MimoEvent.textlin = 0;
#ifdef	_ABAL_DTI
		else if ( Gigo.direction & _GIGO_B2T )
			MimoEvent.textlin = (Gigo.lines - ((y-Gigo.topmargin) / Gigo.fontheight));
#endif
		else	MimoEvent.textlin = (((y-Gigo.topmargin) / Gigo.fontheight)+1);
	}
	else	MimoEvent.textlin = 1;


	/* test for click/double click or just up */
	/* -------------------------------------- */
	if ( mode == _MIMO_UP ) 
	{
		if (!( MimoEvent.mask & _MIMO_UP )) 
		{
			if (( t - MimoEvent.down) < MimoEvent.clicktime ) 
			{
				if (!( MimoEvent.mask & _MIMO_DOUBLE )) 
				{
					mode = _MIMO_CLICK;
				}
				else  if (( t - MimoEvent.up) < MimoEvent.doubletime ) 
				{
					mode = _MIMO_DOUBLE;
				}
				else	
				{
					mode = _MIMO_CLICK;
				}
			}
		}
		MimoEvent.up = t;
	}
	else if ( mode == _MIMO_DOWN ) 
	{
		MimoEvent.down = t;
	}

	/* save these now */
	/* -------------- */
	MimoEvent.type = mode;
	MimoEvent.stamp = t;

	/* Determine nature of event */
	/* ------------------------- */
	if ( GigoXtrace & 16 ) 
	{
		printf("ME(t=%x,m=%x,b=%u,l=%u,c=%u)\r\n",MimoEvent.type,MimoEvent.mask,
			b,
			MimoEvent.textlin,MimoEvent.textcol);
	}
	if ((   b == _MIMO_LEFT )
	&&  (!( MimoEvent.mask & _MIMO_SEND_LEFT )))
		return( -1 );

	if ((   b == _MIMO_RIGHT )
	&&  (!( MimoEvent.mask & _MIMO_SEND_RIGHT )))
		return( -1 );

	if ((   b == _MIMO_MIDDLE )
	&&  (!( MimoEvent.mask & _MIMO_SEND_MIDDLE )))
		return( -1 );

	if (((   b == _MIMO_WHEELUP   )
	||   (   b == _MIMO_WHEELDOWN ))
	&&  (!( MimoEvent.mask & _MIMO_SEND_WHEEL )))
		return( -1 );

	if ( (MimoEvent.type & MimoEvent.mask) )
		return(256);
	else	return( -1 );
}

/*	------------	*/
/*	use_new_mimo	*/
/*	------------	*/
void	use_new_mimo()
{	
	return;
}

/*	---------	*/
/*	init_mimo	*/
/*	---------	*/
void	init_mimo()		
{	
	MimoEvent.active    =
	MimoEvent.buttons   = 
	MimoEvent.type      =
	MimoEvent.parameter = 
	MimoEvent.textlin  =
	MimoEvent.textcol  =
	MimoEvent.grafrow  =
	MimoEvent.grafcol  = 0;
	MimoEvent.mask     = _MIMO_MASK;
	return;			
}

/*	--------------	*/
/*	mimo_set_event	*/
/*	--------------	*/
void	mimo_set_event( int t, int b, int c, int l )
{
	MimoEvent.type     = t;
	if ( t == _MIMO_DOWN ) 
		MimoEvent.buttons |= b;
	else if (t == _MIMO_UP ) 
	{
		MimoEvent.buttons &= (b ^ 0xFFFF);
	}
	MimoEvent.parameter = b;
	MimoEvent.grafrow  = l;
	MimoEvent.grafcol  = c;
	MimoEvent.textlin  =
	MimoEvent.textcol  = 0;
	return;
}

/*	-------------	*/
/*	activate_mimo	*/
/*	-------------	*/
int	activate_mimo()		
{	
	if (!( MimoEvent.active ))
	{
	 
		MimoEvent.active = 1;
		set_enhanced_events();
	}
	return(0);
}

/*	-------------	*/
/*	set_mimo_mask	*/
/*	-------------	*/
void	set_mimo_mask(int v)	
{
	if ( GigoXtrace & 16 ) 
	{
		printf("set_mimo_mask(%x)\r\n",v);	
	}

	if (!((MimoEvent.mask = v) & (_MIMO_BUTTONS)))
		MimoEvent.mask |= _MIMO_SEND_LEFT;

	return;	
}

/*	------------	*/
/*	inhibit_mimo	*/
/*	------------	*/
int	inhibit_mimo()		
{	
	MimoEvent.active = 0;
	set_standard_events();
	return(0);
}

/*	--------	*/
/*	fin_mimo	*/
/*	--------	*/
void	fin_mimo()
{	
	init_mimo(); 
	return;
}
int	mimo_getch()		{	return(x_getch());					}
int	mimo_kbhit()		{	return(x_kbhit());					}
int	mimo_detect()		{	return( (x_detect() == 256 ? Gigo.thisevent : 0 ) );	}
int	get_mimo_type()		{	return(MimoEvent.type);					}
int	get_mimo_par()		{	return(MimoEvent.parameter);				}
int	get_mimo_row()		{	return(MimoEvent.grafrow);				}
int	get_mimo_column()	{	return(MimoEvent.grafcol);				}
int	get_mimo_lin()		{	return(MimoEvent.textlin);				}
int	get_mimo_col()		{	return(MimoEvent.textcol);				}
int 	get_mimo_mask()		{	return( MimoEvent.mask );				}
int	get_mimo_status()	{ 	return((MimoEvent.active?MimoEvent.mask:0)); 		}
int	get_mimo_buttons()	{ 	return((MimoEvent.active?MimoEvent.buttons:0)); 	}

/*	----------	*/
/*	flush_mimo	*/
/*	----------	*/
int 	flush_mimo()		
{
	while ( mimo_kbhit() )
		(void) mimo_getch();
 	return(0);	
}

int	verify_wakeup_status(a) {	return(a); 			}
int	clear_wakeup_status()	{	return(0);			}

#define	mimoputw(b,v) {\
	*((unsigned char *) b) = ((v & 0xFF00) >> 8); \
	*((unsigned char *) (b+1)) = (v & 0x00FF); \
	}


#define	mimogetw(b,v) v = ((*((unsigned char*)b) << 8) | *((unsigned char*)(b+1)))

/*	-----------------	*/
/*	save_mimo_context	*/
/*	-----------------	*/
void	save_mimo_context( buffer )
char *	buffer;
{
	mimoputw((buffer+0),MimoEvent.active    );
	mimoputw((buffer+2),MimoEvent.buttons   ); 
	mimoputw((buffer+4),MimoEvent.type      );
	mimoputw((buffer+6),MimoEvent.parameter ); 
	mimoputw((buffer+8),MimoEvent.textlin  );
	mimoputw((buffer+10),MimoEvent.textcol  );
	mimoputw((buffer+12),MimoEvent.grafrow  );
	mimoputw((buffer+14),MimoEvent.grafcol  );
	mimoputw((buffer+16),MimoEvent.mask     );
	return;
}

/*	--------------------	*/
/*	restore_mimo_context	*/
/*	--------------------	*/
void	restore_mimo_context( buffer )	
char *	buffer;
{ 
	mimogetw((buffer+0),MimoEvent.active    );
	mimogetw((buffer+2),MimoEvent.buttons   ); 
	mimogetw((buffer+4),MimoEvent.type      );
	mimogetw((buffer+6),MimoEvent.parameter ); 
	mimogetw((buffer+8),MimoEvent.textlin  );
	mimogetw((buffer+10),MimoEvent.textcol  );
	mimogetw((buffer+12),MimoEvent.grafrow  );
	mimogetw((buffer+14),MimoEvent.grafcol  );
	mimogetw((buffer+16),MimoEvent.mask     );
	set_mimo_mask( MimoEvent.mask );
	return;	
}

int	start_mimo_alarm() 	{	return(0); 			}
int	cancel_mimo_alarm() 	{	return(0); 			}
int	simulate_mimo() 	{	return(0); 			}
char *	Mgetenv(char * nptr) 	{	return( getenv(nptr) );		}
int	set_mimo_curser() 	{ 	return(0); 			}

#endif	/* _stdmimo_c */


