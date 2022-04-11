#ifndef	_singfmed_h
#define	_singfmed_h

#define	_ACTION_NULL	0
#define	_ACTION_OVERLAY	1
#define	_ACTION_MODULE	2
#define	_ACTION_CHAIN	3
#define	_ACTION_LOADGO	4
#define	_ACTION_CLASS	5

#define	_FLOW_STYLE 	'WY'
#define	_FLOW_RESET 	'BZ'
#define	_FLOW_IMPORT	'BL'
#define	_FLOW_EXPORT	'BS'
#define	_FLOW_ADD  	'BA'
#define	_FLOW_NEW  	'BN'
#define	_FLOW_INFO	'BI'
#define	_FLOW_WORK	'BU'
#define	_FLOW_TRACE	'BT'
#define	_FLOW_HYPER	'BY'
#define	_FLOW_INHIBIT	'BB'
#define	_FLOW_HELP   	'BH'
#define	_FLOW_SOLO	'BO'
#define	_FLOW_DETAIL	'BD'
#define	_FLOW_BEST	'BW'
#define	_FLOW_SCREEN	'BE'
#define	_FLOW_IMAGE	'BG'
#define	_FLOW_SIGHT	'WG'
#define	_FLOW_DOMAIN	'OO'
#define	_FLOW_MODE	'OM'
#define	_FLOW_DELETE	'OD'

#define	_FORM_ACTION_INFO	'LI'
#define	_FORM_ACTION_DELETE	'LD'
#define	_FORM_ACTION_MOVE	'LM'

#define	_FORM_MODEL_STATE	'MS'
#define	_FORM_MODEL_RENAME	'MR'
#define	_FORM_MODEL_COPY	'MC'
#define	_FORM_MODEL_PASTE	'MP'
#define	_FORM_MODEL_DELETE	'MD'
#define	_FORM_MODEL_LOCK	'ML'
#define	_FORM_MODEL_SOLO	'MU'
#define	_FORM_MODEL_INFO	'MI'

#define	_FORM_MEMBER_RENAME		'MM'
#define	_FORM_MEMBER_NATURE		'MN'
#define	_FORM_MEMBER_DEFINE		'MF'
#define	_FORM_MEMBER_DELETE		'MD'
#define	_FORM_MEMBER_COPY		'MC'
#define	_FORM_MEMBER_BEFORE		'MB'
#define	_FORM_MEMBER_AFTER		'MA'
#define	_FORM_MEMBER_RELATION 	'MR'
#define	_FORM_MEMBER_PASTE		'MP'

#ifndef _flowmenu_c
#ifndef _actormenu_c
#ifndef _widgetmenu_c
#ifndef _methodmenu_c
#ifndef _vdepmenu_c
#ifndef _vdepmodmenu_c

#include "singfile.h"
#include "vstyle.h"
#include "singplan.h"

#define	_STYLE_FLOWCHART_FRAME			"sing/flowchart_editor_frame"
#define	_STYLE_FLOWCHART_TITLE			"sing/flowchart_editor_title"
#define	_STYLE_FLOWCHART_HEADER			"sing/flowchart_editor_header"

#define	_STYLE_FLOWCHART_FOCUS			"sing/flowchart_editor_focus"
#define	_STYLE_FLOWCHART_MODEL_TRAY		"sing/flowchart_model_tray"
#define	_STYLE_FLOWCHART_MODEL			"sing/flowchart_model_frame"
#define	_STYLE_FLOWCHART_MEMBER			"sing/flowchart_member_frame"

#define	_STYLE_FLOWCHART_CLASS_FRAME		"sing/flowchart_component_frame"
#define	_STYLE_FLOWCHART_CLASS_FOCUS		"sing/flowchart_component_focus"

#define	_STYLE_FLOWCHART_INDEX 			"sing/flowchart_index_frame"
#define	_STYLE_FLOWCHART_INDEX_FOCUS		"sing/flowchart_index_focus"
#define	_STYLE_FLOWCHART_MODEL_FOCUS		"sing/flowchart_model_focus"
#define	_STYLE_FLOWCHART_MEMBER_FOCUS		"sing/flowchart_member_focus"

