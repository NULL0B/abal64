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

#define	WORD16SIZE 2
#define	WORD32SIZE 4
#ifdef	ABAL64
#define	WORD64SIZE 8
#endif

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
			/* 		LB HB 			*/

#ifdef	EVENBOUND	/* Requires even alignement		*/

#define	TcodeWord16( Tx )	((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 
#define	TcodeWord32( Tx )	( (((EXAWORD) *(Tx+3) ) << 24) | (((EXAWORD) *(Tx+2) ) << 16) | (((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 
#ifdef	ABAL64
#define	TcodeWord64( Tx )	( (((EXAWORD) *(Tx+7) ) << 56) | (((EXAWORD) *(Tx+6) ) << 48) | (((EXAWORD) *(Tx+5) ) << 40) | (((EXAWORD) *(Tx+4) ) << 32)  | (((EXAWORD) *(Tx+3) ) << 24) | (((EXAWORD) *(Tx+2) ) << 16) | (((EXAWORD) *(Tx+1) ) <<  8) | (((EXAWORD) *(Tx  ) )      ) ) 
#define Tcodeword( TcW ) 	( WORDSIZE == WORD32SIZE ? (TcodeWord32(TcW)) : ( WORDSIZE == WORD16SIZE ? (TcodeWord16(TcW)) : (TcodeWord64(TcW))) )
#else
#define	Tcodeword( TcW )	( WORDSIZE == WORD32SIZE ? (TcodeWord32(TcW)) : (TcodeWord16(TcW)))
#endif

#define	TcodeSignedShort( Tx )	((signed short)((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) ))) 
#define	TcodeSignedLong( Tx )	((signed long )( (((EXAWORD) *(Tx+3) ) << 24) | (((EXAWORD) *(Tx+2) ) << 16) | (((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) ))) 

#ifdef	ABAL64
#define	TcodeSignedHuge( Tx )	( (((signed long long) *(Tx+7) ) << 56) | (((signed long long) *(Tx+6) ) << 48) | (((signed long long) *(Tx+5) ) << 40) | (((signed long long) *(Tx+4) ) << 32)  | (((signed long long) *(Tx+3) ) << 24) | (((signed long long) *(Tx+2) ) << 16) | (((signed long long) *(Tx+1) ) <<  8) | (((signed long long) *(Tx  ) )      ) ) 
#define	TcodeInteger( TcW )	( WORDSIZE == WORD32SIZE ? ((BINAIRE)(TcodeSignedLong(TcW))) : ( WORDSIZE == WORD16SIZE ? ((BINAIRE)(TcodeSignedShort(TcW))) : ((BINAIRE)(TcodeSignedHuge(TcW)))) )
#else
#define	TcodeInteger( TcW )	( WORDSIZE == WORD32SIZE ? ((BINAIRE)(TcodeSignedLong(TcW))) : ((BINAIRE)(TcodeSignedShort(TcW))))
#endif

#ifdef	ABAL64
#define	TcodePmot64( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				*((BPTR) (Tx + 2)) = (EXABYTE) (( Vx & 0xFF0000) >> 16);\
				*((BPTR) (Tx + 3)) = (EXABYTE) (( Vx & 0xFF000000) >> 24);\
				*((BPTR) (Tx + 4)) = (EXABYTE) (( Vx & 0xFF00000000) >> 32);\
				*((BPTR) (Tx + 5)) = (EXABYTE) (( Vx & 0xFF0000000000) >> 40);\
				*((BPTR) (Tx + 6)) = (EXABYTE) (( Vx & 0xFF000000000000) >> 48);\
				*((BPTR) (Tx + 7)) = (EXABYTE) (( Vx & 0xFF00000000000000) >> 56);\
				}
#endif
#define	TcodePmot32( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				*((BPTR) (Tx + 2)) = (EXABYTE) (( Vx & 0xFF0000) >> 16);\
				*((BPTR) (Tx + 3)) = (EXABYTE) (( Vx & 0xFF000000) >> 24);\
				}

#define	TcodePmot16( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#ifdef	ABAL64
#define TcodePmot( TxW , VxW ) 	{\
				if ( WORDSIZE == WORD16SIZE )\
				{ TcodePmot16(TxW,VxW); }\
				else if ( WORDSIZE == WORD32SIZE )\
				{ TcodePmot64(TxW,VxW);	}\
				else { TcodePmot32(TxW,VxW); }\
				}
