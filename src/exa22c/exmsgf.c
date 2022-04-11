#include "ex.h"
#include "msg.h"

#pragma check_stack-		/* Switch off Stack Probes For MSC /TCC	*/

#define	MSGFILEMAX 	16	/* Maximum number of Files		*/
#define	MSGQUEUEMAX	64	/* Maximum number of messages per file	*/
#define	MSGSIZEMAX	64	/* Maximum Unit message length		*/

#define	ONSEM_FEXIST	0x0100
#define	ONSEM_FEXCLU	0x0200
#define	ONSEM_FPRIVA	0x0400

UBINAIR	fileperm[MSGFILEMAX];	/* Contains file control semaphores	*/
				/* Bit 8 : File Exists			*/
				/* Bit 9 : Exclusivity flag 		*/
				/* Bit 10: Private Flag			*/
				/* Bits 11 - 15 Reserved !!		*/
				/* Bits 0 - 7 Process ID owner/Creater  */

UBINAIR	fileuser[MSGFILEMAX];	/* Contains number of Messages in file  */ 
EXBPTR	filelink[MSGFILEMAX];	/* Contains pointers to MSG F.C.B	*/


struct	msgfctrl {
	UBINAIR	msgfcid;	/* Message ID		*/
	UBINAIR	msgfclg;	/* Message Length	*/
	UBINAIR	msgfcow;	/* Message Owner sender */
	UBINAIR	msgfclk;	/* Message Lock semaph  */
	EXBPTR	msgfctx;	/* Message text pointer	*/
};


/*
 *	I N I T W O R K ( )
 *	-------------------
 *	Initialise Message control structures
 */

UBINAIR	initwork()
{
	UBINAIR	x;
	for ( x = 0; x < MSGFILEMAX; x++) {
		fileperm[x] = 0;
		fileuser[x] = 0;
		filelink[x] = (EXBPTR) 0;
		}
	return(1);
}


UBINAIR	msgfopen( msgfid , msgfperm )
UBINAIR	msgfid;
UBINAIR	msgfperm;
{
	EXBPTR	lwptr;

	/* Check Requested file ID */
	/* ----------------------- */
	if ( msgfid >= MSGFILEMAX ) { return( 50 ); }

	/* Test for File Existance */
	/* ----------------------- */
	if ( fileperm[msgfid] & ONSEM_FEXIST ) {
		/* Test for Private MSG File */
		/* ------------------------- */
		if ( fileperm[msgfid] & ONSEM_FPRIVA ) { 
			/* Test for Owners access */
			/* ---------------------- */
			if ((fileperm[msgfid] & 0x00FF) != npos() ) {
				return( 44 ); 
				}
			}
		}
	/* File Does not Exist so Create it */
	/* -------------------------------- */
	else	{
		if ( msgfperm & IPC_CREAT ) {
			/* Allocate a new file control Table	*/
			/* ---------------------------------    */
			lwptr = (EXBPTR) malloc( (sizeof( struct msgfctrl ) * MSGQUEUEMAX) );		
			if ( lwptr == (EXBPTR) 0 ) { return( 27 ); }
			/* Establish file control values */
			/* ----------------------------- */
			fileuser[msgfid] = 0;      filelink[msgfid] = (EXBPTR) lwptr;
			fileperm[msgfid] = npos(); fileperm[msgfid] |= ONSEM_FEXIST;
			if ( msgfperm & IPC_EXCL ) { fileperm[msgfid] |= ONSEM_FPRIVA; }
			}
		else	{ return( 40 ); }	
		}

	return( 0 );
}

UBINAIR	msgaccess( msgfid )
UBINAIR	msgfid;
{
	/* Check Requested file ID */
	/* ----------------------- */
	if ( msgfid >= MSGFILEMAX ) { return( 50 ); }

	/* Test for File Existance */
	/* ----------------------- */
	if (( fileperm[msgfid] & ONSEM_FEXIST ) == 0) { return( 40 ); }

	/* Test for File Sharable  */
	/* ----------------------- */
	if (( fileperm[msgfid] & ONSEM_FPRIVA ) != 0) { 

		/* Test for File Owner REQ */
		/* ----------------------- */
		if (( fileperm[msgfid] & 0x00FF) != npos()) { return( 44 ); }
		}

	/* OK File access granted */
	/* ---------------------- */
	return( 0 );
	
}



UBINAIR	msgfsend( msgfid , msgfbuf, msgflen , msgfperm )
UBINAIR	msgfid;
EXBPTR	msgfbuf;
UBINAIR	msgflen;
UBINAIR	msgfperm;
{
	UBINAIR	lwerr;
	UBINAIR	lwdex;
	struct 	msgfctrl EXSPTR lwptr;

	/* Check for File access rights OK */
	/* ------------------------------- */
	if ( (lwerr = msgaccess(msgfid)) != 0 ) { return(lwerr); }

	/* Check for Correct Message length */
	/* -------------------------------- */
	if ( msgflen > MSGSIZEMAX ) {
		if ( msgfperm & MSG_NOERROR ) {
			msgflen = MSGSIZEMAX;
			}
		else	{ return( 62 ); }
		}

	/* Test for File Not Full */
	/* ---------------------- */
	if ( (lwdex = fileuser[msgfid]) >= MSGQUEUEMAX )   { return( 46 ); }

	lwptr = (struct msgfctrl EXSPTR ) filelink[msgfid];

	(*(lwptr + lwdex)).msgfcid = 
	(*(lwptr + lwdex)).msgfclg = msgflen;
	(*(lwptr + lwdex)).msgfcow = npos();
	(*(lwptr + lwdex)).msgfclk = 0;
	(*(lwptr + lwdex)).msgfctx = (EXBPTR) malloc( msgflen );
	if ( (*(lwptr + lwdex)).msgfctx == (EXBPTR) 0 ) { return( 27 ); }
 	(void) memcpy( (EXBPTR) (*(lwptr + lwdex)).msgfctx , msgfbuf , msgflen );
	fileuser[msgfid]++;
	return(0);
 }

