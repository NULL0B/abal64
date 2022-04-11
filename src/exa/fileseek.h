#ifndef	_FILESEEK_H
#define	_FILESEEK_H

#ifndef	UNIX

/*	Unix allows LSEEK/READ/WRITE to any offset.
 *	Amenesik / Sologic,DOS and VMS may not access files at offsets which
 *	are not a multiple of block size
 */

#ifdef	VMS

/*	Redefine SEEK/READ and WRITE		*/
/*	----------------------------		*/
#define	lseek(arg1,arg2,arg3)	Mlseek(arg1,arg2,arg3)
#define	read(arg1,arg2,arg3)	Mread(arg1,arg2,arg3)
#define	write(arg1,arg2,arg3)	Mwrite(arg1,arg2,arg3)
#define	unlink(arg1)		delete( arg1 )

#endif

#endif	/* UNIX */

#endif	/* _FILESEEK_H */
	/* ----------- */

