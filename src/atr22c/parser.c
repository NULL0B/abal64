/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *	Module  : ATR
 *	Fichier : PARSER.C
 *	Version : 2.1f
 *	Date    : 21/11/95
 *	Systeme : DOS / PRL / UNIX / VMS
 *
 *	Traducteur ABAL
 *
 *	[Analyseur syntaxique]
 *	
 */

 /*
 * Mises a jour :
 * ------------
 *	18/07/90 : Mise en conformite avec les versions 1.2e / 1.3a / 1.4a
 *	03/04/91 : Correction utilisation des registres sur SELECT expression
 *	------------ 2.1d -------------------------------------------------
 *	21/11/95 : version dediee 2.1
 */

/* Fichier de definition */
/* --------------------- */
#include "tr.h"
#include "fuser.h"
#include "syntaxe.h"
#include "tsymb.h"
#include "tcode.h"
#include "codes.h"

#define SUIVI_REG
#define _PARSER
#include "parser.he"
#include "parser.hs"

#include "parse1.c"
#include "parse2.c"


