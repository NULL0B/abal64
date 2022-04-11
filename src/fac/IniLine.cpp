// ***********************************************************************************************
// * IniLine.cpp
// ***********************************************************************************************

#include "errno.h"
#include "bda.h"

#if defined (BDA_WIN32)
#include <io.h>
#elif defined (BDA_UNIX)
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#elif defined (BDA_TWIN16)
#include <io.h>
#include <string.h>
#include <fcntl.h>
#endif

#include "FacTrace.h"
#include "CstExt.h"
#include "CstInt.h"
#include "IniLine.h"

#define CI_MODULE_ID 0x0010

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CIniLine
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// ***********************************************************************************
// * CIniLine::CIniLine
// ***********************************************************************************
CIniLine::CIniLine(short IsPad)
{
_DefaultConfig();
SetPad(IsPad);
m_pLine     = NULL;
m_LgMaxLine = 0;
m_LgAnaLine = 0;
m_pKey      = NULL;
m_pVal      = NULL;
m_State     = eVoid;
}

// ***********************************************************************************
// * CIniLine::~CIniLine
// ***********************************************************************************
CIniLine::~CIniLine()
{
_FreeAll();
}

// ***********************************************************************************
// * CIniLine::_DefaultConfig
// ***********************************************************************************
void CIniLine::_DefaultConfig(void)
{
m_SectionBegin = '[';
m_SectionEnd   = ']';
m_Affect       = '=';
strcpy( (char*)m_CommentColl, "#*;");
}

// ***********************************************************************************
// * CIniLine::_FreeAnalyse
// ***********************************************************************************
void CIniLine::_FreeAnalyse(void)
{
m_State = eVoid;

if (m_pKey)
   {
   delete m_pKey;
   m_pKey = NULL;
   }
if (m_pVal)
   {
   delete m_pVal;
   m_pVal = NULL;
   }
}

// ***********************************************************************************
// * CIniLine::_FreeAll
// ***********************************************************************************
void CIniLine::_FreeAll(void)
{
if (m_pLine)
   {
   delete m_pLine;
   m_pLine     = NULL;
   m_LgMaxLine = 0;
   m_LgAnaLine = 0;
   }
_FreeAnalyse();
}

// ***********************************************************************************
// * CIniLine::_AnaKillSpace
// ***********************************************************************************
void CIniLine::_AnaKillSpace( const unsigned char* Buf, long LgBuf, long& i)
{
while ( (i<LgBuf) && ((Buf[i]==' ') || (Buf[i]=='\t')) )
   i++;
}

// ***********************************************************************************
// * CIniLine::_AnaCopyToken
// ***********************************************************************************
short CIniLine::_AnaCopyToken( const unsigned char* Buf, long LgBuf, long& i, unsigned char* pDest, const unsigned char Separator)
{
_AnaKillSpace( Buf, LgBuf, i);

do {
   while ((i<LgBuf) && (Buf[i] != ' ') && (Buf[i] != '\t') && (Buf[i] != Separator))
      *pDest++  = Buf[i++];

   _AnaKillSpace( Buf, LgBuf, i);

   if ((i<LgBuf) && (Buf[i] != Separator))
      *pDest++  = ' ';
   }
while ((i<LgBuf) && (Buf[i] != Separator));

*pDest = '\0';

if (Buf[i] == Separator)
   {
   i++;
   return TRUE;
   }
else
   return FALSE;
}

// ***********************************************************************************
// * CIniLine::_AnaCopyToken
// ***********************************************************************************
short CIniLine::_AnaCopyToken( const unsigned char* Buf, long LgBuf, long& i, unsigned char* pDest)
{
_AnaKillSpace( Buf, LgBuf, i);

while (i<LgBuf)
   *pDest++ = Buf[i++];

*pDest  = '\0';
return TRUE;
}

