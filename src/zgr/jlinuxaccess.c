#ifndef	public	
#define	public
#endif

#ifndef	private
#define	private static
#endif

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

private	void  	connect_access_controller( BDA_INIT * iptr, void * eptr )
{
	int	i;
	void *	vptr;
	
	if (!( iptr ))
		return;

	for (i=0; i < CICO_NOMBRE; i++ ) {
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

public	int	x_graph(int i, void * dptr )
{
	return( (CicoAccessController.FunctionRelay[CICO_GRAPH])(i,dptr) );
}

public	int	x_event(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_EVENT])(i) );

}
public	int	x_putch(int i)
{
	return( (CicoAccessController.FunctionRelay[CICO_CO])(i) );

}

public	int	x_lin()
{
	return( (CicoAccessController.FunctionRelay[CICO_LIGNE])() );

}

public	int	x_col()
{
	return( (CicoAccessController.FunctionRelay[CICO_COLONNE])() );
}

private	void	prepare_access_controller(BDA * dptr, int functions)
{
	dptr->fonction[functions+1]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+2]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+3]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+4]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+5]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+6]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+7]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+8]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+9]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+10]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+11]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+12]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+13]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+14]	= (WORD (FAR PTR)()) 0;
	dptr->fonction[functions+15]	= (WORD (FAR PTR)()) connect_access_controller;
	dptr->fonction[functions+16]	= (WORD (FAR PTR)()) 0;

	if (rt_init != (VOID FAR PTR) 0L) {
		rt_init->cico.numero = 16384;
		rt_init->cico.fonction[CICO_CI]     = dptr->fonction[functions+1]; 
	 	rt_init->cico.fonction[CICO_TPCI]   = dptr->fonction[functions+2];
	  	rt_init->cico.fonction[CICO_PRFO]   = dptr->fonction[functions+3];  	
		rt_init->cico.fonction[CICO_LCFO]   = dptr->fonction[functions+4];  	
		rt_init->cico.fonction[CICO_CONF]   = dptr->fonction[functions+5]; 	
		rt_init->cico.fonction[CICO_CO]     = dptr->fonction[functions+6]; 	
		rt_init->cico.fonction[CICO_MES]    = dptr->fonction[functions+7]; 	
		rt_init->cico.fonction[CICO_LIGNE]  = dptr->fonction[functions+8]; 	
		rt_init->cico.fonction[CICO_COLONNE]= dptr->fonction[functions+9]; 	
		rt_init->cico.fonction[CICO_START]  = dptr->fonction[functions+10]; 	
		rt_init->cico.fonction[CICO_FLUSH]  = dptr->fonction[functions+11]; 	
		rt_init->cico.fonction[CICO_LO]     = dptr->fonction[functions+12]; 	
		rt_init->cico.fonction[CICO_MIMA]   = dptr->fonction[functions+13];   
		rt_init->cico.fonction[CICO_EVENT]  = dptr->fonction[functions+14];
		rt_init->cico.fonction[CICO_INIT]   = dptr->fonction[functions+15];
		rt_init->cico.fonction[CICO_GRAPH]  = dptr->fonction[functions+16];
		}
	return;
}

