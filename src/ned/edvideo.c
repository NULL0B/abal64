#define __MSC
/*------------------------------------------------------ EDVIDEO.C ----------
 *
 *	Editeur de textes ABAL	  -	Copyright Amenesik / Sologic s.a. (c) 1989,97
 *
 *		    Gestion des commandes en mode "page"
 *
 *			Revision 1.0 du 13/10/1997
 *
 * Corrections :
 * 13/10/97 : Gestion de plus de 65000 lignes (YT131097)
 *
 * 21/03/2000 : Gestion de plus de 320 characters (IJM) (ver2K)
 * 01/04/2003 - 10/05/2003 : tellement de truc qu'il est dificile 
 * d'en raconter tout.
 *-------------------------------------------------------------------------*/
#ifndef	_edvideo_c
#define	_edvideo_c

#include "ed.h"
#include "edvideo.h"
#include "edmouse.h"

void	editorPageDown();
void	editorPageUp();
void	increment_line_counter();
void	decrement_line_counter();
void	HyperText();

BYTE buf_getch[80];
BINAIRE index_buf;

int	down_line=0;
int	down_column=0;
int	down_button=0;

int	is_graphical=0;

int	INDENT_MSG_COL=30;
int	INSERT_MSG_COL=41;
int	BASKET_MSG_COL=52;

extern 	int env_mouse;
extern	int dragfactor;

extern BOOL EXTEND_AED;

BOOL	corbeilOnCreate();
BOOL	corbeilOnShow();
BOOL	corbeilOnHide();
SWORD	corbeilOnUseEvent(SWORD);
BOOL	corbeilOnRemove();
void	set_is_graphical()	{	is_graphical=2; return;		}

/*
 *	First we find the various MESSAGE show and wipe functions 
 *	which were previously repeated every time needed with
 *	various bugs and errors.
 *
 *	Due to the graphical conversion work these have been 
 *	consolidated here as unique functions which check their
 *	column coordinate in case the screen width is too small.
 *
 *	wipe/show insert_message
 *	wipe/show indent_message
 *	wipe/show basket_message
 *	     show basket_options
 *	wipe/show line_numbering
 *	     show line_number
 *	     show column_number 
 *
 */

char	bufnomfic[128];

char *	get_filename_buffer()
{
	return( bufnomfic );
}

void	set_filename_buffer(char * nptr)
{
	if (!( nptr )) 	
		bufnomfic[0] = 0;
	else	strcpy(bufnomfic,nptr);
	return;
}

void	show_filename( char * nptr )
{
	int	barline;
	int	i;
	int	l;

	if ( (barline = get_status_line()) != 0 ) {
		if ( nptr )
			strcpy(bufnomfic,nptr);
		l = strlen(bufnomfic);
		Xatb(102); pos(barline,11);
		x_cprintf((BYTE FPTR) bufnomfic);
		Xatb(0);
		for (i=l; i < 16; i++ )
			x_putch(' ');
		}
	return;
}

void	show_line_number(BYTE FPTR lptr)
{
	int	latcol=57;
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( latcol + Xstrlen((BYTE FPTR) lptr)) <= MXCOL) {
			Xatb(0);
			pos(barline,latcol);
			x_cprintf((BYTE FPTR)lptr);
			}
		}
	return;
}

void	show_column_number(BYTE FPTR cptr)
{
	int	latcol=75;
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( latcol + Xstrlen((BYTE FPTR) cptr)) <= MXCOL) {
			Xatb(0);
			pos(barline,latcol);
			x_cprintf((BYTE FPTR)cptr);
			}
		}
	return;
}

void	show_line_numbering()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (flg_affnbln) {
			if (( _MESSAGE_COL1 + Xstrlen( (BYTE FPTR)edit_msg[msglgn])) < MXCOL ) {
				Xatb(0);
				pos(barline,_MESSAGE_COL1); 
				x_cprintf((BYTE FPTR)edit_msg[msglgn]);
				if (( _MESSAGE_COL2 + Xstrlen( (BYTE FPTR)edit_msg[msgcol])) < MXCOL ) {
					pos(barline,_MESSAGE_COL2); 
					x_cprintf((BYTE FPTR)edit_msg[msgcol]);
					}
				Xatb(0);
				}
			}
		}
	else	{
		editorOnStatus( 2, numlgn );
		}
	return;
}

void	wipe_line_numbering()
{
	int	i;
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( _MESSAGE_COL1 + Xstrlen( (BYTE FPTR)edit_msg[msglgn])) < MXCOL ) {
			pos(barline,_MESSAGE_COL1); 
			Xatb(0); 
			Xatb(21); 
			}
		horizontal_rule(barline+1,1,MXCOL);
		Xatb(0);
		}
	return;
}

void	show_insert_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (flg_insert) {
			if (( INSERT_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgins])) < MXCOL ) {
				pos(barline,INSERT_MSG_COL);
				Xatb(102);
				x_cprintf((BYTE FPTR)edit_msg[msgins]); 
				Xatb(0);
				}
			}
		}
	else	{
		editorOnStatus( 1,flg_insert );
		}

	return;
}

void	wipe_insert_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( INSERT_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgins])) < MXCOL ) {
			pos(barline,INSERT_MSG_COL); 
			Xatb(21);
			}
		show_line_numbering();
		}
	else	{
		editorOnStatus( 1, flg_insert );
		}
	return;
}

void	show_indent_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (flg_indent) {
			if (( INDENT_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgidt])) < MXCOL ) {
				pos(barline,INDENT_MSG_COL);
				Xatb(102);
				x_cprintf((BYTE FPTR)edit_msg[msgidt]); 
				Xatb(0);
				}
			}
		}
	else	{
		/* editorOnStatus( 2, flg_indent ); */
		}
	return;
}

void	wipe_indent_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( INDENT_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgidt])) < MXCOL ) {
			pos(barline,INDENT_MSG_COL); 
			Xatb(21);
			}
		show_insert_message();
		show_line_numbering();
		}
	else	{
		/* editorOnStatus( 2, flg_indent ); */
		}
	return;
}

static	void	show_basket_full()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if ( MXCOL > 65 ) {
			off_cursor();
			pos(barline,65); 
			Xatb(102); 
			x_putch(edit_msg[msgaff][0]); 
			Xatb(0);
			on_cursor();
			}
		}
	return;
}

static	void	show_basket_star()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if ( MXCOL > 68 ) {
			pos(barline,68); 
			Xatb(2); 
			putch('*');
			Xatb(0);
			}
		}
	return;
}

static	void	wipe_basket_full()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if ( MXCOL > 65 ) {
			pos(barline,65); 
			Xatb(21); 
			putch(' ');
			Xatb(0);
			}
		}
	return;
}

static	void	wipe_basket_star()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if ( MXCOL > 68 ) {
			pos(barline,68); 
			Xatb(0); 
			putch(' ');
			Xatb(0);
			}
		}
	return;
}

void	show_basket_options()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {

		/* Clear to the end of line */
		/* ------------------------ */
		if ( MXCOL > 63 ) { pos(barline,63);  Xatb(21); }

		if (boolbest) {
			if ( MXCOL > 63 ) {
				pos(barline,63); 
				Xatb(102); 
				x_putch(edit_msg[msgaff][2]); 
				Xatb(0);
				}
			}
#ifdef ver14
		if (boolbloc) {
			if ( MXCOL > 64 ) {
				pos(barline,64); Xatb(102); 
				x_putch(edit_msg[msgaff][1]); 
				Xatb(0);
				}
			}
#endif
		/* Test si presence de corbeille dans le tampon */
		if (tete != FNIL) {
			show_basket_full();
			}
		}
	return;
}

void	hide_basket_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( BASKET_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgcor])) < MXCOL ) {
			pos(barline,BASKET_MSG_COL); 
			Xatb(21);  Xatb(0);
			}
		}
	else	{
		editorOnStatus( 4, 0 );
		}
	return;
}

void	show_basket_message()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		if (( BASKET_MSG_COL + Xstrlen( (BYTE FPTR)edit_msg[msgcor])) < MXCOL ) {
			pos(barline,BASKET_MSG_COL); 
			Xatb(21); Xatb(102);
			x_cprintf((BYTE FPTR)edit_msg[msgcor]); 
			Xatb(0);
			}
		}
	else	{
		editorOnStatus( 4, 4 );
		}
	return;
}

void	show_messages()
{
	int	barline;
	if ( (barline = get_status_line()) != 0 ) {
		show_indent_message();
		show_insert_message();
		show_line_numbering();
		}
	return;
}


/* -------------------------------------------------------- */
/* Who knows what this one is all about, I don't use it ... */
/* -------------------------------------------------------- */

