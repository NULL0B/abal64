#ifndef	_EXCONV_C
#define	_EXCONV_C

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1997 Amenesik / Sologic S.A.		*/
/*									*/
/*		Module  :	EXCONV - C				*/
/*		Version :	1.5a 					*/
/*		Date 	:	24/03/1997				*/
/*									*/
/*----------------------------------------------------------------------*/
/*	This module provides the following conversion routines for all
 *	executer data type conversions.
 *
 *	VOID	negbcd(bcd,length)		Converts between minus forms
 *	UBIN	itohex(integer,buffer,length)	Integer to Hexadecimale
 *	UBIN 	itoa(integer,buffer,length)	Integer to Ascii Base 10
 *	UBIN 	itobcd(integer,buffer,length)	Integer to B.C.D.
 *	BIN 	hextoi(buffer,length)		Hexadecimale to Integer
 *	EXALONG 	hextol(buffer,length)		Hexadecimale to Long
 *	BIN	exatoi(buffer,length)		Ascii Base 10 to Integer
 *	BIN	bcdtoi(buffer,length)		B.C.D. to Integer
 *	UBIN	atobcd(string,buffer,length)	Ascii Base 10 to B.C.D.
 *	UBIN	bcdtoa(bcd,length,string,length) B.C.D. to Ascii Base 10
 *	UBIN	minimaji(UBIN)			Convert Mini => Maji
 *	UBIN	conv(Registre,Data_Type)	Register contents to data_type
 *	VOID	Squeeze(BcdPtr,BcdLen)		Removes leading Zeros
 *------------------------------------------------------------------------*/
#ifdef	ABAL21
#define	get_national_language	NationalLanguage
#else
#define	get_national_language	conf(5)
#endif

#include "exmima.c"

/*
 *	N E G B C D ( bcd , len )
 *	-------------------------
 */

VOID	negbcd(bcd,len)
BPTR	bcd;
EXAWORD	len;
{
	while ( len > 0 ) {
		*bcd = (EXABYTE) ( ((EXAWORD) *bcd) ^ 0x00FF ); 
		bcd++; len--;
		}
	return;
}
/*
 *	N E G B C D C P Y ( bcd , len )
 *	-------------------------------
 */

BPTR	negbcdcpy(bcd,len)
BPTR	bcd;
EXAWORD	len;
{
	BPTR	rptr;

	rptr = (BPTR) (TcodeByteStack + worktop); worktop += len;
	(VOID) memcpy((BPTR) rptr, (BPTR) bcd , (USINT) len);
	bcd = rptr;
	while ( len > 0 ) {
		*bcd = (EXABYTE) ( ((EXAWORD) *bcd) ^ 0x00FF ); 
		bcd++; len--;
		}
	return((BPTR) rptr);
}


/* 
 *	I T O H E X ( v , dest , len )
 *	------------------------------
 *
 * 	Conversion Integer 16 ou 8 bits en Chaine Hexadeciamle
 *
 */
	
EXAWORD itohex(v,dest,len)
EXAWORD	v;			/*	Integer to convert to HEXA	*/
BPTR	dest;			/*	Destination for storage		*/
EXAWORD	len;			/*	Length of Result 2=>8bit, 4=>16 */
{
	register EXAWORD x,y;
		 EXAWORD w,o;
		 BINAIRE z;
	o = 0;
	if   (len > 2) 	{ z = 12; w = 0xF000; }
	else		{ z = 4;  w = 0x00F0; }

	do {	
		x = ( v & w ) >> z;
		if ( x != 0 ) {
		 	if ( x > 9 ) { y = (( x-9) | 0x0040); }
			else { y = (x | 0x0030); }
			*(dest++) = (EXABYTE) y; o++;
			}
		else { if ( o != 0 ) { *(dest++) = '0'; o++; } }

		w >>= 4; z -= 4;
		}
	while ( z >= 0 );	
	if ( o == 0 ) { *(dest++) = '0'; o++; } 
	return(o);	
}

/*
 *	H E X T O I ( cp , len )
 *	------------------------
 *
 *	Conversion Chaine Hexadecimale en Integer sur longeur len
 *
 */

BINAIRE hextoi(cp,len)
BPTR	cp;		/*	Pointer to Hexa string	*/
EXAWORD	len;		/*	Length to convert	*/
{
register EXAWORD	x;
register BPTR 	ep;
	 EXABYTE		c;
	 EXAWORD	y,z;

x = 0; z = 1; ep = cp + len - 1; y = len;
while (y) { 
	c = *(ep--);
	if (isdigit(c) == 0) x += ((( (EXAWORD) c) & 0x000F) * z);
	else { 	if (isxdigit(c) == 0) { x += ((((EXAWORD) toupper(c)) - 55) * z); }
	 	else { break; }
	     }
	z *= 16; y--;
	}
return(x);
}

