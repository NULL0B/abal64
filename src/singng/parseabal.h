#ifndef	_parseabal_h
#define	_parseabal_h

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
#define	_PARSE_CODE		15
#define	_PARSE_DIRECTIVE	16
#define	_PARSE_VALUE		17
#define	_PARSE_TARGETLEFT	18
#define	_PARSE_TARGETFIRST	19
#define	_PARSE_TARGETNEXT	20
#define	_PARSE_TARGETSECOND	21
#define	_PARSE_TARGETRIGHT	22

#define	_PARSE_UPPER		0
#define	_PARSE_LOWER		1
#define	_PARSE_PRESERVE		2

char	*	abal_parse_keyword[] = {
	(char *) "DCL",
	(char *) "PTR",
	(char *) "FIELD",
	(char *) "FILLER",
	(char *) "LIKE",
	(char *) "CONST",
	(char *) "ARG",
	(char *) "M",
	(char *) "E",
	(char *) "PROC",
	(char *) "FORWARD",
	(char *) "EXTERN",
	(char *) "ENDPROC",
	(char *) "SEGMENT",
	(char *) "ESEG",
	(char *) "PROGRAM",
	(char *) "MODULE",
	(char *) "END"
	};


struct	abal_parser_context;

struct	abal_relay	{
	int	(*syntax_error)(struct abal_parser_context *, int);
	int	(*use_field)(struct abal_parser_context *);
	int	(*use_declaration)(struct abal_parser_context *);
	int	(*use_filler)(struct abal_parser_context *);
	int	(*reset_field)(struct abal_parser_context *);
	int	(*use_procedure)(struct abal_parser_context *);
	int	(*use_segment)(struct abal_parser_context *);
	int	(*use_program)(struct abal_parser_context *);
	int	(*use_module)(struct abal_parser_context *);
	int	(*use_end)(struct abal_parser_context *);
	int	(*use_directive)(struct abal_parser_context *);
	int	(*use_token)(struct abal_parser_context *);
	int	(*use_punctuation)(struct abal_parser_context *);
	int	(*use_space)(struct abal_parser_context *,int);
	};

struct abal_parser_constant	{
	struct abal_parser_constant * previous;
	struct abal_parser_constant * next;
	int	hash;
	int	type;
	char *	name;
	char *	value;
	};
	
struct abal_parser_context	{
	struct abal_parser_constant * firstconstant;
	struct abal_parser_constant * lastconstant;
	FILE *	handle;
	char *	name;
	char	token[256];
	char	operand[256];
	int	tokensize;
	int	punctuation;
	int	echo;
	int	state;
	int	stack[64];
	int	level;
	int	ungotc;
	int	convert;
	int	nature;
	int	linecount;
	int	columncount;
	int	(*get_token)(struct abal_parser_context *);
	int	(*get_punctuation)(struct abal_parser_context *);
	int	(*parse_file)(struct abal_parser_context *,char *);
	struct	abal_relay * relay;
	void *	application;
	};

#define _PARSE_KW_DCL		0
#define _PARSE_KW_PTR		1
#define _PARSE_KW_FIELD		2
#define _PARSE_KW_FILLER	3
#define _PARSE_KW_LIKE		4
#define _PARSE_KW_CONST		5
#define _PARSE_KW_ARG		6
#define _PARSE_KW_M		7
#define _PARSE_KW_E		8
#define _PARSE_KW_PROC		9
#define _PARSE_KW_FORWARD	10
#define _PARSE_KW_EXTERN	11
#define _PARSE_KW_ENDPROC	12
#define _PARSE_KW_SEGMENT	13
#define _PARSE_KW_ESEG		14
#define _PARSE_KW_PROGRAM	15
#define _PARSE_KW_MODULE 	16
#define _PARSE_KW_END		17
#define _MAX_PARSE_KEYWORD	18

#endif	/* _parseabal_h */
	/* ------------ */

