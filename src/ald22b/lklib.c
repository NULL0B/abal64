/*------------------------------------------------------------- LKLIB.C ------
 *
 *	Editeur de liens A.B.A.L.	-   Copyright Amenesik / Sologic s.a. (c) 1993
 *
 *		Interface avec les objets externes au linker
 *
 *		      Creation 2.0 le 07/04/1993
 *
 * Revisions :
 *	
 *
 *---------------------------------------------------------------------------*/

#define _LKLIB

#include "aldtype.h"
#include "lkstruct.h"

#include "lklib.h"
#include "lkfile.h"
#include "lkmes.h"
#include "lkmain.h"
#include "fn_parse.h"
#include "lkecran.h"

/*********************************
* FCT LibDiffRepFic
*
* Entree : 
*	repertoire
*	fichier	
*	tampon de reception rep. + fic.
* Sortie :
*	rien
*
* Remarque :
*	resul est un parametre en reecriture
*
**********************************/

VOID  LibDiffRepFic(BYTE XPTR * repertoire, BYTE XPTR * fichier, BYTE XPTR * resultat)
{
//JPH	BYTE misctmpA[LGREP];
//JPH	BYTE misctmpB[LGREP];
//JPH	BYTE misctmp[LGREP];
//JPH	WORD niveauA;
//JPH	WORD niveauB;
//JPH	WORD i;
//JPH	WORD boule;
//JPH	WORD niveau;

	resultat[0] = EOSTR;

	Xfn_parser
		(
		(BYTE XPTR *) fichier, 
		(BYTE XPTR *) resultat, 
		(FILE_NETWORK_NODE | FILE_DEVICE | FILE_PATH | FILE_NAME | FILE_EXTENSION)
		);
}

/*********************************
* FCT LibMakeReper
*
* Entree : 
*	un repertoire
*	un tampon de reception
*
* Sortie :
*	rien
*
* Remarque :
*	Analyse un chemin et le complete par une fin de repertoire si besoin
*
**********************************/

VOID LibMakeReper	
		(
		IN		BYTE XPTR *		PathIn, 
		OUT	BYTE XPTR *		PathOut
		)
	{
	WORD				Index;
	BYTE XPTR *		PathInPtr;
	BYTE 				PathTmp[LGREP];
	BYTE XPTR *		EndOfPathOut = 0;

	PathInPtr = PathIn;
	LibNextOpt(&PathInPtr, &PathTmp[0]);

	/* PathTmp == path without leading spaces */

	if (PathTmp[0] == EOSTR) 
		{
		PathOut[0] = EOSTR;
		}
	else if ((Xstrcmp(PathTmp,".")) == 0)  
		{
		/* .\ */
		Xstrcpy(PathOut,".");
		Xstrcat(PathOut,DREP);
		}
	else 
		{
		Xfn_parser(PathTmp, &PathOut[0], FILE_DEVICE);
		if (PathOut[0] != EOSTR) 
			{
			if (PathOut[(WORD) (Xstrlen(PathOut)-1)] != (BYTE) SEPVOL[0])
				{
				Xstrcat(PathOut, SEPVOL);
				}
			}

		EndOfPathOut = &PathOut[Xstrlen(PathOut)];
		Xfn_parser( PathTmp, EndOfPathOut, FILE_PATH);
		if (PathOut[0] != 0) 
			{
			Index = (WORD) (Xstrlen(PathOut));
			
			if (PathOut[Index-1] != DELIMREP) 
				{
				if (PathOut[(WORD) (Index - 1)] != (BYTE) SEPVOL[0])
					Xstrcat(PathOut, DREP);
				}
			else 
				{
				if (Index > 1) 
					{
#ifdef prologue
					if (PathOut[Index-2] == SEPVOL[0])
						PathOut[Index-1] = EOSTR;
#endif
					}
/*
#ifdef msdos
				else 
					{
					if (PathOut[0] == DELIMREP)  
						Xstrcat(PathOut,DREP); 
					}
#endif
*/
				}
			}

		EndOfPathOut = &PathOut[Xstrlen(PathOut)];
		Xfn_parser( PathTmp, EndOfPathOut, FILE_NAME);
		
#ifdef prologue
		if (PathOut[0] != 0) 
			{
			if (Xstrlen(PathOut) == 3) 
				{
				if (
					(isascii(PathOut[0])) && 
					(isascii(PathOut[1])) && 
					(isdigit(PathOut[2]))
					) 
					{
					Xstrcat(PathOut, SEPVOL);
					return;
					}
				}
			}
#endif
		if ((Xstrcmp(PathTmp,"..")) == 0)  
			{
			Xstrcpy(PathOut,"..");
			}
		else	
			{
			WORD LastOfPathOutIndex = Xstrlen(PathOut) - 1;
			
			if (
				(PathOut[LastOfPathOutIndex] != (BYTE) DELIMREP) && 
				(PathOut[LastOfPathOutIndex] != (BYTE) SEPVOL[0])
				)
				{
				Xstrcat(PathOut,DREP);
				}
			}
		}
	}

