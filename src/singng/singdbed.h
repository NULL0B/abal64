#ifndef	_singdbed_h
#define	_singdbed_h

#define	_BASE_RESET 	'BZ'
#define	_BASE_IMPORT	'BL'
#define	_BASE_EXPORT	'BS'
#define	_BASE_ADD  	'BA'
#define	_BASE_INFO	'BI'
#define	_BASE_TRACE	'BT'
#define	_BASE_HYPER	'BY'
#define	_BASE_INHIBIT	'BB'
#define	_BASE_HELP   	'BH'
#define	_BASE_LOCK   	'BK'
#define	_BASE_IMAGE	'BG'
#define	_BASE_READ   	'BR'
#define	_BASE_CLOSE	'BC'

#define	_LINK_INFO	'LI'
#define	_LINK_DELETE	'LD'
#define	_LINK_MOVE	'LM'

#define	_MODEL_STATE	'MS'
#define	_MODEL_RENAME	'MR'
#define	_MODEL_COPY	'MC'
#define	_MODEL_PASTE	'MP'
#define	_MODEL_DELETE	'MD'
#define	_MODEL_LOCK	'ML'
#define	_MODEL_SOLO	'MU'
#define	_MODEL_INFO	'MI'
#define	_MODEL_SIZES	'MZ'
#define	_MODEL_CLOSE	'MK'

#define	_MEMBER_RENAME		'MM'
#define	_MEMBER_NATURE		'MN'
#define	_MEMBER_DEFINE		'MF'
#define	_MEMBER_DELETE		'MD'
#define	_MEMBER_COPY		'MC'
#define	_MEMBER_BEFORE		'MB'
#define	_MEMBER_AFTER		'MA'
#define	_MEMBER_RELATION 	'MR'
#define	_MEMBER_LINK		'ML'
#define	_MEMBER_LIST 		'MT'
#define	_MEMBER_PASTE		'MP'

#ifndef _basemenu_c
#ifndef _modelmenu_c
#ifndef _membermenu_c
#ifndef _linkmenu_c

#include "singfile.h"
#include "vstyle.h"
#include "singplan.h"

#define	_STYLE_DATABASE_FRAME		"sing/database_editor_frame"
#define	_STYLE_DATABASE_TITLE		"sing/database_editor_title"
#define	_STYLE_DATABASE_HEADER		"sing/database_editor_header"

#define	_STYLE_DATABASE_FOCUS		"sing/database_editor_focus"
#define	_STYLE_DATABASE_MODEL_TRAY	"sing/database_model_tray"
#define	_STYLE_DATABASE_MODEL		"sing/database_model_frame"
#define	_STYLE_DATABASE_MEMBER		"sing/database_member_frame"

#define	_STYLE_DATABASE_INDEX 		"sing/database_index_frame"
#define	_STYLE_DATABASE_INDEX_FOCUS	"sing/database_index_focus"
#define	_STYLE_DATABASE_MODEL_FOCUS	"sing/database_model_focus"
#define	_STYLE_DATABASE_MEMBER_FOCUS	"sing/database_member_focus"
#define	_STYLE_DATABASE_MEMBER_LINK	"sing/database_member_link"
#define	_STYLE_DATABASE_MEMBER_LIST	"sing/database_member_list"
#define	_STYLE_DATABASE_INDEX_LINK	"sing/database_index_link"
#define	_STYLE_DATABASE_INDEX_LIST	"sing/database_index_list"

#define	_STYLE_DATABASE_RELATION_SOURCE	"sing/database_relation_source"
#define	_STYLE_DATABASE_RELATION_TARGET	"sing/database_relation_target"
#define	_STYLE_DATABASE_RELATION_SOURCE_LEFT	"sing/database_relation_source_left"
#define	_STYLE_DATABASE_RELATION_TARGET_LEFT	"sing/database_relation_target_left"
#define	_STYLE_DATABASE_RELATION_SOURCE_RIGHT	"sing/database_relation_source_right"
#define	_STYLE_DATABASE_RELATION_TARGET_RIGHT	"sing/database_relation_target_right"

#define	_STYLE_DATABASE_RELATION_EXTERN	"sing/database_relation_extern"
#define	_STYLE_DATABASE_SOURCE_FILE	"sing/database_source_file"
#define	_STYLE_DATABASE_TARGET_FILE	"sing/database_target_file"

#define	_STYLE_DATABASE_RELATION_FRAME 	"sing/database_relation_frame"
#define	_STYLE_DATABASE_RELATION_LABEL 	"sing/database_relation_label"


