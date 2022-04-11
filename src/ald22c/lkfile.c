/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 1992, 1993
 *	Module  : T-CODE
 *	Fichier : LKFILE.C
 *	Version : 2.0a
 *	Date    : 23/05/93
 *	Systeme : Tous
 *
 *	Gestion Fichier des acces de fichier
 *
 *	[Noyau TCode- Gestion de fichier]
 *
 */

/* --------------------------------------------------------------------------
 * Mises a jour :
 * ------------
 *	11/01/93 : Debut du codage
 *
 */

/* Inclusions importees et privees */
/* Inclusions exportees et privees */


#define _LKFILE

#include "aldtype.h"
#include "lkfile.h"
#include "lkmes.h"
#include "lkstruct.h"

//JPH
#include "lkecran.h"
#include "lklib.h"

// YT modif
#ifndef _DOS //SAP
#ifndef PRL //SAP
#ifdef WIN_BRUNO_DARR
#ifdef WIN32
	#define open(f,r,o) open(f,r)
	#define close(h) close(h)
	#define read(h,b,l) read(h,b,l)
	#define write(h,b,l) write(h,b,l)
	#define lseek(h,o,w) lseek(h,o,w)
#else
	#define open(f,r,o) lopen(f,r)
	#define close(h) lclose(h)
	#define read(h,b,l) lread(h,b,l)
	#define write(h,b,l) lwrite(h,b,l)
	#define lseek(h,o,w) llseek(h,o,w)
#endif
#endif
#endif
#endif	//SAP


#ifdef DBGTRC
	extern FILE * fdbgtrc;
#endif

/*T*******************************
*	Fonction d'acces au T-Code 
*
* 	FileInit
* 	FileOpen
* 	FileResultOpen
* 	FileClose
* 	FileDestroy
* 
* 	FileIsEmpty
* 	FileGetReloc
* 	FileGetNumBloc
* 	FileGetOffset
* 	FilePutBlocOfst
* 	FileWriteBlocForce
* 	FileCopyBloc
* 	FilePositBloc
* 	FileSeekBloc
* 	FileReadBloc
* 	FileWriteBloc
* 	FilePurge
*	FileEndBloc
* 
* 	FileGetString
* 	FileGetStringLg
* 	FileGetBloc
* 	FileGetByte
* 	FileGetBin
* 	FilePutByte
* 	FilePutBin
* 	FilePutStringLg
* 	FilePutString
*	FileXopen
*	FileSeek
*	FileRead
*	FileWrite
*
*/


/*
XTWopen(f) FileXopen( (O_CREAT | O_TRUNC | O_RDWR | O_BINARY), (WORD) (S_IREAD | S_IWRITE))
XTRopen(f) FileXopen( (O_RDONLY | O_BINARY), (WORD) 0)

*/

#ifdef __WALD__
#include <sys\stat.h>

void AttemptToForceReadWrite(ctConstStr FilePath, int typ, int mod)
	{
	if ((typ & O_RDWR) || (typ & O_WRONLY))
		{
		// must write
		if (_access(FilePath,2) != 0)
			{
			// dont have write access
			// Try change mode to force read/write
			//ODS_("AttemptToForceReadWrite(");
			//ODS_(FilePath);
			//ODS(")");
			chmod(FilePath,S_IWRITE);
			}
		}
	}
#endif

/*********************************
*
* FCT FileInit
*
* Entree : 
*	structure fichier Tabfic a initialiser
*	le nom du fichier pour la destruction
*	le type d'acces (LECTURE ou ECRITURE)
*	Pointeur sur une structure d'entete
*			
* Sortie :
*	rien
*
* Remarque :
*	initialise la structure d'un fichier
*	Tabfic
*
* Voir aussi:
* 	Init_bloc
*
**********************************/

VOID FileInit( fic, nom, typ, ent)
Tabfic XPTR * 	fic;
BYTE XPTR * 	nom;
BYTE 		typ;
Entete XPTR * 	ent;
{
//JPH	BYTE XPTR * p;

//Debug int Ret = FileSameContent("CopieDeEssai.o", "CopieDeEssai.dbo");

	fic->nl 	= 0;	/* numero logique a zero (ferme) */
	fic->bloc 	= 0;
	fic->ofst 	= 0;
	if (typ == LECTURE)	{
		fic->inf = MOINS_UN; /*force la premiere lecture */
	}
	if (typ == ECRITURE) 	fic->inf = 0;
	fic->sup  	= 1;
	fic->lg_read 	= LGBLOC;
	fic->type    	= typ;
	fic->reloc_bloc  = 0;
	fic->ent	= ent;

	fic->FieldM	= FALSE;
	fic->FieldE	= FALSE;
	fic->FieldV	= FALSE;

	XstrCpySize(fic->nom,nom,sizeof(fic->nom));

	Init_bloc( fic->buffer );
}

