#ifndef	_edend_c
#define	_edend_c

/*	------------------------------------	*/
/*		 F I N E C R A N ()		*/
/*		 ------------------		*/
/*	liberation of screen controllers	*/
/*	------------------------------------	*/

static VOID finecran()
{					/* finecran */
	ChnFic XPTR p;

#ifdef prologue
	SWORD i;
#endif

	/* Vidage eventuel de la corbeil */
	if (tete != FNIL) {
		Raztamp();
		pos(1,68); putch(' ');
		}

	if (!( is_window_editor() )) {
		pos(LGINIT,CLINIT); atb(22); pos((SWORD) (LGINIT+1),1);
		}

	prfo(1,SAVCURD,(SWORD) (Xstrlen(SAVCURD)));
	prfo(4,SAVCURB,(SWORD) (Xstrlen(SAVCURB)));
	prfo(3,SAVCURH,(SWORD) (Xstrlen(SAVCURH)));
	prfo(2,SAVCURG,(SWORD) (Xstrlen(SAVCURG)));
	prfo(0x00AC,ST7F,(SWORD) (Xstrlen(ST7F)));


#ifdef prologue
	for (i=128; i < 138; i++) {
		prfo(i,(BYTE XPTR) (epstfp[i-128]),(SWORD) (LGTFP-1));
		}
#endif
	/* liste des ecarts */
	if (deb_chnfic != GenericNULL(ChnFic)) {
		while (deb_chnfic != GenericNULL(ChnFic)) {
			p = deb_chnfic;
			deb_chnfic = p->suiv;

			liberate(p);
			}
		};

	flg_cico = close_console();

}	

#endif	/* _edend_c */
	/* -------- */

