BPTR	abal_crypt( pkey , sptr , slen ,mode)
EXAWORD	pkey;
BPTR	sptr;
EXAWORD	slen;
EXAWORD	mode;
{
	BPTR	rptr;
	BYTE	exkm[16][16];
	short int kdex,kdey;
	short int rotor;
	EXAWORD	cmpt;
	EXAWORD	x,y;
	EXAWORD	phase;
	rptr = sptr; cmpt = 0;
	for (x = 0; x < 16 ; x++) {
		for ( y =0; y < 16; y++ ) {
			exkm[x][y] = (BYTE) cmpt; cmpt++;
			}
		}
	rotor = 1; phase = pkey & 0x0007;
	while ( slen > 0 ) {
		if ( mode == 1 ) { 
			kdex = ((EXAWORD) *sptr) / 16;
			kdey = ((EXAWORD) *sptr) % 16;
			switch ( phase ) {
				case 1 : kdey++;
				case 0 : kdex--; break;
				case 2 : kdey++; break;
				case 3 : kdey++; 
				case 4 : kdex++; break;
				case 5 : kdex++;
				case 6 : kdey--; break;
				case 7 : kdex--; kdey--;
				}
			}
		else	{
			for ( x = 0; x < 16; x++ ) {
				for ( y = 0; y < 16; y++ ) {
					if ( exkm[x][y] == *sptr ) {
						kdex = x; x = 16;
						kdey = y; y = 16;
						}
					}
				}
			switch ( phase ) {
				case 1 : kdey--;
				case 0 : kdex++; break;
				case 2 : kdey--; break;
				case 3 : kdey--; 
				case 4 : kdex--; break;
				case 5 : kdex--;
				case 6 : kdey++; break;
				case 7 : kdex++; kdey++;
				}
			}
		if ( kdex > 15 ) { kdex = 0; }
		if ( kdey > 15 ) { kdey = 0; }
		if ( kdex < 0 ) { kdex = 15; }
		if ( kdey < 0 ) { kdey = 15; }
		if ((pkey & rotor ) != 0 ) {
			phase++;
			if ( phase > 7 ) { phase = 0; }
			}
		rotor <<= 1;
		if ( rotor == 0 ) { rotor = 1; }
		*(sptr++) = exkm [ kdex ][ kdey ]; slen--;
		}
 	return(rptr);
}
EXAWORD	atheader_getw( MODULE * mptr, int offset )
{
	return( tcgetword( &mptr->atheader[offset], mptr->wordsize ) );
}

EXAWORD	dbheader_getw( MODULE * mptr, int offset )
{
	return( tcgetword( &mptr->dbheader[offset], mptr->wordsize ) );
}

int	is_tcode_program( MODULE * mptr )
{
	if ( mptr->whatisit == TCODE_MODULE )
		return(0);
	else	return(1);
}


VOID	build_header( MODULE * mptr, BPTR buffer, int isdebug )
{
	int	i;
	long	time(long *);

	memset( buffer, 0xFF, 256 );

	if ( mptr->wordsize > 2 )
		*(buffer++) = '3'; 
	else	*(buffer++) = '2';

	*(buffer++) = '1'; *(buffer++) = '3';

	for (i=0; i < 15; i++ ) { *(buffer++) = mptr->progname[i]; }

	*(buffer++) = (mptr->options | 1);
	*(buffer++) = 0;

	mptr->extended.sector = 0;

	if (mptr->EtdLimit != 0) {
		mptr->extended.length = ((mptr->EtdLimit/16)+(mptr->EtdLimit%16?1:0));
		mptr->extended.sector = (mptr->extended.length >> 16);
		}

	if (!(isdebug)) {
		buffer = tcputword( buffer, mptr->argvariable, mptr->wordsize );
		buffer = tcputword( buffer, mptr->constable.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->constable.length , mptr->wordsize );
		buffer = tcputword( buffer, mptr->varbtable.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->varbtable.length , mptr->wordsize );
		buffer = tcputword( buffer, mptr->extended.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->extended.length , mptr->wordsize );
		buffer = tcputword( buffer, mptr->segmtable.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->segmtable.length , mptr->wordsize );
		buffer = tcputword( buffer, mptr->proctable.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->proctable.length , mptr->wordsize );
		buffer = tcputword( buffer, mptr->procnames.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->maxldt, mptr->wordsize );
		buffer = tcputword( buffer, mptr->maxlds, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* x p t */
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* v r t */
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* c r t */
		}
	else	{
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize );
		buffer = tcputword( buffer, mptr->procnames.sector , mptr->wordsize );
		buffer = tcputword( buffer, mptr->maxldt, mptr->wordsize );
		buffer = tcputword( buffer, mptr->maxlds, mptr->wordsize );
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* x p t */
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* v r t */
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* c r t */
		}
	buffer = tcputword( buffer, mptr->diezeheap,  mptr->wordsize );
	buffer = tcputword( buffer, mptr->diezefiles, mptr->wordsize );
	buffer = tcputword( buffer, mptr->diezemem,   mptr->wordsize );
	buffer = tcputword( buffer, mptr->diezestack,   mptr->wordsize );
	buffer = tcputword( buffer, (mptr->CryptCode & 0x0FFFF), mptr->wordsize ); /* c r y p t */

	/* 1.1, 1.2, 1.4 extensions */
	/* ------------------------ */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* debug map sector */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* debug list names  */
	buffer = tcputword( buffer, mptr->librtable.sector, mptr->wordsize ); 
	buffer = tcputword( buffer, mptr->librtable.length, mptr->wordsize ); 
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* DLL RELOC */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* #MINALSM */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* GLOBAL DATA IMAGE sector */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* GLOBAL DATA IMAGE length */

	/* 2.1 Extensions */
	/* -------------- */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* ETD Page Size */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* ETD Swap Buffer */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* MAX OPTIMISATION */
	buffer = tcputword( buffer, mptr->segmnames.sector , mptr->wordsize );
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* external segments */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* external fields */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* module names */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* vct block */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* cct block */
	buffer = tcputword( buffer, 0, mptr->wordsize ); /* cct length */
	buffer = tcputword( buffer, mptr->filenames.sector , mptr->wordsize );
	for ( i=0; i < 7; i++ )
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* zero ! nul ! */

	/* OTR / CTR Extensions */
	/* -------------------- */
	for ( i=0; i < 5; i++ )
		buffer = tcputword( buffer, 0, mptr->wordsize ); /* zero ! nul ! */

	if ( Linker.debug ) {
		if ( mptr->wordsize > 2 )
			buffer = tcputword( buffer, 1, mptr->wordsize );
		else	buffer = tcputword( buffer, mptr->minusone, mptr->wordsize );
		}

	return;
}