/*********************************
*
* FCT FileOpen 
*
* Entree : 
*	une structure de fichier Tabfic
*		
* Sortie :
*	rien
*
* Remarque :
*	Allocation du tampon de bufferisation + ouverture
*	Si l'ouverture echoue, appel de la fonction Erreur
*	avec le numero de message ErreurNoyau02
*	" Acces fichier impossible "
*
* Voir aussi :
*	Erreur, FileXopen
*
**********************************/

VOID FileOpen( fic )
Tabfic XPTR * fic;
{

	if (fic->nl == 0) {
		EcranEnCours( fic->nom );

		/* Ouverture du fichier */
		if ( fic->type == LECTURE ) 
			fic->nl = XTRopen( fic->nom );
		else 	
			fic->nl = XTWopen( fic->nom );
	}
}

//SP
/*********************************
*
* FCT FileResultOpen
*
* Entree : 
*	fichier existant	
*	fichier resultat a ouvrir	
* Sortie :
*	rien
*
* Remarque :
*	Ouverture d'un fichier avec les droits d'acces du fichier
*	passe en premier parametre
*
* Voir aussi :
*	FileWriteBlocForce , FileXopen
*
**********************************/

VOID FileResultOpen( fic, fic_res )
Tabfic XPTR * fic;
Tabfic XPTR * fic_res;
{
#ifdef unix
	struct stat buf;
	struct stat buf1;
	stat( fic->nom, &buf );
	if (stat(fic_res->nom, &buf1)) {
		chmod( fic_res->nom, buf.st_mode );
		fic_res->nl = XTWopen( fic_res->nom );
		}
	else 	{
		fic_res->nl = XTWopen( fic_res->nom );
	/*fic_res->nl = Xcreat_mode( fic_res->nom );*/
		}
#else
		fic_res->nl = XTWopen( fic_res->nom );
#endif	
	/* ecrit le secteur d'entete */

	fic_res->bloc = 0;
	fic_res->ofst = 0;
	FileWrite( fic_res, fic_res->buffer, LGBLOC );
}

/*********************************
*
* FCT FileClose
*
* Entree : 
*	un pointeur sur une structure d'un fichier Tabfic
*		
* Sortie :
*	rien
*
* Remarque :
*	Fermeture d'un fichier plus liberation des buffer associes
*
* Voir aussi :
*	XTclose
**********************************/

VOID FileClose( fic )
Tabfic XPTR * fic;
{
	if (fic->nl != 0) {
		XTclose(fic->nl);
#ifdef unix
		liberlox(fic->nom);
#endif
	}
	fic->nl = 0;
}

/*********************************
*
* FCT FileDestroy
*
* Entree : 
*	un pointeur sur une structure d'un fichier Tabfic 
*
* Sortie :
*	rien
*
* Remarque :
*	fermeture d'un fichier plus sa destruction physique
*
* Voir aussi :
*	FileClose , Xunlink
**********************************/

VOID FileDestroy( fic )
Tabfic XPTR * fic;
{

	/* Fermerture du module */
	FileClose( fic );
	
	/* destruction du fichier */
	Xunlink(fic->nom);
}

/*********************************
*
* FCT FileIsEmpty
*
* Entree : 
*	un fichier 
*		
* Sortie :
*	TRUE : le fichier est vide
*	FALSE: le fichier n'est pas vide 
*
* Remarque :
*	Test si le fichier est vide ou non	
*
* Voir aussi :
*
**********************************/
BOOL FileIsEmpty( fic )
Tabfic XPTR * fic;
{
	if (fic->bloc == 0 && fic->ofst == 0)
		return( TRUE );
	
	return( FALSE );
}

/*********************************
*
* FCT FileGetReloc 
*
* Entree : 
*	un fichier
*		
* Sortie :
*	la valeur en octet de l'offset courrant dans le fichier
*
* Remarque :
*	utilise pour recuperer l'adresse d'un nouveau descrificeur
*
* Voir aussi :
*
**********************************/

