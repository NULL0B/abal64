/*
 *
 *		E X E C U T E U R 	A . B . A . L
 *		-------------------------------------
 *
 *		Copyright (c) 1987,2002 Amenesik / Sologic  .
 *
 *		Module  :	EXTCODE.H
 *		Version :	2.2b
 *		Date 	:	16/12/2002
 */
 
/*
 * Mises a jour :
 * ------------
 *	------------ 2.2b -------------------------------------------------
 */


#ifndef	EXTCODEH	/* If not already included			*/
#define	EXTCODEH	/* Avoid multiple inclusions			*/

#define		_tc_GIS		0x13		/* Reg(imm) >> Global %    */
#define		_tc_LIS		0x33		/* Reg(imm) >> Local  %    */
#define		_tc_GIL		0x53		/* Global % >> Register	   */
#define		_tc_LIL		0x73		/* Local  % >> Register    */
#define		_tc_GVP		0x10		/* Load pointer global 	   */
#define		_tc_LVP		0x30		/* Load pointer local      */
#define		_tc_SGN 	0x50		/* Set Unsigned flag	   */

#define		_tc_LDI		0x01		/* Chargement de registre  */
#define		_tc_LDC		0x21		/* Chargement de registre  */
#define		_tc_LDV		0x41		/* Chargement de registre  */
#define		_tc_LDR		0x61		/* Chargement de registre  */

#define		_tc_DTV		0x27		/* Read=0,Variable V ABAL  */
#define		_tc_DTR		0x1E		/* Read=0,Register V ABAL  */

#define		_tc_CNV		0x37		/* Function CONV( )	   */
#define		_tc_VPT		0x47		/* Load Variable pointer   */

#define		_tc_STI		0x14		/* Store Immediate => Var  */
#define		_tc_STC		0x34		/* Store Constant => Var   */
#define		_tc_STV		0x54		/* Store Variable => Var   */
#define		_tc_STR		0x74		/* Stockage de registre    */
 
#define		_tc_GWS		0x75		/* Local  Word Store	   */
						/* ----------------------- */
						/*    ***************	   */
#define		_tc_RTR		0x75		/*    ** Attention **	   */
						/*    ***************      */
						/* Store Reg to Reg with   */
						/* interpretation of both  */
						/* registers and auto CONV */
						/* ----------------------- */

#define		_tc_CTR		0x70		/* Store Constant to reg   */
						/* with interpretation of  */
						/* Register and auto CONV  */ 

#define		_tc_VTR		0x77		/* Store Variable to reg   */
						/* with interpretation of  */
						/* Register and auto CONV  */ 
#define		_tc_LWS		0x77		/* Global Word Store	   */

#define		_tc_LXI		0x03		/* Chargement d'index 1er  */
#define		_tc_LXC		0x23		/* Chargement d'index 1er  */
#define		_tc_LXV		0x43		/* Chargement d'index 1er  */
#define		_tc_LXR		0x63		/* Chargement d'index 1er  */

#define		_tc_AXI		0x04		/* Chargement d'index 2eme */
#define		_tc_AXC		0x24		/* Chargement d'index 2eme */
#define		_tc_AXV		0x44		/* Chargement d'index 2eme */
#define		_tc_AXR		0x64		/* Chargement d'index 2eme */

#define		_tc_RAZ		0x05		/* Quick Free Temp.descrip */
#define		_tc_PSH		0x25		/* Reg[F,X,I,A] ==> Pile   */
#define		_tc_POP		0x45		/* Pile ==> Reg[A,I,X,F]   */
#define		_tc_LDF		0x65		/* Chargement du fonction  */
#define		_tc_NEW		0x16		/* New line Source file    */
#define		_tc_NOP		0x56		/* No operation       	   */

#define		_tc_JMI		0x12		/* Saut direct             */
#define		_tc_JMR		0x32		/* Par Registre		   */
#define		_tc_GSR		0x52		/* Par Registre		   */