#ifdef	VERSION666

/* 
 *	L T O H E X ( v , dest , len )
 *	------------------------------
 *
 * 	Conversion Integer 16 ou 8 bits en Chaine Hexadeciamle
 *
 */
	
EXAWORD ltohex(v,dest,len)
EXAWORD	v;			/*	Integer to convert to HEXA	*/
BPTR	dest;			/*	Destination for storage		*/
EXAWORD	len;			/*	8 bytes at least */
{
	EXAWORD	o=len;
	while ((v) && (o)) {
		o--;
		if ((v%16) > 9) 
			*(dest+o)=(((v%16)-10) + 'A');
		else	*(dest+o)=((v%16) + '0');
		v /= 16;
		}
	while ( o ) {
		o--;
		*(dest+o) = '0';
		}
	return( len );
}

/*
 *	H E X T O L ( cp , len )
 *	------------------------
 *
 *	Conversion Chaine Hexadecimale en Integer sur longeur len
 *
 */

EXAWORD hextol(cp,len)
BPTR	cp;		/*	Pointer to Hexa string	*/
EXAWORD	len;		/*	Length to convert	*/
{
register EXAWORD	x=0;
register EXAWORD	i;

	for (i=0; i < len; i++ ) {
		if (( *(cp+i) >= '0' )
		&& ( *(cp+i) >= '9' )) 
			x = ((x * 16) + (*(cp+i) - '0'));		
		else if (( *(cp+i) >= '0' )
		&& ( *(cp+i) >= '9' )) 
			x = ((x * 16) + (*(cp+i) - 'A') + 10);		
		else if (( *(cp+i) >= 'a' )
		&& ( *(cp+i) >= 'f' )) 
			x = ((x * 16) + (*(cp+i) - 'a') + 10 );		
		else	break;
		}
	return(x);
}
#endif
/* 
 *	A T O B C D ( sp , bcd , len , slen )
 *	-------------------------------------
 *
 *	Conversion  ASCII Numerique => BCD Numerique
 *
 */

EXAWORD	not_legal_digit( sp, slen )
BPTR	sp;
EXAWORD	slen;
{
	if ( slen > 0 )
		if ((( *sp >= '0' ) && ( *sp <= '9' ))
		||   ( *sp == '.' ))
			return(0);
	return(1);
}

EXAWORD atobcd(sp,bcd,len,slen)
BPTR	sp;
BPTR	bcd;
EXAWORD	len,slen;

{
register EXAWORD 	phase=0;
	 EXAWORD 	db=0x00C0;
	 EXAWORD	digits=0;
	 EXAWORD	fraction=0;
	 EXAWORD	flag=0;	   
	 EXAWORD	x;
	 BPTR 		bcdptr;
	 EXAWORD	bcdlen;
	 EXAWORD	i;		  
	 EXABYTE	x1;	 

	bcdptr = bcd;
	bcdlen = len;

	/* Ignore leading Spaces */
	/* --------------------- */
	while (( slen > 0 ) && ( *sp == ' ' )) 
	{ 
		slen--; 
		sp++; 
	}

	while (( len > 0 ) && ( slen > 0 )) 
	{
		x = *(sp++); slen--;

		// high byte / low byte phase
		switch ( phase ) 
		{
		case 0 : 
			// Collect and Set Digit * no exit on sign * 
			switch ( x ) 
			{
			case ' '	: slen = 0; 
					  continue;
			case '-'	: db = 0x00B0;
			case '+'	: phase = 2;
					  continue;
			}

		case 2 : 
			// Establish Low order 2nd digit 
			if (( x >= '0' ) && ( x <= '9' )) 
			{ 
				x -= '0'; 
			}
			// detect decimal separator
			else if (( x == '.' ) || ( x == ',')) 
			{ 
				// is it already fraction 
				if ( fraction ) 
				{
					// error decimal separator
					slen = 0;
					continue;
				}
				// enter fraction
				fraction = 1;
				digits++;
				x = 0x000A; 
			}
			else	
			{ 
				// not a legal digit
				slen = 0; 
				continue; 
			}
			// only avoid leading zeros or not legal 
			if ((( x != 0 ) || ( digits ) ) || ( not_legal_digit( sp, slen ) )) 
			{
				// store the digit pair byte to result
				*(bcd++) = (EXABYTE) ( db | x ); len--;
				phase = 1; digits++;
			}
			continue;

		case 1 : 
			// Establish High order 1st digit
			if (( x >= '0' ) && ( x <= '9' )) 
			{ 
				db = ((x - '0') << 4);
				if (( db ) && ( digits ))
					digits++;
				phase = 2; 
				continue;
			}
			// detect decimal separator
			else if (( x == '.' ) || ( x == ',')) 
			{ 
				// is it already fraction 
				if ( fraction ) 
				{
					// error decimal separator
					slen = 0;
					continue;
				}
				// enter fraction
				fraction = 1;
				digits++;
				db = 0x00A0; 
				phase = 2; 
				continue;
			}
			else	
			{ 
				// not a legal digit
				slen = 0; 
				continue; 
			}
		}
	}

	if ( len > 0 ) 
	{
		switch ( phase ) 
		{
		case 2 : *(bcd++) = (EXABYTE) (db | 0x000F); len--; break;
		case 0 : *(bcd++) = (EXABYTE) 0x00C0; len--;
		}
		while ( len > 0 ) { *(bcd++) = (EXABYTE) 0x00FF; len--; }
	}

	x1=(EXABYTE)(*bcdptr);
	if((x1 & 0xF0) ==0xB0)
	{
		for(i=0;i<bcdlen;i++)
		{
			x1=(EXABYTE)(*(bcdptr+i));
			x1 &= 0xF0;
			if(x1 == 0xF0) break;
			if((x1 > 0x00) && (x1 <= 0x90)) flag++;
	
			x1=(EXABYTE)(*(bcdptr+i));
			x1 &= 0x0F;
			if(x1  == 0x0F) break;
			if((x1 > 0x00) && (x1 <= 0x09)) flag++;
		}
		if(!flag) *bcdptr=0xCF;
	}

	return(1);
}

