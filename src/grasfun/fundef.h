#ifndef	_fundef_h
#define	_fundef_h

#define	WORD	unsigned short int
#define	WPTR	WORD *
#define	BYTE	unsigned char

typedef struct desc_creat_fun {
	int Amere_nbr;			/* numero mere ou console */
	WORD Apos_lig;			/* position ligne   */
	WORD Apos_col;			/* position colonne */
	WORD Anb_lig;			/* Nombre de lignes */
	WORD Anb_col;			/* Nombre de colonnes */

	BYTE Aatb_vid;			/* attribut video texte */
	BYTE Aatbcol_text;		/* couleur texte */
	BYTE Aatbcol_fond;		/* couleur fond */

	WORD Acontrol;			/* bit 0 = 1  (1): Invisible	 */
					/* bit 1 = 1  (2): Curseur actif */
					/* bit 2 = 1  (4): SCROLL actif  */
					/* bit 3 = 1  (8): Cadre simple trait */
					/* bit 4 = 1 (16): Cadre double trait */
					/* bit 5 = 1 (32): Cadre utilisateur  */
	WORD Aln_tit;			/* Longueur titre */
	BYTE Atitre[TAIL_TITRE];	/* Titre fenetre  */
	BYTE Acad_usr[8];		/* Cadre utilisateur */
	BYTE Acad_atb ; 		/* attribut cadre user */
	BYTE Acad_text; 		/* couleur texte cadre user */
	BYTE Acad_fond; 		/* couleur fond cadre user */
	BYTE reserve;
} WDESC_APP;

#define WDESC_APP_PTR	WDESC_APP *

#endif	/* _fundef_h */
	/* --------- */

