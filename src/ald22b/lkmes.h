#ifndef __LKMES_H__
#define __LKMES_H__

/*------------------------------------------------------------- LKMES.HE ------
 *
 *	Editeur de liens A.B.A.L.	-   Copyright Amenesik / Sologic s.a. (c) 1993
 *
 *			Declaration des variables publiques 
 *			Declaration des variables et procs. externes
 *
 *			      Creation 2.0 le 07/04/1993
 *
 * Revisions :
 *	
 *
 *---------------------------------------------------------------------------*/


/* Messages non traduisibles */

#define fieldm			"Field=m :"
#define fielde 		"Field=e :"
#define MesConst		"Const   :"


/********************************/

#ifdef _LKMES
	#undef PRIMITIVE
	#define PRIMITIVE

//		#define DECLARE_MESSAGE(ID,INDEX) WORD ID = INDEX;
#else
	#undef PRIMITIVE
	#define PRIMITIVE extern

//		#define DECLARE_MESSAGE(ID,INDEX) extern WORD ID;
#endif

/********************************/

#ifdef LINT_ARGS

	PRIMITIVE VOID MesInitTab( VOID );
	PRIMITIVE VOID MesVerifTcode( Entete XPTR * );
	PRIMITIVE VOID Banniere ( VOID );
	PRIMITIVE char XPTR * GetMessageLine (int Index);
	PRIMITIVE int GetMessageLevel (int Index);

#else 	/* LINT_ARGS */

	PRIMITIVE VOID MesInitTab();
	PRIMITIVE VOID MesVerifTcode();
	PRIMITIVE VOID Banniere();
	PRIMITIVE char XPTR * GetMessageLine ();
	PRIMITIVE int GetMessageLevel ();

#endif  /* LINT_ARGS */

/********************************/


#include "lkmes.hg"

#endif	/* __LKMES_H__ */