WORD FileGetReloc( fic )
Tabfic XPTR * fic;
{
	fic->inf = fic->reloc_bloc;
	fic->sup = fic->inf;

	return( fic->reloc_bloc );
}

/*********************************
*
* FCT FileGetNumBloc 
*
* Entree : 
*	un fichier		
* Sortie :
*	le numero de secteur courrant 
*
* Remarque :
*	utilise pour connaitre le numero de secteur ou va etre
*	transfere une table ou un code 
*
* Voir aussi :
*
**********************************/

WORD FileGetNumBloc( fic )
Tabfic XPTR * fic;
{
	return( fic->bloc );
}

/*********************************
*
* FCT FileGetOffset 
*
* Entree : 
*	un fichier		
* 
* Sortie :
*	retourne l'offset courrant dans le secteur courrant
*
* Remarque :
*	util pour sauvegarder un positionnement dans le parcours
* 	d'une table
*
* Voir aussi :
*
**********************************/
WORD FileGetOffset( fic )
Tabfic XPTR * fic;
{
	return( fic->ofst );
}


/*********************************
*
* FCT FilePutBlocOfst 
*
* Entree : 
*	un fichier
*	numero de secteur
*	offset dans le secteur
*		
* Sortie :
*	rien
*
* Remarque :
*	se repositonne dans une table
*	pour rependre le parcours 
*
* Voir aussi :
*
**********************************/

VOID FilePutBlocOfst( fic , bloc, ofst)
Tabfic XPTR * 	fic;
WORD		bloc;
WORD		ofst;
{
	fic->bloc = bloc;
	fic->ofst = ofst;

}

/*********************************
*
* FCT FileGetString 
*
* Entree : 
*	un fichier
*	une chaine a mettre a jour
*		
* Sortie :
*	rien
*
* Remarque :
*	extraction d'un fichier une chaine de charactere se terminant par NULL
*
*
* Voir aussi :
*	FileGetByte
*
**********************************/

VOID FileGetString( fic, nom)
Tabfic XPTR * 	fic;
BYTE XPTR * 	nom;
{
	do {
		*nom = FileGetByte( fic );
	}
	while (*nom++);
}

/*********************************
*
* FCT FileGetStringLg
*
* Entree : 
*	un fichier
*	une chaine resultat a mettre a jour
*	une longeur
*		
* Sortie :
*	rien
*
* Remarque :
*	Extraction d'un fichier d'une chaine de charactere d'une longueur
*	donnee
*	L'extraction force la chaine en majuscule
*	(sert pour l'extraction du nom de module dans l'entete)
*	
* Voir aussi :
*	FileGetByte
*
**********************************/

VOID FileGetStringLg( fic, nom, lg)
Tabfic XPTR * 	fic;
BYTE XPTR * 	nom;
WORD 		lg;
{
	BYTE c;

	PRECOND( fic != GN( Tabfic ) );

	lg--;
	while (lg) {
		c = FileGetByte(fic); lg--;
		if (c == ' ') 
			*nom++ = EOSTR;
		else 	
			*nom++ = toupper(c);
	}
	*nom = EOSTR;
}

/*********************************
*
* FCT FileGetBloc
*
* Entree : 
*	un fichier en lecture
*	un fchier en ecriture
*	nombre de bloc (de LGBLOC 256 )
*	
* Sortie :
*	rien
*
* Remarque :
*	Extraire un bloc d'un fichier pour 
* 	le transferer dans un autre
*	le transfert se fait octet par octet
*
* Voir aussi :
*	FileSeekBloc, FileRead
*
**********************************/

VOID FileGetBloc( source_fic, target_fic, nb)
Tabfic XPTR * 	source_fic;
Tabfic XPTR * 	target_fic;
WORD 		nb;
{
  	if ((source_fic->bloc != nb) || (source_fic->inf == MOINS_UN)) {
		FileSeekBloc(source_fic,nb);
		FileReadBloc(source_fic,target_fic,nb);
		}
	else 	{
		if (source_fic != target_fic) {
			Xmemcpy(target_fic->buffer, source_fic->buffer, LGBLOC);
			}
		}
	target_fic->ofst = 0;
	if (target_fic == source_fic) {
		target_fic->bloc = nb; /* Affiche le bloc lu */
		}
}
/*********************************
*
* FCT FileCopyBuf
*
* Entree : 
*	fichier source
*	fichier destination
*	numero de bloc
*	longueur en octet
*		
* Sortie :
* 	rien
*
* Remarque :
*	transfert rapide par buffer
*	suppose le fichier destination bien positionne
*
* Voir aussi :
*	FileRead, FileWrite
*
**********************************/

