#ifndef	_ixim_h
#define	_ixim_h

extern	WORD	prnflag;

/*	IX IM					*/
/*	-----					*/
/*	Shared printer library for ABAL		*/
/*	and TWIN USE				*/	

/*	NOTE : ONLY 32 printers at a time may	*/
/*	be managed by the library		*/

/*	INITFORM( mode, default, path )	*/
/*	-------------------------------	*/
/*	Should be called once to start	*/
/*	the printer subsytem end to be	*/
/*	default values are set		*/
/*	mode : 1 : use default and path	*/
/*	mode : 0 : no default nor path  */

WORD	initform( int , char * , char * );


/*	IM_OPEN( name, mode )		*/
/*	---------------------   	*/
/*	Returns a file handle 		*/
/*	to be used for all other	*/
/*	functions.			*/

WORD	im_open( BYTE * , WORD );

/*	IM_WRITE( handle, buffer, length )	*/
/*	----------------------------------	*/

VOID	im_write(WORD , BYTE * , WORD );

/*	IM_CLOSE( handle )	*/
/*	------------------	*/

VOID	im_close(WORD );

/*	IM_PUTCH( handle, character )	*/
/*	-----------------------------	*/

VOID	im_putch(WORD );

/*	IM_POS( handle, column, line )	*/
/*	------------------------------ 	*/
/*	positions to logical column	*/
/*	and line using line feed and	*/
/*	space characters.		*/

VOID	im_pos(WORD,WORD,WORD);

/*	IM_COL( handle )		*/
/*	----------------		*/
/*	returns current column number	*/
	
WORD	im_col(WORD );

/*	IM_LIN( handle )		*/
/*	----------------		*/
/*	returns current line number	*/
	
WORD	im_lin(WORD );

/*	FINFORM()			*/
/*	---------			*/
/*	may be called to flush all	*/
/*	printers or prior to closure	*/

VOID	finform();

#endif	/*_ixim_h */

