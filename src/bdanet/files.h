#ifndef	_FILES_H
#define	_FILES_H

#ifdef WIN32 
EXTERN	INT	errno;
#define	FileOpen(a,b)   	_open(a,b)
#define	FileRead(a,b,c) 	_read(a,b,c)
#define	FileWrite(a,b,c) 	_write(a,b,c)
#define	FileClose(a)	 	_close(a)
#define	FileFlush(a)		_close(a)
#define	FilePurge(a)		_close(a)
#define	FileCreate(a)		_creat(a,0666)
#endif

#ifdef	UNIX

EXTERN	INT	errno;
#define	FileOpen(a,b)   	open(a,b)
#define	FileRead(a,b,c) 	read(a,b,c)
#define	FileWrite(a,b,c) 	write(a,b,c)
#define	FileClose(a)	 	close(a)
#define	FileFlush(a)		close(a)
#define	FilePurge(a)		close(a)
#define	FileCreate(a)		creat(a,0666)

	/* ------ */
#else	/* ! UNIX */
	/* ------ */

#ifdef	PROLOGUE

#define	SocketRead(a,b,c) 	sread(a,b,c)
#define	SocketWrite(a,b,c) 	swrite(a,b,c)
#define	SocketClose(a) 		sclose(a)

PUBLIC	INT		FileOpen(BPTR,INT);
PUBLIC	INT		FileRead(INT,BPTR,INT);
PUBLIC	INT		FileWrite(INT,BPTR,INT);
PUBLIC	INT		FileClose(INT);
PUBLIC	INT		FileFlush(INT);
PUBLIC	INT		FilePurge(INT);
PUBLIC	INT		FileCreate(BPTR);

	/* -------- */
#endif	/* PROLOGUE */
	/* -------- */

	/* -------- */
#endif	/* UNIX     */
	/* -------- */

#define	file_puts( h, s ) FileWrite( h, s, strlen(s) )


#endif	/* _FILES_H */
	/* -------- */