/*	-----------------	*/
/*	ConvertAsciiToBcd	*/
/*	-----------------	*/
EXAWORD	ConvertAsciiToBcd(BPTR rptr, EXAWORD rlen, BPTR sptr, EXAWORD slen)
{
	BYTE	digit=0x0C0;
	EXAWORD	mode=1;
	EXAWORD	fraction=0;
	BYTE	c;

	/* reset the BDD result */
	memset(rptr,0x0FF,rlen); *rptr = 0x0CF;

	/* step over white space */
	while (( slen != 0 ) && ( *sptr == ' ' )) { sptr++; slen--; }
	if (!( slen )) return( GOODRESULT); 

	/* handle the sign */
	if ( *sptr == '-' ) { sptr++; slen--; digit = 0x0B0; } else if ( *sptr == '+' ) { sptr++; slen--; }

	/* repeat while more source bytes */
	while ( slen-- )
	{
		/* end of string we quit */
		if (!( c = *(sptr++) ))
			break;

		/* detect a digit */
		else if (( c >= '0' ) && ( c <= '9'))
		{
			if (!( mode ))
				digit = ((c - '0') << 4);
			else if (!( rlen ))
			{
				err_val = 110;
				return(SOFTERROR);
			}
			else
			{
				/* store output byte */
				*(rptr++) = (digit | ( c - '0')); rlen--; digit = 0;
			}
			mode = ((mode+1) & 1);
		}
		/* detect a decimal separator */
		else if (( c == '.' ) || ( c == ',')) 
		{
			if ( fraction )
			{
				err_val = 110;
				return(SOFTERROR);
			}
			else if (!( mode ))
				digit = 0x00A0;
			else if (!( rlen ))
			{
				err_val = 110;
				return(SOFTERROR);
			}
			else
			{
				/* store output byte */
				*(rptr++) = (digit | 0x0A);; rlen--; digit = 0;
			}
			mode = ((mode+1) & 1);
			fraction++;
		}
		else
		{
			err_val = 110;
			return(SOFTERROR);
		}
	}
	/* detect and handle waiting digit */
	if ( mode )
	{
		if (!( rlen ))
		{
			err_val = 110;
			return(SOFTERROR);
		}
		else
		{
			*(rptr++) = (digit | 0x0F); rlen--;
		}
	}
	return( GOODRESULT );
}

/*	--------	*/
/*	 ltobcd		*/
/*	--------	*/
EXAWORD	ltobcd( EXAWORD value, BPTR buffer, EXAWORD buflen )
{
	BYTE	ascii[64];
	int	v=(int)value;
	sprintf(ascii,"%d",v);
	return( ConvertAsciiToBcd(buffer, buflen, ascii, strlen(ascii) ) );
}

/*      --------        */
/*       htobcd        	*/
/*      --------        */
EXAWORD	htobcd( EXAWORD value, BPTR buffer, EXAWORD buflen )
{
	BYTE	ascii[64];
	long long v=(long long)value;
	sprintf(ascii,"%lld",v);
	return( ConvertAsciiToBcd(buffer, buflen, ascii, strlen(ascii) ) );
}

