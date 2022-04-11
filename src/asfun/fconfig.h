#ifndef	_fconfig_h
#define	_fconfig_h

struct F_CONFIG {
	/* controle version */
	BYTE	f_titr[3];	/* YES */
	BYTE	f_vers;		/* YES */
	BYTE	f_ind;		/* YES */

	/* correspondance attributs couleurs */
	BYTE	f_fond[3];	/* YES */
	BYTE	f_sousint[3];	/* YES */
	BYTE	f_normal[3];	/* YES */
	BYTE	f_souligne[3];	/* YES */
	BYTE	f_surint[3];	/* YES */
	BYTE	f_inverse[3];	/* YES */
	BYTE	f_barsel[3];	/* YES */
	/* jeux de cadre */
	BYTE	f_cadr1[8];	/* YES */
	BYTE	f_cadr2[8];	/* YES */
	BYTE	f_cadr3[8];	/* YES */
	/* caracteres speciaux */
	BYTE	f_cfond;	/* YES */
	BYTE	f_cseph;	/* YES */
	BYTE	f_clactif;	/* YES */
	BYTE	f_cmactif;	/* YES */
	BYTE	f_cchain;	/* YES */
	BYTE	f_chaut;	/* YES */
	BYTE	f_cbas;		/* YES */
	BYTE	f_cdroit;	/* YES */
	BYTE	f_cgauche;	/* YES */
	/* touches speciales */
	BYTE	f_tvalid;	/* YES */
	BYTE	f_tesc;		/* YES */
	BYTE	f_tback;	/* YES */
	BYTE	f_tdroite;	/* YES */
	BYTE	f_tgauche;	/* YES */
	BYTE	f_thaut;	/* YES */
	BYTE	f_tbas;		/* YES */
	BYTE	f_tpghaut;	/* YES */
	BYTE	f_tpgbas;	/* YES */
	BYTE	f_tpgdroite;	/* YES */
	BYTE	f_tpggauche;	/* YES */
	BYTE	f_thome;	/* YES */
	BYTE	f_tend;		/* YES */
	BYTE	f_ttab;		/* YES */
	BYTE	f_taide;	/* YES */
	BYTE	f_efecran;
	BYTE	f_efdebl;
	BYTE	f_effinl;
	BYTE	f_centre;
	BYTE	f_supsuiv;
	BYTE	f_supprec;
	BYTE	f_inslig;
	BYTE	f_suplig;
	BYTE	f_inscar;
	BYTE	f_msuiv;
	BYTE	f_mprec;
	BYTE	f_bd_elprec;

	BYTE	f_reserve[9];	/* NON */
	/* styles de fenetres */
	BYTE	f_stf1[7];
	BYTE	f_stf2[7];
	BYTE	f_stf3[7];
	BYTE	f_stf4[7];
	BYTE	f_stf5[7];
	/* position status */
	BYTE	f_lslig;	/* YES */
	BYTE	f_lscol;	/* YES */
	/* validation */
	BYTE	f_bvlig;	/* YES */
	BYTE	f_bvcol;	/* YES */
	BYTE	f_bvstf;	/* YES */
	/* fond */
	BYTE	f_mode;		/* YES */
	/* attributs ‚l‚ments boite de dialogue */
	BYTE	f_bd[3];	/* YES */
	BYTE	f_c_bout[3];	/* YES */
	/* attribut ombre */
	BYTE	omb_atb[3];	/* YES */
	BYTE	mouse_inhibit;	/* YES */
	BYTE	f_bouton[3];	/* YES */
	/* ce qu'il reste */
	BYTE	f_res[137];	/* NON */
	};

#endif	/* _fconfig_h */
	/* ---------- */

