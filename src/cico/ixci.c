#ifndef	_ixci_c
#define	_ixci_c

/*************************************************************************
 *									 *
 *		Primitives internes de la gestion du clavier		 *
 *									 *
 *************************************************************************/

#define NEW_TEMPO

/*	------------------	*/
/*	_trap_signal_alarm	*/
/*	------------------	*/

void	_trap_signal_alarm(nb)
int nb;
{
	(VOID) signal(SIGALRM,_trap_signal_alarm);
	return;
}

/*	---------	*/
/*	_read_buf	*/
/*	---------	*/

static int _read_buf( CHAR * buf, int nb, int flag)
{
	void (*sv_signal) ();		

	int n;
	int r_err;
	static int conv=1;

	struct itimerval sv_tvalue, tvalue, tvalue2;
	int tret;

	errno=0;
			
	if (nb > 0) 
	{
		/* ------------------------------ */
		/* Next bytes to be read may wait */
		/* ------------------------------ */
		delay_on();

#ifdef NEW_TEMPO		
		sv_signal=signal(SIGALRM, _trap_signal_alarm);
		
		/* --------------------------------------------------------------------------------------------------- */
		/* Mise en place d'une temporisation de la lecture clavier et sauvegarde de la temporistaion courante. */
		/* --------------------------------------------------------------------------------------------------- */
		tvalue.it_interval.tv_sec=0L;
		tvalue.it_interval.tv_usec=0L;
		tvalue.it_value.tv_sec=tempo/10;
		tvalue.it_value.tv_usec=(tempo%10)*100000L;
		tret=setitimer(ITIMER_REAL, &tvalue, &sv_tvalue);
#endif

#ifdef LINUX
		if (proterm.c_cc[VTIME]  == 0) 
		{
			if ( ioctl(STDIN, TCGETA, &proterm) != -1)
			{
				proterm.c_cc[VTIME] = tempo;
				proterm.c_cc[VMIN] = 0;
				/* ---------------------- */
				/* who's closed the stdin */
				/* ---------------------- */
				if ( ioctl(STDIN, TCSETA, &proterm) == -1) 
				{
					if ( errno == ENOTTY ) 
					{
						err_val = EXER_DEVFAIL;
#ifdef EXABAL
						sprintf(SysLogBuffer, "Error: _read_buf failed: Next bytes, errno=%d, err_val=%d", errno, err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
#endif
					}
					return(0);
				}
			}
		}
#endif
		errno = 0; 
		n=read(STDIN,buf,1);
		r_err=errno;

#ifdef	_MOUSE_TRACE
		if ( n != -1 ) 
		{
			if ( TraceMouse )
			{
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"ixi.c 1   : %d=read(STDIN,%x,N);\r\n",n,*buf);
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
			}
		}
#endif

#ifdef NEW_TEMPO		
		/* ---------------------- */
		/* Purger les reemissions */
		/* ---------------------- */
		tvalue2.it_interval.tv_sec=0L;		
		tvalue2.it_interval.tv_usec=0L;
		tvalue2.it_value.tv_sec=0L;
		tvalue2.it_value.tv_usec=0L;
		tret=setitimer(ITIMER_REAL, &tvalue2, &tvalue);

		/* ------------------------------------------------------------------ */
		/* #BG 16/08/18 Restorer la tempo initiale eventuelle (ON TIMER ABAL) */
		/* ------------------------------------------------------------------ */
		tret=setitimer(ITIMER_REAL, &sv_tvalue, &tvalue);		
		signal(SIGALRM, sv_signal);
#endif		
		delay_off();
		
		/* ----------------------------------- */
		/* #BG 12/12/12 Interruption (SIGTERM) */
		/* ----------------------------------- */
		if (( n < 1 ) && ( r_err==EINTR )) 
			return( 0 );
		else	
		{
			/* ------------------------- */
			/* #BG 24/03/11 Gestion UTF8 */
			/* ------------------------- */
			if (n == 1) 
				if (flag == TRUE)
					n=get_twin_code(buf, 1, 0);
			return( n );
		}
	}
	else	
	{
		/* ----------------------------------- */
		/* first byte to be read must not wait */
		/* ----------------------------------- */
#ifdef LINUX
		if (proterm.c_cc[VTIME]  != 0) 
		{
			if ( ioctl(STDIN, TCGETA, &proterm) != -1 ) 
			{
				proterm.c_cc[VTIME] = 0;
				proterm.c_cc[VMIN] = 1;
				/* ---------------------- */
				/* who's closed the stdin */
				/* ---------------------- */
				if ( ioctl(STDIN, TCSETA, &proterm) == -1 )  
				{
					if ( errno == ENOTTY ) 
					{
						err_val = EXER_DEVFAIL;
#ifdef EXABAL
						sprintf(SysLogBuffer, "Error: _read_buf failed: First byte, errno=%d, err_val=%d", errno, err_val);
						ExaSysLog(EXA_SYSLOG_ERROR, SysLogBuffer);
#endif
					}
					return(0);
				}
			}
		}
#endif
		errno = 0;
		n=read(STDIN,buf,1);
		r_err=errno;

		/* ---------------------------------- */
		/* #BG 12/12/12 Interruption (SIGTERM) */
		/* ---------------------------------- */
		if ((n == -1) && (r_err==EINTR)) 
			return( 0 );
			
		/* ------------------------- */
		/* #BG 24/03/11 Gestion UTF8 */
		/* ------------------------- */
		if (n == 1) 
			if (flag == TRUE)
				n=get_twin_code(buf, 1, 0);

#ifdef	_MOUSE_TRACE
		if ( n != -1 ) 
		{
			if ( TraceMouse )
			{
				if (MouseTrace == (FILE*)0)
					MouseTrace = fopen(MOUSE_TRACE_FILE,"a");
				fprintf(MouseTrace,"ixi.c 2   : %d=read(STDIN,%x,1);\r\n",n,*buf);
				fclose(MouseTrace);
				MouseTrace = (FILE*) 0;
			}
		}
#endif
		return( n ); 
	}
}


#endif	/* _ixci_c */
	/* ------- */


