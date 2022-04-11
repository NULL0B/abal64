#ifndef	_iximploc_c
#define	_iximploc_c

PRIVATE	int	losyswrite(fh,bptr,blen)
	int	fh;
	BYTE  *	bptr;
	int	blen;
{
	while (1) {
		if ( write(fh,bptr,blen) != -1 )
			return( blen );
		else if ( errno == EAGAIN )
			continue;
		else	return(-1);
		}
}

#ifdef IMPLOC

PRIVATE 	BOOL	IMP_LOC_ACTIVE=FALSE;
PRIVATE	int	sharedlo=0;

PUBLIC	VOID	set_shared_lo(v)
int v;
{
	sharedlo = v;
	return;
}

/* Envoie de la sequence d'initialisation de l'imprimante locale */

PUBLIC	VOID	activate_local_lo(fh)
int fh;
{
	BYTE *pt;

	if (( pt=enter_local ) != (BYTE*) 0) {
		while((*pt)
		&&    (losyswrite(fh,pt++,1)==1));
		}
	return;

}

/* Envoie de la sequence de fermeture de l'imprimante locale */

PRIVATE	VOID	cancel_local_lo(fh)
int fh;
{
	BYTE	*pt;

	if ( IMP_LOC_ACTIVE == TRUE ) {
		/* Fermeture de la liaison imprimante locale */
		if ((pt=exit_local) != (BYTE *) 0) {
			while ((*pt)
			&&     (losyswrite(fh,pt++,1)==1));
			}
		/* Desactivation de l'imprimante locale */
		IMP_LOC_ACTIVE=FALSE;	
		}	
	return;
}


PUBLIC	VOID	terminate_local_lo()
{
	if ( IMP_LOC_ACTIVE == TRUE ) {
		if ( courante ) {
			cancel_local_lo( courante->handle );
			}
		}
	return;
}

PUBLIC	VOID	initialise_local_lo(aptr,tptr)
CHAR * aptr;
CHAR * tptr;
{
	enter_local = aptr;
	exit_local  = tptr;
	return;
}

#endif



#endif	/* _iximploc_c */

