#ifndef	_apush_c
#define	_apush_c

static	int	pushpoptions=7;
static	int	pushpopid=0;
static	int	pushpopowner=-1;
static	int	pushpophandle=-1;
static	int	pushcounter=0;

#include "apush.h"

#undef	USE_PUSH_TRACE
#ifdef	USE_PUSH_TRACE
/*	-------------------------------------------------------------	*/
/*				ABAL PUSH POP				*/
/*	-------------------------------------------------------------	*/
/*	This code has been added to allow tracing of the push pop	*/
/*	mechanisms. This is a complicated job due to multiple process	*/
/*	situations across external load.go operations			*/
/*	the push pop file mechanisms are shared amongst all loadgo	*/
/*	instances across an exa process group !				*/
/*	-------------------------------------------------------------	*/
void	pushtrace(char * mptr)
{
	char	buffer[320];
	FILE *	h;
	if (!( h = fopen("/tmp/pushtrace.tmp","a")))
		return;
	fprintf(h," %s( pid=%u, id=%u, owner=%u )\n" ,mptr,getpid(),pushpopid,pushpopowner);
	fclose(h);
	return;
}

void	pushtracew(char * mptr,int w)
{
	char	buffer[320];
	FILE *	h;
	if (!( h = fopen("/tmp/pushtrace.tmp","a")))
		return;
	fprintf(h," %s( pid=%u, id=%u, owner=%u ) value = %u \n" ,mptr,getpid(),pushpopid,pushpopowner,w);
	fclose(h);
	return;
}

void	pushtracebuffer(char * mptr,char * bptr, int blen)
{
	int	i;
	char	buffer[320];
	FILE *	h;
	if (!( h = fopen("/tmp/pushtrace.tmp","a")))
		return;
	fprintf(h," %s( pid=%u, id=%u, owner=%u ) {\n" ,mptr,getpid(),pushpopid,pushpopowner);
	for (i=0; i < blen; i++ ) {
		if (( i != 0) && (!( i % 16 )))
			fprintf(h,"\n");
		fprintf(h,"%02.2X ",*(bptr+i));
		}
	fprintf(h," } \n");
	fclose(h);
	return;
}
	/* -------------- */
#endif	/* USE_PUSH_TRACE */
	/* -------------- */

/*	--------------------------------	*/
/*	p u s h p o p f i l e n a m e ()	*/
/*	--------------------------------	*/
static	void	pushpopfilename( char * sptr )
{
	sprintf(sptr,"/tmp/pushpop%u.tmp",pushpopid);
	return;
}

/*	---------------------------------	*/
/*	s e t _ p u s h p o p i t o n s()	*/
/*	---------------------------------	*/
static	void	set_pushpoptions()
{
	char *	eptr;
	if (( eptr = getenv("ABALPUSHPOP")) != (char *) 0) {
		pushpoptions=0;
		while ( *eptr ) {
			if ((*eptr >= '0') && ( *eptr <= '9' ))
				pushpoptions = ((pushpoptions * 10) + ( *(eptr++) - '0') );
			else	break;
			}
		}
	else	pushpoptions=_PUSH_TO_FILE|_PUSH_BEFORE|_POP_AFTER;
}

/*	-------------------------------------	*/
/*	i n i t i a l i s e _ p u s h p o p()	*/
/*	-------------------------------------	*/
void	initialise_pushpop()
{
	char	nomfic[64];
	set_pushpoptions();
	if ( pushpoptions & _PUSH_TO_FILE ) {
		pushpopowner = getpid();
		if (!( pushpopid ))
			pushpopid = pushpopowner;
		pushpopfilename(nomfic);
		unlink( nomfic );
		}
	else	pushpopid = pushpopowner = 0;
	return;
}

/*	-----------------------------------	*/
/*	t e r m i n a t e _ p u s h p o p()	*/
/*	-----------------------------------	*/
void	terminate_pushpop()
{
	char	nomfic[64];
	if (!( pushpopid ))
		return;
	if ( pushpophandle != -1 ) {
		cicoclose( pushpophandle );
		pushpophandle  -1;
		}
	if ( pushpopid == pushpopowner ) {
		pushpopfilename(nomfic);
		unlink( nomfic );
		}
	pushpopid = 0;
	pushpopowner = -1;
	return;
}

/*	----------------------------		*/
/*	s e t _ p u s h p o p i d ()		*/
/*	----------------------------		*/
void	set_pushpopid(int v)
{
	if (!( pushpopid=v ))
		pushpoptions = 0;
	else 	set_pushpoptions();
	return;	
}

/*	----------------------------		*/
/*	g e t _ p u s h p o p i d ()		*/
/*	----------------------------		*/
int	get_pushpopid()		{	return( pushpopid  );	}

/*	---------------------------------	*/
/*	g e t _ p u s h p o p i t o n s()	*/
/*	---------------------------------	*/
int	get_pushpoptions()	{	return( pushpoptions);	}


