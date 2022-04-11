/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1993, 1995
 *      Module  : ATR
 *      Fichier : DATE.C
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Fonction de conversion de la date systeme]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *         09/97 : Correction date prologue, creation prl_date en assembleur
 *      05/01/00 : Correction #DATE sous DOS/Windows pour date > 2000.
 */

/* Fichier de definition */
/* --------------------- */

#include <stdio.h>
#include <time.h>

#define _DATE
#include "date.hs"
#include "date.he"

void xdate(s)
char *s;
{

#ifdef prologue
	/*SG Correction de la date sous prologue*/
	struct tm *st;
	struct tm stt;
	
	unsigned char descripteur[9];
	prl_date((char far *)descripteur);

	
	stt.tm_mday = descripteur[3]; 
	stt.tm_mon = descripteur[2]-1;
	stt.tm_year = (descripteur[0] * 256 + (unsigned short int)(unsigned char)descripteur[1]) % 100;
	st=(struct tm *)&stt;
#else
	struct tm *st;
	time_t t;
	time(&t);
	st=localtime(&t);
#endif

/* #BG 05/01/00 */
sprintf(s,"%02d/%02d/%02d", st->tm_mday, st->tm_mon+1, st->tm_year % 100);

}


void xtime(s)
char *s;
{
	
#ifdef prologue
	struct tm *st;
	struct tm stt;
	
	signed char descripteur[9];
	prl_date((char far *)descripteur);
	stt.tm_hour = descripteur[6]; 
	stt.tm_min = descripteur[7];
	stt.tm_sec = descripteur[8];
	st=(struct tm *)&stt;
#else
	struct tm *st;
	time_t t;

	time(&t);
	st=localtime(&t);
#endif

sprintf(s,"%02d:%02d:%02d", st->tm_hour, st->tm_min, st->tm_sec);
}

/* ---------------------- Fin de fichier : date.c ------------------------- */