SWORD mouse_getch()
{
	SWORD c;

#ifdef souris
if (env_mouse) {
	 PopSouris();
         while (1) {	
		s = PresseSouris(0,&sx,&sy);
		if (s) {
			/* Bouton gauche */
			for (s=0; s < 40000; s++);
			s = StateSouris(&sx,&sy);
			if (s) {
				sx = (sx/8) +1;
				sy = (sy/8) + 1;
				cursor_goto(sy,sx);			
				PushSouris();
				while ( s != 0 ) {
					if (sy == LGINIT ) {
						if (!( Montee() ))
							break;
						}
					else if ( sy ==  MXLIG) {
						if (!( Descente() ))
							break;
						}
					else	break;
					for (s=0; s < 40000; s++);
					s = StateSouris(&sx,&sy);
					sx = (sx/8) +1;
					sy = (sy/8) + 1;
					}
				PopSouris();
				mouse_col = sx;
				mouse_lin = sy;
				mouse_bouton = 4;
				}
			else	{
				mouse_bouton = 0;
				mouse_col = (sx / 8) + 1;
				mouse_lin = (sy / 8) + 1;
				}
			c = MOUSE;
			break;
			}				
		else	{
			s = PresseSouris(1,&sx,&sy);
			if (s) {
				/* Bouton droit */
				/* Tempo */
				for (s=0; s < 40000; s++);
				s = StateSouris(&sx,&sy);
				if (s) {
					while ( s != 0 ) {
						for (s=0; s < 40000; s++);
						s = StateSouris(&sx,&sy);
					}
					mouse_bouton = 3;
				}
				else {
					mouse_bouton = 1;
				}

				mouse_col = (sx / 8) + 1;
				mouse_lin = (sy / 8) + 1;

				c = MOUSE;
				break;
				}				
			else	{
				if (x_kbhit()) {
					c = x_getch();
					break;
					}	
				}
			}
            	}
	PushSouris();
	}
else	{

#endif
	c = x_getch();
	return(c);

}
	
BYTE	video_cursor_on()
{
	BYTE	curcar=0;
	BYTE	outcar;
	if (EXTEND_AED == TRUE) {
		curcar = getmemchar(ligcur,colcur);
		if (curcar == EOSTR || curcar == TABUL || curcar >= 0x0020) {
			if (curcar == EOSTR || curcar == TABUL ) {
				if ( curcar == TABUL ) 
					outcar = 'I';
				else	outcar = ' ';
				}
			else	{	
				outcar = curcar;
				}
			pos(ligne,colonne); 
			foregr(15); backgr(1);
			putch(outcar); 
			Xatb(0);
			pos(ligne,colonne);
			}
		}
	return( curcar );
}	

void	video_cursor_off(int corbeil)
{
	BYTE	curcar=0;
	BYTE	outcar=0;
	if (EXTEND_AED == TRUE ) {
		if ( curcar == 0 )
			curcar = getmemchar(ligcur,colcur);
		if (curcar == EOSTR || curcar == TABUL || curcar >= 0x0020) {
			if ( curcar == TABUL ) 
				outcar = ' ';
			else if ( curcar == EOSTR )
				outcar = ' ';
			else	outcar = curcar;
			if (!( corbeil )) 
				Xatb(0);
			else if ( test_corbeil( numlgn, colcur ) ) 
				/* Inside the clipboard zone */
				Xatb(2);
			else if ( test_bloc(numlgn) )
				/* Inside the clipboard zone */
				Xatb(2);
			else	Xatb(0);
			pos(ligne,colonne);
			check_shadow_colour(ligcur,colcur);
			putch(outcar);
			pos(ligne,colonne);
			}
		}
	return;
}

/*	gestion du mode video	 */
/*	---------------------	*/

#define	WORD	unsigned short;

int	video_mouse_event()
{
	int	rep=0;
	int	event;
	int	old_downer=0;

	/* Test for Special Case : Enter Command Mode */
	/* ------------------------------------------ */
	if ( ned_mouse_line() < LGINIT ) {
		if ( get_mouse_event() == _MIMO_UP )
			rep = ESCAPE;
		else	return(0);
		}
	else if ( ned_mouse_line() >= (NBLIG + LGINIT) ) {
		if ( get_mouse_event() == _MIMO_UP )
			rep = PGDN;
		else	return(0);
		}
	else	{
		switch ((event = get_mouse_event())) {
			case	_MIMO_WHILE_DOWN:
			case	_MIMO_IS_DOWN	:
				if ( down_button != 0 ) {
					if (( down_button == _MIMO_RIGHT )
					&&  ( boolcor )) {
						cursor_goto(ned_mouse_line(),ned_mouse_column());
						corbeilOnUseEvent('B');
						}
					return(0);
					}

			case	_MIMO_DOWN	:

				if (!( is_editor_scrollbar_event() )) {
					down_column = ned_mouse_column();
					down_line   = ned_mouse_line();
					if ((down_button = get_mouse_button()) == _MIMO_RIGHT) {
						if ( boolcor ) {
							corbeilOnUseEvent('R');
							corbeilOnHide();
							corbeilOnRemove();
							}
						corbeilOnCreate();
						corbeilOnShow();
						cursor_goto(down_line,down_column);
						corbeilOnUseEvent('A');
						}
					}
				return(0);

			case	_MIMO_UP	:
				if ( down_button == _MIMO_RIGHT ) {
					if ( boolcor ) {
						cursor_goto(ned_mouse_line(),ned_mouse_column());
						corbeilOnUseEvent('B');
						corbeilOnUseEvent('C');
						}
					return((down_button = 0));
					}
				else if ( down_button == _MIMO_WHEELUP ) {
					editorPageUp();
					return((down_button = 0));
					}
				else if ( down_button == _MIMO_WHEELDOWN ) {
					editorPageDown();
					return((down_button = 0));
					}
				else if ( down_button != 0 ) {
					if ( down_line == ned_mouse_line() ) {
						cursor_goto(ned_mouse_line(),ned_mouse_column());
						if ((mouse_bouton = get_mouse_button()) == _MIMO_RIGHT)  {
							Razcorb();
							rep = CORB;
							down_button = down_column = down_line=0;
							break;
							}
						}
					else if ( down_line < ned_mouse_line() ) {
						if ( down_button == _MIMO_LEFT ) {
							if ((ned_mouse_line()-down_line) > dragfactor )
								editorPageUp();
							else	{
								cursor_goto(down_line,down_column );
								Centrage();
								}
							}
						else	posdeb();
						}
					else if ( down_button == _MIMO_LEFT ) {
						if ((down_line - ned_mouse_line()) > dragfactor)
							editorPageDown();
						else	{
							cursor_goto(down_line,down_column );
							Centrage();
							}
						}
					else	posfin();
					down_button = down_column = down_line=0;
					return(0);
					}

			case	_MIMO_CLICK	:
			case	_MIMO_DOUBLE	:
				cursor_goto(ned_mouse_line(),ned_mouse_column());			
				return((down_button = 0));

			case	_MIMO_KEYBOARD	:
				rep = get_mouse_button();
				break;
			default			:
				return(0);
			}
		}
	return(rep);
}
		
int	standard_use_video_event( int  event )
{
	BOOL	FINI = FALSE;
	BYTE	rep;

	if ((event == 256)
	&& (!(event = video_mouse_event())))
		return((FINI=FALSE));
	else	rep = (event & 0x00FF);

	if (rep == T7F) 
		Delcar();
	else if ctrlbyte(rep) {	/* caractere de controle ? */
		if (rep == ESCAPE) {
			flg_undel = 0; /* 'UnDelete' impossible */
			editorOnGetFocus();
			FINI = commande();
			editorOnLoseFocus();
			if (flg_affnbln && !FINI) {
				show_line_numbering();
				pos(ligne,colonne);
				}
			}
		else	{
			off_cursor();
			if (rep == CR) 		{ NewLine(); 	}
#ifdef	VERSION666
			else if (rep == 0x001A) { HyperText();	}
#endif
			else if (rep == PGDN) 	{ editorPageDown(); }
			else if (rep == PGUP) 	{ editorPageUp();}
			else if (rep == CURH) 	{ Montee(); 	}
			else if (rep == CURG) 	{ Precedent();	} 
			else if (rep == CURD) 	{ Suivant();	}
			else if (rep == CURB) 	{ Descente();   }
			else if (rep == TABUL) 	{ saisie(rep);	}
			else if (rep == NEXTWORD){ NextWord(); 	}
			else if (rep == PREVWORD){ BackWord(); 	}
			else if (rep == DELCAR) { Delcar();	}
			else if (rep == DELBACK){ Backspace();	}
			else if (rep == DLINE) 	{ Deline();	}
			else if (rep == ILINE) 	{ Insline();	}
			else if (rep == DEOLN) 	{ Delfline();	}
			else if (rep == DBOLN) 	{ Deldline();	}
			else if (rep == PDEBFIN){ DebutFin();	}
			else if (rep == PHOME) 	{ HomeEnd();	}
			else if (rep == CENTER) { Centrage();	}
			else if (rep == CTRLHOME){Debut();	}
#ifndef integre
#ifndef ver11
			else if (rep == CORB) {
				if ( corbeilOnCreate() != 0 )
					corbeilOnShow();
#ifdef	OLD_BASKET_MODE
				editorOnGetFocus();
				rep = Corbeil();
				editorOnLoseFocus();
				if ( rep != 0 ) 
					return((FINI=TRUE));
							/* Fin de aed */
#endif
				}			/* Sniff !!!*/	
#endif
#endif
			else if (rep == INSERT) {
			     	if (flg_insert) {
					flg_insert = FALSE;
					wipe_insert_message();
					}
				else	{
					flg_insert = TRUE;
					show_insert_message();
				     	}
				pos(ligne,colonne);
				}
			else if (rep == INDENT) {
#ifdef ver21
			     	if (traceon) {
					poserrback();
			     		}
			     	else	{
#endif
					if (flg_indent) {
						flg_indent = FALSE;
						wipe_indent_message();
						}
				      else	{
						flg_indent = TRUE; 
						show_indent_message();
						}
					pos(ligne,colonne);
#ifdef ver21
				     	}
#endif
				}
			else if (rep == UNDEL) UnDelete();
			else if (rep == NEXTERR) {
				if (traceon) 
					poserrsuiv();
				else	editor_bell();
				}
			else if (rep == NUMLN) {
				if (!( is_window_editor() )) {
				     	if (flg_affnbln) {
						flg_affnbln = FALSE;
						wipe_line_numbering();
				     		}
				     	else	{
						flg_affnbln = TRUE;
						show_line_numbering();
				     		}	
					pos(ligne,colonne);
					}
				}
			on_cursor();
			}
		}
	else	{
		off_cursor(); 
		if (rep != MOUSE) saisie(rep); 
		on_cursor();
		}
	return(FINI);
}					/* video */

int	use_video_event( int  event )
{
	if (!( boolcor ))
		return( standard_use_video_event( event ) );
	else	return( corbeilOnUseEvent( event ) );
}

void 	video()
{
	BYTE	rep,i;
	BOOL	FINI = FALSE;

	BYTE	curcar;
	BYTE	outcar;	
	int	event;

	colbest = colonne;
	fcolbest = firstcol;

#ifndef ver21
	flg_insert = flg_indent = FALSE;
	flg_affnbln = FALSE;
#else
	window_messages();
	pos(ligne,colonne);
#endif	
	com[0] = EOSTR;
	flg_undel = 0;

	do 	{

		editorOnGetFocus();
		event  = x_getch();
		editorOnLoseFocus();
		FINI = use_video_event(event);
		}
	while (!FINI);
	return;
}

void cursor_goto(SWORD l, SWORD c)
{
	BOOL sbool;
	SWORD  scol;
	SWORD sfirst;
	SWORD smcol;
	SWORD smfirst;

	smcol   = c;
	smfirst = firstcol;
	
	if (l < ligne) {
		while ( l != ligne) {
			if (!(Montee()))
				break;
			}
		}
	else if (l > ligne) {
		while ( l != ligne) {
			if (!(Descente()))
				break;
			}
		}

	sbool = boolbest;
	if (sbool) {
		scol = colbest;
		sfirst = fcolbest;
		}

	boolbest = 1;
	colbest = smcol;
	fcolbest = smfirst; 	
	newcol(FALSE);

	boolbest = sbool;
	if (sbool) {
		colbest = scol;
		fcolbest = fcolbest;
	}
}

/*global*/ BOOL carvisu( BYTE c)
{
	if (c < 0x20) return(FALSE);

	return(TRUE);
}

void editorPageDown ()

/*	avancer d'une page	 */

{					/* PageDown */
	SWORD	i,cptligne;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (fs->Feof && fret->Feof) {
		/* pas de "scrolling" si source et retour sont vides */
		numlgn += (SWORD) (lastligne - ligcur);
		ligcur = lastligne; ligne = (SWORD) (lastligne + LGINIT);
		/* voir si il faut deplacer le curseur */
		newcol(FALSE);
		return;
		}
	/* mettre la memoire affichee dans le fichier destination */
	for (i = 0; i <= lastligne; i++) 
		putdest(adrmemlin(i));
	lastligne = i = 0; cptligne = LGINIT;
	/* remplir la memoire avec le contenu du fichier retour */
	while (cptligne <= MXLIG) {
		if (!getret(adrmemlin(i))) /* fin du fichier retour */
			break;
		cptligne++; lastligne = i; i++;
		}
	/* completer si necessaire avec le contenu du source */
	if (!tstfinsource()) {
		while (cptligne <= MXLIG) {
			if (!getsource(adrmemlin(i))) /* fin du fichier source */
				break;
			cptligne++; lastligne = i; i++;
	   		}
		}
	numlgn = (LONG) (fdest->nblgn + 1);

	ligcur = 0; ligne = LGINIT;
	/* voir si il faut deplacer le curseur */
	newcol(TRUE);
}					/* PageDown */


/*	------------------	*/
/*	avancer d'une page	*/
/*	------------------	*/

void editorPageUp ()
{					/* PageUp */
	SWORD	j,cptligne;
	SWORD i;
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (fdest->Feof) {
		 /* destination vide : le debut du fichier est deja affiche */
		numlgn -= ligcur;
		ligcur = 0; ligne = LGINIT;
		/* voir si il faut deplacer le curseur */
		newcol(FALSE);
		return;
	}
	/* mettre la memoire affichee dans le fichier retour */
	for (i = lastligne; i > 0; i--) putret(adrmemlin(i));
	putret(adrmemlin(0)); cptligne = MXLIG; i = NBLIG;
	/* remplir la memoire avec le contenu du fichier destination */
	while (i != 0) {
		i--;
		if (!getdest(adrmemlin(i))) { /* destination est vide */
			/* decaler en memoire pour remonter les lignes */
			cptligne = LGINIT;
			for ( i += 1, j = 0; i < (SWORD) NBLIG; j++ , i++) {
				Xstrcpy(adrmemlin(j),adrmemlin(i)); cptligne++;
				}
			/* completer avec le contenu du fichier retour */
			while (cptligne <= MXLIG) {
				getret(adrmemlin(j)); /* retour ne peut etre vide */
				cptligne++; j++;
				}
			break;
			}
		cptligne--;
		if (cptligne < LGINIT) { /* ecran est plein */
			if (i != 0) {	  /* decalage ecran <-> memoire */
				for ( j = 0; i < (SWORD) NBLIG; j++ , i++)
					Xstrcpy(adrmemlin(j),adrmemlin(i));
				}
			break;
			}
		}

	numlgn = (LONG) (fdest->nblgn + NBLIG);

	ligcur = lastligne = (SWORD) (NBLIG - 1); ligne = MXLIG;
	/* voir si il faut deplacer le curseur */
	newcol(TRUE);
}					/* PageUp */

/*	-------------------------------	*/
/*	Montee d'une ligne dans l'ecran	*/
/*	-------------------------------	*/
int	Montee()

{					
	SWORD savecol,savelgn;
	SWORD i;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	
	if ( numlgn <= 1 )	return(0);

	numlgn--;	/* on vient de passer a la ligne precedente */

	if (ligne == LGINIT) {	/* scrolling necessaire */
		if (fdest->Feof) {
			if (colonne > MXCOL) 
				colonne = CLINIT;
			numlgn++;
			draw_editor_scrollbar();
			return(0);	/* impossible si destination vide */
			}
		if (lastligne < NBLIG-1)
			lastligne++; /* decalage en memoire suffit */
		else	putret(adrmemlin(lastligne));

		/* decaler en memoire */
		for (i = lastligne; i > 0; i--)
			Xstrcpy(adrmemlin(i),adrmemlin((i-1))); /* May be hidden bug here */
		/* completer la memoire par lecture dans destination */
		getdest(adrmemlin(0)); /* qui n'est pas vide !! */
		ligcur = 0; ligne = LGINIT;
		if (colonne > MXCOL) {	/* scrolling a droite <- (Precedent)*/
			colcur = (SWORD) Xstrlen(adrmemlin(ligcur));
			if (colcur == 0)
				colonne = CLINIT;
			else	{
				colonne = (SWORD) (Lgnlen(adrmemlin(ligcur)) + 1);
				if (getmemchar(ligcur,(colcur-1)) == TABUL && getmemchar(ligcur,colcur) == EOSTR) 
					colonne--;

				while (colonne > MXCOL) {
					firstcol += (SWORD) (MXCOL / 2);
					colonne -= (SWORD) (MXCOL / 2);
					}
				}	
			editorOnShow();
			ligne = LGINIT;
			pos(ligne,colonne);
			}
		else	{  /* voir si il faut deplacer le curseur */
			if (flg_InsLgn) {
				/* possibilite d'exploiter le terminal */
				savecol = colonne; 
				pos(LGINIT,CLINIT); 
				atb(23);
				affligne(0); 
				colonne = savecol;
				newcol(FALSE);
				}
			else	newcol(TRUE);
			}	
		}
	else	{
		ligne--; ligcur--;
		if (colonne > MXCOL) {	/* scrolling a droite <- (Precedent) */
			colcur = (SWORD) (Xstrlen(adrmemlin(ligcur)));
			if (colcur == 0)
				colonne = CLINIT;
			else	{
				colonne = (SWORD) (Lgnlen(adrmemlin(ligcur)) + 1);
				if (getmemchar(ligcur,(colcur-1)) == TABUL && getmemchar(ligcur,colcur) == EOSTR) 
					colonne--;
				if (colonne > MXCOL) {
					while (colonne > MXCOL) {
						firstcol += (SWORD) (MXCOL / 2);
						colonne -= (SWORD) (MXCOL / 2);
						}
					editorOnShow();
					}
				}
			pos(ligne,colonne);
			}
		else	/* voir si il faut deplacer la position colonne */
			newcol(FALSE);
		}	
	draw_editor_scrollbar();
	return(1);
}

/*	---------------------------------	*/
/*	Descente d'une ligne dans l'ecran	*/
/*	---------------------------------	*/

int	Descente()
{
	SWORD	i,savecol;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	ligne++;

	fin_fichier = FALSE; /* test les fin de fichier */

	numlgn++;	/* on vient de passer a la ligne suivante */

	if (ligne > MXLIG) {	/* scrolling necessaire */
		ligne--;
		if (fret->Feof && tstfinsource()) {
			numlgn--; /* retour a la ligne courante */
			fin_fichier = TRUE;
			draw_editor_scrollbar();
			return(0);/* impossible si source et retour sont vides */
			}			
		putdest(adrmemlin(0));
		/* decaler en memoire */
		for (i = 0; i < lastligne; i++)
			Xstrcpy(adrmemlin(i),adrmemlin((i+1)));
		/* completer par lecture du fichier retour ou du source */
		if (!fret->Feof)
			getret(adrmemlin(lastligne));
		else	getsource(adrmemlin(lastligne));
		ligcur = lastligne; ligne = MXLIG;
		/* voir si il faut deplacer le curseur */
		if (flg_DelLgn) {
			savecol = colonne; pos(LGINIT,CLINIT); atb(24);
			affligne(ligcur); colonne = savecol;
			newcol(FALSE);
			}
		else	newcol(TRUE);
		}
	else	{
		ligcur++;
		if (ligcur > lastligne) {
			ligne--; ligcur--;
			numlgn--;
			fin_fichier = TRUE;
			return(0);
			}

		/* voir si il faut deplacer la position colonne */
		newcol(FALSE);
		}
	draw_editor_scrollbar();
	return(1);
}					/* Descente */

/*	------------------------------------	*/
/*	Passer au debut de la ligne suivante	*/
/*	------------------------------------	*/

static void NewLine()
{
	SWORD	i,savecol;
	SWORD sc;			/* Sauve ligne et colonne */
	BYTE	c;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	off_cursor();
	if (flg_insert)
		Insline();	/* commencer par inserer une ligne */

	if (!flg_indent) {
		colonne = CLINIT; colcur = 0;	/* a priori : debut de ligne = 0 */
		if (boolbest) {
			colbest = colonne;
			fcolbest = 0;
			}
		}
	ligne++;
	if (ligne > MXLIG) {	/* scrolling necessaire */
		ligne--;
		putdest(adrmemlin(0));
		/* decaler en memoire */
		for (i = 0; i < lastligne; i++)
			Xstrcpy(adrmemlin(i),adrmemlin((i+1)));
		/* completer par lecture du fichier retour ou du source */
		if (!fret->Feof)
			getret(adrmemlin(lastligne));
    		else if (!tstfinsource())
			getsource(adrmemlin(lastligne));
		else	{
			/* ajout d'une ligne en fin de fichier */
			putmemchar(lastligne,0,EOSTR);
			}
		ligcur = lastligne; ligne = MXLIG;
		/* voir si il faut deplacer le curseur */
		if (flg_DelLgn) {
			savecol = colonne; pos(LGINIT,CLINIT); atb(24);
			affligne(ligcur); colonne = savecol;
			newcol(FALSE);
			}
		else
			newcol(TRUE);
		}
	else	{
		ligcur++;
		if (ligcur > lastligne) {
			/* ajout d'une ligne en fin de fichier */
			lastligne++;
			putmemchar(lastligne,0,EOSTR);
			}
		newcol(FALSE);
		}
	numlgn++;	/* on vient de passer a la ligne suivante */
  	if (flg_indent && flg_insert) {
		i = 0; c = getmemchar(ligcur,(i++));
  		while ( (c == TABUL) || (c == ' ') ) {
			c = getmemchar(ligcur,i);
			i++;
			}
		i--;	
	   	colcur = i;
		c = getmemchar(ligcur,i);
		putmemchar(ligcur,i,EOSTR);
		affligne(ligcur);
		putmemchar(ligcur,i,c); i++;
		sc = colonne;
		x_bstart();
		while ((c != EOSTR) && (colonne <= MXCOL)) {
			if (c == TABUL) {
				NextTab(colonne, firstcol);
				if (colonne > MXCOL) break;
				pos(ligne,colonne);
				}
			else	{
				putch(c);
				colonne++;
				}
			c = getmemchar(ligcur,i); 
			i++;
			}

		colonne = sc;
		pos(ligne, colonne);
		x_bflush();
#ifdef ver14
	txtchg = TRUE;
#endif
	}  

	on_cursor();
	draw_editor_scrollbar();
	return;
}					/* NewLine */

/*	-------------------------------------------	*/
/*	Passage au caractere precedent dans l'ecran	*/
/*	-------------------------------------------	*/

static void Precedent()
{
	SWORD	i,savlgn,savcol;
	BOOL savebool;

	savebool = boolbest;
	boolbest = 0;	/* inhibe pour cette fonction */
	
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (colcur == 0) { /* passer a la ligne precedente */
		colonne = (SWORD) (MXCOL + 1); Montee();
		}
	else	{
		colcur--;
		if (getmemchar(ligcur,colcur) == TABUL) {
			/* cas particulier de la tabulation */
			colonne = 1;
			for (i = 0; i < colcur; i++) {
				if (getmemchar(ligcur,i) != TABUL)
					colonne++;
				else	NextTab(colonne,0);
				}
			}
		else	{
			colonne--; colonne += firstcol;
			}
		if (colonne <= firstcol) {
			firstcol -= (SWORD) (MXCOL / 2);
			editorOnShow();
			}
		colonne -= firstcol;
		pos(ligne,colonne);
		}

	boolbest = savebool; /* reactive boolbest */

	colbest = colonne;
	fcolbest = firstcol;
}					/* Precedent */

/*	-----------------------------------------	*/
/*	Passage au caractere suivant dans l'ecran	*/
/*	-----------------------------------------	*/

static void Suivant()
{
	SWORD	savlgn,savcol;
	BOOL savebool;


	savebool = boolbest;
	boolbest = 0;	/* inhibe pour cette fonction */
	
	flg_undel = 0;	/* plus de 'UnDelete' possible */

	if (getmemchar(ligcur,colcur) == TABUL) {
		/* cas particulier de la tabulation */
		NextTab(colonne,firstcol);
		colcur++;
		}
	else	{
		if (colcur == (SWORD) Xstrlen(adrmemlin(ligcur))) {
			/* passer a la ligne suivante */
			Descente();
			colcur = 0;
			colonne = CLINIT;	/* Passage en debut de ligne */
			newcol(FALSE);

			colbest = colonne;
			fcolbest = firstcol;
			boolbest = savebool; /* reactive boolbest */

			return;
			}
		else	{
			colonne++; colcur++;
			}
		}

	if (colonne > MXCOL) { /* scrolling horizontal necessaire */
		firstcol += (SWORD) (MXCOL / 2); colonne -= (SWORD) (MXCOL / 2);
		editorOnShow();
		}

	boolbest = savebool; /* reactive boolbest */

	colbest = colonne;
	fcolbest = firstcol;
	pos(ligne,colonne);

	return;

}					/* Suivant */

/*	----------------------		*/
/*	avancer au mot suivant		*/
/*	----------------------		*/

static void NextWord()
{
	BYTE	c;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	c = getmemchar(ligcur,colcur);
	while (Xisalnum(c)) {
		Suivant(); c = getmemchar(ligcur,colcur);
		if (colcur == 0)	/* changement de ligne */
			break;
		}
	while (!Xisalnum(c)) {
		Suivant(); c = getmemchar(ligcur,colcur);
		if (c == EOSTR) { /* risque de fin de fichier ... */
			if (fret->Feof && tstfinsource())
				break;
		}
	}
}					/* NextWord */

/*	------------------------	*/
/*	reculer au mot precedent	*/
/*	------------------------	*/

void 	BackWord()
{
	BYTE	c;

	flg_undel = 0;	/* plus de 'UnDelete' possible */

#ifdef MERDE
	do 	{
		if ((numlgn == 1) && (colcur == 0)) { 
			/* debut de fichier */
			return;
			}
		Precedent(); c = getmemchar(ligcur,colcur);
		}
	while (Xisalnum(c));
#endif
/* debut de mot */
	do 	{
		if ((numlgn == 1) && (colcur == 0)) { /* debut de fichier */
			return;
			}
		Precedent(); 
		c = getmemchar(ligcur,colcur);
		}
	while (!Xisalnum(c));

	/* on avale les non caracteres */

	do 	{
		if ((numlgn == 1) && (colcur == 0)) { /* debut de fichier */
			return;
			}
		Precedent(); 
		c = getmemchar(ligcur,colcur);
		}
	while (Xisalnum(c));
	Suivant();

}					/* BackWord */

#ifdef	VERSION666

/*	-------------------------	*/
/*	Locate Occurances of Text 	*/
/*	-------------------------	*/

#define	HYPER_TOKEN_SIZE 128
BPTR	HyperSearch=(BPTR) 0;
BPTR	HyperLink=(BPTR) 0;
BYTE	HyperToken[HYPER_TOKEN_SIZE+1];
BPTR	HyperFiles = "*.*";
BYTE	HyperSelection[320];
BYTE	HyperBuffer[320];

void	UseHyperFunkPath(BYTE * sptr)
{ 
	Xstrcpy( HyperSelection, sptr );
	HyperFiles = HyperSelection;
	return;
}

void	UseHyperFunkZone()
{
	if (!( HyperSearch )) return;
	sprintf(HyperBuffer,"agr -s%s %s",HyperSearch,HyperFiles);
	system(HyperBuffer);
	return;
}

static	int	HyperTextByte( BYTE c, int filetoken )
{
	if (( c >= 'A' ) && ( c <= 'Z' ))
		return(1);
	else if (( c >= 'a' ) && ( c <= 'z' ))
		return(1);
	else if (( c >= '0' ) && ( c <= '9' ))
		return(1);
	else if ( c == '_' )
		return(1);
	else if ( c == '.' )
		return(1);
	else if (!( filetoken ))
		return(0);
	else if ( filetoken & 1 ) {
		/* filename type required may include path information */
		/* --------------------------------------------------- */
#ifdef	UNIX
		if ( c == '/' )
			return(1);
#else
		else if ( c == '\\' )
			return(1);
#endif
		else	return(0);
		}
	else if ( filetoken & 2 ) {
		/* expression type required may include dimensions */
		/* ----------------------------------------------- */
		if ( c == '(' )
			return(1);
		else if ( c == ',' )
			return(1);
		else if ( c == ')' )
			return(1);
		else	return(0);
		}
	else	return( 0 );
}

/*	-----------------------------------------------------------	*/	
/*		e d i t o r G e t T o k e n ( result, option )		*/
/*	-----------------------------------------------------------	*/	
/*	Returns the token under the current cursor position in the	*/
/*	provided result buffer. The option value allows for the 	*/
/*	collection of :							*/
/*		0	name tokens, alpha,num,underline only		*/
/*		1	file tokens my include / or \ for system	*/
/*		2	may include () or , for variable dimensions	*/
/*	-----------------------------------------------------------	*/	

int	editorGetToken( char * hypertoken, int filetoken )
{
	int	c;
	int	i;
	int	hcolcur=colcur;
	int	hligcur=ligcur;
	do 	{
		if ((numlgn == 1) && (colcur == 0)) { 
			/* debut de fichier */
			break;
			}
		else	{
			Precedent(); 
			c = getmemchar(ligcur,colcur);
			}
		}
	while ( HyperTextByte( c, (filetoken&1) ) );	/* keep file request but inhibit expression request */

	if ( c == '"' ) {
		*hypertoken=c; i = 1;
		}
	else	i = 0;

	/* scan forward collecting characters */
	for ( 	; i < HYPER_TOKEN_SIZE; i++ ) {
		Suivant();
		if (colcur == 0)
			/* changement de ligne */
			break;
		else	{
			c = getmemchar(ligcur,colcur);
			if (!(HyperTextByte(c, filetoken) ))
				break;
			else	{
				*(hypertoken+i) =c;
				}
			}
		}
	*(hypertoken+i) = 0;
	while (( hcolcur != colcur ) && ( ligcur != hligcur )) {
		Precedent();
		c = getmemchar(ligcur,colcur);
		}
	return(i);
}


void	HyperText()
{
	BYTE 	autrefic[LGMXNOM], *paf;
	int	i;
	int	retvideo;
	ULONG 	machine;
	BYTE	c;

	flg_undel = 0;	/* plus de 'UnDelete' possible */

	editorGetToken( HyperToken, 0 );

	if (!( HyperToken[0] )) return;
	HyperSearch = HyperToken;
	if ( HyperToken[0] == '"' )
		HyperLink = &HyperToken[1];
	else	HyperLink = "\0";
	if ((retvideo = WizzardStop(HyperLink,&machine,autrefic)) != 0 ) {
		if (!( *HyperLink ))
			UseHyperFunkZone();
		(void) WizzardStart(HyperLink,&machine,autrefic);
		}
	return;
}


#endif

/*	--------------------------------	*/
/*	suppression de la ligne courante	*/
/*	--------------------------------	*/

static void Deline()
{
	SWORD	i,savlgn;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	flg_undel = 1;	/* 'UnDelete' sera possible 			*/
	decrement_line_counter();
	Xstrcpy(lgntemp,adrmemlin(ligcur));	/* garder la ligne pour cela */

	if (ligcur != lastligne) {
		/* ligne suivante en memoire : scrolling */
		for (i = ligcur; i < lastligne; i++)
			Xstrcpy(adrmemlin(i),adrmemlin((i+1))); 
		}

	if (!fret->Feof)
		getret(adrmemlin(lastligne));

	else if (!tstfinsource())
		getsource(adrmemlin(lastligne));

	else	{
		putmemchar(lastligne,0,EOSTR);
		if (lastligne > ligcur) {
			lastligne--;
			}
		}

	if (firstcol != 0) { /* il faut un scrolling a gauche */
		firstcol = 0; 
		editorOnShow();
		}
	else	{
		aff_ecran = TRUE;
		x_bstart();
		if (flg_DelLgn) {
			savlgn = ligne; pos(ligne,CLINIT); atb(24);
			ligne = (SWORD) (lastligne + LGINIT);
			}
		else	{
			savlgn = ligne; /* ligne++; */
			for (i = ligcur; i < lastligne; i++, ligne++)
				affligne(i);
			}
		affligne(lastligne); ligne = savlgn;
		x_bflush();
		aff_ecran = FALSE;
		}
	colcur = 0; colonne = CLINIT; pos(ligne,colonne);

	colbest = colonne;
	fcolbest = firstcol;

#ifdef ver14
	txtchg = TRUE;
#endif
	return;
}					/* Deline */

/*	--------------------------------------------	*/
/*	insertion d'une ligne a la position courante	*/
/*	--------------------------------------------	*/

void Insline()
{
	SWORD i,j,savlgn,savcol;
	BYTE	c;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	flg_undel = 0;	/* plus de 'UnDelete' possible */

	increment_line_counter();

	if (ligcur == (NBLIG - 1)) {	/* utiliser le fichier retour */
		if (colcur == 0)
			putret(adrmemlin(lastligne));
		else	{
			j = 0;
			if (flg_indent) {
				i = 0; c = getmemchar(ligcur,i);
				while ((c == TABUL) || (c == ' ')) {
					lgntemp[j++] = c; i++;
					c = getmemchar(ligcur,i);
					}
				}
			i = colcur;
			while ( (c = getmemchar(ligcur,i)) != EOSTR ) {
				i++;
				lgntemp[j++] = c;
				}
			lgntemp[j] = EOSTR;
			putret(lgntemp);
			}
		}
	else	{
		if (lastligne < NBLIG-1)
			lastligne++; /* decalage en memoire suffit */
		else	putret(adrmemlin(lastligne));
		/* decaler en memoire */
		for (i = lastligne; i > ligcur+1; i--)
			Xstrcpy(adrmemlin(i),adrmemlin(i-1));
		if (colcur != 0) {
			j = 0;
			if (flg_indent) {
				i = 0; c = getmemchar(ligcur,i);
				while ((c == TABUL) || (c == ' ')) {
					putmemchar((ligcur+1),j,c);
					i++; j++;
					c = getmemchar(ligcur,i);
					}
				}
			i = colcur;
			while ( (c = getmemchar(ligcur,i)) != EOSTR ) {
				i++;
				putmemchar((ligcur+1),j,c); j++;
				}
			putmemchar((ligcur+1),j,EOSTR);
			}
		else	Xstrcpy(adrmemlin((ligcur+1)),adrmemlin(ligcur));
		}
	/* nouvelle fin de la ligne courante */
	putmemchar(ligcur,colcur,EOSTR);
	if ((flg_InsLgn) && (colcur == 0)) {
		pos(ligne,colonne); atb(23);
		}
	else	{
		aff_ecran = TRUE;
		x_bstart();
		savlgn = ligne; savcol = colonne;
		for (i = ligcur; i <= lastligne; i++, ligne++)
			affligne(i);
		ligne = savlgn; colonne = savcol; pos(ligne,colonne);
		x_bflush();
		aff_ecran = FALSE;
		}
#ifdef ver14
	txtchg = TRUE;
#endif
}					/* Insline */

/*	--------------------------------	*/
/*	suppression du caractere courant	*/
/*	--------------------------------	*/

static void Delcar()
{
	SWORD c,i,savlgn,savecol;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
	}
#endif
	aff_ecran = TRUE;
	x_bstart();
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	savecol = colonne;
	if (colcur != (SWORD) Xstrlen(adrmemlin(ligcur))) {
		/* decalage de la ligne courante et de son affichage */
		for (i = colcur; i < (SWORD) Xstrlen(adrmemlin(ligcur)); i++) {
			putmemchar(ligcur,i,(getmemchar(ligcur,(i+1))));
			}
		affligne(ligcur);
		}
	else	{
		/* concatener la ligne suivante a la ligne courante */
		decrement_line_counter();
		if (ligcur == lastligne) {
			/* la ligne suivante n'est pas en memoire */
			if (!fret->Feof)
				getret(lgntemp);
			else if (!getsource(lgntemp)) {
				x_bflush();
				aff_ecran = FALSE;
				return;	/* impossible */
				}	
	
			if ((Lgnlen(adrmemlin(ligcur)) + Lgnlen(lgntemp)) >= LGLIGNE) {
				editor_bell(); putret(lgntemp); 
				x_bflush();
				aff_ecran = FALSE;
				return;				
				}
			Xstrcat(adrmemlin(ligcur),lgntemp);
			}
		else	{ /* ligne suivante en memoire : scrolling */
			if ((Lgnlen(adrmemlin(ligcur)) + Lgnlen(adrmemlin((ligcur+1)))) >= LGLIGNE) {
				/* impossible */
				editor_bell(); 
				x_bflush();
				aff_ecran = FALSE;
				return;
				}
			Xstrcat(adrmemlin(ligcur),adrmemlin((ligcur+1)));
			savlgn = ligne; ligne++;
			for (i = (SWORD) (ligcur+1); i < lastligne; i++, ligne++) {
				Xstrcpy(adrmemlin(i),adrmemlin((i+1))); affligne(i);
				}
			if (!fret->Feof) {
				getret(adrmemlin(lastligne));
				affligne(lastligne);
				}
			else if (!getsource(adrmemlin(lastligne))) {
				/* Fin de source */
				putmemchar(lastligne,0, EOSTR);
				affligne(lastligne); 
				if (lastligne > ligcur) {
					lastligne--;
					}
				}
			else  	affligne(lastligne);

			ligne = savlgn;
			}
		/* afficher la nouvelle fin de ligne */
		pos(ligne, savecol);
		affligne(ligcur);
		}
	colonne = savecol; pos(ligne,colonne);
	x_bflush();
	aff_ecran = FALSE;
#ifdef ver14
	txtchg = TRUE;
#endif
	return;
}					/* Delcar */

