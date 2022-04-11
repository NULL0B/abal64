/*---------------------------------------------------------------------------
 *
 *	Projet A.B.A.L.		-	Copyright Amenesik / Sologic s.a. (c) 1988,1989
 *
 *		 Definitions de la gestion des fichiers
 *			sequentiels indexes
 *
 *			(Longueur Variable)
 *
 *		      Revision 1.0 du 06/03/1989
 *
 * Modified : 04/09/1989	:	WordStore/Value via IDIRECT define
 *				:	(I.J.M.)
 * Modified : 03/10/1989	:	#define EBADSLT to catch siopen error
 *				:	(I.J.M.)
 * Modified : 27/10/1989	:	#define ENOLCK for Portage DPS 4000
 *
 *---------------------------------------------------------------------------*/

/* ------------------ */
/* #define C_ISAM_410 */
/* ------------------ */

#define FIRST_BYTE(word)	((word >> 8) & 0x00FF)
#define SECOND_BYTE(word)	(word & 0x00FF)

/*	---------------------------------------- 	*/
/*	Macros dependantes du processeur utilise 	*/
/*	---------------------------------------- 	*/

#ifdef x8086
/*	Indirect Word Storage : INTEL NSC VAX etc 	*/
/* 	-----------------------------------------	*/
#define WORDSTORE(adr,exp) { *(unsigned short int *) adr = exp; }
#define WORDVALUE(adr) (*(short unsigned int *) adr)
#else
/*	Direct Word Storage   : MOTOROLA , RISC etc	*/
/*	-------------------------------------------	*/
unsigned short int ZZZ_;
#define WORDSTORE(adr,exp) {ZZZ_ = exp; \
	memcpy((unsigned char *) adr,(unsigned char *) &ZZZ_,2);\
}
#define WORDVALUE(adr) (*(short unsigned int *)  memcpy((unsigned char *) &ZZZ_,(unsigned char *) adr, 2))
#endif

/*	File Constants which may not be defined		*/
/*	---------------------------------------		*/
#ifndef	SEEK_SET
#define	SEEK_SET	0
#endif

#ifndef	SEEK_END
#define	SEEK_END	2
#endif

#define BOOL	int
#define TRUE	1
#define FALSE	0
#define SUCCESS 0
#define MAX_FILE_ASSIGN	64
#define	ABAL_CISAM_IDX ".idx"
#define	ABAL_CISAM_DAT ".dat"
#define	ABAL_TIRET_I   "-I"
#define SI_CREATE_PERM 0666

/*	Table descriptive des fichiers SI		*/
/*	---------------------------------		*/

struct  {
#ifdef  C_ISAM_410
	int  last_error;	/* Derneir error UP/Down        */
#endif
	BOOL used;		/* entree utilisee ? 		*/
	BOOL ex;		/* exclusif oui/non 		*/
	int  modisam;		/* ISINOUT, ...			*/	
	unsigned char type;	/* K,LK,RK			*/
	BOOL blocked;		/* TRUE si dernier enr. bloque	*/
	int  fildes;		/* Numero interne fildes isam	*/
	int  lgcle;		/* Longueur des cles		*/
	int  lgdonnees;		/* Longueur des donnees		*/
	int  lgtotale;		/* Longueur enregistrement isam */
	BOOL flag_err;		/* flag DOWN precedent a echoue */
        int  flag_posit;        /* indicateur du posit sur index secondaire */
	char *rec;		/* adresse zone tampon		*/
	BOOL flag_LV;		/* flag longueur variable */
	int  lvfildes;		/* numero interne fichier -LV */
	char *fnomptr;		/* Nom du fichier pour si_matb 44 Check */
	} tabsi[MAX_FILE_ASSIGN];


struct keydesc keybal;		/* info cles */
struct dictinfo info;		/* info generales */

extern char *malloc();

extern	long	SystemError;

/* 	Functions offered by the interface with ACCESS in EXACCESS.OBJ 	*/
/* 	-------------------------------------------------------------- 	*/
extern int Access();
extern void liberlox();
extern void PurgeLox();
extern int matb();
	
/*	Fonctions internes		*/
/*	------------------		*/

void si_init();
void si_fin();
short int si_open();
int si_matb();
int si_close();
short int si_create();
int si_unlink();
int si_rename();
int si_up();
int si_down();
int up_down();
int si_insert();
int si_modif();
int si_search();
int si_delete();
int si_readzc();
int si_writezc();

void traitfilerror();
void cadrer_cle();
int fichier_inf();
int deblock();
int getentry();
int verif_nlsi();

#ifndef	EBADSLT
					/* ----------------------------- */
#define	EBADSLT	55			/* Error read() .idx in isopen() */
					/* ----------------------------- */
#endif

#ifndef	ENOLCK
					/* --------------------------- */
#define	ENOLCK	46			/* Error NO Locks for DPS 4000 */
					/* --------------------------- */
#endif