VOID FileCopyBuf( source_fic, target_fic, bloc, lg)
Tabfic XPTR * 	source_fic;
Tabfic XPTR * 	target_fic;
WORD 		bloc;
WORD  		lg;
{
	WORD nbbuf;
	WORD reste;
	WORD i;

	WORD reste256;
	
	FileSeek( source_fic, bloc);
	nbbuf =  lg / LGBUF;
	reste = lg - ( nbbuf * LGBUF );
	for (i=0; i < nbbuf; i++) {
		FileRead( source_fic, source_fic->tmp, LGBUF );
		FileWrite( target_fic, source_fic->tmp, LGBUF );
	}
	
	if ( reste )  {
		reste = (reste + LGBLOC - 1) / LGBLOC;
		reste256 = reste * 256;
		FileRead( source_fic, source_fic->tmp, reste256 );
		FileWrite( target_fic, source_fic->tmp, reste256 );		
	}
}

/*********************************
*
* FCT FileGetByte
*
* Entree : 
*	un fichier
*
* Sortie :
*	un octet non signe
*
* Remarque :
*	Extraction d'un octet a partir d'un fichier
*
* Voir aussi :
*	FileGetBloc
*
**********************************/

BYTE FileGetByte( fic )
Tabfic XPTR * fic;
{
	BYTE b;

	if (fic->ofst == LGBLOC) {
		FileGetBloc(fic, fic, (WORD) (fic->bloc+1));
	}

	b = fic->buffer[fic->ofst++];

	return(b);
}

/*********************************
*
* FCT FileGetBin 
*
* Entree : 
*	un fichier		
* Sortie :
*	un entier non signe
*
* Remarque :
*	Extraction d'un WORD a partir d'un fichier
*
* Voir aussi :
*	FileGetByte
*
**********************************/

WORD FileGetBin( fic )
Tabfic XPTR * fic;
{
	WORD b;

	b =  (WORD) ((FileGetByte(fic)) & 0x00ff);
	b |= (WORD) (FileGetByte(fic) << 8) & (WORD) 0xff00;
	
	return(b);

}

/*********************************
*
* FCT FilePutByte 
*
* Entree : 
*	un fichier
*	un octet non signe
*		
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'un octet non signe dans un fichier
*
* Voir aussi :
*	FileWrite
*	
**********************************/

VOID FilePutByte( fic, val )
Tabfic XPTR * 	fic;
BYTE 		val;
{


	fic->buffer[fic->ofst++] = val;

	if (fic->ofst == LGBLOC) {
		FileWriteBlocForce(fic);
	}
}

/*********************************
*
* FCT FilePutBin
*
* Entree : 
*	un fichier
*	un entier non signe	
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'un entier non signe dans un fichier
*
* Voir aussi :
*	FilePutBin
*
**********************************/

VOID FilePutBin( fic, val )
Tabfic XPTR * 	fic;
WORD 		val;
{
	BYTE tb;

	tb = (BYTE) SECOND_BYTE( val );
	FilePutByte(fic,tb);
	tb = (BYTE) FIRST_BYTE( val );
	FilePutByte(fic,tb);
}

/*********************************
*
* FCT FilePutStringLg 
*
* Entree : 
*	un fichier		
*	une chaine
*	une longueur
*
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'une chaine de characteres dans un fichier sur une longueur
*	donnee
*	(sert pour ecrire le nom du module dans l'entete)
*
* Voir aussi :
*	FilePutByte	
*
**********************************/

VOID FilePutStringLg( fic, s, l)
Tabfic XPTR * 	fic;
BYTE XPTR * 	s;
WORD 		l;
{
	BYTE c;
	l--;
  	while(l) {
		c = *s ++; 
		if (c == EOSTR) c = ' ';
	
		FilePutByte(fic,(BYTE) c); l--;
	}
}

/*********************************
*
* FCT FilePutString 
*
* Entree : 
*	un fichier
*	un pointeur sur une chaine 
*		
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'une chaine se terminant par EOSTR dans un fichier
*
* Voir aussi :
*	FilePutByte
*
**********************************/