/*	----------------------------------	*/
/*	suppression du caractere precedent	*/
/*	----------------------------------	*/

static void Backspace()
{
	SWORD k,l,i,savlgn,savcol;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (colcur != 0) {
		Precedent(); Delcar();
		}
	else	{
		/* concatener la ligne courante a la ligne precedente */
		decrement_line_counter();
		if (ligcur == 0) {
		    /* la ligne precedente n'est pas en memoire */

			if (fdest->Feof)
				return;	/* impossible */
		    	getdest(lgntemp); 
			i = (SWORD) (Xstrlen(lgntemp));
		    	k = Lgnlen(lgntemp); 
			l = Lgnlen(adrmemlin(ligcur));	
		    	if (k+l >= LGLIGNE) {
				/* impossible */
				editor_bell(); 
				putdest(lgntemp); 
				return;
			    	}
			colcur = i;
			colonne = (SWORD) (Lgnlen(lgntemp) + 1);
			if (i > 0) {
		    		if ((lgntemp[i-1] == TABUL) 
				&&  (lgntemp[i]   == EOSTR))
					colonne--; 
		    		}
			Xstrcat(lgntemp,adrmemlin(ligcur)); Xstrcpy(adrmemlin(ligcur),lgntemp);
			while (colonne > MXCOL) { /* scrolling a droite */
				firstcol += (SWORD) (MXCOL / 2); 
				colonne -= (SWORD) (MXCOL / 2);
		    		}
			editorOnShow();
			}
		else	{	/* la ligne precedente est en memoire */
		    	i = (SWORD) (Xstrlen(adrmemlin((ligcur-1))));
		    	if ((Lgnlen(adrmemlin(ligcur)) + Lgnlen(adrmemlin((ligcur-1)))) >= LGLIGNE) {	
				/* impossible */
				editor_bell(); return;
			    	}
			colcur = i; 
		    	colonne = (SWORD) (Lgnlen(adrmemlin((ligcur - 1))) + 1);
		    	if (i > 0) {
				if (getmemchar((ligcur - 1),(i-1)) == TABUL && getmemchar((ligcur - 1),i) == EOSTR) 
					colonne--;
			    	}

		    	Xstrcat(adrmemlin((ligcur-1)),adrmemlin(ligcur));
		    	for (i = ligcur; i < lastligne; i++)
				Xstrcpy(adrmemlin(i),adrmemlin((i+1)));
		    	if (!fret->Feof)
				getret(adrmemlin(lastligne));
		    	else if (!getsource(adrmemlin(lastligne)))
			putmemchar(lastligne,0,EOSTR);
		    	ligcur--; ligne--;
		    	if (colonne > MXCOL) {
			    	while (colonne > MXCOL) { /* scrolling a droite */
					firstcol += (SWORD) (MXCOL / 2); colonne -= (SWORD) (MXCOL / 2);
			    		}
				editorOnShow();
		    		}
		    	else	{
				aff_ecran = TRUE;
				x_bstart();
			    	savlgn = ligne; savcol = colonne;
			    	for (i = ligcur; i <= lastligne; i++, ligne++)
					affligne(i);
			    	ligne = savlgn; colonne = savcol;
				x_bflush();
				aff_ecran = FALSE;
		    		}
			}
		numlgn--;	/* on vient de passer a la ligne precedente */
		}
	pos(ligne,colonne);

	colbest = colonne;
	fcolbest = firstcol;

#ifdef ver14
	txtchg = TRUE;
#endif

	return;

}					/* Backspace */

