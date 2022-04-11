#ifndef	_singsmed_h
#define	_singsmed_h

#include "singfile.h"
#include "vstyle.h"
#include "singplan.h"

#define	_STYLE_FRAME			"sing/dependance_editor_frame"
#define	_STYLE_TITLE			"sing/dependance_editor_title"
#define	_STYLE_HEADER			"sing/dependance_editor_header"
#define	_STYLE_FOCUS			"sing/dependance_editor_focus"
#define	_STYLE_MODEL_TRAY		"sing/dependance_model_tray"
#define	_STYLE_MODEL			"sing/dependance_model_frame"
#define	_STYLE_MEMBER			"sing/dependance_member_frame"
#define	_STYLE_MODEL_FOCUS		"sing/dependance_model_focus"
#define	_STYLE_MEMBER_FOCUS		"sing/dependance_member_focus"
#define	_STYLE_EDITOR_FRAME		"sing/dependance_style_editor"

#define	_STYLE_RELATION_SOURCE		"sing/dependance_relation_source"
#define	_STYLE_RELATION_TARGET		"sing/dependance_relation_target"

#define	_STYLE_REV_RELATION_SOURCE	"sing/dependance_rev_relation_source"
#define	_STYLE_REV_RELATION_TARGET	"sing/dependance_rev_relation_target"

#define	_STYLE_TRACE_NORTH		"sing/flowchart_trace_north"
#define	_STYLE_TRACE_SOUTH		"sing/flowchart_trace_south"
#define	_STYLE_TRACE_EAST 		"sing/flowchart_trace_east"
#define	_STYLE_TRACE_WEST 		"sing/flowchart_trace_west"
#define	_STYLE_TRACE_POINT 		"sing/flowchart_trace_point"

#define	_STYLE_BUBBLE_FRAME		"sing/flowchart_help_bubble"
#define	_STYLE_HYPERVIEW_FRAME		"sing/flowchart_hyperview_frame"
#define	_STYLE_HYPERVIEW_TRAY 		"sing/flowchart_hyperview_tray"
#define	_STYLE_HYPERVIEW_CROSS		"sing/flowchart_hyperview_cursor"
#define	_STYLE_HYPERVIEW_ZOOM 		"sing/flowchart_hyperview_zoom"

struct	visual_dependance_member	{
	struct	visual_dependance_member   	* previous;
	struct	visual_dependance_member  	* next;
	struct	visual_dependance_model	  	* parent;
	struct	visual_dependance_model	  	* detail;
	char 					* name;
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

struct	visual_dependance_model	{
	struct	visual_dependance_model  	* previous;
	struct	visual_dependance_model  	* next;
	struct	visual_dependance_member 	* first;
	struct	visual_dependance_member 	* last;
	struct	visual_dependance_member 	* firstdependance;
	struct	visual_dependance_member 	* lastdependance;
	struct	visual_dependance_member 	* firstdependant;
	struct	visual_dependance_member 	* lastdependant;
	struct	visual_dependance_member 	* current;
	struct	visual_dependance_member 	* oldfocus;
	char 					* name;
	char 					* basename;
	struct	element_style			* style;
	int	hash;
	int	users;			/* total users count  : indicates links in  	*/
	int	members;		/* total member count : indicates links out 	*/
	int	dependance;		/* total dependance member count  : links out 	*/
	int	dependants;		/* total dependant members count  : links in 	*/
	int	inhibit;		/* inhibit apperance of model for form view 	*/
	int	lock;			/* model is locked to its position 	    	*/
	int	focus;			/* true when this model has the focus	    	*/
	int	state;			/* opened / closed / etc 			*/
	int	safty;			/* height when open 				*/
	struct	style_zone	icon;	/* stores the model icon position / dimensions	*/
	int	sequence;
	int	done;
	int	by;
	int	number;
	int	nosave;
	int	x;
	int	y;
	int	w;
	int	h;
	};

struct	visual_dependance_editor	{
	struct	visual_dependance_model  * best;
	struct	visual_dependance_model  * first;
	struct	visual_dependance_model  * last;

	struct	visual_dependance_model  * current;
	struct	visual_dependance_model  * solo;

	struct	visual_dependance_model  * copied_model;
	struct	visual_dependance_member * copied_member;

	char			       	* title;
	char				* stylezoom;
	char				* zoomname;

	char				* selection;
	char				* stylesheet;

	int				mode;		/* 0 : dependance : 1 : dependants */
	int				hyperspace;
	int				bubblehelp;
	int				fraction;
	int				detail;

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

	int	useroot;		/* go back to base class root */
	int	schema;			/* sing / merise / uml */
	int	images;			/* show forms images */
	int	iconpadd;		/* padding around icon */

	struct	style_zone 		hyperzone;
	struct	style_zone 		hyperview;
	struct	style_zone 		hypercursor;
	struct	style_zone		hypersave;
	struct	style_zone		zoomzone;

	struct	buffer_control buffer;
	struct	standard_image  * image;

	char			* exportname;
	int			  filter;
	};

#endif	/* _singsmed_h */
	/* ----------- */

