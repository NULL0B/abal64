/*	--------------------------------------		*/
/*	Elements of the CICO Access Controller		*/
/*	--------------------------------------		*/

private	struct	cico_access_controller	{

	WORD   FunctionCount;
	WORD  (*FunctionRelay[CICO_NOMBRE])();

	} CicoAccessController;


/*	--------------------------------------		*/
/*	Access Controller Basic Initialisation		*/
/*	--------------------------------------		*/

private	void	initialise_access_controller()
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

private	void *	redirect_access_controller( int	item,  void *	fptr )
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

private	void  	connect_access_controller( BDA_INIT * iptr, void * eptr, struct cico_access_controller * cptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return;

	for (i=0; i < CICO_NOMBRE; i++ ) {
/*	---------------------------------------------------------------------------	*/
/*	it would be good to use an indirection to be able to overload some of these 	*/
/*	by later arriving dlls ,like printer 						*/
/*	vptr = &iptr->cico.function[i] for example					*/
/*	---------------------------------------------------------------------------	*/
		if ( i == CICO_GRAPH )
			XgraphPtr = &cptr->FunctionRelay[i];
		vptr = iptr->cico.fonction[i];
		if ( i != CICO_INIT )
			CicoAccessController.FunctionRelay[i] = vptr;
		}
	return;
}

public	int	x_conf(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(i) );
}

public	int	x_graph( int i, struct x_graph_descriptor * dptr )
{
	void	* vptr;
	vptr = *XgraphPtr;
	CicoAccessController.FunctionRelay[CICO_GRAPH]	= vptr;
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(i,dptr) );
}

public	int	x_event(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(i) );

}

public	int	xgr_prfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_PRFO])(i,c,l) );
}

public	int	xgr_lcfo(int i, char * c, int l )
{
	return( (CicoAccessController.FunctionRelay[CICO_LCFO])(i,c,l) );
}



public	int	x_putch(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );
}

public	int	x_col(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_COLONNE])(i) );

}

EXAWORD	x_getch() 
{ 
	return( (CicoAccessController.FunctionRelay[CICO_CI])() ); 
}

public	int	x_lin(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_LIGNE])(i) );

}
EXAWORD	conf(EXAWORD item)
{
	return( (CicoAccessController.FunctionRelay[CICO_CONF])(item) );
}

public	void	pos(int ligne, int colonne)	
{
	x_putch(27);
	x_putch('f');
	x_putch(colonne + 0x001f);
	x_putch(ligne + 0x001f);
	return;
}
public	void	paint(int fg, int bg )
{
	x_putch(27);
	x_putch('r');
	if ( fg < 10 )
		x_putch(fg+'0');
	else	x_putch((fg - 10) + 'A');
	x_putch(27);
	x_putch('s');
	if ( fg < 10 )
		x_putch(bg+'0');
	else	x_putch((bg - 10) + 'A');
	return;
}


public	void	enable_scroll()
{
	x_putch(27);
	x_putch('t');
	return;
}

public	void	inhibit_scroll()
{
	x_putch(27);
	x_putch('u');
	return;
}

public	void	enable_cursor()
{
	x_putch(27);
	x_putch('v');
	return;
}

public	void	inhibit_cursor()
{
	x_putch(27);
	x_putch('w');
	return;
}

