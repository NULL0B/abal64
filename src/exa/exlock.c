#define ACCESSPURGE

/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1990 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXLOCK - C				*/
/*		Version :	1.2d / 1.3a / 1.4a			*/
/*		Date 	:	07/11/1990				*/
/*									*/
/*----------------------------------------------------------------------*/
/* Modif SB 18/06/98
   Ajout Fonction DCEXAFPURGE
     - avec no inode et dnode … z‚ro
  	purge de tous les acces au fichier quelquesoit
       	les propri‚taires ou le dnode
  	(pour utilisation en access -f<no inode> voir exdaemon.c
     - avec no inode et dnode
  	purge de tous les acces au fichier quelquesoit
       	les propri‚taires
        (pour utilisation aprŠs cfile r‚ussi pour ‚viter erreur 44 sur cfile)
     -  sans no inode et sans no dnode
        purge de tous les accŠs fichiers par un process absent
        (pour remplacer ockill plus rapide et plus s–r)
        (utilisable seulement si access lanc‚ par root)
  Ajout Purge en Open ou Matb
        purge de tous les accŠs fichiers par un process absent
        (utilisable seulement si access lanc‚ par root)
	Pour ‚viter erreur 44 en autres accŠs
*/

#include "exuser.h"		/* Message definition header		*/
#include "exlock.h"		/* Lock definition header		*/

/*
 *	Adjustment of Message Start with respect to Structure 
 *	-----------------------------------------------------
 *
 */
/*
#ifdef	x8086
#define	MsgIndent (sizeof(int) - sizeof(short int))
#endif
*/

#ifndef	MsgIndent
#if defined(RT_AIX) || defined(UNIXWARE)
#define	MsgIndent	2
#else
#define	MsgIndent	0
#endif
#endif

#include <stdio.h>		/* FILE pointer declarations		*/

#ifdef ACCESSPURGE
#include <sys/errno.h>
#endif


extern	int	errno;		/* Global Error Variable		*/

unsigned short int err_val;	/* Global System Error Variable		*/
extern	int	   UserMode;	/* User Arguament Flags			*/
extern	int	   Permission;	/* Installation success flag		*/

struct exapadd Request;		/* Global Structure			*/

struct	lokpadd {
	struct exapadd lock_info; /* Lock Informations			*/
	int    lock_ctrl;	  /* Number of access by same process	*/
	struct lokpadd *fwdptr;	  /* Liste Forward Pointer		*/
	struct lokpadd *bakptr;	  /* Liste Back Wards Pointer		*/
	};

int	lock_compt;		/* Number of Lock Structures		*/
struct	lokpadd * lock_liste;	/* Pointer to Liste of Locked Files	*/


#ifdef ACCESSPURGE
/*
 * DEL_ACCESS_LINE(struct lokpadd *, int mode)
 * Mode 0:
 * Supprime une ligne de la file d'access 
 * Mode 1:
 * Supprime un compteur de la file d'access
 * et retourne un pointeur sur la ligne suivante
 * ou 0 si plus de ligne
*/

struct lokpadd * del_access_line (wptr,mode)
struct lokpadd * wptr;
int mode;
{
  struct lokpadd * nptr;
 
    nptr = wptr->fwdptr;		/* pointeur sur ‚l‚ment suivant */

    /* Decrement Entry Usage control Counter */
    /* ------------------------------------- */
    if (mode == 1)
	{  wptr->lock_ctrl--; }
    else
	{  wptr->lock_ctrl = 0; };


    /* Zero means we can liberate it now */
    /* --------------------------------- */
    if ( wptr->lock_ctrl == 0 )
     {

      /* Check for Valid Forward Reference Pointer */
      /* ----------------------------------------- */
	if ( wptr->fwdptr !=  (struct lokpadd *) 0 )
	 {
		/* Adjust Forward link Back Reference */
		/* ---------------------------------- */
		wptr->fwdptr->bakptr = wptr->bakptr;
	 }

	/* Check for Head of the List */
	/* -------------------------- */
	if ( wptr->bakptr !=  (struct lokpadd *) 0 )
	 {
		/* Adjust to lose this Entry */
		/* ------------------------- */
		wptr->bakptr->fwdptr = wptr->fwdptr;
	 }

	/* Since this is the first element */
	/* ------------------------------- */
	else
	 {
		/* Correct list base pointer */
		/* ------------------------- */
		lock_liste = wptr->fwdptr;
	 }

	/* Liberate this table Entry Now */
	/* ----------------------------- */
	liberate (wptr); 
    }

  return (nptr);
}
#endif

