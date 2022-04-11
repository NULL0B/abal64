// ***********************************************************************************************
// * IniLine.h
// ***********************************************************************************************

#ifndef INILINE_H
#define INILINE_H

#include <stdio.h>

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CIniLine
//
// Analyse de ligne provenant d'un fichier INI
// Cette classe 
// - alloue un buffer pouvant recevoir la ligne à analyser
// - analyse la ligne pour déterminer s'il s'agit d'un commentaire, d'une section 
//   ou d'une clé avec ou sans valeur.
// - Copie le contenu de l'entité identifiée en assurant le padding avec des espaces
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
class CIniLine
{
// *******************************************************************************************************
// - SECTION PUBLIQUE
// *******************************************************************************************************
public:

   // -----------------------------------------------------------------------------
   //  Variables 
   // -----------------------------------------------------------------------------
   unsigned char * m_pLine;      // Pointeur sur la zone allouée
   long            m_LgMaxLine;  // Taille de la zone allouée
   long            m_LgAnaLine;  // Taille des données à analyser

   // -----------------------------------------------------------------------------
   //  Construction / Destruction
   //  Paramétrage
   // -----------------------------------------------------------------------------
   CIniLine(short IsPad = 0);
   virtual ~CIniLine();

   short SetPad(short IsPad = 1);
   short GetPad();

   // -----------------------------------------------------------------------------
   //  Initialisation
   // -----------------------------------------------------------------------------
   short Alloc(long LgBuf);
   void  Free(void);

   // -----------------------------------------------------------------------------
   //  Traitement
   // -----------------------------------------------------------------------------
   short Analyse(void);
   short AnalyseForSection(void);
   short AnalyseForKey(void);

   // -----------------------------------------------------------------------------
   //  Lecture des infos sur la ligne analysée
   // -----------------------------------------------------------------------------
   short IsSection();
   short IsComment();
   short IsKey();
   short IsKeyValue();

   unsigned char* GetSection();
   unsigned char* GetKey();
   unsigned char* GetValue();
   long GetSectionLength();
   long GetKeyLength();
   long GetValueLength();

   short CopySection(unsigned char* Buf, long LgBuf, long* pLg);
   short CopyKey(unsigned char* Buf, long LgBuf, long* pLg);
   short CopyValue(unsigned char* Buf, long LgBuf, long* pLg);


// *******************************************************************************************************
// - SECTION PROTEGEE
// *******************************************************************************************************
protected:

   enum { eVoid, eComment, eSection, eKey, eKeyVal };
   enum { eWantAll, eWantSection, eWantKey };

   // --- Paramétrage
   unsigned char  m_SectionBegin;
   unsigned char  m_SectionEnd;
   unsigned char  m_CommentColl[10];
   unsigned char  m_Affect;
   short          m_IsPad;

   // --- Buffers remplis par l'analyse
   unsigned char * m_pKey;
   unsigned char * m_pVal;

   // --- Etat
   short  m_State;

   // --- Utilitaires
   inline void _DefaultConfig(void);
   inline void _FreeAll(void);
   inline void _FreeAnalyse(void);
   inline short _Analyse( short Want );

   inline void  _AnaKillSpace( const unsigned char* Buf, long LgBuf, long& i);
   inline void  _AnaFindState( const unsigned char* Buf, long LgBuf, long& i);
   inline short _AnaCopyToken( const unsigned char* Buf, long LgBuf, long& i, unsigned char* pDest, const unsigned char Separator);
   inline short _AnaCopyToken( const unsigned char* Buf, long LgBuf, long& i, unsigned char* pDest);
};

#endif
