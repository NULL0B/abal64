#ifndef	_cico_c
#define	_cico_c

/*	-------------------------------------------------------------------------------		*/
/*	This file provides the various and crucial cico bits for clients that need them		*/
/*	-------------------------------------------------------------------------------		*/
#ifndef	EXAWORD
#ifdef	ABAL64
#define	EXAWORD unsigned long long int
#else
#ifdef	VERSION666
#define	EXAWORD unsigned long int
#else
#define	EXAWORD unsigned short int
#endif
#endif
#endif
#ifndef	BPTR
#define	BPTR unsigned char *
#endif

void *	prnfid=0;
int	prndest=1;
int	prnleng=0;
int	prndex=0;
unsigned char * prnptr=(BPTR) 0;
EXAWORD  	sicico=0;

void	si_fin()	{ return; }

#ifndef	_NO_PANIC
/* the panic trap is not defined elsewhere */
int	panic(int s)	{ return(1); }
#endif

	/* ------- */
#endif	/* _cico_c */
	/* ------- */


