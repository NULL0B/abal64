#ifndef	_singcam_h
#define	_singcam_h

#include "threed.h"
#include "scene.h"
#include "texture.h"
#include "align.h"
#include "vconf.h"
#include "valign.h"


#define	_INHIBIT_GIF _CAMERA_INHIBIT_GIF

#define	_APPLICATION_NONE	0
#define	_APPLICATION_PROGRAM	1
#define	_APPLICATION_OVERLAY	2
#define	_APPLICATION_MODULE	3
#define	_APPLICATION_LIBRARY	4
#define	_APPLICATION_PACKAGE	5

#define	_THREED_PALETTE		0x0010
#define	_THREED_TOOLBAR		0x0020	
#define	_THREED_TREEVIEW	0x0040
	
#ifdef	ABAL32A
#define	_THREED_OUT_OF_DATE	0x0100
#define	_SING_TITLE 	"Sing Version 2.1a"
#else
#define	_SING_TITLE 	"Sing Version 1.1e"
#endif

#define	_SING_LOGO  	"singlogo.gif"
#define	_SING_STYLE 	"style.css"
#define	_SING_COPYRIGHT	"Copyright (c) 2002,2007 Amenesik / Sologic "


private	struct	model_control {
	int	saveimages;
	int	savemembers;
	int	saveall;
	};

#include "singappl.h"
struct production_manager {
	char	*	filename;
	FILE 	*	handle;
	int		nature;
	int		prodlang;
	};


struct	document_parameters {
	char *	title;
	char *	pathroot;
	char *	screenstyle;
	char *	printstyle;
	char *	logo;
	char *	footer;
	int	separate;
	int	report;
	int	forcelang;
	int	language;
	int	holdlang;
	int	metric;
	int	scale;
	};

struct	bitmap_control {
	unsigned long		  loadstamp;
	unsigned long		  savestamp;
	struct standard_image 	* payload;
	struct treeview 	* treenode;
	void			* host;
	};

struct	source_control {
	unsigned long		  loadstamp;
	unsigned long		  savestamp;
	void		 	* payload;
	struct treeview 	* treenode;
	void			* host;
	};

struct	camera3d	*	initialise_Camera();


#endif	/* _singcam_h */
	/* ---------- */


