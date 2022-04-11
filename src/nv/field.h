//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_tag_field_h
#define	_html_tag_field_h

#include "types.h"

class	html_ascii_stream;
class	html_output;
class   html_tag_field;

#include "syntax.h"
#include "mime.h"

//	--------------------------------------------------------------------
//			H T M L _ T A G _ F I E L D
//	--------------------------------------------------------------------
class	html_tag_field : public html_string {

	static	char *	valuebuffer;

public:
	char *	name;
	int	parsed;
	html_tag_field( const char * vptr="!" );
		int	checkname( char * nptr );
		int 	onparse( char * tagname, html_ascii_stream * source );
	virtual	int  	setvalue( char * bptr );
	virtual void 	generate( html_output * target );
	static	int 	garbage_collection();
	};

//	--------------------------------------------------------------------
//			H T M L _ I N T E G E R _ F I E L D
//	--------------------------------------------------------------------
class	html_integer_field : public html_tag_field {

public:
	int	value;
	html_integer_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );

	int	percentage;
	};

//	--------------------------------------------------------------------
//			H T M L _ P E R C E N T _ F I E L D
//	--------------------------------------------------------------------
class	html_percent_field : public html_tag_field {

public:
	int	value;
	int	percentage;
	html_percent_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );
		int 	percentageof( int wholevalue );

	};

//	--------------------------------------------------------------------
//			H T M L _ C O L O U R _ F I E L D
//	--------------------------------------------------------------------
class	html_colour_field : public html_tag_field,
			    public html_colour	 {

public:
	html_colour_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );
		int	approximation();
	};

//	--------------------------------------------------------------------
//			H T M L _ S T R I N G _ F I E L D
//	--------------------------------------------------------------------
class	html_string_field : public html_tag_field {

public:
	char	* value;
	html_string_field( const char * vptr );
	~html_string_field();
	virtual	int	setvalue( char * bptr );
	virtual void 	generate( html_output * target );

	};

//	--------------------------------------------------------------------
//			H T M L _ U P P E R C A S E _ F I E L D
//	--------------------------------------------------------------------
class	html_uppercase_field : public html_string_field {

public:
	html_uppercase_field( const char * vptr );
	~html_uppercase_field();
	virtual	int	setvalue( char * bptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ L O W E R C A S E _ F I E L D
//	--------------------------------------------------------------------
class	html_lowercase_field : public html_string_field {

public:
	html_lowercase_field( const char * vptr );
	~html_lowercase_field();
	virtual	int	setvalue( char * bptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ D A T E _ F I E L D
//	--------------------------------------------------------------------
class	html_date_field : public html_string_field {

public:
	html_date_field( const char * vptr );
	int	compare( html_date_field * xptr );
	int	compare( char * cptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ U R L _ F I E L D
//	--------------------------------------------------------------------
class	html_url_field	: public html_tag_field {

public:
	standard_url * value;
	html_url_field( const char * vptr );
	~html_url_field();
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ I N P U T _ F I E L D
//	--------------------------------------------------------------------
class	html_input_field	: public html_tag_field {

public:
	int	value;
	html_input_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ S H A P E _ F I E L D
//	--------------------------------------------------------------------
class	html_shape_field	: public html_tag_field {

public:
	int	value;
	html_shape_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );

	};

//	--------------------------------------------------------------------
//			H T M L _ B O O L E A N _ F I E L D
//	--------------------------------------------------------------------
class	html_boolean_field	: public html_tag_field {

public:
	int	value;
	html_boolean_field( const char * vptr );
	virtual void 	generate( html_output * target );
	virtual	int	setvalue( char * bptr );

	};

#include "field.h"	// Names of all fields

#endif	// _html_tag_field_h











