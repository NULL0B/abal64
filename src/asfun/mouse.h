
/****************************************************************
* Services Fenetres                 				*
*---------------------------------------------------------------*
* Source : sfmouse.h                   				*
*---------------------------------------------------------------*
* Version : 1.1b                    				*
* Mise a jour le : 29/04/92  EDS (CERVIX)			*				*
*								*
*****************************************************************
* 				                        	*
* INCLUDES SPECIFIQUES MOUSE                             	*
*								*
****************************************************************/




/* les evenements mouse */

#define	MOUSE_LEFT		1
#define	MOUSE_RIGHT		2
#define	MOUSE_MIDDLE		4

#define NO_EVENT		0
#define	TASK_INTERRUPT		1
#define KEYBOARD		2

#define MOUSE_DOWN		0x0010
#define MOUSE_UP		0x0020
#define MOUSE_CLICK		0x0040
#define MOUSE_D_CLICK		0x0080
#define MOUSE_MOVE		0x0100
#define MOUSE_M_W_DOWN		0x0200
#define MOUSE_IS_DOWN		0x0400
#define	MOUSE_SEND_LEFT		0x1000
#define	MOUSE_SEND_RIGHT	0x2000
#define	MOUSE_SEND_MIDDLE	0x4000



/* Sens de variation de la mouse */

#define M_LEFT			0
#define M_RIGHT			2
#define M_UP			4
#define M_DOWN			8



/* structure des evenements */

typedef struct {
		WORD event;	/* l'evenement capte				*/
		WORD arg;	/* argument de l'event (caractere, bouton)	*/
		WORD plig;
		WORD pcol;	/* position ligne et colonne event (mouse)      */

	       } EVENT_STR;


#define EVENT_PTR EVENT_STR FAR *

