#ifndef WIN32
unsigned short int err_val=0;
#endif

char *	rt_init=(char *) 0;

void	rt_error()	{ return; }
long	_aFftol()	{	return(0L);	}
#ifndef WIN32 /* #FCH */
void	_cfltcvt()	{ 	return; 	}
void	_cropzeros()	{ 	return; 	}
#endif


