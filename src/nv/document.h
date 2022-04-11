//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------

#ifndef  _html_document_h 
#define  _html_document_h 

#include "html4.h"

#include "palette.h"
#include "trace.h"

class	html_document 	: public html_based_component 	{

	html_logical_palette * colours;
	html_entity 	     * wherefrom;
public:
	static	int		contract;
	int			redimension;
	int			useheader;
	int			users;
	html_document(int t=_HTML_TAG_HTML);
	~html_document();
	int 			navigate(html_output * target, standard_url * hyperlink );
	virtual int		addmember( html_basic_component * member );
	virtual int 		addtext( int c );
	virtual	html_basic_component * 	addactive( html_active_component * aptr );
	virtual void		ondestroy();
	virtual int		ontrace( html_output * target );
	virtual void		addmime( html_mime_field * mptr );
	virtual void		usetext( char * tptr );
	virtual	int		checktimer(standard_url * hyperlink);
	virtual void    	setpending( html_pending_image * pptr );
	void			release();
	int			resolve_anchor( char * target );
	void			position(html_output * target);
	void			hardcopy( html_output * target, int mode );
	virtual	html_basic_component* 	getmap(char * nptr);
	virtual	void	 	addmap(html_basic_component * nptr);
	html_title_component *	gettitle();
	html_form_component *	getform();
	html_document 		*previous;
	html_document 		*next;
	html_mime_field		*firstmime;
	html_mime_field		*lastmime;
	html_active_component	*firstactive;
	html_active_component	*lastactive;
	html_active_component	*currentactive;
	html_map_component	*maplist;
	int			started;
	int			topline;
	int			tracemode;
	html_layout  		* LayoutManager;
	char		        * SeekLabel;
	static	html_form_component *	working_form;
	int			canreload;
private:
	void			render(html_output * target);
	cssi_selector *		styleroot;
	int			timeout;
	unsigned long		worktime;
	char	*		targeturl;
	int			labeled;
	static	char searchbuffer[80];
	int			ready;
	};


#endif // _html_document_h 



