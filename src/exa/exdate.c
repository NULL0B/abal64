/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1989 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDATE - C				*/
/*		Version	:	1.2b					*/
/*		Date 	:	15/12/1989				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	WIN32

#include <time.h>

#define	DAYannee 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31

EXAWORD	leapyear( y )
EXAWORD	y;
{
if( ((( y % 4 ) == 0) && (( y % 100 ) != 0)) || (( y % 400) == 0)) {
		return(DAYannee + 1);
		}
else { return(DAYannee); }
}

EXAWORD	leapmois( y , m ) 
EXAWORD	y,m;
{
	switch ( m ) {
		case 1  :
		case 3  :
		case 5  :
		case 7  :
		case 8  :
		case 10 :
		case 12 : return(31);
		case 2  :
			if( ((( y % 4 ) == 0) && (( y % 100 ) != 0)) || (( y % 400) == 0)) {
				return(29);
				}
			else { return(28); }
		default : return(30);
		}
}

#define	SECmin	 60
#define	SEChour	 SECmin * 60
#define	SECjour  SEChour * 24
#define	YEARdot	 1970
#define YEARDOT  1900
#define	MOISdot	 1
#define MOISDOT  1
#define	JOURdot	 1

EXAWORD	exclock[10];	/* Date element Matrix Globally stored	*/
EXALONG	TimeZone;	/* Difference between local and GMT	*/ 
EXALONG	UnixTime;	/* Systeme GMT Time Value		*/

#ifdef AIX_VERS
#ifdef SPARC
VOID   modif_quantieme()
/* modification du quantieme si la date a change */
{
	EXAWORD jmois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
        EXAWORD jm;
	EXAWORD mm;
	EXAWORD y;

	y = exclock[0]+ 1970;
	if ( ((( y % 4 ) == 0) && (( y % 100 ) != 0)) || (( y % 400) == 0)) 
		jmois[1]=29;

	mm = 1;
	while (mm < exclock[1] )
		{jm += jmois[mm-1];mm++;};
	jm+=exclock[2];
	exclock[3] = jm;
	return;
}

EXAWORD modif_jour()
/* modification du jour si le quantieme a change */
{
	EXAWORD jmois[12] = { 31,28,31,30,31,30,31,31,30,31,30,31};
        EXAWORD qq;
	EXAWORD mm;
	EXAWORD y;

	y = exclock[0]+ 1970;
	if ( ((( y % 4 ) == 0) && (( y % 100 ) != 0)) || (( y % 400) == 0)) 
		jmois[1]=29;
	mm=0;
	qq=exclock[3];
	while (qq > jmois[mm])
		{++mm;qq -= jmois[mm]; };
	exclock[1] = mm+1;
	exclock[2] = qq;
	return(qq);
}
#endif
#endif /* AIX_VERS */
/*
 *	L I R D A T ( )
 *	---------------
 *	Read current UNIX time
 */
extern	long encryptiontime;

VOID lirdate(int mode)
{
	struct tm * LocalTime;
	EXALONG	unixtime;
	extern	long	int timezone;

	/* Read the system Clock */
	/* --------------------- */
	if ( mode > 10 )  
		unixtime = encryptiontime;
	else
		unixtime = time((EXALONG *) 0);

	UnixTime = (unixtime + timezone);

	/* Convert to Local Time */
	/* --------------------- */
	LocalTime = (struct tm * ) localtime(&unixtime);

	/* Transfer to exclock matrix */
	/* -------------------------- */
	exclock[0] = YEARDOT + LocalTime->tm_year;
	exclock[1] = MOISDOT + LocalTime->tm_mon;
	exclock[2] = LocalTime->tm_mday;		
	exclock[3] = LocalTime->tm_yday+1;	
	exclock[4] = LocalTime->tm_hour;
	exclock[5] = LocalTime->tm_min;
	exclock[6] = LocalTime->tm_sec;
	exclock[8] = LocalTime->tm_wday+1;
	return;

}

