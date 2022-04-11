#ifndef	_edsing_c
#define	_edsing_c

#include "edsing.h"

int	OnFailure=1;

int	editorGetPosition( char ** nptr, 
		unsigned long * lptr, 	/* current 	*/
		unsigned long * tptr, 	/* top or first */
		unsigned long * eptr	/* last		*/
		 )
{
	*nptr = (char *) &nomsrce;
	*lptr = numlgn;
	*tptr = (numlgn-ligcur);
	*eptr = ((numlgn-ligcur)+lastligne);
	return(1);
}

VOID	editorOnMain()
{
	if ( flg_cico > 1 )
		editorOnGraphic();
	else	editorOnText();
}



int	editorOnCreate(int argc, char * argv[] )
{
	int	argi;
	BYTE comtmp[255];
	BYTE XPTR paed;

	char *	eptr;

	OnFailure=1;
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	if (( eptr = (char *) getenv("AEDBELL")) != (char *) 0) {
		if (!( *eptr ))
			set_editor_bell( 0 );
		else if ( *eptr == '1' )
			set_editor_bell( 1 );
		else if ( *eptr == '0' )
			set_editor_bell( 0 );
		}
	else	set_editor_bell( 1 );

	set_filename_buffer((char *) 0);
#ifdef vms
	/* Jeux de caractere prologue */
	if (getenv("PROLOGUE") != GenericNULL(char) ) {
		TRAIT =	(BYTE) 0x00C4;	/* ligne horizontale */
	}
#endif
	nballoc = 0;
	boolbloc=boolbest=0;
	flg_help=FALSE;

	initabmes();

	/*
	flg_cico = FALSE; 
	*/
	/* pas encore d'init ecran */

#ifdef	ver2Kalloc
#ifdef	PRESCAN_PARAMETERS
	/* Prescan parameters for graphics options:     */
	/*	bios mode	-m<N>			*/
	/*	font names      -n0<name>		*/
	/*			-nN<name>		*/
	/* -------------------------------------------- */
	for ( argi=1; argi < argc; argi++ ) {
		if ((argp = argv[argi]) != (BYTE XPTR) 0) {
			if (( *argp == '-' ) 
			||  ( *argp == '/' )) {
				if (( *(argp+1) == 'm' )
				||  ( *(argp+1) == 'M' )) {
					set_bios_mode( (argp+2) );
					*(argp+1) = '+';
					*(argp+2) = 0;
					break;
					}
				if (( *(argp+1) == 'n' )
				||  ( *(argp+1) == 'N' )) {
					if ( *(argp+2) == '0' )
						fontz = (argp+3);
					else if ( *(argp+2) == '!' )
						fontn = (argp+3);
					else	{
						fontz = fontn = (argp+2);
						}
					*(argp+1) = '+';
					*(argp+2) = 0;
					break;
					}
				}
			}
		}
#endif
#endif

	if (argc-- < 2) { return(0); 	}

	/* initialisation generale a partir de la commande */

	paed = (BYTE XPTR) AEDPLUSPLUS;

	if (Xstrlen(paed) < 5)	EXTEND_AED = FALSE;
	else			EXTEND_AED = TRUE;

#ifdef ver14
	/* historique */
	init_his();
#endif
	if (initgene(argc,argv)) {
#ifdef ver14
		/* histo du premier fichier */
		Xstrcpy(comtmp,(BYTE XPTR) "O-");
		diff_repfich(n_path, nomsrce, &comtmp[2]); 
		maj_histo(comtmp);
#endif				

		/* initialiser le contenu de la memoire */
		initmem();

		posfin();
		maxnumlgn = numlgn;
		if (traceon) { editorOnTrace(); }
		else	     { posdeb();	}
		/* construction complete */
		OnFailure=0;
		return(1);

		}
	else	return(-1);

}

static	int	inhibitOnShow=0;

int	editorOnShow()
{
	int	holdline=ligne;
	int	holdcol =colonne;
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	use_editor_window(); 
	off_cursor();
	window_messages();
	affecran();
	draw_editor_scrollbar();
	on_cursor();
	ligne = holdline; 
	colonne = holdcol;
	return(0);
}

void	editorNoShow()
{
	inhibitOnShow = 1;
	return;
}

void	editorDoShow()
{
	inhibitOnShow = 0;
	editorOnShow();
	return;
}


int	editorOnGetFocus()
{
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}

	display_line_numbering();

	CURD = (BYTE) 0x0004; 
	prfo(1,&CURD,1); /* ctrl-D */
	CURB = (BYTE) 0x0018; 
	prfo(4,&CURB,1); /* ctrl-X */
	CURH = (BYTE) 0x0005; 
	prfo(3,&CURH,1); /* ctrl-E */
	CURG = (BYTE) 0x0011; 
	prfo(2,&CURG,1); /* ctrl-Q */
	T7F = (BYTE) 0x007f; 
	prfo(0x00ac,&T7F,1); /*Annul */

	pos(ligne,colonne);
	video_cursor_on();
	on_cursor();
	return((ligne > 0 ? ligne-1:0));
}

