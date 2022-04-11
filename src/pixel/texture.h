#ifndef	_texture_3d_h
#define _texture_3d_h

struct	texture	{
	int			width;
	int			height;
	char		   *	storage;
	char		   *	name;
	struct	texture	   *	next;
	};

struct texture * locate_texture( char * );

#endif /* _texture_3d_h */

