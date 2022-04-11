/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXSIGNAL - C				*/
/*		Version :	1.4c / 2.1a				*/
/*		Date 	:	06/04/1998				*/
/*		Date 	:	28/01/1993				*/
/*									*/
/*----------------------------------------------------------------------*/
#ifndef  EXSIGNALC
#define  EXSIGNALC

#ifndef  PROLOGUE
#ifndef  DOS

#include <signal.h>		/* Signal function definitions header	*/
#include "excico.h"

void inhibe_signal(void);

#ifdef ABAL_CRITERIA
#ifdef LINUX
extern int FlagSignal;
#else
static	int FlagSignal;
#endif
#endif
extern int FlagExaRed;

#if defined(RT_AIX) || defined(LINUX)
EXTERN EX_FILE_HANDLE TcodeFileHandle;	/* Numero logique du fichier		*/
#endif
/*
 *	E X A S O R T I E ( sigid )
 *	---------------------------
 *	Allows reception of the signal SIGTERM : SOFTWARE TERMINATION
 *	and performs a graceful exit to the operating system after
 *	terminal liberation and Purge of Co-Executeur Locking Infos
 */

static	void ExaSortie( sigid )
int	sigid;
{
FILE *ftrace;
#if defined(RT_AIX) || defined(LINUX)
EX_FILE_HANDLE	CloseTcodeFile();
#endif


	/* on inhibe les signaux */
	/* Attention, cette zone est critique, si EXA recoit un signal */
	/* alors qu'il n'a pas fini d'inhiber l'ensemble des signaux */
	/* ca peut finir tres mal, il faudra donc trouver une solution */
	/* pour rendre cette fonction ininterrompable meme par le systeme */
	inhibe_signal();

#ifdef USED
	ftrace = fopen("./trace.trc", "aw");
	fprintf(ftrace, "\nExa Sortie reception signal apres inhibe 2");
	fclose(ftrace);
#endif

#ifdef ABAL_CRITERIA
	FlagSignal=1;
	(void) si_fin();		/* IsamEnd		*/
#endif
					/* -------------------- */
	(void) x_newlyne();		/* Newline Feed		*/
#ifdef SPARC
        (void) modterm(1);		/* forcer le reset ecran*/
#endif
	(void) finterm(0);		/* stty sane please	*/

#ifdef	COEXA
	(void) PurgeLox();		/* liberate all files	*/
#endif
#ifdef	UNIX
     TcodeFileHandle = CloseTcodeFile( TcodeFileHandle );
#endif

#ifdef USED
	ftrace = fopen("./trace.trc", "aw");
	fprintf(ftrace, "\nExa Sortie fin");
	fclose(ftrace);
#endif

	exit(0);			/* and die gracefully	*/
					/* -------------------- */
}

#include "fct.c"

/*
 *	E X S I G N A L ( sigid )
 *	-------------------------
 *	Performs system exception signal management for Executeur under 
 *	UNIX like operating systems that offer the SIGNAL() function
 *		sigid = Signal number
 *	Note : 
 *		Sigid = 0	==>	Initialise signal trapping
 *		Sigid = 99	==>	Liberate signal trapping
 *
 */	

void ReadEnvSig()

