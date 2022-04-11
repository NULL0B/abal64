/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXOVL.H   				*/
/*		Date 	:	18/02/1993				*/
/*		Version :	1.4c / 2.1a				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef	_EXOVL_H
#define	_EXOVL_H

#ifdef	ABAL21
#define	MAX_OVERLAYS	2048
#else
#define	MAX_OVERLAYS	256
#endif

#ifdef	EXDATASEG
#define	OVL_SCOPE	
#else	
#define	OVL_SCOPE EXTERN
#endif

OVL_SCOPE EXAWORD	Overlay_User;		   /* Current Overlay segment ID   */
OVL_SCOPE BPTR  Overlay_Code;		   /* Code of current overlay	   */
OVL_SCOPE BPTR  Overlay_Data;		   /* Data Table / current overlay */

#ifdef	ABAL21
OVL_SCOPE BPTR  Overlay_Const;		   /* Constants  / current overlay */
OVL_SCOPE EXAWORD	MaxOverlayConst;	   /* Size of Overlay Constants	   */
OVL_SCOPE EXAWORD	Overlay_Map[MAX_OVERLAYS]; /* Mapping of Segments in table */
#else
OVL_SCOPE EXABYTE	Overlay_Map[MAX_OVERLAYS]; /* Mapping of Segments in table */
#endif


#endif	/* _EXOVL_H */
	/* -------- */
