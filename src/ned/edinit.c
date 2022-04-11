#ifndef	_edinit_c
#define	_edinit_c

/*
 *	S C R E E N  _  C H A R A C T E R I S T I C S
 *	---------------------------------------------
 *	collects the various screen control parameters
 *	from the low level system screen controller,
 *	CICO or GIGO.
 */

WORD	screen_characteristics(int mode) /* 0: no top zone, 1 : normal */
{
	int	v;
	if ( mode ) {
		if (!( v = is_window_editor() ))
			LGINIT = 3;
		else	LGINIT = v;
		}
	else	{
		LGINIT = 1;
		}
	CLINIT = 1;

  	MXLIG = conf(1);
	MXCOL = (SWORD) (conf(2) - 1);

	dragfactor = (MXLIG / 3);

	if ( NBMXLIG < (SWORD) (( (MXLIG + 1) - LGINIT)) )
		return(0);

	NBLIG = (SWORD) ((MXLIG + 1) - LGINIT);

	return(1);

}

/*	
 *	I N I T I A L I S E _ S C R E E N _ H A R D W A R E 
 *	---------------------------------------------------
 *	activate or initialise the low level screen manager.
 *
 */

static	void	initialise_screen_hardware()
{
	if (!( test_initialise_hardware() )) {
		set_is_graphical();
		return;
		}
#ifdef vms
	qio_usage_flag = 0;
#endif
	select_cico_ecran();
#ifdef	UNIX
	set_desktop_name("Abal Editor");
	set_desktop_icon("Aed");
#else
	inifont(fontz,fontn);
#endif
	if ((flg_cico = open_console())> 1)
		set_is_graphical();
/*	initialise_editor_mouse();	*/
	return;
}

/*	
 *	I N I T I A L I S E _ S C R E E N _ S O F T W A R E 
 *	---------------------------------------------------
 *	activate or initialise the editor screen control.
 *
 */

static	int	initialise_screen_software() 
{
	int	i;

	curs_is_on = TRUE;

	if (!( screen_characteristics(1))) {
		Xerreur(FATALE,ernoy03);
 		editor_bell();	
		return(FALSE);
		}


	i = conf(11);

	flg_InsLgn = flg_DelLgn = TRUE;

	if ((i & 0x04) == 0) 
		flg_InsLgn = FALSE;

	if ((i & 0x08) == 0) 
		flg_DelLgn = FALSE;

	LGERR = 2; COLERR = 1;
	ligne = LGINIT; colonne = CLINIT; pos(ligne,colonne);

	return(1);
}

/*
 *	I N I T I A L I S E _ K E Y B O A R D
 *	-------------------------------------
 *	definition of all keycodes, collection
 *	of current function key values.
 *
 */

