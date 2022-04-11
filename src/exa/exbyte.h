#ifndef	_EXBYTE_H
#define	_EXBYTE_H

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

#endif	/* _EXBYTE_H */
	/* --------- */