#ifndef	INTELASM2

/*
 *	B C D T O A ( bcd , len , xp , sl )
 *	-----------------------------------
 *
 *	Conversion  BCD Numerique => ASCII Numerique  
 *
 */

EXAWORD	bcdtoa(bcd,len,xp,sl)
BPTR	bcd;			/* Pointer to BCD String to be converted */
EXAWORD	len;			/* Length of String to Convert		 */
BPTR	xp;			/* Result storage zone pointer		 */
EXAWORD	sl;			/* Maximum string length		 */
{
register EXAWORD x;
	 EXAWORD digit;

#ifdef	 ABAL_RTL
	EXAWORD holdlen;
	holdlen = sl;
#else
#define	holdlen 1
#endif

if (len > BCDMAX) { len = BCDMAX; }
if ( (((EXAWORD) *bcd) & 0x00F0 ) == 0x0040 ) { bcd = (BPTR) negbcdcpy(bcd,len); }
digit = 0;
while (( len > 0 ) && ( sl > 0 )) {
	x = (EXAWORD) *(bcd++); len--;
	switch ( x & 0x00F0 ) {
		case 0x00B0	:  *(xp++) = '-'; sl--; break;
		case 0x00F0	:  len = 0; continue;
		case 0x00A0	:  if (( x & 0x000F ) != 0x000F) {
					 if ( digit == 0 ) { *(xp++) = '0'; sl--; }
					 if ( sl == 0 )
						return( holdlen );
					 if ( sl > 1 ) {
						 *(xp++) = sepdec ; sl--; 
						}
					 else	{
						*(xp++) = ' '; sl--;
						}
					 }
				    else { len = 0; continue; }
				    digit++; break;
		case 0x00C0	:   break;
		case 0x00D0	:
		case 0x00E0	:   len = 0; err_val = ABAL_BCDFORM; 
						return(0); 
		case 0x0000	:   if ( digit == 0 ) { break; }
		default		:   *(xp++) = (EXABYTE) ((( x & 0x00F0) >> 4) | 0x0030); 
				    sl--; digit++; break;
		}
     if ( sl > 0 ) {		/* Watch out for end of String !!!! */
	switch ( x & 0x000F ) {
		case 0x000F	:  len = 0; continue;
		case 0x000A	:  if ( len == 0 ) { continue; }
				   if ((( (EXAWORD) *bcd & 0x00F0 ) != 0x00F0) && ( len > 0 )) {
					 if ( digit == 0 ) { *(xp++) = '0'; sl--; }
					 if ( sl == 0 )
						return( holdlen );
					 if ( sl > 1 ) {
						 *(xp++) = sepdec ; sl--; 
						}
					 else	{
						*(xp++) = ' '; sl--;
						}
					 }
				    else { len = 0; continue;}
				    digit++; continue;
		case 0x000B	: 
		case 0x000C	:
		case 0x000D	:
		case 0x000E	:   
						len = 0; 
						err_val = ABAL_BCDFORM; 
						return(0);
		case 0x0000	:   if ( digit == 0 ) { continue; }
		default		:   *(xp++) = (EXABYTE) (( x & 0x000F) | 0x0030); 
				    sl--; digit++; continue;
		}
	  } /* Endif sl > 0 */
	}
if (( digit == 0 ) && ( sl > 0 )) { *(xp++) = '0'; sl--; }
while ( sl > 0 ) { *(xp++) = ' ';sl--; }
return(holdlen);
}
#endif

#ifndef	INTELASM2

/* 
 *	E X A T O I ( cp , len )
 *	------------------------
 *	Converts an Ascii string pointed to by 'cp' of length 'len'
 *	to a signed Integer value which is subsequently returned
 *
 */

BINAIRE	exatoi(cp,len)
BPTR	cp;
EXAWORD	len;
{
register BINAIRE x;
	 EXAWORD y;

/*	Parse out any leading white space 	*/
/*	---------------------------------	*/
	while (( *cp == ' ' ) && (len > 0)) { cp++; len--; }

/*	Initialise local variables		*/
/*	--------------------------		*/
	x = 0; y = 0;

/*	Watch out for Empty String 		*/
/*	--------------------------		*/
	if ( len > 0 ) {

	/*	Interpret possible leading SIGN symbol	*/
	/*	-------------------------------------- 	*/
		if ( *cp == '+' ) { cp++; len--;	 }
		if ( *cp == '-' ) { cp++; y = 1; len--;	 } 

	/*	Perform Digit interpretation till end of string or non digit */
	/*	------------------------------------------------------------ */
		while ( len > 0 ) {
			if (( *cp >= '0' ) && ( *cp <= '9' ) ) {
				x *= 10;
				x += ((EXAWORD) *cp & 0x000F); len--; cp++;
				}
			else 	{ 
				break; 
				}
			}
		}
	
/*	Perform Negation if Required	*/
/*	----------------------------	*/
	if ( y == 1 ) { x = -x; }

/*	Return Converted integer Result	*/
/*	------------------------------- */
	return(x);
}
#endif