static	void	initialise_keyboard()
{
	SWORD	i,nbtfp;

	ESCAPE = (BYTE) 0x001B;
	INSERT = (BYTE) 0x000F;		/* ctrl-O */
	INDENT = (BYTE) 0x0016;		/* ctrl-V */
	UNDEL = (BYTE) 0x001A;		/* ctrl-Z */
	PGDN = (BYTE) 0x0003;		/* ctrl-C */
	PGUP = (BYTE) 0x0012;		/* ctrl-R */
        INSERT = (BYTE) 0x000F;         /* ctrl-O */
	INDENT = (BYTE) 0x0016;         /* ctrl-V */
        UNDEL = (BYTE) 0x001A;  	/* ctrl-Z */
        PGDN = (BYTE) 0x0003;   	/* ctrl-C */
        PGUP = (BYTE) 0x0012;   	/* ctrl-R */
	NEXTWORD = (BYTE) 0x0006;	/* ctrl-F */
	PREVWORD = (BYTE) 0x0001;	/* ctrl-A */
	DELCAR = (BYTE) 0x0007;		/* ctrl-G */
	DELBACK = (BYTE) 0x0008;	/* ctrl-H */
	DEOLN = (BYTE) 0x000B;		/* ctrl-K */
	DBOLN = (BYTE) 0x0015;		/* ctrl-U */
	PDEBFIN = (BYTE) 0x0002;	/* ctrl-B */
	PHOME = (BYTE) 0x0010;		/* ctrl-P */
	DLINE = (BYTE) 0x0019;		/* ctrl-Y */
	ILINE = (BYTE) 0x000E;		/* ctrl-N */
	CENTER = (BYTE) 0x000C;		/* ctrl-L */
	NUMLN = (BYTE) 0x000A;		/* ctrl-J */
	NEXTERR = (BYTE) 0x0014;	/* ctrl-T */
        CORB  = (BYTE) 0x0017;   	/* ctrl-W */

	lcfo(1,SAVCURD,32); 
	lcfo(4,SAVCURB,32); 
	lcfo(3,SAVCURH,32); 
	lcfo(2,SAVCURG,32); 
	lcfo(0x00AC,ST7F,32); 

	/* sauvegarde des touches fonction */
	nbtfp = conf(9);

	if (nbtfp >= 10) {
#ifdef prologue
		for (i=128; i < 138; i++) {
			lcfo(i,epstfp[i-128],LGTFP);
			lcfo(i,epltfp[i-128],LGTFP);
			}
#else
		for (i=128; i < 138; i++) {
#ifdef vms
			epltfp[i-128][0] = EOSTR;
#else
			lcfo(i,epltfp[i-128],LGTFP);
#endif
			}
#endif
		}
	return;
}


/*
 *	I N I T I A L I S E _ P O I N T I N G _ D E V I C E
 *	---------------------------------------------------
 *	activation and initialistion of mouse subsystem.
 *
 */


static	void	initialise_pointing_device()
{
#ifdef souris
	SWORD  s,bouton;
#endif
#ifdef souris
#ifdef	ver2K
	env_mouse = initialise_editor_mouse();
#else
	if (getenv("MOUSE") != GenericNULL(char) ) {
		env_mouse = 1;
		}
	else 	env_mouse = 0;

	if (env_mouse) {
		bouton = 0;
		s = InitSouris(&bouton);
		LimitSouris(1,(SWORD) ((LGINIT-1)*8), (SWORD) ((MXLIG-1)*8));
		LimitSouris(0,1,MXCOL*8);
		}
#endif
#endif
	return;
}

/*
 *	D R A W _ E D I T O R _ S C R E E N 
 *	-----------------------------------
 *	draws the top bar and stupid messages.
 *
 */

public	void	horizontal_rule( int atlin, int atcol, int nbcol )
{
	int	i;
	if ( flg_cico > 1 )
		graphical_rule(atlin,atcol,nbcol);
	else	{
		Xatb(0);
		pos(atlin,atcol);
		for (i = 1; i <= (nbcol+1); i++)  { putch(TRAIT); }
		}
	return;
}

static	void	draw_editor_screen()
{
	int	i;
	x_bstart();
	Xatb(0);
	pos(1,1);
	Xatb(21);
	x_cprintf((BYTE FPTR)edit_msg[msgfic]);
	for (i=(SWORD)(Xstrlen(edit_msg[msgfic])); i < MXCOL; i++)
		x_putch(' ');
	show_filename((char *) 0);
	horizontal_rule(2,1,MXCOL);
	Xatb(0);
	x_bflush();
	return;
}


/*	------------------------------------	*/
/*		I N I T E C R A N ()		*/
/*		--------------------		*/
/*	initialisation de la gestion d'ecran	*/
/*	------------------------------------	*/

static VOID initecran ()
{
	initialise_screen_hardware();
	initialise_screen_software();
	initialise_keyboard();
	initialise_pointing_device();
	return;
}

public	VOID	editorInitEcran()
{
	initecran();
	return;
}

#endif	/* _edinit_c */
	/* --------- */