{

char *MyVar;
int LenMyVar;
int etat;
int numsig;
int erreur = 0;
int type_action;
int i;
int j;
int cpt;
TRAPSIGNAL *cour;
char chaine[50];
int saute=0;



	MyVar = (char *)getenv((char *)"TRAPPEDSIGNAL");
	if (MyVar == NULL)
		{

		/* la variable n'est pas definie */
		/* on positionne les signaux par defaut */
		nb_lolotte=NB_DEFAULT_SIGNAL;
		if (!(TabSig=(TRAPSIGNAL *)allocate(nb_lolotte*sizeof(TRAPSIGNAL))))
			{ erreur = 27; goto err; }
		memset(TabSig, 0x00, nb_lolotte*sizeof(TRAPSIGNAL));
		memset(chaine, 0x00, 50);

		/* On remplit */
		for (cour=TabSig, i=0; i<nb_lolotte; i++, cour++)
			{
			switch (i)
				{
				case 0 :
					(*cour).nosig = DEFAULT_SIGNAL0;
					(*cour).type = TYPE_DEFAULT_SIGNAL0;
					break;
				case 1 :
					(*cour).nosig = DEFAULT_SIGNAL1;
					(*cour).type = TYPE_DEFAULT_SIGNAL1;
					break;
				case 2 : 
					(*cour).nosig = DEFAULT_SIGNAL2;
					(*cour).type = TYPE_DEFAULT_SIGNAL2;
					break;
				case 3 :
					(*cour).nosig = DEFAULT_SIGNAL3;
					(*cour).type = TYPE_DEFAULT_SIGNAL3;
					break;
				case 4 :
					(*cour).nosig = DEFAULT_SIGNAL4;
					(*cour).type = TYPE_DEFAULT_SIGNAL4;
					break;
				}
			}
			
		return;
		}



	/* Analyse de la liste et remplissage du tableau */
	/* chaque case correspond a une etape de l'automate */
	/* case 0 : lecture du numero du signal */
	/* case 1 : lecture de la parenthese ouvrante */
	/* case 2 : lecture de l'action a effectuer sur le signal */
	/* case 3 : lecture de la parenthese fermante */
	/* case 4 : lecture de la virgule */

	LenMyVar = strlen(MyVar);
	etat = 0;
	numsig = 0;
	/* Au premier passage, on compte le nombre de signaux a intercepter */
	cpt=0;
	for (i=0; i<LenMyVar; i++)
		{
		switch (etat)
			{
			case 0 : /* lecture numero signal */
				if ( (*(MyVar+i) >= '0') && *(MyVar+i) <= '9')
					{
					numsig = (numsig*10) + (*(MyVar+i)-0x30);
					continue;
					}
				else
					if ( (*(MyVar+i) == ' ' && numsig)
					     || (*(MyVar+i) == '(') )
						{ etat=1; i--; }
					else
						if ( *(MyVar+i) == ' ' && !numsig)
							continue;
						else
							erreur = 1;
				break;

			case 1 : /* lecture parenthese ouvrante */
				if (*(MyVar+i) == '(')
					{ 
					etat=2; 
					if (numsig == SIGUSR1 || numsig == SIGUSR2)
						{ 
						/* on ne doit pas prendre ces */
						/* signaux en compte */
						saute = 1;
						}
					else
						{ cpt++; }
					}
				else
					if (*(MyVar+i) != ' ')
						erreur = 2;
				break;

			case 2 : /* lecture action */
				if (*(MyVar+i) == 'K')
					{ 
					etat=3; 
					continue; 
					}
				else if (*(MyVar+i) == 'N')
					{ etat=3; continue; }
				else if (*(MyVar+i) == 'I')
					{ etat=3; continue; }
				else if (*(MyVar+i) != ' ')
					{ erreur = 3; }
				break;

			case 3 : /* lecture parenthese fermante */
				if (*(MyVar+i) == ')')
					{ etat=4; }
				else	
					if (*(MyVar+i) != ' ')
						erreur = 4;
				break;

			case 4 : /* lecture virgule */
				if (*(MyVar+i) == ',')
					{
					etat=0; numsig=0; 
					if (saute) saute--;
					}
				else
					if (*(MyVar+i) != ' ')
						erreur = 5;
				break;

			}
		if (erreur)	break;
		}


	nb_lolotte = cpt;

	/* Allocation du tableau de structure pour la liste des signaux */
	if ( !(TabSig = (TRAPSIGNAL *)allocate(cpt*sizeof(TRAPSIGNAL))))
		{ erreur = 27; goto err; }
	memset(TabSig, 0x00, cpt*sizeof(TRAPSIGNAL));

	etat=0;
	numsig=0;
	/* On redecode la variable d'environnement pour remplir le tableau */
	for (cour=TabSig, i=0; i<LenMyVar; i++)
		{
		switch (etat)
			{
			case 0 : /* lecture numero signal */
				if ( (*(MyVar+i) >= '0') && *(MyVar+i) <= '9')
					numsig = (numsig*10) + (*(MyVar+i)-0x30);
				else
					if ( (*(MyVar+i) == ' ' && numsig)
					     || (*(MyVar+i) == '(') )
						{ etat=1; i--; }
					else
						if ( *(MyVar+i) == ' ' && !numsig)
							continue;
						else
							erreur = 1;
				break;

			case 1 : /* lecture parenthese ouvrante */
				if (*(MyVar+i) == '(')
					{ 
					etat=2; 
					if (numsig == SIGUSR1 || numsig == SIGUSR2)
						{ saute = 1; }
					else
						{
						cpt++; 
						(*cour).nosig=(int)numsig; 
						}
					}
				else
					if (*(MyVar+i) != ' ')
						erreur = 2;
				break;

			case 2 : /* lecture action */
				if (*(MyVar+i) == 'K')
					{ 
					if (!saute)
						cour->type=0; 
					etat=3; 
					}
				else if (*(MyVar+i) == 'N')
					{ 
					if (!saute)
						cour->type=1; 
					etat=3; 
					}
				else if (*(MyVar+i) == 'I')
					{
					if (!saute)
						cour->type=2;
					etat=3;
					}
				else if (*(MyVar+i) != ' ')
					erreur = 3;
				break;

			case 3 : /* lecture parenthese fermante */
				if (*(MyVar+i) == ')')
					{ etat=4; }
				else	
					if (*(MyVar+i) != ' ')
						erreur = 4;
				break;

			case 4 : /* lecture virgule */
				if (*(MyVar+i) == ',')
					{
					if (!saute)	cour++;
					else		saute--;
					etat=0; numsig=0;
					}
				else
					if (*(MyVar+i) != ' ')
						erreur = 5;
				break;

			}
		if (erreur)	break;
		}


err:
	if (erreur)	printf("\nErreur %d", erreur);

}




