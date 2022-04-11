/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDIRENT - C				*/
/*		Version :	1.2d / 1.3a / 1.4a			*/
/*		Date 	:	26/04/1990				*/
/*									*/
/*----------------------------------------------------------------------*/

#include <memory.h>
#include <fcntl.h>

#ifdef XENIX386
#include <sys/types.h>
#endif

#ifdef NCR
#include <sys/types.h>
#endif

#ifdef SPIX
#include <sys/types.h>
#endif

#include <sys/dir.h>

#ifdef SPIX
#define	dirent direct
#endif

#ifdef ALTOS
#define ushort unsigned short
#endif

typedef struct {
	int	dirlog;
	long	dirseek;
	} LLDIR;

#ifdef AIX
#define dirent direct
#endif

#ifdef XENIX386
#define dirent direct
#endif

#ifdef NCR
#define dirent direct
#endif

#ifdef ALTOS
#define dirent direct
#endif

struct	dirent Direadzone;

#ifndef SEEK_SET
#define SEEK_SET 0
#endif

/*
 *	R E A D D I R ( DirPtr )
 *	------------------------
 *	Reads and returs a pointer to the next directory entry
 *
 */

struct dirent * readdir( dirptr )
LLDIR * dirptr;
{
	/* Check for Valid directory control structure */
	/* ------------------------------------------- */
	if ( dirptr == (LLDIR * ) 0 ) { return( (struct dirent *) 0 ); }
	do 	{
		/* Seek to current Position */
		/* ------------------------ */
		(void) lseek( (*(dirptr)).dirlog,(*(dirptr)).dirseek,SEEK_SET );
		/* Read the directory entry */
		/* ------------------------ */
		if (read((*(dirptr)).dirlog,&Direadzone,sizeof(struct dirent))!= sizeof(struct dirent)) {
			return( (struct dirent *) 0 );
			}
		/* Adjust current offset */
		/* --------------------- */
		(*(dirptr)).dirseek += sizeof( struct dirent );
		}
	/* Check for and Avoid deleted entries */
	/* ----------------------------------- */
	while ( Direadzone.d_ino == 0 );
	return( &Direadzone );

}

/*
 *	O P E N D I R ( DirNom )
 *	------------------------
 *	Opens the directory file DirNom and returns a pointer to
 *	a directory management structure
 *
 */

LLDIR * opendir( dirnom )
char * dirnom;
{
	LLDIR * ldp;
	int	fid;

	/* Check for existance and Access */
	/* ------------------------------ */
	if ( access(dirnom,0 ) == 0 ) {

		/* Open the Directory File */
		/* ----------------------- */
		fid = open(dirnom , O_RDONLY );
		if ( fid != -1 ) {

			/* Allocate a directory control structure */
			/* -------------------------------------- */
			ldp = (LLDIR * ) malloc( sizeof(struct direct) );
			if ( ldp != (LLDIR *) 0) {

				/* Initialise Control information */
				/* ------------------------------ */
				(*(ldp)).dirlog = fid;
				(*(ldp)).dirseek = 0L;

				/* Return Directory Pointer */
				/* ------------------------ */
				return( ldp );
				}
			/* Close Directory */
			/* --------------- */
			close( fid );	
			}
		}
	/* Return a NULL Pointer to show error */
	/* ----------------------------------- */
	return( (LLDIR *) 0 );

}

/*
 *	C L O S E D I R ( dirptr )
 *	--------------------------
 *	Closes the directory indicated and liberates the control
 *	structure associated
 */

int	closedir( dirptr )
LLDIR * dirptr;
{
	if ( dirptr != (LLDIR * ) 0 ) {
		close( (*(dirptr)).dirlog );
		free( dirptr );
		return(0);
		}
	return( -1 );

}

/*
 *	S E E K D I R ( dirptr , SeekVal )
 *	----------------------------------
 *	Positions to a directory entry 'SeekVal' for
 *	the directory indicated by dirptr
 */

void	seekdir(dirptr , seekval )
LLDIR * dirptr;
long	seekval;
{
	if ( dirptr != (LLDIR *) 0 ) {
		(*(dirptr)).dirseek = seekval;
		}
	return;
}

/*
 *	T E L L D I R ( dirptr )
 *	------------------------
 *	Returns the current directory position of dirptr
 *
 */

long	telldir( dirptr )
LLDIR * dirptr;
{
	if ( dirptr != (LLDIR *) 0 ) {
		return( (*(dirptr)).dirseek );
		}
	else	{
		return(-1L);
	 	}
}

