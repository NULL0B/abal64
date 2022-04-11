
/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1993
 *      Module  : ATR
 *      Fichier : ATRDEBUG.C
 *      Version : 2.1a
 *      Date    : 23/03/93
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Debug interne du traducteur]
 *
 * 
 */

 /*
 * Mises a jour :
 * ------------
 */
// YT : The next line has been removed because it redefines WORD (unsigned int / unsigned short)
// #define WORD unsigned int

#include "aldtype.h"

#include "lkfile.h"

void dbgoption(WORD);

/* Fichier de definition */
/* --------------------- */

#define _ATRDEBUG
#include "lkdebug.h"
#include "lkdebugs.h"
#include <malloc.h>
#include "display.h"

void dbginit(nom)
char *nom;
{
	atr_debug = 0;		/* Pas de debug par defaut */

/* Initialisation debug memoire */
	lstmem= (DbgMem *) 0;
	dbgnballoc=0;
	dbgmem=0;
	dbgmemno=0;

	atr_file_dbg = fopen(TranslateLongPathName(nom),"w");
	fprintf(atr_file_dbg,"\nFichier de DEBUG - ATR 2.1");
	fprintf(atr_file_dbg,"\n--------------------------\n");
}

void dbgfin()
{
	fprintf(atr_file_dbg,"\n-------- Fin de fichier de DEBUG - ATR 2.1 -------\n");
	fclose(atr_file_dbg);
}

/* void dbgoption(WORD); */

void dbgoption(opt)
WORD opt;
{
	atr_debug |= opt;
}

char *dbgalloc(nom,na)
char *nom;
long na;
{
char *pt;
DbgMem *ptm;
int nb;

	nb = (int) na;
	pt = malloc(nb);

	dbgmemno +=1;
	dbgmem += nb;
	dbgnballoc +=1;
	dbgprintf(AMEM)(atr_file_dbg,"\n%08lX=ALLOC(%04d):%08ld\n",pt,nb,dbgmemno);

	if ( (ptm=(DbgMem *) malloc(sizeof(DbgMem))) == (DbgMem *) 0 ) {
		dbgprintf(AMEM)(atr_file_dbg,"\nStop error mem...\n");
		dbgfin();		
		exit(1);
	}

	strcpy(ptm->nom,nom);
	ptm->no = dbgmemno;
	ptm->nb = (long) nb;
	ptm->pt = pt;

	ptm->suiv = lstmem;
	lstmem = ptm;
	return(pt);
}

void dbgfree(pt)
char *pt;
{
DbgMem *ptm;
DbgMem *ptm2;
int trouve=0;

	ptm2 = (DbgMem *) 0;
	ptm = lstmem;
	
	while ( ptm != (DbgMem *) 0 ) {
		if ( ptm->pt == pt ) {
			trouve=1; break;
		}
		ptm2 = ptm;
		ptm = ptm->suiv;		
	}
	if ( trouve ) {
		if ( ptm2 != (DbgMem *) 0 )
			ptm2->suiv = ptm->suiv;
		else
			lstmem = ptm->suiv;
		dbgprintf(AMEM)(atr_file_dbg,"\nLiberation(%s,%ld,%ld,%08lX)",ptm->nom,ptm->no,ptm->nb,ptm->pt);
		dbgmem -= ptm->nb;
		free ((char *) ptm);
		dbgprintf(AMEM)(atr_file_dbg,":%08ld\n",dbgnballoc);
		dbgnballoc -=1;
		free(pt);
	} else {
		dbgprintf(AMEM)(atr_file_dbg,"INVALIDE FREE(%08lX)\n",pt);
	}
}

void dbgstat()
{
DbgMem *ptm;
DbgMem *ptm2;
unsigned char c;
int i,j;

	dbgprintf(AMEM)(atr_file_dbg,"\nMEMOIRE ALLOUEE:%ld",dbgmem);
	dbgprintf(AMEM)(atr_file_dbg,"\nNOMBRE D'ALLOCATION:%ld",dbgnballoc);
	dbgprintf(AMEM)(atr_file_dbg,"\n");
#ifdef	WIN32
	if (atr_debug & AMEM) 
		{
		sprintf(waBuffer,"MEMOIRE ALLOUEE:%ld",dbgmem);
		waDisplayMessage(waBuffer);
		sprintf(waBuffer,"NOMBRE D'ALLOCATION:%ld",dbgnballoc);
		waDisplayMessage(waBuffer);
		waDisplayMessage("");
		}
#endif
	if ( lstmem != (DbgMem *) 0 ) {
		ptm = lstmem;
		while ( ptm != (DbgMem *) 0 ) {

			dbgprintf(AMEM)(atr_file_dbg,"\nNon Libere(%s,%ld,%ld,%08lX)\n",ptm->nom,ptm->no,ptm->nb,ptm->pt);
			for ( i=0; i<ptm->nb; i +=16 ) {
				for ( j=i; j<i+16; j++ ) {
					c = *(ptm->pt+j);
					dbgprintf(AMEM)(atr_file_dbg,"%02X ",c);
				}
				dbgprintf(AMEM)(atr_file_dbg,"  ");
				for ( j=i; j<i+16; j++ ) {
					c = *(ptm->pt+j);
					if ( c < 0x20 ) {
						dbgprintf(AMEM)(atr_file_dbg,".");
					} else {
						dbgprintf(AMEM)(atr_file_dbg,"%c ",c);
					}
				}
				dbgprintf(AMEM)(atr_file_dbg,"\n");
			}			
			ptm2 = ptm;
			ptm = ptm->suiv;		
			free((char *) ptm2);
		}
	}
}

/* -------------------------- Fin du fichier : atrdebug.c ---------------*/




