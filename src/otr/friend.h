/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:						*/
/*		Version :	1.1a					*/
/*		Date	:	01/12/1990				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_FRIEND_H
#define	_FRIEND_H

#define	FRIENDPTR	struct aplus_friend XPTR

struct	aplus_friend	{
	BPTR		name;	/* Name of friend			*/
	FRIENDPTR	next;	/* Next friend in the list		*/
	};

#define	BCLASSPTR	struct aplus_bclass XPTR

struct	aplus_bclass	{
	BPTR		name;		/* Name of friend		*/
	BCLASSPTR	next;		/* Next friend in the list	*/
	BCLASSPTR	previous;	/* Previous Base class in list	*/
	};

FRIENDPTR	add_friend_to_list( FRIENDPTR, BPTR );

#endif	/* _FRIEND_H */
	/* --------- */
