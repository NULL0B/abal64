#ifndef	_EXPROTO_H
#define	_EXPROTO_H

EXAWORD		tkodgo(	EXAWORD	, BPTR );
VOID 		bufwipe();
VOID		fmtbass(EXAWORD);
BPTR		negbcdcpy(BPTR,EXAWORD);
EXAWORD		sf_print(EXAWORD );
EXAWORD		ret_seg(EXAWORD);
VPTR		malloc(int);
BPTR		Squeeze(BPTR,EXAWORD);
EXAWORD		lenuze(BPTR,EXAWORD);
EXAWORD		loadfich();
EXAWORD		savefich();
EXAWORD		sf_close();




#endif	/* _EXPROTO_H */

