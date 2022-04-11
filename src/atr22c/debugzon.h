/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : DEBUGZON.H
 *      Version : 2.1f
 *      Date    : 13/10/97
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Zone de debug pour JUNE]
 *
 * 
 */
#ifndef _DEBUGZON
#define _DEBUGZON

/* PUBLIC */
/* ------ */
#define MAX_STACK_ITEM_COUNT 40
#define ZoneStackPtr long*


/* PUBLIC VARIABLES */
/* ---------------- */

long	ZoneStack[MAX_STACK_ITEM_COUNT];
long			CurrentZoneCode;

/* PRIVATE VARIABLES */
/* ---------------- */

static long			stackItemCount;

/* PUBLIC FONCTIONS */
/* ---------------- */

long ZoneInitStack();
long ZonePushStack(long);
long ZonePopStack ();
long ZoneCodeLineNumber (long, long);
long ZoneDecodeLineNumber (long, long*);
long ZoneStackIsEmpty();

/* PUBLIC END */
/* ---------- */

/* FIN DEFINITIONS INTERNES */
/* ------------------------ */

#endif
