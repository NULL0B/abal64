#ifndef	_abaldcl_h
#define	_abaldcl_h

#define	_PARSE_KEYWORD		0
#define	_PARSE_NAME		1
#define	_PARSE_TYPE		2
#define	_PARSE_SIZEVALUE	3
#define	_PARSE_FIRSTVALUE	4
#define	_PARSE_SECONDVALUE	5
#define	_PARSE_EQUALS		6
#define	_PARSE_LEFT		7
#define	_PARSE_RIGHT		8
#define	_PARSE_SECOND		9
#define	_PARSE_FIELD		10
#define	_PARSE_REDEFINE		11
#define	_PARSE_LENGTH		12
#define	_PARSE_MORE		13
#define	_PARSE_TARGET		14

#define	_PARSE_UPPER		0
#define	_PARSE_LOWER		1
#define	_PARSE_PRESERVE		2

char	*	abal_dcl_keyword[] = {
	(char *) "DCL",
	(char *) "PTR",
	(char *) "FIELD",
	(char *) "FILLER",
	(char *) "LIKE",
	(char *) "CONST",
	(char *) "ARG",
	(char *) "M",
	(char *) "E"
	};

struct abal_parser_context	{
	FILE *	handle;
	char *	name;
	char	token[256];
	char	operand[256];
	int	tokensize;
	int	punctuation;
	int	echo;
	int	state;
	int	stack[16];
	int	level;
	int	ungotc;
	int	convert;
	int	nature;
	char *	indexname;
	char *	markername;
	char *	recordname;
	struct	file_control * file;
	struct	data_control * data;
	};

#define _DCL_KW_DCL		0
#define _DCL_KW_PTR		1
#define _DCL_KW_FIELD		2
#define _DCL_KW_FILLER		3
#define _DCL_KW_LIKE		4
#define _DCL_KW_CONST		5
#define _DCL_KW_ARG		6
#define _DCL_KW_M		7
#define _DCL_KW_E		8
#define _MAX_DCL_KEYWORD	9

#endif	/* _abaldcl_h */
	/* ---------- */

