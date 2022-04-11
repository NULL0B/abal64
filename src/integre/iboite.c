#include "iboite.h"

/*global*/ SWORD boite(BINAIRE lig, BINAIRE col,BYTE XPTR buffer,BYTE XPTR ext,StrGen XPTR hist,StrGen XPTR fic,StrGen XPTR rep,BYTE XPTR pttitre)
{
	BYTE InitDir[LGREP];
	BYTE XPTR pt_dir;

	BINAIRE i;
	SWORD ret;
	ligne = lig;
	colonne = col;

	pchis = hist;		/* historique associe */

	pcfic = fic;

	pcrep = rep;

	
	pt_dir = &InitDir[0];

#ifdef prologue
	GetReper(pt_dir,LGREP);
#else
	GetReper(&pt_dir,LGREP);
#endif

	Xfn_parser((BYTE FPTR) ext, (BYTE FPTR) tmp, 2+4); /* on extirpe la directorie */
	if (tmp[0] != EOSTR) ChgDir(tmp);

	Xfn_parser((BYTE FPTR) ext, (BYTE FPTR) tmp, 16); /* on extirpe l'extention */
	if (Xstrlen(tmp) >= LGEXT) tmp[LGEXT - 1] = EOSTR; /* on tronque */
	Xstrcpy(sext,tmp);

	init_his();

	/* initialise la zone du path */
	if ( cico_is_graphic() ) {
		cadre(ligne-2,colonne-2,(BINAIRE) (conf(1)-4) , (BINAIRE) (colonne+58) );

		}
	else	{
		for (i=(BINAIRE) (ligne-1) ; i < (BINAIRE) (pchis->LB+1); i++) {
			pos(i,(BINAIRE) ( col -2)); Xatb(21);
			}
		}

	pos((BINAIRE) (ligne+3),colonne);

	for (i=colonne; i <= pchis->CB+1; i++)
		x_putch((BYTE) ' ');

	init_sel();

	Posit( pchis, 0);
	affiche(pchis);

	cadre(ligne,colonne,(BINAIRE) (ligne+2), (BINAIRE) (colonne+56));
	pos((BINAIRE) (ligne+1),(BINAIRE) (colonne+1)); x_cprintf((BYTE FPTR) pttitre);

	pos((BINAIRE) (ligne+1), (BINAIRE) (colonne+55)); x_putch((BYTE) ' ');
	
	while (1) {
		ret = saisie_sel((BYTE XPTR) &sel[0]);
		
		if (sel[0] == EOSTR || sel[0] == ';' ) {
			if (sel[0] == EOSTR) {
				buffer[0] = EOSTR;
			}
			else {
				Xstrcpy(buffer,&sel[1]);
			}
			break; /* nom vide */
		}
#ifdef souris
		if (ret == MOUSE) {
			if (mouse_lin > pchis->LH && mouse_lin < pchis->LB &&  mouse_col > pchis->CH && mouse_col < pchis->CB) {
				ret = 1; /* historique */
			}
			else ret = -5; /* en dehors de la boite */
		}
#endif
		if (ret == -5) {
			break;
		}
		if (ret == -1) {
			break;
		}
		if (ret == 1) {
			ret = selection(pchis);
#ifdef souris
			if (ret == MOUSE) {
				/* est ce dans la saisie */
				if (mouse_lin == (ligne+1) && mouse_col > (colonne+1) && mouse_col < (colonne + 55)) {
					ret = 1;
				}
				else ret = -5; /* en dehors de la boite */
			
			}
#endif
			if (ret == -5) break;
			if (ret == -1) break;
			if (ret == 0) {
				if ((pchis->num_fic > 0) && (ret >= 0)) {
				   Mstrcpy((BYTE FPTR) buffer,(BYTE FPTR) pchis->adr_fic->ptfic->nom);
				   maj_histo(buffer);		   
				   break;
				}
				else if (pchis->num_fic == 0) pcfic->cat_mod[0] = EOSTR;
				/* else init_sel(); */
			}
		}
		else if (ret == 0) {
			ret = chx();
			if (ret == -5) break;
			if (ret == 0) {
				if (sel[0] != EOSTR) {
					if (sel[0] != ';') {
						Xstrcpy(buffer,sel);
						maj_histo(sel);
					}
					else Xstrcpy(buffer,&sel[1]);
				}
/*				Xstrcpy(buffer,sel); */
				break;
			}

			affiche(pchis);
		}
	}

	MakeReper(InitDir,tmp);
/*	chdir(InitDir);*/
	ChgDir(tmp); 
/* retour a l'endroit initial */

	pos(lig,col); Xatb(22);

	return(ret);
}

/*global*/ VOID init_boite(StrGen XPTR pt,BINAIRE  l_aff, BINAIRE n_lig, BINAIRE n_col, BINAIRE lh, BINAIRE ch, BINAIRE b_ch, BINAIRE  t_aff, BYTE XPTR nom)
{

	pt->LG_AFF = l_aff;
	pt->nlig = n_lig;
	pt->ncol = n_col;
	pt->LH = lh;
	pt->CH = ch;
	pt->LB = (BINAIRE) (pt->LH + pt->nlig + 1);
	pt->CB = (BINAIRE) (pt->CH+ b_ch);
	
	pt->lnext = GenericNULL(Liste);

	Mstrcpy((BYTE FPTR) pt->nom, (BYTE FPTR) nom);
	pt->cat_mod[0] = EOSTR;

	pt->type_aff = (BYTE) t_aff; /* Type d'affichage */

	pt->lnext = GenericNULL(Liste);
	pt->lback = GenericNULL(Liste);
	
	pt->lg_liste = 0;	

	/* Constuire la liste */
	
	pt->num_fic = 0;
	pt->adr_fic = pt->lnext;

	pt->deb_page = 0;
	pt->fin_page = pt->lg_liste;

	pt->adr_deb = pt->lnext;

	pt->imax = 0;
	pt->jmax = 0;
	pt->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */

}

