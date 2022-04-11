#ifndef	_tcblock_h
#define	_tcblock_h

/*		---------------------					*/
/*		T C O D E _ B L O C K					*/
/*		---------------------					*/

struct	tcode_block {
	WORD	code_sector;
	WORD	code_length;
	WORD	table_sector;
	WORD	table_length;
	WORD	const_sector;
	WORD	const_length;
	};

#endif	/* _tcblock_h */