void exsignal( sigid )
int sigid;

{
int i;
FILE *ftrace;


	switch (sigid)
		{
		case 0 :	/* Initialisation of Signal TRAPS */
				/*--------------------------------*/
			for (i=0; i<nb_lolotte; i++)
				{
				if (TabSig[i].type == 1)
					{
					/* type = 1, on debranche vers la fonction qui ne fait */
					/* rien */
#ifdef LINUX
					(void) signal((int)(TabSig[i].nosig), exsignal);
#else
					(void) sigset((int)(TabSig[i].nosig), exsignal);
#endif
					}
				else if (!TabSig[i].type)
					{
					/* type = 0, on debranche vers la fonction qui sort en */
					/* fermant tous les fichiers */
#ifdef USED
					ftrace = fopen("./trace.trc", "aw");
					fprintf(ftrace, "\nJe debranche vers signal %d", TabSig[i].nosig);
					fclose(ftrace);
#endif
#ifdef LINUX
					(void) signal((int)(TabSig[i].nosig), ExaSortie);
#else
					(void) sigset((int)(TabSig[i].nosig), ExaSortie);
#endif
					}
				else if (TabSig[i].type == 2)
					{
					/* on ignore le signal */
#ifdef LINUX
					(void) signal((int)(TabSig[i].nosig), SIG_IGN);
#else
					(void) sigset((int)(TabSig[i].nosig),SIG_IGN);
#endif
					}
				}
			break;

		case 99 :	/* Liberation of Signals TRAPPED */
				/*-------------------------------*/
			for (i=0; i<nb_lolotte; i++)
				{
#ifdef LINUX
				(void) signal((int)(TabSig[i].nosig), SIG_DFL);
#else
				(void) sigset((int)(TabSig[i].nosig), SIG_DFL);
#endif
				}
			break;

		default :	/* Handling of received signals */
				/*------------------------------*/
			(void) x_newlyne();
			(void) x_cprintf((BPTR)TalkPtr[12]);
			(void) x_putch(' ');
			(void) intvisi( sigid );
			(void) eder(err_val);
			(void) exsignal( 99 );
			exit(0);
		}
	return;

}