/*global*/ VOID liste_histo(StrGen XPTR ptliste, BYTE XPTR ptbuf)
{
	pchis = ptliste;
	init_his();
	maj_histo(ptbuf);
}

#ifdef DBmalloc
 VOID XPTR  XXmalloc(l)
int l;
{
	BYTE resul[10];
	VOID XPTR  p;

	p = malloc(l);
	if (p == 0) {
		x_cprintf((BYTE FPTR) " MERDE ");
	}
	else nballoc++;
	return (p);
}

 VOID XXfree(p)
VOID XPTR p;
{
	char resul[10];

	if (p == 0) {
#ifdef prologue
		x_cprintf((byte far *) " Halte Scandale !!! pointeur NUUUUULLLLL!");
#else
		x_cprintf((BYTE far *) " Halte Scandale !!! pointeur NUUUUULLLLL!");
#endif
		x_getch();
	}
	free(p);
	nballoc--;
}
#endif

/*global*/ VOID init_sel()
{


	maj_path();

	Xstrcpy(sjoker,"*");
	Xstrcpy(sel,sjoker);
	Xstrcat(sel,sext);
	bool_path = FALSE;
}

/*global*/ BINAIRE init_fic()
{
	
	BYTE    recfic[LGBNOM];


	Xstrcpy(tmp,n_path);
	Xstrcat(tmp,sel);
	if (Xstrcmp(pcfic->cat_mod,tmp) == 0) {
		return(0);
	}
		
	purge(pcfic);

	Xstrcpy(pcfic->cat_mod,tmp);
	
	if (FFile(pcfic->cat_mod,recfic) == -1) {
		return(0);
		}
	while (1) {
		Xstrcpy(tmp, n_path);
		Xstrcat(tmp,recfic);
		if ((ins_en_ordre(pcfic,tmp)) != 1) break;
		if ((NFile(recfic)) == MOINS_UN) break;			/* Prise en compte d'un nouveau cfic */
		};

	Posit(pcfic,0);

	pcfic->deb_page = 0;

	if (pcfic->lg_liste == 0) {
		pcfic->fin_page = 0;
	} 
	else {
		if (pcfic->lg_liste <= (pcfic->nlig*pcfic->ncol)) {
			pcfic->fin_page = (BINAIRE) (pcfic->lg_liste - 1);
		}
		else {
			pcfic->fin_page = (BINAIRE) ((pcfic->nlig * pcfic->ncol) - 1);
		}
	}

	pcfic->adr_deb = pcfic->lnext;
	pcfic->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */
	return(1); /* on a modifie la liste */
}


/*global*/ VOID init_aff(StrGen XPTR pt) /* initialise les bornes de l'affichage */
{
	BINAIRE nb_max,num;

	nb_max = (BINAIRE) (pt->nlig * pt->ncol - 1);

	num = (BINAIRE) (pt->fin_page - pt->deb_page);
	
	if (nb_max < num) {
		/* on commence par un ecran plein */
		pt->imax = (BINAIRE) (pt->nlig-1);
		pt->jmax = (BINAIRE) (pt->ncol-1);
	}
	else {
		/* Le premier ecran n'est pas plein */
		pt->imax = (BINAIRE) (num / pt->ncol);
		pt->jmax = (BINAIRE) (num - (BINAIRE) (pt->imax * pt->ncol));
	}
}

/*global*/ VOID affiche(StrGen XPTR ll) 
{
	/* cadre */
	cadre(ll->LH,ll->CH,ll->LB,(BINAIRE) (ll->CB+1));
	/* affichage du nom de la liste */

	pos(ll->LH, (BINAIRE) (ll->CH + 1)); x_cprintf((BYTE FPTR)ll->nom);
	aff_liste(ll);

}

/*global*/ VOID aff_liste(StrGen XPTR ll)
{


	Liste XPTR sauv_adr;
	BINAIRE sauv_num;


	BINAIRE lg,cl,i,j;
	BINAIRE cmp_col;
	

#ifdef buf_cico
x_bstart();
#endif
	if (ll->lg_liste == 0) return;

	init_aff(ll);

	sauv_adr = ll->adr_fic;
	sauv_num = ll->num_fic;

	Xatb(0);
	cl = ll->CH;
	for (i = 0; i < ll->imax ; i++){
		cmp_col = cl;
		for (j =0; j < ll->ncol; j++) {
			findliste(ll,i,j,1);
			Print(ll,i,j);
			cmp_col += ll->LG_AFF;
		}


		/* completer jusqu'au bord de doite */
		while (cmp_col++ < ll->CB) x_putch(' ');

		cl = ll->CH;
	}

	/* Derniere ligne a afficher */
	cmp_col = cl;
	for (j=0; j <= ll->jmax; j++) {
		findliste(ll,i,j,1);
		Print(ll,i,j);
		cmp_col += ll->LG_AFF;
	}
	while (cmp_col++ < ll->CB) x_putch(' ');

	/* Mise a jour du dernier fichier a l'ecran */
	ll->adr_fin = ll->adr_fic;
	ll->fin_page= ll->num_fic;

	lg = (BINAIRE) (ll->LH+1+i);
	cl = (BINAIRE) (ll->CH+1+(j*ll->LG_AFF));

	pos(lg++,cl);
	/* Efface la fin du tableau */
	cmp_col = cl;
	for (; j < ll->ncol; j++) {
		next_pos(0,ll->LG_AFF);
		cmp_col += ll->LG_AFF;
	}
	while (cmp_col++ < ll->CB) x_putch(' ');

	i++;
	cl = (BINAIRE) (ll->CH+1);
	

	for (; i < ll->nlig; i++) {
		pos(lg++,cl);
		cmp_col = cl;
		for(j=0; j < ll->ncol; j++) {
			next_pos(0,ll->LG_AFF);
			cmp_col += ll->LG_AFF;
		}
		while (cmp_col++ <= ll->CB) x_putch(' ');
	}

	ll->adr_fic = sauv_adr;
	ll->num_fic = sauv_num;

#ifdef buf_cico
x_bflush();
#endif
}

