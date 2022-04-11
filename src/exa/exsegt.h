/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSEGT - H				*/
/*		Version	:	1.4a / 2.1a				*/
/*		Date 	:	18/02/1993				*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef _EXSEGT_H
#define _EXSEGT_H

/*
 *	Declaration du structure de La Table des Segments
 *	-------------------------------------------------
 */

struct segmform {
	EXAWORD	 segm_ID;	/* Numero du segment 	*/
	EXAWORD	 segm_AC;	/* Adresse disque code 	*/
	EXAWORD	 segm_LC;	/* Longeur du Code	*/
	EXAWORD	 segm_AD;	/* Adresse disque data  */
	EXAWORD	 segm_LD;	/* Longeur du Data	*/
	EXAWORD	 segm_OP;	/* Option Value     	*/
#ifdef	ABAL21
	EXAWORD	 segm_AK;	/* Adresse Local Const	*/
	EXAWORD	 segm_LK;	/* Length  Local Const  */
	BPTR	 segm_KS;	/* Constants Pointer	*/
#endif
	BPTR 	 segm_CS;	/* CS Value 		*/
	BPTR	 segm_DT;	/* Local Data Table     */
	BPTR	 segm_DS;	/* Local Data Memory    */
	};

/*
 *	LDGO.SEG / RET.SEG Segment context structure
 *	--------------------------------------------
 */

struct	context {
	EXAWORD	 seg_ID;		/* Segment ID code	*/
	EXAWORD	 seg_IP;		/* Segment tcode index  */
	BPTR	 seg_CS;		/* Current Segment Base */
#ifdef	ABAL21
	BPTR	 seg_KS;		/* Current Constants	*/
#endif
	struct errform PTR seg_EP;	/* Error structure	*/
	EXAWORD	 seg_SP;		/* Istack index 	*/
	EXAWORD	 seg_SH;		/* Gosub Stack Protect	*/
	EXAWORD	 seg_SM;		/* Segment Semaphores	*/
	BPTR	 seg_DS;		/* Local Data segment	*/
	EXAWORD	 seg_EVS;		/* Current Event Semaph */
	EXAWORD	 seg_EVA;		/* Current Event Adresse*/
#ifdef	ABAL21
	EXAWORD	 seg_EVH;		/* Current Event Adresse*/
#endif
	};

	/* --------- */
#endif	/* _EXSEGT_H */
	/* --------- */