void inhibe_signal()

{
FILE *ftrace;

	/* on inhibe tous les signaux */

#ifdef LINUX
	(void) signal(SIGHUP, SIG_IGN);
	(void) signal(SIGINT, SIG_IGN);
	(void) signal(SIGQUIT, SIG_IGN);
	(void) signal(SIGILL, SIG_IGN);
	(void) signal(SIGTRAP, SIG_IGN);
	(void) signal(SIGIOT, SIG_IGN);
	(void) signal(SIGABRT, SIG_IGN);
	(void) signal(SIGFPE, SIG_IGN);
	(void) signal(SIGBUS, SIG_IGN);
	(void) signal(SIGSEGV, SIG_IGN);
	(void) signal(SIGPIPE, SIG_IGN);
	(void) signal(SIGALRM, SIG_IGN);
	(void) signal(SIGTERM, SIG_IGN);
	(void) signal(SIGUSR1, SIG_IGN);
	(void) signal(SIGUSR2, SIG_IGN);
	(void) signal(SIGCLD, SIG_IGN);
	(void) signal(SIGCHLD, SIG_IGN);
	(void) signal(SIGPWR, SIG_IGN);
	(void) signal(SIGWINCH, SIG_IGN);
	(void) signal(SIGSTOP, SIG_IGN);
	(void) signal(SIGTSTP, SIG_IGN);
	(void) signal(SIGCONT, SIG_IGN);
	(void) signal(SIGTTIN, SIG_IGN);
	(void) signal(SIGTTOU, SIG_IGN);
	(void) signal(SIGVTALRM, SIG_IGN);
	(void) signal(SIGPROF, SIG_IGN);
#ifndef RT_AIX
	(void) signal(SIGPOLL, SIG_IGN);
#endif
#else	/* pas LINUX */
	(void) sigset(SIGHUP, SIG_IGN);
	(void) sigset(SIGINT, SIG_IGN);
	(void) sigset(SIGQUIT, SIG_IGN);
	(void) sigset(SIGILL, SIG_IGN);
	(void) sigset(SIGTRAP, SIG_IGN);
	(void) sigset(SIGIOT, SIG_IGN);
	(void) sigset(SIGABRT, SIG_IGN);
	(void) sigset(SIGFPE, SIG_IGN);
	(void) sigset(SIGBUS, SIG_IGN);
	(void) sigset(SIGSEGV, SIG_IGN);
	(void) sigset(SIGPIPE, SIG_IGN);
	(void) sigset(SIGALRM, SIG_IGN);
	(void) sigset(SIGTERM, SIG_IGN);
	(void) sigset(SIGUSR1, SIG_IGN);
	(void) sigset(SIGUSR2, SIG_IGN);
	(void) sigset(SIGCLD, SIG_IGN);
	(void) sigset(SIGCHLD, SIG_IGN);
	(void) sigset(SIGPWR, SIG_IGN);
	(void) sigset(SIGWINCH, SIG_IGN);
	(void) sigset(SIGSTOP, SIG_IGN);
	(void) sigset(SIGTSTP, SIG_IGN);
	(void) sigset(SIGCONT, SIG_IGN);
	(void) sigset(SIGTTIN, SIG_IGN);
	(void) sigset(SIGTTOU, SIG_IGN);
	(void) sigset(SIGVTALRM, SIG_IGN);
	(void) sigset(SIGPROF, SIG_IGN);
#ifndef RT_AIX
	(void) sigset(SIGPOLL, SIG_IGN);
#endif
#ifndef LINUX
	(void) sigset(SIGEMT, SIG_IGN);
	(void) sigset(SIGSYS, SIG_IGN);
#endif
#endif 	/*LINUX */
	return;

}





	/* ------------ */
#endif	/* ! DOS 	*/
#endif	/* ! PROLOGUE	*/
#endif	/* ! EXSIGNALC	*/
	/* ------------ */