#define		_tc_JMV		0x52		/* Par Variable		   */

#define		_tc_GSB		0x07		/* Appel type GOSUB        */
#define		_tc_RET		0x06		/* Retour apres GOSUB      */

#define		_tc_SGI		0x10		/* LDGO.SEG Immediate #	   */
#define		_tc_SGR		0x30		/* LDGO.SEG Registre	   */
#define		_tc_SGV		0x50		/* LDGO.SEG Variable	   */

#define		_tc_RTS		0x26		/* Return Segment	   */
#define		_tc_ETS		0x27		/* Return and liberate seg */

#define		_tc_CLP		0x17		/* Appel procedure ABAL    */
#define		_tc_RTP		0x46		/* Return Procedure        */

#define		_tc_STP		0x66		/* Fin Programme ABAL	   */

#define		_tc_GCL		0x26		/* Return Segment	   */

#define		_tc_LCL		0x17		/* Appel procedure ABAL    */
#define		_tc_GCS		0x46		/* Return Procedure        */

#define		_tc_LCS		0x66		/* Fin Programme ABAL	   */




#define		_tc_JEQI	0x18		/* Jump if Equal	   */
#define		_tc_JNEI	0x19		/* Jump if not equal	   */
#define		_tc_JGEI	0x1A		/* Jump if Greater or EQ   */
#define		_tc_JLEI	0x1B		/* Jump if Less or equal   */
#define		_tc_JGRI	0x1C		/* Jump if Greater	   */
#define		_tc_JLSI	0x1D		/* Jump if Less		   */

#define		_tc_JEQC	0x38		/* Jump if Equal	   */
#define		_tc_JNEC	0x39		/* Jump if not equal	   */
#define		_tc_JGEC	0x3A		/* Jump if Greater or EQ   */
#define		_tc_JLEC	0x3B		/* Jump if Less or equal   */
#define		_tc_JGRC	0x3C		/* Jump if Greater	   */
#define		_tc_JLSC	0x3D		/* Jump if Less		   */
#define		_tc_JINC	0x3E		/* Jump if Greater	   */
#define		_tc_JNIC	0x3F		/* Jump if Less		   */

#define		_tc_JEQV	0x58		/* Jump if Equal	   */
#define		_tc_JNEV	0x59		/* Jump if not equal	   */
#define		_tc_JGEV	0x5A		/* Jump if Greater or EQ   */
#define		_tc_JLEV	0x5B		/* Jump if Less or equal   */
#define		_tc_JGRV	0x5C		/* Jump if Greater	   */
#define		_tc_JLSV	0x5D		/* Jump if Less		   */
#define		_tc_JINV	0x5E		/* Jump if Greater	   */
#define		_tc_JNIV	0x5F		/* Jump if Less		   */

#define		_tc_JEQR	0x78		/* Jump if Equal	   */
#define		_tc_JNER	0x79		/* Jump if not equal	   */
#define		_tc_JGER	0x7A		/* Jump if Greater or EQ   */
#define		_tc_JLER	0x7B		/* Jump if Less or equal   */
#define		_tc_JGRR	0x7C		/* Jump if Greater	   */
#define		_tc_JLSR	0x7D		/* Jump if Less		   */
#define		_tc_JINR	0x7E		/* Jump if Greater	   */
#define		_tc_JNIR	0x7F		/* Jump if Less		   */

#define		_tc_ADI		0x08		/* Addition d'operandes    */
#define		_tc_ADC		0x28		/* Addition d'operandes    */
#define		_tc_ADV		0x48		/* Addition d'operandes    */
#define		_tc_ADR		0x68		/* Addition d'operandes    */

#define		_tc_SBI		0x09		/* Soustraction d'operands */
#define		_tc_SBC		0x29		/* Soustraction d'operands */
#define		_tc_SBV		0x49		/* Soustraction d'operands */
#define		_tc_SBR		0x69		/* Soustraction d'operands */