/*	-----------------------------------------	*/
/*	suppression du debut de la ligne courante	*/
/*	-----------------------------------------	*/

static void Deldline()
{
	SWORD i = 0,savelgn;
	BYTE	c;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
	}
#endif
	flg_undel = 2;	/* 'UnDelete' sera possible */
	Xstrcpy(lgntemp,adrmemlin(ligcur));	/* garder la ligne pour cela */
	while ((c = getmemchar(ligcur,colcur)) != EOSTR) {
		colcur++;
		putmemchar(ligcur,i,c);
		i++;
		}

	putmemchar(ligcur,i,EOSTR);
	colcur = 0;
	if (firstcol != 0) { /* il faut un scrolling a gauche */
		firstcol = 0;
		editorOnShow();
		}
	else  	{
		/* simple rafraichissement de la ligne */
		affligne(ligcur);
		}
	colonne = CLINIT; pos(ligne,colonne);
#ifdef ver14
	txtchg = TRUE;
#endif
}					/* Deldline */

/*	------------------------------------------	*/
/*	suppression de la fin de la ligne courante	*/
/*	------------------------------------------	*/

static void Delfline()
{
#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
	}
#endif
	flg_undel = 3;
	/* 'UnDelete' sera possible */
	Xstrcpy(lgntemp,adrmemlin(ligcur));
	/* garder la ligne pour cela */
	Xatb(21);
	putmemchar(ligcur,colcur,EOSTR);
#ifdef ver14
	txtchg = TRUE;
#endif

}					/* Delfline */


/*	-----------------------------------------------------	*/
/*	bascule de positionnement en debut ou en fin de ligne	*/
/*	-----------------------------------------------------	*/

static void DebutFin()
{
	SWORD savelgn,savecol;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (colcur == 0) {	/* aller en fin de ligne */
		colcur = (SWORD) (Xstrlen(adrmemlin(ligcur)));
		if (colcur == 0)
			colonne = CLINIT;
		else	{
			colonne = (SWORD) (Lgnlen(adrmemlin(ligcur)) + 1);
			if (getmemchar(ligcur,(colcur - 1)) == TABUL && getmemchar(ligcur,colcur) == EOSTR) colonne--;

			if (colonne > MXCOL) {	/* scrolling a droite */
				while (colonne > MXCOL) {
					firstcol += (SWORD) (MXCOL / 2);
					colonne -= (SWORD) (MXCOL / 2);
					}
				editorOnShow();
				}
			}
		}
	else	{
		/* aller en debut de ligne */
		colcur = 0; colonne = CLINIT;
		if (firstcol != 0) { /* il faut un scrolling a gauche */
			firstcol = 0;
			editorOnShow();
			colonne = CLINIT; 
			}
		}

	colbest = colonne;
	fcolbest = firstcol;

	pos(ligne,colonne);
}					/* DebutFin */

/*	-----------------------------------------------------	*/
/*	bascule de positionnement en debut ou en fin de ligne	*/
/*	-----------------------------------------------------	*/

void Debut()
{
	SWORD savelgn;

	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (colcur != 0) {	/* aller en debut de ligne */
	      	/* aller en debut de ligne */
		colcur = 0; colonne = CLINIT;
		if (firstcol != 0) { /* il faut un scrolling a gauche */
			firstcol = 0;
			editorOnShow();
			colonne = CLINIT; 
			}
		}

	colbest = colonne;
	fcolbest = firstcol;

	pos(ligne,colonne);
}					/* DebutFin */


/*	----------------------------------------------------	*/
/*	bascule de positionnement en debut ou en fin d'ecran	*/
/*	----------------------------------------------------	*/

static void HomeEnd ()
{
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (ligne == LGINIT) {	/* posit en fin d'ecran */
		numlgn += (SWORD) (lastligne - ligcur);
		ligne += lastligne; ligcur = lastligne;
	}
	else {			/* posit en debut d'ecran */
		numlgn -= ligcur;
		ligne = LGINIT; ligcur = 0;
	}
	newcol(FALSE);
}					/* HomeEnd */


/*	------------------------------------------------------	*/
/*	annule la derniere suppression effectuee (si possible)	*/
/*	------------------------------------------------------	*/

static void UnDelete ()
{
	SWORD	savelgn;

	switch (flg_undel) {
	   case 0:	/* refuse */
		editor_bell(); break;
	   case 1:	/* ligne complete */
		Insline();
	   case 2:	/* debut de la ligne */
	   case 3:	/* fin de la ligne */
		Xstrcpy(adrmemlin(ligcur),lgntemp);
		colcur = 0;
		if (firstcol != 0) {	/* scrolling a gauche */
			firstcol = 0;
			editorOnShow();
			colonne = CLINIT;
			}
		else	{
			affligne(ligcur);
			colonne = CLINIT; pos(ligne,colonne);
			}
		}
	flg_undel = 0;
}					/* UnDelete */

/*	----------------------------------------------------------	*/
/*	demande de centrage la ligne courante dans l'ecran affiche	*/
/*	----------------------------------------------------------	*/

static void Centrage ()
{
	SWORD	savecol;
	flg_undel = 0;	/* plus de 'UnDelete' possible */
	if (centrer()) { /* rafraichir l'ecran */
		editorOnShow();
		ligne = (SWORD) (ligcur + LGINIT); pos(ligne,colonne);
		/* nouveau numero de ligne courante */
		numlgn = (LONG) (fdest->nblgn + ligcur + 1);
		}
	return;
}					/* Centrage */


/*	-------------------------------------------------------------	*/
/*	centrer la ligne courante dans l'ecran affiche			*/
/*	retourne 'TRUE' si il faut rafraichir l'ecran, et dans ce	*/
/*	cas, la nouvelle position de la ligne en memoire est mise a	*/
/*	jour dans la variable 'ligcur'.					*/
/*	sinon, l'ancienne valeur de 'ligcur' doit etre maintenue.	*/
/*	-------------------------------------------------------------	*/