private	void	lock_headers( MODULE * mptr )
{
	unsigned short int dcrypt;
	if ((dcrypt = mptr->CryptCode) != 0 ) {
		mptr->atheader[0x12] = (mptr->options | 0x0040); /* Optimised */
		mptr->atheader[0x13] = 0x0000; /* Executable */
		abal_crypt( dcrypt, &mptr->atheader[TCPREFIX], ((21*mptr->wordsize)+2), 1 );
		abal_crypt( dcrypt, &mptr->dbheader[TCPREFIX], ((21*mptr->wordsize)+2), 1 );
		tcputword( &mptr->atheader[(TCPREFIX + (21*mptr->wordsize)+2)],dcrypt,2 );
		tcputword( &mptr->atheader[(TCPREFIX + (21*mptr->wordsize)+2)],dcrypt,2 );
		}
	tcputlong( &mptr->atheader[ OFFSET_TIMESTAMP ], time((long*)0));
	return;
}

private	int unlock_headers( MODULE * mptr )
{
	EXAWORD	dcrypt;
	int	i;
	if ( mptr->atheader[0] == '3') {
		mptr->wordsize = WORD32SIZE;
		mptr->minusone = 0xFFFFFFFFL;
		mptr->islocal  = ISLOCAL3;
		mptr->toglobal = TOGLOBAL3;
		}
	else 	{
		mptr->wordsize = WORD16SIZE;
		mptr->minusone = 0x0000FFFFL;
		mptr->islocal  = ISLOCAL2;
		mptr->toglobal = TOGLOBAL3;
		}

	if (!( Linker.forcecase )) {
		for (i=0; i < 15; i++ ) { mptr->progname[i] = mptr->atheader[i+3]; }
		}
	else	{
		for (i=0; i < 15; i++ ) { mptr->progname[i] = toupper(mptr->atheader[i+3]); }
		}

	if ((dcrypt = tcgetword( &mptr->atheader[(TCPREFIX + (21*mptr->wordsize)+2)],2 )) != 0xFFFF )
		abal_crypt( dcrypt, &mptr->atheader[TCPREFIX], ((21*mptr->wordsize)+2), 0 );
	if ((dcrypt = tcgetword( &mptr->dbheader[(TCPREFIX + (21*mptr->wordsize)+2)],2 )) != 0xFFFF )
		abal_crypt( dcrypt, &mptr->dbheader[TCPREFIX], ((21*mptr->wordsize)+2), 0 );

	mptr->options = mptr->atheader[TCPREFIX];

	mptr->argvariable = tcgetword( &mptr->atheader[(TCPREFIX+2)], mptr->wordsize );
	if ( mptr->wordsize == 2 ) {
		mptr->EtdLimit 	  = (( (tcgetword( &mptr->atheader[(TCPREFIX + (5*mptr->wordsize)+2)],mptr->wordsize ))
				     + (tcgetword( &mptr->atheader[(TCPREFIX + (6*mptr->wordsize)+2)],mptr->wordsize )))
			            * 16);
		}
	mptr->diezeheap=tcgetword( &mptr->atheader[(TCPREFIX + (17*mptr->wordsize)+2)],mptr->wordsize ); 
	mptr->diezefiles=tcgetword( &mptr->atheader[(TCPREFIX + (18*mptr->wordsize)+2)],mptr->wordsize );
	mptr->diezemem=tcgetword( &mptr->atheader[(TCPREFIX + (19*mptr->wordsize)+2)],mptr->wordsize ); 
	mptr->diezestack=tcgetword( &mptr->atheader[(TCPREFIX + (20*mptr->wordsize)+2)],mptr->wordsize );
	mptr->whatisit = (mptr->atheader[0x0013] & TCODE_MODULE);
	return(0);
}	
	

