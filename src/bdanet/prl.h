/*
 *	Bibliotheque C Amenesik / Sologic
 *	-----------------------
 *
 *	Copyright (c) 1989 Amenesik / Sologic s.a.
 *
 *	prl.h - description pour utilisation fonctions Amenesik / Sologic
 *
 *	$Header: /home/Produits/Abal3/bdanet/prl.h,v 1.1.1.1 2003/11/04 23:40:50 root Exp $
 *
 */


#ifndef _BYTE_DEFINED
typedef unsigned char byte;		/* definition du type octet	*/
#define _BYTE_DEFINED
#endif

#ifndef _WORD_DEFINED
typedef unsigned short word;		/* definition du mot de 16 bits */
#define _WORD_DEFINED
#endif

#ifndef _DWORD_DEFINED
typedef unsigned long dword;		/* definition du mot de 32 bits */
#define _DWORD_DEFINED
#endif


extern int _prlerrno;			/* code erreur Amenesik / Sologic 	*/


/* type de resultat ANFC */

#define _ANFC_RESSOURCE 	0x0001		/* nom ressource seul	*/
#define _ANFC_EXPLICITE 	0x0004		/* ressource explicite	*/
#define _ANFC_FICHIER		0x0040		/* nom de fichier	*/


/* positionnement des attributs d'ouverture */

#define _PATB_EXCLUSIF		0x0010		/* mode exclusif	*/
#define _PATB_PARTAGEABLE	0x1010		/* mode partageable	*/
#define _PATB_COPIE		0x8080		/* mode copie		*/
#define _PATB_SECURITE		0x0080		/* mode non copie	*/


/* activation / desactivation du superviseur */

#define _PRIO_ACTIVATION	0x0000		/* activation		*/
#define _PRIO_DESACTIVATION	0x0001		/* desactivation	*/


/* critere d'allocation d'un segment memoire */

#define _ALSM_COMMUNE		0x0080		/* partition commune	*/
#define _ALSM_COMPATIBLE	0x0040		/* partition compatible */
#define _ALSM_HAUTE		0x0020		/* memoire haute	*/
#define _ALSM_EXPLICITE 	0x0001		/* desalloc. explicite	*/


/* sens d'extension d'un segment memoire */

#define _MDSM_REDUCTION 	0x0000		/* reduction de taille	*/
#define _MDSM_EXTENSION 	0x0001		/* extension de taille	*/


/* commande de CO */

#define _CO_NORMAL		"\x01ba"
#define _CO_PREFERENTIEL	"\x01bp"
#define _CO_INVERSION		"\x01bb"
#define _CO_CLIGNOTANT		"\x01bc"
#define _CO_SOULIGNE		"\x01bd"
#define _CO_SOUS_BRILLANCE	"\x01be"
#define _CO_SUR_BRILLANCE	"\x01bh"

#define _CO_ALLUME		"\x01bv"
#define _CO_ETEINT		"\x01bw"

#define _CO_FOND_NOIR		"\x01bs0"
#define _CO_FOND_ROUGE		"\x01bs1"
#define _CO_FOND_VERT		"\x01bs2"
#define _CO_FOND_MARRON 	"\x01bs3"
#define _CO_FOND_BLEU		"\x01bs4"
#define _CO_FOND_MAGENTA	"\x01bs5"
#define _CO_FOND_CYAN		"\x01bs6"
#define _CO_FOND_GRIS_CLAIR	"\x01bs7"

#define _CO_TEXTE_NOIR		"\x01br0"
#define _CO_TEXTE_ROUGE 	"\x01br1"
#define _CO_TEXTE_VERT		"\x01br2"
#define _CO_TEXTE_MARRON	"\x01br3"
#define _CO_TEXTE_BLEU		"\x01br4"
#define _CO_TEXTE_MAGENTA	"\x01br5"
#define _CO_TEXTE_CYAN		"\x01br6"
#define _CO_TEXTE_GRIS_CLAIR	"\x01br7"
#define _CO_TEXTE_GRIS_FONCE	"\x01br8"
#define _CO_TEXTE_ROUGE_CLAIR	"\x01br9"
#define _CO_TEXTE_VERT_CLAIR	"\x01brA"
#define _CO_TEXTE_JAUNE 	"\x01brB"
#define _CO_TEXTE_BLEU_CLAIR	"\x01brC"
#define _CO_TEXTE_MAGENTA_CLAIR "\x01brD"
#define _CO_TEXTE_CYAN_CLAIR	"\x01brE"
#define _CO_TEXTE_BLANC 	"\x01brF"


/* numeros de fonctions de PRFO / LCFO */

