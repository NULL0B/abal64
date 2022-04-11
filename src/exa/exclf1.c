/*
 *	Trace Management Function :  integer arg, then string args  no result 
 *	---------------------------------------------------------------------
 *
 *	0) -	TRACE ON		( NO%, SECTIONKEY$, PRGID$ )
 *	1) -	TRACE OFF	( NO%  )
 *	2) -	TRACE PRINT	( NO%, LEVEL%, ID%, TITLE$, MSG$ ) 
 *	3) -	TRACE HEX	( NO%, LEVEL%, ID%, TITLE$, MSG$, ZONE$ )
 * 
 * le no 0 est réservé à Amenesik / Sologic
 * le no 1 est toujours activé à l'init (pas de TRACE ON nécessaire)
 * les autres sont à disposition des programmeurs
 * le mask1 et 2 ne sont pas utilisés (utilisation historique pour screener, pas util)
 */

#include "extrace.h"

#ifndef TRACEABAL
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// *** TRACEABAL OFF
// *** Fonctions vides. Aucun code n'est implémenté.
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
VOID		reset_trace_control() {}
EXAWORD	f_clf1( EXAWORD x) {return(GOODRESULT);}

#else
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************
// *** TRACEABAL ON
// ****************************************************************************
// ****************************************************************************
// ****************************************************************************

// Paramètres de la trace de base (n°1)
#define CI_TRABAL_MASTERKEY			"[ABAL]"
#define CI_TRABAL_PRG_ID				"ABAL"

#define mymin(a,b)  (((a) < (b)) ? (a) : (b))

// ****************************************************************************
// * Variables globales
// ****************************************************************************

// Contextes de trace
#define CI_TRACEABAL_MAX	17
TI_TRA_CTX CtxTraAbal[CI_TRACEABAL_MAX];

// ****************************************************************************
// * reset_trace_control
// * Called from main() of EXA to ensure all traces are off
// * except the default trace (n°1)
// ****************************************************************************
VOID	reset_trace_control()	
{	
	int	i;

	// Invalidation de toutes les traces
	for (i=0; i < CI_TRACEABAL_MAX; i++ ) 
		CtxTraAbal[i].On = 0;

	// Activation implicite de la trace 1
	MI_TRACTX_RESET(&CtxTraAbal[1],0,0,CI_TRABAL_MASTERKEY,CI_TRABAL_PRG_ID,0);	
}

// ****************************************************************************
// * f_clf1
// * Function group	CLF1 providing the new trace function stubs	
// ****************************************************************************
EXAWORD	f_clf1( EXAWORD x)
{
WORD		Level;
WORD		Id;
WORD		no;
BPTR		p;
EXAWORD	i;
static char  tmpPrg[5];		// 4  + \0
static char  tmpKey[83];	// 80 + [] et \0

// --- Remember begin of descriptors, then step over
p = fdex;
while ( *(fdex++) & 1 );

// --- Numéro de trace, avec contrôle de cohérence
i = *(p++);
if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
	return(SOFTERROR);
no = workval1;

if (no >= CI_TRACEABAL_MAX) 
	{
	err_val = 103;
	return( SOFTERROR );
	}

// --- Exécution de l'instruction
switch ( x ) 
	{
	case	0	: 
	case	5	: 
		// --- SET -------------------------------------------------------
		// syntaxe : SET,"<clé de section>","<mnémonique>"
		// syntaxe : SETMUTE,"<clé de section>","<mnémonique>"

		// Récupération des arguments
		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		// Encapsulation de la clé par []
		worklen1 = lenuze(workptr1,worklen1);
		worklen1 = mymin(sizeof(tmpKey)-3,worklen1);
		p = tmpKey;
		*p++ = '[';
		for (i=0 ; i<worklen1 ; i++)
			*p++ = workptr1[i];
		*p++ = ']';
		*p   = '\0';

		// Limitation de la taille du mnémonique
		worklen2 = lenuze(workptr2,worklen2);
		worklen2 = mymin(sizeof(tmpPrg)-1,worklen2);
		p = tmpPrg;
		for (i=0 ; i<worklen2 ; i++)
			*p++ = workptr2[i];
		*p = '\0';

		// Traitement
		MI_TRACTX_RESET(&CtxTraAbal[no],0,0,tmpKey,tmpPrg,(x==0) );	
		return( GOODRESULT );

	case	4	: 
	case	6	: 
		// --- SETDEF -------------------------------------------------------
		// syntaxe : SETDEF
		// syntaxe : SETDEFMUTE
		MI_TRACTX_RESET(&CtxTraAbal[no],0,0,CI_TRABAL_MASTERKEY,CI_TRABAL_PRG_ID,(x==4) );	
		return( GOODRESULT );

	case	1	:
		// --- OFF -------------------------------------------------------
		// syntaxe : OFF (non documenté)
		CtxTraAbal[no].On = 0;
		return( GOODRESULT );

	case	2	:
		// --- PRINT -----------------------------------------------------
		// syntaxe : PRINT,<niveau de trace>,<id>,"<titre>","<message>"

		// Récupération des arguments
		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Level = workval1;
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Id = workval1;

		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		// Traitement
		MI_TRACTX_MESSLG(&CtxTraAbal[no], Level, Id, workptr1, (WORD)lenuze(workptr1,worklen1), workptr2, (WORD)lenuze(workptr2,worklen2));
		return( GOODRESULT );
		
	case	3	:
		// --- DUMP ------------------------------------------------------
		// syntaxe : PRINT,<niveau de trace>,<id>,"<titre>","<message>","<zone de dump>"

		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Level = workval1;
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Id = workval1;

		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		if ( argset((i & 0x0006)>>1, 0, 3) == SOFTERROR) 
			return(SOFTERROR);

		// Traitement
		MI_TRACTX_DUMPLG(&CtxTraAbal[no], Level, Id, workptr1, (WORD)lenuze(workptr1,worklen1), workptr2, (WORD)lenuze(workptr2,worklen2), workptr3,(WORD)worklen3);
		return( GOODRESULT );

	default		:
		// --- pas glop -----------------------------------------------------
		err_val = 56;
		return( SOFTERROR );
	}
}