VOID FilePutString( fic, s )
Tabfic XPTR * 	fic;
BYTE XPTR * 	s;
{
  	while(*s) {
		FilePutByte(fic,(BYTE) *s++); 
	}
	FilePutByte(fic, (BYTE) EOSTR);
}
	
/*********************************
*
* FCT FileWriteBlocForce
*
* Entree : 
*	un fichier
*		
* Sortie :
*	rien
*
* Remarque :
*	Ecriture du secteur courrant dans le fichier
*	OBLIGATOIRE apres un transfert non modulo 256
*	voir la fonction FileCopyBloc
*
* Voir aussi :
* 	FilePurge, FileWrite, Init_bloc
*
**********************************/

VOID FileWriteBlocForce( fic )
Tabfic XPTR * fic;
{
 	if (fic->bloc < fic->inf || fic->bloc >= fic->inf + LGBUF/LGBLOC) {
		if ( fic->inf != MOINS_UN ) {
			FilePurge(fic);
		}
		fic->inf = fic->bloc;
		fic->sup = (WORD) (fic->inf + 1);
	}

	FileWriteBloc(fic);

	if (fic->sup == fic->bloc) {

		fic->sup ++;
	}
	fic->ofst = 0;
	fic->bloc++;
}

/*********************************
*
* FCT FileCopyBloc
*
* Entree : 
*	fichier source
*	fichier destination
*	longueur en octet
*		
* Sortie :
* 	rien
*
* Remarque :
*	transfert un bloc d'un fichier vers un autre
*
* Voir aussi :
*	FilePutByte, FileGetByte
*
**********************************/

VOID FileCopyBloc( source_fic, target_fic, lg)
Tabfic XPTR * 	source_fic;
Tabfic XPTR * 	target_fic;
WORD  		lg;
{
	while (lg--) {
		FilePutByte( target_fic,(BYTE) FileGetByte(source_fic) );
	}
}

/*********************************
*
* FCT FilePositBloc
*
* Entree : 
*	un fichier
*	numero de secteur
*		
* Sortie :
*	rien
*
* Remarque :
*	Se positionner sur un numero de secteur
*
* Voir aussi :
*	FileSeekBloc
*
**********************************/

VOID FilePositBloc( fic, num_bloc )
Tabfic XPTR * fic;
WORD num_bloc;
{
	FileSeekBloc( fic, num_bloc);

	fic->ofst = 0;
	fic->bloc = num_bloc;
}

/*********************************
*
* FCT FileSeekBloc
*
* Entree : 
*	un fichier
*	un offset en numero de secteur
*		
* Sortie :
*	rien
*
* Remarque :
*	fonction de bas niveau pour se positionner sur un secteur
*	En cas d'erreur d'acces fichier appel de la fonction
*	Erreur avec un degre de gravite FATAL
*	Erreur numero ErreurNoyau02 : "Acces fichier impossible"
*
* Voir aussi :
*	FilePurge, FileSeek, FileRead
*
**********************************/

VOID FileSeekBloc( fic, off )
Tabfic XPTR * 	fic;
WORD 		off;
{
//JPH	WORD val_ret;
//JPH	ULONG loff, ret_seek;

	if (fic->inf > off || off > fic->sup || off == fic->inf + LGBUF/LGBLOC || fic->lg_read != LGBLOC) {
		FilePurge( fic );
		FileSeek( fic, off );
		FileRead( fic, fic->tmp, fic->lg_read );
		fic->inf = off;
		fic->sup = (WORD) (off + fic->lg_read / LGBLOC);
	}	
	else {		/* Le secteur a lire se trouve entre inf et sup */
		if (fic->sup == off) {
			FileSeek( fic, off );
			FileRead(fic, (BYTE XPTR *) &fic->tmp[(off - fic->inf) * LGBLOC], LGBLOC );
			fic->sup ++;
		}
		
	}

	fic->bloc = off;
	fic->ofst = 0;
}

/*********************************
*
* FCT FileReadBloc
*
* Entree : 
*	un fichier pour la lecture
*	un fichier pour recevoir la leccture
*	numero de secteur a lire
*	
* Sortie :
*	rien
*
* Remarque :
*	lecture d'un secteur
*	transfert d'un secteur du tampon de lecture dans le secteur courrant
*
* Voir aussi :
*	Xmemcpy
*
**********************************/

