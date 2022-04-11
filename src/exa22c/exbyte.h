#ifndef ABALSIGN
#define ReadSchar( ptr ) *((CPTR)(ptr))
#else
#define	ReadSchar( ptr ) (((*ptr & 0x80)== 0) ?  *((BPTR)(ptr)) : (((EXAWORD) *((BPTR)(ptr))) | 0xFF00))
#endif