#define	_STYLE_FLOWCHART_OVERLAY_SOURCE		"sing/flowchart_overlay_source"
#define	_STYLE_FLOWCHART_MODULE_SOURCE		"sing/flowchart_module_source"
#define	_STYLE_FLOWCHART_CHAIN_SOURCE		"sing/flowchart_chain_source"
#define	_STYLE_FLOWCHART_LOADGO_SOURCE		"sing/flowchart_loadgo_source"
#define	_STYLE_FLOWCHART_CLASS_SOURCE		"sing/flowchart_class_source"
#define	_STYLE_FLOWCHART_RELATION_SOURCE	"sing/flowchart_relation_source"
#define	_STYLE_FLOWCHART_RELATION_EXTERN	"sing/flowchart_relation_extern"
#define	_STYLE_FLOWCHART_RELATION_UNKNOWN	"sing/flowchart_relation_unknown"

#define	_STYLE_FLOWCHART_OVERLAY_TARGET		"sing/flowchart_overlay_target"
#define	_STYLE_FLOWCHART_MODULE_TARGET		"sing/flowchart_module_target"
#define	_STYLE_FLOWCHART_CHAIN_TARGET		"sing/flowchart_chain_target"
#define	_STYLE_FLOWCHART_LOADGO_TARGET		"sing/flowchart_loadgo_target"
#define	_STYLE_FLOWCHART_CLASS_TARGET		"sing/flowchart_class_target"
#define	_STYLE_FLOWCHART_RELATION_TARGET	"sing/flowchart_relation_target"

#define	_STYLE_FLOWCHART_REV_OVERLAY_SOURCE	"sing/flowchart_rev_overlay_source"
#define	_STYLE_FLOWCHART_REV_MODULE_SOURCE	"sing/flowchart_rev_module_source"
#define	_STYLE_FLOWCHART_REV_CHAIN_SOURCE	"sing/flowchart_rev_chain_source"
#define	_STYLE_FLOWCHART_REV_LOADGO_SOURCE	"sing/flowchart_rev_loadgo_source"
#define	_STYLE_FLOWCHART_REV_CLASS_SOURCE	"sing/flowchart_rev_class_source"
#define	_STYLE_FLOWCHART_REV_RELATION_SOURCE	"sing/flowchart_rev_relation_source"

#define	_STYLE_FLOWCHART_REV_OVERLAY_TARGET	"sing/flowchart_rev_overlay_target"
#define	_STYLE_FLOWCHART_REV_MODULE_TARGET	"sing/flowchart_rev_module_target"
#define	_STYLE_FLOWCHART_REV_CHAIN_TARGET	"sing/flowchart_rev_chain_target"
#define	_STYLE_FLOWCHART_REV_LOADGO_TARGET	"sing/flowchart_rev_loadgo_target"
#define	_STYLE_FLOWCHART_REV_CLASS_TARGET	"sing/flowchart_rev_class_target"
#define	_STYLE_FLOWCHART_REV_RELATION_TARGET	"sing/flowchart_rev_relation_target"

#define	_STYLE_FLOWCHART_TRACE_NORTH		"sing/flowchart_trace_north"
#define	_STYLE_FLOWCHART_TRACE_SOUTH		"sing/flowchart_trace_south"
#define	_STYLE_FLOWCHART_TRACE_EAST 		"sing/flowchart_trace_east"
#define	_STYLE_FLOWCHART_TRACE_WEST 		"sing/flowchart_trace_west"
#define	_STYLE_FLOWCHART_TRACE_POINT 		"sing/flowchart_trace_point"

#define	_STYLE_FLOWCHART_BUBBLE_FRAME		"sing/flowchart_help_bubble"

