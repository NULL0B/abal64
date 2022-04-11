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

#define	_THREED_PALETTE		0x0010
#define	_THREED_TOOLBAR		0x0020	
#define	_THREED_TREEVIEW	0x0040	

#define	_SING_TITLE 	"Sing Version 1.1e"
#define	_SING_LOGO  	"singlogo.gif"
#define	_SING_STYLE 	"style.css"
#define	_SING_COPYRIGHT	"Copyright (c) 2002,2006 Amenesik / Sologic "


private	struct	model_control {
	int	saveimages;
	int	savemembers;
	int	saveall;
	};

struct	application_parameters {
	int	quality;
	int	visible;
	int	build;
	int	productiontype;
	int	language;
	int	isdocument;
	int	makefile;
	int	imagetype;
	char *	target;
	char *	document;
	char *	makename;
	char *	databasename;
	char *	palettename;
	};

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