BOOL centrer ()
{
	SWORD	i,j,k;

	i = (SWORD) (NBLIG / 2);	/* future position de la ligne */
	i--;
	if (ligcur == i)	/* ligne deja centree */
		return (FALSE);
	if (ligcur < i) { /* remonter depuis le fichier destination */
		if (fdest->Feof) /* impossible */
			return (FALSE);
		if (i > lastligne) {	/* tout en memoire */
			j = lastligne;
			lastligne = (SWORD) (i + (lastligne - ligcur));
		}
		else {			/* vider dans fichier retour */
			k = (SWORD) (i - ligcur); /* nb lignes a scroller */
			if (lastligne == (NBLIG - 1))
				for (j = lastligne; k != 0; j--, k--)
					putret(adrmemlin(j));
			else if ((lastligne + k) >= NBLIG) {
				k = (SWORD) (((lastligne + k) - NBLIG) + 1);
				for (j = lastligne; k != 0; j--, k--)
					putret(adrmemlin(j));
				lastligne = (SWORD) (NBLIG - 1);
			}
			else {	/* tout reste en memoire */
				j = lastligne;
				lastligne = (SWORD) (lastligne + k);
			}
		}
		/* decaler en memoire */
		for (k = lastligne; j != 0 ; j--, k--) 
			Xstrcpy(adrmemlin(k),adrmemlin(j));
		Xstrcpy(adrmemlin(k),adrmemlin(0));
		/* lire les lignes manquantes dans le fichier destination */
		j = k;
		while (j != 0) {
			j--;
			if (!getdest(adrmemlin(j))) { /* destination est vide */
				/* re-decaler puis completer avec retour */
				i = (SWORD) ((i - j) - 1);
				for (j++, k = 0; j <= lastligne; k++, j++)
					Xstrcpy(adrmemlin(k),adrmemlin(j));
				while (k < NBLIG) {
					if (!getret(adrmemlin(k))) {
						lastligne = (SWORD) (k-1); break;
					}
					k++;
				}
				break;
			}
		}
	}
	else { /* avancer dans le fichier source ou le fichier retour */
		k = (SWORD) (ligcur - i); /* nb lignes a scroller */
		for (j = 0; k != 0; j++, k--)
			putdest(adrmemlin(j));
		/* decaler en memoire */
		for (k = 0; j <= lastligne; k++, j++)
			Xstrcpy(adrmemlin(k),adrmemlin(j));
		if (lastligne == (NBLIG - 1)) { /* pas en fin de fichier */
			/* completer avec fichier retour */
			while (k < NBLIG) {
			   if (!getret(adrmemlin(k))) { /* fin du fichier retour */
				/* completer avec fichier source */
				while (k < NBLIG) {
					if (!getsource(adrmemlin(k)))
						break;
					k++;
				}
				break;
			   }
			   k++;
			}
		}
		lastligne = (SWORD) (k - 1);
	}
	ligcur = i;
	return (TRUE);
}					/* centrer */

/*	--------------------------------------------------------------	*/
/*	affiche l'ecran courant	  Z! : le curseur n'est pas positionne	*/
/*	--------------------------------------------------------------	*/

void affecran()
{
	SWORD	i;

	ligne = LGINIT; pos(ligne,CLINIT); 
	Xatb(0);
	aff_ecran = TRUE;
	x_bstart();

	for (i = 0; i <= lastligne; i++) {
		affligne(i); ligne++;
		}

	/* pourquoi on simule l'atb(22) */
	/*
	while (i < NBLIG) {
		pos((SWORD) (LGINIT+i) ,1); atb(21);
		i ++;
		}
	 */
	atb(22);	
	x_bflush();
	aff_ecran = FALSE;			
}					/* affecran */


#include "edsyntax.c"

/*
 *	A F F L I G N E ( numl )
 *	------------------------
 *	affiche la ligne de numero 'numl' a la ligne ecran de numero 'ligne'.
 *	cette fonction tient compte de la valeur de 'firstcol' pour cadrer
 *	l'affichage de la ligne dans l'ecran.
 *	Z! : le curseur n'est pas positionne au retour
 */

void affligne(SWORD numl)

{					/* affligne */
	BYTE 	c;
	SWORD 	i = 0, j=0 , tcolonne = 1;
	SWORD 	oldcol, newcol;	/* Save la 1 valeur de TABUL */
	BOOL 	affatb=TRUE;		/* TRUE = atb(0) */
	LONG 	wlig;

	if (aff_ecran == FALSE) 
		x_bstart();

	colonne = CLINIT; 
	pos(ligne,CLINIT);  
	atb(21);

	wlig = (LONG) (numlgn - ligcur + numl);

	build_shadow_colour(numl);

	i = 0;

	if (firstcol != 0) {
		/* ---------------------------------- 	*/
		/* handle special case of tabulations 	*/
		/* when right shifted page		*/
		/* ---------------------------------- 	*/
		while (tcolonne <= firstcol) {
			c = getmemchar(numl,i);
			i++;
			if (c == EOSTR) {
				i--;
				break;
				}
			if (c != TABUL) {
				tcolonne++;
				}
			else	{
				NextTab(tcolonne,0);
				if (tcolonne > firstcol) {
					colonne = (SWORD) (tcolonne - firstcol); pos(ligne,colonne);
					break;
	  				}
		    		}
			}
#ifdef ver14
		if (boolbloc) {
			if (test_bloc(wlig)) Xatb(APU);
			for (j=CLINIT; j < colonne; j++) putch(' ');
			Xatb(0);
			}
#endif
		}

	/* This could have strange results */

	while ((c = getmemchar(numl,i)) != EOSTR) {

		use_shadow_colour(i);

		i++;
		if (c == TABUL) {
			oldcol = colonne;
			NextTab(colonne, firstcol);
#ifndef integre
			if (boolcor) {
				if (colonne > MXCOL) {
					newcol = MXCOL;
					}
				else	newcol = colonne;

				wlig = (LONG) (numlgn - ligcur + numl);

				for (colonne = oldcol; colonne < newcol; colonne++) {
					/* calcul de la ligne mem[0] */

					if (!test_atb(wlig,(SWORD) (i-1)) ) {
						if (affatb == FALSE) {
							Xatb(0);
							affatb = TRUE;
							}
						}
					else	{
						if (affatb == TRUE) {
							Xatb(APU);
							affatb = FALSE;
							}
						}
					putch(' ');
					}
				}
#endif
			if (colonne > MXCOL) /* lg logique > lg physique */
				break;
			pos(ligne,colonne);
			}
		else	{
			if (colonne > MXCOL) /* lg logique > lg physique */
				break;
			if (c < 0x0020)	{ /* caractere de controle */
#ifndef integre
				if (boolcor) {
					wlig  = (LONG) (numlgn - ligcur + numl);
					if (!test_atb(wlig,i)) {
						Xatb(APU); putch((BYTE) (c+0x0040)); Xatb(0);
						}
					else	{
						Xatb(0); putch((BYTE) (c + 0x0040)); Xatb(APU);
						}
			   		}
			   	else	{
					Xatb(APU); putch((BYTE) (c + 0x0040)); Xatb(0);
					}
#else
				Xatb(APU); putch(c + 0x0040); Xatb(0);
#endif

				}
			else	{
#ifndef integre
				if (boolcor) {
					/* calcul de la ligne mem[0] */
					wlig = (LONG) (numlgn - ligcur + numl);
					if (! test_atb(wlig, (SWORD) (i - 1))) {
						if (affatb == FALSE) {
							Xatb(0);
							affatb = TRUE;
							}
						}
					else {
						if (affatb == TRUE) {
							Xatb(APU);
							affatb = FALSE;
							}
						}
					}
#endif
				putch(c);
				}
			colonne++;
			}
		}

	/* Test si la fin de ligne est compris dans le bloc */
#ifndef integre
  	if (colonne < MXCOL)  {
		if (boolcor && !boolbloc && firstcol == 0) {
			if (test_corbeil(wlig,(SWORD) (i-1))) 
				Xatb(APU);
			else	Xatb(0);
			putch(' ');
			Xatb(0);
	 		}
#ifdef ver14
	   	if (boolbloc && (wlig>=deblgn && wlig <= finlgn)) {
			if (firstcol + colonne < rfincol) {
				while ((!(test_bloc(wlig)))
				&&     ( colonne <  MXCOL)) {
					putch(' ');
					colonne++;
					}
				if (colonne < MXCOL) {
					Xatb(APU);
					while (test_bloc(wlig) && colonne < MXCOL) {
						putch(' ');
						colonne++;	
						}
					Xatb(0);
					}		
				}
	   		}
#endif
		}

#endif

	if (aff_ecran == FALSE) x_bflush();

	Xatb(0);	/* Retour a l'atb courant */
	return;

}


void newcol(BOOL refresh)
/*	calcul de la nouvelle position colonne sur la ligne 'ligcur'
 *	partant des valeurs courantes de 'colonne' et 'colcur'
 *	qui peuvent etre modifiees en retour
 *	'refresh' indique si un rafraichissement d'ecran est impose.
 */
{				/* newcol */
	SWORD i,j,k,savcol,savlgn;
	SWORD oldfcol;

	oldfcol = firstcol;

	if (colcur == 0 && !boolbest) /* retour en debut de ligne */
		colonne = CLINIT;
	else	{
		if (boolbest) {
			colonne = colbest;
			firstcol = fcolbest;
			}

		colonne += firstcol;

		i = (SWORD) Xstrlen(adrmemlin(ligcur));
		if (i == 0) {
			j = 1;
			}
		else	{
			j = (SWORD) (Lgnlen(adrmemlin(ligcur)) + 1);
			if (getmemchar(ligcur,(i-1)) == TABUL && getmemchar(ligcur,i) == EOSTR) j--;
			}
		if (colonne >= j) {
			colonne = j; colcur = i;
			}
		else /* colcur != 0 */ {
			i = 0; k = 1;
			while (k < colonne) {
				if (getmemchar(ligcur,i) != TABUL)
					k++;
				else	{
					j = k; NextTab(j,0);
					if (j > colonne) break;
					k = j;
					}
				i++;
				}
			colonne = k; colcur = i;
			}
		}
	/* voir si il faut un scrolling horizontal a gauche */
	if (colonne < firstcol) {
		while (colonne < firstcol) 
			firstcol -= (SWORD) (MXCOL / 2);
		/* Test si il faut rafraichir l'ecran */
		/* if (firstcol != oldfcol) refresh = TRUE; */
		}
	/* voir si il faut un scrolling horizontal a droite */
	if (colonne > MXCOL) {
		colonne -= firstcol;
		while (colonne > MXCOL) {
			firstcol += (SWORD) (MXCOL / 2);
			colonne -= (SWORD) (MXCOL / 2);
			}
		/* test Si le scrolling est necessaire */
		/* if (firstcol != oldfcol) refresh = TRUE; */
		}
	else	{
		/* Ceci pour garder la compatibilite avec les ancetres ... */
		colonne -= firstcol; /* recadrer la position colonne sur l'ecran */
		}
	if (refresh || (firstcol != oldfcol)) {	/* rafraichissement de l'ecran est necessaire */
		editorOnShow();
		}
	pos(ligne,colonne);
}				/* newcol */

/*	affichage du numero de ligne courant si option demandee  */

void 	affnumligne()

{				/* affnumligne */

	char	*p,*q, 
#ifdef	ver2K
	col[5];
#else
	col[4];
#endif
	char valeur[8];
	char lig[8];
	LONG	n;

	BYTE 	c;

	p = &valeur[0]; n = numlgn;
	do 	{
		*p++ = inttocar(n % 10);
		}
	while ((n /= 10) > 0);
	*p = EOSTR;

	q = &lig[6];
	p = &valeur[0];
	while (*p) {
		*q-- = *p++; 
		}

	lig[7] = EOSTR;
	while (q >= lig) *q-- = ' ';

#ifdef ver14
	c = getmemchar(ligcur,colcur);
   	/* affiche le code du caractere ou 4 traits */
	if (!isdigit(c) && !isalpha(c) && c != EOSTR && c != 0x20) {
		pos(2,1); Xatb(2); x_cprintf((BYTE FPTR)"0x");
		c = getmemchar(ligcur,colcur);
		/* lettre de gauche */
		putch((BYTE) (hextocar((c>>4) & 0x0f)));
		/* lettre de droite */
		putch((BYTE) (hextocar(c & 0x0f)));
		
		Xatb(0);
	 	}
	 else	{
		horizontal_rule(2,1,MXCOL);
		Xatb(0);
	 	}
#endif
	off_cursor(); 
	show_line_number((BYTE FPTR) lig);

	p = &valeur[0]; n = (BINAIRE) (colonne + firstcol);
	do 	{
		*p++ = inttocar(n % 10);
		}
	while ((n /= 10) > 0);
	*p = EOSTR;

#ifdef	ver2K
	q = &col[3];
#else
	q = &col[2];
#endif
	p = &valeur[0];

	while (*p) {
		*q-- = *p++; 
		}

#ifdef	ver2K
	col[4] = EOSTR;
#else
	col[3] = EOSTR;
#endif
	while(q >= col) *q-- = ' ';

	show_column_number((BYTE FPTR) col);

	on_cursor();
	Xatb(0);
	pos(ligne,colonne);
}				/* affnumligne */

/*
 *	S A I S I E ( c )
 *	-----------------
 *	saisie a la position courante de l'octet contenu dans 'b'
 */

void saisie(BYTE c)