#else
#define TcodePmot( TxW , VxW ) 	{\
				if ( WORDSIZE == WORD16SIZE )\
				{ TcodePmot16(TxW,VxW); }\
				else { TcodePmot32(TxW,VxW); }\
				}
#endif

#define	balgetw( Tx )		((BINAIRE)((signed short)((((EXAWORD) *Tx ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )))) 
			

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#define	balgetl( Tx )		((((EXAWORD) *((BPTR)Tx) )    << 24) |\
			         (((EXAWORD) *((BPTR)(Tx+1))) << 16) |\
                                 (((EXAWORD) *((BPTR)(Tx+2))) <<  8) |\
                                 (((EXAWORD) *((BPTR)(Tx+3)))) ) 

#define	balputl( Vx , Tx )	{\
				*((BPTR) (Tx + 3)) = (EXABYTE) ( Vx        & 0x00FF );\
				*((BPTR) (Tx + 2)) = (EXABYTE) ((Vx >>  8) & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) ((Vx >> 16) & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) ((Vx >> 24) & 0x00FF );\
				}
#ifdef	ABAL64
#define	balgeth( Tx )		( (((EXAWORD) *((BPTR)Tx) )    << 56) | (((EXAWORD) *((BPTR)(Tx+1))) << 48) | (((EXAWORD) *((BPTR)(Tx+2))) << 40) | (((EXAWORD) *((BPTR)(Tx+3))) << 32) | (((EXAWORD) *((BPTR)(Tx+4))) << 24) | (((EXAWORD) *((BPTR)(Tx+5))) << 16) | (((EXAWORD) *((BPTR)(Tx+6))) <<  8) | (((EXAWORD) *((BPTR)(Tx+7))))) 

#define	balputh( Vx , Tx )	{\
				*((BPTR) (Tx + 7)) = (EXABYTE) ( Vx        & 0x00FF );\
				*((BPTR) (Tx + 6)) = (EXABYTE) ((Vx >>  8) & 0x00FF );\
				*((BPTR) (Tx + 5)) = (EXABYTE) ((Vx >> 16) & 0x00FF );\
				*((BPTR) (Tx + 4)) = (EXABYTE) ((Vx >> 24) & 0x00FF );\
				*((BPTR) (Tx + 3)) = (EXABYTE) ((Vx >> 32) & 0x00FF );\
				*((BPTR) (Tx + 2)) = (EXABYTE) ((Vx >> 40) & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) ((Vx >> 48) & 0x00FF );\
				*((BPTR) (Tx    )) = (EXABYTE) ((Vx >> 56) & 0x00FF );\
				}
#endif

#else			/* Doen't care about alignement		*/

/*	The current 32 bit work area */

#define	TcodeWord16( Tx )	((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 
#ifdef	ABAL64
#define	TcodeWord32( Tx )	((EXAWORD) *((I32PTR) Tx))
#define	TcodeWord64( Tx )	((EXAWORD) *((WPTR) Tx))
#define Tcodeword( TcW ) ( WORDSIZE == WORD32SIZE ? (TcodeWord32(TcW)) : ( WORDSIZE == WORD16SIZE ? (TcodeWord16(TcW)) : (TcodeWord64(TcW))) ) 
#else
#define	TcodeWord32( Tx )	((EXAWORD) *((WPTR) Tx))
#define	Tcodeword( TcW )	( WORDSIZE == WORD32SIZE ? (TcodeWord32(TcW)) : (TcodeWord16(TcW)))
#endif

#define	TcodeSignedShort( Tx )	((signed short)((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) ))) 
#ifdef	ABAL64
#define	TcodeSignedLong( Tx )	((signed long) (*((I32PTR) Tx)))
#define	TcodeSignedHuge( Tx )	((signed long) (*((WPTR) Tx)))
#define	TcodeInteger( TcW )	( WORDSIZE == WORD32SIZE ?  ((BINAIRE)(TcodeSignedLong(TcW))) : ( WORDSIZE == WORD16SIZE ?  ((BINAIRE)(TcodeSignedShort(TcW))):((BINAIRE)(TcodeSignedHuge(TcW)))))
#else
#define	TcodeSignedLong( Tx )	((signed long) (*((WPTR) Tx)))
#define	TcodeInteger( TcW )	( WORDSIZE == WORD32SIZE ? ((BINAIRE)(TcodeSignedLong(TcW))) : ((BINAIRE)(TcodeSignedShort(TcW))))
#endif

