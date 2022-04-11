
#ifndef	PROLOGUE
#include <time.h>

extern		long	int timezone;
static			int trclock[16];

VOID read_date_information()
{
	struct tm * LocalTime;
#ifdef UNIX
	unsigned	long	int systime = 0L;

	/* Read the system Clock */
	/* --------------------- */
	systime = time((unsigned long *) 0);
#else
	time_t        systime;

	/* Read the system Clock */
	/* --------------------- */
	time(&systime);
#endif



	/* Convert to Local Time */
	/* --------------------- */
	LocalTime = (struct tm *)localtime(&systime);

	/* Transfer to exclock matrix */
	/* -------------------------- */
	trclock[0] = 1900 + LocalTime->tm_year;
	trclock[1] = 1    + LocalTime->tm_mon;
	trclock[2] = LocalTime->tm_mday;
	trclock[3] = LocalTime->tm_yday;
	trclock[4] = LocalTime->tm_hour;
	trclock[5] = LocalTime->tm_min;
	trclock[6] = LocalTime->tm_sec;
	trclock[8] = (LocalTime->tm_wday+1);
	return;

}

WORD	directive_date()
{
	char dbuffer[16];
	char * dzero;
	char mbuffer[16];
	char * mzero;
	char ybuffer[16];

	if ( OtrOption.DirectiveDate ) {

		read_date_information();

		sprintf(dbuffer,"%u",trclock[2]);
		if ( strlen(dbuffer) == 1 )
			dzero = "0";
		else	dzero = "\0";
		sprintf(mbuffer,"%u",trclock[1]);
		if ( strlen(mbuffer) == 1 )
			mzero = "0";
		else	mzero = "\0";
		sprintf(ybuffer,"%u",trclock[0]);
		sprintf(TokenBuffer,"%c%s%s/%s%s/%s",0x0022,dzero,dbuffer,mzero,mbuffer,&ybuffer[2],0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else	{
		/* this is maintained for AVNOR to avoid tcode change at each compile */
		/* ------------------------------------------------------------------ */
		sprintf(TokenBuffer,"%c%s%c",0x0022,"DD/MM/YYYY",0x0022);
		return((strlen(TokenBuffer)+2));
		}
}

WORD	directive_time()
{
	char hbuffer[16];
	char * hzero;
	char mbuffer[16];
	char * mzero;
	char sbuffer[16];
	char * szero;

	if ( OtrOption.DirectiveDate ) {
		read_date_information();

		sprintf(hbuffer,"%u",trclock[4]);
		if ( strlen(hbuffer) == 1 )
			hzero = "0";
		else	hzero = "\0";
		sprintf(mbuffer,"%u",trclock[5]);
		if ( strlen(mbuffer) == 1 )
			mzero = "0";
		else	mzero = "\0";
		sprintf(sbuffer,"%u",trclock[6]);
		if ( strlen(sbuffer) == 1 )
			szero = "0";
		else	szero = "\0";
		sprintf(TokenBuffer,"%c%s%s:%s%s:%s%s",0x0022,hzero,hbuffer,mzero,mbuffer,szero,sbuffer,0x0022);
		return((strlen(TokenBuffer)+2));
	}
	else	{
		/* this is maintained for AVNOR to avoid tcode change at each compile */
		/* ------------------------------------------------------------------ */
		sprintf(TokenBuffer,"%c%s%c",0x0022,"HH:MM:SS",0x0022);
		return((strlen(TokenBuffer)+2));
		}
}

#else

WORD	directive_date()
{
	sprintf(TokenBuffer,"%c%s%c",0x0022,"DD/MM/YYYY",0x0022);
	return((strlen(TokenBuffer)+2));
}

WORD	directive_time()
{
	sprintf(TokenBuffer,"%c%s%c",0x0022,"HH:MM:SS",0x0022);
	return((strlen(TokenBuffer)+2));
}

#endif	/* PROLOGUE */