EXALONG	Ecart()
{
	EXALONG	unixtime=0L;
	EXALONG	worktime;
	EXAWORD	ExClock[8];
	EXAWORD	x;

	for ( x = 0; x < 8; x++) { ExClock[x] = exclock[x]; }
	unixtime = ExClock[6];		/* Add in the seconds	*/
	worktime =  ExClock[5];		/* Get minutes		*/
	worktime *= SECmin;		/* Create second count	*/
	unixtime += worktime;		/* Add in minutes	*/
	worktime =  ExClock[4];		/* Get Hour value	*/
	worktime *= SEChour;		/* Calculate Sec/hour	*/
	unixtime += worktime;		/* Add in hour value	*/
	ExClock[2]--;			/* Adjust Day count	*/
	worktime = ExClock[2]; 		/* Days in this month	*/
	worktime *= SECjour;		/* Calculate seconds	*/
	unixtime += worktime;		/* Cumulate please	*/
	worktime = 0;			/* Reset for month calc	*/
	ExClock[1]--;			/* Decrment en avance	*/

	while ( ExClock[1] > 0 ) {
		worktime += ( leapmois( ExClock[0],ExClock[1] ) * SECjour );
		ExClock[1]--;
		}

	unixtime += worktime;		/* Cumulate month value	*/
	ExClock[0]--;			/* Decrement en avance	*/

	while ( ExClock[0] >= YEARdot ) {
		unixtime += ( leapyear( ExClock[0] ) * SECjour );	
		ExClock[0]--;
		}
	/* Difference = GMT - LocalTime */
	/* ---------------------------- */
	TimeZone = timezone;
	return(unixtime);
}

/*
 *	E C R D A T E ( )
 *	-----------------
 *	Writes the new systeme date and Time !!!!! watch out Unix ........
 *
 */

EXAWORD	ecrdate()
{
	EXAWORD	x,y,z;
	EXALONG	unixtime;
	EXALONG	worktime;

	unixtime = exclock[6];		/* Add in the seconds	*/
	worktime =  exclock[5];		/* Get minutes		*/
	worktime *= SECmin;		/* Create second count	*/
	unixtime += worktime;		/* Add in minutes	*/
	worktime =  exclock[4];		/* Get Hour value	*/
	worktime *= SEChour;		/* Calculate Sec/hour	*/
	unixtime += worktime;		/* Add in hour value	*/
	exclock[2]--;			/* Adjust Day count	*/
	worktime = exclock[2]; 		/* Days in this month	*/
	worktime *= SECjour;		/* Calculate seconds	*/
	unixtime += worktime;		/* Cumulate please	*/
	worktime = 0;			/* Reset for month calc	*/
	exclock[1]--;			/* Decrment en avance	*/

	/* Months ==> Seconds Calcul */
	/* ------------------------- */
	while ( exclock[1] > 0 ) {
		worktime += ( leapmois( exclock[0],exclock[1] ) * SECjour );
		exclock[1]--;
		}
	unixtime += worktime;		/* Cumulate month value	*/
	exclock[0]--;			/* Decrement en avance	*/

	/* Years ==> Seconds Calcul */
	/* ------------------------ */
	while ( exclock[0] >= YEARdot ) {
		unixtime += ( leapyear( exclock[0] ) * SECjour );	
		exclock[0]--;
		}

	/* Adjust for TimeZone */
	/* ------------------- */
#ifdef AIX_VERS
#ifdef SPARC
	unixtime += timezone;
#else
	unixtime -= timezone;
#endif
#else  /* AIX_VERS */
	unixtime -= timezone;
#endif /* AIX_VERS */

	/* -------------------- */
	/* Set the systeme Time */
	/* -------------------- */
#undef	_USE_STIME
#ifdef	_USE_STIME
	/* int stime(const time_t *t); */
	return( stime( & unixtime  ) );
#else
	// ------------------------------------------------------
	// The use of the function STIME is DEPRECATED and should 
	// be replaced by the use of CLOCK SETTIME instead	
	// ------------------------------------------------------
	struct timespec ts;
	clockid_t clock=CLOCK_REALTIME;

	ts.tv_sec = unixtime;
	ts.tv_nsec = 0;

	return( clock_settime(clock, &ts) );

#endif

}

/*
 *	A L T D A T E ( )
 *	-----------------
 *	
 *	Allows alterations to the Systeme date if The System Allows !
 *
 *	1	Annee		5	Heure
 *	2	Mois		6	Minute
 *	3	Jour		7	Seconde
 *	4	Day count	8	Dixieme de seconde
 *				9	Week Day

 *	Returns : Zero OK , MOINS_UN Erreur
 */

/* -------------------------------------------- */
/* Date ( Workval1 ) = Workval2 		*/
/* ---------------------------- 		*/
/* EXAWORD	altdate(workval1,workval2) 	*/
/* unsigned short int workval1,workval2;   	*/
/* -------------------------------------------- */