{
	SWORD	k,l,i,j,savlgn,savcol;
	BYTE	c1;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	flg_undel = 0;	/* plus de 'UnDelete' possible */

	if (c == TABUL) 
		l = lg_tabul;
	else	l = 1;

	off_cursor();
	if (flg_insert) {
		/* commencer par decaler la ligne */
		/* This was strange toooo !!! */
		i = Lgnlen((adrmemlin(ligcur)) + colcur);
		i = (SWORD) (firstcol + colonne + i + l - 1);
		if (i >= LGLIGNE) {
			editor_bell(); 
			return;	/* impossible */
			}
		i = (SWORD) (Xstrlen(adrmemlin(ligcur)) + 1);
		while ( i > colcur) {
			putmemchar(ligcur,i,(getmemchar(ligcur,(i-1))));
			i--;
			}	
		putmemchar(ligcur,colcur,' ');
		}
	else	{
		/* Calcul de la longueur de la ligne - le caractere qui va */
		/* etre gnacker . Ceci pour eviter le debordement de ligne */
		/* another strange one 					   */
		i = Lgnlen((adrmemlin(ligcur)) + colcur + 1); 

		if ((colcur + 1) == LGLIGNE) {		
			editor_bell(); return;	/* impossible */
			}
		if (colcur == (SWORD) Xstrlen(adrmemlin(ligcur))){
			putmemchar(ligcur,(colcur+1),EOSTR);
			}
		}
	/* mettre l'octet saisi dans la ligne et faire son echo a l'ecran */
	if (c != TABUL) {
		x_bstart();
		c1 = getmemchar(ligcur,colcur);
		putmemchar(ligcur,colcur,c);
		colcur++;
		if (c < 0x0020) {	/* caractere de controle */
			Xatb(APU); putch((BYTE) (c + 0x0040)); Xatb(0);
			}
		else	putch(c);
		colonne++;
		x_bflush();
		if (((c1 == TABUL) || (flg_insert) || ( _COLOUR_CONTROL)) 
		&&  (colonne <= MXCOL)) {
			/* le caractere remplace une tabulation ou mode insertion */
			savcol = colcur; i = colonne;
			affligne( ligcur );
			colcur = savcol; colonne=i;
#ifdef	FUCK
			savcol = colcur; i = colonne;
			while ( (c1 = getmemchar(ligcur,savcol)) != EOSTR) {
				savcol++;
				if (c1 != TABUL) {
					if (c1 < 0x0020) {
						Xatb(APU); 
						putch((BYTE)(c1 + 0x0040));
						Xatb(0);
						}
					else	putch(c1);
					i++;
					}
				else	{
					j = i;
					NextTab(i,firstcol);
					while (j++ < i) {
						if (j > MXCOL)
							 break;
						putch(' ');
						}
					}
				if (i > MXCOL)
					 break;
				}
			Xatb(21); pos(ligne,colonne);
#endif
			}
		}
	else	{	/* cas particulier de la tabulation */
		x_bstart();
		savcol = colonne;
		NextTab(colonne,firstcol);
		putmemchar(ligcur,colcur,TABUL);
		colcur++;
		if (colonne <= MXCOL) { /* decaler l'affichage */
			while (savcol++ < colonne)
				putch(' ');
			i = colonne; savcol = colcur;
			while ( (c1 = getmemchar(ligcur,savcol)) != EOSTR ) {
				savcol++;
				if (c1 == TABUL) {
					j = i;
					NextTab(i,firstcol);
					while (j++ < i) {
						if (j > MXCOL)
							break;
						putch(' ');
						}
					}
				else	{
					if (c1 < 0x0020) {
						Xatb(APU); putch((BYTE) (c1 + 0x0040));
						Xatb(0);
						}
					else	putch(c1);
					i++;
					}
				if (i > MXCOL) break;
				}
			pos(ligne,colonne);
			}
		x_bflush();
		}
	if (colonne > MXCOL) { /* scrolling horizontal necessaire */
		firstcol += (SWORD) (MXCOL / 2); colonne -= (SWORD) (MXCOL / 2);
		editorOnShow();
		pos(ligne,colonne);  
		}

	on_cursor();
#ifdef ver14
	txtchg = TRUE;
#endif
}					/* saisie */

#ifndef integre

/*	ClipBoard Manager	*/
/*	-----------------	*/

BOOL	corbeilOnCreate()
{
	delecart  = 0;
	if ( traceon && EXTEND_AED == FALSE ) {		
		editor_bell();
		return(0);
		}
	else	return( (boolcor = 1) );
}


BOOL	corbeilOnShow()
{
	SWORD 	i, sl, sc;
	LONG j;

	show_basket_message();
	show_basket_options();
	pos(ligne, colonne);

	on_cursor();

	/* Si deblgn = 0 -> Absence de taquet de depart */
	/* En cours deblgn ne peut jamais etre 0 */

	if (deblgn != 0) {
		sl = ligne;
		sc = colonne;
		ligne = LGINIT;
		colonne = CLINIT;
		x_bstart();
		aff_ecran = TRUE;
		for (i=0; i<= lastligne; i++) {
			j = (LONG) (numlgn - ligcur + i);
		  	if (j >= deblgn && j <= finlgn) 
				affligne(i);
		        ligne++;
			}
		ligne = sl;
		colonne = sc;
		pos(ligne, colonne);
		x_bflush();
		aff_ecran = FALSE;
		}
	return(0);

}

VOID	display_line_numbering()
{
	if (flg_affnbln) 
		affnumligne();
	else if ( is_window_editor() )
		show_line_numbering();
	return;
}

BOOL	corbeilOnHide()
{
	SWORD 	i, sl, sc;
	LONG j;

	x_bstart();
	aff_ecran = TRUE;
	boolcor = 0;
	Xatb(0);

	if (deblgn != 0) {
		sl = ligne;
		sc = colonne;
		ligne = LGINIT;
		colonne = CLINIT;
		for (i=0; i<= lastligne; i++) {
			j = (LONG) (numlgn - ligcur + i);
		  	if (j >= deblgn && j <= finlgn) affligne(i);
			ligne++;
			}
		ligne = sl;
		colonne = sc;
		pos(ligne, colonne);
		}

	hide_basket_message();
	wipe_line_numbering();
	show_line_numbering();
	display_line_numbering();
	pos(ligne,colonne);
	off_cursor();
	x_bflush();
	aff_ecran = FALSE;
	return(0);
}

SWORD	corbeilOnUseEvent(SWORD event)
{
	BOOL	FINI = FALSE;
	SWORD 	i, sl, sc;
	BYTE 	car;
	BYTE	curcar=0;
	LONG j;

	if (( event == 256 )
	&& (!(event = video_mouse_event())))
		return((FINI=FALSE));

	if ((car = (event & 0x00FF)) == (BYTE) MOUSE) {
#ifdef	souris
		/* si position valide Repositionne le curseur */
		cursor_goto(mouse_lin,mouse_col);			
		if (mouse_bouton == 0) car = 'Q';
		if (mouse_bouton == 3 && deblgn == 0) car = 'A';
		else if (mouse_bouton == 3 && deblgn != 0) car = 'B';
		else if (mouse_bouton == 1) car = 'R';
#else
		car = car; /* xF0 is not the mouse trigger ! */ 
#endif
		}
	else	car = (BYTE) (toupper(car));
		
	wipe_basket_star();
	pos(ligne, colonne);
	if (car == ESCAPE) {
#ifdef ver14
		flg_undel = 0; /* 'UnDelete' impossible */
		editorOnGetFocus();
		FINI = commande();
		editorOnLoseFocus();
		if (!FINI) {
			x_bstart();
			show_insert_message();
			show_basket_message();
			show_basket_options();
			pos(ligne,colonne);
			x_bflush();
			}
		else	return(1); /* Sortie de aed */
#else
		editor_bell();
#endif
		}
	else	{
#ifdef ver14
		if (car == 'K') {
			x_bstart();	
			aff_ecran = TRUE;
			if (boolbloc) {
				show_basket_message();
				boolbloc = 0;
				show_basket_options();
				pos(ligne,colonne);
				if (deblgn) {
					if ((fincol >= debcol)
					&&  ((firstcol+colonne) > (mfirstcol+realcol))) {
						sl = ligne;
						sc = colonne;
						ligne = LGINIT;
						colonne = CLINIT;
						for (i=0; i<= lastligne; i++) {
							j = (LONG) (numlgn - ligcur + i);
						  	if ((j >= deblgn)
							&&  (j <= finlgn))
								affligne(i);
							ligne++;
							}
						ligne = sl;
						colonne = sc;
						pos(ligne, colonne);
						}
					}
				}
			else	{
				if (deblgn) {
					if ((fincol >= debcol)
					&&  ((firstcol+colonne) > (mfirstcol+realcol))) {
						show_basket_message();
						boolbloc = 1;
						show_basket_options();
						pos(ligne,colonne);
						sl = ligne;
						sc = colonne;
						ligne = LGINIT;
						colonne = CLINIT;
						for (i=0; i<= lastligne; i++) {
							j = (LONG) (numlgn - ligcur + i);
						  	if ((j >= deblgn) && (j <= finlgn)) 
								affligne(i);
					        	ligne++;
							}
						ligne = sl;
						colonne = sc;
						pos(ligne, colonne);
						}
					else	editor_bell();
					}
				else	{		
					show_basket_message();
					boolbloc = 1;
					show_basket_options();
					pos(ligne,colonne);
					}
				}
			x_bflush();
			aff_ecran = FALSE;
			}
		else	{
#endif
			x_bstart();
			aff_ecran = TRUE;
			if (car == 'A') Debtaq();
			else if (car == 'B' ) Fintaq();
			else if (car == 'C' ) Rempcor();
			else if (car == 0x7F) Affdel();
			else if (car == 'D' ) Affdel();
			else if (car == 'I' ) Inscor(0);
#ifdef ver14
			else if (car == 'X') Inscor(1);
#endif
			else if (car == 'M') Movcor(0);
#ifdef ver14
			else if (car == 'L') Movcor(1);
#endif
			else if (car == 'R') Razcorb();
			else if (car == 'T') Raztamp();
#ifdef ver14
			else if (car == 'P') Modevi();
			else if (car == '+') nextpage(1);	/* en avant */
			else if (car == '-') nextpage(0);	/* en arriere */
#endif
			else if (car == CTRLHOME) Debut();
			else if (car == PDEBFIN) DebutFin();
			else if (car == PGDN) editorPageDown();
			else if (car == PGUP) editorPageUp();
			else if (car == CURH) Montee();
			else if (car == CURG) Precedent();
			else if (car == CURD) Suivant();
			else if (car == CURB) Descente();
			else if (car == NEXTWORD) NextWord();
			else if (car == PREVWORD) BackWord();
#ifndef ver14
			else if (car == CORB) car = 'Q';
#endif

			else if (car == INDENT) {
				if (traceon) poserrback();
				}
			else if (car == NEXTERR) {
				if (traceon) 
					poserrsuiv();
				else	editor_bell();
				}
			else if (car != CORB) {
			       	if (car == INSERT) {
				     	if (flg_insert) {
						flg_insert = FALSE;
						wipe_insert_message();
			             		}
				     	else	{
						flg_insert = TRUE; 
						show_insert_message();
						}
					show_basket_message();
					show_basket_options();
				     	pos(ligne,colonne);
					}
#ifndef ver14
				else if (car == '?') {
					memento(); 
					pos(ligne, colonne);
					}
#endif
			        if (car != 'Q' && car != MOUSE)  car = 'Q'; /* editor_bell();*/
				}
		
			x_bflush();
			aff_ecran = FALSE;
			}
#ifdef ver14
		}
#endif
	if (( car & 0x00FF) == 'Q' ) {
		corbeilOnHide();
		corbeilOnRemove();
		}
	return(0);
	/* (car & 0x00FF)); */

}


BOOL	corbeilOnRemove()
{
	return((boolcor = 0));
}

#ifdef	OLD_BASKET_MODE
BOOL 	Corbeil()

{
	SWORD	event=0;
	BYTE	curcar=0;

	if (!( corbeilOnCreate() ))
		return(0);
	else	{
		corbeilOnShow();
		do	{
			curcar = video_cursor_on();
			event  = x_getch();
			video_cursor_off(boolcor);
			}
		while ((event = corbeilOnUseEvent(event)) != 'Q');
		corbeilOnHide();
		corbeilOnRemove();
		return(0);
		}
}
#endif

#ifdef ver14
static void Modevi()
{

	if (boolbest) {
		pos(1,63); Xatb(0); x_putch(' ');
		}
	else	{
		pos(1,63); Xatb(2); x_putch(edit_msg[msgaff][2]); Xatb(0);
		}
	pos(ligne,colonne);
	if (boolbest) 	boolbest = 0;
	else		boolbest = 1;
}
#endif

static void nextpage(BOOL sens)
{
	SWORD lgligne;
	BOOL sauv_boolbest = boolbest;

	fcolbest = firstcol;
	colbest = CLINIT;

	boolbest = TRUE;
	lgligne = Lgnlen(adrmemlin(ligcur));
	if (!sens) { /* demi ecran en arriere */
                if (fcolbest > 0) {		
			fcolbest -= (SWORD) (MXCOL / 2);
		}
		else editor_bell();
	}
	else {	/* demi ecran en avant */
		if (fcolbest + MXCOL/2 < lgligne) {
			fcolbest += (SWORD) (MXCOL/2);
		}
		else editor_bell();
	}

	newcol(FALSE);
	boolbest = sauv_boolbest;
	pos(ligne,colonne);
}

void Debtaq()			/* debtaq */

{
	if ((deblgn != 0) || ((getmemchar(ligcur,colcur) < 0x0020)
	    && (getmemchar(ligcur,colcur) != TABUL) 
	    && (getmemchar(ligcur,colcur) != EOSTR))) { 
		/* Pas de debut de taquet sur un caractere de controle */
		editor_bell();		/* Si taquet deja mis en place */
		return;
		}
	deblgn = numlgn;
	debcol = colcur;

	realcol = colonne;
	mfirstcol = firstcol;

	finlgn = numlgn;
	fincol = colcur;
	
	/* Affichage debut corbeil */		

	Xatb(APU); 
	if (getmemchar(ligcur,colcur) == TABUL) {
		putch(' ');
		}
	if (getmemchar(ligcur,colcur) == EOSTR) {
		putch(' ');
		}
	else	{
		putch(getmemchar(ligcur,colcur)); 
		}
	Xatb(0);
	pos(ligne, colonne);
}


