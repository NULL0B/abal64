/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : Tous
 *	Fichier : ALBOX.C
 *	Version : 1.1a
 *	Date    : 07/01/93
 *	Systeme : Windows 3/NT
 *
 *	Module de base - Affiche une boite d'alerte
 *
 *	[Code]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	03/12/92 : Debut du codage
 *
 */

#include "aldtype.h"

#if 0
Note : excluded by JPH

	#define __PORTABLE__		/* source pour Windows */

	/* Inclusions importees */

	#include "wabaldef.h"
	#ifdef __WINDOW_SOURCE__
	#include "pubwbapp.h"
	#endif

	/* Inclusions exportees et privees */

	#define PRIMITIVE GLOBAL
#endif

#include "pubalbox.h"


/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*			AFFICHAGE DES ALERTES				     */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

/* --------------------------------------------------------------------------
 *
 * FCT AlertBox
 *
 *	Affiche une boite de validation avec une alerte.
 *
 *	E/ pointeur sur le message de l'alerte
 *	S/ rien
 *
 */
void AlertBox( BYTE FAR * message )
{
	printf("\r\n	ALERT : ");
	printf("\r\n    %s",message );     
}