/*
 *	Conversion Integer to Ascii
 *	---------------------------
 */

EXAWORD	itoa(i,buf,len)
BINAIRE	i;		/*	Valeur a convertir	*/
BPTR	buf;		/*	Buffer to store result	*/
EXAWORD	len;		/*	Length of buffer	*/
{
#ifdef	VERSION666

	register EXAWORD x;

	/* -------------------------------------------- */
	/* use standard c library conversion to string 	*/
	/* from long signed integer into a work buffer 	*/
	/* -------------------------------------------- */
	sprintf(askbuf,"%ld",i);

	/* -------------------------------------------- */
	/* copy to result buffer up to nul terminator 	*/
	/* -------------------------------------------- */
	for (x=0; x < len; x++ ) if (!( *(buf+x) = askbuf[x] )) break;	

	/* -------------------------------------------- */
	/* ZERO Terminate : this is essential : keep it */
	/* -------------------------------------------- */
	if ( x < len ) { *(buf+x) = IO_NUL; x++; }

	/* -------------------------- */
	/* Space pad to end of string */
	/* -------------------------- */
	for ( ; x < len; x++ ) 	*(buf+x) = ' ';
		
	return(GOODRESULT);

#else
	register EXAWORD x,y;
		 EXAWORD flag;

if ( ((EXAWORD) i & 0x8000) != 0 ) { 
	*(buf++) = '-' ; len--;
	if ( (EXAWORD) i == 0x8000 ) {
		if ( len < 5 ) { err_val = ABAL_BUF2SMALL; return(0); }
		else {  memcpy( (BPTR) buf, (BPTR) "32768" , 5);
			buf += 5; len -= 5;
			if ( len > 0 ) {
				*(buf++) = (EXABYTE) 0; len--;
				while ( len > 0 ) { *(buf++) = ' '; len--; } 
				}
			return(1);
			}
		}
	else	{	i = -i ; 	}
	}
if ( i != 0 ) {
	x = 10000; flag = 0;
	while (( x >= 1 ) && (len > 0)) {
		y = ( i / x );
		if ( y != 0 ) {	*(buf++) = (EXABYTE) ( y | 0x0030 ); 
				len--; i %= x; x /= 10; flag = 1;
				}
		else { 	if ( flag == 0 ) { x/= 10; }
			else {	*(buf++) = (EXABYTE) ( y | 0x0030 ); 
				len--; i %= x; x /= 10; flag = 1;
				}
			}
		}
	}
else { *(buf++) = '0'; len--; }
if ( len > 0 ) { *(buf++) = IO_NUL; len--; }
while ( len > 0 ) { *(buf++) = ' '; len--; }
return(GOODRESULT);
#endif	/* VERSION 666 */
}

/* 
 *	Conversion Integer to BCD
 *	-------------------------
 */

EXAWORD	itobcd(i,buf,len)
BINAIRE	i;		/*	Valeur a convertir	*/
BPTR	buf;		/*	Buffer to store result	*/
EXAWORD	len;		/*	Length of buffer	*/
{
#ifdef	VERSION666
	BYTE	wbuffer[32];
	sprintf(wbuffer,"%ld",i);
	return( atobcd(wbuffer,buf,len,strlen(wbuffer)));
#else
	register EXAWORD x,y;
		 EXAWORD flag;
		 EXAWORD bcd,nib;

  if (!buf) {
	  err_val=118;
	  return SOFTERROR;
  }

if ( (EXAWORD) i == 0x8000) {	
	/* Special Case I = -32768	*/
	/* -----------------------------*/
	if ( len < 3 )
 		{ err_val = ABAL_BCDFORM; return(0);   }
	*(buf++) = (EXABYTE) 0x00B3;
	*(buf++) = (EXABYTE) 0x0027;
	*(buf++) = (EXABYTE) 0x0068; len -= 3;
	while ( len > 0 ) 	{ *(buf++) = (EXABYTE) 0x00FF; len--; }
	return(1);
	}
if ( ((EXAWORD) i & 0x8000) != 0 ) { bcd = 0x00B0; i = -i ;}
else { bcd = 0x00C0; }
nib = 2;
if ( i != 0 ) {
	x = 10000; flag = 0;
	while (( x >= 1 ) && (len > 0)) {
		y = ( i / x );
		if ( y != 0 ) { if ( nib == 1 ) { bcd = (y << 4); nib = 2; }
				else { 	bcd |= y; nib = 1; *(buf++) = (EXABYTE) bcd;
					len--; bcd = 0x00FF;
					if ( len == 0 ) { break; }
					}
				i %= x; flag = 1; x /= 10; 
				}
		else { 	if ( flag == 0 ) { x/= 10; }
			else {	if ( nib == 1 ) { bcd = (y << 4); nib = 2; }
				else { 	bcd |= y; nib = 1; *(buf++) = (EXABYTE) bcd;
					len--; bcd = 0x00FF;
					if ( len == 0 ) { break; }
					}
				i %= x; flag = 1; x /= 10; 
				}
			}
		}
	if (( len > 0 ) && ( nib == 2)) {
		*(buf++) = (EXABYTE) (bcd | 0x000F); len--;
		}
	}
else { *(buf++) = (EXABYTE) 0x00c0; len--; }
while ( len > 0 ) { *(buf++) = (EXABYTE) 0x00FF; len--; }
return(1);
#endif	/* VERSION 666 */

}