void Fintaq()			/* fintaq */
{
	LONG olgn, save_olgn;

	SWORD nlcur; 
	SWORD sauvlig, sauvcol, save_ligne, save_nlcur;	

	if (deblgn == 0) {
		editor_bell();
		return;		
		}

	/* Interdiction de poser un taquet sur la 1 col. de la 1 lig. (Je ne sais pas faire et sa me fait ...(sic!) ) */
	if (((ligcur == 0) && (colcur == 0)) || (boolbloc && (colcur < debcol))) {
		editor_bell();
		return;
		}

	/* test si taquet de fin est avant taquet de debut */

	if (numlgn < deblgn) {
		editor_bell();
		return;
		}

#ifdef ver14
	if (boolbloc) {	/* Il doit y avoir un decalage de 1 entre deb et fin */
		if (firstcol+colonne  == mfirstcol+realcol) {
			editor_bell();
			return;
			}
		}
	else	{
#endif
		if ((numlgn == deblgn) && (colcur <= debcol)) {
			editor_bell();
			return;	
			}
#ifdef ver14
		}
#endif
	/* Nouvelles coordonnees */

	rfincol = (SWORD) (firstcol + colonne);	/* Sauv. limite reelle du bloc */

	olgn   = finlgn;	/* sauvegarde de l'ancienne valeur */



	if (colcur == 0) {
		fincol = (SWORD) (Xstrlen(adrmemlin((ligcur - 1))));
		finlgn = (LONG) (numlgn - 1);
		ligcur--;
		ligne--;
		numlgn--;
		}
	else	{
		finlgn = numlgn;
		fincol = (SWORD) (colcur - 1); /* Ne pas prendre en compte le dernier caractere */
		}
	

	sauvcol = colonne;
	sauvlig = ligne;
	nlcur = ligcur;

	off_cursor();

	if (olgn > finlgn) {
#ifdef ver14
		if (boolbloc) {
			save_olgn = olgn;
			olgn = deblgn;

			save_nlcur = nlcur;
			save_ligne = ligne;

			while (olgn <= finlgn && nlcur >= 0) {
				affligne(nlcur);
				nlcur--;
				ligne--;	
				olgn++;
				}

			nlcur	= (SWORD) (save_nlcur+1);
			ligne	= (SWORD) (save_ligne+1);
			olgn	= (SWORD) (save_olgn+1);
			}
#endif
		while (olgn >= finlgn && nlcur <= lastligne) {
			affligne(nlcur);
			nlcur++;
			ligne++;		
			olgn--;
			}
		}
	else	{
#ifdef ver14
		if (boolbloc) olgn = deblgn;
#endif
		while (olgn <= finlgn && nlcur >= 0) {
			affligne(nlcur--);
			ligne--;	
			olgn++;
			}
		}

	colonne = sauvcol;
	ligne   = sauvlig;

	if (colcur  == 0) {
		ligne++;
		ligcur++;
		numlgn++;
		}

	on_cursor();
	pos(ligne, colonne);
	Xatb(0);
}

static void Razcorb() 
{
	SWORD sl, sc, i, j;

	if (deblgn == 0) {
		return;
		}

	sl = ligne;
	sc = colonne;

	aff_ecran = TRUE;
	x_bstart();


	off_cursor();
	Xatb(0);

	sl = ligne;
	sc = colonne;
	ligne = LGINIT;
	colonne = CLINIT;

	boolcor = 0;	/* pour effacer l'inversion video */
	for (i=0; i<= lastligne; i++) {
		j = (SWORD) (numlgn - ligcur + i);
	  	if ((j >= deblgn) && (j <= finlgn)) 
			affligne(i);
		ligne++;
		}

	boolcor = 1; 	/* on continue a rester dans le mode corbeille */
		
	ligne = sl;
	colonne = sc;

	deblgn = 0;
	finlgn = 0;
	
	on_cursor();
	pos(ligne, colonne);
	x_bflush();
	aff_ecran = FALSE;
	return;

}

/*global*/ void Raztamp()  			/* Liberation du tampon */
{
	
	StrCor FPTR p, FPTR q;
	SWORD sl, sc;

	/* RAZ du Tampon si existant */
	if (tete != FNIL) {
		p = tete;
		while (p->suiv != FNIL) {
			if (p->lgn != (BYTE FPTR) 0) 
				liberate(p->lgn);
			q  = p->suiv;
			liberate((BYTE FPTR) p);
			p = q;
			}
		if (p->lgn != (BYTE FPTR) 0) 
			liberate(p->lgn);
		liberate((BYTE FPTR) p);
		tete = FNIL;
		
		/* Efface la trace sur la ligne de commande */
		sl = ligne; sc = colonne;

		wipe_basket_full();
		show_basket_star();

		ligne = sl; colonne = sc;
		pos(ligne, colonne);

		}
	return;
}


static void Delcorb()			/* Suppression de la corbeille */
{

	LONG i;
	
	SWORD j, k;
	SWORD lgligcur;
	BYTE boolfl=0;	/* Pour absorber la fin de ligne */

	/* repositionne le source au debut de la corbeille */

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	if (deblgn == 0) {
		editor_bell();
		return;
		}

	Poscorb(deblgn, debcol);
	
#ifdef ver14
	if (boolbloc) {
		i = deblgn;
		while (i <= finlgn) {
			colcur = 0;
			colonne = CLINIT;
			firstcol = 0;

			while (colonne < realcol) {
				if (getmemchar(ligcur,colcur) == EOSTR) 
					break;
				if (getmemchar(ligcur,colcur) == TABUL) {
					NextTab(colonne,firstcol);
					}
				else	colonne++;
				colcur++;
				}

			while (colonne < rfincol) {
				if (getmemchar(ligcur,colcur) == EOSTR)
					 break;
				if (getmemchar(ligcur,colcur) == TABUL) {
					NextTab(colonne,firstcol);
					}
				else	colonne++;
				colcur++;
				}			
			

			if (colcur > debcol)
			    Xstrcpy( adrmemcol(ligcur,debcol), adrmemcol(ligcur,colcur));

			i++;
			if (i <= finlgn) {
				putdest(adrmemlin(ligcur));
				numlgn++;
				getret(adrmemlin(ligcur));
				}
			} 
	
		completer(1);
		colcur = debcol;
		newcol(FALSE); 
		deblgn=0;
		finlgn=0;
		txtchg = TRUE;
		return;		
		}
#endif
	/* Boucle sur ligne */

	delecart = 0;

	/* Purger les lignes ENTRE deblgn et finlgn */
	if (finlgn != deblgn) {
		i = (SWORD) ((finlgn - deblgn) - 1);
		delecart = 1;	/* Prise en compte de la premiere ligne */
		for ( ; i > 0; i--) {
			getret(adrmemlin((ligcur+1)));
			delecart++;
			}
		}
	
	/* concatener deblgn et finlgn */

		lgligcur = (SWORD) (Xstrlen(adrmemlin(ligcur)));

		/* Si Fin de ligne = EOSTR simmuler Ctrl-Y */
		if (deblgn != finlgn) {
			/* montee de la ligne suivante en memoire */
			getret(adrmemlin((ligcur+1)));

			/* Concatenation avec ligcur */
			j = (SWORD) (Xstrlen(adrmemlin((ligcur + 1))));
						
			/* Test si concatenation possible */
			if ((Lgnlen(adrmemlin(ligcur)) + Lgnlen(adrmemlin((ligcur+1)))) >= LGLIGNE) {
				editor_bell();
				putmemchar(ligcur,colcur,EOSTR);
				putret(adrmemlin((ligcur+1)));
				/* erreur */
			}
			else {

				if (getmemchar((ligcur+1),(fincol)) == EOSTR) boolfl = 1;

				/* Concatenation */
				k = colcur ;
				if (fincol == j) {
					putmemchar(ligcur,colcur,EOSTR);
					}
				else {
					for (i=(SWORD) (fincol+1) ; i <= j; i++) { 
						putmemchar(ligcur,k,(getmemchar((ligcur+1),i)));
						k++;
						}
					}			
				fincol = colcur; 
			}
		}
		else {
				/* Suppression sur la meme ligne */
			i = colcur;
		
			if (getmemchar(ligcur,fincol) == EOSTR) boolfl = 1;

			if (fincol == lgligcur) {
				putmemchar(ligcur,colcur,EOSTR);
			}					
			else {
				k = (SWORD) (fincol + 1);
				for ( ; k <= lgligcur; k++) {
					putmemchar(ligcur,i,(getmemchar(ligcur,k)));
					i++;
				}
			}
		}
		/* Tester la fin de ligne  de ligne courante */
			
		if (boolfl) {

			delecart++;	/* Suppression d'une ligne entiere */

			/* Si le fichier retour est vide tapez dans le source */
			if (!getret(adrmemlin((ligcur+1)))) 
				getsource(adrmemlin((ligcur + 1)));
			j = (SWORD) (Xstrlen(adrmemlin((ligcur+1))));
			if ((Lgnlen(adrmemlin(ligcur)) + Lgnlen(adrmemlin((ligcur+1)))) >= LGLIGNE) {
				/* erreur */
				editor_bell();
				putret(adrmemlin((ligcur+1)));
			}
			else {
				k = colcur;
				for (i=0; i <= j; i++) {
					putmemchar(ligcur,k,(getmemchar((ligcur+1),i)));
					k++;
				}
			}
		}

	completer(1);
	deblgn=0;
	finlgn=0;
#ifdef ver14
	txtchg = TRUE;
#endif

}

static void Affdel()	/* affiche l'ecran courant apres suppression */

{

	if (deblgn == 0) { editor_bell(); return; }

	Delcorb();
	centrer();
	editorOnShow();

	ligne = (SWORD) (ligcur + LGINIT);

	firstcol = mfirstcol; 
	colonne  = realcol;

	newcol(FALSE);
	show_basket_star();
	pos(ligne,colonne);
	
}


static void Poscorb(LONG l, SWORD c) 	/* Repositionne le source */
{
	LONG memb, memh;
	LONG j;
	SWORD i;

	memb = (LONG) (numlgn - ligcur);
	memh = (LONG) (memb + lastligne); /* l -> 1 a 23	lastligne -> 0 a 22 */
	if (l < memb) {
		/* Purger la memoire dans ret */
		for (i=lastligne ; i >= 0; ) {
			putret(adrmemlin(i));
			i--;
		}
		numlgn = (LONG) (memb - 1);
		getdest(adrmemlin(0));

		while (numlgn > l) {
			putret(adrmemlin(0));
			getdest(adrmemlin(0));
			numlgn--;
		}
		/* Pour compenser */
		ligcur = 0;
	}
	else {
		if (l > memh) {
				/* Purge dans dest */
			for (i=0; i <= lastligne; i++) {
				putdest(adrmemlin(i));
			};

			numlgn = (LONG) (memb + i);
			if (!getret(adrmemlin(0))) getsource(adrmemlin(0));

			while ((numlgn < l)) {
				putdest(adrmemlin(0));
				if (!getret(adrmemlin(0))) getsource(adrmemlin(0));
				numlgn++;
			}
			ligcur = 0; 
		}
		else {		/* la ligne courante et la old position
					sont en memoire */

			/* remettre la ligne courante en 0 */
			
			if (numlgn > l) {
				j = (LONG) (ligcur - (numlgn - l));
				}
			else	{
				j = (LONG) (ligcur + (l - numlgn));
				}	
			/* Purge vers le bas */

			for (i = lastligne; i > j; i--) {
				putret(adrmemlin(i));
			}

			/* Purge vers le haut */

			for (i = 0; i <= j; i++) {
				putdest(adrmemlin(i));
			}				
			
			/* Recuperer la ligne courante dans mem[0] */

			ligcur = 0;
			numlgn = l;
			getdest(adrmemlin(ligcur));
		}
	}

	ligne = (SWORD) (ligcur + LGINIT);
	colcur = c; 
}

#ifdef	VERSION666
#ifdef	UNIX

static	void	publish_editor_selection()
{
	StrCor FPTR 	p=(StrCor FPTR)0;
	BYTE  FPTR 	sptr=(BYTE FPTR) 0;
	BYTE  FPTR 	rptr=(BYTE FPTR) 0;
	BYTE  FPTR 	result=(BYTE FPTR) 0;
	int		i=0;
	int		rlen=0;
	int		slen=0;

	if ( is_graphical > 1 ) {

		/* concatenate into 1 big buffer */
		/* ----------------------------- */
		for (	rlen=0,p=tete,result=(BYTE FPTR) 0;
			p != (StrCor FPTR) 0;
			p = p->suiv ) {
			/* avoid empty lines */
			/* ----------------- */
			if (!( sptr = p->lgn )) continue;
			for (	slen=0; *(sptr+slen) != '\n'; slen++ ) {
				if (( *(sptr+slen) == '\r' )
				||  ( *(sptr+slen) ==  1   ) 
				||  ( *(sptr+slen) ==  0   ))
					break;
				else	continue;
				}
			if (!( rptr = allocate( (rlen+slen+2) )))
				break;
			if( rlen ) {
				for (i=0; i < rlen; i++ ) {
					if (!(*(rptr+i) = *(result+i))) {
						rlen=i;
						break;
						}	
					}
				liberate( result );
				result = (BYTE FPTR) 0;
				}
			for (i=0; i < slen; i++ ) {
				if (!( *(rptr+rlen+i) = *(sptr+i) )) {
					slen=i;
					break;
					}
				}

			*(rptr+rlen+i) = '\r';
			*(rptr+rlen+i+1)= 0;
			result = rptr;
			rlen += (slen+1);
			}
		if ( result ) {
	 		publish_selection( result,rlen );
			}

		}


	return;
}
#endif
#endif

static BOOL Allocor()
{
	LONG i;

	StrCor FPTR p, FPTR q;
	BYTE  FPTR s;
	SWORD l;
	SWORD dlgn, flgn;

	/* Se repositionner sur le debut de la corbeille */
	/* --------------------------------------------- */		
	Poscorb(deblgn, debcol);

	if ((tete = (StrCor FPTR) allocate(sizeof(StrCor))) == FNIL)
		return(FALSE);

	p = tete;
	p->lgn = (BYTE FPTR ) 0;

	for (i=deblgn; i <= finlgn; i++) {

		/* Definition des limites de la ligne */
		/* ---------------------------------- */
		if ((i == deblgn) || boolbloc) {
			if (boolbloc) 
				dlgn = realcol;
			else	dlgn = debcol;
			}
		else	{
			dlgn = 0;
			}

		if ((i == finlgn) || boolbloc) {
			if (boolbloc) 
				flgn = rfincol;
			else	flgn = fincol;
			}
		else	{
			flgn = (SWORD) (Xstrlen(adrmemlin(ligcur)));
			}
		
		/* Allocation de la ligne courante */
		/* ------------------------------- */
		l = (SWORD) ((flgn - dlgn) + 2);
		if ((s = (BYTE FPTR) allocate(l)) == (BYTE FPTR) 0) {
			/* Longueur de la ligne courante */
			/* ----------------------------- */
			return(FALSE);
			}

		/* Copy de la ligne en memoire */
		/* --------------------------- */
		alloc2(ligcur,(BYTE FPTR) s);

		/* Remplissage de la structure */
		/* --------------------------- */
		p->lgn  = s;
		
		/* Passage a la ligne suivante */					
		/* --------------------------- */
		putdest(adrmemlin(ligcur));
		getret(adrmemlin(ligcur));
		numlgn++;

		/* Structure suivante */
		/* ------------------ */
		if ((q = (StrCor FPTR) allocate(sizeof(StrCor))) == FNIL )
			return(FALSE);

		p->suiv = q;
		p       = q;
		p->suiv = FNIL;
		p->lgn  = (BYTE FPTR) 0;	/* valeur par defaut */

		}

	/* Traitement de la derniere ligne */
	/* ------------------------------- */
#ifdef	VERSION666
#ifdef	UNIX
	publish_editor_selection();
#endif
#endif	
	return(TRUE);
}


