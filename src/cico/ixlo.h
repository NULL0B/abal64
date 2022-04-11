#ifndef	_ixlo_h
#define	_ixlo_h

#ifndef	INTERFACE
#define	INTERFACE
#endif

#ifndef	DIM_OUT_BUF
#define	DIM_OUT_BUF 512
#endif

#include "_type.h"

/*
 *	Gestion des imprimantes
 *	-----------------------
 */

PRIVATE BYTE out_buflo[DIM_OUT_BUF];	/* buffer de sortie		*/
PRIVATE WORD out_nblo = 0;		/* nb de car. dans le buffer	*/
PRIVATE BOOL flag_buflo = FALSE;	/* TRUE si bufferisation sortie imprimante */

PRIVATE	CHAR *tbl_defaut = NULL;
PRIVATE	CHAR *tbl_chemin = NULL;
PRIVATE	CHAR *enter_local=(CHAR *) 0;
PRIVATE	CHAR *exit_local=(CHAR *) 0;

/*
 *	position et dimensions des imprimantes
 *	--------------------------------------
 */

#define NB_IMPRIMANTE	64		/* nombre d'imprimantes         */

PRIVATE imprimante_st *imprimante[NB_IMPRIMANTE] = {
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
};

#define courante	imprimante[prnfid]

PRIVATE VOID _lo_conv();
PRIVATE VOID _lo_out();
PRIVATE WORD _lo_open();
PRIVATE VOID _lo_close();
PRIVATE WORD _lo_defaut();
PRIVATE WORD _lo_tbl_charge();
PRIVATE VOID _lo_tbl_init();
PRIVATE VOID _lo_tbl_attribut();

PUBLIC	CHAR * getenv();


#endif	/* _ixlo_h */

