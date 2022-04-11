/* --------------------------------------------------------------------	*/
/*									*/
/*		Project ABAL : Macro pre-processer			*/
/*									*/
/*		 Copyright (c) 1990,1994 Amenesik / Sologic s.a.			*/
/*									*/
/*									*/
/*		File	:	RELATION.H				*/
/*		Version :	2.1c					*/
/*		Date	:	09/08/1994				*/
/*									*/
/* --------------------------------------------------------------------	*/
#ifndef	_RELATION_H
#define	_RELATION_H

#define	RELATIONPTR	struct class_relation XPTR

struct	class_relation {
	RELATIONPTR	next;
	CLASSPTR	class;
	MEMBERPTR	member;
	WORD		type;
	};

#ifdef	CHECK_PROTO_ARGS
RELATIONPTR	allocate_for_relation(VOID);
VOID		liberate_for_relation(RELATIONPTR);
#else
RELATIONPTR	allocate_for_relation();
VOID		liberate_for_relation();
#endif

/*	List of users to update upon definition		*/
/*	---------------------------------------		*/
#ifdef	STRUCTC
	RELATIONPTR	PrototypeUsers;
#else	
EXTERN	RELATIONPTR	PrototypeUsers;
#endif



#endif	/* _RELATION_H */
	/* ----------- */
 
