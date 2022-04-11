#ifndef	_console_c
#define	_console_c

#ifndef	WIN32
#include "pixel.h"
#else
#include "pubmanagercico.h"
#endif

private	int	ConsolePurge=1;
private	int	ConsoleStatus=0;
private	int	ConsoleUsers=0;
private	int	BiosMode=3;
private	int	BiosWidth=0;
private	int	BiosHeight=0;
private	int	BiosPixel=0;

private	char *	BaseFont="/opt/prologue/fonts/standard.fmf";
private	char *	Palette ="/opt/prologue/images/standard.rgb";
#ifdef	WIN32
extern	char *  GigoColours;
#else
public	char *  GigoColours=(char *) 0;
#endif
private	char *	EnvBuffer=(char *) 0;

public	int 	get_biosmode() { return( BiosMode ); }
public	int 	get_bioswidth() { return( BiosWidth ); }
public	int 	get_biosheight() { return( BiosHeight ); }
public	void	set_bioswidth(int v) {	BiosWidth = v; }
public	void	set_biosheight(int v) {	BiosHeight = v; }

public	void	inhibit_console_purge()	{	ConsolePurge=0; 	}

public	void	set_biosmode( int vesamode )
{
	if (( vesamode >= 0 )&&(vesamode <= 5))
		BiosMode=vesamode;
	return;

}

public	void	set_basefont( char * basefont )
{
	if ((basefont)
	&&  (*basefont))
		BaseFont = basefont;
	return;
}

public	void	set_palette( char * palette )
{
	if ((palette)
	&&  (*palette))
		Palette = palette;
	return;
}


/*
 *	c l o s e _ c o n s o l e ()
 *	----------------------------
 *
 *
 */

public	int	close_console()
{
	/* Handle multiple entrance */
	/* ------------------------ */
	if ( ConsoleUsers )
		ConsoleUsers--;
	if ( ConsoleUsers )
		return(ConsoleStatus);
#ifndef WIN32	/* GWB le 21/02/2007 */
	if ( ConsoleStatus ) 
		if ( ConsolePurge )
			while (x_kbhit()) x_getch();
	if ( ConsoleStatus == 1 ) 
		finterm(0);
	else if ( ConsoleStatus == 2 )
		while ( liberatepixel() > 0);
	if ( EnvBuffer )
		liberate( EnvBuffer );
	EnvBuffer = (char *) 0;
#else
  finterm(0);	
#endif
	return((ConsoleStatus=0));
}