#define		_tc_MLI		0x0A		/* Multiplication operands */
#define		_tc_MLC		0x2A		/* Multiplication operands */
#define		_tc_MLV		0x4A		/* Multiplication operands */
#define		_tc_MLR		0x6A		/* Multiplication operands */

#define		_tc_DVI		0x0B		/* Division d'operands     */
#define		_tc_DVC		0x2B		/* Division d'operands     */
#define		_tc_DVV		0x4B		/* Division d'operands     */
#define		_tc_DVR		0x6B		/* Division d'operands     */

#define		_tc_MDI		0x0C		/* Modulo (Reste) operands */
#define		_tc_MDC		0x2C		/* Modulo (Reste) operands */
#define		_tc_MDV		0x4C		/* Modulo (Reste) operands */
#define		_tc_MDR		0x6C		/* Modulo (Reste) operands */

#define		_tc_ANI		0x0D		/* ET Logique d'operands   */
#define		_tc_ANC		0x2D		/* ET Logique d'operands   */
#define		_tc_ANV		0x4D		/* ET Logique d'operands   */
#define		_tc_ANR		0x6D		/* ET Logique d'operands   */

#define		_tc_ORI		0x0E		/* OU Logique d'operands   */
#define		_tc_ORC		0x2E		/* OU Logique d'operands   */
#define		_tc_ORV		0x4E		/* OU Logique d'operands   */
#define		_tc_ORR		0x6E		/* OU Logique d'operands   */

#define		_tc_XRI		0x0F		/* OU Exclusive            */
#define		_tc_XRC		0x2F		/* OU Exclusive            */
#define		_tc_XRV		0x4F		/* OU Exclusive            */
#define		_tc_XOR		0x6F		/* OU Exclusive            */

#define		_tc_INC		0x11		/* Increment Registre	   */
#define		_tc_DEC		0x31		/* Decrement Registre	   */
#define		_tc_INX		0x51		/* Increment Reg d'index   */
#define		_tc_DEX		0x71		/* Decrement Reg d'index   */
#define		_tc_ANX		0x02		/* Increment Reg d'index   */
#define		_tc_DAX		0x22		/* Decrement Reg d'index   */
#define		_tc_NGR		0x62		/* Negation d'un variable  */
#define		_tc_NGV		0x72		/* Negation d'un registre  */


#define		_tc_ESC		0x00		/* Escape sequence header  */
#define		_tc_CLF		0x15		/* Appel fonction standard */
#define		_tc_NGF		0x35		/* Access aux fichiers NGF */
#define		_tc_IOF		0x55		/* Io Functions Print ASK  */

#define		_tc_OEV		0x40		/* On erreur var ettiq	   */
#define		_tc_OER		0x1F		/* On Error reg ettiq	   */
#define		_tc_ERA		0x42		/* On erreur Abhort   	   */
#define		_tc_RES		0x60		/* On erreur Ressume  	   */
#define		_tc_REQ		0x67		/* Ressume Adresse	   */

#define		_tc_PSI		0x13		/* Pause Immediate	   */
#define		_tc_PSC		0x33		/* Pause Constante	   */
#define		_tc_PSV		0x53		/* Pause Variable 	   */
#define		_tc_PSR		0x73		/* Pause Registre 	   */

#define		_tc_OPV		0x36		/* OP Var Ettiq		   */
#define		_tc_OPR		0x57		/* OP Reg Ettiq		   */

#define		_tc_RIR		0x70		/* Read indirect register  */
#define		_tc_WIR		0x77		/* Write indirect register */
#define		_tc_TIM		0x20		/* Fonctions du TIMER      */
						/* ARG suivant 	: 0 off	   */
						/* 		: 1 goto   */
						/* 		: 2 gosub  */

#define		_tc_DSP		0x75		/* Decrement SP ( gosubs ) */
#define		_tc_WHN		0x76		/* Activation of Event	   */

#ifdef	ABAL21
#define		_tc_OEO		0x10
#define		_tc_OLE		0x57
#define		_tc_OEP		0x30
#define		_tc_LDE		0x70
#endif


