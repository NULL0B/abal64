/*----------------------------------------------------------------------
 *									
 *		E X E C U T E U R 	A . B . A . L			
 *		-------------------------------------			
 *									
 *		Copyright (c) 1987,1996 Amenesik / Sologic S.A.			
 *									
 *		Module  :	EXLLFIND - C				
 *		Version	:	2.1d					
 *		Date 	:	13/05/1996				
 *									
 *----------------------------------------------------------------------*
 * Gestion des catalogues disques pour MS DOS et UNIX et VMS		*
 *----------------------------------------------------------------------*/
/* ----------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	22/02/96 : exadosfirst et exadosnext -> recherche des repertoires
 *			support des noms longs pour NT et WIN95 	 
 *  13/05/96 : ASS_FIND_VALID pour NT/95
 *  04/05/99 : Correction d'un dépassement de taille de buffer dans la fonction dir_seek().
 */


#include "exngf.h"

#ifdef DOS

#ifndef WIN32

#define	FICBUFFLEN		64
#define	ATTRIBOFFSET		21
#define	FILENAMEOFFSET		0x001E
#define	FILESIZEHIGHOFFSET	28
#define	FILESIZELOWOFFSET	26
#define	FILEDATEOFFSET		24
#define	FILETIMEOFFSET		22

#else

#define	FICBUFFLEN		276
#define	ATTRIBOFFSET		0
#define	FILENAMEOFFSET		0x0009
#define	FILESIZEHIGHOFFSET	7
#define	FILESIZELOWOFFSET	5
#define	FILEDATEOFFSET		3
#define	FILETIMEOFFSET		1
#define SEEKHANDLEOFFSET	269

#endif