static void Rempcor()	/* Remplir la corbeille */

{
	SWORD i;
	BOOL retalloc;
	SWORD  indfor;
	SWORD nb;
	
	if (deblgn == 0) {	/* Retour si pas de corbeille */
		editor_bell();
		return;
	}

	
	if (tete != FNIL) {	/* Retour si corbeille non vide */
		Raztamp();	/* Raz de la corbeille existante */
	}	

	/* Sauvegarde de la position courrante */

	saunum   = numlgn;
	saulgn   = ligcur;
	saucol   = colcur;
	saurcol  = colonne;
	saufirst = firstcol;
	saulast  = lastligne;
	
	retalloc = Allocor();


	/* Repositionner la ligne sauvegardee en mem[0] */

	while (numlgn != saunum) {
		if (numlgn < saunum) {
			putdest(adrmemlin(ligcur));
			getret(adrmemlin(ligcur));
			numlgn++;
			}
		else	{
			putret(adrmemlin(ligcur));
			getdest(adrmemlin(ligcur));
			numlgn--;
			}			
		}
		
	/* Repositionner la ligne dans l'ecran */

	Xstrcpy(adrmemlin(saulgn), adrmemlin(ligcur));
	ligcur = saulgn;
	
	/* Completer l'ecran vers le haut */

	for (indfor = (SWORD) (ligcur-1); indfor >= 0; indfor--) {
		getdest(adrmemlin(indfor));
		}

	/* Completer l'ecran vers le bas */

	i = (SWORD) (ligcur + 1);

	while (i <= saulast) {
		getret(adrmemlin(i)); i++;
		}


	if (retalloc == FALSE) {
  		Xerreur(USUAL,ernoy03);
		editor_bell();

  		while (x_kbhit() == 0) {
		};
  		Raztamp(); 
		horizontal_rule(LGERR,COLERR,MXCOL);
		}
	else	{
		show_basket_full();
		}

	colcur    = saucol;
	lastligne = saulast;
	ligne	  = (SWORD) (ligcur + LGINIT);
	colonne   = saurcol;
	firstcol  = saufirst;

	if ( MXCOL > 68 ) {
		show_basket_star();
		}
	pos(ligne,colonne);
}

static void Inscor(BOOL mixe)		/* Insertion de la corbeille */
{
	LONG sn;

	StrCor FPTR p;
	SWORD i, sc , sf;
	BOOL ret_chang=TRUE;
	BYTE sau_car;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
	}
#endif
	if ((deblgn == 0) && (tete == FNIL)) {
		editor_bell();
		return;
	}
	if ((deblgn != 0) && (tete != FNIL)) Raztamp();
	if (tete == FNIL) Rempcor();
	if (tete != FNIL) {
		p = tete;
		colbest  = colonne;	/* colonne de reference */
		fcolbest = firstcol;	/* 1ere colonne de reference */
		sn = numlgn;	/* Sauvegarde de la ligne de depart */
		/* Insertion des lignes */
		while (p->suiv != FNIL) { /* p-> condition d'arret */
			i = (SWORD) (Mstrlen(p->lgn));

			sau_car =(BYTE) *(p->lgn + i - 1);

			if ((BYTE) *(p->lgn + (i-1)) == LIMLIG) {
			    if (mixe) {
					*(p->lgn + (i-1)) = EOSTR;
			    }
			    i--;
			}				

			Mstrcpy((BYTE FPTR) lgntemp, (BYTE FPTR) p->lgn );

			ret_chang = changer(ligcur,0,i,lgntemp);

			if (mixe && (sau_car == LIMLIG)) *(p->lgn + i) = sau_car;

			if (! mixe) {
			}
			else if (p->suiv->suiv != FNIL) corb_CURB(mixe); /* pour mixer on arrette sur l'avant dernier */
			if (!ret_chang) break;
			p = p->suiv;
		}
	}

	/* Affiche du debut d'ecran */

	centrer();
	sf = firstcol;
	poscol(); 

	if ((sn == numlgn) && (firstcol < sf)) {
		colonne  = (SWORD) ((colonne + firstcol) - sf);
		firstcol = sf;
	}

	sc = colonne;
	deblgn = finlgn = 0;	/* Suppression de la selection */
	editorOnShow();
	colonne = sc;
	ligne = (SWORD) (ligcur + LGINIT);
	show_basket_star();
	pos(ligne, colonne);

	fcolbest = firstcol;
	colbest  = colonne;

#ifdef ver14
	txtchg = TRUE;
#endif
}

static void Movcor(BOOL mixe)		/* Transfert un bloc via la corbeille */
{
	LONG  scur;

	SWORD  sc;

#ifdef ver14
	if (txtcons) {
		editor_bell();
		return;
		}
#endif
	if (deblgn == 0) {
		editor_bell();
		return;
		}


	if (boolbloc) {
#ifdef ver14
		if (test_bloc(numlgn)) {
			editor_bell();
			return;
			}
#endif
		}
	else	{
		if (test_corbeil(numlgn,colcur)) {
			editor_bell();
			return;
			}
		}

	if (tete != FNIL) {
		Raztamp();
	}

	sc = colcur;
/*
	if ((numlgn == deblgn) && (sc > fincol) && (deblgn == finlgn)) {
		sc -= fincol - debcol + 1;
	}
*/
	if ((numlgn >= deblgn) && (numlgn <= finlgn) && (sc > fincol) ) {
		sc -= (SWORD) (fincol - debcol + 1);
	}

	scur = numlgn;

	fcolbest = firstcol;
	colbest  = colonne;

	Rempcor();

	if (tete != FNIL) { 
		Delcorb();

		if (scur > numlgn) {
			scur -= delecart;
		}

		Poscorb(scur, sc);

		completer(1);

		colonne = colbest;
		firstcol = fcolbest;
		centrer();

		Inscor(mixe);
	}
#ifdef ver14
	txtchg = TRUE;
#endif
}


#ifdef ver14
static SWORD XXisalnum(BYTE c)
{
	BYTE *p;

	if (isalnum(c)) return(1);
	p = edit_msg[tstcar];
	while (*p) {
		if (*p++ == c) return(1);
	}	
	return(0);	/* pas touve */
}
#endif
	
#ifdef ver14

SWORD test_bloc(LONG l)
{
	/* Test si un caractere appartient a un bloc de selection */

	if (boolcor && boolbloc) {
		if ((l >= deblgn) && (l <= finlgn)) {
			if ((firstcol+colonne >= mfirstcol+realcol) && (firstcol + colonne < rfincol)) {
				return(1);	/* Appartient au bloc	*/
				}
			}
		}
	return(0);	/* n'appartient pas au bloc */
}
#endif

SWORD test_corbeil(LONG l, SWORD i)
{
	/* Test si un caractere appartient a la corbeille */
	if ((boolcor) && (!boolbloc)) {
		if ((l >= deblgn) && (l <= finlgn)) {
			if (((i < debcol) && (l == deblgn)) 
			||  ((i > fincol) && (l == finlgn))) {
				return(0);	
				}
			else	return(1);		/* Appartient a la corbeille */
			}	
		}
	return(0);	/* n'appartient pas au bloc */
}

SWORD test_atb(LONG l, SWORD i)
{
	if (boolcor && !boolbloc) return(test_corbeil(l,i));
#ifdef ver14
	if (boolcor && boolbloc) return(test_bloc(l));
#endif
	return(0);
}

void  alloc2(SWORD numl, BYTE FPTR pt)

/*	affiche la ligne de numero 'numl' a la ligne ecran de numero 'ligne'.
 *	cette fonction tient compte de la valeur de 'firstcol' pour cadrer
 *	l'affichage de la ligne dans l'ecran.
 *	Z! : le curseur n'est pas positionne au retour
 */

{					/* affligne */
	BYTE c;
	SWORD i = 0, j=0 , tcolonne = 1;
	SWORD oldcol;	/* Save la 1 valeur de TABUL */

	BOOL 	affatb=TRUE;		/* TRUE = atb(0) */

	LONG wlig;

	SWORD lnextab;

	wlig = (LONG) (numlgn - ligcur + numl);
	
	colonne = CLINIT;
	firstcol  = 0;

	while ((c = getmemchar(numl,i++)) != EOSTR) {
		if (c == TABUL) {
			oldcol = colonne;
			lnextab = 0;
			LgNextTab(lnextab,colonne);
#ifdef ver14
			if (boolbloc) {
				for (; colonne < oldcol + lnextab; colonne++) {
					/* calcul de la ligne mem[0] */
					if (test_atb(wlig,(SWORD) (i-1)) ) {
						/* dans la corbeille */
						*pt++ = ' ';
					}
				}
			}
			else {
#endif
				if (test_atb(wlig,(SWORD) (i-1))) * pt ++ = TABUL;
#ifdef ver14
			}
#endif
		}
		else {
			if (test_atb(wlig, (SWORD) (i - 1))) {
				/* dans la corbeille */
				*pt++ = c;
			}
			colonne++;
		}
	}

/* Test si la fin de ligne est compris dans le bloc */

	   if (boolcor && !boolbloc) { 
		if (test_corbeil(wlig,(SWORD) (i-1))) {
			/* dans la corbeil */
			/* le CTRL A */
			*pt++ = 0x01;
		}
	   }
#ifdef ver14
	   if (boolbloc && (wlig>=deblgn && wlig <= finlgn)) {
		if (firstcol + colonne < rfincol) {
			/* dans la corbeil */
			while (test_bloc(wlig) && colonne < rfincol) {
				*pt++ = ' ';
				colonne++;	
			}
		}
		*pt++ = 0x01;	/* fin de ligne */
	   }
#endif
	 *pt = EOSTR;
}					/* alloc2 */

extern	unsigned long maxnumlgn;

void	increment_line_counter()
{
	maxnumlgn += 1;
	if (traceon) {
		adjust_trace_information((SWORD) 1,  numlgn);
		}
	return;
}

void	decrement_line_counter()
{
	if ( maxnumlgn ) {
		maxnumlgn -= 1;
		}
	if ( traceon ) {
		adjust_trace_information((SWORD) MOINS_UN,  numlgn);
		}
	return;
}

void corb_CURB(BOOL mixe)
{
	SWORD lgnext, i, colo,j;
#ifdef ver14
	if (mixe) {
		Descente();	
	}
#endif
	if (fin_fichier) { 
		increment_line_counter();
		putdest(adrmemlin(0)); 
		for (j = 0; j < ligcur; ) {
			Xstrcpy(adrmemlin(j), adrmemlin((j+1)));
			j++;
			}
		numlgn++;

		colonne = CLINIT;
		colcur = 0;
		putmemchar(ligcur,colcur,EOSTR);
		}	
#ifdef ver14
	if (boolbloc) {
		if (!mixe) {
			if (colcur == 0) {
				for (colonne = CLINIT; colonne < colbest+fcolbest; colonne++) {
					changer(ligcur,0,1,(BYTE XPTR) " ");
					colcur;
					}
				colcur = (SWORD) (colonne - 1);
				}
		    	}
		if (getmemchar(ligcur,colcur) == EOSTR) {
			while (colonne < colbest + fcolbest) {
				putmemchar(ligcur,colcur, ' ');
				colonne ++; colcur++;
				}
			putmemchar(ligcur,colcur,EOSTR);
	    		}
		if (getmemchar(ligcur,colcur) == TABUL && colonne > fcolbest + colbest) {
			/* Une tabulation vient de faire depasser */
			/* Substitution de la Tabul. par des blancs */
			lgnext = 0;
			LgNextTab(lgnext,colonne);
			changer(ligcur,1,1,(BYTE XPTR) " ");

			colo = (SWORD) (colonne - lgnext);
			for (i = 0; i < lgnext; i++) {
				changer(ligcur,0,1,(BYTE XPTR) " ");
				if (colo + i < colbest+fcolbest) {
					colcur++;
					}
				}
	    		}
		}
	colonne = colbest;
	firstcol = fcolbest;
#endif
}

void get_token()
{
	BINAIRE fin,avant,lg;
	
	/* il faut commencer sur un caractŠre ascii */

	boolcor = 1; /* on force pour le mode Corbeil */
	
	fin = 1;
	avant = 0;
	lg = 0;

	index_buf = 0;
	buf_getch[index_buf] = EOSTR;

	/* Razcorb(); */
	/* on revient en arriŠre sur le premier caractŠre */
	while(fin) {
		switch ((BYTE) getmemchar(ligcur,colcur)) {
			case '\0':
			case '\t':
			case ';':
			case ' ':
			case ',':
			case '#':
			case '=':
			case '&':
			case '|':
			case ':':
			case '[':
			case ']':
			case '-':
			case '+':
			case '*':
			case '(':
			case ')':
			case '}':
			case '{':
				if (lg == 0) {
					fin = 0;
					break;
				}
				if (avant == 0) {
					Suivant();			
					Xatb(2);
					index_buf = 0;
					buf_getch[index_buf] = getmemchar(ligcur,colcur);
					avant = 1;
					}
				else	{
					Xatb(0);
					fin = 0;
					buf_getch[index_buf] = EOSTR;
					}			
				break;
			default:
				if (avant) {
					x_putch(getmemchar(ligcur,colcur));
					buf_getch[index_buf++] = getmemchar(ligcur,colcur);
					Suivant();
					}
				else {
					if (colcur) Precedent();
					else {
						/* Debut de source */
						Xatb(2);
						x_putch(getmemchar(ligcur,colcur));
						buf_getch[index_buf++] = getmemchar(ligcur,colcur);
						avant = 1;
					}
				}		
		}
		lg++;
	}	
}



#endif
#endif