/*global*/ VOID next_pos(BINAIRE deb, BINAIRE fin)
{
	while (deb < fin) {
		x_putch(' ');
		deb++;
	}
}


/*global*/ VOID findliste(StrGen XPTR ptst, BINAIRE i, BINAIRE j, BINAIRE sens)
{
	BINAIRE num;

	BINAIRE num_der;


	num_der = ptst->num_fic;

	num = (BINAIRE) (ptst->deb_page + (i*ptst->ncol) + j);

	while (num_der != num) {
		if (sens == 1) {	/* vers la doite */
			if (num_der == ptst->fin_page) {
				num_der = ptst->deb_page;
				ptst->adr_fic = ptst->adr_deb;
			}
			else {
				ptst->adr_fic = ptst->adr_fic->next;
				num_der ++;
			}
		}
		else {	/* vers la gauche */
			if (num_der == ptst->deb_page) {
				num_der = ptst->fin_page;
				ptst->adr_fic = ptst->adr_fin;
			}
			else {
				ptst->adr_fic = ptst->adr_fic->back;
				num_der --;
			}
		}
	}
	ptst->num_fic = num;
}

/*global*/ VOID purge(StrGen XPTR pt)
{
	BINAIRE i;
	Liste XPTR tmp;

	for (i=0; i < pt->lg_liste; i++) {
		tmp = pt->lnext;
		Free_Cat(tmp->ptfic);
		pt->lnext = tmp->next;
		Free_Lis(tmp);		

	}

	pt->lg_liste = 0;
	pt->deb_page = 0;
	pt->fin_page = 0;
	pt->imax = 0;
	pt->jmax = 0;
	pt->adr_deb = GenericNULL(Liste);
	pt->adr_fin = GenericNULL(Liste);
	pt->lnext    = GenericNULL(Liste);	/* pointe sur le prochain */
	pt->lback    = GenericNULL(Liste);   /* pointe sur le dernier */
	pt->adr_fic  = GenericNULL(Liste);		/* Sauvegarde de l'adresse du dernier cfic */
	pt->cat_mod[0] = EOSTR;
}

/*global*/ BINAIRE init_rep()
{


	BYTE recfic[LGMXNOM];
	BYTE prep[LGREP];

	Xstrcpy(prep, n_path);
	if (Xstrcmp(pcrep->cat_mod,prep) == 0) {
		return(0);
	}

	purge(pcrep);

	Xstrcpy(pcrep->cat_mod,prep);
	
	/* Premier cfic de la selection */
	
#ifndef vms
	Xstrcat(prep,"*");
#else
	Xstrcat(prep,"*.DIR");
#endif
	if (FRep(prep,recfic) == -1) {
		return(0);
	}
	while (1) {

		Xstrcpy(tmp, n_path);
		Xstrcat(tmp,recfic);

		if ((ins_en_ordre(pcrep,tmp)) != 1) break;
		if ((NRep(recfic)) == MOINS_UN) break;			/* Prise en compte d'un nouveau cfic */
	};

	Posit(pcrep,0);

	pcrep->deb_page = 0;

	if (pcrep->lg_liste == 0) {
		pcrep->fin_page = 0;
	}
	else {
		if (pcrep->lg_liste <= (pcrep->nlig*pcrep->ncol)) {
			pcrep->fin_page = (BINAIRE) (pcrep->lg_liste - 1);
		}
		else {
			pcrep->fin_page = (BINAIRE) ((pcrep->nlig * pcrep->ncol) - 1);
		}
	}
	pcrep->adr_deb = pcrep->lnext;

	pcrep->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */

	return(1);
}

/*global*/ VOID init_his()
{

	/* structure deja initialise */
	if (pchis->lnext != GenericNULL(Liste))
		return;

	/* Premier cfic de la selection */
	
	ins_en_tete(pchis,(BYTE XPTR) " -***- ");

	pchis->deb_page = 0;

	if (pchis->lg_liste == 0) {
		pchis->fin_page = 0;
	}
	else {
		if (pchis->lg_liste <= (pchis->nlig*pchis->ncol)) {
			pchis->fin_page = (BINAIRE) (pchis->lg_liste - 1);
		}
		else {
			pchis->fin_page = (BINAIRE) ((pchis->nlig * pchis->ncol) - 1);
		}
	}

	pchis->adr_deb = pchis->lnext;
	pchis->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */

}

