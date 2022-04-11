#ifndef	_stdsignal_h
#define	_stdsignal_h

/*	--------------------------------------------------------	*/
/*	This fichier describes the two interface functions that		*/
/*	are to be used for access to the new standardised signal	*/
/*	loging facilities control by the environment variable		*/
/* 	provided at initisation, or STDSIGNAL by  default,		*/
/*	STDSIGNAL=hexvalue where each bit weight represents the		*/
/*	various signals, in order from 0x0001 to 0x400,			*/
/*	described below :						*/
/*									*/
/*	Trapped or Default :						*/
/*	--------------------						*/
/*	SIGBUS,SIGSEGV,SIGILL,SIGFPE,SIGINT,SIGTERM,SIGHUP,SIGPIPE	*/
/*									*/
/*	Ignored or Default :						*/
/*	--------------------						*/
/*	SIGALRM,SIGUSR2,SIGUSR1,SIGCHLD,SIGTSTP,SIGPWR,SIGSYS		*/
/*									*/
/*	--------------------------------------------------------	*/
 

/*	--------------------------------------------------------	*/
/*	s t a n d a r d _     l o g     _ s i g n a l ( signal )	*/
/*	--------------------------------------------------------	*/
/*	This function is used to log  signal trapping events    	*/
/*	--------------------------------------------------------	*/
void		standard_log_signal( int sigid, char * message );

/*	--------------------------------------------------------------	*/
/*	s t a n d a r d _   i n i t   _ s i g n a l s (module,variable)	*/
/*	--------------------------------------------------------------	*/
int	standard_init_signals(char * modulename, char * variablename);


#endif	/* _stdsignal_h */
	/* ------------ */