VOID FileReadBloc( fic, des, bloc)
Tabfic XPTR * 	fic;
Tabfic XPTR * 	des;
WORD 		bloc;
{
	Xmemcpy(des->buffer, &fic->tmp[ ((bloc - fic->inf) * LGBLOC)], LGBLOC);
}


/*********************************
*
* FCT FileWriteBloc
*
* Entree : 
*	un fichier
*		
* Sortie :
*	rien
*
* Remarque :
*	Mise en correspondance du secteur de travail (buffer) et
*	le 'cache' du fichier (tmp)
*
* Voir aussi :
*	Xmemcpy
*
**********************************/

VOID FileWriteBloc( fic )
Tabfic XPTR * fic;
{
	Xmemcpy(&fic->tmp[((fic->bloc - fic->inf) * LGBLOC)] , fic->buffer, LGBLOC);
}

/*********************************
*
* FCT FilePurge 
*
* Entree : 
*	un fichier		
* Sortie :
*	rien
*
* Remarque :
*	ecriture du cache (tmp) dans le fichier (sur disque)
*	- Pas de purge pour les fichiers en lecture 
*	- En cas d'erreur d'acces fichier appel de la fonction
*	  Erreur avec un degre de gravite FATAL
*
* Voir aussi :
*	FileOpen, FileSeek, FileWrite
*	
**********************************/

VOID FilePurge( fic )
Tabfic XPTR * fic;
{
//JPH	BYTE nom[LGMXNOM];
//JPH	ULONG depl;
	
//JPH	WORD  val_ret;
	
	if (fic->type == ECRITURE) {  
		/* Ouvrir les fichiers */

		if (fic->nl == 0) {
			FileOpen( fic );
		}

		FileSeek( fic, fic->inf );
		FileWrite(fic, &fic->tmp[0],(WORD) ((fic->sup - fic->inf) * LGBLOC));
	}
}

/*********************************
*
* FCT FileEndBloc
*
* Entree : 
*	un fichier		
* Sortie :
*	rien
*
* Remarque :
*	Padding de la fin de bloc a 0xff
*	Force l'ecriture du bloc
*	Force l'ecriture du buffer sur disque
*
* Voir aussi :
*	FileGetOffset, FilePurge, FilePutByte
*	
**********************************/

VOID FileEndBloc( fic )
Tabfic XPTR * fic;
{
	WORD off;


	for (off = FileGetOffset(fic); off < LGBLOC; off ++) {
		FilePutByte( fic, 0xff );
	}

	FilePurge( fic );
}

/********   Gestion de fichier de bas niveau ********************************

	/* 	fonctions d'ouverture des fichiers	*/
	/*	----------------------------------	*/

/*********************************
*
* FCT FileXfopen 
*
* Entree : 
*	nom de fichier
*	type d'ouverture
*	mode d'acces
*		
* Sortie :
*	si OK 		: numero logique donnee par le systeme 
*	si non OK 	: MOINS_UN
*
* Remarque :
*	Ouverture de fichier buffurise
*
* Voir aussi :
*	Access  
**********************************/

FILE * FileXfopen(nomfic)

/*	Ouverture d'un fichier par 'fopen', en demandant son exclusivite
 *	pour une exploitation 'multi-utilisateurs' sans suppression
 *	sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */
BYTE *nomfic;
{					/* Xfopen */
	int resac;

	/* Teste le fichier en mode partageable.
	 * Si l'acces est possible, c'est que le fichier existe
	 * et n'est pas bloque en mode exclusif.
	 */
	char * ShortPathName = TranslateLongPathName(nomfic);

	resac = Xaccess(ShortPathName,0);
	return
		(
		resac == 0 
		? fopen(ShortPathName,"r") 
		: GenericNULL(FILE)
		);
}

/*********************************
*
* FCT FileXopen 
*
* Entree : 
*	nom de fichier
*	type d'ouverture
*	mode d'acces
*		
* Sortie :
*	si OK 		: numero logique donnee par le systeme 
*	si non OK 	: MOINS_UN
*
* Remarque :
*	Ouverture de fichier non buffurise
*
* Voir aussi :
*	Access  
**********************************/


SWORD FileXopen( nomfic, typ, mod )
BYTE XPTR * 	nomfic;
WORD 		typ;
WORD 		mod;

