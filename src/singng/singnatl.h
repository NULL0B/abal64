#ifndef	_singnatl_h
#define	_singnatl_h

#define	MAXNATLANG	8

#define	_NATLANG_EN	0
#define	_NATLANG_FR	1
#define	_NATLANG_IT	2
#define	_NATLANG_ES	3
#define	_NATLANG_DE	4
#define	_NATLANG_NL	5
#define	_NATLANG_PT	6
#define	_NATLANG_XX	7

#ifdef	_SINGABAL_C
public	char *	LanguagePrefix[MAXNATLANG] = { "en","fr","it","es","de","nl","pt","xx" };
#else
extern	char *	LanguagePrefix[MAXNATLANG];
#endif


#endif	/* _singnatl_h */
	/* ----------- */