/*global*/ SWORD chx()
{
	BINAIRE etat;

	SWORD   ret;

	/* si la liste n'est pas vide */

	while (1) {
		Xfn_parser((BYTE FPTR) sel,(BYTE FPTR)nomtmp,1+2+4);

		if (nomtmp[0] != EOSTR) { /* path non vide */
		   MakeReper(nomtmp, tmp);
		   if (ChgDir(tmp)) { x_bell();
			 return(MOINS_UN);
		    }
			/* presence d'un path dans la selection */
		   bool_path = TRUE;
		}
		
		Xfn_parser((BYTE FPTR)sel,(BYTE FPTR)tmp,8+16+32+64);
		if (Xstrlen(n_path) + Xstrlen(tmp) > LGREP) return(MOINS_UN); /* nom de fichier trops long */	

		if (joker(tmp) == 0) {
			if (tmp[0] != EOSTR) {
				MakeReper(tmp, nomtmp);
				ret = ChgDir(nomtmp);

				if (ret != 0) { /* C'est 1 fichier */

				   if (bool_path) {
					Xstrcpy(sel,n_path);
				   	Xstrcat(sel,tmp);
				   }

				   Xfn_parser((BYTE FPTR)sel,(BYTE FPTR) tmp,16);
				   if (Xstrlen(tmp) >= LGEXT)
					tmp[LGEXT - 1] = EOSTR; /* extention tronquee */
				   Xstrcpy(sext,tmp);
			
				   return(0);
				}
				else {
					/* on a change de directorie */
					Xstrcpy(sel,sjoker);
					Xstrcat(sel,sext);
				}

			}
		}
		else {
			   Xfn_parser((BYTE FPTR) sel, (BYTE FPTR) sjoker, 8);
			   Xfn_parser((BYTE FPTR)sel,(BYTE FPTR) tmp,16);
			   if (Xstrlen(tmp) >= LGEXT)
				tmp[LGEXT - 1] = EOSTR; /* extention tronquee */
			   Xstrcpy(sext,tmp);
		}

/*		init_sel(); */

		init_fic(); affiche(pcfic);
		init_rep(); affiche(pcrep);	

		/* Tout va tres bien */
		
		etat = 0;
		while (1) { /* on boucle sur les tabul */
			switch (etat) {
				case 0:
					ret = saisie_sel(&sel[0]);
#ifdef souris
					if (ret == MOUSE) {
						/* est ce les fichiers */
						if (mouse_lin > pcfic->LH && mouse_lin < pcfic->LB &&  mouse_col > pcfic->CH && mouse_col < pcfic->CB) {
							ret = 1; /* fichier */
						}
						else {
							/* est ce les repertoires */
							if (mouse_lin > pcrep->LH && mouse_lin < pcrep->LB &&  mouse_col > pcrep->CH && mouse_col < pcrep->CB) {
								etat = 2;
								ret = 2; /* repertoire */
							}
							else ret = -5; /* en dehors de la boite */
						}
					}
#endif
					if (ret == -5) return(MOINS_CINQ);
					if (ret == -1) return(MOINS_UN);
					if (ret == 0) {
						if (sel[0] == EOSTR || sel[0] == ';') 	return(0);
						else 			etat = 1;
						etat = 9;
					}
					if (ret == 1)  etat = 1;
					break;
				case 1:
					ret = selection(pcfic);
#ifdef souris
					if (ret == MOUSE) {
						/* est ce la saisie */
						if (mouse_lin == (ligne+1) && mouse_col > (colonne+1) && mouse_col < (colonne +55)) {
							etat = 0;
							ret = 2; /* saisie */
						}
						else {
							/* est ce les repertoires */
							if (mouse_lin > pcrep->LH && mouse_lin < pcrep->LB &&  mouse_col > pcrep->CH && mouse_col < pcrep->CB) {
								ret = 1; /* repertoire */
							}
							else ret = -5; /* en dehors de la boite */
						}
					}
#endif
					if (ret == -5) return(MOINS_CINQ);
					if (ret == -1) return(MOINS_UN);
					if (ret == 0) {
						Mstrcpy((BYTE FPTR) sel, (BYTE FPTR) pcfic->adr_fic->ptfic->nom);
						/* sortie de la selection */
						return(0);
					}
					if (ret == 1)  etat = 2;

					break;
				case 2:
					ret = selection(pcrep);
#ifdef souris
					if (ret == MOUSE) {
						/* est ce les fichiers */
						if (mouse_lin > pcfic->LH && mouse_lin < pcfic->LB &&  mouse_col > pcfic->CH && mouse_col < pcfic->CB) {
							etat = 1;
							ret = 2; /* fichier */
						}
						else {
							if (mouse_lin == (ligne+1) && mouse_col > (colonne+1) && mouse_col < (colonne +55)) {
								/* saisie */
								ret = 1;
							}
							else ret = -5; /* en dehors de la boite */
						}
					}
#endif
					if (ret == -5) return(MOINS_CINQ);
					if (ret == -1) return(MOINS_UN);
					if (ret == 0) {
							Mstrcpy((BYTE FPTR) tmp, (BYTE FPTR) pcrep->adr_fic->ptfic->nom);
							ChgDir(tmp);

							init_fic(); affiche(pcfic); 
							init_rep(); affiche(pcrep);
					}
					if (ret == 1)  etat = 0;
					break;
				default:
					break;
			};
			if (etat == 9) break;
		}
	}	
	return(0);
}

/*global*/ VOID aff_path(BYTE XPTR pt)
{
	BINAIRE i, d, f;

	pos((BINAIRE) (ligne+3),(BINAIRE) (colonne+2));
	/* Bufferisation du path */
	
	d = (BINAIRE) (Xstrlen(pt));
	f = (BINAIRE) (Xstrlen(buf_path));

	i = 0;
	while (*pt && i < PATH_LEN) {
		buf_path[i++] = *pt;
		pt++;
	}

	for (; d < f; d++) {
		buf_path[i++] = ' ';
	}

	buf_path[i] = EOSTR;
	x_cprintf((BYTE FPTR) buf_path);

}

/*global*/ BINAIRE joker(BYTE XPTR pt)
{
	while (*pt) {
		if (*pt == '*')  return(1);
		if (*pt == '?')  return(1);
		pt++;
	}
	return(0);
}

/*global*/ SWORD ChgDir(BYTE XPTR pt)
{
	BYTE    tmp[LGREP];

	BINAIRE disk;
	SWORD   ret;

	/* Nom de volume explicite */
	/* NOUVEAU CHGDIR */

	/* le volume */
	Xfn_parser((BYTE FPTR) pt,(BYTE FPTR) tmp,2);
		/* changement de volume */
	if (tmp[0] != 0) {
#ifdef msdos
		disk = (BYTE) ((toupper(tmp[0]) - (BYTE)('A')) + 1);
		ret = SetDisk(disk);	

#else
#ifdef prologue
		ret = Xchdir(tmp);
#else
		ret = chdir(tmp);
#endif
#endif
		if (ret == MOINS_UN && (Xstrcmp(tmp,"..")) == 0) {
			return(0);
		}
		if (ret == MOINS_UN) return(ret);

	}
		/* changement de repertoire */
#ifndef prologue
	Xfn_parser((BYTE FPTR) pt, (BYTE FPTR) tmp,4);
#else
	Xfn_parser((BYTE FPTR) pt, (BYTE FPTR) tmp,2+4);
#endif

#ifdef msdos
	if ((BYTE) (tmp[Xstrlen(tmp) - 1]) == (BYTE) (DREP[0]) && (BINAIRE) (Xstrlen(tmp)) > (BINAIRE) 1) (BYTE) tmp[Xstrlen(tmp) - 1] = (BYTE) EOSTR;
#endif

	if (tmp[0] != EOSTR) {
		ret = Xchdir(tmp);
		if (ret == MOINS_UN && (Xstrcmp(tmp,"..")) == 0) {
			return(0);
		}
	}	

		/* nom = repertoire */
	Xfn_parser((BYTE FPTR) pt, (BYTE FPTR) tmp,8+16+32);

	if (tmp[0] != EOSTR) {
		ret = Xchdir(tmp);
		if (ret == MOINS_UN && (Xstrcmp(tmp,"..")) == 0) {
			return(0);
		}
	}	
	if (ret == 0) maj_path();
	return(ret);
}

