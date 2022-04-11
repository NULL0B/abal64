#ifndef	_gmfileèh
#define _gmfile_h

struct	gmcontext {
	BPTR   	filename;	/* Pointer to filename 			*/
	WORD	nlog;		/* File handle				*/
	BPTR    buffer;		/* File Buffer				*/
	WORD	maxind;		/* Current file block limit		*/
	WORD	indent;		/* indent into current block		*/
	WORD	sector;		/* File LSeek Value for Amenesik / Sologic	*/
	} ;


#define FILEINFO struct gmcontext *

FILEINFO        gm_open(BPTR);
FILEINFO        gm_creat(BPTR);
void            gm_close(FILEINFO);
BPTR            gm_getw(FILEINFO);
void            gm_finline(FILEINFO);


#endif /* _gmfil_h */

