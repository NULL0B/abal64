/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1993, 1995
 *      Module  : ATR
 *      Fichier : ATRDEBUG.C
 *      Version : 2.1f
 *      Date    : 22/11/95
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
 *	22/11/95 : version dediee 2.1
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "tcode.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"

#define _ATRDEBUG
#include "atrdebug.hs"
#include "atrdebug.he"

void dbginit(nom)
char *nom;
{
	atr_debug = 0;		/* Pas de debug par defaut */

	/* Initialisation debug memoire */
	lstmem= (DbgMem *) 0;
	dbgnballoc=0;
	dbgmem=0;
	dbgmemno=0;

	atr_file_dbg = fopen(nom,"w");
	fprintf(atr_file_dbg,"\nFichier de DEBUG - ATR 2.2");
	fprintf(atr_file_dbg,"\n--------------------------\n");
}


void dbgfin(nom)
char *nom;
{
	fprintf(atr_file_dbg,"\n-------- Fin de fichier de DEBUG - ATR 2.2 -------\n");
	fclose(atr_file_dbg);
	if ( ! ( atr_debug & AFIC) )
		Xunlink(nom);
}


void dbgoption(opt)
BINAIRE opt;
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

	if ( (atr_debug & AMEM) || (atr_debug & AFIC) ) {

		dbgprintf(AFIC)(atr_file_dbg,"\n%08lX=ALLOC(%04d):%08ld\n",pt,nb,dbgmemno);

		if ( (ptm=(DbgMem *) malloc(sizeof(DbgMem))) == (DbgMem *) 0 ) {
			dbgprintf(AFIC)(atr_file_dbg,"\nStop error mem...\n");
			printf("Debug:[Out of memory]\n");
			dbgstat();
			dbgfin("atrdebug.txt");		
			exit(1);
		}

		strcpy(ptm->nom,nom);
		ptm->no = dbgmemno;
		ptm->nb = (long) nb;
		ptm->pt = pt;

		ptm->suiv = lstmem;
		lstmem = ptm;
	}

	return(pt);
}


void dbgfree(pt)
char *pt;
{
DbgMem *ptm;
DbgMem *ptm2;
int trouve=0;

	if ( (atr_debug & AMEM) || (atr_debug & AFIC) ) {

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
			dbgprintf(AFIC)(atr_file_dbg,"\nLiberation(%s,%ld,%ld,%08lX)",ptm->nom,ptm->no,ptm->nb,ptm->pt);
			dbgmem -= ptm->nb;
			free ((char *) ptm);
			dbgprintf(AFIC)(atr_file_dbg,":%08ld\n",dbgnballoc);
			dbgnballoc -=1;
			free(pt);
		} else {
			dbgprintf(AFIC)(atr_file_dbg,"INVALIDE FREE(%08lX)\n",pt);
			printf("INVALIDE FREE(%08lX)\n",pt);
		}
	} else {
		dbgnballoc -=1;
		free(pt);
	}
}


void dbgstat()
{
DbgMem *ptm;
DbgMem *ptm2;
unsigned char c;
int i,j;

	dbgprintf(AFIC)(atr_file_dbg,"\nMEMOIRE ALLOUEE:%ld",dbgmem);
	dbgprintf(AFIC)(atr_file_dbg,"\nNOMBRE D'ALLOCATION:%ld",dbgnballoc);
	dbgprintf(AFIC)(atr_file_dbg,"\n");

	if ( (atr_debug & AMEM) || (atr_debug & AFIC) ) {
		if ( lstmem != (DbgMem *) 0 ) {
			ptm = lstmem;
			while ( ptm != (DbgMem *) 0 ) {

				dbgprintf(AFIC)(atr_file_dbg,"\nNon Libere(%s,%ld,%ld,%08lX)\n",ptm->nom,ptm->no,ptm->nb,ptm->pt);

				for ( i=0; i<ptm->nb; i +=16 ) {
					for ( j=i; j<i+16; j++ ) {
						c = *(ptm->pt+j);
						dbgprintf(AFIC)(atr_file_dbg,"%02X ",c);
					}
					dbgprintf(AFIC)(atr_file_dbg,"  ");
					for ( j=i; j<i+16; j++ ) {
						c = *(ptm->pt+j);
						if ( c < 0x20 ) {
							dbgprintf(AFIC)(atr_file_dbg,".");
						} else {
							dbgprintf(AFIC)(atr_file_dbg,"%c ",c);
						}
					}
					dbgprintf(AFIC)(atr_file_dbg,"\n");
				}				
				ptm2 = ptm;
				ptm = ptm->suiv;		
				free((char *) ptm2);
			}
		}
	}
	if ((atr_debug & AMEM) || (atr_debug & AFIC)) {	
		if (dbgmem) printf("\nMEMOIRE ALLOUEE:%ld",dbgmem);
		if (dbgnballoc) printf("\nNOMBRE D'ALLOCATION:%ld\n",dbgnballoc);
	}
}


void dbgprint(opt,mess)
BINAIRE opt;
char *mess;
{
	if ( opt & atr_debug ) {
		printf("%s",mess);
	}	
}

/* -------------------------- Fin du fichier : atrdebug.c ---------------*/

