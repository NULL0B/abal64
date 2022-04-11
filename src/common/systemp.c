#include "systemd.h"

extern WORD errno;
#ifdef	_PROTOTYPES
BPTR	ll_malloc();
void	ll_free();
WORD	Chargeur();
WORD	ExecGo();
void	Discharge();
#else
BPTR	ll_malloc( WORD );
void	ll_free( BPTR );
WORD	Chargeur( BPTR , BPTR );
WORD	ExecGo( BPTR , BPTR );
void	Discharge( BPTR );
#endif

WORD	Msystem( cmdptr )
BPTR cmdptr;
{
#ifdef	PRL
	WORD	i,j,k;
	BYTE 	c;
	BYTE 	d;
	BPTR	ExecBuf;
	BPTR	ArguBuf;
	i = 0; j = 0; k = 0;

	/* Scan past Binary function name */
	/* ------------------------------ */
	while (( *(cmdptr + i) != ' ') && ( *(cmdptr + i) != 0 )) {
		i++;
		}
	if ( i == 0 ) { return(0); }

	/* Establish File Terminator */
	/* ------------------------- */	
	c =  *(cmdptr + i);
	*(cmdptr + i) = (unsigned BYTE) 0;

	if ((ExecBuf = (BPTR) ll_malloc ( 32 )) == (BPTR) 0 ) {
		return(27);
		}

	/* Attempt to Load the Executable Binary File */
	/* ------------------------------------------ */
	if ( Chargeur((BPTR) cmdptr , (BPTR) ExecBuf ) != 0 ) {
		*(cmdptr + i  ) = c; 
		ll_free((BPTR) ExecBuf);
		return(40);
		}

	if ( c == ' ' ) {
		j = 1;
		}

	/* Scan for End of Arg */
	/* ------------------- */
	while ( (*(cmdptr+i+j+k) != 0 ) && ( *(cmdptr+i+j+k) != 0x000D)) {
		k++;
		}

	d = *(cmdptr+i+j+k);
	*(cmdptr+i+j+k) = 0x000D;

	if ((ArguBuf = (BPTR) ll_malloc( (k + 1 ) )) == (BPTR) 0 ) {
		return( 27 );
		}
	memcpy( ArguBuf , (cmdptr + i + j) , (k + 1) );

	/* Attempt to Execute the Binary File */
	/* ---------------------------------- */
	errno = ExecGo((BPTR) ExecBuf, (BPTR) ArguBuf );

	/* Liberate the binary Image */
	/* ------------------------- */
	Discharge( (BPTR) ExecBuf );

	/* Replace Swapped Bytes */
	/* --------------------- */
	*(cmdptr+j+i+k) = d; 
	*( cmdptr + i ) = c; 
	return( errno );
#endif
}