/*global*/ VOID maj_path()
{
	BYTE XPTR p;

	p = nomtmp;
#ifdef prologue 
	GetReper(p,LGREP);
#else
	GetReper(&p,LGREP);
#endif

	MakeReper(nomtmp, n_path);
	aff_path(n_path);

}

/*global*/ SWORD selection(StrGen XPTR pt)
{
	BINAIRE ii,jj,i;
	BINAIRE ii1, jj1;
	SWORD   rep;
	
	/* Determination des coordonnees */
	if (pt->adr_fic == GenericNULL(Liste)) {
		return(1);
	}

	ii = (BINAIRE) ((pt->num_fic - pt->deb_page) / pt->ncol);
	jj = (BINAIRE) ((pt->num_fic - pt->deb_page) - (ii * pt->ncol));


	Xatb(2); Print(pt,ii,jj); Xatb(0);
#ifdef souris
	rep = PositSouris((BINAIRE) ((pt->CH+1 + jj*pt->LG_AFF) * 8),(BINAIRE) ((pt->LH + ii) * 8) );
#endif
	while (1) {
		rep = x_getch();
#ifdef souris
		if (rep == MOUSE) {
			if (mouse_lin > pt->LH && mouse_lin < pt->LB &&  mouse_col > pt->CH && mouse_col < pt->CB) {
				switch (mouse_bouton) {
					case 0:
						ii1 = (BINAIRE) ((mouse_lin - pt->LH) - 1);
						jj1 = (BINAIRE) (((mouse_col - pt->CH) -1) / pt->LG_AFF);
						if (((ii1 == pt->imax) && (jj1 > pt->jmax)) || (ii1 > pt->imax) ) {
							rep = -5; 
						}
						else {
							if (jj1 == jj && ii1 == ii) {
								rep = CR;
							}
							else {
								Print(pt,ii,jj);
								findliste(pt,ii1,jj1,1);
								ii = ii1;
								jj = jj1;
								
								rep = MOUSE;
							}
						}
		
						break;
					case 3:
						rep = MOINS;
						break;
					default:
						rep = TABUL;
						break;

				};
			}
			else {
				Print(pt,ii,jj);
				return(rep); /* en dehors de la boite */
			}			
		}
#endif
		if (rep == CTRLF) return(MOINS_CINQ);
		if (rep == TABUL) {
			Print(pt,ii,jj);
			return(1);
		}
		if (rep == ESCAPE) {
			Print(pt,ii,jj);
			return (MOINS_UN);
		}
		if (rep == CR) {
			Print(pt,ii,jj);
			return (0);
		}
		if (rep == CURG) { 
			Print(pt,ii,jj);
			if (jj == 0) {
				if (ii == 0) {
					ii = pt->imax; jj = pt->jmax;
				}
				else {
					ii--;
					jj = (BINAIRE) (pt->ncol -1);
				}
			}
			else {
				jj--;
			}

			findliste(pt,ii,jj,0);
		}
		else if (rep == CURD) { 
			Print(pt,ii,jj);
			if ((ii == pt->imax) && (jj == pt->jmax)) {
				ii = 0; jj = 0; 
			}
			else {
				if (jj == pt->ncol -1) {
					ii++;
					jj = 0;
				}
				else {
					jj++;
				}
			}

			findliste(pt,ii,jj,1);

		}
		else if ((rep == CURB) || (rep == PLUS)) {
			Print(pt,ii,jj);
			if ((ii == pt->imax) || ((ii == pt->imax-1) 
			   && (jj > pt->jmax)) ) {

				if (rep != PLUS) {
					ii=0; 				
				}
				else {
					/* scrooling */
					if (pt->fin_page != pt->lg_liste - 1) {
						Posit(pt, (BINAIRE) (pt->deb_page + pt->ncol));
						pt->adr_deb = pt->adr_fic;
						pt->deb_page = pt->num_fic;

						if (pt->lg_liste <= pt->num_fic + (pt->nlig* pt->ncol)) {
							   pt->fin_page = (BINAIRE) (pt->lg_liste - 1);
						}
						else {
							   pt->fin_page = (BINAIRE) (pt->num_fic+ (pt->nlig * pt->ncol) - 1);
						}
						pt->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */
						
						aff_liste(pt);

						if (ii == pt->imax  && jj > pt->jmax)  {
							ii --;
						} 

						Posit(pt,(BINAIRE) (pt->deb_page + (ii * jj)));
					}
					else 	x_bell();
				}
			}
			else {
				ii++; 
			}
			findliste(pt,ii,jj,1);
		}
		else if (rep == CURH || rep == MOINS) {
			Print(pt,ii,jj);
			if (ii == 0) {
				if (rep != MOINS) {
					ii = pt->imax;
					if (jj > pt->jmax) {
						ii --;
					}
				}
				else {
					/* scrooling */
					if (pt->deb_page > pt->ncol-1) {
						Posit(pt, (BINAIRE) (pt->deb_page - pt->ncol));
					}
					else	Posit(pt, 0);
				
					pt->adr_deb = pt->adr_fic;
					pt->deb_page = pt->num_fic;

					pt->fin_page = (BINAIRE) (pt->lg_liste - 1);

					aff_liste(pt);

					ii = (BINAIRE) ((pt->num_fic - pt->deb_page) / pt->ncol);
					jj = (BINAIRE) ((pt->num_fic - pt->deb_page) - (ii * pt->ncol));
				}
			}
			else {
				ii--;
			}
 
			findliste(pt,ii,jj,0);
	
		}
		else if (rep == PGDN) {
			if (pt->imax != pt->nlig-1 || pt->jmax != pt->ncol-1 || pt->fin_page == pt->lg_liste - 1) {
				x_bell();
			}
			else {
				pt->num_fic = (BINAIRE) (pt->fin_page + 1);
				pt->adr_fic = pt->adr_fin->next;
				pt->adr_deb = pt->adr_fin->next;
				pt->deb_page = pt->num_fic;
				if (pt->lg_liste <= pt->num_fic + (pt->nlig* pt->ncol)) {
				   pt->fin_page = (BINAIRE) (pt->lg_liste - 1);
				}
				else {
				   pt->fin_page = (BINAIRE) (pt->num_fic+ (pt->nlig * pt->ncol) - 1);
				}
				pt->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */
				aff_liste(pt);
				ii = jj = 0;				
			}
		}
		else if (rep == PGUP) {
			if (pt->deb_page == 0) {
				x_bell();
			}
			else {
				/* On se repositionne sur le last of ecran -1 */
				pt->adr_fic = pt->adr_deb->back;
				pt->num_fic = (BINAIRE) (pt->deb_page - 1);

				if (pt->deb_page > (pt->nlig*pt->ncol) -1) {
					i = (BINAIRE) ((pt->nlig * pt->ncol)- 1);
					pt->fin_page = (BINAIRE) (pt->deb_page - 1);
				}
				else {
					if (pt->lg_liste > (pt->nlig * pt->ncol)- 1) {	
						pt->fin_page = (BINAIRE) ((pt->nlig * pt->ncol)- 1);
					}
					else	pt->fin_page = (BINAIRE) (pt->lg_liste - 1);

					/* pour revenir sur le premier */
					i = (BINAIRE) (pt->deb_page - 1);
				}
				while(i--) {
					pt->adr_fic = pt->adr_fic->back;
					pt->num_fic--;			
				}

				pt->deb_page = pt->num_fic;
				pt->adr_deb  = pt->adr_fic;

				pt->adr_fin = GenericNULL(Liste);

				aff_liste(pt);

				ii = jj = 0;				
			}
		}
#ifdef ver15
		else if (rep == CTRLY && pt->type_aff != 1) {
			/* suppression dans l'historique */
			if (pt->num_fic) {

				del_item(pt);
				/* recadrer la liste */
				if (pt->lg_liste <= pt->deb_page + (pt->nlig* pt->ncol)) {
				   pt->fin_page = (BINAIRE) (pt->lg_liste - 1);
				}

				if (pt->num_fic < pt->deb_page) {
					pt->adr_deb = pt->adr_fic;
					pt->deb_page = pt->num_fic;
				}
				pt->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */

				aff_liste(pt);

				ii = (BINAIRE) ((pt->num_fic - pt->deb_page) / pt->ncol);
				jj = (BINAIRE) ((pt->num_fic - pt->deb_page) - (ii * pt->ncol));

			}
		}
#endif
		else if (rep) {
			Print(pt,ii,jj);					
			if ((Posit_car(pt, (BYTE) rep)) == 1) {
				/* REAFFICHE */;
				if (pt->num_fic >= pt->deb_page && pt->num_fic <= pt->fin_page) {
					ii = (BINAIRE) ((pt->num_fic - pt->deb_page) / pt->ncol);
					jj = (BINAIRE) ((pt->num_fic - pt->deb_page) - (ii * pt->ncol));
				}
				else {
					pt->adr_deb = pt->adr_fic;
					pt->deb_page = pt->num_fic;
					if (pt->lg_liste <= pt->num_fic + (pt->nlig* pt->ncol)) {
					   pt->fin_page = (BINAIRE) (pt->lg_liste - 1);
					}
					else {
					   pt->fin_page = (BINAIRE) (pt->num_fic+ (pt->nlig * pt->ncol) - 1);
					}
					pt->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */
						
					aff_liste(pt);

					ii = jj = 0;
				}
			}
			else 	x_bell();
		}
		else {     
			x_bell();
		}

		Xatb(2); Print(pt,ii,jj); Xatb(0);

		if (pt->type_aff != 0) {
			Xfn_parser((BYTE FPTR)pt->adr_fic->ptfic->nom,(BYTE FPTR)tmp,6);
			if (Xstrcmp(n_path, tmp)) aff_path(tmp);
		}
	}
}

