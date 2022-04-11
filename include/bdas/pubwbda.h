/*
 *  Projet  : ABAL      Copyright Prologue s.a. (c) 1992, 2000
 *  Module  : biblioth�que dynamique pour WEXA
 *  Fichier : PUBWBDA.H
 *  Version : 2.00
 *  Date    : 20/04/2000
 *  Systeme : Windows 3/95/98/NT/2000
 *
 *  Bibliotheques dynamiques ABAL
 *
 *  [Interface avec les bibliotheques dynamiques - Definitions publiques]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *  20/04/2000 : mise � jour v2.00
 */

#ifndef __PUBWBDA_H__
#define __PUBWBDA_H__

#ifdef __cplusplus
  extern "C" {
#endif

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
/*      DESCRIPTION DES DONNEES            */
/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

BDA_EXTERN BDA_ARG        rt_arg;           // struct qualifiant les param�tres d'une API ABAL, remplie par __rt_arg
BDA_EXTERN LPBDA_INIT     rt_init;          // pointeur sur v_rt_init
BDA_EXTERN BDA_INIT       v_rt_init;        // struct d�crivant la BDA (type, signature,...)
BDA_EXTERN LPBDA          Int_Descripteur;  // pointeur sur struct d�crivant les API ABAL
BDA_EXTERN WORD           noerr;            // n� erreur positionn�e par rt_error, lisible par appli par __rt_error
#if defined(BDA_WIN16) || defined(BDA_WIN32)
BDA_EXTERN HINSTANCE      dll_handle;       // handle de la DLL, fourni en entr�e de __InitRelais
#endif

// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//      Description Des fonctions fournies dans Wbdacli
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

void rt_error(EXAWORD);


#ifdef __cplusplus
  }
#endif

#endif /* __PUBWBDA_H__ */
