
#ifndef	_AOCLFTC_C
#define	_AOCLFTC_C

/*
 *	INCLUDE FILE FOR : TCODE.C and IDBCODE.C
 *	----------------------------------------
 *
 */

void	ClfMnemonic( x )
EXAWORD	x;
{
#ifdef	AO_STATS
	if (( Options.Stats & STAT_VRAI ) && ( Options.Stats & STAT_CODE ))
		_clf_stat[ x ]++;
#endif
	switch (x & 0x000F) 
	{
		case	3	:
			oputs("DISPLAY");
			switch ( (x & 0x00F0) >> 4) 
			{
				case	4 : oputs("LABEL"); break;
				case	5 : oputs("IMAGE"); break;
				case	6 : oputs("VIDEO"); break;
				case	7 : oputs("POPUP"); break;
				case	8 : oputs("SIZE"); break;
				case	9 : oputs("FONT"); break;
				case	10: oputs("FORE"); break;
				case	11: oputs("BACK"); break;
				case	12: oputs("COLOR"); break;
				case	13: oputs("UPLOAD"); break;
			}
			break;

		case	1	:
			oputs("TRACE");
			switch ( (x & 0x00F0) >> 4) 
			{
				case	0 : oputs("ON"); break;
				case	1 : oputs("OFF"); break;
				case	2 : oputs("PRINT"); break;
				case	3 : oputs("DUMP"); break;
				case	4 : oputs("SETDEF"); break;
				case	5 : oputs("SETMUTE"); break;
				case	6 : oputs("SETDEFMUTE"); break;
			}
			break;

		case	5	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("VALIDPTR");break;
				case	2 : oputs("TRAIN");   break;
				case	3 : oputs("LOADGO");break;
				}
			break;

		case 	6	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("CREATE");break;
				case	1 : oputs("REMOVE");break;
				case	2 : oputs("FORGET");break;
				case	3 : oputs("ALIAS");break;
				case	4 : oputs("ATTACH");break;
				case	5 : oputs("DETACH");break;
				case	6 : oputs("ALTER");break;
				case	7 : oputs("BUILD"); break;
				case    8 : oputs("DROP"); break;
				case    9 : oputs("EVALUATE"); break;
				case    10: oputs("INPUT_SYNAPSE"); break;
				case    11: oputs("OUTPUT_SYNAPSE"); break;
				case    12: oputs("SET_WEIGHT"); break;
				case    13: oputs("GET_WEIGHT"); break;
				case    14: oputs("SET_THRESHOLD"); break;
				case    15: oputs("GET_THRESHOLD"); break;
				}
			break;

		case	7	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("WAIT");break;
				case	1 : oputs("MASK");break;
				case	2 : oputs("RESTORE");break;
				case	3 : oputs("DATE");break;
				case	4 : oputs("KBF");break;
				case	5 : oputs("ASKCOLOR"); break;
				case	6 : oputs("ASKATB"); break;
				case	7 : oputs("SETHOTKEY"); break;
				case	8 : oputs("SETLANG"); break;
				case    9 : oputs("INITDATA"); break;
				case    10 : oputs("END.USER"); break;
				case    11 : oputs("END.PROC"); break;
				case    12 : oputs("END.SEG"); break;
				case	13 : oputs("EVENT");    break;
				case	14 : oputs("IPCSEND");	break;
				}
			break;
		case	8	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("ABS");break;
				case	1 : oputs("INCLUD");break;
				case	3 : oputs("INSERT");break;
				case	2 : oputs("TRANS");break;
				case	4 : oputs("MKDIR");break;
				case	5 : oputs("RMDIR");break;
				}
			break;
		case	9	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("ATN");break;
				case	1 : oputs("COS");break;
				case	2 : oputs("EXP");break;
				case	3 : oputs("LOG");break;
				case	4 : oputs("SIN");break;
				case	5 : oputs("SQR");break;
				case	6 : oputs("TAN");break;
				}
			break;
		case	10	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("LARGE");break;
				case	1 : oputs("SMALL");break;
				case	2 : oputs("SHL");break;
				case	3 : oputs("SHR");break;
				case	4 : oputs("INVERT");break;
				case 	8 : oputs("ENV"); break;
				case	5 : oputs("FMV"); break;
				case 	6 : oputs("FMR"); break;
				case	7 : oputs("FM"); break;
				case	9 : oputs("ASCIIFM"); break;
				}
			break;
		case	11	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("CRC");break;
				case	1 : oputs("DEC");break;
				case	2 : oputs("LEN");break;
				case	3 : oputs("LEN$");break;
				case	4 : oputs("SIGN");break;
				case	5 : oputs("INDEX");break;
				case	6 : oputs("INSTR");break;
				case	7 : oputs("VPTR");break;
				case	8 : oputs("FMINT");break;
				case	9 : oputs("FMFP");break;
				case	10: oputs("POWER");break;
				case	11: oputs("CHECKFMT");break;
				case	12: oputs("DAYS");break;
				case	13: oputs("RUNTIME");break;
				case	14: oputs("WILDCOMP");break;
				case	15: oputs("CHDIR");break;
				}
			break;
		case	12	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("LEFT");break;
				case	1 : oputs("RIGHT");break;
				case	2 : oputs("SUBSTR");break;
				case	3 : oputs("MOVE");break;
				case	4 : oputs("SWAP");break;
				case	5 : oputs("PARSE");break;
				case	6 : oputs("ABALANFC");break;
				case	7 : oputs("TOKENISE");break;
				}
			break;
		case	13	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("GENER");break;
				case	1 : oputs("SPACE");break;
				case	2 : oputs("DATE");break;
				case	3 : oputs("KBF");break;
				case	4 : oputs("CURDIR");break;
				case	5 : oputs("CURVOL");break;
				case    6 : oputs("HEX");break;
				case    7 : oputs("CHR$");break;
				case	8 : oputs("REPSTR");break;
				case 	9 : oputs("CRYPT"); break;
				case	10: oputs("SYSERROR"); break;
				case	11: oputs("PROCPTR"); break; 
				case	12: oputs("USERPTR"); break; 
				case	13: oputs("SEGMPTR"); break; 
				case	14 : oputs("IPCTEST");	break;
				case	15 : oputs("IPCWAIT");	break;
				}
			break;
		case	14	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("FIX");break;
				case	1 : oputs("ROUN");break;
				case	2 : oputs("FPT");break;
				case	3 : oputs("INT");break;
				case	4 : oputs("VAL");break;
				case	5 : oputs("STDFORM");break;
				case	6 : oputs("REAL");break;
				case	7 : oputs("STRN");break;
				case	8 : oputs("LONG");break;
				}
			break;
		case	15	:
			switch ( (x & 0x00F0) >> 4) {
				case	0 : oputs("COL");break;
				case	1 : oputs("LIN");break;
				case	2 : oputs("PROCESS"); break;
				case	3 : oputs("RND");break;
				case	4 : oputs("MASK"); break;
				case	5 : oputs("CONF");break;
				case	6 : oputs("ERRADR");break;
				case    7 : oputs("RESTORE"); break;
				case	8 : oputs("EVENTADR"); break;
				case 	9 : oputs("HOTKEY"); break;
				case	10: oputs("EVENT");  break;
				}
			break;
		}
	oputb('(');
	return;

}

#endif	/* _AOCLFTC_C */
	/* ---------- */


