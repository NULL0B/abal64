/*
 *	Bibliotheque Multi-Fenetrage
 *	----------------------------
 *
 *	Copyright (c) 2021 Amenesik / Sologic
 *
 *	wmem.c - fonctions de manipulation memoire
 *
 *	$Header: /home/Produits/Abal3/asfun/wmem.c,v 1.1.1.1 2003/11/04 23:40:50 root Exp $
 *
 */


#include "wtype.h"


/* wmemset - remplissage d'une  zone de caracteres
 * -----------------------------------------------
 *
 * appel:	void wmemset(zone, caractere, longueur);
 *		BYTE *zone     = zone a remplir
 *		BYTE caractere = caractere de remplissage
 *		WORD longueur  = longueur de la zone
 *
 * retour:	rien
 *
 */
void wmemset(zone, caractere, longueur)
BYTE *zone;
BYTE caractere;
WORD longueur;
{
	(void)memset((char *)zone, (int)caractere, (int)longueur);
}


/* wwmemset - remplissage d'une  zone de mots
 * ------------------------------------------
 *
 * appel:	void wwmemset(zone, mot, longueur);
 *		WORD *zone    = zone a remplir
 *		WORD mot      = mot de remplissage
 *		WORD longueur = longueur de la zone
 *
 * retour:	rien
 *
 */
void wwmemset(zone, mot, longueur)
WORD *zone;
WORD mot;
WORD longueur;
{
	while (longueur--)
		*zone++ = mot;
}


/* wmemcpy - recopie d'une zone de caracteres
 * ------------------------------------------
 *
 * appel:	void wmemcpy(destination, source, longueur);
 *		BYTE *destination = zone destination
 *		BYTE *source	  = zone source
 *		WORD longueur	  = longueur du transfert
 *
 * retour:	rien
 *
 */
void wmemcpy(destination, source, longueur)
BYTE *destination;
BYTE *source;
WORD longueur;
{
	(void)memcpy((char *)destination, (char *)source, (int)longueur);
}


/* wimemcpy - recopie en arriere d'une zone de caracteres
 * ------------------------------------------------------
 *
 * appel:	void wmemcpy(destination, source, longueur);
 *		BYTE *destination = zone destination
 *		BYTE *source	  = zone source
 *		WORD longueur	  = longueur du transfert
 *
 * retour:	rien
 *
 */
void wimemcpy(destination, source, longueur)
BYTE *destination;
BYTE *source;
WORD longueur;
{
	destination += longueur;
	source += longueur;
	while (longueur--)
		*--destination = *--source;
}

/* fin de fichier */
