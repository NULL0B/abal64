/* Bibliotheque mathematique
 *
 * Mises a jour :
 *	20/12/90 : adaptation a VMS
 *	18/03/91 : modifications style d'ecriture
 *	04/04/91 : banniere rendue traductible
 *	16/04/91 : mention de copyright
 *	07/08/91 : ignore les pertes partielles de precision
 *		   traite la variable errno partout
 *	12/08/91 : conserve une trace de toutes les requetes dans un fichier
 *		   journal (si JOURNAL est defini)
 *	03/10/91 : utilise la longueur du resultat pour l'affichage dans
 *		   le fichier journal
 *	04/10/91 : accepte le . et la , comme separateur decimal
 *	18/11/91 : definition de errno pour MSDOS et PROLOGUE
 *	20/01/92 : BULL : detecte argument incorrect pour SQR et LOG
 *	02/02/93 : passage en 1.1c : generalisation de l'option Bull et
 *		   option PLOSS selon existence ou non.
 *		   source commun a tous les OS. Traitement probleme de
 *		   localisation sous Unix (. ou exclusif , accepte pour atof)
 */


#include	<stdio.h>
#include	<math.h>
#include	<string.h>
#include	<errno.h>
#include	"bda.h"

extern DOUBLE atof();


/* Definition du nombre de fonctions de la bibliotheque */
#define	MAXFCT	7


/* Definitions generales */
#define	BCD_SEP		0x0a
#define	BCD_FIN		0x0f
#define	BCD_PLUS	0xc0
#define	BCD_MOINS	0xb0
#define Xisnan(x)	FALSE		/* isnan(x) */

#define	GLOBAL BDA_GLOBAL
#define	GN(a) 0
/* Variables globales */
GLOBAL BDA desrt;
#ifdef JOURNAL
static int Hjournal = -1;
static DWORD noreq = 1L;
#endif
BYTE DecimalSeparator;


/* Variables externes */
extern BDA_INIT FAR PTR rt_init;
extern BDA_ARG rt_arg;

#ifdef msdos
extern int errno;
#endif
#ifdef dosext
extern int errno;
#endif
#ifdef prologue
extern int errno;
#endif