#define	_STYLE_DATABASE_TRACE_NORTH	"sing/database_trace_north"
#define	_STYLE_DATABASE_TRACE_SOUTH	"sing/database_trace_south"
#define	_STYLE_DATABASE_TRACE_EAST 	"sing/database_trace_east"
#define	_STYLE_DATABASE_TRACE_WEST 	"sing/database_trace_west"
#define	_STYLE_DATABASE_TRACE_POINT 	"sing/database_trace_point"

#define	_STYLE_DATABASE_BUBBLE_FRAME	"sing/database_help_bubble"
#define	_STYLE_DATABASE_HYPERVIEW_FRAME	"sing/database_hyperview_frame"
#define	_STYLE_DATABASE_HYPERVIEW_TRAY 	"sing/database_hyperview_tray"
#define	_STYLE_DATABASE_HYPERVIEW_CROSS	"sing/database_hyperview_cursor"
#define	_STYLE_DATABASE_HYPERVIEW_ZOOM 	"sing/database_hyperview_zoom"

struct	visual_database_model;
struct	visual_database_member;

struct	visual_database_relation	{
	struct	visual_database_relation * previous;
	struct	visual_database_relation * next;
	struct	visual_database_member   * source;
	struct	visual_database_member   * target;
	struct	link_control		 * relation;
	char 				 * name;
	char				 * jointure;
	struct	style_zone 		   label;
	struct	style_zone 		   left;
	struct	style_zone 		   right;
	int				   nature;	/* 1 to 1 	*/
							/* 1 -> many 	*/
							/* many -> 1 	*/
	};

struct	visual_database_member	{
	struct	visual_database_member   * previous;
	struct	visual_database_member   * next;
	struct	visual_database_model	 * parent;
	struct	visual_database_relation * first;
	struct	visual_database_relation * last;
	char *	name;
	struct	style_zone 		   left;
	struct	style_zone 		   right;
	int	number;
	int	nature;	/* 0 : data, 1 : index */
	int	focus;
	int	x;
	int	y;
	int	w;
	int	h;
	};

struct	visual_database_model	{
	struct	visual_database_model  	* previous;
	struct	visual_database_model  	* next;
	struct	visual_database_member 	* first;
	struct	visual_database_member 	* current;
	struct	visual_database_member 	* oldfocus;
	struct	visual_database_member 	* last;
	struct data_control 		* data;
	struct file_control 		* file;
	char 				* name;
	int	inhibit;		/* inhibit apperance of model for form view */
	int	lock;			/* model is locked to its position 	    */
	int	focus;
	int	state;			/* opened / closed / etc */
	int	safty;			/* height when open */
	int	x;
	int	y;
	int	w;
	int	h;
	};

struct	visual_database_reader	{
	char *	ifile;
	char *	cname;
	char *	oname;
	char * 	fname;
	char *	iname;
	char *	mname;
	char *	dname;
	int	convert;	/* 0 : uppercase, 1 : lowercase : 2 : preserve */
	};

struct	visual_database_editor	{
	struct	visual_database_model  * first;
	struct	visual_database_model  * last;

	struct	visual_database_model  * current;
	struct	visual_database_model  * solo;

	struct	visual_database_model  * copied_model;
	struct	visual_database_member * copied_member;

	struct visual_database_reader	Reader;

	char			       * title;

	int				hyperspace;
	int				bubblehelp;
	int				fraction;

	int	xmargin;
	int	ymargin;

	int	x;
	int	y;
	int	w;
	int	h;

	int	xpadding;
	int	ypadding;
	int	tracepadding;
	int	debug_trace_route;
	int	depth;

	int	bender;
	int	tracewidth;
	int	tracecolour;

	int	inhibit;		
	int	outofdate;

	/* Help Bubble Control Variables */
	/* ----------------------------- */
	struct	style_zone 		bubble;
	STDPSUPTR			bubblezone;

	/* Hyper View Control Variables	*/
	/* ---------------------------- */
	int	sbh;
	int	sbw;

	int	schema;			/* sing / merise / uml */
	int	lock;			

	struct	style_zone 		hyperzone;
	struct	style_zone 		hyperview;
	struct	style_zone 		hypercursor;
	struct	style_zone		hypersave;

	struct	buffer_control buffer;
	struct	standard_image  * image;
	};

#endif	/* _linkmenu_c */
	/* ------------- */

#endif	/* _membermenu_c */
	/* ------------- */

#endif	/* _modelmenu_c */
	/* ------------ */

#endif	/* _basemenu_c */
	/* ----------- */

#endif	/* _singdbed_h */
	/* ----------- */

