/*
 *      Projet  : ABAL                  Copyright Amenesik / Sologic s.a. (c) 1990, 1995
 *      Module  : ATR
 *      Fichier : CODES.H
 *      Version : 2.1f
 *      Date    : 22/11/95
 *      Systeme : DOS / PRL / UNIX / VMS
 *
 *      Traducteur ABAL
 *
 *      [Codage des operations T-code]
 *
 * --------------------------------------------------------------------------
 *      27/10/92 : Debut revision 1.5
 *              Insertion des nouveaux mots cles :
 *              ALIAS (fct), ANY (syn), AS (syn), ASKATB (ins), ASKCOLOR (ins)
 *              CREATE (ins), FORGET (ins), FORWARD (syn), IN (syn), INITGLOBAL (mac)
 *              INITLOCAL (mac), LANG (fct), LIKE (syn), NAME (ins), PARSE (fct)
 *              POWER (fct), CODE (syn), PTR (syn), REAL (fct), REMOVE (ins)
 *              STDFORM (fct)
 *	06/09/93 : F_LERG er F_LERGR pas encore de CODE !!!!
 *
 * -------------------------------------------------------------------------
 *  29/02/00 : (#AT) Amelioration EXA-57 - LOAD.GO modifications for ABAL v.2.2a
 * -------------------------------------------------------------------------
 */
#ifndef _CODES_H
#define _CODES_H

#define F_LDR           0x01            /* Chargement de registre  */

#define F_SGN           0x50            /* Demande de non-signe pour diese */

#define F_STO           0x14            /* Stockage de registre    */
#define F_RTR           0x75            /* Stockage registre -> registre */
#define F_RTC           0x70            /* Stockage constante -> registre */
#define F_RTV           0x77            /* Stockage variable -> registre */

#define F_LIX           0x03            /* Chargement de 1er index */

#define F_AIX           0x04            /* Chargement de 2eme index */

#define F_RAZ           0x05            /* Control machine fictive */
#define F_PSH           0x25
#define F_POP           0x45
#define F_LDF           0x65
#ifdef ver15
#define F_EDF           0x70            /* Appel proc/var  A.B.A.L */
#endif /* ver15 */
#define F_RET           0x06            /* Retour apres GOSUB      */

#define F_GSB           0x07            /* Appel type GOSUB        */

#define F_TIM           0x20            /* Fonctions "TIMER"       */
#define F_WHN           0x76            /* Fonctions "WHEN"        */

#define F_JMP           0x12            /* Branchement inconditionnel */

#define F_JEQ           0x18            /* branchement si egal              */
#define F_JNE           0x19            /* .............. different         */
#define F_JGE           0x1A            /* .............. superieur ou egal */
#define F_JLE           0x1B            /* .............. inferieur ou egal */
#define F_JGR           0x1C            /* .............. superieur         */
#define F_JLS           0x1D            /* .............. inferieur         */
#define F_JIN           0x1E            /* .............. inclus            */
#define F_JNI           0x1F            /* .............. non-inclus        */

#define F_ADD           0x08            /* Addition d'operandes    */
#define F_SUB           0x09            /* Soustraction d'operands */
#define F_MUL           0x0A            /* Multiplication operands */
#define F_DIV           0x0B            /* Division d'operands     */

#define F_MOD           0x0C            /* Modulo (Reste) operands */
#define F_AND           0x0D            /* ET Logique d'operands   */
#define F_OR            0x0E            /* OU Logique d'operands   */
#define F_OX            0x0F            /* OU Exclusif            */

#define F_INC           0x11            /* Increment Registre      */
#define F_DEC           0x31            /* Decrement Registre      */
#define F_INX           0x51            /* Increment Reg d'index   */
#define F_DEX           0x71            /* Decrement Reg d'index   */
#define F_ANX           0x02            /* Increment Reg d'index   */
#define F_DAX           0x22            /* Decrement Reg d'index   */
#define F_NGR           0x62            /* Negation d'un variable  */
#define F_NGV           0x72            /* Negation d'un registre  */

#define F_CLF           0x15            /* Appel fonction standard */
#define F_NGF           0x35            /* Appel systeme de fichiers */

#define F_TPC           0x36            /* Instruction OP du B.A.L. */
#define F_TPCR          0x57            /* idem sur registre        */
					/* pas utilise */

#define F_CNV           0x37            /* Fonction CONV du B.A.L. */

#define F_ERG           0x40            /* ON ERROR GOTO           */
#define F_ERGR          0x1F            /* registre (recouvre JNI int) */

#define F_LERG           0x57            /* ON ERROR GOTO           */
#define F_LERGR          0x00            /* registre (recouvre JNI int) */

#define F_ERA           0x42            /* ON ERROR ABORT          */
#define F_RES           0x60            /* RESUME                  */

#define F_IOF           0x55            /* debut de PRINT ou de ASK */

#define F_DTR           0x27            /* READ=0: ... */
#define F_DTRR          0x1E            /* registre (recouvre JEI int) */

#define F_NOP           0x56            /* No operation ...         */

#define F_VPT           0x47            /* registre <- adr variable */

#define F_OLE           0x10            /* ON LOCAL ERROR 	*/
#define F_LEP           0x30            /* LOCAL ERROR POP 	*/

/*      Operations en "echappement", qui necessitent 2 octets           */
/*      -----------------------------------------------------           */

#define F_ESC           0x00            /* Escape sequence header  */

