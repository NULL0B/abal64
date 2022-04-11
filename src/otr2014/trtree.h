#ifndef	_TRTREE_H
#define	_TRTREE_H

#define	TREEPTR	struct tcode_class_tree XPTR

struct	tcode_class_tree	{
	TCSTRUCTPTR	class;
	TREEPTR		left;
	TREEPTR		right;
	TREEPTR		next;
	};

#endif	/* _TRTREE_H */
	/* --------- */