#ifndef	INTELASM2

/*	------	*/
/*	bcdtoi	*/
/*	------	*/
BINAIRE	bcdtoi(cp,len)
BPTR	cp;		/*	Pointer to BCD String to convert	*/
EXAWORD	len;		/*	Maximum length of string		*/
{
register BINAIRE x;
	 EXAWORD y;
	 EXAWORD bcd,nib;

	if ( (((EXAWORD) *cp) & 0x00F0 ) == 0x0040 ) 
	{ 
		cp = (BPTR) negbcdcpy(cp,len); 
	}
	x = 0; nib = 1; y = 0;
	while ( nib > 0 ) 
	{
		if ( nib == 1 ) 
		{
			if ( len > 0 ) 
			{ 
				bcd = (EXAWORD) *(cp++); 
				len--; 
			}
			else 
			{ 
				nib = 0; 
				continue; 
			}
			switch ( bcd & 0x00F0 ) 
			{
			case 0x00B0 :	y = 1; nib = 2; break;
			case 0x00C0 :	nib = 2; break;
			case 0x00F0 :
			case 0x00A0 : 	nib = 0; break;
			default	    : 	x *= 10; x += (( bcd & 0x00F0 ) >> 4 );
					nib = 2; break;
			}
		}
		else 
		{
			switch ( bcd & 0x000F ) 
			{
			case 0x000F :
			case 0x000A : 	nib = 0; break;
			default	    :	x *= 10; x += ( bcd & 0x000F );
					nib = 1; break;

			}
		}
	}

	if ( y == 1 ) { x = -x; }
	return(x);
}
#endif

#ifndef	ABAL_RTL
/*
 *	The General purpose convert routine	CONV ( Register, Data_Type )
 *	-----------------------------------	----------------------------
 *	This converts the Item in the register R to the data type supplied
 *	and returns the result in the same register.
 */

