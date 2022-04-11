/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1992 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORK.H  				*/
/*		Date 	:	12/11/1992				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXDBDUMP_C
#define	_EXDBDUMP_C

EXTERN EXAWORD ScreenLin;

#ifdef	ABAL21
EXAWORD	patch_memory(topcol,toplin, maxlines,paragraph, offset, nibble, wptr, wlen )
EXAWORD	topcol;
EXAWORD	toplin;
EXAWORD	maxlines;
EXAWORD	paragraph;
EXAWORD	offset;
EXAWORD	nibble;
BPTR	wptr;
EXAWORD	wlen;
{
	EXAWORD	offatb;
	EXAWORD	onatb;
	EXAWORD	c;
	toplin--;
	while ( 1 ) {

		if ((((paragraph -1) * 16) + offset) < wlen ) {
			offatb = 2; onatb = 0;
			}
		else	{
			offatb = 0; onatb = 2;
			}

		show_nibble(onatb,topcol,toplin, paragraph, offset, nibble, wptr );
#ifdef	ABAL21
		c = mouse_or_keyboard();
#else
		c = db_xgetch();
#endif
		show_nibble(offatb,topcol,toplin, paragraph, offset, nibble, wptr );

		if ((c == 0x001B) || (c == 0x000D) || ( c == 0x0020))
			return( c );

		switch (c) {
			
			case 0x001A : /* Interprete Zoom Pointer */
				attempt_zoom_pointer((wptr + ((paragraph-1) * 16) + offset));
				continue;

			case 0x0006 :
				if ( nibble ) {

					if ( offset < 15 ) 
						offset++;
					else	offset = 0;
					nibble = 0;
					}
				else	nibble = 1;
				continue;

			case 0x0008 :
				if (!(nibble)) {
					if ( offset > 0 ) 
						offset--;
					else	offset = 15;
					nibble = 1;
					}
				else	nibble = 0;
				continue;

			case 0x0005 :
				if ( paragraph < maxlines )
					paragraph++;
				else	paragraph = 1;
				continue;

			case 0x000B :
				if ( paragraph > 1 )
					paragraph--;
				else	paragraph = maxlines;
				continue;

			default	    :
				if (( c >= 'a' ) && ( c <= 'f' ))
					c = ((c - 'a') + 10);
				else if (( c >= 'A' ) && ( c <= 'F' ))
					c = ((c - 'A') + 10);
				else if (( c >= '0' ) && ( c <= '9' ))
					c -= '0';
				else	continue;
				put_nibble(c,paragraph,offset,nibble,wptr);
				show_nibble(0,topcol,toplin, paragraph, offset, nibble, wptr );
				if ( nibble ) {

					if ( offset < 15 ) 
						offset++;
					else 	offset = 0;
					nibble = 0;
	
					}
				else	nibble = 1;
				continue;

			}

		}


}

VOID	dumpzone(wptr,mode,entry)
BPTR	wptr;
EXAWORD	mode;
EXAWORD	entry;
{
	EXAWORD	topcol=2;
	EXAWORD	toplin=6;
	EXABYTE	c;
	EXAWORD	x,y;
	EXAWORD	lno;
	EXAWORD	Hl,Hc;
	EXAWORD	flag;
	EXAWORD	dislines=2;
	BPTR	xwptr;
	EXAWORD	xmode;

	/* Save Current Screen Details */
	/* --------------------------- */
	Hl = db_xlin(); Hc = db_xcol();

	if ( mode > 0 ) 
		flag = 1;	
	else	flag = 0;

	y = POINTER * 2;

	/* Draw Window and Save Buffered Infos */
	/* ----------------------------------- */
	WdwLimit(9,4,64);
	if (trad_ver < '2') {
		topcol = WindCord[9][1];
		toplin = WindCord[9][0];
		}
	if ( PushZone(toplin,topcol,4,64,0x0013,Couleurs[9][0],Couleurs[9][1]) != 0 ) {
		Debordement();
		return;
		}
	set_mouse_control( topcol, toplin,62,dislines);

#ifdef	BUF_CICO
	/* Activate PRINT Buffering */
	/* ------------------------ */
	x_bstart();
#endif		
	for ( x = 0; x < y; x++ ) 
		db_xputch(' ');

	db_xcprintf((BPTR)"     ");

	for ( x = 0; x < 16 ; x++ ) { 
		showword( x,2 ); db_xputch(' '); 
		}

#ifdef	BUF_CICO
	x_bflush();
#endif		
	lno = 2;
	xwptr = wptr;
	xmode = mode;
	do{
	   if(lno < ScreenLin * 3/4 )
	   {
#ifdef	BUF_CICO
		x_bstart();
#endif		
		wdw_xpos(lno++,2);
		db_xputch('('); 
		showptr(wptr); 
		db_xcprintf((BPTR)") : ");
		if ( flag == 1 ) 
			ColourAtb(2);

		for ( x = 0; x < 16 ; x++ ) {

			/* Control adresse for systeme validity */
			/* ------------------------------------ */
			if ( VerifPtr( wptr ) == 0 ) {
				showword( (EXAWORD) *(wptr++),2); 
				}
			else	{
				db_xputch(' ');
				db_xputch(' ');
				}
			db_xputch(' ');
			if ( flag == 1 ) { 
				mode--;
				if ( mode == 0 ) {
					flag = 0; 
					ColourAtb(0); 
					}
				}
			}

		ColourAtb(0);
#ifdef	BUF_CICO
		x_bflush();
#endif		
	   }		   
		y = patch_memory( 15, 2, (dislines-1), 1, 0, 0, xwptr, xmode );
		ColourAtb(0); 
		switch ( y ) {
			case 0x000D : if ( entry == 0 ) {
						LibZone(); 
						y= IO_ESC; 
						break;
						}
			case 0x001B : PopZone(); y= IO_ESC; break;
			case 0x0020 : 
				if (lno < ScreenLin * 3 / 4) {
					if ( ZaddLynes(1) == 0 ) {
						pop_mouse();
						dislines++;
						set_mouse_control( topcol, toplin,62,dislines);
						}
					}
				y = 0;
			}

		}
	while	( y != IO_ESC );
	db_xpos(Hl,Hc);
	pop_mouse();
	return;
}


