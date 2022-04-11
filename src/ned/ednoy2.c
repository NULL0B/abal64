#include "palet.h"
#ifndef ver14

/*	lecture au clavier d'une comande dans le buffer pointe par pcom
 *	lg caracteres au maximum sont acceptes
 *	si le retour chariot est donne en premier, la commande precedente
 *	est maintenue.
 */

static void get_saisie (pcom,lg)
	BYTE  *	pcom;
	SWORD  	lg;
{					/* getcom */
	BYTE	*ch = pcom;
	BYTE 	*work;
	BYTE	c;
	int	n, i, fincom; 
 
	fincom = aff_com(pcom);
	ch = pcom; pos(1,31); c = getch(); n = 0;

	if (c == CR) 
		return;
	do 	{
		if (c == DELBACK) {
			if (n == 0) {
				editor_bell();
				}
			else 	{
			  	putch(CURG);
				work = ch;
				ch --;
				i = 0;
				while (*work) {
					c = *work++;
				     	*(ch + i++) = c;
					if (c != ESCAPE) {
						if (c < 0x0020) {
							Xatb(APU);
							putch(0x0040+c);
							Xatb(0);
							}
						else 	{
							putch(c);
							}

						}
					else 	{ 
						Xatb(APU); putch('&'); Xatb(0); 
						}
					}				

				*(ch + i) = EOSTR;
				fincom--;

				putch(' ');
				n--;
				pos(1,31 + n);
			}
		}
		else if (c == PDEBFIN) {
			if (*ch == EOSTR) {
				/* Aller en debut de zone */
				ch = pcom;
				pos(1,31); n = 0;
			}
			else {
				/* Aller en fin de zone */
				n = Xstrlen(pcom);
				pos(1,31 + n);
				ch = pcom + n;				
			}
		}
		else if (c == CURG) {	/* retour en arriere */
			if (n == 0) editor_bell();
			else {
				*ch--; n--; 
				putch(c);
			};
		}
		else if (c == CURD) {	/* avance a droite */
			if (*ch == EOSTR) editor_bell();
			else {
				c = *ch++; n++;
				if (c != ESCAPE) {
					if (c < 0x0020) {
						Xatb(APU);
						putch(0x0040+c);
						Xatb(0);
						}
					else 	{
						putch(c);
						}

				}
				else { Xatb(APU); putch('&'); Xatb(0); }
			};
		}

		else if (c == T7F) {
			if (n == fincom) {
				editor_bell();
			}
			else {
				work = ch+1;
				i = 0;
				while (*work) {
					c = *work++;
				     	*(ch + i++) = c;
					if (c != ESCAPE) {
						if (c < 0x0020) {
							Xatb(APU);
							putch(0x0040+c);
							Xatb(0);
							}
						else 	{
							putch(c);
							}
						}
					else 	{ 
						Xatb(APU); putch('&'); Xatb(0); 
						}
					}				

				*(ch + i) = EOSTR;
				fincom--;

				putch(' ');
				pos(1,31 + n);
				}
			}
        	else 	{			/* caractere "normal" */
			if (n == lg-1) editor_bell();
			else 	{
			 if (ctrlbyte(c) && (c != ESCAPE) && (c != TABUL) && (c != LIMLIG)) {
			    editor_bell();
			 	}
			 else 	{
			    	if (ctrlbyte(c) && (c != ESCAPE)) {
					Xatb(APU);
					putch(0x0040+c);
					Xatb(0);
			     		}	
			     	else 	{
					if (c != ESCAPE) putch(c);
					else { Xatb(APU); putch('&'); Xatb(0); }
			     		};
			    *ch++ = c; n++;
			    if (n == fincom) {
				*ch = EOSTR;
				fincom++;
			    }
			  }
			}
		}
		c = getch();
	}
	while (c != CR);
	*ch = EOSTR;
	Xatb(21);
}					/* getcom */

static int aff_com(ch)
BYTE *ch;
{
	SWORD fincom, i;
	BYTE c;
	x_bstart();
	fincom = 1;
	while (*ch != EOSTR) {
		c = *ch++;
		if (c != ESCAPE) {
			if (ctrlbyte(c)) {
				Xatb(APU);
				putch(0x0040+c);
				Xatb(0);
				}	
			else 	{
				putch(c);
				}
			}
		else 	{ Xatb(APU); putch('&'); Xatb(0); }
		fincom++;
	}

	for (i = fincom; i < LGCOM; i++) x_putch(' ');
	x_bflush();
	return(fincom);
}

#else

/*	lecture au clavier d'une comande dans le buffer pointe par pcom
 *	lg caracteres au maximum sont acceptes
 *	si le retour chariot est donne en premier, la commande precedente
 *	est maintenue.
 */

static VOID get_saisie( BYTE XPTR pcom, SWORD lg)
{
	SWORD ret;
	BYTE tmp[256];
	WORD	askatc=31;
	WORD	asknbc=40;
	
	Xstrcpy(tmp,pcom);

	do 	{
		if ((askatc+asknbc) >= MXCOL) {
			askatc = 1;
			asknbc = (MXCOL-4);
			}			
		ret = ask(1,askatc,asknbc,lg,tmp);
		if ( askatc == 1 )
			showfilename();

		if (ret == -3) 
			BackCom(tmp);
		else if (ret == -4) 
			NextCom(tmp);
		}
	while (ret < 0);
	if (ret >= 0) {
		if (tmp[0] != ';') {
			maj_histo(tmp);
			}
		Xstrcpy(pcom,tmp);
		}
	Xatb(0);

}
#endif

static BOOL confirme (SWORD l, SWORD c, BYTE XPTR msg)
/*	demande d'une confirmation (oui/non)
 */
{					/* confirme */
	BYTE	rep, val;
	BOOL	flgret = TRUE;
	SWORD	posit;

	on_cursor();

	Xatb(0); pos(l,c); x_cprintf(msg);
	posit = (SWORD) (c + (Xstrlen(msg)));
	pos(l,posit);
	do 	{
		rep = getch(); 
		rep = (BYTE) tolower(rep);
		if ((rep == rno) || (rep == ryes)) {
			putch(rep); val = getch();
			if (val == CR) {
				if (rep == rno) flgret = FALSE;
				break;
				}
			pos(l,posit);
			if (val != CURG)
				editor_bell();
			}
		else 	{ 
		  	if (rep == 0x1b) {
				flgret = (BOOL) 2;
				break;
		  		}
		  	else 	editor_bell();
			}
		}
	while (1);	/* sortie par BREAK */
	
	off_cursor();
	Xatb(0);
	return (flgret);
}					/* confirme */


VOID	reaffligne()
{
	affligne((ligne - LGINIT));
}

/*	positionnement en debut de fichier	*/
/*	----------------------------------	*/

VOID posdeb ()
{
	SWORD	i;

	numlgn = 1;	/* dans tous les cas on revient a la 1ere ligne */
	if (fdest->Feof) {
		 /* destination vide : le debut du fichier est deja affiche */
		ligcur = 0; colcur = 0; ligne = LGINIT; colonne = CLINIT;
		/* voir si il faut deplacer le curseur */
		newcol(FALSE);
		return;
		}
	/* mettre la memoire affichee dans le fichier retour */
	for (i = lastligne; i > 0; i--) 
		putret(adrmemlin(i)); 
	putret(adrmemlin(0));
	/* remonter le fichier destination jusqu'a son debut */
	while (getdest(lgntemp))
		putret(lgntemp);
	/* mettre en memoire le debut du fichier retour */
	firstcol = 0; 
	ligne = LGINIT; colonne = CLINIT; 
	pos(ligne,colonne);
	aff_ecran = TRUE;
	x_bstart();
	while ( ligne <= MXLIG) {
		if (!getret(adrmemlin(i))) { /* fichier source est vide */
			break;
			}
		affligne(i); ligne++; i++;
		}
	x_bflush();
	draw_editor_scrollbar();
 	aff_ecran = FALSE;
	lastligne = (SWORD) (i - 1); 
	ligcur = colcur = 0;
	ligne = LGINIT; colonne = CLINIT;
}					/* posdeb */

/*	positionnement en fin de fichier	 */

VOID 	posfin()
{
	SWORD	i;

	if (tstfinsource() && fret->Feof) {
		/* deja en fin de fichier */
		numlgn += (SWORD) (lastligne - ligcur);
		ligcur = lastligne; colcur = 0;
		ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
		/* voir si il faut deplacer le curseur */
		newcol(FALSE);
		return;
		}
	/* mettre la memoire affichee dans le fichier destination */
	for (i = 0; i <= lastligne; i++) 
		putdest(adrmemlin(i));
	/* continuer jusqu'a la fin du fichier retour */
	while (getret(lgntemp))
		putdest(lgntemp);
	/* et avancer autant que possible dans le source */
	while (getsource(lgntemp))
		putdest(lgntemp);
	/* relire le fichier destination pour mettre en memoire */
	i = ligcur = lastligne = (SWORD) (NBLIG / 2); colcur = 0;
	do 	{
		getdest(adrmemlin(i)); i--;
		}
	while (i != 0);
	getdest(adrmemlin(0));
	firstcol = 0; 

	numlgn = (LONG) (fdest->nblgn + lastligne +1);
	editorOnShow();
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	return;
}					/* posfin */


static int   poslgn (SWORD sens, LONG nb)

/*	positionnement a la ligne nb du fichier
 *	en absolu si sens = 0, en relatif par rapport a la ligne
 *	courante, en remontant si sens = -1, en avancant si sens = 1.
 */

{					/* poslgn */
	LONG i, j, ecart;

	if (sens == 1)
		nb += numlgn;
	else if (sens == MOINS_UN) {
		if (numlgn == 1) return(0);
		if (nb > numlgn) {
			editor_bell(); return(0);
			}
		nb = (LONG) (numlgn - nb);

		}	
	else if (nb == (LONG)numlgn)	/* deja positionne */
		return(0);
	if (nb > (LONG)numlgn) {		/* on avance */
		ecart = (LONG) (nb - numlgn); i = (LONG) (ligcur + ecart);
		if (i <= lastligne) {	/* reste en memoire */
			ligcur = (SWORD)i; colcur = 0; numlgn = nb;
			ligne = (SWORD) (i + LGINIT); colonne = CLINIT;
			/* voir si il faut deplacer le curseur */
			newcol(FALSE);
			return(0);
			}
		/* il faut avancer dans le fichier */
		for (i = 0; i <= ligcur; i++) putdest(adrmemlin(i));
		for ( ; i <= lastligne; i++) {
			putdest(adrmemlin(i)); ecart--; numlgn++;
			}
		while (ecart != 0) {
			if (!getret(lgntemp)) {
				while (ecart != 0) {
					if (!getsource(lgntemp))
						break;
					putdest(lgntemp); ecart--; numlgn++;
					}
				break;
				}
			putdest(lgntemp); ecart--; numlgn++;
			}
		}
	else 	{				/* on recule */
		ecart = (LONG) (numlgn - nb);
		if ((ligne - LGINIT) >= ecart) { /* reste en memoire */
			ligcur -= (SWORD) ecart; colcur = 0; numlgn = nb;
			ligne -= (SWORD) ecart; colonne = CLINIT;
			/* voir si il faut deplacer le curseur */
			newcol(FALSE);
			return(0);
		}
		/* reculer dans le fichier */
		for (i = lastligne; i > ligcur; ) {
			putret(adrmemlin(i));
			i--;
			}
		putret(adrmemlin(i));
		if (i != 0) {
			i--;
			while (i != 0) {
				putret(adrmemlin(i));
				i--; ecart--; numlgn--;
				}
			putret(adrmemlin(0)); ecart--; numlgn--;
			}
		while (ecart != 1) {
			getdest(lgntemp); putret(lgntemp); ecart--; numlgn--;
			}
		numlgn--;
		}
	/* cadrer la memoire autour de la ligne trouvee */
	i = ligcur = lastligne = (SWORD) (NBLIG / 2); colcur = 0; j = 0;
	do 	{
		if (!getdest(adrmemlin(i))) {
			/* destination vide : recadrer la memoire */
			i++;
			if (i <= lastligne) {
				ligcur = (SWORD) (lastligne - i);
				for (j = 0; i <= lastligne; j++) {
					Xstrcpy(adrmemlin(j),adrmemlin(i)); i++;
				}
				i = j; j = 1;
			}
			else
				ligcur = 0;
			break;
		}
		i--;
	}
	while (i != 0);
	if (j == 0) {
		getdest(adrmemlin(0));
		i = (LONG) (ligcur + 1);
		}
	completer((SWORD)i);
	firstcol = 0; 
	editorOnShow();
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	return(1);
}					/* poslgn */