/*
 *	U S E R _ I N I T ( message_parameter_structure_pointer )
 *	---------------------------------------------------------
 *	Allows initialisation of the message manager parameter structure
 *	and initialisation of the AutoMate's own Variables
 *	(Called from MAIN() before IPC MSG FILE creation and before FORK()
 */

int user_init( mptr )
struct ipc_param * mptr;
{
	/* Message Parameter Initialisations */
	/* --------------------------------- */
	(*(mptr)).key = 13;		/* Message file Key value	*/
	(*(mptr)).max = sizeof(struct exapadd);	/* Maximum communication length	*/
	(*(mptr)).id  = 1L;		/* Automate recieve ID value	*/
	(*(mptr)).perm = 0;		/* Automate recieve permissions	*/
	(*(mptr)).opt = 0;		/* Automate child semaphore	*/

	/* Lock Management Initialisations */
	/* ------------------------------- */
	lock_liste = (struct lokpadd * ) 0;	/* Rest Lock Liste Pointer */
	lock_compt = 0;				/* Zero Lock Liste Counter */

	return(0);
}


void Suivi()
{
	int	lll;
	struct	lokpadd * wptr;
	printf("\nLock Liste Status : ");
	wptr = lock_liste; lll = 0;
	while ( wptr != (struct lokpadd *) 0 ) {
		lll++;
		printf("\n((%d)) (",lll);
		printf("X= %d, M= %d, O= %d , I= %d, D= %d )",wptr->lock_ctrl,wptr->lock_info.lock_mode,wptr->lock_info.lock_owner,wptr->lock_info.lock_inode,wptr->lock_info.lock_dnode);
		wptr = wptr->fwdptr;
		}
	printf("\n");
	return;
}


/*
 *	U S E R _ M A I N ( message_text_pointer , message_id_number )
 *	--------------------------------------------------------------
 *	This function is called by the message manager to honour the
 *	received message function request
 */
	