#else	/* ABAL14 */
	/* ------ */

/*
 *	D U M P Z O N E ()
 *	------------------
 *	Affichage en forme d'une ligne d'octets ( x 16 )
 *	d'une zone memoire
 *
 */

VOID	dumpzone(wptr,mode)
BPTR	wptr;
EXAWORD	mode;
{
	EXABYTE	c;
	EXAWORD	x,y;
	EXAWORD	lno;
	EXAWORD	Hl,Hc;
	EXAWORD	flag;

	/* Save Current Screen Details */
	/* --------------------------- */
	Hl = db_xlin(); Hc = db_xcol();

	if ( mode > 0 ) { flag = 1; }	
	else		{ flag = 0; }

	y = POINTER * 2;

	/* Draw Window and Save Buffered Infos */
	/* ----------------------------------- */
	WdwLimit(9,4,64);
	if ( PushZone(WindCord[9][0],WindCord[9][1],4,64,0x0013,Couleurs[9][0],Couleurs[9][1]) != 0 ) {
		Debordement();
		return;
		}
#ifdef	BUF_CICO
	/* Activate PRINT Buffering */
	/* ------------------------ */
	x_bstart();
#endif		
	for ( x = 0; x < y; x++ ) { db_xputch(' '); }
	db_xcprintf((BPTR)"     ");
	for ( x = 0; x < 16 ; x++ ) { showword( x,2 ); db_xputch(' '); }
#ifdef	BUF_CICO
	x_bflush();
#endif		
	lno = 2;
	do	{
#ifdef	BUF_CICO
		x_bstart();
#endif		
		wdw_xpos(lno++,2);
		db_xputch('('); showptr(wptr); db_xcprintf((BPTR)") : ");
		if ( flag == 1 ) { ColourAtb(2); }

		for ( x = 0; x < 16 ; x++ ) {

			/* Control adresse for systeme validity */
			/* ------------------------------------ */
			if ( VerifPtr( wptr ) == 0 ) {
				showword( (EXAWORD) *(wptr++),2); 
				}
			else	{
				db_xputch(' ');
				db_xputch(' ');
				}
			db_xputch(' ');
			if ( flag == 1 ) { 
				mode--;
				if ( mode == 0 ) { flag = 0; ColourAtb(0); }
				}
			}

		ColourAtb(0);
#ifdef	BUF_CICO
		x_bflush();
#endif		
		switch ( ExitMethod((lno >= 21 ? 1 : 2)) ) {
			case 0 : PopZone(); y = IO_ESC; break;
			case 1 : LibZone(); y = IO_ESC; break;
			case 2 : ZaddLynes(1); y = (EXABYTE) 0; break;
			}
		}
	while	( y != IO_ESC );
	db_xpos(Hl,Hc);
	return;
}

#endif	/* ABAL21 or ABAL14 */
	/* ---------------- */


#endif	/* _EXDBDUMP_C */
	/* ----------- */