#define F_PSE           0x13            /* Pause B.A.L.            */
#define F_SGT           0x10            /* Appel Segment LOADSEG   */
#define F_CLP           0x17            /* Appel procedure A.B.A.L */
#define F_CLV           0x37            /* Appel variable  A.B.A.L */
#define F_RTS           0x26            /* Return Segment          */
#define F_EDS           0x27            /* End Segment             */
#define F_EDP           0x47            /* End Proc : a renseigner */
#define F_RTE		0x28		/* Remontee ERROR 	   */
#define F_RTP           0x46            /* Return Procedure        */
#define F_STP           0x66            /* Fin Programme BAL       */
#define F_JMR           0x32            /* JMP sur registre        */
#define F_GSR           0x52            /* GSB sur registre        */

#define F_SGW           0x70            /* Appel Segment LOADSEG avec num WORD  */

/*      Operations d'acces direct aux emplacements memoires             */
/*      ---------------------------------------------------             */

#define F_VPTG          0x10    /* chargement pointeur sur variable globale */
#define F_VPTL          0x30    /* chargement pointeur sur variable locale */

#define F_STGI          0x13    /* rangement % en memoire globale */
#define F_STLI          0x33    /* rangement % en memoire locale */

#define F_LDGI          0x53    /* chargement % en memoire globale */
#define F_LDLI          0x73    /* chargement % en memoire locale */

#define F_STGC          0x46    /* rangement # en memoire globale */
#define F_STLC          0x66    /* rangement # en memoire locale */

#define F_LDGC          0x26    /* chargement # en memoire globale */
#define F_LDLC          0x17    /* chargement # en memoire locale */

/* #AT: 29/02/00, EXA-57 (begin)*/
#ifdef __ATR22__
/* New instructions for control of value return (LOAD.GO / ESEG)*/
#define F_ILGR          0x80    /* INIT LOADGO RESULT (ESC+code)*/
#define F_SLGR          0x81    /* SAVE LOADGO RESULT (ESC+code)*/
#define F_LLGRG         0x82    /* LOAD LOADGO RESULT TO A GLOBAL VAR (ESC+code)*/
#define F_LLGRL         0x83    /* LOAD LOADGO RESULT TO A LOCAL VAR  (ESC+code)*/
#endif
/* #AT: 29/02/00, EXA-57 (end)*/

/*      Codage d'une instruction PRINT ou ASK   */
/*      -------------------------------------   */

#define io_jmp          (BYTE) 0x01
#define io_ctab         (BYTE) 0x02
#define io_atb          (BYTE) 0x03
#define io_prn          (BYTE) 0x04
#define io_iprn         (BYTE) 0x84
#define io_vtab         (BYTE) 0x05
#define io_fmt          (BYTE) 0x06
#define io_dev          (BYTE) 0x07
#define io_bak          (BYTE) 0x08
#define io_clr          (BYTE) 0x09
#define io_home         (BYTE) 0x29
#define io_bell         (BYTE) 0x49
#define io_for          (BYTE) 0x0A
#define io_ltab         (BYTE) 0x0B
#define io_ask          (BYTE) 0x0C
#define io_rbrc         (BYTE) 0x0D
#define io_brc          (BYTE) 0x0E
#define io_gsb          (BYTE) 0x0F
#define io_fin          (BYTE) 0x00

/*      Codage des formats de saisie et d'edition       */
/*      -----------------------------------------       */

                                /*      Format code string control      */
#define FMT_SEP (BYTE) 0x0000           /* , */
#define FMT_DEB (BYTE) 0x00FE           /* debut de format ABAL */
#define FMT_FIN (BYTE) 0x00FF           /* fin de format ABAL */
                                /*      Character type control masks    */
#define FMT_D   (BYTE) 0x0001           /* D */
#define FMT_A   (BYTE) 0x0081           /* A */
#define FMT_N   (BYTE) 0x0002           /* N */
#define FMT_Z   (BYTE) 0x0082           /* Z */
#define FMT_C   (BYTE) 0x0003           /* C */
#define FMT_B   (BYTE) 0x0083           /* B */
#define FMT_W   (BYTE) 0x000F           /* W */
#define FMT_U   (BYTE) 0x008F           /* U */
#define FMT_O   (BYTE) 0x0092           /* O */
#define FMT_H   (BYTE) 0x0057           /* H */
#define FMT_I   (BYTE) 0x0055           /* I */
#define FMT_V   (BYTE) 0x0008           /* V */
#define FMT_P   (BYTE) 0x0088           /* . */
                                /*      Format Action codes             */
#define FMT_PR  (BYTE) 0x0020           /* " */
#define FMT_LF  (BYTE) 0x0021           /* / */
#define FMT_TAB (BYTE) 0x0022           /* T */
#define FMT_ESP (BYTE) 0x0023           /* X */
#define FMT_ATB (BYTE) 0x0024           /* \\ */
                                /*      Format Environment codes        */
#define FMT_ZER (BYTE) 0x0040           /* * */
#define FMT_ZCH (BYTE) 0x0049           /* *(x) */
#define FMT_JL  (BYTE) 0x0041           /* L */
#define FMT_JR  (BYTE) 0x0042           /* R */
#define FMT_JJ  (BYTE) 0x0043           /* J */
#define FMT_POS (BYTE) 0x0046           /* + */
#define FMT_NEG (BYTE) 0x0045           /* - */
#define FMT_MIL (BYTE) 0x0047           /* S */
#define FMT_MCH (BYTE) 0x0048           /* S(x) */
#define FMT_STR (BYTE) 0x0050           /* E */
#define FMT_CUT (BYTE) 0x0051           /* F */
#define FMT_DOL (BYTE) 0x0052           /* $ */
#define FMT_DCH (BYTE) 0x0053           /* $(x) */
#define FMT_DYN (BYTE) 0x0054           /* ? */
#define FMT_PCH (BYTE) 0x0058           /* .(x) */

#endif /* _CODES_H */

