#ifndef	_xml_h
#define	_xml_h

struct	source_context	{
	FILE	*	handle;
	char	*	name;
	int		lines;
	int		column;
	int		ungotch;
	char		token[1024];
	int		punctuation;
	int		length;
	int		state;
	int		nesting;
	};

#define	_TAG_IDLE	0
#define	_TAG_NAME	1
#define	_TAG_FINAL	2
#define	_TAG_OPEN	3
#define	_TAG_COMMENT	4
#define	_TAG_ATBNAME 	5
#define	_TAG_ATBEQUAL	6
#define	_TAG_ATBVALUE	7
#define	_TAG_CLOSE	8

#define	_TAG_QUESTION		9
#define	_TAG_ENDQUESTION	10
#define	_TAG_EXCLAIM		12
#define	_TAG_ENDEXCLAIM		13



#endif	/* _xml_h */
	/* ------ */