#define _FO_DROITE		0x0001
#define _FO_GAUCHE		0x0002
#define _FO_HAUT		0x0003
#define _FO_BAS 		0x0004
#define _FO_ORIGINE		0x0005
#define _FO_EFFACEMENT		0x0006
#define _FO_ANNULATION		0x0007


/* descripteur d'une ressource peripherique */

#ifndef _PRL_RESS_DEFINED
#pragma pack(1)
typedef struct {
	byte no_ress;		/* numero de ressource */
	byte no_unit;		/* numero d'unite      */
} _PRL_RESS;
#pragma pack()
#define _PRL_RESS_DEFINED
#endif


/* descripteur de retour de ANFC */

#ifndef _PRL_ANFC_DEFINED
#pragma pack(1)
typedef struct {
	_PRL_RESS ress; 	/* descripteur de la ressource	*/
	byte nom[8];		/* nom du fichier		*/
	byte type[3];		/* type du fichier		*/
	byte lec_cle[2];	/* cle en lecture du fichier	*/
	byte ecr_cle[2];	/* cle en Çcriture du fichier	*/
} _PRL_ANFC;
#pragma pack()
#define _PRL_ANFC_DEFINED
#endif


/* descripteur d'appel et de retour de CHGT ou CHGP */

#ifndef _PRL_CHGTP_DEFINED
#pragma pack(1)
typedef struct {
	_PRL_ANFC nom;		/* nom analyse du fichier	*/
	word reserve;		/* reserve			*/
	void far *pile; 	/* pile du module		*/
	void far *code; 	/* code du module		*/
	word overlay;		/* numero d'overlay             */
} _PRL_CHGTP;
#pragma pack()
#define _PRL_CHGTP_DEFINED
#endif


/* descripteur de retour de PSYS */

#ifndef _PRL_PSYS_DEFINED
#pragma pack(1)
typedef struct {
	byte version;		/* version du systäme en ASCII		*/
	byte indice;		/* indice du systäme en ASCII		*/
	byte langue;		/* code langue				*/
	byte nb_poste;		/* nombre de postes usager		*/
	byte auto_expl[2];	/* autorisations d'exploitation         */
	byte nb_ligne;		/* nb de lignes premiere imprimante	*/
	byte nb_col;		/* nb de colonnes premiere imprimante	*/
	byte cp_indic;		/* indicateur presence du coprocesseur	*/
	byte nb_max;		/* nombre maximum de postes		*/
	byte release;		/* lettre release du systeme		*/
} _PRL_PSYS;
#pragma pack()
#define _PRL_PSYS_DEFINED
#endif


/* descripteur de retour de LDAT ou d'appel de MDAT */

#ifndef _PRL_MDAT_DEFINED
#pragma pack(1)
typedef struct {
	word annee;		/* annee		*/
	byte mois;		/* mois 		*/
	byte jour;		/* jour 		*/
	word no_jour;		/* numero de jour	*/
	byte heure;		/* heure		*/
	byte minute;		/* minute		*/
	byte seconde;		/* seconde		*/
} _PRL_LMDAT;
#pragma pack()
#define _PRL_MDAT_DEFINED
#endif


/* descripteur de retour de MEMO */

#ifndef _PRL_MEMO_DEFINED
#pragma pack(1)
typedef struct {
	byte mnemo[2];		/* mnemonique		*/
	word nb;		/* nombre d'unites      */
} _PRL_MEMO;
#pragma pack()
#define _PRL_MEMO_DEFINED
#endif


/* descripteur de PPOS */

#ifndef _PRL_PPOS_DEFINED
#pragma pack(1)
typedef struct {
	_PRL_RESS imp_prg;	/* implicite programme du poste        */
	_PRL_RESS imp_fic;	/* implicite fichier du poste	       */
	_PRL_RESS imp_imp;	/* implicite imprimante du poste       */
	word part;		/* taille de la partition mÇmoire      */
} _PRL_PPOS;
#pragma pack()
#define _PRL_PPOS_DEFINED
#endif


/* descripteur de STCS */

#ifndef _PRL_STCS_DEFINED
#pragma pack(1)
typedef struct {
	byte nb_lin;		/* nombre de lignes ecran		*/
	byte nb_col;		/* nombre de colonnes ecran		*/
	byte nb_sys;		/* nombre de colonnes ligne systeme	*/
	byte nb_prog;		/* nombre de touches programmables	*/
	byte curs_opt;		/* presence des fonctions curseur	*/
	byte atb_opt;		/* presence des attributs noir et blanc */
	byte coul;		/* indicateur gestion couleur		*/
	byte no_cons;		/* numero de console			*/
} _PRL_STCS;
#pragma pack()
#define _PRL_STCS_DEFINED
#endif