EXAWORD	dir_seek( rptr , rlen , pptr , plen , mode )
BPTR	rptr;
EXAWORD	rlen;
BPTR	pptr;
EXAWORD	plen;
EXAWORD	mode;
{
	EXAWORD	exadosfirst(BPTR,BPTR,EXAWORD);
	EXAWORD	exadosnext(BPTR);
	EXAWORD	loclen,c,lerr;
	EXAWORD	ecart=0;
	EXAWORD	temp;
	BPTR	tptr;
#ifdef WIN32
	EXALONG	SeekHandle = 0L;
#endif

	if (mode & 0x0020) {
		ecart = 11;
		rptr += ecart;
		rlen -= ecart;
		}

	/* Test if buffer already allocated */
	/* -------------------------------- */
	if (( fidperm & ASS_BUFF_VALID ) == 0 ) {

		/* Attempt to allocate buffer for FIND operations */
		/* ---------------------------------------------- */
		if ( (fidbuff = (BPTR) allocate( (USINT) FICBUFFLEN ) ) == (BPTR) 0) {
			err_val = ABAL_MEMORY; 
			return(MOINS_UN);
			}

#ifdef WIN32
		/* A defaut, pas de handle de recherche */
		memcpy((BPTR)(fidbuff + SEEKHANDLEOFFSET),(BPTR)&SeekHandle,4);		
		fidperm |= ASS_FIND_VALID;
#endif

		/* Indicate allocated FIND buffer */
		/* ------------------------------ */
		fidperm |= ASS_BUFF_VALID;
		}

	while ( 1 ) {	/* DOS does not separate files from directories */

		/* Separate FIND FIRST from FIND NEXT */
		/* ---------------------------------- */
		if ( (mode & 1 ) == 0 ) {

			/* Check for space in buffer for terminator */
			/* ---------------------------------------- */
#ifdef WIN32
			if ((loclen = lenuzend(pptr,plen)) == plen) {
#else
			if ((loclen = lenuze(pptr,plen)) == plen) {
#endif
				/* Duplicate in current ASK buffer */
				/* ------------------------------- */
				memcpy((BPTR) askbuf,pptr,plen); 
				pptr = (BPTR) askbuf;
				}

			/* Collect current last byte and save */
			/* ---------------------------------- */
			c = *(pptr + loclen);

			/* Establish DOS 'C' terminator */
			/* ---------------------------- */
			*(pptr + loclen) = (EXABYTE) 0;

			/* Perform Operation then replace previous byte */
			/* -------------------------------------------- */
			lerr = exadosfirst(fidbuff,pptr,mode);
			*(pptr + loclen) = c;
			}
		else	/* Perform FIND NEXT */
			/* ----------------- */
			lerr = exadosnext(fidbuff);	

		mode |= 1;	/* Force to NEXT */

		/* Check for system error */
		/* ---------------------- */
		if ( lerr == 0 ) {

			/* Filter out files if directories required */
			/* ---------------------------------------- */
			if (( mode & 0x0010 ) != (*(fidbuff + ATTRIBOFFSET) & 0x0010))
				continue;

			/* Ok Somethng has been found */
			/* -------------------------- */
			if ((loclen = strlen( (BPTR) (fidbuff + FILENAMEOFFSET) )) > rlen ) {
				errno = 63; 
				lerr = MOINS_UN;
				loclen = rlen;
				}
			else	errno = 0;

			/* Prewipe buffer with spaces */
			/* -------------------------- */
			if ( rlen   > 0 ) 
				memset( rptr , ' ' , rlen );

			/* Copy found filename to result buffer */
			/* ------------------------------------ */
			if ( loclen > 0 ) 
				memcpy( rptr , (BPTR) (fidbuff + FILENAMEOFFSET ) , loclen );

			if ( ecart != 0 ) {

				/* Informations sur le fichier */
				rptr -= ecart;
				memset( rptr, 0, ecart );
				tptr = (BPTR) fidbuff;
		
				/* File size */
				temp = Tcodeword( (tptr + FILESIZEHIGHOFFSET) );
				balputw( temp, (rptr + 7) );
				temp = Tcodeword( (tptr + FILESIZELOWOFFSET) );
				balputw( temp, (rptr + 9) );
		
				/* Date de modif */
				temp = Tcodeword( (tptr + FILEDATEOFFSET) );
				*(rptr + 3) = (temp & 0x001F);
				*(rptr + 2) = ((temp >> 5) & 0x000F);
				temp = ((temp >> 9) & 0x003F);
				temp += 1980;
				balputw( temp, rptr );
		
				/* Heure de modif */
				temp = Tcodeword( (tptr + FILETIMEOFFSET) );
				*(rptr + 6) = ((temp & 0x001F) << 1);
				*(rptr + 5) = ((temp >> 5) & 0x003F);
				*(rptr + 4) = ((temp >> 11) & 0x001F);	
				}
			return(lerr);
			}
		else	{
			errno = 40;	
			return(MOINS_UN);  
			}
		}
}
#endif

#ifdef UNIX

	/* Directory seek function for UNIX */
	/* -------------------------------- */
#define	PATHTERM	'/'
#define	PATHSYMBOL	"/"

	/* Parametrage en fonction du Systeme Hote */
	/* --------------------------------------- */

#ifdef GENIX	/* FORUM 3210 FORUMIX GENIX */
		/* ------------------------ */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef	ultrix	/* VAX ULTRIX */
		/* ---------- */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef SPIX	/* BULL Q700 DPX2000 SPIX  et BOS DPX/2 */
		/* ----------------------  ------------ */
#include <dirent.h>
#define	ABALFIND
#endif

#ifdef LSX	/* OLIVETTI LSX X/OS	*/
		/* -----------------	*/
#include <sys/dir.h>
#define ABALFIND
#define dirent direct
#endif

#ifdef XSUPERTEAM	/* SUPTERTEAM SPIX LIKE */
			/* -------------------- */
#include <sys/dir.h>
#define ABALFIND
#define dirent direct
#endif

#ifdef SUPERTEAM	/* SUPTERTEAM SPIX LIKE */
			/* -------------------- */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef HP9000		/* HEWLET PACKARD 9000 */
			/* ------------------- */
#include <sys/dir.h>
#define ABALFIND
#define dirent direct
#endif

#ifdef XENIX386		/* SCO XENIX 386 */
			/* ------------- */
#include <sys/dir.h>
#include "exdirent.h"
#define ABALFIND
#define dirent direct
#endif

#ifdef IX386		/* INTERACTIVE UNIX IX 386 */
			/* ----------------------- */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef NCR		/* NCR TOWER */
			/* --------- */
#include <sys/dir.h>
#include "exdirent.h"
#define ABALFIND
#define dirent direct
#endif

#ifdef RT_AIX		/* IBM RT6150 AIX */
			/* -------------- */
#include <dirent.h>
#define ABALFIND
#define	ABALGCWD
#endif

#ifdef AIX_VERS
#ifdef SPARC		/* SOLARIS SPARC           */
			/* ----------------------- */
#include <dirent.h>
#define ABALFIND
#endif
#endif /* AIX_VERS */

#ifdef PS_AIX		/* PC SERVER 2000 CONVERGANT UNISYS ALCATEL */
			/* ---------------------------------------- */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef UNISYS		/* PC SERVER 2000 CONVERGANT UNISYS ALCATEL */
			/* ---------------------------------------- */
#include <dirent.h>
#define ABALFIND
#endif

#ifdef ALTOS		/* ALTOS 1000 2000 etc	*/
			/* -------------------	*/
#include <sys/dir.h>
#include "exdirent.h"
#define ABALFIND
#define dirent direct
#endif

#ifdef ABALFIND
struct	findwork {
	EXALONG	pathdex;
	EXABYTE	pathbuf[FNMAX];
	EXABYTE	pathsel[FNMAX];
	};

struct findwork SPTR pathwork;

EXABYTE	statchker[65];
struct stat StatGetZ;

EXAWORD	wildchk( pptr , plen )
BPTR	pptr;
EXAWORD	plen;
{
	EXAWORD	wild;
	wild = 0;
	while ( plen > 0 ) {
		if ( *pptr == '?' ) { return(wild); }
		if ( *pptr == '*' ) { return(wild); }
		pptr++; plen--; wild++;
		}
	return(MOINS_UN);

}

EXAWORD	pathchk( pptr , plen )
BPTR	pptr;
EXAWORD	plen;
{
	EXAWORD	wild,pflg;
	wild = 0; pflg = MOINS_UN;
	while ( plen > 0 ) {
		if ( *pptr == PATHSEP ) { pflg = wild; }
		pptr++; plen--; wild++;
		}
	return(pflg);
}

VOID	initpath( pptr , plen )
BPTR	pptr;
EXAWORD	plen;
{
	EXAWORD	x,y;
	(*(pathwork)).pathdex = 0;
	plen = lenuze(pptr,plen);
	if ( plen == 0 ) {
		(*(pathwork)).pathbuf[0] = '.';
		(*(pathwork)).pathbuf[1] = FILETERM;
		(*(pathwork)).pathsel[0] = '*';
		(*(pathwork)).pathsel[1] = FILETERM;
		return;
		}
	x = pathchk( pptr , plen );
	if ( x == MOINS_UN ) {
		(*(pathwork)).pathbuf[0] = '.';
		(*(pathwork)).pathbuf[1] = FILETERM;
		memcpy ( (*(pathwork)).pathsel , pptr , plen );
		(*(pathwork)).pathsel[plen] = FILETERM;
		return;
		}
	else	{
		x++;
		memcpy ( (*(pathwork)).pathbuf , pptr , x );
		(*(pathwork)).pathsel[x] = '.';
		(*(pathwork)).pathsel[x+1] = FILETERM;
		if ( x >= plen ) {
			(*(pathwork)).pathsel[0] = '*';
			(*(pathwork)).pathsel[1] = FILETERM;
			}
		else	{
			y = plen - x;
			memcpy( (*(pathwork)).pathsel , ( pptr + x ) , y);
			(*(pathwork)).pathsel[y] = FILETERM;
			}
		return;
		}
}

EXAWORD	wildcomp( tptr , wptr )
BPTR	tptr;
BPTR	wptr;
{
	EXAWORD	wlen,tlen;

	wlen = strlen(wptr); tlen = strlen(tptr);

	while (( tlen > 0 ) && (wlen > 0)) {

		switch ( *wptr ) {
			case '*' : if ( wildcomp( tptr , (wptr + 1)) == 0 ) {
					return(0);
					}
				   tptr++; tlen--;
				   continue; 
			default  : if ( *tptr != *wptr ) { return(MOINS_UN); }
			case '?' : wptr++; tptr++; wlen--; tlen--; continue;
			}
		}
	if (( tlen == 0 ) && ( wlen == 0 )) { return(0); }
	if ( tlen == 0 ) {
		while ( wlen > 0 ) {
			if (( *wptr != '*' ) && ( *wptr != '?' )) { return(MOINS_UN); }
			wlen--; wptr++;
			}
		return(0);
		}
	if (( wlen == 0 ) && ( *(wptr - 1) == '*')) { return(0); }
	return(MOINS_UN);

}

#define YEARDOT  1900
#define	MOISDOT	 1
#include <time.h>

EXAWORD	finder( pathid, rptr ,rlen, ecart, mode )
DIR	*pathid;
BPTR	rptr;
EXAWORD	rlen;
EXAWORD	ecart;
EXAWORD	mode;
{
	BPTR	xptr;
	struct	dirent * dirptr;
	EXAWORD	x,y,z;
	EXAWORD	wildflg;
	EXAWORD	temp;
	struct tm * LocalTime;
	EXALONG		unixtime;

	xptr = rptr;
	wildflg = wildchk( (*(pathwork)).pathsel , strlen((*(pathwork)).pathsel) );
	while ( (dirptr = (struct dirent *) readdir( pathid )) != (struct dirent *) 0 ) {
		strcpy((BPTR) statchker , (*(pathwork)).pathbuf );
		if ( *(statchker + strlen((BPTR) statchker)) != PATHTERM ) {
			strcat((BPTR) statchker, PATHSYMBOL );
			}
		strcat((BPTR) statchker , dirptr->d_name );
		if ( stat((BPTR) statchker , &StatGetZ ) != 0 ) { continue; }

		if (( StatGetZ.st_mode & S_IFDIR ) == S_IFDIR) { 
			if (!( mode & 0x0010 ))
				continue;
			}
		else if (mode & 0x0010)
			continue;

		if ( wildflg == MOINS_UN ) { /* Simple File Check */
					     /* ----------------- */
			if ( strcmp( dirptr->d_name , (*(pathwork)).pathsel) != 0 ) {
				continue;
				}
			}
		else	{ /* Wild card checking */
			  /* ------------------ */
			if ( wildcomp(dirptr->d_name,(*(pathwork)).pathsel) != 0) {
				continue;
				}
			}
		x = strlen( dirptr->d_name ); z = 0;
		while (( x > 0 ) && ( rlen > 0 )) {
			*(rptr++) = dirptr->d_name[z++];
			x--; rlen--;
			}			
		while ( rlen > 0 ) { *(rptr++) = ' '; rlen--; }
		if ( ecart ) {
			rptr = (xptr - ecart);

			/* File size */
			temp = (EXAWORD) (StatGetZ.st_size >> 16 );
			balputw( temp, (rptr + 7) );

			temp = (EXAWORD) (StatGetZ.st_size);
			balputw( temp, (rptr + 9) );
	
			unixtime = StatGetZ.st_mtime;

			/* Convert to Local Time */
			/* --------------------- */
			LocalTime = (struct tm * ) localtime(&unixtime);
			/* Date de modif */

			*(rptr + 3) = LocalTime->tm_mday;
			*(rptr + 2) = MOISDOT + LocalTime->tm_mon;
			balputw((YEARDOT + LocalTime->tm_year), rptr );

			/* Heure de modif */
			*(rptr + 6) = LocalTime->tm_sec;
			*(rptr + 5) = LocalTime->tm_min;
			*(rptr + 4) = LocalTime->tm_hour;

			}
		if ( x != 0 ) { return(63); }
		else	      { return(0);  }
		}
	return(40);
}

EXAWORD	dir_seek( rptr , rlen , pptr , plen , mode )
BPTR	rptr;
EXAWORD	rlen;
BPTR	pptr;
EXAWORD	plen;
EXAWORD	mode;
{
	DIR	*tmptr;
	EXAWORD	lerr;
	EXAWORD	ecart=0;

	lerr = MOINS_UN;


	if (mode & 0x0020) {
		if (rlen < 11) {
			err_val = 122;
			return( MOINS_UN );
			}
		else	{
			memset( rptr, 0, (ecart=11) );
			rptr += ecart;
			rlen -= ecart;
			}
		}

if (( fidperm & ASS_BUFF_VALID ) == 0 ) {
	if ( (fidbuff = (BPTR) malloc( sizeof( struct findwork ))) == (BPTR) 0) {
		err_val = ABAL_MEMORY; 
		return(MOINS_UN);
		}
	memset( fidbuff , (USINT) 0 , (USINT) sizeof( struct findwork ) );
	fidperm |= ASS_BUFF_VALID;
	}
pathwork = (struct findwork SPTR) fidbuff;
	if (( mode & 1 ) == 0 ) { 
		initpath( pptr , plen ); 
		}
	if ((tmptr = opendir( (*(pathwork)).pathbuf )) != (DIR *) 0) {
		seekdir( tmptr , (*(pathwork)).pathdex );
		lerr =	finder( tmptr, rptr , rlen, ecart,mode );
		(*(pathwork)).pathdex = telldir( tmptr );
		closedir( tmptr );
		if ( lerr == 0 ) { return(0); }
		}
	/* Directory Errors */ 
	/* ---------------- */
	if ( lerr != MOINS_UN ) { errno = lerr; }
	else			{ errno = 40;	}
	return(MOINS_UN);
}

#else	/* ndef ABALFIND */
EXAWORD	dir_seek( rptr , rlen , pptr , plen , mode )
BPTR	rptr;
EXAWORD	rlen;
BPTR	pptr;
EXAWORD	plen;
EXAWORD	mode;
{
	errno = 56;
	return(MOINS_UN);
}
#endif
#endif

#ifdef	VMS	/* def VMS	 */

/*	Prototypes of VMS lowlevel functions	*/
/*	------------------------------------	*/
extern	EXAWORD	findfirst(BPTR , BPTR SPTR);
extern	EXAWORD	findnext(EXAWORD , BPTR SPTR);
extern	EXAWORD	findclose(EXAWORD);


/* 	Directory seek function for VMS  	*/
/* 	-------------------------------- 	*/

EXAWORD	dir_seek( rptr , rlen , pptr , plen , mode )

			/* -------------------- */
BPTR	rptr;		/* Result Pointer	*/
EXAWORD	rlen;		/* Result Length	*/
BPTR	pptr;		/* Search Pointer	*/
EXAWORD	plen;		/* Search Length	*/
EXAWORD	mode;		/* First or Next MODE	*/
			/* -------------------- */

{
	BPTR	lrptr;
	EXAWORD	lerr;
	EXAWORD	loclen;
	EXAWORD	c;

	/* Initialise Local Result pointer */
	/* ------------------------------- */
	lrptr = (BPTR) 0;

	/* Check for a Find (F) */
	/* -------------------- */
	if ( (mode & 1 ) == 0 ) {

		/* Check for Already Opened Handle */
		/* ------------------------------- */
		if ((fidperm & ASS_FIND_VALID ) != 0) {
			
			/* Close to liberate VMS searcher */
			/* ------------------------------ */
			(VOID) findclose( fidbd );

			}

		/* Calculate usable String Length */
		/* ------------------------------ */
		loclen = lenuze(pptr,plen);

		/* Might need copied for Termination */
		/* --------------------------------- */
		if ( loclen == plen ) {

			/* Copy it to temporary storage */
			/* ---------------------------- */
			memcpy((BPTR) askbuf,pptr,plen);
			pptr = (BPTR) askbuf;
			}
		
		/* Save Character and Terminate */
		/* ---------------------------- */
		c = *(pptr + loclen);
		*(pptr + loclen) = (EXABYTE) 0;

		/* Perform Find First low-level Call */
		/* --------------------------------- */ 
		lerr = (EXAWORD) findfirst((BPTR) pptr , (BPTR SPTR) & lrptr );

		/* Replace Byte */
		/* ------------ */
		*(pptr + loclen) = c;

		/* Check for Errors */
		/* ---------------- */
		if (( lerr == 0 ) || ( lerr == MOINS_UN )) {

			/* Indicate end of Catalogue */
			/* ------------------------- */
			err_val = 48; return(MOINS_UN);
			}
		/* Storage Find access Handle */
		/* -------------------------- */
		fidperm |= ASS_FIND_VALID;
		fidbd    = lerr;
		}

	else	{

		if (( fidperm & ASS_FIND_VALID) != 0 ) {

			/* Perform Find (N) operation */
			/* -------------------------- */
			lerr = (EXAWORD) findnext(fidbd , (BPTR SPTR) & lrptr);	

			/* Check for Errors */
			/* ---------------- */
			if (( lerr == 0 ) || ( lerr == MOINS_UN )) {

				/* Indicate end of Catalogue */
				/* ------------------------- */
				err_val = 48; return(MOINS_UN);
				}
			}

		else	{
			err_val = 42; return(MOINS_UN);
			}

		}

	/* Reset Data Result Zone to SPACE()	*/
	/* ---------------------------------	*/	
	memset((BPTR) rptr , ' ' , (USINT) rlen );

	/* Calculate Result Length */
	/* ----------------------- */
	if ((lerr = strlen((BPTR) lrptr)) > 0) {

		/* Transfer to DATA Result Zone */
		/* ---------------------------- */
		memcpy((BPTR) rptr , (BPTR) lrptr , (USINT) (lerr > rlen ? rlen : lerr ));

		}

	/* Return to Caller */
	/* ---------------- */
	if ( lerr > rlen ) { 
		err_val = 63;
		return( MOINS_UN );
		}
	else	{
		err_val = 0;
		return(0);
		}

}
#endif

#ifdef	ABALGCWD

VOID	catstr( rptr , sptr )
BPTR	rptr;
BPTR	sptr;
{
	char	Work[65];
	strcpy(Work , rptr);
	strcpy(rptr , sptr);
	strcat(rptr , Work);
	return;
}

BPTR	GetCwd( resptr , reslen )
BPTR	resptr;
int	reslen;
{
	DIR	*tmptr;
	struct	dirent * dirptr;
	EXALONG	dotnode,dotdotnode,seeknode;
	EXALONG	dotunit,dotdotunit,seekunit;
	EXAWORD	lerr,l;
	char	PathBuf1[65];
	char	WorkBuf[65];
	char	NameStat[65];
	EXAWORD	Level,status;

	/* Test for Nul Pointer and Allocate if needed */
	/* ------------------------------------------- */
	if ( resptr == (BPTR) 0 ) {
		if ((resptr = (BPTR) malloc( (USINT) 65)) == (BPTR) 0 ) {
			errno = 8;
			return((BPTR) 0);
			}
		}
	
	/* Initialise WorkZones */
	/* -------------------- */
	Level = 0; strcpy(PathBuf1,"."); 
	strcpy((BPTR) WorkBuf , (BPTR) "/" );

while ( 1 ) {
	/* Find the I-Node of Our Current Level of Directory Tree */
	/* ------------------------------------------------------ */
	if ((tmptr = opendir( PathBuf1 )) != (DIR *) 0) {
		seekdir( tmptr , 0 );

		/* Establish Unique Identity of "*." */
		/* --------------------------------- */
		if (stat( PathBuf1 , &StatGetZ ) != 0 ) {
			/* Error Here */
			/* ---------- */
			catstr( WorkBuf , "ErreurStatdot" );
			strcpy( resptr  , WorkBuf );
			closedir(tmptr);
			return( resptr );
			}
		dotnode = StatGetZ.st_ino; 
		dotunit = StatGetZ.st_dev; 

		if ((dirptr = readdir( tmptr )) == (struct dirent *) 0 ) {
			/* ERROR HERE */
			/* ---------- */
			catstr( WorkBuf , "Erreurdot" );
			strcpy( resptr  , WorkBuf );
			closedir(tmptr);
			return( resptr );
			}

		/* Establish Unique Identity of "*.." */
		/* --------------------------------- */
		l = strlen( PathBuf1 );
		PathBuf1[l]	= '.';
		PathBuf1[l+1]	= (EXABYTE) 0;

		if (stat( PathBuf1 , &StatGetZ ) != 0 ) {
			/* Error Here */
			/* ---------- */
			catstr( WorkBuf , "ErreurStatdot" );
			strcpy( resptr  , WorkBuf );
			closedir(tmptr);
			return( resptr );
			}
		PathBuf1[l]	= (EXABYTE) 0;
		dotdotnode = StatGetZ.st_ino;  
		dotdotunit = StatGetZ.st_dev; 

		if ((dirptr = readdir( tmptr )) == (struct dirent *) 0 ) {
			/* ERROR HERE */
			/* ---------- */
			catstr( WorkBuf , "Erreurdotdot" );
			strcpy( resptr  , WorkBuf );
			closedir(tmptr);
			return( resptr );
			}

		/* Check for INODE Seek Required */
		/* ----------------------------- */
		if ( Level > 0 ) {
			status = 0;
			do	{
				/* Read Directory Entry */
				/* -------------------- */
				if ((dirptr = readdir( tmptr )) == (struct dirent *) 0 ) {
					/* ERROR HERE */
					/* ---------- */
					catstr( WorkBuf , "ErreurSeek" );
					strcpy( resptr  , WorkBuf );
					closedir(tmptr);
					return( resptr );
					}
				/* Create Full Path Name for Stat */
				/* ------------------------------ */
				strcpy(NameStat,PathBuf1);
				strcpy(&NameStat[l-1],dirptr->d_name);

				/* Get Stat infos NODE/UNIT */
				/* ------------------------ */
				if ( stat(NameStat,&StatGetZ) != 0 ) {
					/* Errors Here */
					/* ----------- */
					catstr( WorkBuf , "ErreurStat" );
					strcpy( resptr  , WorkBuf );
					closedir(tmptr);
					return( resptr );
					}
				/* Test for NODE/UNIT Matching Request */
				/* ----------------------------------- */
				if ((  StatGetZ.st_ino == seeknode ) && (  StatGetZ.st_dev == seekunit )) {
					status = 1;
					}
				}
			while ( status == 0 );
									
			/* OK GOTCHA so Insert the Name of the Directory */
			/* --------------------------------------------- */
			catstr((BPTR) WorkBuf, dirptr->d_name );
			catstr((BPTR) WorkBuf , (BPTR) "/" );

			}

		/* Check for Top of Tree ("." == "..") */
		/* ----------------------------------- */
		if ( dotnode == dotdotnode ) {
			if ( dotunit == dotdotunit ) {
				/* We Have Finished OK */
				/* ------------------- */
				strcpy( resptr  , WorkBuf );
				closedir(tmptr);
				return( resptr );
				}
			}

		/* Adjust Level Counter */
		/* -------------------- */
		Level++; 
		seeknode = dotnode;
		seekunit = dotunit;

		/* Close this Level */
		/* ---------------- */
		closedir( tmptr );

		/* Insert yet another "../" */
		/* ------------------------ */
		catstr(PathBuf1,"../");
		}
	}
}

#endif

