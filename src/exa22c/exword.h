/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987, 1992  Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXWORD - C				*/
/*		Version :	2.1d					*/
/*		Date 	:	11/04/1996				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXWORD_H
#define _EXWORD_H

#ifdef AIX
#define ABALSIGN
#endif
/*	Remarques :
 *	-----------
 *	Word storage varies from machine to machine.
 *	Word storage by the translator (TR) and executeur (EX) follows
 *	the rules set out below.
 *
 *	T-Code file storage of tables etc.
 *	----------------------------------
 *	Indirect 80x86 type storage		LOWB : HIGH
 *
 *	BAL Variables (DCL's)
 *	---------------------
 *	Direct 680xx type storage		HIGH : LOWB
 *
 *	Two selection switchs are provided to select the type of
 *	conversions neccessary.
 *
 *	IDIRECT	and 	EVENBOUND
 *	-------     	---------
 *	False		False		680xx type machines
 *	False		True		680xx type machines
 *	True		False		80x86 type machines
 *	True		True		Other type machines
 *	-------		---------
 *	Notes	:
 *	---------
 *	PROLOGUE,DOS,XENIX and UNIX/SYS		True / False
 *	Questar 700 (Unix)			False/ True
 */	    

/*
 *	Tcodeword ( Tx , Vx )
 *	---------------------
 *	The word pointed to by Tx is returned to the short integer Vx.
 *	Note : 	This solves word boundary problems for machines with
 *	 	direct (68000) type word storage or machines with 
 *		indirect (80x86) type word storage.
 *
 *	TcodePmot ( Tx , Vx )
 *	---------------------
 *	Stores the word Vx at the short integer location pointed to by
 *	the EXABYTE pointer Tx.
 *	Note : 	This solves word boundary problems for machines with
 *	 	direct (68000) type word storage or machines with 
 *		indirect (80x86) type word storage.
 */

#ifdef IDIRECT		/* Indirect word storage type 80x86	*/

#ifdef	EVENBOUND	/* Requires even alignement		*/

#define	Tcodeword( Tx )		((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 

#define	TcodePmot( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#define	balgetw( Tx )		((((EXAWORD) *Tx ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )) 
				

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#else			/* Doen't care about alignement		*/

#define Tcodeword( Tx )		*((WPTR) Tx)
#define TcodePmot( Tx , Vx  ) 	*((WPTR) Tx) = Vx
#define	balgetw( Tx )		((((EXAWORD) *((BPTR) (Tx) ) ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )) 
				

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#endif			/* IDIRECT treatments			*/


#else			/* Direct word storage type 680xx	*/


#define	Tcodeword( Tx )		((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 

#define	TcodePmot( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}
#ifdef EVENBOUND
#define	balgetw( Tx )		((((EXAWORD) *Tx ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )) 
				

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}
#else
#define balgetw( Tx )		*((WPTR) Tx)
#define balputw( Vx , Tx  ) 	*((WPTR) Tx) = Vx
#endif
#endif			/* IDIRECT / DIRECT selection		*/


/*	Signed character integer operations for RISC machines		*/
/*	-----------------------------------------------------		*/
#ifndef ABALSIGN
#define ReadSchar( ptr ) *((CPTR)(ptr))
#else
#define	ReadSchar( ptr ) (((*ptr & 0x80)== 0) ?  *((BPTR)(ptr)) : (((EXAWORD) *((BPTR)(ptr))) | 0xFF00))
#endif


/*	EXALONG <-> EXAWORD manipulations	*/
/*	---------------------------	*/

#define PLOWORD(l)       ((EXAWORD)(ULONG)(l))
#define PHIWORD(l)       ((EXAWORD)((((ULONG)(l)) >> 16) & 0xFFFF))
#define PULONG(low,high) ((ULONG)(((EXAWORD)(low)) | (((ULONG)((EXAWORD)(high))) << 16)))

#define	TcodeWord16(a) Tcodeword(a)
#define	TcodePmot16(a,b) TcodePmot(a,b)

#endif	/* _EXWORD_H */
	/* --------- */

