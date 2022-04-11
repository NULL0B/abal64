#ifndef	_exfmtoa_c
#define	_exfmtoa_c

#define	oputb(c) { \
	if ( outbytes < rlen ) { \
		*(rptr + (outbytes++)) = c; \
		} \
	else 	{ \
		err_val = ABAL_BUF2SMALL; \
		return( SOFTERROR); \
		} \
	}

EXAWORD	fmtoa(BPTR fptr,EXAWORD flen,BPTR rptr,EXAWORD rlen)
{
	EXAWORD	outbytes=0;
	EXAWORD	xtrl,x,y;
	BYTE	Decimal[16];
	EXAWORD	iii;

/* Ensure legal format */
if ( *fptr != (BYTE) 0x00FE ) { 
	err_val = ABAL_FORMAT;
	return(SOFTERROR);
	}
else	memset( rptr,' ',rlen );

fptr++; oputb('('); xtrl = 0;

do 	{ 
	y = (EXAWORD) *(fptr++); 
	switch ( y ) {
		case	FMT_K	: x = 'K' ; break;
		case	FMT_D	: x = 'D' ; break;
		case	FMT_A	: x = 'A' ; break;
		case	FMT_N	: x = 'N' ; break;
		case	FMT_Z	: x = 'Z' ; break;
		case	FMT_O	: x = 'O' ; break;
		case	FMT_C	: x = 'C' ; break;
		case	FMT_B	: x = 'B' ; break;
		case	FMT_W	: x = 'W' ; break;
		case	FMT_U	: x = 'U' ; break;
		case	FMT_V   : oputb('V'); fptr++;  continue;
		case	FMT_P	: oputb('.'); continue;
		case	FMT_DOL : oputb('$'); continue;
		case	FMT_PR	: oputb('"'); 
				  x = *(fptr++);
				  while (x > 0) { oputb(*(fptr++)); x--;}
				  oputb('"'); continue;
		case	FMT_LF  : x = '/' ; break;
		case	FMT_ATB	: x = '\\' ; break;
		case	FMT_TAB	: x = 'T' ; break;
		case	FMT_ESP	: x = 'X' ; break;
		case	FMT_SEP	: oputb(',');  continue;
		case	FMT_STR	: oputb('E');  continue;
		case	FMT_CUT	: oputb('F');  continue;
		case	FMT_ZER	: oputb('*');  continue;
		case	FMT_JL	: oputb('L');  continue;
		case	FMT_JR	: oputb('R');  continue;
		case	FMT_NEG	: x = '-'; break;
		case	FMT_PNG	: x = '+'; break;
		case 	FMT_H   : oputb('H');  continue;
		case 	FMT_INH : oputb('I');  continue;
		case	FMT_MIL : oputb('S');  continue;
		case	FMT_DYN : oputb('?');  continue;
		case	FMT_MCH	: oputb('S');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_DCH	: oputb('$');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_ZCH	: oputb('*');
				  oputb('(');
				  oputb(*(fptr++)); 
				  oputb(')');
				  continue;
		case	FMT_FIN	:
		default		: oputb(')'); xtrl = 1; continue;
		}
	oputb( x ); 

	x = (EXAWORD) *(fptr++);
	
	if (( x != 1 ) || ( y & 0x0020 )) {
		if (!( x )) {
			oputb('0');
			}
		else	{	
			for (iii=0; x != 0; iii++ ) {
				Decimal[iii] = ((x%10)+'0');
				x /= 10;
				}
			do	{
				iii--;
				oputb((Decimal[iii]));
				}
			while ( iii != 0 );
			}
		}
	}
while ( xtrl == 0 );
return(GOODRESULT);
}

#endif  /* _exfmtoa_c */
	/* ---------- */