#define TcodePmot16( Tx , Vx  ) *((WPTR16) Tx) = Vx;
#ifdef	ABAL64
#define TcodePmot32( Tx , Vx  ) *((I32PTR) Tx) = Vx;
#define TcodePmot64( Tx , Vx  ) *((WPTR) Tx) = Vx;
#define TcodePmot( TxW , VxW ) 	if ( WORDSIZE == WORD16SIZE  ) { TcodePmot16(TxW,VxW); } else if ( WORDSIZE == WORD32SIZE ) { TcodePmot32(TxW,VxW); } else { TcodePmot64(TxW,VxW); }
#else
#define TcodePmot32( Tx , Vx  ) *((WPTR) Tx) = Vx;
#define TcodePmot( TxW , VxW ) 	if ( WORDSIZE == WORD16SIZE ) { TcodePmot16(TxW,VxW); } else { TcodePmot32(TxW,VxW); }
#endif


#define	balgetw( Tx )		((BINAIRE)((signed short)((((EXAWORD) *Tx ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )))) 
				

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#define	balgetl( Tx )		((((EXAWORD) *((BPTR)Tx) )    << 24) | (((EXAWORD) *((BPTR)(Tx+1))) << 16) | (((EXAWORD) *((BPTR)(Tx+2))) <<  8) | (((EXAWORD) *((BPTR)(Tx+3)))) ) 

#define	balputl( Vx , Tx )	{\
				*((BPTR) (Tx + 3)) = (EXABYTE) ( Vx        & 0x00FF );\
				*((BPTR) (Tx + 2)) = (EXABYTE) ((Vx >>  8) & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) ((Vx >> 16) & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) ((Vx >> 24) & 0x00FF );\
				}

#ifdef	ABAL64
#define	balgeth( Tx )		( (((EXAWORD) *((BPTR)Tx) )    << 56) | (((EXAWORD) *((BPTR)(Tx+1))) << 48) | (((EXAWORD) *((BPTR)(Tx+2))) << 40) | (((EXAWORD) *((BPTR)(Tx+3))) << 32) | (((EXAWORD) *((BPTR)(Tx+4))) << 24) | (((EXAWORD) *((BPTR)(Tx+5))) << 16) | (((EXAWORD) *((BPTR)(Tx+6))) <<  8) | (((EXAWORD) *((BPTR)(Tx+7))))) 

#define	balputh( Vx , Tx )	{\
				*((BPTR) (Tx + 7)) = (EXABYTE) ( Vx        & 0x00FF );\
				*((BPTR) (Tx + 6)) = (EXABYTE) ((Vx >>  8) & 0x00FF );\
				*((BPTR) (Tx + 5)) = (EXABYTE) ((Vx >> 16) & 0x00FF );\
				*((BPTR) (Tx + 4)) = (EXABYTE) ((Vx >> 24) & 0x00FF );\
				*((BPTR) (Tx + 3)) = (EXABYTE) ((Vx >> 32) & 0x00FF );\
				*((BPTR) (Tx + 2)) = (EXABYTE) ((Vx >> 40) & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) ((Vx >> 48) & 0x00FF );\
				*((BPTR) (Tx    )) = (EXABYTE) ((Vx >> 56) & 0x00FF );\
				}
#endif

#endif			/* IDIRECT treatments			*/


#else			/* Direct word storage type 680xx	*/

		/* *************************************************************** */
		/* 			    W A R N I N G			   */
		/* *************************************************************** */
		/* this needs the 64 bit integer manipulation macros to be defined */
		/* *************************************************************** */

#define	TcodeWord16( Tx )	((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 
#define	TcodeWord32( Tx )	( (((EXAWORD) *(Tx+3) ) << 24) | (((EXAWORD) *(Tx+2) ) << 16) | (((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) )) 
#define	Tcodeword( TcW )	( WORDSIZE == WORD32SIZE ? (TcodeWord32(TcW)) : (TcodeWord16(TcW)))