/* descripteur de ARTO et de DRTO */

#ifndef _PRL_ADRTO_DEFINED
#pragma pack(1)
typedef struct {
	byte evenement;
	word delai;
	void far *chainage;
} _MTZ_ADRTO;
#pragma pack()
#define _PRL_ADRTO_DEFINED
#endif


/* descripteur de HORL */

#ifndef _PRL_HORL_DEFINED
#pragma pack(1)
typedef struct {
	byte evenement;
	word delai;
} _MTZ_HORL;
#pragma pack()
#define _PRL_HORL_DEFINED
#endif


#ifndef _REGS_DEFINED

/* registres 16 bits */

struct WORDREGS {
	word ax, bx, cx, dx, si, di, cflag;
};


/* registres 8 bits */

struct BYTEREGS {
	byte al, ah, bl, bh, cl, ch, dl, dh;
};


/* union des registre 16 et 8 bits */

union REGS {
	struct WORDREGS x;
	struct BYTEREGS h;
};


/* registres de segment */

struct SREGS {
	word es, cs, ss, ds;
};

#define _REGS_DEFINED
#endif


/* definition des macros de decoupage d'un pointeur far */

#define FP_SEG(fp)	(*((unsigned *)&(fp) + 1))
#define FP_OFF(fp)	(*((unsigned *)&(fp)))


/* declaration des fonctions */

int int86(int, union REGS *, union REGS *);
word _mgm_alsm(word, word, void far **);
word _mgm_lbsm(void far *);
word _mgm_mdsm(void far *, word, word);
word _mgm_stsm(void far *, word, word, void far **, word *);
word _mgm_xtsm(void far *, word);
word _mtz_abqt(void);
word _mtz_acri(word, void (far *)(), word);
word _mtz_acti(word, void far *, word);
word _mtz_arto(_MTZ_ADRTO *);
word _mtz_cres(word, void (far *)(), word);
word _mtz_dmex(word);
word _mtz_drto(_MTZ_ADRTO *);
word _mtz_dsac(word);
void _mtz_evat(byte *);
void _mtz_evpr(byte far *, word);
void _mtz_exit(void);
void _mtz_fmex(word);
void _mtz_horl(_MTZ_HORL *);
word _mtz_npos(void);
void _mtz_prio(word);
void _mtz_razh(void);
void _mtz_reti(word);
word _mtz_supr(word);
word _mtz_wait(byte *);
void _mtz_wmul(void far *(*)[], word, word *, word *);
word _ngf_close(word);
word _ngf_creat(_PRL_ANFC *, word *, dword *);
word _ngf_extend(word, word);
word _ngf_getdd(word, byte *);
word _ngf_open(_PRL_ANFC *, word *, dword *);
word _ngf_patb(word, word);
word _ngf_putdd(word, byte *);
word _ngf_read(word, byte *, word, dword);
word _ngf_rename(word, _PRL_ANFC *);
word _ngf_unlink(_PRL_ANFC *);
word _ngf_write(word, byte *, word, dword);
word _ngf_xcreat(_PRL_ANFC *, word *, dword *);
word _ngf_xopen(_PRL_ANFC *, word *, dword *);
word _prl_anfc(byte *, _PRL_ANFC *, word *);
word _prl_call(union REGS *, union REGS *);
word _prl_chgp(_PRL_CHGTP *, word, void far **);
word _prl_chgt(_PRL_CHGTP *, word, void far **);
word _prl_ci(void);
word _prl_clav(byte *);
void _prl_co(word);
word _prl_col(void);
word _prl_dchgp(void far *);
word _prl_eder(word);
word _prl_edru(word, byte *);
word _prl_exec(_PRL_CHGTP *, byte *);
void _prl_intr(word);
word _prl_lcfo_char(word, byte *);
word _prl_lcfo_str(word, byte *, word);
word _prl_ldat(_PRL_LMDAT *);
word _prl_lin(void);
word _prl_lo(word);
word _prl_mdat(_PRL_LMDAT *);
word _prl_memo(word, _PRL_MEMO *);
void _prl_mes(byte *);
void _prl_pos(word, word);
word _prl_ppos(_PRL_PPOS *);
word _prl_prfo_char(word, byte);
word _prl_prfo_str(word, byte *, word);
word _prl_psys(_PRL_PSYS *);
word _prl_sf(word, void *, word *, word *);
word _prl_sf2(word, void *, word *, word *);
word _prl_stcs(_PRL_STCS *);
word _prl_tpci(void);
word _prl_tplo(void);
void segread(struct SREGS *);