/*	Ouverture d'un fichier par 'open', en demandant son exclusivite
 *	pour une exploitation 'multi-utilisateurs' sans suppression
 *	sauf si ouverture en mode lecture seule sous Amenesik / Sologic.
 */

{					/* Xfopen */
	SWORD 	fh;
	char *	FilePath = TranslateLongPathName(nomfic);

#ifdef	unix
	SWORD resac;
#endif

	EcranSetLastFileAccessed(FilePath);
	AttemptToForceReadWrite(FilePath, typ, mod);

#ifdef unix
	/* Pour ald tous les fichiers sont ouvert en mode exlusif */

	/* Teste le fichier en mode exclusif.
	 * Si l'acces est possible, le fichier existe et n'est pas
	 * ouvert (ni en mode partageable ni en mode exclusif).
	 * Si l'access n'est pas possible, soit le fichier existe
	 * et ne peut pas passer en mode exclusif, soit le fichier
	 * n'existe pas et il faut le creer puis le bloquer en exclusif.
	 */
	resac = Access(FilePath,0,1);
	if (resac != 0 && mod != 0 ) { /* et acces en ecriture */
		if (errno != ENOENT) 
			{
			EcranWarningFichier(nomfic);
			THROW( MessagePartage ); /* fichier non partageable */
			}

		/* cree le fichier puisqu'inexistant */
		fh = open(FilePath, typ, mod);
		if ( fh == (SWORD) MOINS_UN )
			{
			EcranWarningFichier(FilePath);
			THROW( ErreurNoyau02 );
			}

		/* retente un blocage du fichier */
		resac = Access(nomfic,0,1);
		if (resac != (SWORD) 0) {
			XTclose(fh);
			return(MOINS_UN);
		}
		else
			return(fh);
	}
#endif

	
	fh = (SWORD) (open(FilePath, (int) typ, (int) mod));

#ifdef msdos
/*	pas d'exclusivite sous DOS	*/
#endif

#ifdef vms
	if (fh == (SWORD) MOINS_UN) {
		traitfilerror(0, errno);
		if (errno == 44) {
			THROW( partage );
		}
		fh = EOF;
	}

#endif
	if (fh == (SWORD) MOINS_UN ) 
		{
		/* Ouverture impossible */
		EcranWarningFichier(FilePath);
		THROW( ErreurNoyau02 );
		}

	EcranSetLastFileAccessed("");
	return (fh);
}

/*********************************
*
* FCT FileSeek
*
* Entree : 
*	un fichier
*	un offset en numero de secteur
*		
* Sortie :
*	rien
*
* Remarque :
*	fonction de bas niveau pour se positionner sur un secteur
*	En cas d'erreur d'acces fichier appel de la fonction
*	Genere une exception de numero ErreurNoyau02
*	Erreur numero ErreurNoyau02 : "Acces fichier impossible"
*
* Voir aussi :
*	bintolong, XTseek
*
**********************************/

VOID FileSeek( fic, off )
Tabfic XPTR * 	fic;
WORD		off;
{
//JPH	SWORD val_ret;
	LONG loff, ret_seek;

	PRECOND( fic->nl != MOINS_UN );

	loff = (LONG) off * (LONG) LGBLOC;

	ret_seek = XTseek(fic->nl,loff);

	if (ret_seek == -1L) 
		{
		EcranSetLastFileAccessed(fic->nom);
		EcranWarningFichier(fic->nom);
		THROW( ErreurNoyau02 ); 
		}

	fic->bloc = off;
	fic->ofst = 0;

}

/*********************************
*
* FCT FileWrite
*
* Entree : 
*	un fichier pour l'ecriture
*	un buffer a ecrire sur disque 
*	une longueur d'ecriture
*	
* Sortie :
*	rien
*
* Remarque :
*	Ecriture d'un buffer (buf) d'une longueur (lg) a partir
*	de la position courrante du fichier
*	On suppose que le fichier soit positionne en debut de secteur
*	( FileSeek )
*	En cas d'erreur Generation d'un exception de valeur 
*	( errnoy02 )	
*
* Voir aussi :
*	XTwrite
*
*/

