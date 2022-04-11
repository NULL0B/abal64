/***********************************************************************
* fichier:	WTYPE.H
* description:	Definition de types pour portage
*
* creation:	27.12.89 sb
* mise a jour:	27.12.89
*
*	Copyright Amenesik / Sologic s.a.
************************************************************************/
#ifndef	_wtype_h
#define	_wtype_h


#define	wmemset asfun_wmemset
#define	wwmemset asfun_wwmemset
#define	wmemcpy asfun_wmemcpy
#define	wwmemcpy asfun_wwmemcpy
#define tabmes asfun_tabmes


#ifdef BYTE
#undef BYTE
#endif /* BYTE */
#define BYTE unsigned char		/* octet non signe		*/

#ifdef WORD
#undef WORD
#endif /* WORD */

#ifdef	VERSION666
#define WORD unsigned short 		/* mot de 16 bits		*/
#define EXAWORD unsigned long  		/* mot de 32 bits		*/
#else
#define WORD unsigned short 		/* mot de 16 bits		*/
#define EXAWORD WORD
#endif

#ifndef _DWORD_DEFINED
#ifdef dWORD
#undef dWORD
#endif /* dWORD */
typedef unsigned long dWORD;		/* double mot de 16 bits	*/
#define _DWORD_DEFINED
#endif /* _DWORD_DEFINED */

#ifndef _BOOL_DEFINED
#ifdef bool
#undef bool
#endif /* bool */
#ifdef FALSE
#undef FALSE
#endif /* FALSE */
#ifdef TRUE
#undef TRUE
#endif /* TRUE */
#ifdef _NO_ENUM
#define FALSE	0
#define TRUE	1
typedef int bool;
#else
typedef enum {FALSE, TRUE} bool;	/* booleen			*/
#endif /* _NO_ENUM */
#define _BOOL_DEFINED
#endif /* _BOOL_DEFINED */

#ifndef _FAR_DEFINED
#ifndef FAR
#if MSDOS || PROL
#define FAR far
#else
#define FAR
#endif /* MSDOS || PROL */
#endif /* FAR */
#define _FAR_DEFINED
#endif /* _FAR_DEFINED */


#define void_ptr	void FAR *
#define FPTR		FAR *
/****
#define uint		WORD
#define uint_ptr	WORD FAR *
***/
#define WPTR		WORD FAR *
#define TYPF		extern short FAR
#define BPTR		BYTE FAR *
#define ld_desc_ptr	ld_desc FAR *
#define WDESC_APP_PTR	WDESC_APP FAR *
#define WDESC_APP_F	WDESC_APP FAR
#define BPTRPTR 	BPTR FAR *
#define ld_tab_ptr	ld_tab FAR *
#define bv_desc_ptr	bv_desc FAR *
#define md_desc_ptr	md_desc FAR *
#define mo_tab_ptr	mo_tab FAR *
#define mo_desc_ptr	mo_desc FAR *
#define WDESC_PTR	WDESC FAR *
#define LD_INFO_PTR	LD_INFO FAR *
#define STYL_DESC_PTR	STYL_DESC FAR *

#define fct_far_ptr		void FAR *
#define DATA_ELEM_PTR		DATA_ELEM FAR *
#define AIG_PTR			AIG_ FAR *
#define B_DIAL_PTR		B_DIAL FAR *
#define TB_STR_PTR		TB_STR FAR *
#define DESC_BOUTON_PTR         DESC_BOUTON FAR *
#define DESC_C_BOUTON_PTR       DESC_C_BOUTON FAR *
#define DESC_R_BOUTON_PTR       DESC_R_BOUTON FAR *
#define DESC_LISTE_PTR		DESC_LISTE FAR *
#define DESC_SAISIE_PTR		DESC_SAISIE FAR *
#define DESC_AIDE_PTR		DESC_AIDE FAR *
#define DESC_FUN_PTR		DESC_FUN FAR *
#define EQUIV_PTR		EQUIV FAR *


/* fin du source */

#endif	/* _wtype_h */
	/* -------- */

