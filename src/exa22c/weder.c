// Ce source reste a modifier pour prendre en compte la table
// des messages d'erreur de l'executeur

/*
 *	E D E R ( e )
 *	-------------
 *
 *	Affichage des erreurs d'execution et d'initialisation
 *
 */

#ifndef	DEBUGGER
VOID eder( e )
#else
VOID syseder( e )
#endif
EXAWORD	e;
{ EXABYTE buf[512];
#ifdef WIN32
extern void __fastcall AlertBox(BPTR);
#else
extern void __fastcall far AlertBox(BPTR);
#endif

	if ( e != 0 ) {

#ifdef	ABAL14
#ifdef	ABALPS
		/* Liberate first any user libraries */
		/* --------------------------------- */
		liberate_dynamic_libraries();
#endif
#endif

		/* Ensure Error sent to Screen OutPut */
		/* ---------------------------------- */
#ifdef RT_AIX
		prndest = 1; prnptr = (BPTR)buf; prnleng = 511;
#else
		prndest = 0; prnptr = (BPTR)buf; prnleng = 511;
#endif

		/* Debut d'un message d'erreur */
		/* --------------------------- */
		x_cprintf((BPTR)TalkPtr[2]);
		x_putch(' ');

		/* Erreurs d'Entree Sorties  1 a 19 */
		/* -------------------------------- */
		if ( e < 20 ) {
			x_cprintf((BPTR)TalkPtr[3]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme 20 a 29 */
		/* ----------------------- */
		if (( e > 19 ) && ( e < 30 )) {
			x_cprintf((BPTR)TalkPtr[4]);
			x_putch(0x0009);
			}
		/* Erreurs Syntaxe de Commande 30 a 39 */
		/* ----------------------------------- */
		if (( e > 29 ) && ( e < 40 )) { 
			x_cprintf((BPTR)TalkPtr[5]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de Fichiers 40 a 96 */
		/* ----------------------------------- */
		if (( e > 39 ) && ( e < 97 )) {
			x_cprintf((BPTR)TalkPtr[6]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes 97 a 170 */
		/* ------------------------- */
		if (( e > 96 ) && ( e < 170)) { 
			x_cprintf((BPTR)TalkPtr[7]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme de fichiers 170 a 190 */
		/* ------------------------------------- */
		if (( e > 169) && ( e < 190)) {
			x_cprintf((BPTR)TalkPtr[8]);
			x_putch(0x0009);
			}
		/* Erreurs Systeme Graphiques  190 a 196 */
		/* ------------------------------------- */
		if (( e > 189) && ( e < 197)) {
			x_cprintf((BPTR)TalkPtr[9]);
			x_putch(0x0009);
			}
		/* Erreurs Systemes Divers  190 a 196 */
		/* ---------------------------------- */
		if ( e > 196)		      {
			x_cprintf((BPTR)TalkPtr[10]);
			x_putch(0x0009);
			}

		/* Affichage d'identite ABAL plus Adresse d'erreur */
		/* ----------------------------------------------- */
		intvisi(e);
		x_putch('\n');
		if ( sicico & ONSEM_SEG ) { /* If Erreur d'execution du T-code */
			x_cprintf((BPTR)TalkPtr[11]); x_putch(' ');
			showword(((lineptr - TcodeSegment) -1),4);
			if ( sicico & ONSEM_PRC ) { /* If Erreur de Procedure		*/
				x_cprintf((BPTR)" (proc: "); intvisi(procid);
				x_putch(')');
				}
			x_cprintf((BPTR)" (seg: "); intvisi(cur_seg); x_putch(')');
			}

		x_putch(0);

		/* Affiche le tout dans une boite de dialogue */
		AlertBox((BPTR)buf);
		}

	return;
}