VOID FileWrite(fic, buf, lg )
Tabfic XPTR * 	fic;
BYTE XPTR *	buf;
WORD 		lg;
{
	SWORD val_ret;

	PRECOND( fic->nl != MOINS_UN );

	if (lg == 0 ) return; /* purge d'une reloc non utilisee */

	val_ret = XTwrite(fic->nl, buf, lg);

	if (val_ret <  (SWORD) lg) 
		{
		EcranSetLastFileAccessed(fic->nom);
		EcranWarningFichier(fic->nom);
		THROW( ErreurNoyau02 ); 
		}

	fic->bloc += lg / LGBLOC;
	if (fic->bloc > fic->reloc_bloc) fic->reloc_bloc = fic->bloc;
}

/*********************************
*
* FCT FileRead
*
* Entree : 
*	un fichier pour la lecture
*	un buffer de reception 
*	une longueur de lecture
*	
* Sortie :
*	rien
*
* Remarque :
*	Lecture d'un buffer (buf) d'une longueur (lg) a partir
*	de la position courrante du fichier
*	On suppose que le fichier soit positionne en debut de secteur
*	( FileSeek )
*	En cas d'erreur Generation d'un exception de valeur 
*	( errnoy02 )	
*
* Voir aussi :
*	XTread
*
*/

VOID FileRead( fic, buf, lg )
Tabfic XPTR *	fic;
BYTE XPTR * 	buf;
WORD 		lg;
{
	SWORD val_ret;

/*
	PRECOND( fic->nl != MOINS_UN );
	PRECOND( lg != 0 );

*/

	/* lg doit etre multiple de 256 */

	if ( lg % 256 ) {
		/* si lg n'est pas multiple de 256 arrondi au 256 sup. */
		lg = LGBLOC * (( LGBLOC + lg ) / LGBLOC);
	}
	val_ret = XTread(fic->nl, buf, lg);

	if (val_ret < (SWORD) 0 ) 
		{
		EcranSetLastFileAccessed(fic->nom);
		EcranWarningFichier(fic->nom);
		THROW( ErreurNoyau02 ); 
		}
}
VOID FilePadding( fic )
Tabfic XPTR * fic;
{
	WORD i;
	WORD pad;

/*
#ifndef prologue
	return;
#else
*/

	if ( fic->nl == MOINS_UN) return;

	i = fic->reloc_bloc / ( LGBUF / LGBLOC );
	pad = ( i * (LGBUF/LGBLOC) ) + (LGBUF / LGBLOC );
	FileSeek( fic, fic->reloc_bloc );

	Init_bloc( fic->buffer );
	for (i = fic->reloc_bloc; i < pad; i++) { 
		FileWrite( fic, fic->buffer, LGBLOC );
	}

/*		
#endif
*/
}



char XPTR * TranslateLongPathName(char XPTR * LongPathName)
	{
	/*
		Translate the long path into DosCompatible short path.

		Beware: return must be used or copied immediately.
		This code is NOT reentrant because 
		there is not buffer to copy new value.

	*/


/*
	JPH note:

		la traduction ne semble pas necessaire,
		apparemment, les open et autres fopen reagissent bien aux long noms
		en 32 bits !!!

*/


	
	char * Result = LongPathName;

	#ifdef WIN32
		{
		static char Buffer[LGREP+1];
		DWORD Length = GetShortPathName
			(
			(LPCTSTR) LongPathName,		
			(LPTSTR) Buffer,				
			(DWORD) sizeof(Buffer)-1 	
			);

		if (Length)
			Result = Buffer;

		}
	#endif

	return Result;
	}

ctBoolean FileSameContent(char * FName1, char * FName2)
	{
	ctBoolean Result = TRUE;
	int Fh1, Fh2;
	int Flag = (O_RDONLY | O_BINARY);
	int Mod = 0;
	char Byte1, Byte2;
	int Ret1, Ret2;
	long Adr = 0;

	Fh1 = XTRopen(FName1);
	Fh2 = XTRopen(FName2);

	while (TRUE)
		{

		Ret1 = XTread(Fh1, &Byte1, 1);
		Ret2 = XTread(Fh2, &Byte2, 1);

		if (Byte1 != Byte2)
			{
			Result = FALSE;
			//ODS("diff");
			break;
			}

		if ((Ret1<=0) || (Ret2<=0))
			{
			if (Ret1 != Ret2)
				{
				Result = FALSE;
				//ODS("diff");
				}

			break;
			}

		Adr++;
		}

	XTclose(Fh1);
	XTclose(Fh2);

	return Result;
	}

