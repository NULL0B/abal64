#ifndef	_tcxref_h
#define	_tcxref_h

/*		-----------------------------------------		*/
/*		T C O D E _ C R O S S _ R E F E R E N C E		*/
/*		-----------------------------------------		*/
struct	tcode_cross_reference	{
	WORD	type;		/* Type of reference 0 : interne, 1 extern */
	WORD	identity;	/* Proc ID or Segm ID 			   */
	WORD	sector;		/* Sector of reference			   */
	WORD	offset;		/* Offset of reference			   */
	XREFPTR	next;		/* Next in list				   */
	};


#endif	/* _tcxref_h */

