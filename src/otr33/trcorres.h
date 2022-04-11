#ifndef	_TRCORRES_H
#define	_TRCORRES_H


#define	TCLINKPTR	struct tcode_source_link XPTR


struct	tcode_source_link {
	WORD		file;
	WORD		line;
	WORD		level;
	TCLINKPTR	next;
	};

#ifndef	UNIX
VOID	drop_correspondances( VOID );
TCLINKPTR	allocate_tcode_link( VOID );
WORD	set_correspondance( VOID );
WORD	add_correspondance( VOID );
VOID	pending_correspondances( VOID );
VOID	release_correspondances( VOID );
VOID	symbolic_correspondance( VOID );
#else
#endif


#endif	/* _TRCORRES_H */
	/* ----------- */