/*global*/ VOID Print(StrGen XPTR pt, BINAIRE lgn, BINAIRE cln)
{
	BYTE tmp[LGREP];
	BYTE p[LGREP];
	BINAIRE  pad;

	pos((BINAIRE) (pt->LH+1 + lgn), (BINAIRE) (pt->CH+1 + cln*pt->LG_AFF));
	
	if (pt->adr_fic == GenericNULL(Liste)) {
		pad = 0; /* on nettoye la zone */
	}
	else {
		if (pt->type_aff == 1) {
			Xfn_parser((BYTE FPTR)pt->adr_fic->ptfic->nom,(BYTE FPTR)p,8 + 16);
		}
		else {
			if (pt->num_fic == 0) {
			        Mstrcpy((BYTE FPTR) p, (BYTE FPTR) pt->adr_fic->ptfic->nom); 
			}
			else {
				Mstrcpy( (BYTE FPTR) tmp, (BYTE FPTR) pt->adr_fic->ptfic->nom );
				diff_repfich(n_path, tmp,p);
			}
		}
		x_putch(' ');
		if (Xstrlen(p) > pt->LG_AFF) {
			for (pad=0; pad < pt->LG_AFF; pad ++) {
				x_putch(*(p+pad));
			}
		}
		else {
			x_cprintf((BYTE FPTR) p);
			pad = (BINAIRE) ((BINAIRE) (Xstrlen(p)) + 1);
		}
	}
	for (;pad < pt->LG_AFF; pad++) {
		x_putch(' ');
	}
}

