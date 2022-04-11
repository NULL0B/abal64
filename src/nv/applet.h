//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_applet_h
#define	_html_applet_h

#include "complex.h"
#include "zone.h"
#include "appdesc.h"

class html_applet_component 	: public html_collection_component,
				  public html_applet_descriptor,
				  public html_active_component 	{

public:

	// Derivation of BASIC/COLLECTION METHODS
	// --------------------------------------
	html_applet_component( int t=_HTML_TAG_APPLET );
	virtual void	ondestroy();
	virtual int 	onparse( html_ascii_stream * source );
	virtual void 	generate( html_output * target );
	virtual void	setparent( html_basic_component * member );


	// Derivation of ACTIVE METHODS
	// -----------------------------
	virtual html_basic_component * 	getbasic();
	virtual int			getnature();
	virtual int			getstart();
	virtual void  			setactive(int status);

	// Derivation of ACTIVE_DESCRIPTOR Methods
	// ---------------------------------------
	virtual int			getfirstbyte(int id);
	virtual int			getnextbyte();


	// Data Members of the Applet Class
	// --------------------------------
	static	int			java_enabled;
	html_output_zone	*	window;
	int				windowline;
	int				windowcolumn;


	};


#endif	// _html_applet_h