/*********************************
* FCT LibNextOpt
*
* Entree : 
*	un pointeur sur le pointeur de la ligne d'argument		
*	un pointeur  sur la variable de reception de la prochaine option
*
* Sortie :
*	TRUE  : option recopie
*	FALSE : fin de la ligne d'argument
*
* Remarque :
*	retourne le prochain argument situe dans une chaine
* 
**********************************/

BOOL LibNextOpt(BYTE XPTR * XPTR * pp, BYTE XPTR * dest)
	{
	BYTE XPTR * lptr;

	*dest = '\0';
	/* pp pointeur courant de chaine */

	while (1) 
		{
		while ((*(*pp) == ' ') || (*(*pp) == TABUL) || (*(*pp) == ',') ) 
			{
			(*pp) ++; /* Skip des blancs et de la tabulation */
			}

		if ( (BYTE) *(*pp) == LF || (BYTE) *(*pp) == CR ) 
			{
			/* passage a la ligne suivante */
			lptr = (BYTE XPTR *) Xfgets
				((char *) GlobalArgLine,(WORD) 256,(FILE *) GlobalArgFile);

			if (lptr == GenericNULL(BYTE)) 
				{
				/* fin de fichier atteinte */
				*dest = EOSTR;
				 return(FALSE);
				}
			GlobalArgPtr = &GlobalArgLine[0];
			pp = &GlobalArgPtr;
			}
		else 
			{
			if (
				((BYTE) *(*pp) == (BYTE) EOSTR) || 
				((BYTE) *(*pp) == CTRL_Z) || 
				((BYTE) *(*pp) == LF) || 
				((BYTE) *(*pp) == CR)  
				) 
				{
			   *dest = EOSTR;
			   return(FALSE);
	
			  /* fin de la ligne de commande */
				}
			else 	
				{
				/* termine les tokens par un zero */
				char	StartQuote = 0;
				
				/* 
					Copy all string 
					when a quoted string is found, copy its content unchanged
					(including whites and ',')
				*/
				while 
					(
//					(*(*pp) != ' ' && 
//					((BYTE) *(*pp) != ',')
					(*(*pp) != EOSTR) && 
					((BYTE) *(*pp) != CR) && 
					((BYTE) *(*pp) != LF) 
					) 
					{
					char Car = *(*pp);
					char MustStore = TRUE;
					
					if (
						((Car == ' ') || (Car == ',')) &&
						(StartQuote == 0)
						)
						{
						/* white or ',' when not inside quote */
						break;
						}
					else if ((Car == '\'') || (Car == '"'))
						{
						if (StartQuote == Car)
							{
							/* Ending quote */
							MustStore = FALSE;
							StartQuote = 0;
							}
						else if (StartQuote == 0)
							{
							/* start quote */
							StartQuote = Car;
							MustStore = FALSE;
							}
						else
							{
							/* ' inside " or vice-versa */
							/* store as usual */
							}
						}
					
					if (MustStore)
						{
						*dest++ = *(*pp);
						}
					(*pp) ++;
					}
	
				*dest = EOSTR;
				return(TRUE);
				}
			}
		}
	}
	
/*********************************
* FCT LibInitArg
*
* Entree : 
*	la ligne d'argument se trouve dans le fichier p
*	recopie de la ligne du fichier dans 		
*
* Sortie :
*	rien
* 
* Remarque :
*	Va chercher dans le fichier la suite de la ligne d'argument
*
**********************************/

BOOL LibInitArg (BYTE XPTR * FileName, BYTE XPTR * ArgBuffer)

/*	initialisations de la ligne de commande dans un fichier 
 *	a partir du fichier designe par la chaine 'FileName'
 */
	{					/* init_arg */
	BYTE *	lptr;
	BYTE 		FullPath[LGREP];
/*
	FILE *farg;
*/
	FullPath[0] = EOSTR;
	XstrCpySize(FullPath,(BYTE *) FileName,sizeof(FullPath));

	GlobalArgFile = Xfopen(FullPath,"r");
	if (GlobalArgFile == GenericNULL(FILE)) 
		{
		EcranSetLastFileAccessed(FullPath);
		EcranWarningFichier(FullPath);
		THROW(ErreurNoyau01);
		}

	lptr = (BYTE XPTR *) Xfgets((char *) ArgBuffer,(WORD) 256,(FILE *) GlobalArgFile);
	if (lptr == GenericNULL(BYTE)) 
		{
		EcranSetLastFileAccessed(FullPath);
		THROW(ErreurNoyau01);
		}
		
#ifdef merde
	/* enlever le dernier 0a */
	ArgBuffer[Xstrlen(ArgBuffer) - 1] = EOSTR;
#endif

	return (TRUE);
	}					/* init_arg */

/*********************************
* FCT LibGetNomFic
*
* Entree : 
*	un nom de fichier
*	une chaine pour le resultat
*	une extension 
*	un repertoire destination par defaut
*
* Sortie :
*	rien
*
* Remarque :
*	Force l'extension au nom de fichier passe en argument
*	Tient compte du rerpertoire par defaut si le nom en entree ne
*	possede de repertoire
*
**********************************/

