#ifndef	_TRTEXT_H
#define	_TRTEXT_H

#define	TCTEXTPTR	struct tcode_text_value XPTR

/*		-------------------------------				*/
/*		T C O D E _ T E X T _ V A L U E				*/
/*		-------------------------------				*/

struct	tcode_text_value	{
	WORD		users;
	VALUEPTR	buffer;
	};

#ifndef		UNIX
TCTEXTPTR	liberate_text_value( TCTEXTPTR );
TCTEXTPTR	allocate_text_value( VOID );
TCTEXTPTR	copy_text_value( TCTEXTPTR );
#else
TCTEXTPTR	liberate_text_value();
TCTEXTPTR	allocate_text_value();
TCTEXTPTR	copy_text_value();
#endif

#endif	/* _TRTEXT_H */
	/* --------- */