/* ------------------------------------------------------------------ */
/*			PROTOTYPAGE DES FONCTIONS		      */
/* ------------------------------------------------------------------ */
#ifdef LINT_ARGS
/* Definition des fonctions de la bibliotheque */
VOID FAR mysin(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR mycos(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR mytan(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR myatn(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR mysqr(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR myexp(BYTE FAR PTR,BYTE FAR PTR);
VOID FAR mylog(BYTE FAR PTR,BYTE FAR PTR);

#ifdef FCT_ENTETE
VOID FAR PASCAL _mysin(VOID FAR PTR FAR []);
VOID FAR PASCAL _mycos(VOID FAR PTR FAR []);
VOID FAR PASCAL _mytan(VOID FAR PTR FAR []);
VOID FAR PASCAL _myatn(VOID FAR PTR FAR []);
VOID FAR PASCAL _mysqr(VOID FAR PTR FAR []);
VOID FAR PASCAL _myexp(VOID FAR PTR FAR []);
VOID FAR PASCAL _mylog(VOID FAR PTR FAR []);
#endif /* FCT_ENTETE */

/* Definition des fonctions internes */
VOID FAR PTR InitRelais(VOID);
static DOUBLE bcd2fl(BYTE FAR PTR);
static VOID fl2bcd(DOUBLE,BYTE FAR PTR);
static VOID buf2bcd(BYTE PTR,BYTE FAR PTR);
static VOID FAR banniere(VOID);

#ifdef JOURNAL
static VOID JournalInsert1(BYTE PTR,BYTE FAR PTR,DOUBLE);
static VOID JournalInsert2(BYTE FAR PTR,DOUBLE);
static VOID finbib(VOID);
#endif /* JOURNAL */

/* Definition des fonctions externes */
extern VOID rt_error(EXAWORD);

#else /* LINT_ARGS */

/* Definition des fonctions de la bibliotheque */
VOID FAR mysin();
VOID FAR mycos();
VOID FAR mytan();
VOID FAR myatn();
VOID FAR mysqr();
VOID FAR myexp();
VOID FAR mylog();

#ifdef FCT_ENTETE
VOID FAR PASCAL _mysin();
VOID FAR PASCAL _mycos();
VOID FAR PASCAL _mytan();
VOID FAR PASCAL _myatn();
VOID FAR PASCAL _mysqr();
VOID FAR PASCAL _myexp();
VOID FAR PASCAL _mylog();
#endif /* FCT_ENTETE */

/* Definition des fonctions internes */
VOID FAR PTR InitRelais();
static DOUBLE bcd2fl();
static VOID fl2bcd();
static VOID buf2bcd();
static VOID FAR banniere();

#ifdef JOURNAL
static VOID JournalInsert1();
static VOID JournalInsert2();
static VOID finbib();
#endif /* JOURNAL */

/* Definition des fonctions externes */
extern VOID rt_error();
#endif /* LINT_ARGS */


/* ------------------------------------------------------------------ */
/*		FONCTIONS D'ENTETE POUR UNIX ET VMS		      */
/* ------------------------------------------------------------------ */
#ifdef FCT_ENTETE

VOID FAR PASCAL _myatn(a)
VOID FAR PTR FAR a[];
{
	myatn((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _mycos(a)
VOID FAR PTR FAR a[];
{
	mycos((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _myexp(a)
VOID FAR PTR FAR a[];
{
	myexp((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _mylog(a)
VOID FAR PTR FAR a[];
{
	mylog((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _mysin(a)
VOID FAR PTR FAR a[];
{
	mysin((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _mysqr(a)
VOID FAR PTR FAR a[];
{
	mysqr((unsigned char *)a[0], (unsigned char *)a[1]);
}

VOID FAR PASCAL _mytan(a)
VOID FAR PTR FAR a[];
{
	mytan((unsigned char *)a[0], (unsigned char *)a[1]);
}
#endif /* FCT_ENTETE */


/* ------------------------------------------------------------------ */
/*		TEST ERREURS MATHEMATIQUES POUR VMS		      */
/* ------------------------------------------------------------------ */
#define _ERRNO_PREP	{ errno = 0; \
			}
#define _ERRNO_STAT	{ if ((errno != 0) || (Xisnan(x)))\
				(void) matherr((struct exception *)NULL);\
			}

#ifdef JOURNAL
#define _JOURNAL_PREP(a)	{ JournalInsert1(a,vars,x); \
				}
#define _JOURNAL_STAT		{ JournalInsert2(vard,x); \
				}
#else
#define _JOURNAL_PREP(a)	{}
#define _JOURNAL_STAT		{}
#endif


/* ------------------------------------------------------------------ */
/*		INITIALISATION DE LA BIBLIOTHEQUE		      */
/* ------------------------------------------------------------------ */
VOID FAR PTR InitRelais()
{ if (rt_init != (VOID FAR PTR) 0L)
	rt_init->ordinaire.signature = BDA_ORDINAIRE;

  desrt.banniere = (VOID (FAR PTR)()) banniere;
#ifdef JOURNAL
  desrt.fin = (VOID (FAR PTR)()) finbib;
#else
  desrt.fin = (VOID (FAR PTR)()) 0L;
#endif /* JOURNAL */

#ifdef vms
#else
  desrt.reserve = NULL;
#endif /* vms */

  desrt.nombre = MAXFCT;		/* description des fonctions */

#ifdef vms
  desrt.nom[0] = (BYTE PTR ) "_myatn";			/* VMS */
  desrt.nom[1] = (BYTE PTR ) "_mycos";
  desrt.nom[2] = (BYTE PTR ) "_myexp";
  desrt.nom[3] = (BYTE PTR ) "_mylog";
  desrt.nom[4] = (BYTE PTR ) "_mysin";
  desrt.nom[5] = (BYTE PTR ) "_mysqr";
  desrt.nom[6] = (BYTE PTR ) "_mytan";

#else /* vms */

#ifdef FCT_ENTETE
#ifdef dosext
  desrt.fonction[0] = (VOID (FAR PTR)()) _myatn;	/* DOS ETENDU */
  desrt.fonction[1] = (VOID (FAR PTR)()) _mycos;
  desrt.fonction[2] = (VOID (FAR PTR)()) _myexp;
  desrt.fonction[3] = (VOID (FAR PTR)()) _mylog;
  desrt.fonction[4] = (VOID (FAR PTR)()) _mysin;
  desrt.fonction[5] = (VOID (FAR PTR)()) _mysqr;
  desrt.fonction[6] = (VOID (FAR PTR)()) _mytan;

#else /* dosext */

  desrt.fonction[0] = _myatn;				/* UNIX */
  desrt.fonction[1] = _mycos;
  desrt.fonction[2] = _myexp;
  desrt.fonction[3] = _mylog;
  desrt.fonction[4] = _mysin;
  desrt.fonction[5] = _mysqr;
  desrt.fonction[6] = _mytan;
#endif /* dosext */

#else /* FCT_ENTETE */

  desrt.fonction[0] = (VOID (FAR PTR)()) myatn;		/* PROLOGUE et MS/DOS */
  desrt.fonction[1] = (VOID (FAR PTR)()) mycos;
  desrt.fonction[2] = (VOID (FAR PTR)()) myexp;
  desrt.fonction[3] = (VOID (FAR PTR)()) mylog;
  desrt.fonction[4] = (VOID (FAR PTR)()) mysin;
  desrt.fonction[5] = (VOID (FAR PTR)()) mysqr;
  desrt.fonction[6] = (VOID (FAR PTR)()) mytan;

#endif /* FCT_ENTETE */
#endif /* vms */


  /* Recherche le separateur decimal (pour eviter les problemes
   * de localisation des versions d'unix.
   */
  { BYTE buf[64];
    WORD i;

	sprintf(&buf[0],"%f",(double)1.25);
	DecimalSeparator = '.';

	for (i=0 ; i<64 ; i++) {
		/* Teste la fin du buffer de conversion */
		if (buf[i] == '\0') break;

		/* Autorise , et . comme separateur decimal */
		if ((buf[i] == '.') || (buf[i] == ',')) {
			DecimalSeparator = buf[i];
			break;
		}
	}
  }

  return((VOID FAR PTR) &desrt);
}

/* ------------------------------------------------------------------ */
/*		INTERFACE ABAL - FONCTIONS MATHEMATIQUES	      */
/* ------------------------------------------------------------------ */
VOID FAR mysin(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("sin")
  _ERRNO_PREP
  x = sin(x);
  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR mycos(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("cos")
  _ERRNO_PREP
  x = cos(x);
  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR mytan(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("tan")
  _ERRNO_PREP
  x = tan(x);
  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR myatn(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("atn")
  _ERRNO_PREP
  x = atan(x);
  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR mysqr(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("sqr")
  _ERRNO_PREP

  if (x < 0.0)			/* evite plantages sous BULL */
	errno = 108;
  else
	x = sqrt(x);

  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR myexp(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("exp")
  _ERRNO_PREP
  x = exp(x);
  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

VOID FAR mylog(vard,vars)
BYTE FAR PTR vard;
BYTE FAR PTR vars;
{ DOUBLE x;

  x = bcd2fl(vars);
  _JOURNAL_PREP("log")
  _ERRNO_PREP

  if (x <= 0.0)				/* evite plantage sous Bull */
	errno = 108;
  else
	x = log(x);

  _ERRNO_STAT
  fl2bcd(x,vard);
  _JOURNAL_STAT
}

/* ------------------------------------------------------------------ */
/*		CORPS DE LA BIBLIOTHEQUE MATHEMATIQUE		      */
/* ------------------------------------------------------------------ */

/* Conversion flottant -> ASCII */
/* ---------------------------- */

static VOID fl2bcd(fl,var)
DOUBLE fl;
BYTE FAR PTR var;
{ BYTE buf[500];

  sprintf(&buf[0],"%-+.25f",fl);
  buf2bcd(&buf[0],var);
}


/* Conversion ASCII -> BCD */
/* ----------------------- */

static VOID buf2bcd(p1,var)
BYTE PTR p1;
BYTE FAR PTR var;
{ BYTE c;
  BYTE FAR PTR p2;
  BYTE digit;
  WORD lg;
  BYTE PTR fin;

#ifdef DEBUG
  printf("\r\nRES=%s",p1);
#endif

  /* Recherche de la fin logique de la representation ASCII du flottant */
  fin = p1+strlen(p1);
  while (((c = *--fin) == '0') && (fin != p1)) ;
  *++fin = '\0';

#ifdef DEBUG
  printf("\r\nREC=%s",p1);
#endif

  /* Pose le signe */
  p2 = var;
  digit = (*p1 == '-') ? (BCD_MOINS) : (BCD_PLUS);

  /* Saute le signe : normalement present sauf sous
   * Amenesik / Sologic en raison d'un bug de la bibli C 2.1b
   */
  if ((*p1 == '+') || (*p1 == '-'))
	p1++;

  /* Pose le premier chiffre ou la virgule */
  c = *p1;
  if ((c == '0') && ((*(p1+1) == '.') || (*(p1+1) == ','))) {
	digit = digit | (BYTE) BCD_SEP;
	p1++;
  }
  else {
	digit = digit | (BYTE) (c - '0');
  }
  p1++;
  *p2++ = digit;

  /* Pose la fin du nombre */
  lg = 2;
  digit = 0;
  while ((c = *p1) != '\0') {
	c = ((c == '.') || (c == ',')) ? (BCD_SEP) : (c - '0');
	lg++;
	if (!(lg%2)) {
		digit = digit | (BYTE) c;
		*p2++ = digit;
		digit = 0;
	}
	else {
		digit = ((BYTE) c) << 4;
	}
	p1++;
  }
  if (lg%2) {
	digit = digit | BCD_FIN;
	*p2 = digit;
	lg++;
  }
  else {
	*p2 = (BCD_FIN << 4);
	lg += 2;
  }

#ifdef DEBUG
  { int i;
    char cc;
#define fonconv(x) ((x < 10) ? (x+'0') : (x-10+'A'))

    printf("\r\nREB=");
    for (i=0 ; i<12 ; i++) {
	cc = *(var+i);
	printf("%c%c",fonconv(((cc & 0xf0)>>4)),fonconv((cc & 0x0f)));
    }
  }
#endif

}


/* Conversion BCD -> flottant */
/* -------------------------- */

static DOUBLE bcd2fl(var)
BYTE FAR PTR var;
{ BYTE buf[50];
  DOUBLE x;
  BYTE c;
  BYTE FAR PTR p1;
  WORD flag,p2;
  WORD lg;

  lg = *(rt_arg.l+1);

#ifdef DEBUG
  printf("\r\n\n\n");
  printf("\nLGR=%d",lg);

  { int i;
    char cc;
#define fonconv(x) ((x < 10) ? (x+'0') : (x-10+'A'))

    printf("\r\nENT=");
    for (i=0 ; i<lg*2 ; i++) {
	cc = *(var+i);
	printf("%c%c",fonconv(((cc & 0xf0)>>4)),fonconv((cc & 0x0f)));
    }
  }
#endif

  p1 = var;
  c = *p1++;

  /* Pose le signe */
  buf[0] = ((c & 0xf0) == BCD_MOINS) ? '-' : '+';

  /* Pose soit le separateur decimal, soit le premier chiffre */
  c = (c & 0x0f);
  if (c == BCD_SEP) {
	buf[1] = '0';
	buf[2] = DecimalSeparator;
	p2 = 3;
  }
  else {
	buf[1] = c + '0';
	p2 = 2;
  }
  lg--;

  /* Traite la fin du nombre */
  flag = 0;
  while ((c != BCD_FIN) && (lg)) {
	if (!flag) {
		c = *p1;
		flag = 1;
		c = (c & 0xf0) >> 4;
	}
	else {
		c = *p1++;
		flag = 0;
		c = c & 0x0f;
		lg--;
	}

	switch (c) {
		case BCD_SEP :
			buf[p2] = DecimalSeparator;
			break;

		case BCD_FIN :
			buf[p2] = '\0';
			break;

		default :
			buf[p2] = c + '0';
			break;
	}
	p2++;
  }
  buf[p2] = '\0';

  x = atof(&buf[0]);

#ifdef DEBUG
  printf("\r\nBUF=%s\r\n FL=%-+.25f\r\n",&buf[0],x);
#endif

  return(x);
}


/* ------------------------------------------------------------------ */
/*			DEBORDEMENTS ARITHMETIQUES		      */
/* ------------------------------------------------------------------ */
int matherr(probleme)
struct exception *probleme;
{
#ifdef JOURNAL
  BYTE buf[256];
#endif

#ifdef DEBUGNEMAUSIC
  if (probleme == GN(struct exception)) {
	printf("\n\r\n\n\n\n\n\n\ntype   : ERRNO");
	printf("\n\rerrno  = %d",errno);
#ifdef JOURNAL
	/* Insertion dans le journal de la cause de l'erreur */
	if (Hjournal != -1) {
		sprintf(&buf[0]," -> ERRNO=%d",errno);
		(void) write(Hjournal,&buf[0],strlen(&buf[0]));
	}
#endif

  }
  else {
	printf("\n\r\n\n\n\n\n\n\ntype   : %d",probleme->type);
	printf("\n\rname   : %s",probleme->name);
	printf("\n\rarg1   = %g",probleme->arg1);
	printf("\n\rarg2   = %g",probleme->arg2);
	printf("\n\rretval = %g",probleme->retval);
	sleep(5);
#ifdef JOURNAL
	/* Insertion dans le journal de la cause de l'erreur */
	if (Hjournal != -1) {
		sprintf(&buf[0]," -> EXCEPTION");
		(void) write(Hjournal,&buf[0],strlen(&buf[0]));
		sprintf(&buf[0],"\n   type:%d\n   arg1:%g\n   arg2:%g\n   retv:%g",
			probleme->type,probleme->arg1,probleme->arg2,probleme->retval);
		(void) write(Hjournal,&buf[0],strlen(&buf[0]));
	}
#endif
  }
#endif

  /* Ignore les pertes partielles de precision */
#ifdef PLOSS
  if ((probleme != GN(struct exception)) && (probleme->type == PLOSS))
	return(1);
#endif

  rt_error(108);
}

/* ------------------------------------------------------------------ */
/*			TENUE DU JOURNAL			      */
/* ------------------------------------------------------------------ */
#ifdef JOURNAL
static VOID JournalInsert1(libelle,vbcd,vdou)
BYTE PTR libelle;
BYTE FAR PTR vbcd;
DOUBLE vdou;
{
  WORD lg;
  BYTE buf[256];
  WORD i;

	/* Creation du fichier journal s'il n'existe pas */
	if (Hjournal == -1) {
		Hjournal = creat("/tmp/bibmath.log",0666);
		if (Hjournal == -1)
			return;
	}

	/* Insertion du libelle */
	sprintf(&buf[0],"\n\n-------------------- Appel no %ld ------------------\nArg = %s(BCD:",
	        noreq,libelle);
	noreq++;
	(void) write(Hjournal,&buf[0],strlen(&buf[0]));

	/* Insertion de la representation BCD de l'argument */
	lg = *(rt_arg.l+1);
	for (i=0 ; i<lg ; i++) {
		sprintf(&buf[0],"%0.2X",*(vbcd+i));
		(void) write(Hjournal,&buf[0],strlen(&buf[0]));
	}

	/* Insertion de la valeur flottante de l'argument */
	sprintf(&buf[0]," , FL:%-+.25f)",vdou);
	(void) write(Hjournal,&buf[0],strlen(&buf[0]));
}

static VOID JournalInsert2(vbcd,vdou)
BYTE FAR PTR vbcd;
DOUBLE vdou;
{
  BYTE buf[256];
  WORD i;
  WORD lg;

	/* Verifie que le fichier est cree */
	if (Hjournal == -1)
		return;

	/* Insertion de la valeur flottante du resultat */
	sprintf(&buf[0],"\nRes = FL:%-+.25f , BCD:",vdou);
	(void) write(Hjournal,&buf[0],strlen(&buf[0]));

	/* Insertion de la representation BCD du resultat */
	lg = *(rt_arg.l);
	for (i=0 ; i<lg ; i++) {
		sprintf(&buf[0],"%0.2X",*(vbcd+i));
		(void) write(Hjournal,&buf[0],strlen(&buf[0]));
	}
}

static VOID finbib()
{
	/* Fermeture du fichier journal */
	if (Hjournal != -1)
		close(Hjournal);
}
#endif

/* ------------------------------------------------------------------ */
/*			BANNIERE DE LA BIBLIOTHEQUE		      */
/* ------------------------------------------------------------------ */
/* Identification de la bibliotheque */

static char ban[]="*STX*3BIBMATH 11c00\0Bibliotheque de fonctions mathematiques\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0*ETX*";

static VOID FAR banniere()
{ printf("\n   %s",&ban[20]);
  printf(" - Version 2.1f");
#ifdef PROV
  printf("\n   Provisoire du 15/05/1999");
#endif
#ifdef DEBUGNEMAUSIC
  printf("\n   --> Affichage a l'ecran des erreurs 108 <---");
#endif
#ifdef JOURNAL
  printf("\n   --> Appels enregistres dans le fichier /tmp/bibmath.log <--");
#endif
  printf("\n   Copyright (c) 1990, 2006 Amenesik / Sologic ");
#ifdef unix
  printf("\n");
#endif
}