/*global*/ VOID maj_histo(BYTE XPTR sl)
{
	SWORD ret;

	ret = Find_Item(pchis, sl);
	if (ret == 1) del_item(pchis);

	if (pchis->lg_liste > LMAXHIS) { /* Supprimer le dernier */
		del_en_fin(pchis);
	}

	Posit(pchis, 0);
	ins_item(pchis, sl);

/*	Posit(pchis, 0); */

	pchis->deb_page = 0;

	if (pchis->lg_liste <= (pchis->nlig*pchis->ncol)) {
		pchis->fin_page = (BINAIRE) (pchis->lg_liste - 1);
	}
	else {
		pchis->fin_page = (BINAIRE) ((pchis->nlig * pchis->ncol) - 1);
	}

	pchis->adr_deb = pchis->lnext;
	pchis->adr_fin = GenericNULL(Liste); /* Sera mis a jour lors de l'affichage */
}


/*global*/ SWORD saisie_sel(BYTE XPTR pt)
{
	/* Saisie d'une selection */
	/* La saisie  boucle tant que le nom complet est invalide */
	/* ou si le nom saisie est une directorie */

	
	BYTE XPTR pt_opt;
	SWORD     ret;

	
	while (1) {
		ret = saisie((BINAIRE) (ligne+1),(BINAIRE) (colonne+14),(BINAIRE) (36),(BINAIRE) (LGREP-1),pt);
#ifdef souris
		if (ret == MOUSE) return(ret);
#endif
		if (ret == MOINS_CINQ) return (MOINS_CINQ);
		if (ret == MOINS_UN) return (MOINS_UN); /* ESC */
		if (ret == -2) return (1);  /* TABUL */
		if (ret > 0) {
			pt_opt = pt;
			NextOpt(&pt_opt,pt);
			if ( !Xstrcmp(pt,".") || !Xstrcmp(pt,"-") ) {
				x_bell();
			}
			else {
				return(0);
			}
		}
	}
}


/*global*/ Liste XPTR new_node( BYTE XPTR nom)
{
	Liste   XPTR pt_liste;
	FileCat FPTR pt_cat;

	pt_liste = All_Lis();

	/* plus de place ? */
	if (pt_liste != GenericNULL(Liste)) {
		pt_cat = All_Cat();
		if (pt_cat == GenericFNULL(FileCat)) {
			Free_Lis(pt_liste);
			pt_liste = GenericNULL(Liste);
		}
		else {
			/* c'est bon, on peut commencer */
	
			Mstrcpy((BYTE FPTR) pt_cat->nom, (BYTE FPTR) nom);
			pt_cat->etat = 0;
			pt_liste->ptfic = pt_cat;
		}
	}
	return(pt_liste);
}

/*global*/ SWORD ins_en_tete(StrGen XPTR Xptfic, BYTE XPTR  nom)
{
	Liste   XPTR pt_liste;

	pt_liste = new_node(nom);

	/* plus de place ? */
	if (pt_liste == GenericNULL(Liste)) return(MOINS_UN);
	
	if (Xptfic->lg_liste) {
		/* l'ex numero 1 */
		Xptfic->lnext->back = pt_liste;
	}

	pt_liste->back  = Xptfic->lback;
	pt_liste->next  = Xptfic->lnext;
	
	Xptfic->lnext    = pt_liste;

	if (Xptfic->lg_liste == 0) {
		/* c'est le premier */
		Xptfic->lback	= pt_liste;
	}

	Xptfic->adr_fic  = pt_liste;

	Xptfic->num_fic  = 0;

	Xptfic->lg_liste ++;
	
	return(1);
}

/*global*/ SWORD ins_en_milieu(StrGen XPTR Xptfic, BYTE XPTR nom)
{

	Liste XPTR pt_liste;
	
	pt_liste = new_node(nom);

	if (pt_liste == GenericNULL(Liste)) return(MOINS_UN);

	pt_liste->next 		= Xptfic->adr_fic->next;
	pt_liste->back		= Xptfic->adr_fic;

	pt_liste->next->back = pt_liste;
	pt_liste->back->next = pt_liste;
	
	Xptfic->adr_fic 	= pt_liste;
	Xptfic->num_fic ++;
	Xptfic->lg_liste ++;

	return(1);
}

/*global*/ SWORD ins_en_fin(StrGen XPTR Xptfic,  BYTE XPTR nom)
{
	Liste   XPTR pt_liste;

	pt_liste = new_node(nom);

	/* plus de place ? */
	if (pt_liste == GenericNULL(Liste)) return(MOINS_UN);
	
	/* mise a jour du dernier de la liste */

	Xptfic->lback->next = pt_liste;
	pt_liste->back  = Xptfic->lback;

	pt_liste->next  = Xptfic->lnext;

	Xptfic->lback	= pt_liste;

	Xptfic->lg_liste ++;

	Xptfic->adr_fic  = pt_liste;
	Xptfic->num_fic  = (BINAIRE) (Xptfic->lg_liste - 1);

	return(1);	/* cela c'est bien passe */
}

/*global*/ SWORD ins_en_ordre(StrGen XPTR Xptfic,  BYTE XPTR nom)
{
	BINAIRE deb, fin, mil;
	SWORD   ret;	

	/* insertion dichotomique */

	if (Xptfic->lg_liste == 0) {
		return(ins_en_tete(Xptfic,nom));
	}
	
	/* test aux bornes */

	/* test en queue */
	/* Pour ne pas penaliser les arrivees en ordre alpha */

	
	ret = cmp_item(nom, Xptfic->lback->ptfic);
	if (ret == 0) return(0);	/* doublon */
	if (ret > 0) {
		return(ins_en_fin(Xptfic, nom));
	}

	/* test en tete */

	ret = cmp_item(nom, Xptfic->lnext->ptfic);
	if (ret == 0) return(0); /* doublon */
	if (ret < 0) {
		return(ins_en_tete(Xptfic,nom));
	}

	/* debut de la recherche */

	
	deb = 0;
	fin = (BINAIRE) (Xptfic->lg_liste - 1);

	do {
		mil =  (BINAIRE) (deb + (fin - deb) / 2);

		Posit(Xptfic, mil);
	
		ret = cmp_item(nom,Xptfic->adr_fic->ptfic);

		if (ret == 0) return(0); /* c'est un doublon */

		if (ret > 0) 
			deb = mil;
		else 	fin = mil;

	}
	while ((fin - deb) != 1);

	Posit(Xptfic,deb);
		
	return(ins_en_milieu(Xptfic,nom));
}

