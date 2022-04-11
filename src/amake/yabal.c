#ifndef	_yabal_c
#define	_yabal_c

#include <stdio.h>

#define allocate(a) malloc(a)
#define liberate(b) free(b)

void * allocate( int );
void   liberate( void * );

char * 	including=(char *) 0;
char *	sourcedir=(char *) 0;
char *	homepath=(char *) 0;
int	ungotch=0;
int	verbose=0;
int	echo=0;
int	state=0;

char	*	listfile=(char *) 0;

struct	member {
	char *	name;
	char *	value;
	struct member * next;
	struct member * prev;
	};

struct	section {
	char * name;
	struct member * root;
	struct member * last;
	struct section *  next;
	struct section *  prev;
	};

struct	project	{
	char *	name;
	struct section * root;
	struct section * last;
	struct project *  next;
	struct project *  prev;
	};

struct	project * root=(struct project *) 0;
struct	project * foot=(struct project *) 0;

#define	maxbuffersize 2048

char	workbuffer[maxbuffersize];

int	report_error( int e )
{
	if ( e != 0 )
		printf("\n error : %u \n",e);
	return(e);
}

void	comment( FILE * h, char * prefix, char * postfix );
void	inclusion( FILE * h, char * nptr);

#ifndef	UNIX
#include "wildcomp.c"
#include "fnparser.c"
#endif
#include "yparse.c"
#include "yfind.c"
#include "youtput.c"
#include "ysymbol.c"
#include "yfile.c"
#include "ymake.c"
#include "ymain.c"


# endif // _yabal_c

