/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXDBKEYS - H				*/
/*		Date 	:	25/11/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef EXDBKEYSH
#define EXDBKEYSH

/*	Debug Command Function Key Values				*/
/*	---------------------------------				*/

#define	DB_ABORT	0x0001		/* Ctrl A : Effacement ligne	*/
#define	DB_TRAPA	0x0001		/* Ctrl A : Trap permanant	*/
#define	DB_TRAPB	0x0002		/* Ctrl B : Trap temporary	*/
#define	DB_PAGEDWN	0x0003		/* Ctrl C : Consult Page Down 	*/
#define	DB_WDWCUT	0x0004		/* Ctrl D : Window decrease	*/
#define	DB_LINEDWN	0x0005		/* Ctrl E : Consult line down	*/
#define DB_FIND		0x0006		/* Ctrl F : Find Text (wild)	*/
#define	DB_WDWGROW	0x0007		/* Ctrl G : Window Grow		*/
#define	DB_HELP		0x0008		/* Ctrl H : Control Help	*/
#define DB_TAB		0x0009		/* Ctrl I : Definir Liste Tab	*/
#define	DB_INFOS	0x000A		/* Ctrl J : Verbose replies	*/
#define	DB_LINEUP	0x000B		/* Ctrl K : Consult line Up	*/
#define	DB_HOME		0x000C		/* Ctrl L : Definir Libelle   	*/
#define	DB_RETURN	0x000D		/* Ctrl M : Return to Exec Page	*/
#define	DB_PARAM	0x000E		/* Ctrl N : Modification Params */
					/* Ctrl O */
#define	DB_POINT	0x0010		/* Ctrl P : Positioner Liste	*/
					/* Ctrl Q */
#define	DB_PAGEUP	0x0012		/* Ctrl R : Consult Page Up	*/
					/* Ctrl S */
#define DB_HEADER	0x0014		/* Ctrl T : Debut Segment/Proc  */
#define DB_EXEC		0x0015		/* Ctrl U : Execute via Point	*/
#define	DB_VIEW		0x0016		/* Ctrl V : Redraw View Page	*/
#define	DB_WDWSWAP	0x0017		/* Ctrl W : Change View Window	*/
#define	DB_RUN		0x0018		/* Ctrl X : Execution Continue	*/
#define	DB_WIPE		0x0019		/* Ctrl Y : Supression Libelle  */
#define	DB_ZOOM		0x001A		/* Ctrl Z : Zoom display ligne	*/
#define	DB_EXITKEY	0x001B		/* Escape : Exit Request	*/
#define	DB_STEP		0x0020		/*  ' '   : Execute Step	*/

#endif	/* ! EXDBKEYSH */
	/* ----------- */