/*global*/ VOID ins_item(StrGen XPTR Xptfic, BYTE XPTR nom)
{
	if (Xptfic->lg_liste == 0) ins_en_tete(Xptfic,nom);
	else if (Xptfic->num_fic == Xptfic->lg_liste - 1) ins_en_fin(Xptfic, nom);
	else ins_en_milieu(Xptfic, nom);

}

/*global*/ VOID del_item(StrGen XPTR Xptfic)
{
	if (Xptfic->num_fic == 0) del_en_tete(Xptfic);
	else if (Xptfic->num_fic == Xptfic->lg_liste - 1) del_en_fin(Xptfic);
	else del_en_milieu(Xptfic);

}


/*global*/ VOID del_en_tete(StrGen XPTR Xptfic)
{
	Liste XPTR pt_liste;
	
	/* suppression de l'element courrant */

	pt_liste = Xptfic->adr_fic;
 
	Xptfic->lnext 		= pt_liste->next;
	pt_liste->next->back 	= Xptfic->lback;
	
	Xptfic->lg_liste --;

	Xptfic->adr_fic		= Xptfic->lnext;
	
	Free_Cat(pt_liste->ptfic);
	Free_Lis(pt_liste);

}


/*global*/ VOID del_en_fin(StrGen XPTR Xptfic)
{

	Liste XPTR pt_liste;
	
	/* suppression de l'element courrant */

	pt_liste = Xptfic->adr_fic;
 
	Xptfic->lback 		= pt_liste->back;
	pt_liste->back->next 	= Xptfic->lnext;
	
	Xptfic->lg_liste --;

	Xptfic->adr_fic 		= Xptfic->lback;
	Xptfic->num_fic	--;
	
	Free_Cat(pt_liste->ptfic);
	Free_Lis(pt_liste);
}

/*global*/ VOID del_en_milieu(StrGen XPTR Xptfic)
{

	Liste XPTR pt_liste;
	
	/* suppression de l'element courrant */

	pt_liste = Xptfic->adr_fic;
 
	pt_liste->next->back 	= pt_liste->back;
	pt_liste->back->next	= pt_liste->next;
	
	Xptfic->lg_liste --;
	Xptfic->adr_fic = pt_liste->next;
	
	Free_Cat(pt_liste->ptfic);
	Free_Lis(pt_liste);
}

/*global*/ VOID Posit(StrGen XPTR Xptfic, BINAIRE num)
{



	if (num >= Xptfic->lg_liste) {
		Xptfic->adr_fic = Xptfic->lnext;
		Xptfic->num_fic = 0;
		num = 0;
	}

	while (num != Xptfic->num_fic) {
		if (num < Xptfic->num_fic) {
			Xptfic->adr_fic = Xptfic->adr_fic->back; /* en arriere */
			Xptfic->num_fic --;
		}
		else	{
			Xptfic->adr_fic = Xptfic->adr_fic->next; /* en avant */
			Xptfic->num_fic ++;
		}
	}
}

/*global*/ BINAIRE Posit_car(StrGen XPTR pt, BYTE lettre)
{
	BINAIRE sauv_pos;

	sauv_pos = pt->num_fic;
#ifndef unix
	lettre = (BYTE) toupper(lettre);
#endif
	Xfn_parser( (BYTE FPTR) pt->adr_fic->ptfic->nom,(BYTE FPTR) tmp, 8);
	if (tmp[0] == lettre) Posit(pt,(BINAIRE) (pt->num_fic + 1));

	Xfn_parser( (BYTE FPTR) pt->adr_fic->ptfic->nom,(BYTE FPTR) tmp, 8);
	if (tmp[0] == lettre) return(1);
	
	/* lettre non trouve */
	while (1) {
		if (pt->num_fic == 0) break;	
		Xfn_parser( (BYTE FPTR) pt->adr_fic->ptfic->nom,(BYTE FPTR) tmp, 8);
		if (tmp[0] < lettre) break;
		Posit(pt,(BINAIRE) (pt->num_fic - 1));
	}
	
	while (1) {
		Xfn_parser((BYTE FPTR) pt->adr_fic->ptfic->nom, (BYTE  FPTR) tmp, 8);
		if (pt->num_fic == pt->lg_liste - 1) break;
		if ( (BYTE) tmp[0] == (BYTE) lettre) break;

		Posit(pt,(BINAIRE) ( pt->num_fic+ 1));
	}

	if ( (BYTE) tmp[0] != (BYTE) lettre) {
		Posit(pt,sauv_pos);
		return(0);
	}
	else {
		/* changement d'ecran */
		return(1);
	}	

}

/*global*/ BINAIRE cmp_item(BYTE XPTR nom, FileCat FPTR pt_cat)
{
	return((BINAIRE) (Mstrcmp((BYTE FPTR) nom, (BYTE FPTR) pt_cat->nom)));
}

/*global*/ BINAIRE Find_Item(StrGen XPTR Xptfic, BYTE XPTR what)
{
	BINAIRE nb;
	
	nb = 0;
	while (nb < Xptfic->lg_liste) {
		Posit(Xptfic,nb);	
		if ((cmp_item(what, Xptfic->adr_fic->ptfic)) == 0) return(1);
		nb++;
	}

	return(0);	/* non trouve */
}

BINAIRE Mstrcmp( s , t )
BYTE FPTR s;
BYTE FPTR t;
{
	BYTE source[320];
	BYTE target[320];

	Mstrcpy((BYTE FPTR ) source, (BYTE FPTR) s);
	Mstrcpy((BYTE FPTR ) target, (BYTE FPTR) t );

	return( strcmp(source, target ) );
}

