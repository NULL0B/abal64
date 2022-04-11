//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_active_h
#define	_html_active_h


class	html_active_component 	{

public:

	virtual	int			chkevent( html_logical_event * eptr );
	virtual	int			getevent( html_output * target, int topline );
	virtual html_basic_component * 	getbasic();
	virtual int			getnature();
	virtual char *			getprompt();
	virtual int			getstart();
	virtual	int			canfocus();
	virtual	int			validate( standard_url * uptr, char * bptr );
	virtual void			setactive(int status);
	virtual	int			compare( char * cptr );
	html_active_component();


	html_active_component * upactive;
	html_active_component * downactive;

	};

#endif // _html_active_h