UBINAIR	msgfrecv( msgfid , msgftyp , msgfbuf , msgflen , msgfperm)
UBINAIR	msgfid;
UBINAIR	msgftyp;
EXBPTR	msgfbuf;
UBINAIR	msgflen;
UBINAIR	msgfperm;
{
	UBINAIR	lwerr;
	UBINAIR	lwdex;
	struct 	msgfctrl EXSPTR lwptr;
	UBINAIR	x,y,z,msgfil;

	/* Check for File access rights OK */
	/* ------------------------------- */
	if ( (lwerr = msgaccess(msgfid)) != 0 ) { return(lwerr); }
	
	/* Test for Messages Exist */
	/* ----------------------- */
	if ( (lwdex = fileuser[msgfid]) == 0 ) 	{ return( 48 ) ; }

	lwptr = (struct msgfctrl EXSPTR) filelink[msgfid];

	/* Search for required message type */
	/* -------------------------------- */
	for ( x = 0; x < lwdex; x++ ) {
		if ( (*(lwptr + x)).msgfcid == msgftyp ) { break; }
		}
	if  ( x >= lwdex ) { return( 48 ); }
	
	z = (*(lwptr + x)).msgfclg; msgfil = 0; lwerr = 0;
	
	if ( msgflen > z ) 	{ msgfil = msgflen - z; 	}
	else			{ 
		msgfil = 0; z = msgflen; 
		if (( msgfperm & MSG_NOERROR ) == 0 ) { lwerr = 63; }
		}

 	if ( z > 0 ) 		
		{ 
		(void) memcpy( msgfbuf ,(EXBPTR) (*(lwptr + x)).msgfctx , z ); 
		}
	if ( msgfil > 0 ) 
		{ 
		(void) memset( (msgfbuf + z) , ' ' , msgfil );
		}

	msgliber( (*(lwptr + x)).msgfctx , (*(lwptr + x)).msgfcow );

	lwdex--;
	for ( ; x < lwdex; x++ ) {
		(*(lwptr + x)).msgfcid = (*(lwptr + (x+1))).msgfcid; 
		(*(lwptr + x)).msgfclg = (*(lwptr + (x+1))).msgfclg; 
		(*(lwptr + x)).msgfcow = (*(lwptr + (x+1))).msgfcow; 
		(*(lwptr + x)).msgfclk = (*(lwptr + (x+1))).msgfclk; 
		(*(lwptr + x)).msgfctx = (*(lwptr + (x+1))).msgfctx; 
		}
	fileuser[msgfid] = lwdex;
	return( lwerr );

}

/*
 *	M S G F M A I N ( CodeNGF , Es_Bx )
 *	-----------------------------------
 *	Main entry point for message function requests
 *	CodeNGF	: Code d'operation messagerie
 *	Es_Bx   : Pointeur systeme type ES:BX
 */

UBINAIR	msgfmain( codeNGF , Es_Bx )
UBINAIR	codeNGF;
EXBPTR	Es_Bx;
{
	UBINAIR	lmsgfid;
	EXBPTR	lmsgptr;
	UBINAIR	lmsglen;
	UBINAIR	lmsgtyp;
	UBINAIR	lmsgper;

	lmsgfid = (UBINAIR) *(Es_Bx + 1); codeNGF &= 0x00FF;	

	switch ( codeNGF ) {
		case	0x0040 :	/* Recieve Message 	*/
		case 	0x0080 :	/* Envoi Message	*/
			lmsgptr = *((EXBPTR EXSPTR) (Es_Bx + 3));
			lmsglen = *((EXWPTR) (Es_Bx + 7));
			lmsgper = *((EXWPTR) (Es_Bx + 9));
			if ( codeNGF == 0x0080 ) {
				return( msgfrecv(lmsgfid,lmsgptr,lmsglen,lmsgper));
				}
			lmsgtyp = lmsgper;
			lmsgper = *((EXWPTR) (Es_Bx + 0x000D));
			return( msgfrecv(lmsgfid,lmsgtyp,lmsgptr,lmsglen,lmsgper));
		case	0x0010 :	/* Open File		*/
			return( msgfopen(lmsgfid,0) );
		case	0x0030 :	/* Create File		*/
			return( msgfopen(lmsgfid,IPC_CREAT) );
		case	0x0024 :	/* Close File (Amenesik / Sologic)*/
			return(0);
		default	       : 	/* All the rest		*/
			return( 55 );
		}

}