/*	ecriture de 'nb' lignes a partir de la ligne courante
 *	dans le fichier designe par 'nomfic'.
 *	si 'keep' vaut 'FALSE' en entree, le fichier peut etre ecrase
 *	si il existe deja.
 */


static int ecrfic(BOOL keep, LONG nb, BYTE XPTR nomfic)


{					/* ecrfic */
	FILE	XPTR fic;
	SWORD	i = ligcur,j;
	BOOL	refresh = FALSE;
	BOOL    find = FALSE;			/* Correction 1.2d */

	SWORD resac;

	if (colcur != 0) {	/* non admis !! */
		editor_bell(); return (FALSE);
		}

	resac = (SWORD) (Xaccess(nomfic,0));
	
#ifdef unix
	if ((resac != 0) && (errno != ENOENT)) {
		Xerreur(USUAL,ernoy00);
		editor_bell();	
		return(FALSE);
		}
		
	liberlox(nomfic);
#endif

	if ((keep == TRUE) && (resac == 0)) {	/* fichier existe */
		Xerreur(USUAL,ficexist); editor_bell(); return (FALSE);
		}

#ifdef ver21
	if (keep == 2)	fic = Xfopen(nomfic,"a+");
	else 		fic = Xfopen(nomfic,"w");
#else
	fic = Xfopen(nomfic,"w");
#endif	
	if (fic == GenericNULL(FILE)) {
#ifdef unix
		if (errno != ENOENT) {
			Xerreur(USUAL, ernoy00);
			editor_bell();
			return (FALSE);
			}
#endif
		Xerreur(USUAL,ficnwrit); editor_bell(); return (FALSE);
		}

#ifdef ver21
#ifdef msdos
	if (keep == 2)	Xfseek(fic, 0L, SEEK_END); 
#endif
#endif
	while (nb != 0) {
		if (i > lastligne) {
			if (lastligne == NBLIG-1) {	/* fin de la memoire */
				for (j = 0; j <= lastligne; j++)
					putdest(adrmemlin(j));
				}
			else 	{
				nb  = 0; /* correction du 14/02/92 */
				}
			break;
			}
		Xfputs((BYTE XPTR) adrmemlin(i),fic); Xfputc('\n',fic);
		i++; numlgn++; nb--;
		}

	if (nb == 0) find = TRUE;

	while (nb != 0) { /* continuer en avancant dans le fichier retour */
		if (!getret(lgntemp))	/* fin du fichier retour */
			break;
		Xfputs(lgntemp,fic); Xfputc('\n',fic); putdest(lgntemp);
		numlgn++; nb--;
		}
	while (nb != 0) { /* continuer en avancant dans le source */
		if (!getsource(lgntemp)) /* fin du fichier source */
			break;
		Xfputs(lgntemp,fic); Xfputc('\n',fic); putdest(lgntemp);
		numlgn++; nb--;
		}

	numlgn--;
	i--;

	if (i >= lastligne && find == FALSE) {	/* recadrer en memoire */
		for (j = lastligne; j != 0; j--)
			getdest(adrmemlin(j));
  		getdest(adrmemlin(0));
		}
	
	ligcur = i;
	if (centrer())
		refresh = TRUE;
	colcur = 0; firstcol = 0;
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	newcol(refresh);
#ifndef LGEXACTE
	Xfputc(EOTXT,fic);	/* marque fin de fichier */
#endif
	Xfclose(fic);
	return (TRUE);
}					/* ecrfic */

static BOOL ecrcor(BOOL keep, BYTE XPTR nomfic)

/*	ecriture de la corbeille courante dans un fichier */
{					/* ecrcor */
	FILE	*fic;
	SWORD i;

	SWORD 	resac;

	StrCor FPTR p;

	if (tete == FNIL) {	/* non admis !! */
		editor_bell(); return (FALSE);
		}

	resac = (SWORD) (Xaccess(nomfic,0));
	
#ifdef unix
	if ((resac != 0) && (errno != ENOENT)) {
		Xerreur(USUAL,ernoy00);
		editor_bell();	
		return(FALSE);
		}
		
	liberlox(nomfic);
#endif

	if ((keep==TRUE) && (resac == 0)) {	/* fichier existe */
		Xerreur(USUAL,ficexist); editor_bell(); return (FALSE);
		}
#ifdef ver21
	if (keep == 2) 	fic = Xfopen(nomfic,"a+");
	else 		fic = Xfopen(nomfic,"w");
#else
	fic = Xfopen(nomfic,"w");
#endif
	if (fic == GenericNULL(FILE)) {
#ifdef unix
		if (errno != ENOENT) {
			Xerreur(USUAL, ernoy00);
			editor_bell();
			return (FALSE);
			}
#endif
		Xerreur(USUAL,ficnwrit); editor_bell(); return (FALSE);
		}

#ifdef ver21 
#ifdef msdos
	if (keep == 2) Xfseek(fic, 0L, SEEK_END);
#endif
#endif
	p = tete;
	while (p->suiv != FNIL) {
		Mstrcpy((BYTE FPTR) lgntemp, p->lgn);
		i = (SWORD) (Xstrlen(lgntemp));
		if (lgntemp[i-1] == LIMLIG) lgntemp[i-1] = '\0';
		Xfputs(lgntemp,fic); Xfputc('\n',fic);
		p = p->suiv;
		}

#ifndef LGEXACTE
	Xfputc(EOTXT,fic);	/* marque fin de fichier */
#endif
	Xfclose(fic);
	return (TRUE);
}					/* ecrcor */

static BOOL lirefic(BYTE XPTR nomfic)

/*	lecture du fichier designe par 'nomfic', et insertion
 *	de son contenu a partir de la ligne courante
 */

{					/* lirefic */
	FILE	*fic;
	SWORD	i,j;
	char	*lptr;
	BOOL	first = TRUE;

	if (colcur != 0) {	/* non admis !! */
		editor_bell(); return (FALSE);
		}
	if (traceon) {	/* interdit en mode TRACE */
		editor_bell(); return (FALSE);
		}
	fic = Xfopen(nomfic,"r");
	if (fic == GenericNULL(FILE)) {
#ifdef unix
		if (errno != ENOENT) {
			Xerreur(USUAL,ernoy00);
			editor_bell();
			return(FALSE);
			}
#endif
		Xerreur(USUAL,ficnexist); editor_bell(); return (FALSE);
		}
	do 	{
		lptr = XXfgets(lgntemp,LGLIGNE,fic);
		if (lptr == GenericNULL(char)) {
			if (Xfeof(fic)) {
				if (first) {
					Xerreur(USUAL,ficvide); editor_bell();
					Xfclose(fic); return (FALSE);
					}
				else 
					break;	/* fin du fichier a lire */
				}
			else 	{
				editor_bell(); Xfclose(fic);
				if (first) {
					Xerreur(USUAL,ficnread); return (FALSE);
					}
				else	{
					Xerreur(FATALE,ficnread);
					}
				}
			}
		lgntemp[Xstrlen(lptr) -1] = EOSTR;
		if (first) {
			for (i = 0; i < ligcur; i++)
				putdest(adrmemlin(i));
			first = FALSE;
			}
		else
			numlgn++;
		putdest(lgntemp);
		}
	while (TRUE);	/* sortie par BREAK sur fin de fichier a lire */
	Xfclose(fic);
	/* recadrer la memoire */
	if (ligcur == 0) {
		if (lastligne < NBLIG - 1) /* reste en memoire */
			lastligne++;
		else
			putret(adrmemlin(lastligne));
		for (j = lastligne; j != 0; j--)
			Xstrcpy(adrmemlin(j),adrmemlin((j-1)));
		}
	else 	{
		i = 1;
		for (j = ligcur; j <= lastligne; j++) {
			Xstrcpy(adrmemlin(i),adrmemlin(j)); i++;
			}
		/* completer a partir de la ligne i */
		completer(i);
		}
	getdest(adrmemlin(0)); ligcur = 0;
	centrer();
	colcur = 0; firstcol = 0;
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	newcol(TRUE);
	return (TRUE);
}					/* lirefic */

static BOOL getampon (SWORD nb)

/*	inserer 'nb' fois le contenu du tampon a la position courante
 */

{					/* getampon */
	MemTemp	*p;

	SWORD	i,j;

	if (colcur != 0) {	/* non admis !! */
		editor_bell(); return (FALSE);
		}
	if (tampon == GenericNULL(MemTemp)) {
		Xerreur(USUAL,bufvide); editor_bell(); return (FALSE);
		}
	else 	{
		p = tampon->suiv;
		if (p == GenericNULL(MemTemp)) {
			Xerreur(USUAL,bufvide); editor_bell(); return (FALSE);
			}
		}
	for (i = 0; i < ligcur; i++)
		putdest(adrmemlin(i));
	numlgn--;	/* pour pallier la premiere incrementation */
	while (nb != 0) {
		do 	{
			putdest(p->lgn); numlgn++; p = p->suiv;
			increment_line_counter();
			}
		while (p != GenericNULL(MemTemp));
		nb--; p = tampon->suiv;
		}
	/* recadrer la memoire */
	if (ligcur == 0) {
		if (getmemchar(ligcur,0) != EOSTR) {
			if (lastligne < NBLIG - 1) /* reste en memoire */
				lastligne++;
			else
				putret(adrmemlin(lastligne));
			for (j = lastligne; j != 0; j--)
				Xstrcpy(adrmemlin(j),adrmemlin((j-1)));
			}
		}
	else 	{
		i = 1;
		for (j = ligcur; j <= lastligne; j++) {
			Xstrcpy(adrmemlin(i),adrmemlin(j)); i++;
			}
		completer(i);
		}
	getdest(adrmemlin(0)); ligcur = 0;
	centrer();
	colcur = 0; firstcol = 0;
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	newcol(TRUE);
	return (TRUE);
}					/* getampon */

static BOOL putampon (BOOL lib, BOOL keep, SWORD nb)