private	void	check_gigo()
{
	char *	eptr;
	int	v;

	/* Collect Environment variable values */
	/* ----------------------------------- */
	if ((eptr = getenv("GIGO"))!=(char*) 0) {

		if (EnvBuffer)
			EnvBuffer = liberate(EnvBuffer);

		if ((EnvBuffer = allocate((strlen(eptr)+1))) != (char*) 0) { 
			strcpy(EnvBuffer,eptr);
			eptr = EnvBuffer;
			
			/* First Parameter : BISOMODE */
			/* -------------------------- */
			if (( *eptr != 0   )
			&&  ( *eptr != ':' )) {
				if ( *eptr != '=' ) {
					BiosMode = 0;
					while (( *eptr != 0 )
					&&     ( *eptr != ',')  
					&&     ( *eptr != ':')) {
						if (( *eptr >= '0' ) && ( *eptr <= '9' ))
							BiosMode = ((BiosMode * 10) + ( *(eptr++) - '0' ));
						else	break;
						}
					if ( *eptr != ',' )
						BiosPixel=0;
					else	{
						eptr++;
						BiosPixel = *(eptr++);
						BiosPixel -= '0';
						}		
					}
				else	{
					eptr++;
					BiosMode=7;
					BiosWidth=0; BiosHeight=0;
					while (( *eptr != 0 )
					&&     ( *eptr != ',')) {
						if (( *eptr >= '0' ) && ( *eptr <= '9' ))
							BiosWidth = ((BiosWidth * 10) + ( *(eptr++) - '0' ));
						else	break;
						}

					while (( *eptr ) && ( *eptr != ',' )) eptr++;
					if ( *eptr == ',' ) *(eptr++) = 0;
					while (( *eptr != 0 )
					&&     ( *eptr != ',')  
					&&     ( *eptr != ':')) {
						if (( *eptr >= '0' ) && ( *eptr <= '9' ))
							BiosHeight = ((BiosHeight * 10) + ( *(eptr++) - '0' ));
						else	break;
						}

					if ( *eptr != ',' )
						BiosPixel=0;
					else	{
						eptr++;
						BiosPixel = *(eptr++);
						BiosPixel -= '0';
						}		
					}

				while (( *eptr ) && ( *eptr != ':' )) eptr++;
				if ( *eptr == ':' )
					*(eptr++) = 0;


				}
			else if ( *eptr == ':' )
				eptr++;

			/* Second Parameter : BASEFONT */
			/* --------------------------- */
			if (( *eptr != 0   )
			&&  ( *eptr != ':' )) {
				BaseFont=eptr;
				while (( *eptr ) && ( *eptr != ':' )) eptr++;
				if ( *eptr == ':' )
					*(eptr++) = 0;

				}
			else if ( *eptr == ':' )
				eptr++;

			/* Third Parameter : PALETTE */
			/* ------------------------- */
			if (( *eptr != 0   )
			&&  ( *eptr != ':' )) {
				Palette = eptr;
				while (( *eptr ) && ( *eptr != ':' )) eptr++;
				if ( *eptr == ':' ) *(eptr++) = 0;

				}
			else if ( *eptr == ':' )
				eptr++;

			/* Fourth Parameter : DEFAULT COLOUR */
			/* --------------------------------- */
			if (( *eptr != 0   )
			&&  ( *eptr != ':' )) {
				GigoColours = eptr;
				while (( *eptr ) && ( *eptr != ':' )) eptr++;
				if ( *eptr == ':' ) *(eptr++) = 0;
				}
			else if ( *eptr == ':' )
				eptr++;
			}

		}
	return;
}

/*
 *	o p e n _ c o n s o l e ()
 *	--------------------------
 *
 *
 */

public	int 	open_console()
{
	int	status=0;

	/* Handle multiple entrance */
	/* ------------------------ */
	if ( ConsoleUsers ) {
		ConsoleUsers++;
		return( ConsoleStatus );
		}
	else	ConsoleUsers++;

/* GWB le 21/02/2007 avant Jamie */
#ifdef WIN32
	initerm_graphic();

	BiosHeight = hardrows();
	BiosWidth  = hardcolumns();
	BiosMode   = hardmode(); 

	return((ConsoleStatus=2));
#else
	/* Read GIGO variable information */
	/* ------------------------------ */
	check_gigo();

	
	/* Check for graphics permitted */
	/* ---------------------------- */
	if (!( consoletype() )) {

		/* Use Text Mode CiCo */
		/* ------------------ */
		initerm();
		return((ConsoleStatus=1));

		}

	if ( BiosMode == 7 ) {
		/* special case : Dimensions */
		if (( status = activatepixel( BiosWidth,BiosHeight,(BiosPixel<<8) )) == -1) {
			/* Failre so Use CiCo */
			/* ------------------ */
			initerm();
			return((ConsoleStatus=1));
			}
		}

	/* Attempt to start the Graphics and GiGo */
	/* -------------------------------------- */
	else if ((status = initialisepixel( (BiosMode | (BiosPixel << 8)) )) == -1 ) {

		/* Failre so Use CiCo */
		/* ------------------ */
		initerm();
		return((ConsoleStatus=1));
		}

	/* Attempt to load the Default Palette */
	/* ----------------------------------- */
	if ((status = load_palette( Palette )) != 0) {

		liberatepixel();
		initerm();
		return((ConsoleStatus=1));
		}

	/* Attempt to load the Default Palette */
	/* ----------------------------------- */
	else if ((status = load_font(1, BaseFont)) != 0) {

		liberatepixel();
		initerm();
		return((ConsoleStatus=1));
		}
	else if ((status = use_base_font(1)) != 0) {

		liberatepixel();
		initerm();
		return((ConsoleStatus=1));
		}
	else	{
		cicopalette(0,16);
		return((ConsoleStatus=2));
		}
#endif
}


public	int	x_initerm()
{
	return( open_console() );
}

public	int	x_finterm()
{
	return( close_console() );
}


#endif	/* _console_c */

