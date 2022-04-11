#ifndef	_nedcico_c
#define	_nedcico_c

#ifdef UNIX

/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

static	struct	cico_access_controller	{

	WORD   FunctionCount;
	WORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

static	void	initialise_access_controller()
{
	CicoAccessController.FunctionCount = CICO_NOMBRE;

	CicoAccessController.FunctionRelay[CICO_CI] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_TPCI]	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_PRFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LCFO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CONF] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_CO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MES] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LIGNE] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_COLONNE]= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_START] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_FLUSH] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_LO] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_MIMA] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_EVENT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_INIT] 	= (void *) 0;
	CicoAccessController.FunctionRelay[CICO_GRAPH] 	= (void *) 0;
  	return;
}

/*	-------------------------------------------------	*/
/* 	This function is provided to  perform redirection	*/
/*	--------------------------------------------------	*/

static	void *	redirect_access_controller( int	item,  void *	fptr )
{
	void	*	vptr=(void *) 0;
	if ((item >= 0) && ( item < CicoAccessController.FunctionCount )) {
		if ( fptr ) {
			vptr = CicoAccessController.FunctionRelay[item]; 	
			CicoAccessController.FunctionRelay[item] = fptr;
	 		}
 		}
	return( vptr );
}

static	EXAWORD  	connect_access_controller( BDA_INIT * iptr, void * eptr, struct cico_access_controller * cptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return(0);

	for (i=0; i < CICO_NOMBRE; i++ ) {
/*	---------------------------------------------------------------------------	*/
/*	it would be good to use an indirection to be able to overload some of these 	*/
/*	by later arriving dlls ,like printer 						*/
/*	vptr = &iptr->cico.function[i] for example					*/
/*	---------------------------------------------------------------------------	*/
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return(0);
}

int	conf(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(i) );
}

int	x_conf(int i)
{
	return( conf(i) );
}


int	x_graph( int i, struct x_graph_descriptor * dptr )
{
	void	* vptr;
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(i,dptr) );
}

int	x_event(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(i) );

}

int	x_getch() 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_CI])() ); 
}

int	x_kbhit() 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_TPCI])() ); 
}

int	xgr_prfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(i,c,l) );
}

int	xgr_lcfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(i,c,l) );
}

int	x_putch(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );

}

int	x_cprintf(BYTE * mptr)
{
	return( (CicoAccessController.FunctionRelay[CICO_MES])(mptr) );
}

int	x_bell()	
{	
	x_putch(7);	
}

int	lcfo(int n, char  * buffer, int blen) 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(n,buffer,blen) ); 
} 

int	prfo(int n, char  * buffer, int blen) 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(n,buffer,blen) ); 
}


int	atb( int attribut )
{
	switch (attribut) {
	case 0: 		/* visualisation normale */
		attribut = 'a';
		break;
	case 1: 		/* attribut preferentiel */
		attribut = 'p';
		break;
	case 2: 		/* inversion video */
		attribut = 'b';
		break;
	case 3: 		/* clignotement */
		attribut = 'c';
		break;
	case 4: 		/* soulignement */
		attribut = 'd';
		break;
	case 5: 		/* sous-brillance */
		attribut = 'e';
		break;
	case 6: 		/* sur-brillance */
		attribut = 'h';
		break;
	case 7: 		/* lettres forcees majuscules */
		attribut = 'i';
		break;
	case 8: 		/* lettres forcees minuscules */
		attribut = 'j';
		break;
	case 9: 		/* hard copy */
		attribut = 'O';
		break;
	case 10:		/* caracteres penches */
		attribut = 'y';
		break;
	case 11:		/* double largeur */
		attribut = 'z';
		break;
	case 12:
		attribut = 'k';
		break;
	case 13:
		attribut = 'l';
		break;
	case 14:
		attribut = 'm';
		break;
	case 15:
		attribut = 'n';
		break;
	case 16:
		attribut = 'q';
		break;
	case 17:
		attribut = 'r';
		break;
	case 18:
		attribut = 's';
		break;
	case 19:		/* double hauteur */
		attribut = 't';
		break;
	case 20:
		attribut = 'Q';
		break;
	case 21:		/* effacement fin de ligne */
		attribut = 'K';
		break;
	case 22:		/* effacement fin de page */
		attribut = 'J';
		break;
	case 23:		/* insertion de ligne */
		attribut = 'L';
		break;
	case 24:		/* suppression de ligne */
		attribut = 'M';
		break;
	case 25:		/* extinction curseur */
		attribut = 'w';
		break;
	case 26:		/* allumage curseur */
		attribut = 'v';
		break;
	case 27:
		attribut = '*';
		break;
	case 28:
		attribut = '#';
		break;
	case 29:		/* caracteres compactes */
		attribut = 'x';
		break;
	case 30:		/* indice ou push ecran */
		attribut = '>';
		break;
	case 31:		/* exposant ou pop ecran */
		attribut = '<';
		break;
	default:
		return;
	}
	x_putch(27);
	x_putch(attribut);

	return(0);
}

int	x_col(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_COLONNE])(i) );
}

int	x_lin(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_LIGNE])(i) );
}

int	pos(int ligne, int colonne)
{
	x_putch(27);
	x_putch('f');
	x_putch((colonne-1) + 0x0020);
	x_putch((ligne-1) + 0x0020);
	return(0);
}

int 	backgr(int couleur)
{
	couleur &= 0x000F;
	x_putch(27);
	x_putch('s');
	x_putch(couleur + '0');
	return(0);
}

int 	washgr(int couleur)
{
	couleur &= 0x001F;
	x_putch(27);
	x_putch('n');
	x_putch(couleur + '0');
	return(0);
}

int 	foregr(int couleur)
{
	if ((couleur >= 0) && (couleur <= 9))
		{
		x_putch(27);
		x_putch('r');
		x_putch(couleur + '0');
		}
	else if ((couleur >= 10) && (couleur <= 15))
		{
		x_putch(27);
		x_putch('r');
		x_putch(couleur - 10 + 'A');
		}
	return(0);
}

int	x_bstart()
{
	return( (CicoAccessController.FunctionRelay[CICO_START])() ); 
}

int	x_bflush()
{
	return( (CicoAccessController.FunctionRelay[CICO_FLUSH])() ); 
}

#endif

#endif	/* _nedcico_c */
	/* ---------- */

