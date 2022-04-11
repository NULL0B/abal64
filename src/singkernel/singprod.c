#ifndef	_singprod_c
#define	_singprod_c

#define	MAX_PRODUCTION	10

private	struct	production_control	{
	FILE	*	handle[MAX_PRODUCTION];
	char	*	realname[MAX_PRODUCTION];
	char	*	tempname[MAX_PRODUCTION];
	} NameControl;


public	void	initialise_production_control()
{
	int	i;
	for ( i=0; i < MAX_PRODUCTION; i++ ) {
		NameControl.realname[i] = NameControl.tempname[i] = (char * ) 0;
		NameControl.handle[i] = (FILE *) 0;
		}
	return;
}


private	void	reset_production_control(int i)
{
	if ( NameControl.handle[i] )
		fclose(NameControl.handle[i]);
	if ( NameControl.realname[i] )
		liberate( NameControl.realname[i] );
	if ( NameControl.tempname[i] )
		liberate( NameControl.tempname[i] );
	NameControl.realname[i] = NameControl.tempname[i] = (char * ) 0;
	NameControl.handle[i] = (FILE *) 0;
	return;
}
	
public	void	release_production_control()
{
	int	i;
	for ( i=0; i < MAX_PRODUCTION; i++ ) {
		reset_production_control(i);
		}
	return;
}

/*	--------------------------------------------------------------		*/
/*	o p e n _ p r o d u c t i o n _ t a r g e t ( filename, mode )		*/
/*	--------------------------------------------------------------		*/

public	FILE *	open_production_target(
	char *	filename,
	int	mode )		/* 0 : ASCII, 1, BINARY */
{
	FILE	*	h=(FILE *) 0;
	int		i;
	char		tempname[64];

	/* Locate a free production target */
	/* ------------------------------- */
	for (	i=0; i < MAX_PRODUCTION; i++ )
		if (!( NameControl.handle[i] ))
			break;

	/* Too many nested production targets */
	/* ---------------------------------- */
	if (( i >= MAX_PRODUCTION )) 
		return((FILE *) 0);
	else	reset_production_control(i);

#ifdef	UNIX
	while (1) {
		if ( Access( filename, 0, 1 ) != 0 )
			break;
		else if ( errno != 44 )
			break;
		else if ( fileshare_failure( filename ) != 27 )
			continue;
		else	return( (FILE *) 0 );
		}
#endif
	/* Allocate storage for real file name */
	/* ----------------------------------- */
	if (!( NameControl.realname[i] = allocate_string( filename )))
		return((FILE *) 0);

#ifdef	UNIX
	/* Allocate Storage for Temporary filename */
	/* --------------------------------------- */
	unique_filename( tempname );

	if (!( NameControl.tempname[i] = allocate_string( tempname ) ))
		return((FILE *) 0);

	/* Attempt to create temporary work file */
	/* ------------------------------------- */
	while (!(h = fopen(tempname,(mode & 1 ? "wb" : "w"))))
		if ( creation_failure( tempname ) == 27 )
			break;

	(void) Access( tempname, 0, 1 );
#else
	/* Attempt to create temporary work file */
	/* ------------------------------------- */
	while (!(h = fopen(filename,(mode & 1 ? "wb" : "w"))))
		if ( creation_failure( filename ) == 27 )
			break;
#endif
	return((NameControl.handle[i] = h));

}

/*	------------------------------------------------------------------	*/
/*	c l o s e _ p r o d u c t i o n _ t a r g e t ( handle, filename )	*/
/*	------------------------------------------------------------------	*/

public	void	close_production_target( FILE * h, char * nptr )
{
	FILE *	wh=(FILE*)0;
	int	i;
	char *	wptr;
	/* Locate the production control entry for this name */
	/* ------------------------------------------------- */
	for (i=0; i < MAX_PRODUCTION; i++ ) 
		if ( string_compare( NameControl.realname[i], nptr ) )
			break;

	/* whoooopsss ...	*/
	/* -------------------- */
	if (( i >= MAX_PRODUCTION )) return;

	if ( NameControl.handle[i] != (FILE *) 0 ) {
		fclose(h);
		NameControl.handle[i] = (FILE *) 0;
#ifdef	UNIX
		if ((wptr = allocate( strlen(NameControl.tempname[i])+strlen(NameControl.realname[i])+64)) != (char *) 0) {
			if ((wh = fopen(NameControl.realname[i],"r")) != (FILE *) 0) {
				fclose(wh);
				sprintf(wptr,"mv %s %s.bak",NameControl.realname[i],NameControl.realname[i]);
				system(wptr);
				}
			sprintf(wptr,"mv %s %s",NameControl.tempname[i],NameControl.realname[i]);
			system(wptr);
			liberate( wptr );
			}
		liberlox(NameControl.tempname[i]);
		liberlox(NameControl.realname[i]);
#endif
		}
	reset_production_control(i);
	return;
}

/*	-----------------------------------------	*/
/*	 Inclusion of standard production methods	*/
/*	-----------------------------------------	*/
#include "vtype.c"


#endif	/* _singprod_c */
	/* ----------- */