// ***********************************************************************************
// * CIniLine::_AnaFindState
// * Détermination du type de ligne
// * m_State est positionné à eVoid, eComment, eSection, eKey
// ***********************************************************************************
void CIniLine::_AnaFindState ( const unsigned char* Buf, long LgBuf, long& i)
{
_AnaKillSpace( Buf, LgBuf, i);

// ligne vide
if (i>=LgBuf)
   {
   m_State = eVoid;
   return;
   }

// Section
if (Buf[i] == m_SectionBegin)
   {
   i++;
   m_State = eSection;
   return;
   }

// Commentaire
short iCom;
for ( iCom=0 ; (m_CommentColl[iCom] != '\0') && (m_CommentColl[iCom] != Buf[i]) ; iCom++ );

if (m_CommentColl[iCom] != '\0')
   {
   i++;
   m_State = eComment;
   return;
   }

// Y a plus que ça...
// pour déterminer si c'est un couple KeyValue, il faudra le faire ailleurs
// car il faut analyser le contenu complet de la ligne.
m_State = eKey;
}

// ***********************************************************************************
// * CIniLine::_Analyse
// * Analyse la ligne
// * si eWantAll    , les items sont conservés qu'ils soient section, ou key-value
// * si eWantSection, l'item section est conservé 
// * si eWantKey    , les items key et value sont conservés
// ***********************************************************************************
short CIniLine::_Analyse( short Want )
{
long i = 0;

if (!m_pLine)
   return ERR_MEM;

_FreeAnalyse();

_AnaFindState(m_pLine, m_LgAnaLine, i);

switch(m_State)
   {
   case eSection:
      if ((Want==eWantAll) || (Want==eWantSection))
         {
         m_pKey = new unsigned char[m_LgAnaLine+1];
         if (!m_pKey)
            return ERR_MEM;
         _AnaCopyToken(m_pLine, m_LgAnaLine, i, m_pKey, m_SectionEnd);
         }
      break;

   case eKey:
      if ((Want==eWantAll) || (Want==eWantKey))
         {
         m_pKey = new unsigned char[m_LgAnaLine+1];
         if (!m_pKey)
            return ERR_MEM;
         if (_AnaCopyToken(m_pLine, m_LgAnaLine, i, m_pKey, m_Affect))
            {
            m_pVal = new unsigned char[m_LgAnaLine+1];
            if (!m_pVal)
               return ERR_MEM;

            _AnaCopyToken(m_pLine, m_LgAnaLine, i, m_pVal);
            m_State = eKeyVal;
            }
         }
      break;
   }

return NO_ERRORS;
}

// ***********************************************************************************
// * CIniLine::SetPad
// ***********************************************************************************
short CIniLine::SetPad( short IsPad )
{
short Old = m_IsPad;
m_IsPad = IsPad;
return Old;
}

// ***********************************************************************************
// * CIniLine::GetPad
// * renvoie la valeur courante
// ***********************************************************************************
short CIniLine::GetPad()
{
return m_IsPad;
}

// ***********************************************************************************
// * CIniLine::Free
// ***********************************************************************************
void CIniLine::Free(void)
{
_FreeAll();
}

// ***********************************************************************************
// * CIniLine::Alloc
// ***********************************************************************************
short CIniLine::Alloc( long LgBuf)
{
_FreeAll();
m_pLine = new unsigned char[LgBuf];
if (m_pLine)
   {
   m_LgMaxLine = LgBuf;
   m_LgAnaLine = 0;
   return NO_ERRORS;
   }
else
   return ERR_MEM;
}

// ***********************************************************************************
// * CIniLine::Analyse
// ***********************************************************************************
short CIniLine::Analyse(void)
{
return _Analyse( eWantAll );
}

// ***********************************************************************************
// * CIniLine::AnalyseForSection
// ***********************************************************************************
short CIniLine::AnalyseForSection(void)
{
return _Analyse( eWantSection );
}

// ***********************************************************************************
// * CIniLine::AnalyseForKey
// ***********************************************************************************
short CIniLine::AnalyseForKey(void)
{
return _Analyse( eWantKey );
}

// ***********************************************************************************
// * CIniLine::GetSection
// ***********************************************************************************
unsigned char* CIniLine::GetSection()
{
return (m_State==eSection) ? m_pKey : NULL;
}

