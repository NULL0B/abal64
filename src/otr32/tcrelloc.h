#ifndef	_tcrelloc_h
#define	_tcrelloc_h

/*		---------------------------------			*/
/*		T C O D E _ R E L L O C A T I O N			*/
/*		---------------------------------			*/

struct	tcode_rellocation	{
				/* ------------------------------------ */
	WORD	sector;		/* Sector in which rellocation occurs	*/ 
	WORD	length;		/* Offset into sector (not length!)	*/
	RELOCPTR	next;	/* Next rellocation item in list	*/
				/* ------------------------------------ */
	};


#endif	/* _tcrelloc_h */

