#ifndef	_xeleven_h
#define	_xeleven_h

/*	This file provides X11 substitution stubs for compilation checking	*/

// FCH begin
// mise en conformité du code
typedef	struct {
	int	handle;
	} Widget ;

typedef	struct {
	int	handle;
	} Display ;

typedef	struct {
	int	handle;
	} XtAppContext ;

typedef	struct	{
	char	*	data;
	int		width;
	int		columns;
   int      bytes_per_line; // FCH ajout car utilisé dans filzone.c
   } XImage ;
// FCH end

// FCH begin
// Ces types sont inconnus, je mets n'importe quoi pour essayer d'avancer
typedef struct  {
	int	handle;
	} Atom ;

typedef struct  {
	int	handle;
	} XTextProperty ;

typedef struct  {
	int	handle;
	} Visual ;

//typedef struct  {
//	int	handle;
//	} GC ;
typedef int GC;

//typedef struct  {
//	int	handle;
//	} Window ;
typedef int Window;

typedef struct  {
	int	handle;
	} Colormap ;

typedef struct  {
	int	handle;
	} XEvent ;

// FCH end


#endif	/* _xeleven_h */