EXAWORD	altdate()
{
/* #BG 31/01/19 Les 10emes de sec ne sont pas geres sous UiLS avec la fct stime() !
	if (( workval1 < 1 ) || ( workval1 >  8 )) { return(MOINS_UN); }
*/
	if (( workval1 < 1 ) || ( workval1 >  7 )) { return(MOINS_UN); }

#ifndef AIX_VERS
	if (( workval1 % 4 ) == 0 ) { 
#else   /* AIX_VERS */
#ifdef SPARC
	if (workval2 == 8) {
#else
	if (( workval1 % 4 ) == 0 ) { 
#endif
#endif /* AIX_VERS */
		return(0); 
		}
	else 	{
		/* Read Current Date */
		/* ----------------- */
		lirdate(workval1);

		/* Calculate Ecart Local - GMT */
		/* --------------------------- */
		(void) Ecart();

		/* Establish New Date Element */
		/* -------------------------- */
		exclock[(workval1-1)] = workval2; 
#ifdef AIX_VERS
#ifdef SPARC
		/* modif mois/jour par quantieme */
		/* modif quantieme par mois/jour */
		if (workval1 == 4) modif_jour();
		if ( (workval1 == 2) || (workval2 == 3) ) modif_quantieme();
	
#endif
#endif /* AIX_VERS */

		/* Re-Write the Date */
		/* ----------------- */
		return( ecrdate() );
		}
}

/*
 *	D A T E ( f )
 *	-------------
 *	Reads and returns the system date and returns date(f)
 *  #BG Revision 31/01/19 et 17/06/19
 */

EXAWORD	date( f )
EXAWORD	f;
{
	switch(f) {
		/* n+10: Idem to n, but using the time stamp (cf encryptiontime) */
		case 1 :	/* Year */
		case 11	:
		case 2 :	/* Month */
		case 12	:
		case 3 :	/* Day */
		case 13	:
		case 4 :	/* Day of the year, #BG 11/03/19 Was previously calculated in f_clfd() as for Windows */
		case 14:
		case 5 :	/* Hour */
		case 15	:
		case 6 :	/* Min */
		case 16	:
		case 7 :	/* Sec */
		case 17	:
		case 9 :	/* Day of the week */
		case 19 :
			lirdate(f);
			return(exclock[((f%10)-1)]);

		/* #BG 31/01/19 et 17/06/19 ajout 10e, 100e, 1000e sec */
		case 8 :	/* 10e sec */
		case 20 :	/* 100e sec */
		case 21 :	/* 1000e sec */
		{
			struct timeval tv;

			gettimeofday(&tv, NULL);
			// tv.tv_usec varie entre 0 et 1000000=1s
			
			if (f==8)
				return (tv.tv_usec / 100000);
			else if (f==20)
				return (tv.tv_usec / 10000);
			else
				return (tv.tv_usec / 1000);
		}

		default:
			return(-1);
	}

	return(-1);
}

/* #BG 17/06/19 Ajout */
EXAWORD fulltime(BPTR ptime, int lg)
{
	struct timeval tv;
	long hms;
	int hour;
	int min;
	int sec;
	int mil; 

	#define SEC_PER_DAY   86400
	#define SEC_PER_HOUR  3600
	#define SEC_PER_MIN   60

	// Read system hour
	lirdate(5);
	hour = exclock[5-1];	// With localization

	gettimeofday(&tv, NULL);

	// Form the seconds of the day
	hms = tv.tv_sec % SEC_PER_DAY;
	// mod `hms` to insure in positive range of [0...SEC_PER_DAY)
	hms = (hms + SEC_PER_DAY) % SEC_PER_DAY;

	// Tear apart hms into h:m:s
//	hour = hms / SEC_PER_HOUR;	// Without localization!
	min = (hms % SEC_PER_HOUR) / SEC_PER_MIN;
	sec = (hms % SEC_PER_HOUR) % SEC_PER_MIN; // or hms % SEC_PER_MIN

	// tv.tv_usec varie entre 0 et 1000000=1s
	mil = (tv.tv_usec / 1000);

	if (lg >= 10)
		sprintf(ptime, "%02d%02d%02d%03d", hour, min, sec, mil);
	else
		return(-1);

	return 0;
}


EXAWORD	datedays( d, m, y )
EXAWORD	d;
EXAWORD	m;
EXAWORD	y;
{
	EXALONG		unixtime;
	struct tm * 	LocalTime;
	if (!( y )) return(0);
	else if (!( m ))
		return( leapyear(y) );
	else if (!( d ))
		return( leapmois(y,m) );
	else	{
		/* week day */
		/* -------- */
		exclock[0]=y; exclock[1] = m; exclock[2] = d;
		exclock[3]= exclock[4]= 
		exclock[5]= exclock[6]= 0;
		unixtime  = Ecart();

		/* Convert to Local Time */
		/* --------------------- */
		LocalTime = (struct tm * ) localtime(&unixtime);

		/* Return Week Day Item */
		/* -------------------- */
		return( (LocalTime->tm_wday+1) );
		}
	
}

#endif	/* WIN32 */
