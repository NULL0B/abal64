// ***********************************************************************************************
// * Strm.h
// ***********************************************************************************************

#ifndef STREAM_H
#define STREAM_H

#include <stdio.h>
#include "IniLine.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CLine 
// CListLine
// 
// Liste chainée utilisée par CStreamLine pour représenter les lignes d'un fichier 
// avec leur caractéristiques.
// 
// Caractéristiques principales de la liste chainée :
// - Les éléments de la liste doivent être triés par ordre croissant d'offset
// - On accède à la liste par la tête ou par la fin.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
struct CLine
{
CLine*   Next;   
CLine*   Prev;
long     Offset; // Offset physique (binaire) dans le fichier
long     Lg;     // Longueur logique de la ligne, tenant compte de l'expansion des tabulations en espaces 
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class ClistLine
{
// *******************************************************************************************************
// - SECTION PUBLIQUE
// *******************************************************************************************************
public:

   // -----------------------------------------------------------------------------
   //  Construction / Destruction
   // -----------------------------------------------------------------------------
   ClistLine();
   virtual ~ClistLine();

   // -----------------------------------------------------------------------------
   //  Fabrication de la liste
   //  Les éléments doivent être triés par ordre croissant d'offset
   //  - ClearAll      : détruit la liste
   //  - InsertFromEnd : insert les éléments en les triant en cherchant à partir 
   //                    de la fin. Si l'offset existe déjà, la longueur est mise à jour
   //  - AddAtEnd      : Place un élément en queue de liste (c'est à l'appelant
   //                    de s'assurer que les éléments sont ordonnés)
   // -----------------------------------------------------------------------------
   void  ClearAll();
   void  AddAtEnd( long Offset, long Lg );
   void  InsertFromEnd( long Offset, long Lg );

   // -----------------------------------------------------------------------------
   //  Propriétés générales
   // -----------------------------------------------------------------------------
   inline BOOL  IsValid();
   inline long  GetLines();
	inline long  GetLinesMaxLg();

   // -----------------------------------------------------------------------------
   //  Recherche d'un élément pour définir l'élément courant
   // -----------------------------------------------------------------------------
   void  SetCurLineAtOffset( long Offset);  // Elément défini par Offset binaire
   void  SetCurLineAtLine( long Line);      // Elément défini par numéro de ligne
   void  SetCurLineAtBegin();               // 1er élément
   void  SetCurLineAtEnd();                 // Dernier élément

   // -----------------------------------------------------------------------------
   //  Consultation de celui-ci
   // -----------------------------------------------------------------------------
   long  GetCurLineOffset();                // Offset de début de ligne
   long  GetCurLineLg();                    // Longueur logique de la ligne
   long  GetCurLineLine();                  // Numéro de la ligne


// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:

   // --- Pointeurs d'élément
   CLine*   m_pFirst;      // Tête de liste
   CLine*   m_pLast;       // Queue de liste
   CLine*   m_pCur;        // Elément courant

   // --- Infos
   BOOL     m_IsNewError;  // Indique un pb d'allocation mémoire
   long     m_CurLine;     // Numéro de ligne de l'élément courant
   long     m_MaxLine;     // Nombre d'éléments de la liste 
   long     m_MaxLenLine;  // Taille de la plus grande ligne

   // --- Méthode internes
   CLine* _New( long Offset, long Lg );
   void _Link( CLine* pCur, CLine* pNew, BOOL IsAfter=TRUE );
   void _Unlink( CLine* pOld );
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CStreamBin
//
// Accès à des fichiers en mode binaire pour Windows, Twin, UseIt
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class CStreamBin
{
// *******************************************************************************************************
// - SECTION PUBLIQUE
// *******************************************************************************************************
public:

   // -----------------------------------------------------------------------------
   //  Construction / Destruction
   // -----------------------------------------------------------------------------
   CStreamBin();
   virtual ~CStreamBin();

   // -----------------------------------------------------------------------------
   //  Identification de la classe au moment de l'exécution
   //  Pour CStreamBin, renvoie 0
   // -----------------------------------------------------------------------------
   virtual short GetClassId() {return 0;}

   // -----------------------------------------------------------------------------
   //  Ouverture / Fermeture
   //  Valeurs de Flags :
   //    Existence du fichier :
   //       CE_F_CHK_NOEXIST , CE_F_CHK_EXIST , CE_F_NOCHK       
   //    Mode d'ouverture
   //        CE_F_R  , CE_F_W_NEW  , CE_F_W_APPEND       
   //        CE_F_RW , CE_F_RW_NEW , CE_F_RW_APPEND  
   // -----------------------------------------------------------------------------
   virtual short Open( const char* sFileName, WORD Flags );
   virtual short Close();
   virtual short Save();

   // -----------------------------------------------------------------------------
   //  Lecture / Ecriture
   //    Read et Write d'un octet  
   //    Read et Write d'un buffer
   // 
   //    Find d'un octet
   //    Find d'un buffer
   //    Find d'un octet appartenent à une collection d'octets
   //    Les méthodes de recherche se positionnent
   //       - sur l'octet ou le buffer trouvé (défaut)
   //       - après l'octet ou le buffer trouvé
   //       - à la fin du fichier si non trouvé 
   // -----------------------------------------------------------------------------
   virtual short Write( const unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Read ( unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Write( unsigned char c  );
   virtual short Read ( unsigned char* c );

   virtual short Find ( unsigned char c, BOOL SeekAfter=FALSE );
   virtual short Find ( const unsigned char* Buf, long LgBuf, BOOL SeekAfter=FALSE );
   virtual short FindInCollection ( const unsigned char* Buf, long LgBuf, unsigned char* pc=NULL, BOOL SeekAfter=FALSE );

   // -----------------------------------------------------------------------------
   //  Déplacement
   //       - CE_SEEK_SET   : par rapport au début du fichier
   //       - CE_SEEK_CUR : par rapport à la position courante
   //       - CE_SEEK_END     : par rapport à la fin du fichier
   // -----------------------------------------------------------------------------
   virtual short Seek ( long Offset, short Orig );
   virtual long  Tell ( );
   virtual long  GetFileSize(); 
   virtual short Eof(); 

   // -----------------------------------------------------------------------------
   //  Gestion des erreurs
   //    Récupération des erreurs provenant des fonctions C (pour débug)
   // -----------------------------------------------------------------------------
   virtual short GetError(); 
   virtual short ClearError(); 

// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:
   enum { opeBof, opeRead, opeWrite, opeSeek };

   // --- Nom du fichier
   char     m_FileName[1024]; // Mémorisation du nom de fichier
                              // ATTENTION pour la conversion ABALANFC, 
                              // la taille doit être >= à la taille prévue dans fnconver.c   

   char *   m_pAbalAnfc;      // Pointeur sur la variable d'environnement ABALANFC
                              // (mémorisé pour debug)
                                 
   // --- variables de travail
   FILE *   m_Handle;      // Handle du fichier (NULL si pas ouvert) 
   BOOL     m_IsRead;      // Vrai si lecture autorisée
   BOOL     m_IsWrite;     // Vrai si écriture autorisée
   BOOL     m_IsAppend;    // Vrai si on écrit en mode 'append'

   short    m_MemoOpe;     // Mémorise la dernière opération sur le fichier
   BOOL     m_MemoModif;   // Mémorise si on a fait une écriture

   // --- Initialisations
   //     Cette méthode est virtuelle car elle doit être
   //     complétée par une classe dérivée
   virtual void _Clean();

   // --- Mémorisation du nom de fichier passé en paramètre
   //     avec une éventuelle conversion tenant compte de la variable 
   //     d'environnement ABALANFC sous UseIt
   void _InitFileName( const char* FileName ); 

   // --- Positionnement corrects
   inline short _PositBeforeWrite();
   inline short _PositBeforeRead();
   inline short _PositBeforeSeek();

   // --- Utilitaires
   inline short _IsOk();
   inline short _IsOkForWrite();
   inline short _IsOkForRead();
   inline int   _ConvSeek( short Ori );
   inline long  _GetFileSize();

   // --- Fonctions de base avec même code retour que les fonctions C
   inline long  _mytell_basic(void);
   inline short _mygetc_basic(void);   
   inline short _myeof_basic(void);   
   inline short _myseek_basic(long Offset, short Orig);   

   // --- Fonctions de base avec conversion des codes retour ou bidouilles
   inline void  _myclearerr(void);
   inline short _myseek(long Offset, short Orig);
   inline short _mygetc(unsigned char* c);
   inline short _myputc(unsigned char c);
   inline short _mywrite(const unsigned char* Buf, long LgBuf, long* pLg);
   inline long  _mytell(void);

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CStreamLine
//
// Accès à des fichiers en mode texte pour Windows, Twin, UseIt
// pour une compatibilité totale, le mode texte est géré à la main
//
// A noter que les méthode d'accès binaire sont possibles
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class CStreamLine : public CStreamBin
{
// *******************************************************************************************************
// - SECTION PUBLIQUE
// *******************************************************************************************************
public:

   // -----------------------------------------------------------------------------
   //  Construction / Destruction
   //    Par défaut, pas d'expansion de tabulation, et padding à espace
   // -----------------------------------------------------------------------------
   CStreamLine(short LgTab=0, short IsPad=1, short IsFormFeed=0);
   virtual ~CStreamLine();

   // -----------------------------------------------------------------------------
   //  Identification de la classe au moment de l'exécution
   //  Pour CStreamLine, renvoie 1
   // -----------------------------------------------------------------------------
   virtual short GetClassId() {return 1;}

   // -----------------------------------------------------------------------------
   //  Initialisations indépendante du open
   //    Expansion des tabulations en espaces (0==pas de conversion)
   //    Padding du buffer avec des espaces (0==pas de padding)
   // -----------------------------------------------------------------------------
   virtual short LnSetExpandTab( short LgTab=0 );
   virtual short LnGetExpandTab();
   virtual short LnSetPad( short IsPad=1 );
   virtual short LnGetPad();
   virtual short LnSetFormFeed( short IsFormFeed=1 );
   virtual short LnGetFormFeed();

   // -----------------------------------------------------------------------------
   //  Ouverture / Fermeture
   //  Valeurs de Flags :
   //    Existence du fichier :
   //       CE_F_CHK_NOEXIST , CE_F_CHK_EXIST , CE_F_NOCHK       
   //    Mode d'ouverture
   //       CE_F_R , CE_F_RW , CE_F_RW_NEW
   //    Format d'écriture 
   //       CE_F_STREAM_F_ADD_NOTHING  : Pas de Cr, ni de Ctrlz
   //       CE_F_STREAM_F_ADD_CTRLZ    : Ajout d'un Ctrlz
   //       CE_F_STREAM_F_ADD_CR       : Ajout d'un Cr
   //       rien (défaut)              : automatique
   //                                    si le fichier existe, écriture selon son format
   //                                    sinon, écriture selon les conventions de l'OS
   //    ( conventions :                                           )
   //    ( Twin = Ctrlz-Cr , Windows = Cr , UseIt = ni Ctrlz-ni Cr )
   // -----------------------------------------------------------------------------
   virtual short Open( const char* sFileName, WORD Flags );
   virtual short Close();

   // -----------------------------------------------------------------------------
   //  Lecture / Ecriture
   //    LnRead   : Lit depuis la position courante, jusqu'à la fin de ligne
   //               Si le buffer est trop petit, on peut enchiner un nouvel
   //               appel pour lire la suite.
   // 
   //    LnWrite  : Ecrit en fin de fichier uniquement
   // 
   //    Write binaires comme décrit dans CStreamBin
   // -----------------------------------------------------------------------------
   virtual short LnRead( unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short LnWrite( const unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Write( const unsigned char* Buf, long LgBuf, long* pLg=NULL ); // surcharge
   virtual short Write( unsigned char c  );                                     // surcharge
   virtual short Read ( unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Read ( unsigned char* c );
   virtual short Find ( unsigned char c, BOOL SeekAfter=FALSE );
   virtual short Find ( const unsigned char* Buf, long LgBuf, BOOL SeekAfter=FALSE );
   virtual short FindInCollection ( const unsigned char* Buf, long LgBuf, unsigned char* pc=NULL, BOOL SeekAfter=FALSE );

   // -----------------------------------------------------------------------------
   //  Lecture / Ecriture de fichiers INI
   // -----------------------------------------------------------------------------
   virtual short LnReadSection( unsigned char* Sec, long LgSec, long* pLg=NULL );
   virtual short LnFindSection( const unsigned char* Sec, long LgSec, short IsCaseSens);
   virtual short LnReadKey( unsigned char* Key, long LgKey, long* pLgKey, unsigned char* Val, long LgVal, long* pLgVal );
   virtual short LnFindKey( const unsigned char* Key, long LgKey, unsigned char* Val, long LgVal, long* pLgVal, short IsCaseSens );

   // -----------------------------------------------------------------------------
   //  Déplacement
   //  LnAnalyseLines     : Lance explicitement l'analyse du fichier pour détermination
   //                       des lignes et fin de fichier. L'analyse est effectuée
   //                       automatiquement quand cela est nécessaire (WriteLine, Seek,...)
   //  LnSeek             : Aller au début d'une ligne (selon le même principe que Seek) 
   //  LnTell             : Donne la ligne courante
   //  LnGetFileSize      : Nombre de lignes dans le fichier
   //  LnGetLength        : Longueur logique d'une ligne depuis la position courante
   //                       (qui n'est pas forcément le début de la ligne), jusqu'à
   //                       la fin de la ligne. Voir ReadLine.
   //  LnGetFileFormat    : Indique le format trouvé lors de l'analyse du fichier
   //  LnGetLengthLine    : Longueur logique de la ligne depuis le début de la ligne
   //  LnIsLastLine       : Indique si on est sur la dernière ligne
	//  LnGetMaxLengthLine : Taille de la ligne la plus grande
   // -----------------------------------------------------------------------------
   virtual short LnAnalyse();                          
   virtual short LnSeek( long OffsetLine, short Orig );
   virtual long  LnTell();
   virtual long  LnGetFileSize();
   virtual long  LnGetLength();
   virtual short LnEof(); 
   virtual short LnGetFileFormat( WORD* pIsCr, WORD* pIsCtrlz );
   virtual long  LnGetLengthLine();
   virtual short LnIsLastLine();
	virtual long  LnGetMaxLengthLine();

   virtual short Seek ( long Offset, short Orig ); // surcharge
  
   // -----------------------------------------------------------------------------
   //  Gestion des erreurs
   //    Récupération des erreurs provenant des fonctions C (pour débug)
   // -----------------------------------------------------------------------------
   virtual short ClearError(); // surcharge

// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:
   virtual void _Clean();

   // --- Format de fichier souhaité lors du Open
   //     (positionné dans Open)
   BOOL        m_IsFormatForce;     // TRUE=format forcé, FALSE=format selon contenu du fichier
   BOOL        m_IsFormatCtrlz;     // Ajout de Ctrlz ou non   
   BOOL        m_IsFormatCr;        // Ajout de Cr ou non
   
   // --- Expansion des tabulations en espaces
   //     (positionné dans LnSetExpandTab, pas d'expansion par défaut)
   short       m_LgTab;

   // --- Prise en compte du caractère 0x0C comme un 0x0A
   //     (positionné dans LnSetFormFeed, lu par LnGetFormFeed, pas de prise en compte par défaut)
   short       m_IsFormFeed;

   // --- Padding du buffer à espaces avant lecture
   //     (positionné dans LnSetPad, mis à vrai par défaut)
   short       m_IsPad;

   // --- Analyse du format des lignes
   //     Ces variables sont positionnées pendant l'analyse d'une ligne
   //     afin de déterminer le format du fichier        
   //     (positionné dans _UpdateInfoLine, _ReadUntilEol et sous-fonctions)
   BOOL        m_Ctrlz_IsFound;     // un CtrlZ a été détecté     
   BOOL        m_Cr_IsFound;        // Au moins un Cr a été détecté
   BOOL        m_Eof_IsFound;       // La fin de fichier a été détecté (CtrlZ ou EOF)
   long        m_Eof_MemoTell;      // Memo de la position de la fin de fichier (CtrlZ ou EOF)

   // --- Analyse du format des lignes
   //     (positionné dans _SetEofReached)
   BOOL        m_Eof_IsReached;     // Fin de fichier atteinte (CtrlZ ou EOF)

   // --- Analyse du fichier
   //     (positionné par _CreateInfoLine)
   BOOL        m_Lines_IsValid;     // La liste des ligne est valide
   ClistLine   m_Lines_List;        // Liste chainée des lignes

   // --- Analyse des lignes
   virtual void _CleanInfoLine();
   inline short _CreateInfoLine();
   inline short _UpdateInfoLine(long Offset);

   // --- Analyse d'une ligne
   inline short _ReadUntilEol( short IsPad, unsigned char* Buf, long LgBuf, long& Lg );
   inline short _ReadUntilEol( long& Lg );
   inline short _TreatEof();
   inline short _TreatCtrlz();
   inline short _TreatCr();
   inline short _TreatEol();
   inline short _TreatTab( long& iNew );
   inline short _TreatTab( unsigned char* Buf, long LgBuf, long& iNew );

   // --- Utilitaires
   inline BOOL  _IsAddCtrlz();
   inline BOOL  _IsAddCr();
   inline unsigned char _Lower( unsigned char c);
   inline BOOL  _IsStrEqual( const unsigned char* Buf1, long LgBuf1, const unsigned char* Buf2, long LgBuf2, short IsCaseSensitif);

   // --- Lecture spécifique pour fichier INI
   inline short _IniReadSection( CIniLine& Line, unsigned char* Sec, long LgSec, long* pLg);
   inline short _IniReadKey( CIniLine& Line, unsigned char* Key, long LgKey, long* pLgKey, unsigned char* Val, long LgVal, long* pLgVal );
      
   // --- Gestion de la fin de fichier par CtrlZ ou EOF
   inline void  _SetEofReached();
   inline void  _ResetEofReached();
};

#endif  
