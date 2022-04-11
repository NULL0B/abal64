/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *	Module  : ATR
 *	Fichier : EXPR.C
 *	Version : 2.2b
 *	Date    : 21/11/95
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Traitement des expressions]
 *
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1996
 *      Module  : ATR
 *      Fichier : LEXICAL.HS
 *      Version : 2.2b
 *      Date    : 15/01/96
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Definitions de l'analyseur lexical]
 *
 * --------------------------------------------------------------------------
 * 27/10/92 : Debut revision 1.5
 *           Insertion des nouveaux mots cles :
 *           ALIAS (fct), ANY (syn), AS (syn), ASKATB (ins), ASKCOLOR (ins)
 *           CREATE (ins), FORGET (ins), FORWARD (syn), IN (syn), INITGLOBAL (mac)
 *           INITLOCAL (mac), LANG (fct), LIKE (syn), NAME (ins), PARSE (fct)
 *           POWER (fct), CODE (syn), PTR (syn), REAL (fct), REMOVE (ins)
 *           STDFORM (fct)
 *
 * 06/09/93 : LOCAL pour ON LOCAL ERROR
 * 15/10/93 : "BACKSPAC" -----> "BACKSPACE" ( 16 caracteres max maintenant !!!)
 *	17/02/97 : Debut revision 2.2
 *									Nouveaux mots cles : ENDSTRUCT, STRUCT
 *	01/04/97 : Nouveaux mots cles : ENDWITH, WITH
 *	22/03/98 : Paramètre ! dans la définition des BDA, liste des motes clés plus claire
 * -------------------------------------------------------------------------
 *	22/11/99 : (#AT:) Enhancement ATR: BINARY function.
 *	------------ 2.2b -------------------------------------------------
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "tsymb.h"
#include "syntaxe.h"
#include "tcode.h"
#include "codes.h"

#define SUIVI_REG
#define _EXPR
#include "expr.he"
#include "expr.hs"

#include "abal.h"	/* #IJM 06/11/02 */

#include "expr1.c"
#include "expr2.c"


