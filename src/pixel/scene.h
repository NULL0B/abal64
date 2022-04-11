#ifndef	_scene_3d_h
#define _scene_3d_h

#define	EXPECTED_KEYWORD	30
#define	INCORRECT_PUNCTUATION	79
#define	UNKNOWN_KEYWORD	78

#define	DEFAULT_TIMER 	20
#define	DEFAULT_STEP	10

#define	_CAMERA_AUTOSIZE 1
#define	_CAMERA_FORMS    2
#define	_CAMERA_IMAGES   4
#define	_CAMERA_ALL      8
#define	_CAMERA_INHIBIT_GIF 16
#define	_CAMERA_IMAGE_TYPE  32
#define	_CAMERA_OBJECT_LOCK 0x2000
#define	_CAMERA_QUALITY     0x4000

struct	view3d		{
	struct coordinate3d 	position;
	struct coordinate2d 	focus;
	int			direction;
	struct	view3d *	previous;
	struct	view3d *	next;
	};

struct	camera3d	{
	struct background2d *	background;
	struct coordinate3d 	position;
	struct coordinate2d 	focus;
	int			direction;
	int			timer;
	int			step;
	int			options;
	char		*	name;
	char		*	configuration;
	void		*	application;
	struct object3d	*	current;
	struct object3d	*	first;
	struct object3d	*	last;
	struct object3d	*	head;
	struct object3d	*	foot;
	struct treeview	*	treenode;
	struct treeview	*	host;
	struct view3d	*	topview;
	struct view3d	*	curview;
	struct view3d	*	endview;
	};

struct	window3d	{
	struct	camera3d *	camera;
	struct  window3d *	previous;
	struct  window3d *	next;
	};
	
#endif	/* _scene_3d_h */