/*	------------------------------------	*/
/*	c h e c k _ p u s h _ b e f o r e ()	*/
/*	------------------------------------	*/
/*	called prior to loadgo of an abal 	*/
/*	tcode program to save current screen	*/
/*	context to be recovered as the initial	*/
/*	screen of the target program. 		*/
/*	This will be erased if the program is	*/
/*	not NOCLR				*/
/*	-------------------------------------	*/
void	check_push_before()	
{
	if (!( pushpopid ))
		return;
	else if ( pushpoptions & _PUSH_BEFORE ) {
#ifdef	USE_PUSH_TRACE
		pushtrace("check push before");
#endif
		x_putch(27);
		x_putch('>');
		}
	return;
}

/*	----------------------------	*/
/*	c h e c k _ a u t o p o p ()	*/
/*	----------------------------	*/
/*	the loadgo target recovers its	*/
/*	initial screen contents.	*/
/*	----------------------------	*/
void	check_autopop()	
{
	if (!( pushpopid ))
		return;
	else if (!( pushpoptions & _PUSH_BEFORE )) 
		return;
	else if ( pushpopid != pushpopowner ) {
#ifdef	USE_PUSH_TRACE
		pushtrace("check autopop");
#endif
		x_putch(27);
		x_putch('<');
		}
	return;
}

/* ------------------------------------- */
/* require to avoid new line before push */
/* ------------------------------------- */
int	would_autopush()	
{
	if (!( pushpopid ))
		return(0);
	else if (!( pushpoptions & _PUSH_BEFORE )) 
		return(0);
	else if ( pushpopid != pushpopowner ) {
		return(1);
		}
}

/*	-----------------------------	*/
/*	c h e c k _ a u t o p u s h ()	*/
/*	-----------------------------	*/
/*	the loadgo target saves its	*/
/*	final screen contents on STOP	*/
/*	----------------------------	*/
void	check_autopush()	
{
	if (!( pushpopid ))
		return;
	else if (!( pushpoptions & _POP_AFTER )) 
		return;
	else if ( pushpopid != pushpopowner ) {
#ifdef	USE_PUSH_TRACE
		pushtrace("check autopush");
#endif
		x_putch(27);
		x_putch('>');
		}
	return;
}

/*	--------------------------------	*/
/*	c h e c k _ p o p _ a f t e r ()	*/
/*	--------------------------------	*/
/*	program returning after loadgo		*/
/*	recovers the final screen state		*/
/*	of the exiting program.			*/
/*	--------------------------------	*/

void	check_pop_after()	
{
	if (!( pushpopid ))
		return;
	else if ( pushpoptions & _POP_AFTER ) {
#ifdef	USE_PUSH_TRACE
		pushtrace("check pop after");
#endif
		x_putch(27);
		x_putch('<');
		}
	return;
}

/*	------------------------------------	*/
/*	g e t _ p u s h p o p h a n d l e ()	*/
/*	------------------------------------	*/
static	int	get_pushpophandle()
{
	char	nomfic[64];
	unsigned long offset=0L;
	if ( pushpophandle != -1 )
		return( pushpophandle );
	else	{
		pushpopfilename(nomfic);
		if ((pushpophandle = open( nomfic, O_RDWR )) == -1) {
			if ((pushpophandle = creat( nomfic, 0660 )) == -1)
				return( pushpophandle );
			else	cicoclose( pushpophandle ); 
			if ((pushpophandle = open( nomfic, O_RDWR )) == -1) 
				return( pushpophandle );
			else if ( lseek( pushpophandle, 0L, SEEK_SET ) != 0L ) {
				cicoclose(  pushpophandle );
				return(( pushpophandle = -1));
				}
			else if ( write( pushpophandle, &offset, sizeof( unsigned long )) !=  sizeof( unsigned long )) {
				cicoclose(  pushpophandle );
				return(( pushpophandle = -1));
				}
			}
		return( pushpophandle );
		}
}

/*	------------------------------------	*/
/*	c o _ p u s h _ to _ f i l e ()		*/
/*	------------------------------------	*/
int	co_push_to_file( int items, char * buffers[], int buflens[] )
{
	char *	bptr;
	int	h;
	int	i;
	unsigned long offset=0L;
	if (!( pushpoptions & _PUSH_TO_FILE )) 
		return(0);
	if (!( items ))
		return(0);
	if ((h = get_pushpophandle()) == -1)
		return(0);
	else if ( lseek( h, 0L, SEEK_SET ) != 0L )
		return(0);
	else if ( read( h, &offset, sizeof( unsigned long ) ) != sizeof( unsigned long ) )
		return(0);
	else	{
#ifdef	USE_PUSH_TRACE
		pushtrace("push to file");
#endif
		for ( i=0; i < items; i++ ) {
			if (!( bptr = buffers[i] ))
				break;
			else if (!( buflens[i] ))
				break;
			else if ( lseek( h, offset+ sizeof( unsigned long ),  SEEK_SET ) == -1L)
				break;
			else if ( write(h, bptr, buflens[i] ) != buflens[i] )
				break;
			else	offset +=  buflens[i];
			}
		if ( lseek( h, 0L, SEEK_SET ) != 0L )
			return(0);
		else if ( write( h, &offset, sizeof( unsigned long ) ) != sizeof( unsigned long ) )
			return(0);
		else	return(1);
		}
}