/*	mettre les 'nb' lignes qui suivent dans le tampon
 *	si 'lib' vaut 'TRUE' en entree, les lignes sont ajoutees au tampon.
 *	si 'keep' vaut 'TRUE' en entree, les lignes sont maintenues
 *	dans le fichier a leur position courante.
 */
{					/* putampon */
	MemTemp	*p,*q;
	SWORD	i,j;
	BOOL retour;

	if (colcur != 0) {	/* non admis !! */
		editor_bell(); return (FALSE);
		}
	if (lib) {
		libtampon(); 
		/* zone tampon vide au depart */
		if (tampon == GenericNULL(MemTemp)) {
			tampon = (MemTemp *) allocate(sizeof(MemTemp));
			if (tampon == GenericNULL(MemTemp))
				Xerreur(FATALE,ernoy03);
			tampon->suiv = GenericNULL(MemTemp);
			}
		p = tampon;
		}
	else 	{
		p = tampon; q = tampon->suiv;
		while (q != GenericNULL(MemTemp)) {
			p = q; q = q->suiv;
			}
		}

	/* recadrer en memoire */
	for (i = 0; i < ligcur; i++)
		putdest(adrmemlin(i));

	/* commencer par les lignes en memoire */

	retour = TRUE;

	while (nb != 0) {
		if (i > lastligne)
			break;
		q = (MemTemp *) allocate(sizeof(MemTemp));
		if (q == GenericNULL(MemTemp)) {
			Xerreur(USUAL,ernoy03); editor_bell(); 
			retour = FALSE;
			p->suiv = GenericNULL(MemTemp);
			nb = 0;
			break;
			}
		p->suiv = q;
		q->lgn = (BYTE *) allocate(Xstrlen(adrmemlin(i))+1);
		if (q->lgn == GenericNULL(BYTE)) {
			Xerreur(USUAL,ernoy03); editor_bell();
			/* recadrer la memoire !! */
			retour = FALSE;
			nb = 0;
			break;	
			}
		Xstrcpy(q->lgn,adrmemlin(i));
		if (keep) {
			putdest(adrmemlin(i));
			numlgn++;
			}
		else 	{
			decrement_line_counter();
			}
		i++; nb--; p = q;
		}

	/* completer avec le contenu du fichier retour */
	while (nb != 0) {
		if (!getret(lgntemp))
			break;
		q = (MemTemp *) allocate(sizeof(MemTemp));
		if (q == GenericNULL(MemTemp)) {
			putret(lgntemp);  /* Remise de la ligne qui deborde */
			Xerreur(USUAL,ernoy03); editor_bell(); 
			retour = FALSE;
			p->suiv = GenericNULL(MemTemp);
			nb = 0;
			break;
			}
		p->suiv = q;
		q->lgn = (BYTE *) allocate(Xstrlen(lgntemp)+1);
		if (q->lgn == GenericNULL(BYTE)) {
			putret(lgntemp); 
			/* Remise de la ligne en erreur */
			Xerreur(USUAL,ernoy03); editor_bell();
			/* recadrer la memoire !! */
			retour = FALSE;
			nb = 0;
			break;	
			}
		Xstrcpy(q->lgn,lgntemp);
		if (keep) {
			putdest(lgntemp);
			numlgn++;
			}
		else 	{
			decrement_line_counter();
			}
		nb--; p = q;
	}
	/* completer avec le contenu du fichier source */
	while (nb != 0) {
		if (!getsource(lgntemp))
			break;
		q = (MemTemp *) allocate(sizeof(MemTemp));
		if (q == GenericNULL(MemTemp)) {
			putret(lgntemp); /* Remise de la ligne en erreur */
			Xerreur(USUAL,ernoy03); editor_bell(); 
			retour = FALSE;
			p->suiv = GenericNULL(MemTemp);
			nb = 0;
			break;
		}
		p->suiv = q;
		q->lgn = (BYTE *) allocate(Xstrlen(lgntemp)+1);
		if (q->lgn == GenericNULL(BYTE)) {
			putret(lgntemp); /* Remise de la ligne en erreur */
			Xerreur(USUAL,ernoy03); editor_bell();
			/* recadrer la memoire !! */
			retour = FALSE;
			nb = 0;
			break;	
			}
		Xstrcpy(q->lgn,lgntemp);
		if (keep) {
			putdest(lgntemp);
			numlgn++;
			}
		else 	{
			decrement_line_counter();
			}
		nb--; p = q;
		}

	p->suiv = GenericNULL(MemTemp);
	/* recadrer les lignes qui sont restees */
	for (j = 0; i <= lastligne; j++, i++)
		Xstrcpy(adrmemlin(j),adrmemlin(i));
	completer(j);
	ligcur = 0;
	centrer();
	colcur = 0; firstcol = 0;
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	newcol(TRUE);
	return (retour);
}					/* putampon */


static VOID suplines (LONG nb)


/*	detruire 'nb' lignes a partir de la position courante
 */

{					/* suplines */
	SWORD	i,j;

	/* recadrer en memoire */
	for (i = 0; i < ligcur; i++)
		putdest(adrmemlin(i));
	/* commencer par les lignes en memoire */
	while (nb != 0) {
		if (i > lastligne)
			break;
		decrement_line_counter();
		i++; nb--;
		}
	/* continuer avec le contenu du fichier retour */
	while (nb != 0) {
		if (!getret(lgntemp))
			break;
		decrement_line_counter();
		nb--;
		}
	/* continuer avec le contenu du fichier source */
	while (nb != 0) {
		if (!getsource(lgntemp))
			break;
		decrement_line_counter();
		 nb--;
		}
	/* recadrer les lignes qui sont restees */
	for (j = 0; i <= lastligne; j++, i++)
		Xstrcpy(adrmemlin(j),adrmemlin(i));
	completer(j);
	ligcur = 0;
	centrer();
	colcur = 0; firstcol = 0;
	ligne = (SWORD) (ligcur + LGINIT); colonne = CLINIT;
	newcol(TRUE);
	return;
}					/* suplines */

static VOID libtampon ()

/*	liberation du tampon memoire
 */
{					/* libtampon */
	MemTemp	*p;
	MemTemp *q;
	
	if (tampon == GenericNULL(MemTemp)) return;
	p = tampon->suiv;

	while (p != GenericNULL(MemTemp)) {
		liberate(p->lgn); q = p; p = p->suiv;
		liberate(q);
		}

	if (tampon != GenericNULL(MemTemp)) {
		liberate(tampon);
		tampon = GenericNULL(MemTemp);
		}
}					/* libtampon */


static VOID reposit(LONG l, SWORD c, SWORD fc, SWORD colr) 	/* Repositionne le source */
{
	SWORD i;
	SWORD j, k;
	LONG memb, memh;

	memb = (LONG) (numlgn - ligcur - 1);
	memh = (LONG) (memb + lastligne + 1); /* l -> 1 a 23  lastligne -> 0 a 22 */

	if (l < memb) {
		/* Purger la memoire dans ret */
		for (i=lastligne ; i >= 0; ) {
			putret(adrmemlin(i));
			i--;
			}
		numlgn = (memb - 1);
		getdest(adrmemlin(0));

		do 	{
			putret(adrmemlin(0));
			getdest(adrmemlin(0));
			numlgn--;
			}
		while (numlgn >= l);
		numlgn++;	/* Pour compenser */
		completer(1);
		ligcur = 0;
		centrer();
		}
	else 	{
		if (l > memh) {
				/* Purge dans dest */
			for (i=0; i <= (SWORD) lastligne; i++) {
				putdest(adrmemlin(i));
				};
			numlgn = (LONG) (memb + i + 1);

			if (!getret(adrmemlin(0))) getsource(adrmemlin(0));

			while ((numlgn < l)) {
				putdest(adrmemlin(0));
				if (!getret(adrmemlin(0))) getsource(adrmemlin(0));
				numlgn++;
				}
			completer(1);
			ligcur = 0;
			centrer();
			}
		else 	{
			/* la ligne courante et la old position sont en memoire */
			if (numlgn > l) {
				numlgn = (LONG) (numlgn - (numlgn - l));
				}
			else 	{
				if (numlgn < l)
					numlgn = (LONG) (numlgn + (l-numlgn));
				}

			ligcur = (SWORD) (l - memb - 1);
			}
		}

	ligne = (SWORD) (ligcur + LGINIT);
	colcur = c; 
	firstcol = fc;
	colonne = colr;
	editorOnShow();
}

static VOID liginv(BYTE XPTR p)
/*	
	Inversion d'une ligne pour la recherche en ariere
*/
{
	SWORD i, j, lg;
	BYTE c;

	lg = (SWORD) (Xstrlen(p));
	i  = (SWORD) (lg / 2);
	j = 0;
	while (j < i) {
		c      = p[--lg];	
		p[lg]  = p[j];
		p[j++] = c;
		}
}