EXAWORD	conv(reg,dtcnv)
EXAWORD	reg,dtcnv;
{
	EXAWORD	lworktop;

	dtcnv &= VARB_ISOL;

	/* Evaluate Source Operand Type */
	/* ---------------------------- */
	if ( argset(4,reg,2) == SOFTERROR)
		return( SOFTERROR );

#ifdef	ABAL21
	/* Watch out for Identical Conversions */
	/* ----------------------------------- */
	if ( (worktyp2 & 3) == dtcnv )  
	{ 

		/* Check for String copy required */
		/* ------------------------------ */
		if (( dtcnv == 2 ) || ( dtcnv == 3))
		{

			/* Check first for possible ERROR 114 */
			/* ---------------------------------- */
			if (( worktop + (2 * WORDSIZE) + worklen2 ) > dieztmp ) 
			{
				err_val = 114;
				return( SOFTERROR );
			}

			/* Ok do the copy operation */
			/* ------------------------ */
			xreg [reg] = TEMPDESC; freg [reg] = worktop;
			TcodePmot( (TcodeByteStack + worktop) , (worktyp2 & 3) );
			TcodePmot( (TcodeByteStack + worktop + WORDSIZE), worklen2);
			memcpy( (BPTR) (TcodeByteStack + worktop + (2 * WORDSIZE)), (BPTR) workptr2, worklen2 );
			worktop += (worklen2 + (2 * WORDSIZE));
		}
		else	
		{
			freg[reg] = workval2;
			switch ( dtcnv )
			{
			case	VARB_INT16	:
			case	VARB_INT32	:
			case	VARB_INT64	:
				/* TODO think about this and FIX it for ever */
#ifdef	VERSION666
				if (workval2 & 0x08000 ) 
#ifdef	ABAL64
					freg[reg] |= 0xFFFFFFFFFFFF0000;
#else
					freg[reg] |= 0xFFFF0000;
#endif
#endif
			  	xreg [reg] = 0;
				break;
			case	VARB_INT8	:
				xreg [reg] = 4;
			}
		}
				
		/* Indicate Success */
		/* ---------------- */	
		return( GOODRESULT ); 
	}

	/* ------------------------- */
#else	/* ! ABAL21 ==> <= ABAL14    */
	/* ------------------------- */
	/* Ignore Futile Conversions */
	/* ------------------------- */
	if ((worktyp2 & 3) == dtcnv)  
		return( GOODRESULT );

#endif

	/* Switch WRT Result Data type */
	/* --------------------------- */
	switch ( dtcnv ) 
	{ 

	/* A N Y T H I N G   to   B C D */
	/* ---------------------------- */
	case 2 : worklen1 = MAXBCDSIZE; worktyp1 = 2;
		 if ( argsetw(6,reg) == SOFTERROR) 
			return( SOFTERROR ); 
		 else	return(varconv(0));

	/* N U M E R I C   to   A L P H A - N U M E R I C */
	/* ---------------------------------------------- */
	case 3 :
		/* Calculate Temporary String Pointer */
		/* ---------------------------------- */
		 workptr3 = (BPTR) (TcodeByteStack + worktop + (2*WORDSIZE));

		/* Protect our result zone */
		/* ----------------------- */
		 lworktop = worktop; worktop += ((2*MAXBCDSIZE)+(2*WORDSIZE));

		/* Select and Perform Numeric Conversion Type */
		/* ------------------------------------------ */
		 switch ( worktyp2 ) 
		{
		case 0  :
		case 1  :
		case 5 	:
		case 6 	:
			 (VOID) itoa(workval2,workptr3,(2*MAXBCDSIZE));
			  worklen1 = lenuze((BPTR) workptr3,(2*MAXBCDSIZE));
			  break;
		case 2  : (VOID) bcdtoa(workptr2,worklen2,workptr3,(2*MAXBCDSIZE));
			  worklen1 = lenuse((BPTR) workptr3,(2*MAXBCDSIZE));
			  break;
		default : return( SOFTERROR );
		}

		/* Back Patch the Temporary Descriptor */
		/* ----------------------------------- */
		 TcodePmot( (TcodeByteStack + lworktop) , (worktyp1 = 3) );
		 TcodePmot( (TcodeByteStack + lworktop + WORDSIZE), worklen1);

		/* Establish Register Informations */
		/* ------------------------------- */
		 xreg [reg] = TEMPDESC;
		 freg [reg] = lworktop;

		/* Protect the Temporary Allocation */
		/* -------------------------------- */
		 worktop = (lworktop + (worklen1 + (2*WORDSIZE)));

		/* Return to Caller */
		/* ---------------- */
		 return( GOODRESULT );

	/*  A N Y T H I N G   to 3 2  and  6 4  bit  I N T E G E R S */
	/* --------------------------------------------------------- */
	case 6 :
	case 5 :
		switch ( worktyp2 ) 
		{
		case 2  : freg [reg] = (EXAWORD) bcdtol(workptr2,worklen2); break;
		case 3  : freg [reg] = (EXAWORD) exatol(workptr2,worklen2); break;
		default : freg [reg] = workval2; break;
		}
		xreg [reg] = 0;
		return( GOODRESULT );

	/*  A N Y T H I N G   to   8  and  1 6  bit  I N T E G E R S */
	/* --------------------------------------------------------- */
	case 0  :
	case 1  : 
		switch ( worktyp2 ) 
		{
		case 2  : freg [reg] = (EXAWORD) bcdtoi(workptr2,worklen2); break;
		case 3  : freg [reg] = (EXAWORD) exatoi(workptr2,worklen2); break;
		default : 
		freg [reg] = workval2; 
#ifdef	VERSION666
		if (workval2 & 0x08000 ) 
#ifdef	ABAL64
			freg[reg] |= 0xFFFFFFFFFFFF0000;
#else
			freg[reg] |= 0xFFFF0000;
#endif
#endif
		break;
		}
		xreg [reg] = ( dtcnv == 0 ? 4 : 0);
		return( GOODRESULT );

	/* God Knows What : Error 115 !!!!! */
	/* -------------------------------- */
	default : err_val = ABAL_TCODCODE; return( SOFTERROR );
	}
}
#endif