VOID LibGetNomFic 
	(
	IN		BYTE XPTR * PathFile, 
	OUT	BYTE XPTR * Buffer, 
	IN		BYTE XPTR * Extension, 
	IN		BYTE XPTR * DestinationFullPath
	)
/*	construit la designation d'un fichier en tenant compte de l'extension
 *	fournie par 'Extension'. retourne 'TRUE' si cette extension a ete ajoutee.
 */
 
 /*
 	PathFile = c:\titi\tutu\toto
	Buffer = ...
	Extension = .o
	DestinationFullPath = d:\tata\tito\
	
	Buffer --> c:\titi\tutu\toto.o
 */
 
{					/* getnomfic */
//JPH	BYTE XPTR * p = Buffer;
/* JPH: replaced LGMXNOM by LGREP*/
	BYTE Path [LGREP];							/* pour l'extension */
	BYTE DestinationPath [LGREP];			/* pour l'extension */
	BYTE PathFileCopy	[LGREP];
	char * EndOfBuffer = 0;
	char * File = Path; 					/* Same memory, another name */
	char * NewExtension = Path; 		/* Same memory, another name */
		
	Buffer[0] = EOSTR;

//ODS_("Entree LibGetNomFic : PathFile=");
//ODS_(PathFile);
/*ODSsz_(", Buffer=%s",Buffer);*/
//ODSsz_(", Extension=%s", Extension);
//ODS_ (", DestinationFullPath=");
//ODS(DestinationFullPath);

#ifdef vms
/*
	vms$sliste(PathFile);
	vms$nliste(PathFileCopy);
*/
	XstrCpySize(PathFileCopy,PathFile,sizeof(PathFileCopy));
#else
	XstrCpySize(PathFileCopy,PathFile,sizeof(PathFileCopy));
#endif

	Xfn_parser (PathFileCopy, Path, (FILE_NETWORK_NODE | FILE_DEVICE | FILE_PATH));
	Xfn_parser (DestinationFullPath, DestinationPath, (FILE_NETWORK_NODE | FILE_DEVICE | FILE_PATH));
//ODS_("PathFileCopy=");
//ODS_(PathFileCopy);
//ODS_(", tmp=");
//ODS_(Path);

	if ((Path[0] == EOSTR) && (DestinationPath[0] != EOSTR)) 
		{
		/* Path empty, DestinationPath not empty */
//ODS_("Avant Path=");
//ODS(Path);
//
		Xstrcpy(Path, DestinationPath);
//ODS_("Après Path=");
//ODS(Path);
		}

	/* Buffer == c:\xxxx\yyy */
	LibMakeReper(IN Path, OUT Buffer);
//ODS_("Path=");
//ODS(Path);
//ODS_(", Buffer=");
//ODS(Buffer);

	/* Test si nom present dans le repertoire si oui */
	Xfn_parser( DestinationFullPath, File, FILE_NAME );
	if ( File[0] != EOSTR) 
		{
		/* Destination directory contient un nom */
		Xstrcpy( Buffer, DestinationFullPath );
		}
	else
		{
		/* Ajoute le nom du fichier aux resultat */
		EndOfBuffer = &Buffer[Xstrlen(Buffer)];
		Xfn_parser(PathFileCopy,EndOfBuffer,FILE_NAME);
		}

//ODS_("PathFileCopy=");
//ODS(PathFileCopy);
//ODS_(", Buffer=");
//ODS(Buffer);


/*
	??? JPH Que se passe-t-il si il existe deja une extension ???

*/
	/* Ajoute extension */
	NewExtension[0] = SEPTYP;
	NewExtension[1] = EOSTR;
	Xstrcat(NewExtension,Extension);
	Xstrcat(Buffer,NewExtension);

	/* Ajoute pw etc. */
	EndOfBuffer = &Buffer[Xstrlen(Buffer)];
	Xfn_parser(PathFileCopy,EndOfBuffer,(FILE_PROLOGUE_PW | FILE_VMS_VERSION));

//ODS_("Sortie LibGetNomFic : PathFile=");
//ODS(PathFile);
//ODS_(", Buffer=");
//ODS(Buffer);
//ODSsz_(", Extension=%s", Extension);
//ODS_ (", DestinationFullPath=");
//ODS(DestinationFullPath);
	}

/*********************************
* FCT LibBinToLong
*
* Entree :
*	un int non signe
*
* Sortie :
*	un long non signe
*
* Remarque :
*	Convertion WORD -> LONG
*
**********************************/

LONG LibBinToLong( WORD b)

/*	affecte une valeur WORD a un long, en eliminant
 *	le signe eventuel
 */
{					/* bintolong */
	//JPH: replaced ULONG l;
	LONG l;

	//JPH: replaced l = (ULONG) b;
	l = (LONG) b;
	if (l < 0)
		l += MXINT;
	return (l);
}					/* bintolong */


char * XstrCpySize(char * To, char * From, int MaxLength)
	{
	char * Result = strncpy(To,From,MaxLength);

if (MaxLength<9)
	{
	//ODSu("XstrCpySize, maxlength < 9 : %d",MaxLength);
	}

	To[MaxLength-1]='\0';	/* Always an terminator ! */

	return Result;
	}