#define	_STYLE_FLOWCHART_HYPERVIEW_FRAME	"sing/flowchart_hyperview_frame"
#define	_STYLE_FLOWCHART_HYPERVIEW_TRAY 	"sing/flowchart_hyperview_tray"
#define	_STYLE_FLOWCHART_HYPERVIEW_CROSS	"sing/flowchart_hyperview_cursor"
#define	_STYLE_FLOWCHART_HYPERVIEW_ZOOM 	"sing/flowchart_hyperview_zoom"

struct	visual_flowchart_model;
struct	visual_flowchart_member;

struct	visual_flowchart_relation	{
	struct	visual_flowchart_relation * previous;
	struct	visual_flowchart_relation * next;
	struct	visual_flowchart_member   * source;
	struct	visual_flowchart_member   * target;
	struct	form_item 		 * relation;
	char 				 * name;
	int				   nature;	/* 1 to 1 	*/
							/* 1 -> many 	*/
							/* many -> 1 	*/
	};

struct	visual_flowchart_member	{
	struct	visual_flowchart_member   * previous;
	struct	visual_flowchart_member   * next;
	struct	visual_flowchart_model	  * parent;
	struct	visual_flowchart_relation * first;
	struct	visual_flowchart_relation * last;
	struct	form_item 		  * widget;
	struct  forms_method		  * method;	
	struct	form_control		  * target;	/* for project macro models */
	struct	visual_flowchart_model	  * detail;	/* for forms detail models  */
	char *	name;
	int	hash;
	struct	style_zone 		   left;
	struct	style_zone 		   right;
	int	number;
	int	focus;
	int	x;
	int	y;
	int	w;
	int	h;
	};

struct	visual_flowchart_model	{
	struct	visual_flowchart_model  	* previous;
	struct	visual_flowchart_model  	* next;
	struct	visual_flowchart_member 	* first;
	struct	visual_flowchart_member 	* current;
	struct	visual_flowchart_member 	* oldfocus;
	struct	visual_flowchart_member 	* last;
	struct form_control 		* form;
	struct forms_method		* method;	
	struct form_item		* widget; /* for flow chart detail models */
	char 				* name;
	int	hash;
	int	users;			/* total users count  : indicates links in  	*/
	int	members;		/* total member count : indicates links out 	*/
	int	inhibit;		/* inhibit apperance of model for form view 	*/
	int	lock;			/* model is locked to its position 	    	*/
	int	focus;			/* true when this model has the focus	    	*/
	int	state;			/* opened / closed / etc 			*/
	int	isize;			/* height when open 				*/
	int	msize;			/* height when closed 				*/
	int	total;			/* total  when open 				*/
	struct	style_zone	icon;	/* stores the model icon position / dimensions	*/
	int	base;			/* vertical base reference 			*/
	int	done;
	int	by;
	int	number;
	int	nosave;
	int	x;
	int	y;
	int	w;
	int	h;
	};

struct	visual_flowchart_editor	{
	struct	visual_flowchart_model  * first;
	struct	visual_flowchart_model  * last;

	struct	visual_flowchart_model  * current;
	struct	visual_flowchart_model  * solo;

	struct	visual_flowchart_model  * copied_model;
	struct	visual_flowchart_member * copied_member;

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
	int	images;			/* show forms images */
	int	iconpadd;		/* padding around icon */

	struct	style_zone 		hyperzone;
	struct	style_zone 		hyperview;
	struct	style_zone 		hypercursor;
	struct	style_zone		hypersave;

	struct	buffer_control buffer;
	struct	standard_image  * image;
	char			* stylename;

	};

#endif	/* _vdepmodmenu_c */
	/* ------------- */
#endif	/* _vdepmenu_c */
	/* ------------- */
#endif	/* _methodmenu_c */
	/* ------------- */
#endif	/* _widgetmenu_c */
	/* ------------- */
#endif	/* _actormenu_c */
	/* ----------- */
#endif	/* _flowmenu_c */
	/* ----------- */

#endif	/* _singfmed_h */
	/* ----------- */