#ifdef	VERSION666
/*	----	*/
/*	ltoa	*/
/*	----	*/
EXAWORD	ltoa(EXAWORD i, BPTR buf, EXAWORD len )
{
	BYTE	workzone[64];
	EXAWORD	worklen;
	if (!( i )) 
	{
		*(buf++) = '0'; len--;
	}
	else	
	{
		worklen = 0;
		while ((i != 0) && ( worklen < 63)) 
		{
			workzone[worklen++] = ((i%10)+0x0030);
			i /= 10;
		}
		if (( i != 0 ) 
		||  ( len < worklen )) 
		{
			err_val = ABAL_BUF2SMALL; return(SOFTERROR); 
		}
		while ( worklen != 0 ) 
		{
			worklen--;
			*(buf++) = workzone[worklen];
			len--;
		}
	}
	if ( len > 0 ) 
	{ 
		*(buf++) = IO_NUL; len--; 
	}
	while ( len > 0 ) 
	{ 
		*(buf++) = ' '; len--; 
	}
	return( GOODRESULT );
}
#endif

/*	------------------	*/
/*	effective_bcd_zero	*/
/*	------------------	*/
static	EXAWORD	effective_bcd_zero( bptr, blen )
BPTR	bptr;
EXAWORD	blen;
{
	EXAWORD	c;
	EXAWORD	d;
	while ( blen != 0 ) 
	{
		blen--;
		c = *(bptr++);
		if ((d = ( c & 0x00F0 )) == 0x00F0)
			break;
		else if ( d != 0 )
			return( 0 );
		if ((d = ( c & 0x000F )) == 0x000F)
			break;
		else if ( d != 0 )
			return( 0 );
	}
	return( GOODRESULT );
}

/*	---------	*/
/*	 Squeeze	*/
/*	---------	*/
BPTR	Squeeze( bcd , len )
BPTR	bcd;
EXAWORD	len;
{
	BPTR	rptr;
	BPTR	retptr;
	EXAWORD	rlen;
	EXAWORD	phase;
	EXAWORD	digit;
	EXAWORD	x;
	EXAWORD	savelen;

savelen = len;
/* Create temporary Variable in Temporary workspace */
/* ------------------------------------------------ */
retptr = (BPTR) (TcodeByteStack + worktop); worktop += len;

(VOID) memcpy((BPTR) retptr, (BPTR) bcd , (USINT) len);

bcd = retptr;

/* Check for Reverse negative fix needed */
/* ------------------------------------- */
if ( (((EXAWORD) *bcd) & 0x00F0 ) == 0x0040 ) { 
	negbcd(bcd,len); 
	}

/* Check for Zero Squeeze Needed */
/* ----------------------------- */
if ( (((EXAWORD) *bcd) & 0x000F ) == 0x0000 ) {
	rptr = bcd; rlen = len;
	digit = (EXAWORD) *(bcd++); len--; phase = 1;
	while (( phase != 0 ) && (len > 0)) {
		switch ( phase ) {
			case 1 :	/* Read byte elimine zeros */
					/* ----------------------- */	
				len--;
				if ( (x = (EXAWORD) *(bcd++)) == 0) { continue; }
				if ( (x & 0x00F0) == 0 ) {
					*(rptr++) = (EXABYTE) ( digit | x ); rlen--;
					if ( len > 0) { 
						memcpy(rptr,bcd,len);
						rlen -= len; rptr += len;
						}
					phase = 0; continue;
					}
				*(rptr++) = (EXABYTE) ( digit | (( x & 0x00F0) >> 4));
				rlen--; digit = ((x & 0x000F) << 4);
				phase = 2; continue;
			case 2  :
				x = (EXAWORD) *(bcd++); len--;
				*(rptr++) = (EXABYTE) ( digit | (( x & 0x00F0) >> 4));
				rlen--; digit = (( x & 0x000F ) << 4);
				continue;
			}
		}
	if ((( phase == 2 ) && ( rlen > 0 )) || ( (phase == 1) && (len == 0) && (rlen > 0))) {	
		*(rptr++) = (EXABYTE) ( digit | 0x000F ); 
		rlen--;
		}
	while ( rlen > 0 ) { *(rptr++) = (EXABYTE) 0x00FF; rlen--; }
	}

if (( (((EXAWORD) *retptr) & 0x000F ) == 0x000A )
&&  ( effective_bcd_zero( (retptr+1), (savelen-1) ) ))
	*retptr = 0x00CF;

return((BPTR) retptr);
}

/*	---------	*/
/* 	exastrlen	*/
/*	---------	*/
EXAWORD	exastrlen( BPTR sptr )
{
	EXAWORD	l;
	if (!sptr) return 0;
	for ( l = 0; *sptr; l++, sptr++);
	return( l );
}


	/* --------- */
#endif	/* _EXCONV_C */
	/* --------- */
