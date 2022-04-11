#ifndef	_ciconv_c
#define	_ciconv_c

/*	----------------------------------------------------	*/
/*			  C I C O N V				*/
/*	----------------------------------------------------	*/
/*	This program provides a raw stdio to cico conversion 	*/
/*	Standard input will be read and converted using the	*/
/*	value of the CICO variable and then output to the 	*/
/*	file specified by the command line option.		*/
/*	----------------------------------------------------	*/

#include <stdio.h>
#include <signal.h>

/*	-----------------	*/
/*	Global Variables	*/
/* 	----------------	*/
int	err_val=0;
int	prndest=1;
int	prnfid=0;
int	prnleng=0;
char *	prnptr=(char *) 0;

/*	-----------------	*/
/*	Private Variables 	*/
/*	-----------------	*/
static	int	verbose=0;
static	FILE *	targethandle=(FILE *) 0;
static	char *	convname=(char *) 0;
static	unsigned long bytecount=0L;
static	char	progression[80];

/*	-----------------	*/
/*	Private Functions	*/
/*	-----------------	*/
static	int	failure( int v )
{
	printf("\n** error : %u **\n",v);
	return(v);
}

static	int	option( char * sptr )
{
	switch ( *(sptr++) ) {
		case	'v'	:
			verbose=1;
			return(0);
		case	'o'	:
			convname = sptr;
			return(0);
		default		:
			return(30);
		}
}

static	void	terminator()
{
	signal(SIGTERM,SIG_DFL);
	if ( verbose ) {
		sprintf(progression,"%lu bytes converted     \r\n",bytecount);
		x_cprintf(progression);
		}
	finterm();
	fclose(targethandle);
	return;
}

static	void	zap_catcher(int v)
{
	terminator();
	exit(0);
}


static	int	operation(int argc, char * argv[])
{
	int	c;
	int	status;
	int	argi;
	char *	aptr;
	for ( argi=1; argi < argc; argi++ ) {
		if (!( aptr = argv[argi] ))
			break;
		else if ( *aptr == '-' ) {
			if ((status = option((aptr+1))) != 0)
				return( failure(status) );
			else	continue;
			}
		}
	

	/* The target file name is mandatory */
	/* --------------------------------- */
	if (!( convname ))	return( failure(31) );

	if (!( targethandle = fopen( convname, "w" )))
		return(failure(46));

	signal(SIGTERM,zap_catcher);
	initerm();
	x_clear();
	if ( verbose ) {
		x_cprintf("CICO Stream Convertor : Version 1.0a \r\n");
		x_cprintf("Output to : "); x_cprintf(convname); x_cprintf("\r\n");
		x_cprintf("CICO="); x_cprintf(getenv("CICO")); x_cprintf("\r\n");
		}
	while (((c = local_x_getch()) != -1) && ( err_val == 0)) {
		fputc(c,targethandle);
		bytecount++;
		if ( verbose ) {
			sprintf(progression,"%lu \r",bytecount);
			x_cprintf(progression);
			}
		}
	terminator();
	return(0);
}

static	int	banner()
{
	printf("\n   CICO Stream Convertor : Version 1.0.1 ");
//	printf("\n   Provisoire du 02/10/2008 ");
	printf("\n   Copyright (c) 2019 A.P.I. \n\n");
	return(0);
}

int	main(int argc, char * argv[] )
{
	if ( argc == 1 )
		return(banner());
	else	return(operation(argc,argv));
}

#endif	/* _ciconv_c */
	/* --------- */

