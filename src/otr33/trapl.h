#ifndef	_TRAPL_H
#define	_TRAPL_H

/*	APL Class description Member Record Types	*/
/*	-----------------------------------------	*/

#define	_APL_NULL	0
#define	_APL_DATA	1
#define	_APL_OBJECT	2
#define	_APL_BASECLASS	3
#define	_APL_INHERIT	4
#define	_APL_CONST	5
#define	_APL_METHOD	6
#define	_APL_FRIEND	7
#define	_APL_LIBRARY	8

/*	Offset values into sector Zero of APL	*/
/*	-------------------------------------   */
#define _APL_OPTIONS_BYTE 	0x0012
#define _APL_CLASS_SECTOR 	((((0x0016-20)/2)*AplHandle->WordSize)+20)
#define	_APL_CRYPT_CODE 	(((( 0x001E - 20)/2)*AplHandle->WordSize)+20)
#define	_APL_LIBRARY_SECTOR 	((((0x0020-20)/2)*AplHandle->WordSize)+20)
#define	_APL_SYMBOLS_SECTOR 	((((0x0022-20)/2)*AplHandle->WordSize)+20)


#define	APLIDXPTR	struct apl_index_entry XPTR
#define	APLPTR		struct apl_input XPTR
#define	TCAPLPTR	struct apl_log XPTR
#define	APLSYMBPTR	struct apl_symbolic_entry XPTR


struct	apl_input	{
	WORD		handle;
	BPTR		name;
	BYTE		buffer[256];
	WORD		sector;
	WORD		offset;
	WORD		CryptCode;
	WORD		WordSize;
	WORD		Options;
	APLSYMBPTR	Symbolic;
	APLPTR	next;
	};

struct	apl_symbolic_entry	{
	WORD		logical;	/* Number inside APL 	*/
	WORD		resolved;	/* Number inside WORLD 	*/
	APLSYMBPTR	next;
	};

struct	apl_index_entry	{
	TCSTRUCTPTR	class;
	WORD		sector;
	WORD		offset;
	APLIDXPTR	next;
	};

struct	apl_log	{
	BPTR		name;
	TCAPLPTR	next;
	};

#ifdef	_TRAPL_C
	APLIDXPTR		AplIndex=(APLIDXPTR) 0;
	APLSYMBPTR		AplSymbol=(APLSYMBPTR) 0;
	APLPTR			AplHandle=(APLPTR)  0;
	TCAPLPTR		AplRoot=(TCAPLPTR) 0;
	TCAPLPTR		AplFoot=(TCAPLPTR) 0;
#endif

#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifndef	UNIX
/* For traplio.c */
WORD	await_target_end( VOID );
BPTR	library_file_name( VOID );
/* For trgetapl.c */
WORD	translate_use( BPTR );
/* For trputapl.c */
WORD	instance_library( VOID );
WORD	flush_library_index_table( VOID );
#else
#endif

#endif	/* _TRAPL_H */
