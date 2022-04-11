//	------------------------------------------------------------------
//	Project		Web Navigator/Browser	for Amenesik / Sologic / Twin Server
//	------------------------------------------------------------------
#ifndef	_html_descriptors_h
#define	_html_descriptors_h

#include "field.h"
#include "align.h"
#include "element.h"

class	html_dimensions {
	static int redimension;
public:	int	maxcols;
	int	maxrows;
	int	mincols;
	int	minrows;
	int	runcols;
	int	span;
	int	rspan;
	int	percentage;
	int	explicite;
	html_dimensions * next;
	html_dimensions * detail;
	html_dimensions();
	void		update( html_dimensions * result );
	int		outofdate();
	static	void	dimension_control(int v);
	static  int     redimensioning();
	};

class	html_active_descriptor	:  public virtual html_element_descriptor {
public:
	int	logical_line;
	int	width;
	int	height;
	int	left_margin;
	int	right_margin;
	int	start_column;
	int	start_line;
	int	close_column;
	int	close_line;
	int	is_active;
	int	selecting;
	int	topline;
	int	curline;
	int	expanded;
	char 				*workvalue;
	int				workcheck;
	html_active_descriptor();
	virtual int		getfirstbyte(int id);
	virtual int		getnextbyte();

	};


#include "fontdesc.h"
#include "textdesc.h"
#include "bodydesc.h"
#include "ruledesc.h"
#include "anchdesc.h"
#include "areadesc.h"
#include "imgdesc.h"
#include "inpdesc.h"
#include "zonedesc.h"
#include "headdesc.h"
#include "appdesc.h"
#include "seldesc.h"
#include "celldesc.h"
#include "rowdesc.h"
#include "tabldesc.h"
#include "metadesc.h"
#include "basedesc.h"
#include "linkdesc.h"
#include "listdesc.h"
#include "fsetdesc.h"
#include "framdesc.h"

#endif	// _html_descriptors_h







