/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOSTREAM.H  				*/
/*		Version :	1.4a					*/
/*		Date	:	27/09/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOSTREAM_H
#define	_AOSTREAM_H



#ifndef	UNIX
extern	void	StreamString( BPTR );
extern	void	StreamByte( EXAWORD );
extern	void	StreamLine( void );
#else
#ifdef AIX_VERS
#ifdef LINT_ARGS
extern	void	StreamString( BPTR );
extern	void	StreamByte( EXAWORD );
extern	void	StreamLine( );
#endif
#endif /* AIX_VERS */
#ifndef AIX_VERS
extern	void	StreamString();
extern	void	StreamByte();
extern	void	StreamLine();
#endif
#endif /* AIX_VERS */

/*	Macros for List Generation	*/
/*	--------------------------	*/

#define	oputb( arg1 ) StreamByte( arg1 )
#define oputs( arg1 ) StreamString( (BPTR) arg1 )
#define oline()       StreamLine()

#endif	/* _AOSTREAM_H */
	/* ----------- */