int	editorFocusLine(int mode)
{
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	if ( mode )
		editorOnGetFocus();
	else	editorOnLoseFocus();
	pos(ligne,colonne);
	return(0);
}

int	editorOnUseEvent(int event)
{
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	return(use_video_event(event));
}

int	editorOnUseString(char * sptr)
{
	if ( OnFailure )
		return(0);
	editorOnGetFocus();
	while ( *sptr )
		editorOnUseEvent((*(sptr++) & 0x00FF));
	editorOnLoseFocus();
	return(0);
}

int	editorOnLoseFocus()
{
	if ( OnFailure )
		return(0);
	video_cursor_off(boolcor);
	off_cursor();
	prfo(1,SAVCURD,32); 
	prfo(4,SAVCURB,32); 
	prfo(3,SAVCURH,32); 
	prfo(2,SAVCURG,32); 
	prfo(0x00AC,ST7F,32); 
	return(0);
}

int	editorOnExec()
{
	int	event;
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	do	{
		editorOnGetFocus();
		event = x_getch();
		editorOnLoseFocus();
		}
	while (!( editorOnUseEvent(event) ));
	return(0);
}

int	editorOnHide()
{
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	finecran();
	return(0);
}


/*
 *	e d i t o r O n R e m o v e ( status )
 *	--------------------------------------
 *	
 *	destruction of editor context and success/failure
 *	result return.
 *
 */

int	editorOnRemove(int status)
{
	ChnFic	*p,*q;
	OnFailure=1;
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( 0 );
			}
		else	UseEdExit = 1;
		}
	if ( status ) {

		/* liberation de la memoire */
		if (fs != GenericNULL(TFILE)) {
			liberate(fs);
			}
		if (fret != GenericNULL(TFILE)) {
			liberate(fret);
			}

		if (fdest != GenericNULL(TFILE)) {
			liberate(fdest);
			}	

		p = deb_chnfic;
		while (p != GenericNULL(ChnFic)) {
			q = p->suiv; liberate(p); p = q;
			}

		libtampon();

#ifdef ver14
		/* historique */
		purge();
		if (traceon) {
			terminate_trace_controller();
			}
#endif	
		}
#ifdef unix
	PurgeLox();
#endif

#ifdef	ver2Kalloc
	fin2000();
#endif
	if ( status == 1 ) {

		/* Success */
		/* ------- */
#ifndef vms
		return((SWORD) (0 | VAL_RET));
#else
		return(1 | VAL_RET );
#endif
		}
	else	{
		/* Failure */
		/* ------- */
#ifdef unix
		PurgeLox();
#endif
#ifdef	ver2Kaloc
		fin2000();
#endif
#ifndef vms
		return((SWORD) (0 | VAL_RET));
#else
		return(VAL_RET | STS$M_INHIB_MSG);
#endif
		}

	return(0);
}

int	editorOnHigh(int atlin, int nb)
{
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	poslgn(0,atlin+1);
	boolcor=1;
	Debtaq();
	poslgn(0,atlin+1+nb);
	Fintaq();
	return(0);
}

int	editorOnSeek(int sens, int nb )
{
	int	status;
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	use_editor_window();
	off_cursor();
	status = poslgn(sens,nb);
	on_cursor();
	return(status);
}

int	editorOnSearch(char * criteria, int respect, int direction )
{
	int	noerr;
	int	majhold=get_maj_min();
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	set_maj_min(respect);
	off_cursor(); 
	editorOnLoseFocus();
	if (direction) {
		noerr = brecher((SWORD)1,criteria);
		}
	else 	{
		noerr = recherche((SWORD)1,criteria);
		}
	editorOnGetFocus();
	on_cursor();
	set_maj_min(majhold);
	return(0);
}

int	editorOnReplace(char * sptr,char * rptr, int respect, int direction, int doall )
{
	int	noerr;
	if ( OnFailure )
		return(0);
	if (!( UseEdMain )) {
		if (Xsetjmp(Ed_Exit) != 0) {
			return( editorOnRemove(0) );
			}
		else	UseEdExit = 1;
		}
	off_cursor(); 
	editorOnLoseFocus();

	while ((noerr = replace((SWORD)1,sptr,rptr)) != 0)
		if (!( doall ))
			break;

	editorOnGetFocus();
	on_cursor();
	return(0);
}

#endif	/* _edsing_c */
	/* --------- */

