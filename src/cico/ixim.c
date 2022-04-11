#ifndef	_ixim_c
#define	_ixim_c

#include "ixlo.h"

/* ouverture d'un imprimante
 * -------------------------
 *
 * appel:	nom imprimante et autorisation
 *
 * retour:	valeur de prnfid
 *		-1 en cas d'erreur et code erreur dans err_val
 */
WORD im_open(name, mode)
BYTE *name;
WORD mode;
{
	int	i;			/* compteur de boucles		*/

	/* recherche d'une structure de description disponible */
	for (i = 1; i < NB_IMPRIMANTE; i++)
		if (imprimante[i] == NULL)
			break;
	if (i == NB_IMPRIMANTE) {
		err_val =  1;
		return (-1);
	}
	prnfid = i;

	/* ouverture de l'imprimante */
	return (_lo_open(name, mode));
}


/* fermeture d'un imprimante
 * -------------------------
 *
 * appel:	rien (prnfid doit etre positionne)
 *
 * retour:	rien
 *
 */
VOID im_close(handle)
int handle;
{
	int 	holder=-1;
	if ( prnfid != handle ) {
		holder = prnfid;
		prnfid = handle;
		}
	_lo_close();
	if ( holder != -1)
		prnfid = holder;
	return;
}

/*
 *	Ecriture sur imprimante 
 *	----------------------- 
 */
PUBLIC	VOID	im_write(ihandle,ibuffer,buflen)
int ihandle;
char * ibuffer;
int buflen;
{
	int	holder=prnfid;
	int	i;
	prnfid = ihandle;
	for (i=0; i < buflen; i++)
		local_x_lo( ( *(ibuffer +i) & 0x00FF ) );
	prnfid = holder;
	return;
}

PUBLIC	VOID	im_putch(handle,c)
int handle; 
int c;
{
	int	holder=prnfid;
	prnfid = handle;
	_lo_conv( c );
	prnfid = holder;
	return;
}

PUBLIC	VOID	im_pos(handle,ligne,colonne)
int handle;
int ligne;
int colonne;
{
	int	holder=prnfid;
	prnfid = handle;
	_lo_pos(ligne,colonne);
	prnfid = holder;
	return;
}

PUBLIC	WORD	im_lin(handle)
int handle;
{
	int	holder=prnfid;
	int	result;
	prnfid = handle;
	result =_lo_lin();
	prnfid = holder;
	return(result);
}

PUBLIC	WORD	im_col(handle)
int handle;
{
	int	holder=prnfid;
	int	result;
	prnfid = handle;
	result =_lo_col();
	prnfid = holder;
	return(result);
}


PUBLIC	WORD	initform(mode,nptr,pptr)
int mode;
char * nptr;
char * pptr;
{
	char	*	cp;
	char	*	lo;

	if (!( mode )) {

		/* lecture de la variable LO */
		if ((cp = getenv(ENV_IMPRIMANTE)) != NULL) {
			if ((lo = allocate(strlen(cp) + 1)) == NULL)
				return( FALSE );
			strcpy(lo, cp);
			tbl_defaut = lo;
			if ((cp = strchr(lo, ENV_SEPARATEUR)) != NULL) {
				*cp = '\0';
				tbl_chemin = ++cp;
				}
			else	tbl_chemin = NULL;
			}
		}

	else	{
		tbl_defaut = nptr;
		tbl_chemin  = pptr;
		}

	return(TRUE);
}

PUBLIC	VOID	finform()
{
	int	i;
	for (i = 0; i < NB_IMPRIMANTE; i++)
		if (imprimante[i] != NULL) 
			im_close((prnfid = i));
	return;
}

#endif	/* _ixim_c */
	/* --------- */


