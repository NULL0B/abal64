/*-------------------------------------------------------------------------
							09/04/98


	Fichier FCT.C

	Module pour le deroutement des signaux sous UNIX pour EXA.

	Lecture d'une variable d'environnement pour savoir quels sont les 
	signaux qu'il faut trapper. La variable d'environnement s'appelle :
		TRAPPEDSIGNAL

	Si la variable d'environnement n'existe pas, on trappe les memes 
	signaux qu'auparavant, a savoir :

		Signal			Action
		SIGHUP			sortie avec purge des fichiers
		SIGSEGV			sortie sans action
		SIGTSTP			sortie avec purge des fichiers
		SIGTERM			sortie avec purge des fichiers
		SIGBUS			sortie sans action


	Si la variable d'environnement est positionnee, on analyse cette
	variable pour savoir quelle action realiser sur chaque signal 
	trappe. La syntaxe est la suivante :

		TRAPPEDSIGNAL="Numero_signal(Action),Numero_signal(Action)..."
	Action peut valoir K ou N : 
		K = sortie avec purge des fichiers
		N = sortie sans action

	Exemple :
		TRAPPEDSIGNAL="1(K),15(K),24(N)"
		Sur le signal 1, on sort en purgeant les fichiers
		Sur le signal 15, on sort en purgeant les fichiers
		Sur le signal 24, on sort en ne realisant aucune action


	Attention, les signaux 16 et 17 ne peuvent etre trappes, puisqu'ils
	sont utilises par la partie redirecteur de EXA et la partie Serveur de
	Criteria pour la synchronisation des processus Client et Serveur. S'ils
	font partie de la variable d'environnement, ils sont ignores.
	D'autre part, si une erreur intervient dans la syntaxe de la variable
	d'environnement, aucun signal ne sera trappe.


-------------------------------------------------------------------------*/


#define NB_DEFAULT_SIGNAL 	5
#define DEFAULT_SIGNAL0		10
#define DEFAULT_SIGNAL1		11
#define DEFAULT_SIGNAL2		15
#define DEFAULT_SIGNAL3		24
#define DEFAULT_SIGNAL4		1
#define TYPE_DEFAULT_SIGNAL0	1
#define TYPE_DEFAULT_SIGNAL1	1
#define TYPE_DEFAULT_SIGNAL2	0
#define TYPE_DEFAULT_SIGNAL3	0
#define TYPE_DEFAULT_SIGNAL4	0


/* structure d'un signal trappe */
typedef struct TRAPSIG
	{
	int nosig;		/* numero du signal */
	int type;		/* type = 0, on ferme tout sur ce signal */
				/* type = 1, on ignore , on continue */
	} TRAPSIGNAL;


TRAPSIGNAL *TabSig;
int nb_lolotte;


#ifdef LOLOTTE
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


	(void) x_newlyne();
	x_cprintf((BPTR)"ReadEnvSig");
	x_getch();

	MyVar = (char *)getenv((char *)"TRAPPEDSIGNAL");
	if (MyVar == NULL)
		{

		(void) x_newlyne();
		x_cprintf((BPTR)"ReadEnvSig NULL");
		x_getch();

		/* la variable n'est pas definie */
		/* on positionne les signaux par defaut */
		nb=NB_DEFAULT_SIGNAL;
		if (!(TabSig=(TRAPSIGNAL *)malloc(nb*sizeof(TRAPSIGNAL))))
			{ erreur = 27; goto err; }
		memset(TabSig, 0x00, nb*sizeof(TRAPSIGNAL));
		memset(chaine, 0x00, 50);

		/* On remplit */
		for (cour=TabSig, i=0; i<nb; i++, cour++)
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


	(void) x_newlyne();
	x_cprintf((BPTR)"ReadEnvSig pas NULL");
	x_getch();


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
				else
					if (*(MyVar+i) == 'N')
						{ 
						etat=3; 
						}
					else
						if (*(MyVar+i) != ' ')
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


	nb = cpt;

	/* Allocation du tableau de structure pour la liste des signaux */
	if ( !(TabSig = (TRAPSIGNAL *)malloc(cpt*sizeof(TRAPSIGNAL))))
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
						(*cour).nosig=numsig; 
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
				else
					if (*(MyVar+i) == 'N')
						{ 
						if (!saute)
							cour->type=1; 
						etat=3; 
						}
					else
						if (*(MyVar+i) != ' ')
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

	(void) x_newlyne();
	x_cprintf((BPTR)"ReadEnvSig fin nb");
	intvisi(nb);
	x_getch();


err:
	if (erreur)	printf("\nErreur %d", erreur);

}




void exsignal( sigid )
int sigid;

{
int i;

	(void) x_newlyne();
	x_cprintf((BPTR)"exsignal ");
	intvisi(sigid);
	x_getch();

	switch (sigid)
		{
		case 0 :	/* Initialisation of Signal TRAPS */
				/*--------------------------------*/
			(void) x_newlyne();
			x_cprintf((BPTR)"exsignal nb");
			intvisi(nb);
			x_getch();
			(void) signal(SIGTERM, ExaSortie);
			for (i=0; i<nb; i++)
				{
				if (TabSig[i].type)
					{
					/* type = 1, on debranche vers la fonction qui ne fait */
					/* rien */
					(void) signal((int)(TabSig[i].nosig), exsignal);
					printf("\n Signal n %d vers exsignal", TabSig[i].nosig);
					}
				else
					{

					(void) x_newlyne();
					x_cprintf((BPTR)"exsignal positionne ");
					intvisi(TabSig[i].nosig);
					x_getch();

					/* type = 0, on debranche vers la fonction qui sort en */
					/* fermant tous les fichiers */
					(void) signal((int)(TabSig[i].nosig), ExaSortie);
					printf("\n Signal n %d vers ExaSortie", TabSig[i].nosig);
					}
				}
			break;

		case 99 :	/* Liberation of Signals TRAPPED */
				/*-------------------------------*/
			for (i=0; i<nb; i++)
				{
				(void) signal((int)(TabSig[i].nosig), SIG_DFL);
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



#endif	/* LOLOTTE */