#define	TcodeSignedShort( Tx )	((signed short)((((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) ))) 
#define	TcodeSignedLong( Tx )	((signed long )( (((EXAWORD) *(Tx+3) ) << 24) | (((EXAWORD) *(Tx+2) ) << 16) | (((EXAWORD) *(Tx+1) ) << 8) | ( ((EXAWORD) *((BPTR) Tx ) ) ))) 
#define	TcodeInteger( TcW )	( WORDSIZE == WORD32SIZE ? ((BINAIRE)(TcodeSignedLong(TcW))) : ((BINAIRE)(TcodeSignedShort(TcW))))

#define	TcodePmot32( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				*((BPTR) (Tx + 2)) = (EXABYTE) (( Vx & 0xFF0000) >> 16);\
				*((BPTR) (Tx + 3)) = (EXABYTE) (( Vx & 0xFF000000) >> 24);\
				}

#define	TcodePmot16( Tx , Vx )	{\
				*((BPTR) Tx )      = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}

#define TcodePmot( TxW , VxW ) 	if ( WORDSIZE == WORD16SIZE ) { TcodePmot16(TxW,VxW); } else { TcodePmot32(TxW,VxW); }

#ifdef EVENBOUND
#define	balgetw( Tx )		((BINAIRE)((signed short)((((EXAWORD) *Tx ) << 8) | ( ((EXAWORD) *((BPTR)(Tx + 1)) ) )))) 
				

#define	balputw( Vx , Tx )	{\
				*((BPTR) (Tx + 1)) = (EXABYTE) ( Vx & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) (( Vx & 0xFF00) >> 8);\
				}
#define	balgetl( Tx )		((((EXAWORD) *((BPTR)Tx) )    << 24) | (((EXAWORD) *((BPTR)(Tx+1))) << 16) | (((EXAWORD) *((BPTR)(Tx+2))) <<  8) | (((EXAWORD) *((BPTR)(Tx+3)))) ) 

#define	balputl( Vx , Tx )	{\
				*((BPTR) (Tx + 3)) = (EXABYTE) ( Vx        & 0x00FF );\
				*((BPTR) (Tx + 2)) = (EXABYTE) ((Vx >>  8) & 0x00FF );\
				*((BPTR) (Tx + 1)) = (EXABYTE) ((Vx >> 16) & 0x00FF );\
				*((BPTR)  Tx)      = (EXABYTE) ((Vx >> 24) & 0x00FF );\
				}

#else
#define balgetw( Tx )		*((WPTR16) Tx)
#define balputw( Vx , Tx  ) 	*((WPTR16) Tx) = Vx
#define balgetl( Tx )		*((WPTR) Tx)
#define balputl( Vx , Tx  ) 	*((WPTR) Tx) = Vx
#endif
#endif			/* IDIRECT / DIRECT selection		*/


/*	Signed character integer operations for RISC machines		*/
/*	-----------------------------------------------------		*/
#ifndef ABALSIGN
#define ReadSchar( ptr ) *((CPTR)(ptr))
#else
#ifdef	VERSION666
#define	ReadSchar( ptr ) ((((*ptr & 0x80)== 0) ?  *((BPTR)(ptr)) : (((EXAWORD) *((BPTR)(ptr))) | 0xFFFFFF00)))
#else
#define	ReadSchar( ptr ) ((((*ptr & 0x80)== 0) ?  *((BPTR)(ptr)) : (((EXAWORD) *((BPTR)(ptr))) | 0xFF00)))
#endif
#endif


/*	EXALONG <-> EXAWORD manipulations	*/
/*	---------------------------	*/

#define PLOWORD(l)       ((EXAWORD)(ULONG)(l))
#define PHIWORD(l)       ((EXAWORD)((((ULONG)(l)) >> 16) & 0xFFFF))
#define PULONG(low,high) ((ULONG)(((EXAWORD)(low)) | (((ULONG)((EXAWORD)(high))) << 16)))

#define balget64 balgeth
#define balput64 balputh
#define	bcdtoh bcdtol
#define	atoh atol
#define	hextoh hextol
#define	exatoh exatol
#define htoa ltoa

#endif	/* _EXWORD_H */
	/* --------- */