#ifdef	COMPILEUR

/*	Definitions of Discreet Arithmetic/Logique Codes	*/
/*	------------------------------------------------	*/
#define		_tc_ADD		(_tc_ADI & 0x000F)
#define		_tc_SUB		(_tc_SBI & 0x000F)
#define		_tc_MUL		(_tc_MLI & 0x000F)
#define		_tc_DIV		(_tc_DVI & 0x000F)
#define		_tc_MOD		(_tc_MDI & 0x000F)
#define		_tc_AND		(_tc_ANI & 0x000F)
#define		_tc_ORR		(_tc_ORI & 0x000F)
#define		_tc_XRR		(_tc_XRI & 0x000F)

#endif

#ifdef	OPTIMISEUR

/*	Standard function library t-codes	*/
/*	---------------------------------	*/

#define		_clf_LEN	0x2B		/* CLF LEN		*/

/*	IO CYCLE t-codes	*/
/*	----------------	*/

#define		_io_ESC		0x00		/* Escape Codes		*/
#define		_io_KEY1	0x01		/* Hot Key Goto		*/
#define		_io_TABC	0x02		/* Tabulation Colonne	*/
#define		_io_ATBV	0x03		/* Screen Atributs	*/
#define		_io_PRN		0x04		/* PRINT		*/
#define		_io_TABV	0x05		/* Tabulation Verticale	*/
#define		_io_FMT		0x06		/* Format Infos		*/
#define		_io_DEV		0x07		/* Device Selection	*/
#define		_io_FORG	0x08		/* ForeGround Colour	*/
#define		_io_SPX		0x09		/* CLEAR HOME BELL	*/
#define		_io_BACK	0x0A		/* BackGround Colour	*/
#define		_io_TABL	0x0B		/* Tabulation Line	*/
#define		_io_ASK		0x0C		/* ASK			*/
#define		_io_HOT1	0x0D		/* I=&ettiquette etc	*/
#define		_io_HOT2	0x0E		/* I=(&ettiquette) etc	*/
#define		_io_KEY2	0x0F		/* Hot Key Gosub	*/


	/* ------------ */
#else	/* ! OPTIMISEUR */
	/* ------------ */

#include "exesc.h"				/* Escape Tcodes	   */

/*
 *	Definitions of Executeur Semaphores
 *	-----------------------------------
 *	These are contained in the variable SICICO Bits 0 - > 7
 *	Bits 8 -> 15 contain the language code.
 */

#define	ONSEM_CIO	0x0001	/* Console I/O manager active		*/
#define	ONSEM_SI 	0x0002	/* I.S.A.M Manager active		*/
#define	ONSEM_SEG	0x0004	/* CS segments & LDT allocated		*/
#define	ONSEM_PRC	0x0008	/* Execution of procedure underway	*/
#define	ONSEM_TRP	0x0010	/* Global error trap exists		*/
#define	ONSEM_ERR	0x0020	/* Error has occured			*/
#define	ONSEM_XVRB	0x0040	/* External Variable DEVICE		*/
#define ONSEM_VLDT	0x0080	/* Indicates Validity of L.D.T.		*/
#define	ONSEM_JOIN	0x4000	/* Indicates Jointure necessary for BD	*/
#define	ERROR_TEST	0x0030	/* Indicates either TRAP or ERROR	*/

#define	OFSEM_CIO	0xFFFE	/* Dissable CI/O Manager		*/
#define	OFSEM_SI	0xFFFD	/* Dissable ISAM manager		*/
#define	OFSEM_SEG	0xFFFB	/* Initialisation underway		*/
#define	OFSEM_PRC	0xFFF7	/* Back to segment execution		*/
#define	OFSEM_TRP	0xFFEF	/* Error trap ABORT			*/
#define	OFSEM_ERR	0xFFDF	/* Resume after error			*/
#define	OFSEM_ERTR	0xFFCF	/* Liberates both TRAP and ERROR sems	*/