/*	------------------------------------	*/
/*	c o _ p o p _ f r o m _ f i l e ()	*/
/*	------------------------------------	*/
int	co_pop_from_file( int items, char * buffers[], int buflens[] )
{
	char *	bptr;
	int	h;
	int	i;
	unsigned long offset=0L;
	if (!( pushpoptions & _PUSH_TO_FILE )) 
		return(0);
	if (!( items ))
		return(0);
	if ((h = get_pushpophandle()) == -1)
		return(0);
	else if ( lseek( h, 0L, SEEK_SET ) != 0L )
		return(0);
	else if ( read( h, &offset, sizeof( unsigned long ) ) != sizeof( unsigned long ) )
		return(0);
	else	{
#ifdef	USE_PUSH_TRACE
		pushtrace("pop from file");
#endif
		for ( i=0; i < items; i++ ) {
			if (!( bptr = buffers[i] ))
				break;
			else if (!( buflens[i] ))
				break;
			else if ( lseek( h,((offset+sizeof( unsigned long )) - buflens[i]),  SEEK_SET ) == -1L)
				break;
			else if ( read( h, bptr, buflens[i] ) != buflens[i] )
				break;
			else	offset -=  buflens[i];
			}
		if ( lseek( h, 0L, SEEK_SET ) != 0L )
			return(0);
		else if ( write( h, &offset, sizeof( unsigned long ) ) != sizeof( unsigned long ) )
			return(0);
		else	return(1);
		}
}

/*	--------------------	*/
/*	p u s h _ w i p e () 	*/
/*	--------------------	*/
static	VOID	push_wipe()
{

	image_st *image;
	int longueur;

	_co_reset_attribut();
	_co_set_attribut();
	image = &courant->image;
#ifdef AIX_VERS
#ifdef SPARC
	longueur = nombre_ligne * nb_colonne;
#else
	longueur = nb_ligne * nb_colonne;
#endif
#else  /* AIX_VERS */
	longueur = nb_ligne * nb_colonne;
#endif /* AIX_VERS */
	memset(image->caractere, ' ', longueur);
	memset(image->attribut, A_NORMAL, longueur);
	if (flag_couleur == TRUE) {
#ifdef ABALCONF
		memset(image->texte, courant->def_char, longueur);
		memset(image->fond, courant->def_back, longueur);
#else
		memset(image->texte, courant->defaut, longueur);
		memset(image->fond, C_BACK, longueur);
#endif /* ABALCONF */
	}
#ifdef ABALCONF
	courant->texte = courant->def_char;
	courant->fond = courant->def_back;
#else
	courant->texte = courant->defaut;
	courant->fond = C_BACK;
#endif /* ABALCONF */
}

/*	--------------		*/
/*	x _ w i p e ()  	*/
/*	--------------		*/
/*	when NOCLR		*/
/*	--------------		*/

VOID x_wipe()
{
	if (!( pushpopid ))
		push_wipe();
	else if (!( pushpoptions & _PUSH_BEFORE )) 
		push_wipe();
	else if ( pushpopid == pushpopowner )
		push_wipe();

	return;
}

/*	----------------------------------------	*/
/*	c o _ p u s h _ to _ n e w _ f i l e ()		*/
/*	----------------------------------------	*/
int	co_push_to_new_file( int items, char * buffers[], int buflens[] )
{
	char *	bptr;
	int	h;
	int	i;
	char 	nomfic[256];

	unsigned long offset=0L;

	if (!( items ))
		return(0);

	sprintf(nomfic,"escQ%u%u.psh",getpid(),++pushcounter);

	if ((h = open( nomfic, O_RDWR )) == -1) {
		if ((h = creat( nomfic, 0660 )) == -1)
			return( 0 );
		else	cicoclose( h ); 
		if ((h = open( nomfic, O_RDWR )) == -1) 
			return( 0 );
		}
	for ( i=0; i < items; i++ ) {
		if (!( bptr = buffers[i] ))
			break;
		else if (!( buflens[i] ))
			break;
		else if ( lseek( h, offset,  SEEK_SET ) == -1L)
			break;
		else if ( write(h, bptr, buflens[i] ) != buflens[i] )
			break;
		else	offset +=  buflens[i];
		}
	return(1);
}

	/* -------- */
#endif	/* _apush_c */
	/* -------- */

