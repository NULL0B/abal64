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
// Liste chain�e utilis�e par CStreamLine pour repr�senter les lignes d'un fichier 
// avec leur caract�ristiques.
// 
// Caract�ristiques principales de la liste chain�e :
// - Les �l�ments de la liste doivent �tre tri�s par ordre croissant d'offset
// - On acc�de � la liste par la t�te ou par la fin.
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
   //  Les �l�ments doivent �tre tri�s par ordre croissant d'offset
   //  - ClearAll      : d�truit la liste
   //  - InsertFromEnd : insert les �l�ments en les triant en cherchant � partir 
   //                    de la fin. Si l'offset existe d�j�, la longueur est mise � jour
   //  - AddAtEnd      : Place un �l�ment en queue de liste (c'est � l'appelant
   //                    de s'assurer que les �l�ments sont ordonn�s)
   // -----------------------------------------------------------------------------
   void  ClearAll();
   void  AddAtEnd( long Offset, long Lg );
   void  InsertFromEnd( long Offset, long Lg );

   // -----------------------------------------------------------------------------
   //  Propri�t�s g�n�rales
   // -----------------------------------------------------------------------------
   inline BOOL  IsValid();
   inline long  GetLines();
	inline long  GetLinesMaxLg();

   // -----------------------------------------------------------------------------
   //  Recherche d'un �l�ment pour d�finir l'�l�ment courant
   // -----------------------------------------------------------------------------
   void  SetCurLineAtOffset( long Offset);  // El�ment d�fini par Offset binaire
   void  SetCurLineAtLine( long Line);      // El�ment d�fini par num�ro de ligne
   void  SetCurLineAtBegin();               // 1er �l�ment
   void  SetCurLineAtEnd();                 // Dernier �l�ment

   // -----------------------------------------------------------------------------
   //  Consultation de celui-ci
   // -----------------------------------------------------------------------------
   long  GetCurLineOffset();                // Offset de d�but de ligne
   long  GetCurLineLg();                    // Longueur logique de la ligne
   long  GetCurLineLine();                  // Num�ro de la ligne


// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:

   // --- Pointeurs d'�l�ment
   CLine*   m_pFirst;      // T�te de liste
   CLine*   m_pLast;       // Queue de liste
   CLine*   m_pCur;        // El�ment courant

   // --- Infos
   BOOL     m_IsNewError;  // Indique un pb d'allocation m�moire
   long     m_CurLine;     // Num�ro de ligne de l'�l�ment courant
   long     m_MaxLine;     // Nombre d'�l�ments de la liste 
   long     m_MaxLenLine;  // Taille de la plus grande ligne

   // --- M�thode internes
   CLine* _New( long Offset, long Lg );
   void _Link( CLine* pCur, CLine* pNew, BOOL IsAfter=TRUE );
   void _Unlink( CLine* pOld );
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CStreamBin
//
// Acc�s � des fichiers en mode binaire pour Windows, Twin, UseIt
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
   //  Identification de la classe au moment de l'ex�cution
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
   //    Find d'un octet appartenent � une collection d'octets
   //    Les m�thodes de recherche se positionnent
   //       - sur l'octet ou le buffer trouv� (d�faut)
   //       - apr�s l'octet ou le buffer trouv�
   //       - � la fin du fichier si non trouv� 
   // -----------------------------------------------------------------------------
   virtual short Write( const unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Read ( unsigned char* Buf, long LgBuf, long* pLg=NULL );
   virtual short Write( unsigned char c  );
   virtual short Read ( unsigned char* c );

   virtual short Find ( unsigned char c, BOOL SeekAfter=FALSE );
   virtual short Find ( const unsigned char* Buf, long LgBuf, BOOL SeekAfter=FALSE );
   virtual short FindInCollection ( const unsigned char* Buf, long LgBuf, unsigned char* pc=NULL, BOOL SeekAfter=FALSE );

   // -----------------------------------------------------------------------------
   //  D�placement
   //       - CE_SEEK_SET   : par rapport au d�but du fichier
   //       - CE_SEEK_CUR : par rapport � la position courante
   //       - CE_SEEK_END     : par rapport � la fin du fichier
   // -----------------------------------------------------------------------------
   virtual short Seek ( long Offset, short Orig );
   virtual long  Tell ( );
   virtual long  GetFileSize(); 
   virtual short Eof(); 

   // -----------------------------------------------------------------------------
   //  Gestion des erreurs
   //    R�cup�ration des erreurs provenant des fonctions C (pour d�bug)
   // -----------------------------------------------------------------------------
   virtual short GetError(); 
   virtual short ClearError(); 

// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:
   enum { opeBof, opeRead, opeWrite, opeSeek };

   // --- Nom du fichier
   char     m_FileName[1024]; // M�morisation du nom de fichier
                              // ATTENTION pour la conversion ABALANFC, 
                              // la taille doit �tre >= � la taille pr�vue dans fnconver.c   

   char *   m_pAbalAnfc;      // Pointeur sur la variable d'environnement ABALANFC
                              // (m�moris� pour debug)
                                 
   // --- variables de travail
   FILE *   m_Handle;      // Handle du fichier (NULL si pas ouvert) 
   BOOL     m_IsRead;      // Vrai si lecture autoris�e
   BOOL     m_IsWrite;     // Vrai si �criture autoris�e
   BOOL     m_IsAppend;    // Vrai si on �crit en mode 'append'

   short    m_MemoOpe;     // M�morise la derni�re op�ration sur le fichier
   BOOL     m_MemoModif;   // M�morise si on a fait une �criture

   // --- Initialisations
   //     Cette m�thode est virtuelle car elle doit �tre
   //     compl�t�e par une classe d�riv�e
   virtual void _Clean();

   // --- M�morisation du nom de fichier pass� en param�tre
   //     avec une �ventuelle conversion tenant compte de la variable 
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

   // --- Fonctions de base avec m�me code retour que les fonctions C
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
// Acc�s � des fichiers en mode texte pour Windows, Twin, UseIt
// pour une compatibilit� totale, le mode texte est g�r� � la main
//
// A noter que les m�thode d'acc�s binaire sont possibles
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
   //    Par d�faut, pas d'expansion de tabulation, et padding � espace
   // -----------------------------------------------------------------------------
   CStreamLine(short LgTab=0, short IsPad=1, short IsFormFeed=0);
   virtual ~CStreamLine();

   // -----------------------------------------------------------------------------
   //  Identification de la classe au moment de l'ex�cution
   //  Pour CStreamLine, renvoie 1
   // -----------------------------------------------------------------------------
   virtual short GetClassId() {return 1;}

   // -----------------------------------------------------------------------------
   //  Initialisations ind�pendante du open
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
   //    Format d'�criture 
   //       CE_F_STREAM_F_ADD_NOTHING  : Pas de Cr, ni de Ctrlz
   //       CE_F_STREAM_F_ADD_CTRLZ    : Ajout d'un Ctrlz
   //       CE_F_STREAM_F_ADD_CR       : Ajout d'un Cr
   //       rien (d�faut)              : automatique
   //                                    si le fichier existe, �criture selon son format
   //                                    sinon, �criture selon les conventions de l'OS
   //    ( conventions :                                           )
   //    ( Twin = Ctrlz-Cr , Windows = Cr , UseIt = ni Ctrlz-ni Cr )
   // -----------------------------------------------------------------------------
   virtual short Open( const char* sFileName, WORD Flags );
   virtual short Close();

   // -----------------------------------------------------------------------------
   //  Lecture / Ecriture
   //    LnRead   : Lit depuis la position courante, jusqu'� la fin de ligne
   //               Si le buffer est trop petit, on peut enchiner un nouvel
   //               appel pour lire la suite.
   // 
   //    LnWrite  : Ecrit en fin de fichier uniquement
   // 
   //    Write binaires comme d�crit dans CStreamBin
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
   //  D�placement
   //  LnAnalyseLines     : Lance explicitement l'analyse du fichier pour d�termination
   //                       des lignes et fin de fichier. L'analyse est effectu�e
   //                       automatiquement quand cela est n�cessaire (WriteLine, Seek,...)
   //  LnSeek             : Aller au d�but d'une ligne (selon le m�me principe que Seek) 
   //  LnTell             : Donne la ligne courante
   //  LnGetFileSize      : Nombre de lignes dans le fichier
   //  LnGetLength        : Longueur logique d'une ligne depuis la position courante
   //                       (qui n'est pas forc�ment le d�but de la ligne), jusqu'�
   //                       la fin de la ligne. Voir ReadLine.
   //  LnGetFileFormat    : Indique le format trouv� lors de l'analyse du fichier
   //  LnGetLengthLine    : Longueur logique de la ligne depuis le d�but de la ligne
   //  LnIsLastLine       : Indique si on est sur la derni�re ligne
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
   //    R�cup�ration des erreurs provenant des fonctions C (pour d�bug)
   // -----------------------------------------------------------------------------
   virtual short ClearError(); // surcharge

// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:
   virtual void _Clean();

   // --- Format de fichier souhait� lors du Open
   //     (positionn� dans Open)
   BOOL        m_IsFormatForce;     // TRUE=format forc�, FALSE=format selon contenu du fichier
   BOOL        m_IsFormatCtrlz;     // Ajout de Ctrlz ou non   
   BOOL        m_IsFormatCr;        // Ajout de Cr ou non
   
   // --- Expansion des tabulations en espaces
   //     (positionn� dans LnSetExpandTab, pas d'expansion par d�faut)
   short       m_LgTab;

   // --- Prise en compte du caract�re 0x0C comme un 0x0A
   //     (positionn� dans LnSetFormFeed, lu par LnGetFormFeed, pas de prise en compte par d�faut)
   short       m_IsFormFeed;

   // --- Padding du buffer � espaces avant lecture
   //     (positionn� dans LnSetPad, mis � vrai par d�faut)
   short       m_IsPad;

   // --- Analyse du format des lignes
   //     Ces variables sont positionn�es pendant l'analyse d'une ligne
   //     afin de d�terminer le format du fichier        
   //     (positionn� dans _UpdateInfoLine, _ReadUntilEol et sous-fonctions)
   BOOL        m_Ctrlz_IsFound;     // un CtrlZ a �t� d�tect�     
   BOOL        m_Cr_IsFound;        // Au moins un Cr a �t� d�tect�
   BOOL        m_Eof_IsFound;       // La fin de fichier a �t� d�tect� (CtrlZ ou EOF)
   long        m_Eof_MemoTell;      // Memo de la position de la fin de fichier (CtrlZ ou EOF)

   // --- Analyse du format des lignes
   //     (positionn� dans _SetEofReached)
   BOOL        m_Eof_IsReached;     // Fin de fichier atteinte (CtrlZ ou EOF)

   // --- Analyse du fichier
   //     (positionn� par _CreateInfoLine)
   BOOL        m_Lines_IsValid;     // La liste des ligne est valide
   ClistLine   m_Lines_List;        // Liste chain�e des lignes

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

   // --- Lecture sp�cifique pour fichier INI
   inline short _IniReadSection( CIniLine& Line, unsigned char* Sec, long LgSec, long* pLg);
   inline short _IniReadKey( CIniLine& Line, unsigned char* Key, long LgKey, long* pLgKey, unsigned char* Val, long LgVal, long* pLgVal );
      
   // --- Gestion de la fin de fichier par CtrlZ ou EOF
   inline void  _SetEofReached();
   inline void  _ResetEofReached();
};

#endif  
