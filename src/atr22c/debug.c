/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1993, 1999
 *      Module  : ATR
 *      Fichier : DEBUG.C
 *      Version : 2.1f
 *      Date    : 26/02/1999
 *      Systeme : DOS/ PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Communication avec serveur pour debug APLUS]
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
#include <stdio.h>
#include "tr.h"

/*#define _DEBUG_FILE*/

#define _DEBUG2
#include "debug.hs"
#include "debug.he"

BINAIRE connect(nomfic)
char *nomfic;
{
#ifdef _DEBUG_FILE
	aplus_file=fopen(nomfic,"w");
#endif
	return(0);
}


BINAIRE send(lginfo)
ApsOf *lginfo;
{
#ifdef _DEBUG_FILE
	fprintf(aplus_file,"%s ",lginfo->fichier);
	fprintf(aplus_file,"%d ",lginfo->noligne);
	fprintf(aplus_file,"%c ",lginfo->type);
	fprintf(aplus_file,"%s ",lginfo->ident);
	fprintf(aplus_file,"%04X ",lginfo->offset);
	fprintf(aplus_file,"\n");
#endif
	return(0);
}


BINAIRE commit()
{
#ifdef _DEBUG_FILE
	fclose(aplus_file);
#endif
	return(0);
}


BINAIRE release()
{
#ifdef _DEBUG_FILE
	fclose(aplus_file);
#endif
	return(0);
}

/* -------------------------- Fin du fichier : debug.c ---------------*/