EXAWORD	f_clf1_old( EXAWORD x)
{
WORD		Level;
WORD		Id;
WORD		no;
BPTR		p;
EXAWORD	i;
static char  tmpPrg[5];		// 4  + \0
static char  tmpKey[83];	// 80 + [] et \0

// --- Numéro de trace, avec contrôle de cohérence
no = *(fdex++);
if (no >= CI_TRACEABAL_MAX) 
	{
	err_val = 103;
	return( SOFTERROR );
	}
else if ( no <= 0 ) 
	{
	err_val = 102;
	return( SOFTERROR );
	}

// --- Trace Accelerator pour les messages
if (  ((x==2) || (x==3))
	&& (!CtxTraAbal[no].On)
	)
	{
	// On saute le plus vite possible si la trace n'est pas activée
	i = Tcodeword(fdex);
	fdex += i;
	return( GOODRESULT );
	}
else
	{	
	// On continue l'exécution de l'instruction
	fdex += (WORDSIZE);
	}

// --- Step over descriptors
p = fdex;
while ( *(fdex++) & 1 );

// --- Exécution de l'instruction
switch ( x ) 
	{
	case	0	: 
	case	5	: 
		// --- SET -------------------------------------------------------
		// syntaxe : SET,"<clé de section>","<mnémonique>"
		// syntaxe : SETMUTE,"<clé de section>","<mnémonique>"

		// Récupération des arguments
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		if ( argset((i & 0x0006)>>1, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		// Encapsulation de la clé par []
		worklen1 = mymin(sizeof(tmpKey)-3,worklen1);
		p = tmpKey;
		*p++ = '[';
		for (i=0 ; i<worklen1 ; i++)
			*p++ = workptr1[i];
		*p++ = ']';
		*p   = '\0';

		// Limitation de la taille du mnémonique
		worklen2 = mymin(sizeof(tmpPrg)-1,worklen2);
		p = tmpPrg;
		for (i=0 ; i<worklen2 ; i++)
			*p++ = workptr2[i];
		*p = '\0';

		// Traitement
		MI_TRACTX_RESET(&CtxTraAbal[no],0,0,tmpKey,tmpPrg,(x==0) );	
		return( GOODRESULT );

	case	4	: 
	case	6	: 
		// --- SETDEF -------------------------------------------------------
		// syntaxe : SETDEF
		// syntaxe : SETDEFMUTE
		MI_TRACTX_RESET(&CtxTraAbal[no],0,0,CI_TRABAL_MASTERKEY,CI_TRABAL_PRG_ID,(x==4) );	
		return( GOODRESULT );

	case	1	:
		// --- OFF -------------------------------------------------------
		// syntaxe : OFF (non documenté)
		CtxTraAbal[no].On = 0;
		return( GOODRESULT );

	case	2	:
		// --- PRINT -----------------------------------------------------
		// syntaxe : PRINT,<niveau de trace>,<id>,"<titre>","<message>"

		// Récupération des arguments
		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Level = workval1;
		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Id = workval1;

		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		if ( argset((i & 0x0006)>>1, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		// Traitement
		MI_TRACTX_MESSLG(&CtxTraAbal[no],Level,Id,workptr1,(WORD)worklen1,workptr2,(WORD)worklen2);
		return( GOODRESULT );
		
	case	3	:
		// --- DUMP ------------------------------------------------------
		// syntaxe : PRINT,<niveau de trace>,<id>,"<titre>","<message>","<zone de dump>"

		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Level = workval1;
		if ( argset((i & 0x0006)>>1, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		Id = workval1;

		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 1) == SOFTERROR) 
			return(SOFTERROR);
		if ( argset((i & 0x0006)>>1, 0, 2) == SOFTERROR) 
			return(SOFTERROR);

		i = *(p++);
		if ( argset((i & 0x0060)>>5, 0, 3) == SOFTERROR) 
			return(SOFTERROR);

		// Traitement
		MI_TRACTX_DUMPLG(&CtxTraAbal[no],Level,Id,workptr1,(WORD)worklen1,workptr2,(WORD)worklen2,workptr3,(WORD)worklen3);
		return( GOODRESULT );

	default		:
		// --- pas glop -----------------------------------------------------
		err_val = 56;
		return( SOFTERROR );
	}
}

#endif