static BOOL brecher(SWORD nb, BYTE XPTR val)
/*
*	Recherche en arriere
*/
{
	SWORD k, j, lg, lgval; 
	SWORD i;
	SWORD mf; /* sauvegarde de firstcol */
	SWORD sav_lg;

	/* Inversion de l'argument */
	lgval = (SWORD) (Xstrlen(val));
	liginv(val);

	if (lgval > 1) {
		if (val[lgval - 1] == LIMLIG) lgval--;
		}
	if (val[0] == LIMLIG) lgval--;

	/* Recherche en memoire */
	
	i = ligcur;

  	if (colcur > 1) {
		colcur = (SWORD) (Xstrlen(adrmemlin(ligcur)) - colcur);
		}
	else 	{
		if (colcur == 0) {
			i--;
			numlgn--;
			}
		else 	{
			colcur = (SWORD) (Xstrlen(adrmemlin(ligcur)) - 1);
			}
		}
	for ( ; i >= 0; ) {
		lg = (SWORD) (Xstrlen(adrmemlin(i)));
		liginv(adrmemlin(i));
#ifdef ver14
		while (lgnsearch(val,adrmemlin(i),1)) { /* Trouve */
#else
		while (lgnsearch(val,adrmemlin(i),lgval)) { /* Trouve */
#endif
			nb--;
			if (nb == 0) {	/* bonne occurence */
				liginv(adrmemlin(i));
				liginv(val);
#ifdef ver14
				colcur = (SWORD) (lg - (colcur + 1));
				sav_lg = colcur;
#else
				colcur = lg - (colcur + lgval);
#endif
				ligcur = i;
				mf = firstcol;
				poscol();
				if (firstcol != mf) {
					editorOnShow();
					}
				ligne = (SWORD) (ligcur + LGINIT);
				/* Get_token();*/

				colcur = sav_lg;
				poscol();

				return(TRUE);

				}
			colcur += lgval;
			}
		numlgn--;
		colcur = 0;

		liginv(adrmemlin(i));

		i--;

		}

	/* purger la memoire dans le fichier retour */
	for (i = lastligne; i >= 0; i--) 
		putret(adrmemlin(i));
	
	/* on continue avec le fichier dest */

	while (getdest(adrmemlin(0))) {
		lg = (SWORD) (Xstrlen(adrmemlin(0)));
		colcur = 0;
		if (stop()) {
			liginv(val);
			return (TRUE);
			}
		liginv(adrmemlin(0));
#ifdef ver14
		while (lgnsearch(val,adrmemlin(0),1)) { /* Trouve */
#else
		while (lgnsearch(val,adrmemlin(0),lgval)) { /* Trouve */
#endif
			nb--;
			if (nb == 0) {		/* Bonne occurence */
				liginv(adrmemlin(0));
#ifdef ver14
				colcur = (SWORD) (lg - (colcur + 1));
				sav_lg = colcur;
#else
				colcur = lg - (colcur + lgval);
#endif
				completer(1); ligcur = 0;
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				liginv(val);
				/* Get_token(); */
				colcur = sav_lg;
				poscol();
				return(TRUE);
				}
			colcur += (SWORD) (Xstrlen(val));
			}
		liginv(adrmemlin(0));
		putret(adrmemlin(0)); numlgn--;		
		}

	/* Pattern non trouve */

	completer(0);	
	ligcur  = 0;
	colcur  = 0;
	ligne	= (SWORD) (ligcur + LGINIT);
	colonne = CLINIT;	
	firstcol = 0;
	editorOnShow();
	Xerreur(USUAL,absent); editor_bell();
	liginv(val);
	numlgn = 1;	/* Debut de fichier */
	return(FALSE);
	
}

static BOOL stop()	/* Stoppe les recherches */

{
	BYTE c;
	SWORD i;
	/* Test interruption clavier modulo 20 */
	if ((numlgn % 20) == 0) {
		if (x_kbhit() != 0) {
			c = (BYTE) x_getch();
			if (c == ESCAPE) {
				editor_bell();
				completer(1); ligcur = 0;
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				return (TRUE);		
				}
			}
		}
	return(FALSE);
}

static BOOL recherche (SWORD nb, BYTE XPTR val)

/*	recherche de la 'nb'ieme occurrence de la chaine 'val'
 *	a partir de la position courante
 */

{					/* recherche */
	SWORD	i;
	SWORD lg;
	SWORD mf;	/* Sauvegerde de firstcol */

	lg = (SWORD) (Xstrlen(val));

	if (lg > 1) {
		if (val[lg - 1] == LIMLIG) lg--;
		}
	if (val[0] == LIMLIG) lg--;

	if (getmemchar(ligcur,colcur) != EOSTR)  colcur++;

	/* chercher en memoire */
	for (i = ligcur; i <= (SWORD) lastligne; ) {
#ifdef ver14
		if (lgnsearch(val,adrmemlin(i),0)) {	/* trouve */
#else
		if (lgnsearch(val,adrmem(i),lg)) {	/* trouve */
#endif
			nb--;
			if (nb == 0) { /* et c'est la bonne occurrence */
				ligcur = i; 
				mf = firstcol;
				poscol();
				if (mf != firstcol)  {
					editorOnShow();
					}
				ligne = (SWORD) (ligcur + LGINIT);
				/* Get_token();*/
				return (TRUE);
				}
#ifdef ver14
			colcur++;
#else
			colcur += lg;
#endif
			}
		else 	{
			i++; numlgn++; colcur = 0;
			}
		}
	/* purger la memoire dans le fichier destination */
	for (i = 0; i <= (SWORD) lastligne; i++)
		putdest(adrmemlin(i));
	/* il faut continuer avec le fichier retour */
	while (getret(adrmemlin(0))) {
		colcur = 0;
		if (stop()) return(TRUE);
#ifdef ver14
		while (lgnsearch(val,adrmemlin(0),0)) {	/* trouve */
#else
		while (lgnsearch(val,adrmemlin(0),lg)) {	/* trouve */
#endif
			nb--;
			if (nb == 0) { /* et c'est la bonne */
				completer(1); ligcur = 0;
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				/* Get_token(); */
				return (TRUE);
				}
#ifdef ver14
			colcur ++;
#else
			colcur += lg;
#endif
			}
		putdest(adrmemlin(0)); numlgn++;
		}
	/* et continuer avec le fichier source */
	while (getsource(adrmemlin(0))) {
		colcur = 0;
		if (stop()) return(TRUE);
#ifdef ver14
 		while (lgnsearch(val,adrmemlin(0),0)) {	/* trouve */
#else
		while (lgnsearch(val,adrmemlin(0),lg)) {	/* trouve */
#endif
			nb--;
			if (nb == 0) { /* et c'est la bonne */
				completer(1); ligcur = 0;
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				/* Get_token(); */
				return (TRUE);
				}
#ifdef ver14
			colcur++;
#else
			colcur += lg;
#endif
			}
		putdest(adrmemlin(0)); numlgn++;
		}
	for (i = lastligne; i != 0; i--)
		getdest(adrmemlin(i));
	getdest(adrmemlin(0));
	numlgn--;	/* compensation */
	ligcur = lastligne; firstcol = 0;
	colcur = (SWORD) (Xstrlen(adrmemlin(lastligne)));
	if (colcur == 0)
		colonne = CLINIT;
	else 	{
		colonne = (SWORD) (Lgnlen(adrmemlin(lastligne)) + 1);
		if (getmemchar(lastligne,(colcur-1)) == TABUL 
		&&  getmemchar(lastligne,colcur) == EOSTR) colonne--;
		if (colonne > MXCOL) {	/* il faut un scrolling a droite */
			while (colonne > MXCOL) {
				firstcol += (SWORD) (MXCOL / 2);
				colonne -= (SWORD) (MXCOL / 2);
				}
			}
		}
	editorOnShow();
	ligne = (SWORD) (ligcur + LGINIT); Xerreur(USUAL,absent); editor_bell();
	return (FALSE);
}					/* recherche */

static BOOL replace (SWORD nb, BYTE XPTR val, BYTE XPTR repl)

/*	recherche de la 'nb'ieme occurrence de la chaine 'val'
 *	a partir de la position courante
 */
{					/* replace */
	SWORD   i;
	SWORD	wc,wf,lg,lg2;
	BOOL	flg_ret;

	SWORD wi;

	lg = (SWORD) (Xstrlen(val));

	if (lg > 1) {
		if (val[lg - 1] == LIMLIG) lg--;
		}

	if (val[0] == LIMLIG) lg--;

	wi = 0;	lg2 = 0;

	while ((repl[wi] != EOSTR) && (repl[wi] != LIMLIG)) {
		lg2++;
		wi++;
		}

	/* chercher en memoire */
	wf = LGLIGNE;
	if (nb == 1) wf = firstcol;	/* Sauvegarde de la 1ere colonne affichee */

	for (i = ligcur; i <= (SWORD) lastligne; ) {
#ifdef ver14
		if (lgnsearch(val,adrmemlin(i),0)) {	/* trouve */
			if (JOKER == TRUE) lg = LGFIND; 
#else
		if (lgnsearch(val,adrmemlin(i),lg)) {	/* trouve */
#endif
			ligcur = i; 
			
			flg_ret = changer(i,lg,lg2,repl); nb--;
			if ((nb == 0) || (!flg_ret)) {
				ligcur = i;
				ligne = (SWORD) (i + LGINIT);
				poscol();
				wc = colonne;
				if (wf == firstcol) {
					aff_ecran = TRUE;
					x_bstart();
					affligne(ligcur);
					aff_ecran = FALSE;
					x_bflush();
					}
				else 	{
					editorOnShow();
					ligne = (SWORD) (i + LGINIT);
					}
				colonne = wc;
				return (flg_ret);
				}
			}
		else 	{
			i++; numlgn++; colcur = 0;
			}
		}
	/* purger la memoire dans le fichier destination */
	for (i = 0; i <= (SWORD) lastligne; i++)
		putdest(adrmemlin(i));
	/* il faut continuer avec le fichier retour */
	while (getret(adrmemlin(0))) {
		colcur = 0;
#ifdef ver14
		while (lgnsearch(val,adrmemlin(0),0)) {	/* trouve */
			if (JOKER == TRUE) lg = LGFIND; 
#else
		while (lgnsearch(val,adrmemlin(0),lg)) {	/* trouve */
#endif
			flg_ret = changer(0,lg,lg2,repl); nb--;
			if ((nb == 0) || (!flg_ret)) {
				completer(1); ligcur = 0; 
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				return (flg_ret);
				}
			}
		putdest(adrmemlin(0)); numlgn++;
		}
	/* et continuer avec le fichier source */
	while (getsource(adrmemlin(0))) {
		colcur = 0;
#ifdef ver14
		while (lgnsearch(val,adrmemlin(0),0)) {	/* trouve */
			if (JOKER == TRUE) lg = LGFIND;
#else
		while (lgnsearch(val,adrmemlin(0),lg)) {	/* trouve */
#endif
			flg_ret = changer(0,lg,lg2,repl); nb--;
			if ((nb == 0) || (!flg_ret)) {
				completer(1); ligcur = 0; 
				centrer();
				poscol();
				editorOnShow();
				ligne = (SWORD) (ligcur + LGINIT);
				return (flg_ret);
				}
			}
		putdest(adrmemlin(0)); numlgn++;
		}
	for (i = lastligne; i != 0; i--)
		getdest(adrmemlin(i));
	getdest(adrmemlin(0));
	numlgn--;	/* compensation */
	ligcur = lastligne; firstcol = 0;
	colcur = (SWORD) (Xstrlen(adrmemlin(lastligne)));
	if (colcur == 0)
		colonne = CLINIT;
	else 	{
		colonne = (SWORD) (Lgnlen(adrmemlin(lastligne)) + 1);
		if (getmemchar(lastligne,(colcur-1)) == TABUL 
		&&  getmemchar(lastligne,colcur) == EOSTR) colonne --;
		if (colonne > MXCOL) {	/* il faut un scrolling a droite */
			while (colonne > MXCOL) {
				firstcol += (SWORD) (MXCOL / 2);
				colonne -= (SWORD) (MXCOL / 2);
				}
			}
		}
	editorOnShow();
	ligne = (SWORD) (ligcur + LGINIT); editor_bell();
	return (FALSE);
}					/* replace */

#ifdef ver14

static BOOL lgnsearch (BYTE XPTR val, BYTE XPTR lgn, SWORD lg)

/*	recherche de la chaine 'val', dans la ligne 'lgn', 
 *	a partir de la colonne 'colcur'
 *	'colcur' est modifie en retour.
 *	lg est le sens de la recherche 1 -> arriere  0 -> avant 
 */
{					/* lgnsearch */

	BOOL    finlig = 0;		/* BOOLEEN pour demande limite */
	
	SWORD lgval = (SWORD) Xstrlen(val);
	SWORD	lglgn = (SWORD) Xstrlen(lgn);
	SWORD 	ret;
	SWORD depart = colcur;
	/* Analyse de val */
/*
	if (val[lgval-1] == LIMLIG) {
		finlig = 1;
		lgval--;
		val[lgval] = EOSTR;
		if (lglgn - colcur > lgval) depart  = lglgn-lgval; 
		
	}
*/
	if ((val[0] == LIMLIG) && (lgval > 0)) {
		lgval--;
		val++;
		ret = (SWORD) wildcomp(&lgn[depart], val, lg);
		if (ret == 0) return(TRUE);
		else 	      return(FALSE);
	}

	ret = (SWORD) wildcomp(&lgn[depart], val, lg);

/*
	if (finlig) val[lgval] = LIMLIG;
*/		
	if (ret == -1) return(FALSE);

	colcur = (SWORD) (depart + ret);

	if (finlig) {
		if (lg) { /* sens arriere */
			if (lglgn == colcur + 1) return(TRUE);
			else return(FALSE);
		}
		else {	/* sens avant */
			lgval = LGFIND; /* lgtoken(&lgn[colcur],val); */
			if (lglgn == colcur + lgval) return(TRUE);
			else return(FALSE);
		}
	}

	return (TRUE);
}					/* lgnsearch */
#endif

/*global*/ BOOL changer (SWORD nl, SWORD lg, SWORD nb, BYTE XPTR repl)

/*	changer / remplacer les 'lg' caracteres qui suivent a partir
 *	de 'colcur' par le contenu de 'repl', qui fait 'nb' caracteres
 *	dans la ligne de numero 'nl'.
 */
{					/* changer */
	SWORD	i = colcur,j;
	SWORD k,c;
	SWORD saunb;
	BYTE sauvcar;

/*	et Calcul reel de repl */

	saunb  = nb;

	/* test si l'insertion est possible */
	poscol();
	j = Lgnlen((adrmemlin(nl)) + colcur + lg);
	k = Lgnlen(repl);
	if (firstcol + (colonne - 1) + k + j > LGLIGNE) {
		editor_bell();
		return(FALSE);
	}

	if (nb <= lg) {		/* on remplace par plus petit */
		j = (SWORD) (colcur + lg);
		while (nb != 0) {
#ifdef ver14
			if ((JOKER==FALSE) || (*repl != '?')) 
				putmemchar(nl,i,*repl);

			repl++; nb--; i++;			
#else
			putmemchar(nl,i,*repl);
			repl++; nb--; i++;
#endif
		}
		if (nb != lg) {
			k = (SWORD) (Xstrlen(adrmemlin(nl)));
			while (j <= k) {
				putmemchar(nl,i,(getmemchar(nl,j)));
				i++; j++;
			}
			i = (SWORD) (colcur + saunb);
		}
	}
	else {		/* on remplace par plus grand */
		k = (SWORD) (Xstrlen(adrmemlin(nl)));
		nb -= (SWORD) lg; j = (SWORD) (k + nb);
		if (j >= LGLIGNE)
			j = LGLIGNE - 1;
		while (lg != 0) {
#ifdef ver14
			if ((JOKER==FALSE) || (*repl != '?')) 
				putmemchar(nl,i,*repl);

			repl++; lg--; i++;			
#else
			putmemchar(nl,i,*repl);
			repl++; lg--; i++;
#endif
		}
		while ((k >= i) && (k >= 0)) {
			putmemchar(nl,j,(getmemchar(nl,k)));
			j--; k--;
		}
		while ((nb != 0) && (i <= j)) {
#ifdef ver14
			if ((JOKER==FALSE) || (*repl != '?')) 
				putmemchar(nl,i,*repl);

			repl++; nb--; i++;			
#else
			putmemchar(nl,i,*repl);
			repl++; nb--; i++;
#endif
		}
		if (i == j) {
			editor_bell(); return (FALSE);
		}
	}

	while (*repl != EOSTR) {
		if (*repl == LIMLIG) {
			increment_line_counter();
			k = (SWORD) Xstrlen(adrmemlin(nl));
			/* Insertion de la fin de ligne */

			sauvcar = getmemchar(nl,i);

			putmemchar(nl,i,EOSTR);

			putdest(adrmemlin(0)); /* purge adrmemlin(0) */

			for (j = 0; j < (SWORD) nl; ) {
				Xstrcpy(adrmemlin(j), adrmemlin((j+1)));
				j++;
			}
			numlgn++;

			putmemchar(nl,0,EOSTR); /* Nouvelle ligne vide */
			j = i;

			i = 0;

			if (j != k) {
				putmemchar(nl,i,sauvcar);
				i++; j++;
				for ( ; j <= k;) {
				   putmemchar(nl,i,(getmemchar(nl,j)));
				   j++; i++;
				}
				i = 0;
			}
		}
		else {
#ifdef ver14
			if ((JOKER == FALSE) || (*repl != '?')) {
				/* Insertion des caracteres */
				j = (SWORD) Xstrlen(adrmemlin(nl)) ;

				if (j+1  != LGLIGNE){  /* Si ligne plein ? */
					putmemchar(nl,(j+1),(getmemchar(nl,j)));
					while (j != i) {
						putmemchar(nl,j, (getmemchar(nl,(j-1))));
						j--;
					}
				}
				putmemchar(nl,i,*repl);
			}						
			i++;
#else
			/* Insertion des caracteres */
			j = Xstrlen(adrmemlin(nl)) ;

			if (j+1  != LGLIGNE){  /* Si ligne plein ? */
				putmemchar(nl,(j+1),(getmemchar(nl,j)));
				while (j != i) {
					putmemchar(nl,j,(getmemchar(nl,(j-1))));
					j--;
				}
			}
			putmemchar(nl,i,*repl);
			i++;
#endif
		}

		repl++;

	}

	colcur = i;
#ifdef ver14
	txtchg = TRUE; /* le source a ete modifie */
#endif
	return (TRUE);
}					/* changer */

/* global */ VOID completer (SWORD j)

/*	completer l'etat courant en memoire, a partir de la ligne 'j'
 *	par lecture du fichier retour et du source si necessaire.
 *	la valeur de 'lastligne' est modifiee au retour.
 */
{						/* completer */
	/* completer avec le contenu du fichier retour */
	while (j < NBLIG) {
		if (!getret(adrmemlin(j)))
			break;
		j++;
	}
	/* completer avec le contenu du fichier source */
	while (j < NBLIG) {
		if (!getsource(adrmemlin(j)))
			break;
		j++;
	}
	if (j != 0)
		lastligne = (SWORD) (j - 1);
	else
		lastligne = 0;
}						/* completer */

/*global*/ BOOL poscol ()

/*	la variable colonne est modifiee en vue de refaire  l'affichage de
 *	l'ecran pour cadrer avec la colonne 'colcur' de la ligne 'ligcur'.
 *	retourne 'TRUE' si un rafraichissement de l'ecran est necessaire.
 */
{						/* poscol */
	SWORD	i;
	BOOL	refresh = FALSE;

	colonne = 1;
  	firstcol = 0;  	/* Par defaut -> debut de ligne */
	if (colcur != 0){
		/* Test le premier caractere de la ligne */
	   if (getmemchar(ligcur,0) != TABUL) {
		colonne++;
	   	}
	   else {
		NextTab( colonne, 0);
	   	}

	   for (i = 1; i < colcur; i++) {
		if (getmemchar(ligcur,i) != TABUL) {
			colonne++;
			}
		else 	{
			NextTab(colonne, 0);
			}
	   	}
/*	   if (getmemchar(ligcur,(i-1)) == TABUL) colonne --;*/
		}
	if ((colonne - firstcol) > MXCOL) { /* il faut un scrolling a droite */
		firstcol = 0;
		while (colonne > MXCOL) {
			firstcol += (SWORD) (MXCOL / 2); colonne -= (SWORD) (MXCOL / 2);
			}
		refresh = TRUE;
		}
	else 	{
		if (colonne < firstcol) { /* il faut un scrolling a gauche */
			while (colonne < firstcol)
				firstcol -= (SWORD) (MXCOL / 2);
			refresh = TRUE;
			}
		colonne -= firstcol;
		}
	return (refresh);
}						/* poscol */

/*	Gestion du mode TRACE		*/
/*	---------------------		*/

VOID poserrsuiv()

/*	positionnement a l'erreur suivante
 */
{						/* poserrsuiv */
	SWORD	nb;
	LONG	nl = 0;

#ifndef ver21
	SWORD pt;
	BYTE Ligne[256];
	BYTE XPTR tmp;
	BYTE c;
#endif

#ifdef ver21
	TRACEPTR pt_err;
#endif

#ifdef ver14
	if (trace_err == TRUE) return;
#endif
	
	/* enlever l'affichage de l'ereur courante */
	pos(3,1); Xatb(21);
#ifndef ver21
/* commence de fgets */
	Xfgets(&Ligne[0], 256,ftrace);
	if (Ligne[0] == EOSTR) {
		pos(3,1); Xatb(2);
		x_cprintf(edit_msg[ernoy06]); Xatb(0);
		pos(ligne,colonne);
		return;
	}
/* binaire offset dans la ligne  a 0 */
	pt = 0;
	tmp = nomerr;
	while ((c = Ligne[pt++]) != ' ') {
		(*tmp++) = c;
	}
	*tmp = EOSTR;
	XscanfForLong(&Ligne[0], &pt, &nl);
	Xscanf(&Ligne[0], &pt, &clerr);
/*
	nb = Xscanf(ftrace,"%s %d %d ",nomerr,&nl,&clerr);
	if (nb != 3) {
		Xerreur(FATALE,ernoy05);
	}
	XXfgets(curerr,LGLIGNE,ftrace);
*/
	Xstrcpy(curerr, &Ligne[pt]);
#else

	pt_err = position_to_next( ANYTYPE );
	if (pt_err == (TRACEPTR) 0) {
		pt_err = position_to_current();
		pos(3,1); Xatb(2);
		x_cprintf((BYTE FPTR) edit_msg[ernoy06]); Xatb(0);
		pos(ligne,colonne);
	
		return;
	}
	Mstrcpy((BYTE FPTR ) nomerr, (BYTE FPTR) pt_err->filename);
	Mstrcpy((BYTE FPTR ) curerr, (BYTE FPTR) pt_err->message);
	nl = pt_err->ligne;
	clerr = pt_err->colonne;

#endif

	/* voir si il faut changer de fichier source */
	if (!striEq(nomsrce,nomerr)) {
		reinit();		/* oui : reinitialisation */
	}
	/* afficher la nouvelle erreur */
	pos(3,1); Xatb(APU); x_putch(' '); x_cprintf((BYTE FPTR) curerr);
	Xatb(0);
	/* afficher la ligne correspondante */
	nl += err_ecart;
	if (nl != plerr) {	/* changer de ligne */
		plerr = nl; poslgn(0,(LONG) plerr);
	}
	colcur = (SWORD) clerr;
	/* positionner sur le caractere correspondant */
	if (poscol()) {
		editorOnShow();
		}
	pos(ligne,colonne);
	/* Get_token(); */
}						/* poserrsuiv */

#ifdef ver21
VOID poserrback()

/*	positionnement a l'erreur precedente
 */
{						/* poserrsuiv */
	SWORD	nb;
	LONG	nl = 0;

	TRACEPTR pt_err;

	if (trace_err == TRUE) return;

	
	/* enlever l'affichage de l'ereur courante */
	pos(3,1); Xatb(21);

	pt_err = position_to_previous( ANYTYPE );
	if (pt_err == (TRACEPTR) 0) {
		pt_err = position_to_current();
		pos(3,1); Xatb(2);
		x_cprintf((BYTE FPTR) edit_msg[ernoy06]); Xatb(0);
		pos(ligne,colonne);
	
		return;
	}
	Mstrcpy((BYTE FPTR) nomerr, (BYTE FPTR) pt_err->filename);
	Mstrcpy((BYTE FPTR) curerr, (BYTE FPTR) pt_err->message);
	nl = pt_err->ligne;
	clerr = pt_err->colonne;

	/* voir si il faut changer de fichier source */
	if (!striEq(nomsrce,nomerr))
		reinit();		/* oui : reinitialisation */
	/* afficher la nouvelle erreur */
	pos(3,1); Xatb(APU); x_putch(' '); x_cprintf((BYTE FPTR) curerr);
	Xatb(0);
	/* afficher la ligne correspondante */
	nl += err_ecart;
	if (nl != plerr) {	/* changer de ligne */
		plerr = nl; poslgn(0,(LONG) plerr);
		}
	colcur = (SWORD) clerr;
	/* positionner sur le caractere correspondant */
	if (poscol()) {
		editorOnShow();
		}
	pos(ligne,colonne);
	/* Get_token();*/
}						/* poserrsuiv */
#endif

#ifdef	VERSION666
static	void	xcopy( char * sn, char * rn )
{
	struct	stat buf;
	FILE *	sh;
	FILE *	rh;
	int	c;
	if ((sh = fopen(sn,"rb")) != (FILE *) 0) {
		stat( sn, &buf );
		if ((rh = fopen(rn,"wb")) != (FILE *) 0) {
			while ((c = fgetc(sh)) != -1) {
				if (!( c ))
					break;
				else if ( c == 0x001A )
					break;
				else 	fputc(c,rh);
				}
			fclose(rh);
			/* set new file permissions as of old */
			chmod(rn,buf.st_mode );
			}
		fclose(sh);
		}
	Xunlink(sn);
	return;
}
#endif

BOOL	confirme_lose()	{  return( confirme(1,55,edit_msg[msgconf] ) );	}
BOOL	confirme_save()	{  return( confirme(12,10,edit_msg[msgsave]) );	}

static VOID reinit()

/*	reinitialisation de l'editeur lors du passage a
 *	un autre fichier source en mode TRACE
 */
{					/* reinit */
	ChnFic	XPTR p, XPTR q;
	BYTE	nomfic[LGMXNOM];
	BOOL    ret=FALSE;


#ifdef ver14
	if (txtchg) {
#endif
	 	pos(LGINIT,CLINIT); atb(22);
		pos(10,10); Xatb(0); x_cprintf(edit_msg[chgtfic]); on_cursor();
		ret = confirme_save();
#ifdef ver14
		}
#endif
	if (ret == TRUE) {
		purgedest();
		Xclose(fs->nl); Xclose(fret->nl); Xclose(fdest->nl);
#ifdef unix
		liberlox(nomret);
		liberlox(nomdest);
		liberlox(nomsrce);
#endif
		Xunlink(nomret);
		xrename(nomsrce,nombak); 
#ifdef	VERSION666
		xcopy(nomdest,nomsrce);
#else
		xrename(nomdest,nomsrce);
#endif
		
#ifdef ver21
		commit_trace_adjustment();
#endif		
		}
	else 	{
		/* abandon des modifications */
		if (!flgcreat)
			Xclose(fs->nl);
		Xclose(fret->nl); 
		Xclose(fdest->nl);
#ifdef unix
		liberlox(nomret);
		liberlox(nomdest);
		liberlox(nomsrce);
#endif
		Xunlink(nomret);
		Xunlink(nomdest);
#ifdef ver21
		if (txtchg) forget_trace_adjustment();
#endif
		}

 	pos(LGINIT,CLINIT); atb(22); off_cursor();
	/* reprendre la designation du fichier courant pour garder l'ecart */
	designation(nomfic);
	Xstrcpy(nomsrce,nomerr);	/* nouveau fichier source */
	libtampon();
	init_fic(FALSE,FALSE);	/* reinit des fichiers */
	designation(nomfic);
	show_filename(nomfic);
	window_messages();
	Xatb(0);
	/* voir si fichier deja traite auparavant : reprendre l'ecart */
	q = p = deb_chnfic;
	err_ecart = 0;

#ifndef ver21
	if (p != GenericNULL(ChnFic)) {
		do 	{
			if (striEq(p->nom,nomsrce)) {
				err_ecart = p->ecart;
				if (q == deb_chnfic)
					deb_chnfic = p->suiv;
				else	q->suiv = p->suiv;
				liberate(p);
				break;
				}
			q = p; p = p->suiv;
			}
		while (p != GenericNULL(ChnFic));
		}
#endif
	ligne = LGINIT;
	initmem();
	editorOnShow();
	return;
}

#ifdef ver14
/*global*/ VOID Memento(BYTE com)
{
	if (com == EOSTR) {
		go_help();
	}
	else if (com == '?') {
		maj_taille(0,0);
		flg_help = FALSE;
	}
}

VOID go_help()
{
	SWORD i;
	BYTE c;

	if (!flg_help) {
		nbl = MXLIG;
		maj_taille((SWORD) (MXLIG - 7),(SWORD) (MXCOL+1));
		x_bstart();
		horizontal_rule( (nbl-6),CLINIT,MXCOL);
		x_bflush();
		aff_help();
		flg_help = TRUE;
		}

	pos((SWORD) (nbl-5+(h_indice - h_page)), CLINIT);
	c = (BYTE) x_getch();
	while (c != ESCAPE && c != CR) {
		if (c == CURH) {
			if (h_indice == 0) 
				editor_bell();
			else 	h_indice --;	

			if (h_indice < h_page) { /* scrolling haut */
				h_page --;
				aff_help();
			}
		}
		else if (c == CURB) {
			if (h_indice == MCTRL)
				editor_bell();
			else	h_indice ++;

			if (h_indice > h_page + 5) { /* scroling bas */
				h_page ++;
				aff_help();
			}
		}
		else if (c == PGUP) {
			if (h_page == 0) editor_bell();
			else if (h_page  < 6)	h_page = 0;
			     else 		h_page -= 6;

			h_indice = h_page;
			aff_help();
		}
		else if (c == PGDN) {
			if (h_page == MCTRL) editor_bell();
			else if (h_page  > MCTRL - 6)	h_page = MCTRL - 6;
			     else 			h_page += 6;

			h_indice = h_page;
			aff_help();
		}
		else editor_bell();

		pos((SWORD) (nbl-5+(h_indice - h_page)), CLINIT);

		c = (BYTE) x_getch();
	}
}
VOID aff_help()
{
	BYTE i;
	x_bstart();
	for (i=0; i < 6; i++) {
		pos((SWORD) (nbl-5+i), CLINIT); atb(21);
		if (h_page + i < MCTRL) x_cprintf(edit_ctrl[h_page + i]);
		}
	x_bflush();
}
#ifdef bug12
static SWORD wildcomp( BYTE XPTR tptr , BYTE XPTR wptr, SWORD sens)


	/* 1 sens arriere  0 sens avant */
{
	SWORD first,i;
	BYTE XPTR s_first;

	BYTE 	XPTR sauvpt;
	BYTE 	c1,c2;
	BOOL 	jok;
	SWORD	ret;

	SWORD etoile_buf;
	SWORD etoile_exp;
	SWORD etoile_lg;

	SWORD savebuf;

	sauvpt 	= wptr;
	savebuf = (SWORD) (tptr);

	jok = FALSE;
	i = 0;

	first = MOINS_UN;

	/*  i est l'equivalent de colcur */

	while (1) {
		if (*wptr == EOSTR) {	
			LGFIND = (SWORD) (tptr - first);
			return((SWORD) (first - savebuf));
		}
		if (*tptr == EOSTR) {
			if (*wptr == (BYTE) LIMLIG)	{
				LGFIND = (SWORD) (tptr - first);
				return((SWORD) (first - savebuf));
			}
			else	return((SWORD) (MOINS_UN));
		}		
		if ((*wptr == '*') && (JOKER == TRUE)) {
			if (* (wptr + 1) != '*') {
				wptr ++;
				jok = TRUE;
				etoile_buf = (SWORD) (tptr);
				etoile_exp = (SWORD) (wptr);
			}
			else {
				wptr ++;
			}
		}
		else if (((BYTE) *wptr == (BYTE) '?') && (JOKER == TRUE)) {
			wptr++;
			tptr++;
			i++;
			if ((sens) && (first != MOINS_UN)) first ++;
		}
		else {
			if (MAJMIN) {
				c1 = (BYTE) toupper((BYTE) *tptr); c2 = (BYTE) toupper((BYTE) *wptr);
			}
			else {
				c1 = *tptr; c2 = *wptr;	
			}
			if (c1 == c2) {
				if (first == MOINS_UN) {
					first = (SWORD) (tptr);
					s_first = tptr;
				}
				else if (sens) first++;

				wptr++;
				tptr++;
				i++;			
			}
			else {
				if (jok == FALSE) {
					if (first != -1) {
						tptr = s_first;
						first = MOINS_UN; /* fausse route */
						wptr = sauvpt;	/* on repart a zero */

						/* 	on reste sur le caractere
							errone en anticipant
							l'incrementation
						 */
					}
				}
				else {
					/* c1 != c2 and first != 0 */
					etoile_buf ++;
					tptr = (BYTE XPTR) (etoile_buf - 1);
					wptr = (BYTE XPTR) (etoile_exp);
					if (sens) first++;
				}
				tptr++;	/* C'est ici l'incrementation anticipe
					   plus haut */
				i++;
			}
		}
	}
}
#else
#if unix
#define UBINAIRE long int
#else
#define UBINAIRE int
#endif
static SWORD	wildcomp( tptr , wptr, sens)
BYTE    XPTR tptr;
BYTE 	XPTR wptr;
SWORD	sens;	/* 1 sens arriere  0 sens avant */
{
	UBINAIRE first,i;
	BYTE XPTR s_first;

	BYTE 	XPTR sauvpt;
	BYTE 	c1,c2;
	BOOL 	jok;

	UBINAIRE etoile_buf;
	UBINAIRE etoile_exp;

	UBINAIRE savebuf;

	sauvpt 	= wptr;
	savebuf = (UBINAIRE) (tptr);

	jok = FALSE;
	i = 0;

	first = -1;

	/*  i est l'equivalent de colcur */

	while (1) {
		if (*wptr == EOSTR) {	
			LGFIND = (UBINAIRE) (tptr - first);
			return((SWORD) (first - savebuf));
		}
		if (*tptr == EOSTR) {
			if (*wptr == LIMLIG)	{
				LGFIND = (UBINAIRE) (tptr - first);
				return((SWORD) (first - savebuf));
			}
			else	return(-1);
		}		
		if ((*wptr == '*') && (JOKER == TRUE)) {
			if (* (wptr + 1) != '*') {
				wptr ++;
				jok = TRUE;
				etoile_buf = (UBINAIRE) (tptr);
				etoile_exp = (UBINAIRE) (wptr);
			}
			else {
				wptr ++;
			}
		}
		else if ((*wptr == '?') && (JOKER == TRUE)) { 
			wptr++;
			tptr++;
			i++;
			if ((sens) && (first != -1)) first ++;
		}
		else {
			if (MAJMIN) {
				c1 = toupper(*tptr); c2 = toupper(*wptr);
			}
			else {
				c1 = *tptr; c2 = *wptr;	
			}
			if (c1 == c2) {
				if (first == -1) {
					first = (UBINAIRE) (tptr);
					s_first = tptr;
				}
				else if (sens) first++;

				wptr++;
				tptr++;
				i++;			
			}
			else {
				if (jok == FALSE) {
					if (first != -1) {
						tptr = s_first;
						first = -1; /* fausse route */
						wptr = sauvpt;	/* on repart a zero */

						/* 	on reste sur le caractere
							errone en anticipant
							l'incrementation
						 */
					}
				}
				else {
					/* c1 != c2 and first != 0 */
					etoile_buf ++;
					tptr = (BYTE XPTR) (etoile_buf - 1);
					wptr = (BYTE XPTR) (etoile_exp);
					if (sens) first++;
				}
				tptr++;	/* C'est ici l'incrementation anticipe
					   plus haut */
				i++;
			}
		}
	}
}

#endif


static VOID aff_file(BYTE XPTR pt)
{
	BYTE tmp[LGMXNOM];


	pos(8,20); x_cprintf((BYTE FPTR) edit_msg[msgpath]);
	x_cprintf((BYTE FPTR) n_path);
	pos(10,20); x_cprintf((BYTE FPTR) edit_msg[msgfich]);


/*	Xfn_parser((BYTE FPTR) pt,(BYTE FPTR) tmp, 1+2+4+8+16); */

	diff_repfich(n_path, pt, tmp);
	x_cprintf((BYTE FPTR) tmp);

	pos(13,20); x_cprintf((BYTE FPTR) edit_msg[msgwait]);
	x_getch();
}

static VOID aff_histo()
{
	Liste XPTR tmp;
	SWORD i;

	pos(3,1); atb(22);
	tmp = chis.lnext;
	for (i = 0; i < chis.lg_liste; i ++) {
		if (chis.adr_fic == tmp) {
			pos((SWORD) (3+i), 10);
			x_cprintf((BYTE FPTR) "->");
		}
		pos((SWORD) (3+i), 15);
		XX_cprintf(tmp->ptfic->nom);
		tmp = tmp->next;
	}
	
	pos(24,20); x_cprintf(edit_msg[msgwait]);
	x_getch();
	pos(3,1); atb(22);
}
static VOID init_his()
{
	BYTE tmp[LGMXNOM];

	chis.adr_fic = chis.lnext = chis.lback = GenericNULL(Liste);
	chis.lg_liste = 0;	

	/* Constuire la liste */
#ifdef prologue
	GetReper(tmp,LGMXNOM); /* Implicite fichier */
#else
	getcwd(tmp, LGMXNOM);
#endif
	MakeReper(tmp,n_path);
}

static VOID purge()
{
	SWORD i;
	Liste XPTR tmp;
	StrGen XPTR pt;

	pt = &chis;

	for (i=0; i < pt->lg_liste; i++) {
		tmp = pt->lnext;
		Free_Cat(tmp->ptfic);
		pt->lnext = tmp->next;
		Free_Lis(tmp);		
	}

	pt->lg_liste = 0;
	pt->lnext    = GenericNULL(Liste);	/* pointe sur le prochain */
	pt->lback    = GenericNULL(Liste);   /* pointe sur le dernier */
	pt->adr_fic  = GenericNULL(Liste);		/* Sauvegarde de l'adresse du dernier cfic */
}

static VOID maj_histo(BYTE XPTR sl)
{
	BOOL trouve;
	Liste *p,*tmp;
	FileCat *pt;

	SWORD nb;

	nb=1;
	tmp = chis.lnext ;  /* by pass le premier bidon */
	trouve = FALSE;

	if (*sl == EOSTR || *(sl+1) == EOSTR) {
		/* on n'accepte pas les commandes de 1 caractere */

		return;
	}


	while (nb <= chis.lg_liste) {
		if (Xstrcmp(tmp->ptfic->nom,sl) == 0) {
			trouve = TRUE;
			break;
		}
		tmp = tmp->next;
		nb++;
	}
	
	/* Decalage des presents pour le nouveau en deuxieme position */

	if (trouve == FALSE) { /* Insertion en tete du nouveau */
		/* Premier cfic de la selection */
		pt = All_Cat();
		if (pt == GenericNULL(FileCat)) return; /* plus de place */
	
		Xstrcpy(pt->nom,sl);
		pt->etat = 0;	

		p = All_Lis();
		if (p == GenericNULL(Liste)) {
			Free_Cat(pt);
			return;
		}
		if (chis.lnext == GenericNULL(Liste)) {
			chis.lnext = p;
			chis.lback = p;
		}

		p->ptfic = pt;

		chis.lg_liste++;
	}
	else {
		if (chis.lnext == tmp) return; /* C'est le premier */

		p = tmp;
		if (nb == chis.lg_liste) {
			chis.lback = p->back;
		}

		/* on supprime ses liens */
		p->back->next = p->next;
		p->next->back = p->back;
	}
	
	/* Sinon p pointe sur l'element courant */

	/* Decaler les noms histo pour l'insertion en 2 position */

	if (chis.lg_liste > LMAXHIS) { /* Supprimer le dernier */
		tmp = tmp->back;
		Free_Cat(tmp->ptfic);

		tmp->back->next = tmp->next;
		tmp->next->back = tmp->back;

		chis.lback = tmp->back; /* pointeur sur la fin de liste */

		chis.lg_liste--;
		Free_Lis(tmp);		
	}

	/* insertion en premiere position */
	p->back = chis.lback;
	p->next = chis.lnext;
	p->next->back = p;

	chis.lnext = p;	/* pointe sur le premier */
	chis.lback->next = chis.lnext; /* le dernier pointe sur le premier */
	chis.adr_fic = chis.lnext;
}

static VOID NextCom(BYTE XPTR pt)
{
	if (chis.adr_fic == GenericNULL(Liste)) return;
	chis.adr_fic = chis.adr_fic->next;
	Xstrcpy(pt, chis.adr_fic->ptfic->nom);
}

static VOID BackCom(BYTE XPTR pt)
{
	if (chis.adr_fic == GenericNULL(Liste)) return;
	chis.adr_fic = chis.adr_fic->back;
	Xstrcpy(pt, chis.adr_fic->ptfic->nom);
}

static VOID makenom(BYTE XPTR pt, BYTE  inc)
{
	BYTE buf[4];	/* conversion du num. poste en chaine */
	SWORD numposte;
#ifdef msdos
#ifndef BORLAND

	get_time(&_time);
	get_date(&_date);

	b32.hh = (BYTE) (_time.hour & 0x001f);
	b32.ss = (BYTE) ((_time.second >> 1) & 0x001f);
	b32.mm = (BYTE) (_time.minute & 0x001f);
	b32.MM = (BYTE) ((_date.month << 1) & 0x001f | (_time.minute >> 5) & 1);
	
	b32.DD = (BYTE) _date.day;
	b32.AA = (BYTE) ((_date.year - 1970) & 0x001f);

#else 	/* BORLAND */
	get_date(&_date);
	get_time(&_time);

	b32.hh = (BYTE) _time.ti_hour & 0x001f;
	b32.ss = (BYTE) (_time.ti_sec >> 1) & 0x001f;
	b32.mm = (BYTE) _time.ti_min & 0x001f;
	b32.MM = (BYTE) (_date.da_mon << 1) & 0x001f | (_time.ti_min >> 5) & 1;
	
	b32.DD = (BYTE) _date.da_day;
	b32.AA = (BYTE) (_date.da_year - 1980) & 0x001f;

#endif
#else
	/* prologue */
	time(&gettime);
	pt_time = localtime(&gettime);

	b32.hh = (BYTE) pt_time->tm_hour & 0x001f;
	b32.ss = (BYTE) (pt_time->tm_sec >> 1) & 0x001f;
	b32.mm = (BYTE) pt_time->tm_min & 0x001f;
	b32.MM = (BYTE) (pt_time->tm_mon << 1) & 0x001f | (pt_time->tm_min >> 5) & 1;
	
	b32.DD = (BYTE) pt_time->tm_mday;
	b32.AA = (BYTE) (pt_time->tm_year - 1970) & 0x001f;
#endif


	/* on garde la premiere lettre du nom du fichier source */
	pt[1] = conv_base (b32.AA);
	pt[2] = conv_base (b32.DD);
	pt[3] = conv_base (b32.MM);
	pt[4] = conv_base (b32.mm);
	pt[5] = conv_base (b32.ss);
	pt[6] = conv_base (b32.hh);
	pt[7] = conv_base (inc);
	pt[8] = SEPTYP;	/* separateur */
	pt[9] = EOSTR;

#ifdef msdos
/*	numposte = x_npos(); */
	numposte = 1;
	pt = (BYTE XPTR) (itoa((int) numposte, (char *) buf, 10));
	Xstrcat(pt, buf);
#endif
}

static BYTE conv_base ( BYTE c)
{
	if (c < 10)
		return((BYTE) ('0' + c));
	else	return((BYTE) ('A' + c - 10));
}
#endif

VOID 	Xatb(SWORD c)
{
#ifdef ver14
	if ( c == 0 ) {
		if ( conf(14) ) {
			if ( consoletype() ) {
				cicocolours(
					_DEFAULT_GUI_BLACK,
					_DEFAULT_GUI_WHITE,
					_DEFAULT_GUI_WHITE
					);
				}
			else	{
				atb(0);
				}
			}
		else 	{
			atb(0);
			}
		}
	else if ( c == 1 ) {
		if ( conf(14) ) {
			if ( consoletype() ) {
				cicocolours(
					_DEFAULT_GUI_BLACK,
					_DEFAULT_GUI_WHITE,
					_DEFAULT_GUI_WHITE
					);
				}
			else	{
				atb(1);
				}
			}
		else 	{
			atb(1);
			}
		}
	else if ( c == 100 ) {
		if (conf(14)) {
			if ( consoletype() ) {
				cicocolour(
					_DEFAULT_GUI_WHITE,
					_DEFAULT_GUI_BLACK
					);
				}
			else	{
				atb(2);
				}
			}
		else 	{
			atb(2);
			}
		}
	else if (c == 102) {
#ifndef BORLAND
		if (conf(14) == 1) { 
			if ( consoletype() ) {
				cicocolour(_DEFAULT_GUI_LIGHT_HIGH, _DEFAULT_GUI_GREYED );
				}
			else	{
				backgr(1); foregr(15);
				}
			}
		else	{
			atb(1);
			}
#else
		if ( consoletype() ) {
			cicocolour(_DEFAULT_GUI_LIGHT_HIGH ,_DEFAULT_GUI_GREYED );
			}
		else	{
			backgr(1); foregr(15);
			}
#endif
		}
#endif
	else	{	
		atb(c);  	
		}
	return;
}

/*global*/ VOID XX_cprintf(BYTE XPTR p)
{
	while(*p) {
		if (*p != ESCAPE) {
			if (ctrlbyte(*p)) {
				Xatb(2);
				putch((BYTE) (0x0040+*p));
				Xatb(0);
				}	
			else 	putch(*p);
			}
		else 	{ 
			Xatb(2); putch('&'); Xatb(0); 
			}
		p++;
	}
}
#ifdef ver14
VOID outlong(SWORD ln, SWORD cl, LONG val)

/*	edition d'une valeur numerique (longue) en cours de traduction
 */
{				/* outlong */
	BYTE 	XPTR p, XPTR q;
	BYTE    c;
	BYTE    valeur[8],valcad[8];
	ULONG   n;

	p = q = &valeur[0]; n = (ULONG) val;
	do {
		*p++ = inttocar(n % 10L);
	}
	while ((n /= 10L) != 0L);
	*p = EOSTR;
	while (q < --p) {
		c = *q; *q++ = *p; *p = c;
	}
	Xstrcpy(&valcad[0],"       ");
	Xstrcpy(&valcad[7-Xstrlen(&valeur[0])],&valeur[0]);
	pos(ln,cl);
	x_cprintf(&valcad[0]);
}				/* outlong */

static VOID outbin(SWORD ln, SWORD cl, SWORD val)

/*	edition d'une valeur numerique en cours de traduction
 */
{				/* outbin */
	BYTE XPTR p, XPTR q,c,valeur[6],valcad[6];
	SWORD   n;

	p = q = &valeur[0]; n = (SWORD) val;
	do {
		*p++ = inttocar(n % 10);
	}
	while ((n /= 10) != 0);
	*p = EOSTR;
	while (q < --p) {
		c = *q; *q++ = *p; *p = c;
	}
	Xstrcpy(&valcad[0],"     ");
	Xstrcpy(&valcad[5-Xstrlen(&valeur[0])],&valeur[0]);
	pos(ln,cl);
	x_cprintf((BYTE FPTR) &valcad[0]);
}				/* outbin */

VOID maj_taille(SWORD nl, SWORD nc)
{
	SWORD  i;

	if (nl== 0 && nc == 0) {
		/* retour au format standard */
		MXLIG = conf(1);
		MXCOL = (SWORD) (conf(2) - 1);
		NBLIG = (SWORD) ((MXLIG+1) - LGINIT);

		i = conf(11);
		flg_InsLgn = flg_DelLgn = TRUE;
		if ((i & 0x04) == 0) flg_InsLgn = FALSE;
		if ((i & 0x08) == 0) flg_DelLgn = FALSE;

	}
	else {
		MXLIG = nl;
		MXCOL = (SWORD) (nc-1);
		NBLIG = (SWORD) ((MXLIG+1) - LGINIT);
		
		flg_InsLgn = flg_DelLgn = FALSE;

	}					

	for (i=0; i < ligcur; i++) {
		putdest(adrmemlin(i));
	}

	for (i=lastligne; i > ligcur; i--) {
		putret(adrmemlin(i));
	}

	Xstrcpy(adrmemlin(0), adrmemlin(ligcur));
	completer(1);
	ligcur = 0; 
	centrer();
	poscol();
	editorOnShow();
	ligne = (SWORD) (LGINIT + ligcur);
	pos(ligne,colonne);
}

static BOOL lecconf(BYTE XPTR nomcfg)

/*	lecture du fichier de configuration designe par 'nomcfg'
 */
{					/* lecconf */
	FILE	*fc;
	SWORD	i;
	BYTE    buf[256];
	BYTE 	tmp[256];
	BYTE	XPTR	p;
	SWORD	val;
	SWORD pt;

	/* Ouverture du fichier de configuration */
	if (*nomcfg != EOSTR) {
		fc = Xfopen(nomcfg,"r");
	}
	else  {

		fc = Xfopen("abal.cfg","r"); /* nom par defaut */		
	}

	if (fc == GenericNULL(FILE))
		return (FALSE);

	/* Controle la signature du fichier */
	Xfgets(&buf[0],LGREP,fc);

	if (Xstrcmp(verscfg,&buf[0]) != 0) {
		Xfclose(fc);
		return (FALSE);
	}

	/* Lecture des repertoires par defaut */
	Xfgets(&buf[0],LGREP,fc);
	Xfgets(&buf[0],LGREP,fc);
	Xfgets(&buf[0],LGREP,fc);
	Xfgets(&buf[0],LGREP,fc);
	Xfgets(&buf[0],LGREP,fc);

	/* Lecture de la designation du fichier courant */
	Xfgets(&nomsrce[0],LGREP,fc);

	/* Lecture de la designation du projet courant */
	Xfgets(&buf[0],LGREP,fc);

	/* Lecture de l'option d'aide */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	Xscanf(&buf[0],&pt,&val);

	/* Lecture du type d'ecran pour la commande systeme */
	Xscanf(&buf[0],&pt,&val);

	/* Lecture des extensions des fichiers */
	Xfgets(&EXTS[0], LGEXT,  fc);
	Xfgets(&buf[0], LGEXT,  fc);
	Xfgets(&EXTE[0], LGEXT, fc);
	Xfgets(&EXTSAV[0], LGEXT, fc);
	Xfgets(&buf[0], LGEXT, fc);

	if (EXTS[0] == '0') {
		EXTS[0] = EOSTR;
	}
	if (EXTE[0] == '0') {
		EXTE[0] = EOSTR;
	}
	if (EXTSAV[0] == '0') {
		EXTSAV[0] = EOSTR;
	}

	/* Lecture des options de l'editeur de textes */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	for (i=0; i<4; i++) {
		Xscanf(&buf[0],&pt,&val);
	}

	/* Lecture des valeurs par defaut des commandes d'edition */
	for (i = 0; i < 18; i++) {
		Xscanf(&buf[0],&pt,&val);
		vcomed[i] = (BYTE) val;
	}
	PHOME	= vcomed[0];
	PDEBFIN	= vcomed[1];
	PGDN	= vcomed[2];
	PGUP	= vcomed[3];
	CENTER	= vcomed[4];
	NEXTWORD = vcomed[5];
	PREVWORD = vcomed[6];
	ILINE	= vcomed[7];
	DLINE	= vcomed[8];
	DELCAR	= vcomed[9];
	DELBACK = vcomed[10];
	DEOLN	= vcomed[11];
	DBOLN	= vcomed[12];
	UNDEL	= vcomed[13];
	INSERT	= vcomed[14];
	INDENT	= vcomed[15];
	NUMLN	= vcomed[16];
	NEXTERR	= vcomed[17];

	/* Lecture de la valeur de la tabulation */
	Xscanf(&buf[0],&pt,&val);
	lg_tabul = (SWORD) val;

	/* Lecture des symboles de traduction predefinis */
	Xfgets(&buf[0],LGREP, fc); 
	if (buf[0] != '0') {
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
		}
	}

	/* Lecture des options de traduction */
	Xfgets(&buf[0],256,fc);
	pt = 0;
	for (i = 0; i < 11; i++) {
		Xscanf(&buf[0],&pt,&val);
	}

	/* Lecture de la liste des modules */
	Xfgets(&buf[0],LGREP,fc); 
	if (buf[0] != '0') {
		while (1) {
			Xfgets(&buf[0],LGREP,fc);
			if (buf[0] == '0') break;
		}
	}


	/* Lecture des touches de fonction de l'integre */
	for (i=0 ; i<10 ; i++) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
		}
	}

	/* Lecture des touches de fonction de l'editeur de textes */
	for (i=0 ; i<10 ; i++) {
		Xfgets(&buf[0],256,fc);
		pt = 0;
		p = epltfp[i];
		val = 0xff;
		while (val != 0) {
			Xscanf(&buf[0],&pt,&val);
			*p = (BYTE) val;
			p++;
		}
		prfo((SWORD) (128 + i),epltfp[i],(BYTE) Xstrlen(epltfp[i]));
	}

	/* aller generer les l'historique de l'integre */

	Xfgets(&buf[0],256,fc);
	if (buf[0] != VEOF) {
		pt = 0;
		Xscanf(&buf[0],&pt,&val);
		/* recupere l'historique */
		for ( i = 0; i < val; i ++) {
			Xfgets(buf,256,fc);
			diff_repfich(n_path,buf, tmp);
			Xstrcpy(buf,"O-");
			Xstrcat(buf,tmp);
			maj_histo(buf);
		}
	}

	Xfclose(fc);

	/* le cfg est a jour */
	return (TRUE);	/* init OK */
}					/* lecconf */
#endif

static VOID Xfgets(BYTE XPTR buf, SWORD lgr, FILE XPTR fic)
{
	BYTE XPTR p;

	if (XXfgets(buf,lgr,fic) == NULL) {
		*buf = '\0';
	}
	if (Xstrlen(buf) == 0)
		return;

	p = buf+Xstrlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';
	p = buf+Xstrlen(buf)-1;
	if ((*p == '\n') || (*p == '\r'))
		*p = '\0';

}


/*	Lecture d'un entier dans le tampon 'buf', a partir
 *	de la position 'ptr', et resultat dans 'val'
 */
static VOID Xscanf(BYTE XPTR buf,  SWORD XPTR ptr, SWORD XPTR val)
{
	 SWORD tmp;
	 BYTE c;

  tmp = 0;
  while ((c = buf[*ptr]) != '\0' && (c != ' ')) {
	tmp = (SWORD) (10 * tmp + (SWORD) ((c - (BYTE) '0')));
	(*ptr)++;
  }
  while ((c = buf[*ptr]) == ' ')
	(*ptr)++;

  *val = tmp;
}

/*	Lecture d'un entier LONG dans le tampon 'buf', a partir
 *	de la position 'ptr', et resultat dans 'val'
 */
static VOID XscanfForLong(BYTE XPTR buf,  SWORD XPTR ptr, LONG XPTR val)
{
	 LONG tmp;
	 BYTE c;

  tmp = 0;
  while ((c = buf[*ptr]) != '\0' && (c != ' ')) {
	tmp = (LONG) (10 * tmp + (LONG) ((c - (BYTE) '0')));
	(*ptr)++;
  }
  while ((c = buf[*ptr]) == ' ')
	(*ptr)++;

  *val = tmp;
}

#ifndef ver14
/*global*/ VOID memento()
{
	SWORD i, j;
	SWORD sl,sc;
	BOOL bool;
	BYTE c = EOSTR;

	sl = ligne;
	sc = colonne;

	bool = 1;
	while (c != ESCAPE) {
		if (bool) {
			x_bstart();
			pos(LGINIT,CLINIT); 
			atb(22);
			j = LGINIT;

			for (i=0; i < 22;) {
				pos(j++, CLINIT);
				x_cprintf(edit_ctrl[i]);
				i++;
				}	
			j = LGINIT + 1;
			for (i=22; i < MAXCTRL; )  {
				pos(j++,40);
				x_cprintf(edit_ctrl[i]);
				i++;
				}
			pos(24,50); 
			Xatb(2); x_cprintf(edit_msg[memto]);
			Xatb(0);
			x_bflush();
			bool = 0;
			}
		else 	{
			x_bstart();
			pos(LGINIT,CLINIT); atb(22);
			j = LGINIT;
			for (i=0; i < MAXCOM; )  {
				pos(j++,CLINIT);
				x_cprintf(edit_com[i]);
				i++;
			}
			bool = 1;
			pos(24,50); 
			Xatb(2); x_cprintf(edit_msg[memto]);
			Xatb(0);
			x_bflush();
			}
		c = getch();
		}
	editorOnShow();
	return;
}

static BOOL lgnsearch (BYTE XPTR val, BYTE XPTR lgn, SWORD lg)

/*	recherche de la chaine 'val', de longueur 'lg', dans la ligne 'lgn', 
 *	a partir de la colonne 'colcur'
 *	'colcur' est modifie en retour.
 */
{					/* lgnsearch */

	BOOL    finlig = 0;		/* BOOLEEN pour demande limite */
	SWORD lgval = Xstrlen(val);

	SWORD	lglgn = Xstrlen(lgn);


	/* Analyse de val */
	if (val[lgval-1] == LIMLIG) {
		finlig = 1;
	}
	if ((val[0] == LIMLIG) && (lg > 0)) {
		val++;
		if (Xstrncmp(&lgn[colcur],val,lg) == 0){
			return(TRUE);
		}
		else {
			return(FALSE);
		}
	}

	for ( ; colcur < lglgn; colcur++) {
		if (lgn[colcur] == *val) { /* bon debut !! */
			if (Xstrncmp(&lgn[colcur],val,lg) == 0) { 
				if (finlig) {
					if (lglgn == colcur + lg) {
						return(TRUE);
					}
				}
				else return (TRUE);

			}
		}
	}
	return (FALSE);
}					/* lgnsearch */
#ifndef vms
static BOOL getnomfic(BYTE XPTR s, BYTE XPTR buf, BYTE XPTR ext)
/*	construit la designation d'un fichier en tenant compte de l'extension
 *	fournie par 'ext'. retourne 'TRUE' si cette extension a ete ajoutee.
 */
{					/* getnomfic */
	register SWORD i = 0;
	register BYTE XPTR p = buf;

	while (*s && ++i < LGMXNOM)
		*p++ = *s++;
	*p = EOSTR;
#ifdef prologue
	/* prologue = cas particulier ou le '.' est accepte comme separateur
	 * entre le nom et l'extension d'un fichier en plus du caractere
	 * SEPTYP dedie au systeme
	 */
	if (Xstrchr(buf,'\\') != GenericNULL(char)) {
		Xerreur(FATALE, errep);
	}
	if ((Xstrchr(buf,SEPTYP) == NULL) && (Xstrchr(buf,'.') == NULL) &&
	    (++i < LGMXNOM)) {
		*p++ = SEPTYP;
		while (*ext && ++i < LGMXNOM)
			*p++ = *ext++;
		*p = EOSTR;
		return (TRUE);
	}
	else {
		if ((Xstrchr(buf,SEPTYP) == NULL) && (++i < LGMXNOM)) {
		   /* Z ! : le point peut etre le separateur volume-nom */
		   if (Xstrlen(buf) > 4) {
			if (buf[3] == '.') {
				if (Xstrchr(&buf[4],'.') == NULL) {
				 	if (buf[2] < '0' || buf[2] > '9') {
						p = &buf[3];
						*p++ = SEPTYP;
						while (*ext && ++i < LGMXNOM)
							*p++ = *ext++;
						*p = EOSTR;
					}
					else {
						*p++ = SEPTYP;
						while (*ext && ++i < LGMXNOM)
							*p++ = *ext++;
						*p = EOSTR;
						return (TRUE);
					}
				}
				else { /* remplacer le point par SEPTYP */
					*Xstrchr(&buf[4],'.') = SEPTYP;
				}
			}
			else { /* remplacer le point par SEPTYP */
				*Xstrchr(buf,'.') = SEPTYP;
			}
		   }
		   else { /* remplacer le point par SEPTYP */
			*Xstrchr(buf,'.') = SEPTYP;
		   }
		}
	}
#else
	if (Xstrchr(buf,SEPTYP) == NULL && ++i < LGMXNOM) {
		*p++ = SEPTYP;
		while (*ext && ++i < LGMXNOM)
			*p++ = *ext++;
		*p = EOSTR;
		return (TRUE);
	}
#endif
		p = Xstrchr(buf,SEPTYP) + 1;
	/* interdire les extensions EXTDEST, EXTRET et EXTSAV */
	if (striEq(p,EXTDEST) || striEq(p,EXTRET) || striEq(p,EXTSAV))
		Xerreur(FATALE,errcom);
	/* retour normal */
	return (FALSE);
}					/* getnomfic */
#endif


#endif

#ifdef ver21
static VOID nedpause()
/*	afficher un message a la position 'l,c' , et attendre
 *	la frappe d'une touche au clavier
 */
{					/* pause */
	int lg;
	int ret;
	x_bstart();
	Xatb(2);
	pos(conf(1),1); Xatb(21);
	lg = Xstrlen(edit_msg[msgwait]);
	pos(conf(1) , (conf(2)-lg) / 2);
	x_cprintf((BYTE FPTR) edit_msg[msgwait]);
	x_bflush();
	ret = x_getch();
	x_bstart();
	pos(conf(1) , 1); Xatb(21);
	Xatb(0);
	x_bflush();
	return;	
}					/* attendre */
#endif
