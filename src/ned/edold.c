/*	--------------------------------------------------------------- */
/*	This file contains the old code before ver14 for initialisation	*/
/*	etc of the screen subsystem.					*/
/*	tidy up ijm : 02/04/2003 					*/
/*	--------------------------------------------------------------- */

/*	initialisation de la gestion d'ecran
static VOID initecran ()
 */
{					/* initecran */
	SWORD	i;

#ifndef integre
	prndest = 1;
	if (flg_cico == FALSE) {
		initerm(); flg_cico = TRUE;
		}
#endif
	x_clear(); 
	curs_is_on = TRUE;
	if (traceon)
		LGINIT = 5;
	else	LGINIT = 3;

	CLINIT = 1;

  	MXLIG = conf(1);
	MXCOL = (SWORD) (conf(2) - 1);

	if ( NBMXLIG < (SWORD) (( (MXLIG + 1) - LGINIT)) )
		Xerreur(FATALE,ernoy03);

	NBLIG = (SWORD) ((MXLIG + 1) - LGINIT);

	i = conf(11);
	flg_InsLgn = flg_DelLgn = TRUE;
	if ((i & 0x04) == 0) flg_InsLgn = FALSE;
	if ((i & 0x08) == 0) flg_DelLgn = FALSE;

	x_bstart();

	x_cprintf(edit_msg[msgfic]);
	pos(2,1);
	for (i = 1; i <= MXCOL+1; i++)
		putch(TRAIT);

	if (traceon) {
		pos(3,1); atb(APU); x_putch(' '); x_cprintf((BYTE FPTR) curerr);
		Xatb(0); pos(4,1);
		for (i = 1; i <= MXCOL+1; i++)
			putch(TRAIT);
	}

	x_bflush();

	LGERR = 2; COLERR = 1;

#ifndef integre

	ESCAPE = (BYTE) 0x001B;
	INSERT = (BYTE) 0x000F;	/* ctrl-O */
	INDENT = (BYTE) 0x0016;	/* ctrl-V */
	UNDEL = (BYTE) 0x001A;	/* ctrl-Z */
	PGDN = (BYTE) 0x0003;	/* ctrl-C */
	PGUP = (BYTE) 0x0012;	/* ctrl-R */



	lcfo(1,SAVCURD,32); CURD = (BYTE) 0x0004; prfo(1,&CURD,1); /* ctrl-D */
	lcfo(4,SAVCURB,32); CURB = (BYTE) 0x0018; prfo(4,&CURB,1); /* ctrl-X */
	lcfo(3,SAVCURH,32); CURH = (BYTE) 0x0005; prfo(3,&CURH,1); /* ctrl-E */
	lcfo(2,SAVCURG,32); CURG = (BYTE) 0x0011; prfo(2,&CURG,1); /* ctrl-Q */

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

	CORB  = (BYTE) 0x0017;		/* ctrl-W */

#endif
	lcfo(0x00AC,ST7F,32); T7F = (BYTE) 0x007f; prfo(0x00ac,&T7F,1); /*Annul */

	ligne = LGINIT; colonne = CLINIT; pos(ligne,colonne);
}					/* initecran */

static VOID finecran()

/*	fin d'utilisation de l'ecran
 *	"VOID" si dans l'ensemble integre
 */
{					/* finecran */

#ifndef integre
	/* Vidage eventuel de la corbeil */
	if (tete != FNIL) {
		Raztamp();
		pos(1,68); putch(' ');
	}
	prfo(1,SAVCURD,Xstrlen(SAVCURD));
	prfo(4,SAVCURB,Xstrlen(SAVCURB));
	prfo(3,SAVCURH,Xstrlen(SAVCURH));
	prfo(2,SAVCURG,Xstrlen(SAVCURG));


	pos(LGINIT,CLINIT); atb(22); pos(LGINIT+1,1);
#endif
	prfo(0x00AC,ST7F,Xstrlen(ST7F));

#ifndef integre
	flg_cico = close_console();
#endif
}					/* finecran */

