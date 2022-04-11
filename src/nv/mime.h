//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_mime_field_h
#define _html_mime_field_h

#include "string.h"

class	html_mime_field	{

public:
	char		* name;
	char		* value;
	html_mime_field * next;

	html_mime_field( char *nptr=0, char * vptr=0);
	int	compare( char * cptr );
	int	verify( char * cptr );
	char *	locate( char * cptr );
	~html_mime_field();
	
	};



#endif	// _html_mime_field_h