int user_main( msgptr , msgrcvid )
char * msgptr;	
long msgrcvid;
{
	struct	lokpadd * wptr;
	struct	lokpadd * hptr;
	int	leng;
	int	status;
	int	x;
	FILE	* CoExaCore;

/* Duplicate in Lock Structure */
/* --------------------------- */
memcpy( &Request , (msgptr+MsgIndent) , sizeof(struct exapadd) ); 

if ( UserMode & 1 ) {
	printf("\nACCESS (F=");
	switch ( Request.lock_func ) {
		case SPEXAOPEN :
		case DCEXAOPEN : 
			printf("OPEN("); 
			switch ( Request.lock_mode ) {
				case 1 : printf("SHARED)");    	break;
				case 2 : printf("EXCLUSIVE)"); 	break; 
				default: printf("ERROR)");	break;
				}
			break;
		case SPEXACLOSE: 
		case DCEXACLOSE: printf("CLOSE"); break;
		case SPEXAPURGE:
		case DCEXAPURGE: printf("PURGE"); break;
		case SPEXACHANGE:
		case DCEXACHANGE: 
			printf("CHANGE(");
			switch ( Request.lock_mode ) {
				case 1 : printf("SHARED)");    	break;
				case 2 : printf("EXCLUSIVE)"); 	break; 
				default: printf("ERROR)");	break;
				}
			break;
		case SPEXASTATUS:
		case DCEXASTATUS: printf("STATUS"); break;
		case SPEXAKILL:
		case DCEXAKILL: printf("KILL"); break;
#ifdef ACCESSPURGE
		case DCEXAFPURGE : printf("FILE PURGE"); break;
#endif
		default       : printf("UNKNOWN(%04.1H)",Request.lock_func);
		

		}

	printf(",O=%d, I=%d, D=%d )",Request.lock_owner,Request.lock_inode,Request.lock_dnode);

	}

switch ( Request.lock_func ) {

case DCEXAOPEN :	/* Request to Lock File */
			/* -------------------- */

/* Check Permission of Installation Status */
/* --------------------------------------- */
if ( Permission != SUCCESS ) { return(666); }

case SPEXAOPEN :	/* Request to Lock File */
			/* -------------------- */

/* --------------------------------------------- */
/* Check for Network Device Node (NFS) 		 */
/* --------------------------------------------- */

x = 0; status = -1; wptr = lock_liste; hptr = wptr;

#ifdef DBAIX
	if ( (CoExaCore = fopen("/tmp/accessdump","a")) == (FILE *) 0) 
		return(errno);
	fprintf(CoExaCore,"EXAOPEN REQUETE DE LOCK INODE %d DNODE %d MODE %x OWNER %d PID %d\n",Request.lock_inode,Request.lock_dnode,Request.lock_mode,Request.lock_owner);
#endif

while ( wptr != (struct lokpadd *) 0 )
    {
#ifdef DBAIX
	fprintf(CoExaCore,"Fichier INODE %d MODE %d PID %d\n",wptr->lock_info.lock_inode,wptr->lock_info.lock_mode,wptr->lock_info.lock_owner);
#endif
	/* Check for File Unique identifier Matching */
	/* ----------------------------------------- */
#ifdef ACCESSPURGE
	if ( ( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode ))
	 {
#ifdef DBAIX
		fprintf(CoExaCore,"Fichier Trouv‚ MODE %d PID %d\n",wptr->lock_info.lock_mode,wptr->lock_info.lock_owner);
#endif
		if  (  wptr->lock_info.lock_owner != Request.lock_owner  )
		  {
#ifdef DBAIX
		    fprintf(CoExaCore,"Fichier Ouvert par un autre poste\n");
#endif
		    kill(wptr->lock_info.lock_owner,0);
			  /* si bloque par un processus different */
			  /* qui n'existe plus                    */
			  /* on purge la ligne d'access           */			
		    if ( errno == ESRCH)
		     {
#ifdef DBAIX
		fprintf(CoExaCore,"Lib‚ration\n");
#endif
			wptr = del_access_line (wptr, 0);
	             } /* fin ERSRCH 		*/

	         }		/* fin lock‚ par un autre poste */
	  };		/* fin meme inode meme dnode */
#endif			

	if ( ( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode ))
	 {

		/* Check for Same Owner */
		/* -------------------- */
		   if ( wptr->lock_info.lock_owner == Request.lock_owner )
		    {			/* same owner */

			/* Test for Exlusive Requested	    */
			/* -------------------------------- */
			if ( Request.lock_mode == COEXAEXCLUSIVE ) {
				status = 0; /* Denied */
				}
			else	{
				if ( wptr->lock_info.lock_mode == COEXAEXCLUSIVE ) {
					status = 0; /* Shared Rejected */
					}
				else	{ /* Shared Accepted */
					wptr->lock_ctrl = wptr->lock_ctrl + 1;
					status = 1;
					}
				}
			break;
		  }	/* fin same owner */
		else
		  {	/* Not the Same Owner */
			/* ------------------ */
			if ( Request.lock_mode == COEXAEXCLUSIVE ) {

				/* Exclusivity Demanded Rejected */
				/* ----------------------------- */
				status = 0;
				break;
				}

			/* Test for Already held EXCLUSIVE */
			/* ------------------------------- */
			if ( wptr->lock_info.lock_mode == COEXAEXCLUSIVE ) {

				/* Shared Mode Demanded Rejected */
				/* ----------------------------- */
				status = 0;
				break;
				}

			/* ---------------------------------------- */
			/* Arrival Here Means We Can Share the File */
			/* But First we must check to See if there  */
			/* is another record in the Liste for this  */
			/* File for This process	CONTINUE    */
			/* ---------------------------------------- */
			hptr = wptr;
			wptr = wptr->fwdptr;
			}
		}  /* fin not same owner */
	else	{
		/* ------------------------------ */
		/* File Not Matching So Seek Next */
		/* ------------------------------ */
		hptr = wptr;
		wptr = wptr->fwdptr;

		}
#ifdef DBAIX
	fclose(CoExaCore);
#endif

	}		/* Wend */

switch ( status ) {
	case 1 :	/* Succesful Completion nothing to Do */
			/* ---------------------------------- */
		if ( UserMode & 1 ) {
			Suivi();
			}
		return(0);

	case 0 :	/* Failure Nothing to Do */
			/* --------------------- */
		return(44);

	case -1:	/* Succesful completion add to End of 	*/
			/* ----------------------------------   */
			wptr = (struct lokpadd *) allocate ( sizeof(struct lokpadd) );
			if ( wptr == (struct lokpadd *) 0 ) { status = 0; }
			else	{
				if ( hptr != (struct lokpadd *) 0 ) {
					hptr->fwdptr = wptr;
					}
				else	{
					lock_liste = wptr;
					}
				wptr->bakptr = hptr;
				wptr->fwdptr = (struct lokpadd *) 0;
				wptr->lock_ctrl = 1;
				memcpy(&wptr->lock_info,&Request,sizeof(struct exapadd));
				status = 1;
				}
			if ( UserMode & 1 ) { Suivi(); }
			return(0);
		}
	return(56);

/* ========================================================================= */
case SPEXACLOSE:	/* Request to Unlock File */
			/* ---------------------- */
case DCEXACLOSE:	/* Request to Unlock File */
			/* ---------------------- */
x = 0; status = -1;
wptr = lock_liste;
while ( wptr != (struct lokpadd *) 0 )
     {

	/* Check for File Unique identifier Matching */
	/* ----------------------------------------- */
	if (( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode ))
          {
		/* Check for Same Owner */
		/* -------------------- */
		if ( wptr->lock_info.lock_owner == Request.lock_owner )
		 {
			wptr = del_access_line (wptr,1);

			/* Indicate Sucessful Close Operation */
			/* ---------------------------------- */
			if ( UserMode & 1 ) { Suivi(); }
			return(0);

		  	/* ---------------- */
		}	/* Endif Same Owner */
			/* ---------------- */
		/* -------------------------- */
	  }	/* Endif File ID Couple Match */
		/* -------------------------- */

		/* File Not Matching So Seek Next */
		/* ------------------------------ */
	  wptr = wptr->fwdptr;
	}
	return(0);

#ifdef ACCESSPURGE
/* ========================================================================= */
/*	------------------------------------------------------------	*/
/*	Liberation of all remaining Locks for the file identifier 	*/
/*	------------------------------------------------------------	*/
case DCEXAFPURGE :
case SPEXAFPURGE :
     if ( Request.lock_inode == 0)
       { /* requete de purge g‚n‚rale ( seulement si access est root ) */
#ifdef DBAIX
	  fprintf(CoExaCore,"Requˆte de purge g‚n‚rale\n");
#endif
	x = 0; status = -1; wptr = lock_liste; hptr = wptr;
	while ( wptr != (struct lokpadd *) 0 )
         {
		if  (  wptr->lock_info.lock_owner == Request.lock_owner  )
		  {
			/* Next Table Entry Pointer */
			/* ------------------------ */
			wptr = wptr->fwdptr;
		  }
		else
		  {
#ifdef DBAIX
		    fprintf(CoExaCore,"Fichier Ouvert par un autre poste\n");
#endif
		    kill(wptr->lock_info.lock_owner,0);
			  /* si bloque par un processus different */
			  /* qui n'existe plus                    */
			  /* on purge la ligne d'access           */			
		    if ( errno == ESRCH)
		     {
#ifdef DBAIX
		fprintf(CoExaCore,"Lib‚ration\n");
#endif
			wptr = del_access_line (wptr,0);
	 	     } /* fin ERSRCH 		*/
		else
		     {
			/* Next Table Entry Pointer */
			/* ------------------------ */
			wptr = wptr->fwdptr;
		     };

	         }		/* fin lock‚ par un autre poste */

         }
	return(0);
       } /* fin requete de purge g‚n‚rale */
     else
       { /* requete de purge d'un fichier */
	wptr = lock_liste;
#ifdef DBAIX
	  fprintf(CoExaCore,"Requˆte de purge Inode %d Dnode %d\n",Request.lock_inode,Request.lock_dnode);
#endif
	while ( wptr != (struct lokpadd *) 0 ) {

		/* Check for File Unique identifier Matching */
		/* ----------------------------------------- */
/*		if (( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode )) */
		if ( ( ( Request.lock_dnode == 0) || (Request.lock_dnode == wptr->lock_info.lock_dnode) ) 
                  && ( wptr->lock_info.lock_inode == Request.lock_inode ) )
		 {
			wptr = del_access_line (wptr,0);
		 }
		else
		 {
			/* Next Table Entry Pointer */
			/* ------------------------ */
			wptr = wptr->fwdptr;
		 }
	  } /* fin du while */
	return(0);

      } /* fin de requete de purge d'un fichier */

#endif




/*	------------------------------------------------------------	*/
/*	Liberation of all remaining Locks for the process identifier 	*/
/*	------------------------------------------------------------	*/
case DCEXAPURGE :
case SPEXAPURGE :
	wptr = lock_liste;
	while ( wptr != (struct lokpadd *) 0 ) {

		/* Check for Same Owner */
		/* -------------------- */
		if (( wptr->lock_info.lock_owner == Request.lock_owner ) || ( Request.lock_owner == 0 )) {
	
			wptr = del_access_line (wptr,0);
			}
		else	{

			/* Next Table Entry Pointer */
			/* ------------------------ */
			wptr = wptr->fwdptr;
			}
		}
		return(0);

/*	--------------------------------------		*/
/*	Modification of Current Opening Method		*/
/*	Change mode : Exclusive , or Shared 		*/
/*	--------------------------------------		*/
case DCEXACHANGE :
case SPEXACHANGE :

/* Initialise Table management pointers */
/* ------------------------------------ */
wptr = lock_liste; hptr = (struct lokpadd * ) 0;

/* While not end of Liste */
/* ---------------------- */
while ( wptr != (struct lokpadd *) 0 ) {

	/* Check for File Unique identifier Matching */
	/* ----------------------------------------- */
		
#ifdef ACCESSPURGE
	if (( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode )) {
#ifdef DBAIX
		fprintf(CoExaCore,"ATB Fichier Trouv‚ MODE %d PID %d\n",wptr->lock_info.lock_mode,wptr->lock_info.lock_owner);
#endif
		if  (  wptr->lock_info.lock_owner != Request.lock_owner  )
		  {
#ifdef DBAIX
		    fprintf(CoExaCore,"Fichier Ouvert par un autre poste\n");
#endif
		    kill(wptr->lock_info.lock_owner,0);
			  /* si bloque par un processus different */
			  /* qui n'existe plus                    */
			  /* on purge la ligne d'access           */			
		    if ( errno == ESRCH)
		     {
#ifdef DBAIX
		fprintf(CoExaCore,"Lib‚ration\n");
#endif
			wptr = del_access_line (wptr,0);
	 	   } /* fin ERSRCH 		*/

	         }		/* fin lock‚ par un autre poste */
	    }
#endif			
	if (( wptr->lock_info.lock_inode == Request.lock_inode ) && ( wptr->lock_info.lock_dnode == Request.lock_dnode )) {
		/* Check for Same Owner */
		/* -------------------- */
		if ( wptr->lock_info.lock_owner == Request.lock_owner ) {

			/* Test for Exclusive Requested	    */
			/* -------------------------------- */
			if ( Request.lock_mode == COEXAEXCLUSIVE ) {

				/* Check for Unique Access */
				/* ----------------------- */
				if ( wptr->lock_ctrl > 1 ) {

					/* Exclusivity Refused : multiple Sharing */
					/* -------------------------------------- */
					return(44);
					}
				else	{
					/* ------------------------------------- */
					/* Exclusivity Possible : Unique Access  */
					/* But First Check for Exclusive already */
					/* ------------------------------------- */
					if ( wptr->lock_info.lock_mode == COEXAEXCLUSIVE ) {
			
						/* ------------------------------*/
						/* Already Exclusive OK no error */
						/* ----------------------------- */
						return(0);
						}
					else	{
						/* ------------------------------------ */
						/* SHARED MODE Check for Others	        */
						/* Keep Current pointer and Rescan List */
						/* for other process shared locks which */
						/* will cause refusal of request        */
						/* ------------------------------------ */
						if ( hptr == (struct lokpadd *) 0) {
							hptr = wptr;
							wptr = wptr->fwdptr;
							continue;
							}
						else	{
							/* Whoops fragmented Table */
							/* ----------------------- */
							return(44);
							}
						}
					}				
				}
			else	{
				/* Shared mode requested : Easy Do it now */
				/* -------------------------------------- */
				wptr->lock_info.lock_mode = COEXASHARELOCK;
				return(0);
				}

			}
		else	{
			/* File Match Found But Different Owner */
			/* Check for EXCLUSIVE or SHARED modes  */
			/* ------------------------------------ */
			if ( Request.lock_mode == COEXAEXCLUSIVE ) {

				/* Exclusive Request Refused since */
				/* File is already shared 	   */
				/* ------------------------------- */
				return(44);
				}
			else	{
				/* OK we can continue the list scanning */
				/* ------------------------------------ */
				wptr = wptr->fwdptr;
				continue;
				}
			}
		}
	else	{
		/* ------------------------------ */
		/* File Not Matching So Seek Next */
		/* ------------------------------ */
		wptr = wptr->fwdptr;
		continue;
		}
	}

	/* ----------------------------------------------------------- */
	/* Arrival here means the file has not been declared for COEXA */
	/* or no one else is sharing the file so Exclusivity Granted   */
	/* ----------------------------------------------------------- */
	if ( hptr == (struct lokpadd *) 0 ) {
		/* File Not Declared Open */
		/* ---------------------- */
		return(42);
		}
	else	{
		/* OK for Exclusive request */
		/* ------------------------ */
		hptr->lock_info.lock_mode = COEXAEXCLUSIVE;
		return(0);
		}

/*	---------------------------------------------	*/
/*	Output statistics to Standard COEXA CORE file 	*/
/*	---------------------------------------------	*/
case DCEXASTATUS  :
case SPEXASTATUS  :

	/* Attempt to open or Create Core File */
	/* ----------------------------------- */
	if ( (CoExaCore = fopen(COREFILE,"w")) == (FILE *) 0) {
		return(errno);
		}

	/* Establish List Base pointer */
	/* --------------------------- */
	wptr = lock_liste;

	/* Core File Header       */
	/* ----------------	  */
	fprintf(CoExaCore,"\nFile Access Manager Status : P(%d) Q(%d)",getpid(),getqid());
	fprintf(CoExaCore,"\n------------------------------------------------");
	fprintf(CoExaCore,"\n I node   D node   P.I.D.    Mode ( Count )     ");
	fprintf(CoExaCore,"\n------------------------------------------------");
	
	/* While not end of Liste */
	/* ---------------------- */
	while ( wptr != (struct lokpadd *) 0 ) {

		/* Output File and Owner details */
		/* ----------------------------- */
		fprintf(CoExaCore,"\n%8ld %8ld %8ld ",wptr->lock_info.lock_inode,wptr->lock_info.lock_dnode,wptr->lock_info.lock_owner);

		/* Display Mode and, if Shared, Count */
		/* ---------------------------------- */
		if ( wptr->lock_info.lock_mode == COEXAEXCLUSIVE ) {
			fprintf(CoExaCore," EXCLUSIVE");
			}
		else	{
			fprintf(CoExaCore," SHARED(%d)",wptr->lock_ctrl);
			}
		wptr = wptr->fwdptr;
		}

	/* Close the core file */
	/* ------------------- */
	fprintf(CoExaCore,"\n------------------------------------------------\n");
	fclose( CoExaCore );
	return(0);

case DCEXAKILL :
case SPEXAKILL :
	(void) ExUserKill(15);
	exit(0);
		
/*	------------------------------------------------------------	*/
/*	All other commands are Reserved for Extension and Return 56	*/
/*	------------------------------------------------------------	*/
default	     :	
	if ( UserMode & 1 ) {
		printf("\nUnknown function request #%d\n",Request.lock_func);
		}
	return( 56 );
	}

}