#define	OFSEM_XVRB	0xFFBF	/* Liberate External Variable Semaphore */
#define	OFSEM_VLDT	0xFF7F	/* Clear LDT Semaphore			*/
#define	OFSEM_JOIN	0xBFFF	/* Clears the Jointure semaphore	*/

/*	Executeur TIMER semaphores			*/
/*	--------------------------			*/

#define	TIME_ACTIF	0x0001	/* Indicates an ON TIMER GO* function	*/
				/* is currently active			*/
#define	TIME_REARM	0xFF7F	/* Rearms the active timer after expiry */
#define	TIME_GOSUB	0x0004	/* Indicates a GOSUB / RETURN TIMER	*/
#define	TIME_CALL 	0x0008	/* Indicates a CALL / EXIT TIMER	*/
#define	TIME_RAZ	0xFF70	/* Clears the TIMER semaphore entirly	*/
#define	TIME_ALARM	0x0080	/* ALARM occured SIGNAL			*/
#define	TIME_EXPIRED (	TIME_ACTIF | TIME_ALARM ) /* Indicates timer expired */

#define	EVENT_KEEP	0xF000	/* separates hard event flag bits	*/
#define	EVENT_WIPE	0x0FFF	/* removes   hard event flag bits	*/
#define	EVENT_FLAG	0x1000	/* indicates a hard event is active	*/
#define	EVENT_HOLD	0xEFFF	/* clears an active hard event / hold	*/
#define	EVENT_GOTO	0x1000	/* Event goto direct : one shot		*/
#define	EVENT_GSUB	0x3000	/* event gosub will rearm		*/
#define	EVENT_CALL	0x5000	/* event call direct will rearm		*/
#define	EVENT_VARB	0x9000	/* event call indirect will rearm	*/

#endif	/* OPTIMISEUR */

/*	Executeur EVENT Codes				*/
/*	---------------------				*/

#define	_ec_RAZ		0x00	/* Clears Event processing		*/
#define	_ec_DCL		0x01	/* Establish Event processing		*/
#define	_ec_FAUX	0x02	/* Event expression FAUX signal		*/
#define	_ec_STOP	0x04	/* Event annulation (THEN or GOTO)	*/
#define	_ec_HALT	0x08	/* Event supension (DO or GOSUB type)	*/
#define	_ec_START	0x10	/* Event restart (after GOSUB)		*/
#define	_ec_EXTERN	0x40    /* Determines HARD / SOFT event type	*/
#define	_ec_CALLI	0x22	/* GLOBAL PROCEDURE HANDLER INTEGER	*/
#define	_ec_CALLV	0x23	/* GLOBAL PROCEDURE HANDLER VARIABLE	*/
#define	_ec_GOTO  	0x20	/* LOCAL GOTO HANDLER                	*/
#define	_ec_GOSUB 	0x21	/* LOCAL GOSUB HANDLER               	*/
#define	_ec_POP		0x24	/* POP after EVENT CALL			*/

/*	Executeur EVENT semaphores			*/
/*	--------------------------			*/

#define	EVENT_SEMON	0x0100	/* OR  MASK Activates Event checking	*/
#define	EVENT_SEMOFF	0xF0FF	/* AND MASK Disables all Event checking	*/
#define	EVENT_ACTIF	0x0200	/* TST MASK for Event check underway	*/
#define	EVENT_SWAP	0x0300	/* XOR MASK Swaps Event check cycle	*/
#define	EVENT_OVER	0x0400	/* TST / OR MASK step to next Event chk	*/
#define	EVENT_STEP	0xFBFF	/* AND MASK resets event check ON	*/
#define	EVENT_HALT	0x0A00	/* Performs Event suspension		*/
#define	EVENT_START	0x0600	/* Performs last event Reactivation	*/
#define	EVENT_EXIST	0x0800	/* Test for Valide EVENT processing	*/


#endif	/* ! EXTCODEH */