// ***********************************************************************************
// * CIniLine::GetKey
// ***********************************************************************************
unsigned char* CIniLine::GetKey()
{
return ( (m_State==eKey) || (m_State==eKeyVal)) ? m_pKey : NULL;
}

// ***********************************************************************************
// * CIniLine::GetValue
// ***********************************************************************************
unsigned char* CIniLine::GetValue()
{
return (m_State==eKeyVal) ? m_pVal : NULL;
}

// ***********************************************************************************
// * CIniLine::GetSectionLength
// ***********************************************************************************
long CIniLine::GetSectionLength()
{
return (GetSection()) ? strlen((char*)m_pKey) : 0;
}

// ***********************************************************************************
// * CIniLine::GetKeyLength
// ***********************************************************************************
long CIniLine::GetKeyLength()
{
return (GetKey()) ? strlen((char*)m_pKey) : 0;
}

// ***********************************************************************************
// * CIniLine::GetValueLength
// ***********************************************************************************
long CIniLine::GetValueLength()
{
return (GetValue()) ? strlen((char*)m_pVal) : 0;
}

// ***********************************************************************************
// * CIniLine::IsComment
// ***********************************************************************************
short CIniLine::IsComment()
{
return (m_State==eComment);
}

// ***********************************************************************************
// * CIniLine::IsSection
// ***********************************************************************************
short CIniLine::IsSection()
{
return (m_State==eSection);
}

// ***********************************************************************************
// * CIniLine::IsKey
// ***********************************************************************************
short CIniLine::IsKey()
{
return (m_State==eKey);
}

// ***********************************************************************************
// * CIniLine::IsKeyValue
// ***********************************************************************************
short CIniLine::IsKeyValue()
{
return (m_State==eKeyVal);
}

// ***********************************************************************************
// * CIniLine::CopySection
// * Copie la section, si s'en est une et assure le padding
// ***********************************************************************************
short CIniLine::CopySection(unsigned char* Buf, long LgBuf, long* pLg)
{
long Lg = GetSectionLength();

if ((m_IsPad) && (Buf!=NULL))
   memset(Buf,' ',(size_t)LgBuf);

if ((Lg==0) || (Buf==NULL))
   {
   if (pLg)
      *pLg = 0;
   return TRUE;
   }
   
if (Lg<=LgBuf)
   {
   memcpy( (char*)Buf, (char*)m_pKey, (size_t)Lg);
   if (pLg)
      *pLg = Lg;
   return TRUE;
   }
else
   {
   if (pLg)
      *pLg = 0;
   return FALSE;
   }
}

// ***********************************************************************************
// * CIniLine::CopyKey
// * Copie la clé, si s'en est une et assure le padding
// ***********************************************************************************
short CIniLine::CopyKey(unsigned char* Buf, long LgBuf, long* pLg)
{
long Lg = GetKeyLength();

if ((m_IsPad) && (Buf!=NULL))
   memset(Buf,' ',(size_t)LgBuf);

if ((Lg==0) || (Buf==NULL))
   {
   if (pLg)
      *pLg = 0;
   return TRUE;
   }
   
if (Lg<=LgBuf)
   {
   memcpy( (char*)Buf, (char*)m_pKey, (size_t)Lg);
   if (pLg)
      *pLg = Lg;
   return TRUE;
   }
else
   {
   if (pLg)
      *pLg = 0;
   return FALSE;
   }
}

// ***********************************************************************************
// * CIniLine::CopyValue
// * Copie la valeur de la clé, si s'en est une et assure le padding
// ***********************************************************************************
short CIniLine::CopyValue(unsigned char* Buf, long LgBuf, long* pLg)
{
long Lg = GetValueLength();

if ((m_IsPad) && (Buf!=NULL))
   memset(Buf,' ',(size_t)LgBuf);

if ((Lg==0) || (Buf==NULL))
   {
   if (pLg)
      *pLg = 0;
   return TRUE;
   }
   
if (Lg<=LgBuf)
   {
   memcpy( (char*)Buf, (char*)m_pVal, (size_t)Lg);
   if (pLg)
      *pLg = Lg;
   return TRUE;
   }
else
   {
   if (pLg)
      *pLg = 0;
   return FALSE;
   }
}
