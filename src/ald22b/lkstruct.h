#ifndef __LKSTRUCT_H__
#define __LKSTRUCT_H__


/*
	Projet  : ABAL          Copyright Amenesik / Sologic software. (c) 1997
	Module  : WALD
	Fichier : lkstruct.h
	Version : 2.2b
	Date    : 23/03/93
	Systeme : DOS / PRL / UNIX / VMS / Windows

	Linker Abal

	Definition des structures


	Modifications list :
	15 July 1997			JPH	File creation
*/

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 * 05/09/00 : (#OK) ALD 7:  #pragma LOCAL_CONSTANT 
 * 22/11/00 : (#OK & #SP) Bug fixed bounded with constants and and GV > 32k.
 *	------------ 2.2b -------------------------------------------------
 */


/* 	Type d'access au fichier */


#define LECTURE 	0
#define ECRITURE 	1
#define RESULTAT	2
#define MODULE		3

/* liste des types */

#define T_Byte 		0
#define T_Entete	1
#define T_Args 		2
#define T_LstRef 	3
#define T_LstPro	4
#define T_ModPro	5
#define T_Tabfic	6
#define T_Bibli		7
#define T_NomLst	8
#define T_Offset	9
#define T_Patch		10
#define T_Liste_Prg	11
#define T_Fichier	12
#define T_Option	13
#define T_Name		14
#define T_Table		15
#define T_InfoCst 	16
#define T_InfoVar 	17
#define T_InfoPro 	18
#define T_InfoSeg	19

#define NB_TYPE		20

#define NUM_RES		0xff
#define LGMAXTABLE	0xffff

/* #OK: 05/09/00 ALD 7 (begin) */
int commonPragmaLocalConstant;
/* #OK: 05/09/00 ALD 7 (end) */

#ifndef VERSION_XX
/* #AT: 22/11/00 (begin) */
int	bIsGlobalVariable;
/* #AT: 22/11/00 (end) */
#endif

/*	Structure du premier BLOC du fichier traduit -T		*/
/*	-----------------------------------------------		*/

#pragma pack(1)
#define Entete struct t_hd
//JPH:Entete {
struct t_hd {
	BYTE	ver;		/* Version Traducteur	 		 0 */
	BYTE	ind;		/* Indice Traducteur     		 1 */
	BYTE	typ;		/* Marqueur ABAL ='2'    		 2 */
	BYTE	nom[LGNOMPRG];	/* Nom du fichier source 		 3 */
	BYTE	opt;		/* Options de lancement,		18 */
				/* Bit 0 : Debug(1) / Nodebug(0)	   */
				/* Bit 1 : Clear(1) / Noclear(0)	   */
				/* Bit 2 : Commande initiale(1) ou pas 	   */
	BYTE	exec;		/* Executable si 0, non exec. sinon     19 */
				/* (1 = erreurs, 2 = proc ext, 3 = module) */
	WORD	adr_arg;	/* Adr Desc Variable Commande Init 	20 */
	WORD	adr_tcg;	/* Adresse table constantes globales    22 */
	WORD	lng_tcg;	/* Longeur de table 			24 */
	WORD	adr_tvg;	/* Adr Table variables Globales		26 */
	WORD	lng_tvg;	/* Longeur de table 			28 */
	WORD	reserve;	/* Nombre de bloc de memoire etendu     30 */
	WORD	lng_xtm;	/* Longueur mem etendue			32 */
	WORD	adr_tsg;	/* Adr table des segments 		34 */
	WORD	lng_tsg;	/* Longeur de table 			36 */
	WORD	adr_tpr;	/* Adr table des procedures 		38 */
	WORD	lng_tpr;	/* Longeur de table 			40 */
	WORD	adr_npr;	/* Adr table des noms des procedures	42 */
	WORD	l_mxvl;		/* Longeur max tables Var Locales 	44 */
	WORD	t_mxdl;		/* Taille max de declarations locales   46 */
	WORD 	adr_xpro;	/* Table des procedures externes	48 */
	WORD 	adr_xvar;	/* Table des variables externes		50 */
	WORD 	adr_xcst;	/* Table des constantes externes	52 */
	WORD 	nb_regs;	/* Nb max de registres utilises		54 */
	WORD 	nb_files;	/* Nb max de fichier utilises		56 */
	WORD 	lg_mem;		/* Taille max de la memoire tempo.	58 */
	WORD 	lg_stack;	/* Taille max de la pile interne	60 */
	WORD 	secret;		/* code de protection du traduit	62 */
	WORD 	adr_map;	/* Adr "map" de mise au point		64 */
	WORD 	adr_lst;	/* Adr nom fichier liste		66 */
	WORD 	adr_tfu;	/* Adr table fonctions utilisateur	68 */
	WORD 	lng_tfu;	/* Longueur asociee          		70 */
	WORD 	adr_tdr;	/* adresse de relocation des RT		72 */

	WORD 	val_min_bloc;	/* Valeur minimum de blocager 		74 */
	WORD 	adr_image_tvg;  /* Adresse de l'image des var. glob.	76 */
	WORD 	lg_image_tvg;	/* Longueur de l'image des var. glo.	78 */
	WORD 	taille_page;	/* Taille des pages en memoire		80 */
	WORD 	nb_buf_swap;	/* Nombre de buffers de swap		82 */
	WORD 	niv_opt;	/* Niveau maximal d'optimisation	84 */
	WORD 	tnom_seg;	/* Adresse de la table des noms de seg. 86 */
	WORD 	tseg_ext;	/* Adresse de la table des seg. ext.	88 */
	WORD 	tancrage;	/* Adresse des noms de modules		90 */
	WORD 	tnom_modules;	/* Adresse des noms de module		92 */	
	WORD 	tcor_vg;	/* Table de correspondance des Var. Glo 94 */
	WORD 	tcor_cst;	/* Table de correspondance des cst	96 */
	WORD 	lg_tcor_cst;	/* Longueur de la table de cores. cst   98 */
	WORD 	tnom_sources;   /* Table des noms de sources           100 */
	WORD 	tlabel_var;	/* Table des labels des variables      102 */
	WORD	adr_tvarext;	/* Table des descripteurs de var ext   104 */
	WORD	lgn_tvarext;	/* Longueur des desc de var ext	       106 */
	WORD	nom_cstbin;	/* Table des noms de constantes bin.   108 */
	WORD 	nom_cst;	/* Table des noms de constantes $ *    110 */
	WORD	var_static;	/* variables privees dans les modules  112 */
	WORD 	max_seg;	/* valeur du prochain segment nome rel 114 */

};
#pragma pack()

#pragma pack(1)
#define Args struct _Args
//JPH: Args {
struct _Args {
	BYTE typ_arg;
};
#pragma pack()

#pragma pack(1)
#define LstRef struct _lstref
//JPH LstRef {
struct _lstref {
	BYTE    prog;	/* numero de module */
	WORD bloc;
	WORD off;
};

#pragma pack()

#pragma pack(1)
#define LstPro struct _LsPr	/* Liste des procedures externes */

//JPH LstPro {
struct _LsPr {
	/* nom ou offset du module si precis‚ */
	WORD module;	/* Numero du module ou est defini l'extern */
	WORD num_module;	/* Numero du module ou est resolu l'extern */
	WORD hash_code;
	WORD any;		/* type d'extern */
	WORD par_qui;
	BYTE nom[LGIDENT];
	WORD solved;
	WORD proc_app;
	WORD adr_map;
	WORD lg_map;

	union {
		WORD num_seg;
		WORD adr_desc;
		WORD nb_args;
	} ext;

	C_SLIST FAR * pt_args;
	C_SLIST FAR * pt_ref;
};
#pragma pack()


#pragma pack(1)
#define ModPro struct _modpro
//JPH ModPro {
struct _modpro {
	WORD hash_code;
	WORD num_module;
	BYTE nom[LGIDENT];
	WORD used;
	WORD num_desc;
	WORD proc_app;
	WORD adr_map;
	WORD lg_map;

	union {
		WORD num_seg;
		WORD adr_desc;
		WORD nb_args;
	} pub;
	
	C_SLIST FAR * pt_args;

};
#pragma pack()

#pragma pack(1)
#define Tabfic struct t_tabfic
//JPH Tabfic {
struct t_tabfic {
	/* fichier principal */
	BYTE 	nom[LGREP];	/* nom du fichier */
	BYTE	type;		/* 0 : Lecture 1 : Ecriture */
	WORD	nl;		/* numero logique; */
	BYTE   	buffer[LGBLOC];	/* buffer secteur d'un secteur */
	WORD 	ofst;		/* Offset courrant dans le secteur */
	WORD 	bloc;		/* Numero de secteur courrant */
	Entete  *ent;		/* secteur 0 d'entete	*/
	BYTE    tmp[LGBUF]; 	/* Tampon pour bufferiser les L/E de LGBUF */
	WORD 	lg_read;	/* Nombre d'octet a lire */
	WORD 	inf;		/* Numero du premier secteur du tampon	*/
	WORD	sup;		/* Numero du dernier secteur du tampon	*/
	WORD 	reloc_bloc;	/* prochain secteur libre a ecrire */
	BOOL	FieldM;		/* Traitement sur les Field=M FAIT */
	BOOL	FieldE;		/* Traitement sur les Field=E FAIT */
	BOOL	FieldV;		/* Traitement sur les Field=V FAIT */
	/***************/
};
#pragma pack()


/*	Liste des references aux procedures externes	*/
/*	--------------------------------------------	*/

#pragma pack(1)
#define Bibli struct _bibli
//JPH Bibli {
struct _bibli {
	BYTE nom[LGNOMBIB];
	WORD pgn;
	BYTE non_util[16];

};
#pragma pack()

#pragma pack(1)
#define NomLst struct _nomlst
//JPH NomLst {
struct _nomLst {
	BYTE nom[NOMLST]; /* Extension .LST */
	BYTE num_mod;
};
#pragma pack()

#pragma pack(1)
#define Offset struct _Offset
//JPH Offset {
struct _Offset {
	WORD val_off;
	WORD valeur;
	BYTE octet;
	/* #OK & #SP: 22/11/00 (begin) */
	WORD bIsGlobalVariable;
	/* #OK & #SP: 22/11/00 (end) */
};

#pragma pack()

#pragma pack(1)
#define Patch struct _Patch
//JPH Patch { 
struct _Patch { 
	BYTE    fic;
	Tabfic *new_fic;

	WORD bloc;
	WORD new_bloc;

	C_SLIST FAR *off;
};
#pragma pack()

#pragma pack(1)
#define Liste_Prg struct _prg
//JPH Liste_Prg {
struct _prg {
	BYTE  nom_prog[LGNOMPRG];
	WORD num;
};
#pragma pack()

#pragma pack(1)
#define Name struct _name
//JPH Name {
struct _name {
	BYTE nom[LGREP];
	WORD num;
};
#pragma pack()

/*      Definition de la structure d'information sur une variable */
/*      --------------------------------------------------------- */
#define MAX_TABLE 16
#pragma pack(1)
#define Table struct _table
//JPH Table {
struct _table {
	WORD reloc;
	WORD adr;
	WORD index;
/*	BYTE XPTR * mem[8];	Bug CIEE Debordement table Constantes */
	BYTE XPTR * mem[MAX_TABLE];	/* Correction du 23/02/94 : 16 * LGBUF = 64000 */
};
#pragma pack()

#define LGCST 256
#pragma pack(1)
#define InfoCst struct _InfoCst
//JPH InfoCst {
struct _InfoCst {
	BOOL local;
	BYTE type;
	BYTE longueur;
	BYTE valeur[LGCST];
	WORD adrdesc;
	WORD lgdesc;	
};
#pragma pack()

#pragma pack(1)
#define InfoVar struct _InfoVar
//jph InfoVar {
struct _InfoVar {
	WORD descripteur;	/* Descripteur code */
	BOOL local;		/* Local ou Global */
	BOOL etendue;		/* Field=E */
	BOOL virtuelle;		/* Field=no */
	WORD nologique;		/* nologique =no */
	BOOL trou;		/* trou de traduction */
	BOOL arg;		/* arg ou proc */
	BOOL ptr;		/* Pointeur ou non */
	BYTE tptr;		/* Pointeur, ... */
	BYTE type;		/* type */
	WORD longueur;		/* longueur */
	WORD ptr_longueur;	/* longueur de la zone pointee */
	WORD dim1;		/* 1ere dimension */
	WORD dim2;		/* 2eme dimension */
	WORD adredefptr;	/* adresse en cas de redef de zone pointee */
	WORD adrvar;		/* adresse de la variable */
	WORD adrfield;		/* adresse de la variable Field E, NO */
	WORD adrdesc;
	WORD lgdesc;
	ULONG lgfielde;		/* longueur d'une variable field=e */
};
#pragma pack()

#define LGPRO 16
#pragma pack(1)
#define InfoPro struct _InfoPro
//JPH InfoPro {
struct _InfoPro {
	WORD adrcode;
	WORD lgcode;
	WORD adrdcl;
	WORD lgdcl;
	WORD adrcst;
	WORD lgcst;
	WORD reserve;
	WORD options;

	BOOL differedload;
	BOOL staticdcl;
	BOOL noinline;
	WORD adrdesc;
	WORD lgdesc;
};
#pragma pack(1)

#define LGSEG 24
#pragma pack(1)
#define InfoSeg struct _InfoSeg
//JPH InfoSeg {
struct _InfoSeg {
	WORD numseg;
	WORD adrcode;
	WORD lgcode;
	WORD adrdcl;
	WORD lgdcl;
	WORD adrcst;
	WORD lgcst;
	WORD options;
	WORD r1;
	WORD r2;
	WORD r3;
	WORD r4;

	BOOL differedload;
	BOOL staticdcl;
	BOOL noinline;

	WORD adrdesc;
	WORD lgdesc;

};
#pragma pack()

#pragma pack(1)
#define Fichier struct _fichier 
//JPH Fichier {
struct _fichier {
	Tabfic code;
	Entete ent_code;

	Tabfic dbg;
	Entete ent_dbg;

	/* 	la table des constantes */
	Table 	Tcst;

	/* 	la table des variables */
	Table	Tvar;

	/* 	la table des procedures */
	Table 	Tpro;

	/* 	la table des segments   */
	Table	Tseg;

	/*	la table des variables externes */
	Table	Tvarext;

	/*	la liste des constantes binaires */
	C_SLIST FAR * liste_cstbin_pub[ HTV ];

	/*	la liste des constantes bcd/chaine */
	C_SLIST FAR * liste_cst_pub[ HTV ];

	/* 	la liste des var  pub	*/
	C_SLIST FAR * liste_var_pub[ HTV ];

	/* 	la liste des proc pub	*/
	C_SLIST FAR * liste_pro_pub[ HTV ];

	/* 	la liste des seg  pub	*/
	C_SLIST FAR * liste_seg_pub[ HTV ];
	
	/* 	la liste des bda	*/
	C_SLIST FAR * liste_bda;		

	/* 	la liste des sources	*/
	C_SLIST FAR * liste_source;

	/* 	la liste des var. ext   */
	C_SLIST FAR * 	liste_var_ext;

	/* 	la liste des proc. ext. */
	C_SLIST FAR * 	liste_pro_ext;

	/* 	la liste des seg. ext   */
	C_SLIST FAR * 	liste_seg_ext;

	/* 	la liste des modules ext. */
	C_SLIST FAR * liste_mod_ext;

	/*	la liste des labels */
	C_SLIST FAR * liste_label;

	/*	la liste des points d'ancrages */
	C_SLIST FAR * liste_ancrage;

	/* les variables globales d'un fichier */

	BYTE	NUM_PRG; 	/* Numero d'ordre du traduit */
	WORD	nb_var_solved;	/* Nombre de variables externes resolues */
	WORD 	nb_pro_solved;	/* Nombre de procedures externes resolues */
	WORD 	nb_seg_solved;  /* Nombre de segments externs resolus */
	WORD	next_num_seg;	/* Prochain segment libre pour une relocation */
};
#pragma pack()

#define All_Fichier() (Fichier XPTR *) Xmalloc(sizeof(Fichier),T_Fichier)
#define Free_Fichier(p) Xfree((Fichier XPTR *) p, sizeof(Fichier),T_Fichier)
#pragma pack(1)
#define Option struct _option
//jph Option {
struct _option {
	WORD output;

	BYTE rep_destination[LGREP];
	BYTE rep_module[LGREP];
	WORD debug;
	WORD LH;
	WORD CH;
	BOOL libere_liste_publique;
	BOOL cst_alias;
	BYTE info;
	BOOL bavard;
	BOOL resol;
	BOOL strict;
	BOOL quick_open;

	C_SLIST FAR * liste_prg;
	C_SLIST FAR * liste_mod;

	Fichier XPTR *  current;
	Fichier XPTR *  resultat;

};
#pragma pack()

#pragma pack(1)
#define VarExt struct _varext
//JPH VarExt {
struct _varExt {
	BYTE nom[LGIDENT];
	WORD num_desc;	
	C_SLIST FAR * pt_ref;
};
#pragma pack()

#pragma pack(1)
#define Ancrage struct _Ancrage
//JPH Ancrage {
struct _Ancrage {
	WORD par_qui;
	BYTE label[LGIDENT];
	BYTE field;
	WORD off;
	WORD bloc;
	WORD adr_varext;
	C_SLIST FAR * liste_varext;
};
#pragma pack()

#pragma pack(1)
#define Label struct _label
//JPH Label {
struct _label {
	BYTE label[LGIDENT];
	BYTE field;
	WORD off;
	WORD bloc;
};
#pragma pack()


#endif
