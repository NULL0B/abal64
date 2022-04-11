// ***********************************************************************************************
// * Strm.cpp
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
#include "fnconver.h"
#include "Strm.h"

#define CI_MODULE_ID 0x0010


//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CStreamBin
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////


// ***********************************************************************************
// * CStreamBin::_Clean
// ***********************************************************************************
void CStreamBin::_Clean()
{
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_Clean","deb" ));
m_Handle   = NULL;
m_IsAppend = FALSE;
m_IsWrite  = FALSE;
m_IsRead   = FALSE;
m_MemoOpe  = opeBof;
m_MemoModif= FALSE;
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_Clean","end" ));
}

// ***********************************************************************************
// * CStreamBin::_InitFileName
// ***********************************************************************************
void CStreamBin::_InitFileName( const char* FileName )
{
#if defined(BDA_UNIX)
// --------------------------------------------------------------------------
// Linux
// La variable d'environnement ABALANFC est prise en compte
// Le nom de fichier est donc converti en fonction de cette derni�re
// Le code de conversion provient de l'�quipe de Moscou
// --------------------------------------------------------------------------

WORD  Mode = 0;

// --- Lecture et analyse de la variable d'environnement
m_pAbalAnfc = getenv("ABALANFC");
if (m_pAbalAnfc)
   {
   char* sptr = m_pAbalAnfc;
   while ( *sptr ) 
      {
      switch ( *(sptr++) ) 
         {
         case 'm' :
           Mode |= _CONVERT_MNEMONICS;
           continue;
         case 'u' :
           Mode &= ~_CONVERT_LOWER;
           Mode |= _CONVERT_UPPER;
           continue;
         case 'l' :
           Mode &= ~_CONVERT_UPPER;
           Mode |= _CONVERT_LOWER;
           continue;
         }
      }
   }

// --- M�morisation du nom de fichier
if (Mode!=0)
   fn_convertor( (unsigned char*)FileName, (unsigned char*)m_FileName, Mode );
else
   strcpy(m_FileName,FileName); 

#else
// ---------------------------------
// autres 
// Il n'y a pas de variable d'environnement
// On fait une simple copie
// ---------------------------------

m_pAbalAnfc = NULL;
strcpy(m_FileName,FileName); 

#endif
} 

// ***********************************************************************************
// * CStreamBin::_IsOk
// * CStreamBin::_IsOkForWrite
// * CStreamBin::_IsOkForRead
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM
// ***********************************************************************************
short CStreamBin::_IsOk()         { return (m_Handle) ? NO_ERRORS:ERR_PARAM; }
short CStreamBin::_IsOkForWrite() { return (m_Handle) ? ((m_IsWrite)?NO_ERRORS:ERR_BAD_CALL):ERR_PARAM; }
short CStreamBin::_IsOkForRead()  { return (m_Handle) ? ((m_IsRead) ?NO_ERRORS:ERR_BAD_CALL):ERR_PARAM; }

// ***********************************************************************************
// * CStreamBin::_ConvSeek
// ***********************************************************************************
int CStreamBin::_ConvSeek( short Ori )
{ return (Ori==CE_SEEK_SET) ? SEEK_SET : ( (Ori==CE_SEEK_END) ? SEEK_END : SEEK_CUR) ; }

// ***********************************************************************************
// * CStreamBin::_PositBeforeWrite
// * NO_ERRORS , ERR_SEEK
// ***********************************************************************************
short CStreamBin::_PositBeforeWrite()
{
if (m_IsAppend)
   {
   // Mode APPEND, on �crit obligatoirement en fin de fichier
   //   ( Attention, en mode TEXTE, il ne faut pas utiliser )
   //   ( ce mode � cause d'un �ventuel Ctrlz               )
   if (_myseek_basic( 0, SEEK_END))
      return ERR_SEEK;
   }
else
   {
   // Mode UPDATE, on �crit � la position courante
   // avec for�age du seek apr�s une lecture
   //   Sous Windows, si on ne fait pas de seek apres un read, le write ne marche pas,
   //   alors que les codes retour indique que c'est correct.
   //   Donc on fait un blindage.
   if (m_MemoOpe==opeRead)
      {
      if (_myseek_basic( 0, SEEK_CUR))
         return ERR_SEEK;
      }
    }

m_MemoOpe  = opeWrite;
m_MemoModif= TRUE;
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::_PositBeforeRead
// * NO_ERRORS , ERR_WRITE , ERR_SEEK
// ***********************************************************************************
short CStreamBin::_PositBeforeRead()
{
if (m_MemoOpe==opeWrite)
   {
   // For�age du seek apr�s une lecture
   //   Vu les pb rencontr�s pour le write, on fait le m�me blindage pour un enchainement
   //   write, puis read.
   if (_myseek_basic( 0, SEEK_CUR))
      return ERR_SEEK;
   }

m_MemoOpe  = opeRead;
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::_PositBeforeSeek
// * NO_ERRORS , ERR_WRITE
// ***********************************************************************************
short CStreamBin::_PositBeforeSeek()
{
m_MemoOpe  = opeSeek;
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::_myclearerr
// ***********************************************************************************
void CStreamBin::_myclearerr(void)
{
clearerr(m_Handle);
}

// ***********************************************************************************
// * CStreamBin::_mytell_basic
// ***********************************************************************************
long CStreamBin::_mytell_basic(void)
{
long pos = ftell(m_Handle);
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_mytell_basic","pos=%04X", pos));
return pos;
}

// ***********************************************************************************
// * CStreamBin::_myeof_basic
// ***********************************************************************************
short CStreamBin::_myeof_basic(void)
{
short ret = feof(m_Handle);
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_myeof_basic","eof=%04X", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::_myseek_basic
// * NO_ERRORS , ERR_SEEK
// ***********************************************************************************
short CStreamBin::_myseek_basic(long Offset, short Orig)
{
short ret = fseek(m_Handle, Offset, Orig);
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_myseek_basic","eof=%04X", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::_myseek
// * NO_ERRORS , ERR_SEEK
// ***********************************************************************************
short CStreamBin::_myseek(long Offset, short Orig)
{
return (_myseek_basic( Offset, Orig)) ? ERR_SEEK : NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::_mytell
// * NO_ERRORS , ERR_SEEK
// ***********************************************************************************
long CStreamBin::_mytell(void)
{
// FCH03022003 (begin)
// Sous Linux, le ftell fait tomber le flag Eof, donc on blinde
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin__mytell",""));
if (_myeof_basic())
   {
   long pos;
   pos = _mytell_basic();  // r�cup�re la position courante
   _mygetc_basic();        // repositionne le flag feof
   return pos;
   }
else
   return _mytell_basic();
// FCH03022003 (end)
}

// ***********************************************************************************
// * CStreamBin::_getc
// * NO_ERRORS , ERR_EOF , ERR_READ
// ***********************************************************************************
short CStreamBin::_mygetc(unsigned char* c)
{
short car;
car = _mygetc_basic();
if (car == EOF)
   return (_myeof_basic()) ? ERR_EOF : ERR_READ;
else
   {
   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_getc","c=%04X", car));
   *c = (unsigned char) car;
   return NO_ERRORS;
   }
}

// ***********************************************************************************
// * CStreamBin::_mygetc_basic
// * car
// ***********************************************************************************
short CStreamBin::_mygetc_basic()
{
short car = fgetc(m_Handle);
//MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"stbin_getc","c=%04X", car));
return car;
}

// ***********************************************************************************
// * CStreamBin::_myputc
// * NO_ERRORS , ERR_WRITE
// ***********************************************************************************
short CStreamBin::_myputc(unsigned char c)
{
if (fputc( c, m_Handle) == EOF)
   return ERR_WRITE;
else
   return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::_mywrite
// * NO_ERRORS , ERR_FULL , ERR_WRITE
// ***********************************************************************************
short CStreamBin::_mywrite(const unsigned char* Buf, long LgBuf, long* pLg)
{
short ret;

*pLg = fwrite( Buf, 1, (size_t)LgBuf, m_Handle);

MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,"stbin_write","LgIn=%ld LgOut=%ld",LgBuf,*pLg));

// Sous Windows (au moins), si la disquette est pleine, Lg est toujours �gal � LgBuf,
// il faut tester ferror pour d�tecter l'erreur
if (ferror(m_Handle))
   ret = (errno==ENOSPC) ? ERR_FULL : ERR_WRITE;      
else
   {
   // Si la longueur r�ellement �crite est plus petite que la longueur demand�e
   // c'est qu'il y a eu un probl�me pendant l'�criture
   if (*pLg<LgBuf)
      ret = (_myeof_basic()) ? ERR_EOF : ERR_WRITE;
   else
      ret = NO_ERRORS;
   }

return ret;
}

// ***********************************************************************************
// * CStreamBin::_GetFileSize
// * taille du fichier (-1 si erreur)
// * Fait tomber le Eof
// ***********************************************************************************
long CStreamBin::_GetFileSize()
{
long  MemoOffset;
long  Offset = -1;

MemoOffset = _mytell();
if (_myseek(0,SEEK_END)==NO_ERRORS)
   {
   Offset = _mytell();
   _myseek(MemoOffset,SEEK_SET);
   }

return Offset;
}

// ***********************************************************************************
// * CStreamBin::CStreamBin
// ***********************************************************************************
CStreamBin::CStreamBin()
{
_Clean();
}

// ***********************************************************************************
// * CStreamBin::~CStreamBin
// ***********************************************************************************
CStreamBin::~CStreamBin()
{
Close();
}

// ***********************************************************************************
// * CStreamBin::Open
// * Ouverture du fichier en mode binaire
// * Flags = - CE_F_CHK_NOEXIST        ouvre si fichier n'existe pas
// *         - CE_F_CHK_EXIST          ouvre si fichier existe
// *         - CE_F_NOCHK              (d�faut)
// *       +
// *         - CE_F_R                  lecture
// *         - CE_F_W_NEW              �criture partout, si existe efface le contenu
// *         - CE_F_W_APPEND           �criture en fin
// *         - CE_F_RW                 lecture et �criture partout
// *         - CE_F_RW_NEW             lecture et �criture partout, si existe efface le contenu
// *         - CE_F_RW_APPEND          lecture et �criture en fin
// *
// * NO_ERRORS , ERR_BUSY , ERR_NOFILE , ERR_EXIST , ERR_ACCESS
// ***********************************************************************************

short CStreamBin::Open( const char* sFileName, WORD Flags )
{
MI_TRACE_DCL_TFN("stbin_Open");
short ret = NO_ERRORS;
char  Mode[4];

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin"));

// ----------------------------------------------------------------
// Fichier d�j� ouvert
// ----------------------------------------------------------------
if (m_Handle)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ERR_BUSY)) , ERR_BUSY;

// ----------------------------------------------------------------
// M�morisasion/conversion du nom de fichier
// ----------------------------------------------------------------
_InitFileName( sFileName );
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"ABALANFC='%s'", (char*)((m_pAbalAnfc) ? m_pAbalAnfc : "") ));
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Fic='%s'",m_FileName));

// ----------------------------------------------------------------
// Analyse existence du fichier selon les param�tres
// ----------------------------------------------------------------
switch (Flags & CE_F_MASK_CHK)
   {
   case CE_F_CHK_NOEXIST:
      // Le fichier ne doit pas exister
      if (Portable_access( m_FileName,0) == 0)
         ret = ERR_EXIST;
      break;

   case CE_F_CHK_EXIST:
      // Le fichier doit exister
      if (Portable_access( m_FileName,0) != 0)
         ret = ERR_NOFILE;
      break;

   default:
      // Pas de contr�le
      ret = NO_ERRORS;
      break;
   }

if (ret != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Analyse du mode d'ouverture
// ----------------------------------------------------------------
switch (Flags & CE_STREAM_F_MASK_MODE)
   {
   case CE_F_W_NEW:
      // Ecriture seule n'importe o�
      // Si le fichier existe d�j�, effacement du contenu
      // Si n'existe pas, cr�ation
      m_IsRead   = FALSE;
      m_IsWrite  = TRUE;
      m_IsAppend = FALSE;
      strcpy(Mode,"wb");
      break;

   case CE_F_W_APPEND:
      // Ecriture seule � la fin du fichier
      m_IsRead   = FALSE;
      m_IsWrite  = TRUE;
      m_IsAppend = TRUE;
      strcpy(Mode,"ab");
      break;

   case CE_F_RW:
      // Lecture et �criture n'importe o�
      // Si n'existe pas, cr�ation
      if (Portable_access( m_FileName,0) == 0)
         {
         // Le fichier existe ==> "vrai" update
         m_IsRead   = TRUE;
         m_IsWrite  = TRUE;
         m_IsAppend = FALSE;
         strcpy(Mode,"r+b");
         }
      else
         {
         // Le fichier n'existe pas ==> comme CE_F_RW_NEW
         m_IsRead   = TRUE;
         m_IsWrite  = TRUE;
         m_IsAppend = FALSE;
         strcpy(Mode,"w+b");
         }
      break;

   case CE_F_RW_NEW:
      // Lecture et �criture n'importe o�
      // Si le fichier existe d�j�, effacement du contenu
      // Si n'existe pas, cr�ation
      m_IsRead   = TRUE;
      m_IsWrite  = TRUE;
      m_IsAppend = FALSE;
      strcpy(Mode,"w+b");
      break;

   case CE_F_RW_APPEND:
      // Lecture et �criture � la fin du fichier
      m_IsRead   = TRUE;
      m_IsWrite  = TRUE;
      m_IsAppend = TRUE;
      strcpy(Mode,"a+b");
      break;

   default:
      // Lecture seule
      m_IsRead   = TRUE;
      m_IsWrite  = FALSE;
      m_IsAppend = FALSE;
      strcpy(Mode,"rb");
      break;
   }

MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"Mode=%s", Mode));

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------

#if defined(BDA_TWIN16)
// --- Traitement TwinServer (debut) 
int _fSavemode = _fmode;

if (Flags & CE_F_NGF)
   {
   // Taille en granule pour NGF
   // la taille contenu dans le descripteur est ignor�e
   _fmode = 0x0080 /*_O_SHARE FCH03052006 */;
   }
else
   {
   // Taille � l'octet pr�s sur un volume NGF
   // la taille contenu dans le descripteur est prise en compte
   _fmode = O_NGF_LNWR | O_NGF_LNRD | 0x0080 /*_O_SHARE*/;
   }

MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"_fmode=%04X", _fmode));
// --- Traitement TwinServer (fin) 
#endif

m_Handle = fopen( m_FileName, Mode);
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"fopen errno %d", errno));

#if defined(BDA_TWIN16)
// --- Traitement TwinServer (debut) 
_fmode = _fSavemode;
// --- Traitement TwinServer (fin) 
#endif

if (!m_Handle)
   ret = (errno==ENOENT) ? ERR_NOFILE : ERR_ACCESS;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d (%08lX)", ret, m_Handle));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Close
// * NO_ERRORS , ERR_WRITE
// ***********************************************************************************
short CStreamBin::Close()
{
MI_TRACE_DCL_TFN("stbin_Close");
short ret = NO_ERRORS;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

if (m_Handle)
   {
   ret = (fclose(m_Handle) == EOF) ? ERR_WRITE : NO_ERRORS;
   }

if (ret==NO_ERRORS)
   {
   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"avant _clean" ));
   _Clean();
   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"apres _clean" ));
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Save
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_WRITE
// ***********************************************************************************
short CStreamBin::Save()
{
MI_TRACE_DCL_TFN("stbin_Save");
long  MemoTell;
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForWrite()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
MemoTell = _mytell();

if (fflush(m_Handle) == EOF)
   ret = ERR_WRITE;

_myseek(MemoTell,SEEK_SET);

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Write( buffer , LgBuf , pLg )
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_WRITE
// ***********************************************************************************
short CStreamBin::Write( const unsigned char* Buf, long LgBuf, long* pLg  )
{
MI_TRACE_DCL_TFN("stbin_WriteBuf");
short ret;
long Lg;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForWrite()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeWrite();

if (ret==NO_ERRORS)
   {
   ret = _mywrite( Buf, LgBuf, &Lg );

   // Si on veut la longueur en sortie, on la donne
   if (pLg!=NULL)
      *pLg = Lg;
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Write( octet )
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_WRITE
// ***********************************************************************************
short CStreamBin::Write( unsigned char c )
{
MI_TRACE_DCL_TFN("stbin_Write");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForWrite()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeWrite();

if (ret==NO_ERRORS)
   ret = _myputc(c);

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Read( buffer, longueur)
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_READ
// ***********************************************************************************
short CStreamBin::Read( unsigned char* Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("stbin_ReadBuf");
long Lg;
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   Lg = fread( Buf, 1, (size_t)LgBuf, m_Handle);

   MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"LgIn=%ld LgOut=%ld",LgBuf,Lg));

   // Si la longueur r�ellement lue est plus petite que la longueur demand�e
   // c'est qu'il y a eu un probl�me pendant la lecture
   if (Lg<LgBuf)
      ret = (_myeof_basic()) ? ERR_EOF : ERR_READ;

   // Si on veut la longueur lue en sortie, on la donne
   if (pLg!=NULL)
      *pLg = Lg;
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Read( octet )
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_READ , ERR_EOF
// ***********************************************************************************
short CStreamBin::Read( unsigned char* c )
{
MI_TRACE_DCL_TFN("stbin_Read");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   ret = _mygetc(c);

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Find( c , SeekAfter )
// * Recherche un caract�re depuis la position courante
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_READ
// ***********************************************************************************
short CStreamBin::Find (  unsigned char c, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stbin_FindByte");
short ret;
short car;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   do car = _mygetc_basic();
   while ((car!=EOF) && (car!=c));

   if (car == EOF)
      ret = (_myeof_basic()) ? ERR_EOF : ERR_READ;

   if ((ret==NO_ERRORS) && (!SeekAfter))
      if ( _myseek_basic( -1, SEEK_CUR) )
         ret = ERR_SEEK;
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Find( Buf , LgBuf , SeekAfter )
// * Recherche un buffer depuis la position courante
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_READ
// ***********************************************************************************
short CStreamBin::Find ( const unsigned char* Buf, long LgBuf, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stbin_FindBuf");
short ret;
short car;
BOOL  IsFound;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if (LgBuf==0)
   return NO_ERRORS;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   long i;
   long MemoOffset;

   car = _mygetc_basic();
   //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(1) car=%04X",car));
   IsFound = FALSE;
   do {
      i=0;

      while ((car!=EOF) && (car!=Buf[i]))
         {
         car = _mygetc_basic();
         //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(2) car=%04X",car));
         }

      if (car!=EOF)
         {
         MemoOffset = _mytell()-1;
         //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"tell"));

         IsFound = TRUE;
         i++;
         while ((car!=EOF) && (i<LgBuf) && IsFound)
            {
            car = _mygetc_basic();
            //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"(3) car=%04X",car));
            IsFound = (car==Buf[i]);
            i++;
            }
         }
       }
    while((car!=EOF) && !IsFound); // FCH21102002 suppression test de (i<LgBuf)

   if (car == EOF)
      {
      //MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"EOF"));
      ret = (_myeof_basic()) ? ERR_EOF : ERR_READ;
      }

   if ((IsFound) && (!SeekAfter))
      if ( _myseek_basic( MemoOffset, SEEK_SET) )
         ret = ERR_SEEK;
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::FindInCollection( Buf , LgBuf , pc , SeekAfter )
// * Recherche un buffer depuis la position courante
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK , ERR_READ
// ***********************************************************************************
short CStreamBin::FindInCollection ( const unsigned char* Buf, long LgBuf, unsigned char* pc, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stbin_FindInColl");
short ret;
short car;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if (LgBuf==0)
   return NO_ERRORS;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   long i;
   unsigned char c;
   do {
      car = _mygetc_basic();
      if (car != EOF)
         {
         i=0;
         do c = Buf[i++];
         while ((i<LgBuf) && (car!=c));
         }
      }
   while ((car!=EOF) && (car!=c));

   if (car == EOF)
      ret = (_myeof_basic()) ? ERR_EOF : ERR_READ;

  if (pc!=NULL)
    *pc = (car == EOF) ? 0 : (char)car;

   if ((ret==NO_ERRORS) && (!SeekAfter))
      if ( _myseek_basic( -1, SEEK_CUR) )
         ret = ERR_SEEK;
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"c=%02X", (pc) ? *pc : 0 ));
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Seek
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK
// ***********************************************************************************
short CStreamBin::Seek ( long Offset, short Orig )
{
MI_TRACE_DCL_TFN("stbin_Seek");
short ret = NO_ERRORS;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOk()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
MI_TRACE((CI_TRA_F_INFO_LOW,CI_MODULE_ID,TFN,"Offset=%ld Orig=%d",Offset,Orig));

ret = _PositBeforeSeek();

if (ret==NO_ERRORS)
   if ( _myseek_basic( Offset, _ConvSeek(Orig)) )
      ret = ERR_SEEK;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::Tell
// * Position courante (-1 si erreur)
// ***********************************************************************************
long CStreamBin::Tell ( )
{
MI_TRACE_DCL_TFN("stbin_Tell");
long  Offset;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

Offset = (m_Handle) ? _mytell() : -1;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%08lX) %ld",m_Handle,Offset));
return Offset;
}

// ***********************************************************************************
// * CStreamBin::GetFileSize
// * taille du fichier (-1 si erreur)
// * Fait tomber le Eof
// ***********************************************************************************
long CStreamBin::GetFileSize()
{
MI_TRACE_DCL_TFN("stbin_GetFileSize");
long  Offset;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));
Offset = (m_Handle) ? _GetFileSize() : -1;
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%08lX) %ld",m_Handle,Offset));
return Offset;
}

// ***********************************************************************************
// * CStreamBin::GetError
// ***********************************************************************************
short CStreamBin::GetError()
{
MI_TRACE_DCL_TFN("stbin_GetError");
short ret;

ret = (m_Handle) ? ( (ferror(m_Handle)) ? errno : 0) : 0;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%08lX) %d",m_Handle,ret));
return ret;
}

// ***********************************************************************************
// * CStreamBin::ClearError
// ***********************************************************************************
short CStreamBin::ClearError()
{
MI_TRACE_DCL_TFN("stbin_ClearError");

if (m_Handle!=NULL)
   _myclearerr();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%08lX)",m_Handle));
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamBin::Eof
// * TRUE FALSE
// ***********************************************************************************
short CStreamBin::Eof()
{
MI_TRACE_DCL_TFN("stbin_Eof");
short ret;

if (m_Handle)
   ret = (_myeof_basic()) ? TRUE : FALSE;
else
   ret = TRUE;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"(%08lX) %d",m_Handle,ret));
return ret;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CStreamLine
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// ***********************************************************************************
// * CStreamLine::_Clean
// ***********************************************************************************
void CStreamLine::_Clean()
{
m_IsFormatForce   = FALSE;
m_IsFormatCtrlz   = FALSE;
m_IsFormatCr      = FALSE;

_CleanInfoLine();
CStreamBin::_Clean();
}

// ***********************************************************************************
// * CStreamLine::_TreatEof
// * Traitement sur d�tection de fin de fichier sur Eof
// * ERR_EOF , ERR_READ
// ***********************************************************************************
short CStreamLine::_TreatEof()
{
short ret = (_myeof_basic()) ? ERR_EOF : ERR_READ;
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"_TreatEof"," "));

if (ret==ERR_EOF)
   {
   // M�morisation fin de fichier
   m_Eof_IsFound  = TRUE;
   m_Eof_MemoTell = _mytell();
   }
else
   {
   // Il y a un gros probl�me
   // Effacement m�mo
   m_Eof_IsFound  = FALSE;
   m_Eof_MemoTell = 0;
   }

m_Ctrlz_IsFound = FALSE;
return ret;
}


// ***********************************************************************************
// * CStreamLine::_TreatCtrlz
// * Traitement sur d�tection de fin de fichier sur Ctrlz
// * ERR_EOF
// ***********************************************************************************
short CStreamLine::_TreatCtrlz()
{
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"_TreatCtrlz"," "));
m_Ctrlz_IsFound = TRUE;
m_Eof_IsFound   = TRUE;

// On recule sur le Ctrlz pour ne pas d�passer la fin logique du fichier
_myseek(-1,SEEK_CUR);

m_Eof_MemoTell  = _mytell();
return ERR_EOF;
}

// ***********************************************************************************
// * CStreamLine::_TreatEol
// * Traitement sur fin de ligne
// * NO_ERRORS
// ***********************************************************************************
short CStreamLine::_TreatEol()
{
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"_TreatEol"," "));
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamLine::_TreatCr
// * Traitement sur caract�re CR
// * NO_ERRORS
// ***********************************************************************************
short CStreamLine::_TreatCr()
{
MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"_TreatCr"," "));
m_Cr_IsFound = TRUE;
return NO_ERRORS;
}

// ***********************************************************************************
// * CStreamLine::_TreatTab ( &iNew )
// * Traitement sur caract�re tabulation
// * Calcul de la taille
// * NO_ERRORS 
// ***********************************************************************************
short CStreamLine::_TreatTab( long& iNew )
{
iNew += (m_LgTab-(iNew%m_LgTab));
return NO_ERRORS ;
}

// ***********************************************************************************
// * CStreamLine::_TreatTab ( Buf, LgBuf, &iNew )
// *
// * Traitement sur caract�re tabulation
// * On v�rifie qu'on ne la d�passe pas la longueur du tableau
// * et bourrage � ' '
// * NO_ERRORS , ERR_LEN
// ***********************************************************************************
short CStreamLine::_TreatTab( unsigned char* Buf, long LgBuf, long& iNew )
{
long iMemo = iNew;
_TreatTab(iNew);

if (iNew>=LgBuf)
   {
   // Ca ne tient pas dans le buffer, on ignore la tabulation
   iNew = iMemo;
   return ERR_LEN;
   }
else
   {
   // Ca tient dans le buffer, on bourre avec des espaces
   long i;
   for (i=iMemo ; i<iNew ; i++)
      Buf[i] = ' ';
   return NO_ERRORS ;
   }
}

// ***********************************************************************************
// * CStreamLine::_ReadUntilEol( Buf , LgBuf , &Lg )
// * Lecture d'une ligne et �criture dans un buffer
// *
// * Lecture caract�re par caract�re d'une ligne depuis la position courante
// * avec analyse de chaque caract�re.
// * NO_ERRORS , ERR_EOF , ERR_READ , ERR_LEN
// ***********************************************************************************
short CStreamLine::_ReadUntilEol( short IsPad, unsigned char* Buf, long LgBuf, long& Lg )
{
short car;
short ret;

// --- Tout � blanc
// Selon param�trage
if (IsPad)
   memset(Buf,' ',(size_t)LgBuf);

// --- Lecture du fichier et remplissage du buffer
Lg  = 0;
while(TRUE)
   {
   car=_mygetc_basic();

   if (car==EOF)
      {
      ret = _TreatEof();
      break;
      }
   else if (car==0x1A)
      {
      ret = _TreatCtrlz();
      break;
      }
   else if (car==0x0A)
      {
      ret = _TreatEol();
      break;
      }
   else if ((car==0x0C) && (m_IsFormFeed))
      {
      ret = _TreatEol();
      break;
      }
   else if ((car==0x09) && (m_LgTab))
      {
      ret = _TreatTab(Buf,LgBuf,Lg);
      if (ret==ERR_LEN)
         _myseek(-1,SEEK_CUR); // on relira la tabulation au prochain coup
      }
   else if (car==0x0D)
      _TreatCr();
   else
      {
      Buf[Lg++]=(unsigned char)car;
      if (Lg>=LgBuf)
         {
         ret = ERR_LEN;
         break;
         }
      }
   }
return ret;
}

// ***********************************************************************************
// * CStreamLine::_ReadUntilEol( &Lg )
// * Lecture d'une ligne pour analyse seulement
// *
// * Lecture caract�re par caract�re d'une ligne depuis la position courante
// * avec analyse de chaque caract�re.
// * NO_ERRORS , ERR_EOF , ERR_READ , ERR_LEN
// ***********************************************************************************
short CStreamLine::_ReadUntilEol( long& Lg )
{
short car;
short ret;

Lg     = 0;
while(TRUE)
   {
   car=_mygetc_basic();

   if (car==EOF)
      {
      ret = _TreatEof();
      break;
      }
   else if (car==0x1A)
      {
      ret = _TreatCtrlz();
      break;
      }
   else if (car==0x0A)
      {
      ret = _TreatEol();
      break;
      }
   else if ((car==0x0C) && (m_IsFormFeed))
      {
      ret = _TreatEol();
      break;
      }
   else if ((car==0x09) && (m_LgTab))
      {
      _TreatTab(Lg);
      }
   else if (car==0x0D)
      {
      _TreatCr();
      }
   else
      {
      Lg++;
      }
   }
return ret;
}

// ***********************************************************************************
// * CStreamLine::_CleanInfoLine
// ***********************************************************************************
void CStreamLine::_CleanInfoLine()
{
// Efface le format identifi�
m_Ctrlz_IsFound = FALSE;
m_Cr_IsFound    = FALSE;

// Efface la d�tection de fin de fichier
m_Eof_IsFound   = FALSE;
m_Eof_IsReached = FALSE;
m_Eof_MemoTell  = 0;

// Efface la d�tection des lignes
m_Lines_IsValid = FALSE;
m_Lines_List.ClearAll();
}

// ***********************************************************************************
// * CStreamLine::_CreateInfoLine
// * Cr�ation des infos ligne
// * NO_ERRORS , ERR_EOF , ERR_READ , ERR_WRITE , ERR_MEM
// ***********************************************************************************
short CStreamLine::_CreateInfoLine()
{
short ret;
long  MemoOffset;
long  Offset;
long  Lg;

MemoOffset = _mytell();

_CleanInfoLine();

_myseek(0, SEEK_SET);
do
   {
   Offset = _mytell();
   ret = _ReadUntilEol( Lg );
   MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,"_CreateInfoLine","(offset,lg)=(%lu,%lu)",Offset,Lg));
   m_Lines_List.AddAtEnd(Offset, Lg);
   }
while( ret == NO_ERRORS );

m_Lines_IsValid = m_Lines_List.IsValid();
ret = (m_Lines_IsValid) ? ret : ERR_MEM;

_myseek(MemoOffset, SEEK_SET);
if (ret==ERR_EOF)
   ret = NO_ERRORS;
return ret;
}

// ***********************************************************************************
// * CStreamLine::_UpdateInfoLine
// * Mise � jour des infos de ligne apr�s un ajout de ligne en fin de fichier
// * NO_ERRORS , ERR_MEM
// ***********************************************************************************
short CStreamLine::_UpdateInfoLine(long Offset)
{
long  Lg;

// --- M�morisation de la nouvelle fin de fichier
m_Eof_MemoTell = _mytell();

// --- Analyse de la ligne que l'on vient d'ins�rer
// la taille logique peut �tre diff�rente de la taille physique
// � cause des expansions de tabulation
_myseek(Offset, SEEK_SET);
_ReadUntilEol( Lg );
_myseek(m_Eof_MemoTell, SEEK_SET);

// --- Mise � jour (ou ajout) de la ligne � la liste chain�e
m_Lines_List.InsertFromEnd(Offset, Lg);

// --- Ajout de la ligne vide qui suit
// car on a jout� un EOL � la fin
m_Lines_List.AddAtEnd(m_Eof_MemoTell, 0);

m_Lines_IsValid = m_Lines_List.IsValid();

return (m_Lines_IsValid) ? NO_ERRORS : ERR_MEM;
}

// ***********************************************************************************
// * CStreamLine::_IsAddCtrlz
// * CStreamLine::_IsAddCr
// *
// * Si on a d�fini le format forc� lors de l'appel � Open, on applique ce format
// * Sinon, on applique le format d�tect�
// *
// ***********************************************************************************
BOOL CStreamLine::_IsAddCtrlz()
{
return (m_IsFormatForce) ? m_IsFormatCtrlz : m_Ctrlz_IsFound;
}

// ***********************************************************************************
BOOL CStreamLine::_IsAddCr()
{
return (m_IsFormatForce) ? m_IsFormatCr : m_Cr_IsFound;
}

// ***********************************************************************************
// * CStreamLine::_SetEofReached
// * CStreamLine::_ResetEofReached
// *
// * Pour avoir le m�me comportement que Eof binaire, il faut m�moriser
// * la fin de fichier � chaque lecture, et l'effacer � chaque
// * Seek, LnSeek, Read, Find, ClearError
// *
// ***********************************************************************************
void  CStreamLine::_SetEofReached()
{
m_Eof_IsReached = (m_Eof_IsFound) && (_mytell() >= m_Eof_MemoTell);
}

// ***********************************************************************************
void  CStreamLine::_ResetEofReached()
{
m_Eof_IsReached = FALSE;
}

// ***********************************************************************************
// * CStreamLine::_Lower
// ***********************************************************************************
unsigned char CStreamLine::_Lower( unsigned char c)
{
return ((c>='A') && (c<='Z')) ? c-'A'+'a' : c;
}
// ***********************************************************************************
// * CStreamLine::_IsStrEqual
// ***********************************************************************************
BOOL  CStreamLine::_IsStrEqual( const unsigned char* Buf1, long LgBuf1, const unsigned char* Buf2, long LgBuf2, short IsCaseSens)
{
BOOL  Egal;
long i;

if ( (LgBuf1 != LgBuf2) || (Buf1==NULL) || (Buf2==NULL))
   return FALSE;

i = 0;

if (IsCaseSens)
   do {
      Egal = (Buf1[i] == Buf2[i]);      
      i++;
      }
   while ((Egal) && (i<LgBuf1));
else
   do {
      Egal = (_Lower(Buf1[i]) == _Lower(Buf2[i]));      
      i++;
      }
   while ((Egal) && (i<LgBuf1));

return Egal;
}

// ***********************************************************************************
// * CStreamLine::_IniReadSection
// ***********************************************************************************
short CStreamLine::_IniReadSection( CIniLine& Line, unsigned char* Sec, long LgSec, long* pLg)
{
short ret;

// --- Boucle de lecture d'un item
do {
   ret = _ReadUntilEol( FALSE, Line.m_pLine, Line.m_LgMaxLine, Line.m_LgAnaLine);

   if (ret==ERR_LEN)
    {
    // Le buffer est trop petit. On se replace au d�but de la ligne,
    // on prend un buffer de la bonne taille, et on relit la ligne
    // Attention, cela entraine obligatoirement une analyse du fichier
    LnSeek(0,CE_SEEK_CUR);
    ret = Line.Alloc( LnGetLength() );
    if (ret==NO_ERRORS)
       ret = _ReadUntilEol( FALSE, Line.m_pLine, Line.m_LgMaxLine, Line.m_LgAnaLine );
    }

   if ((ret==NO_ERRORS) || (ret==ERR_EOF))
      if (Line.AnalyseForSection()==ERR_MEM)
         ret = ERR_MEM;
   }
while (  (ret==NO_ERRORS)
      && !Line.IsSection() 
      );

// --- Traitement d'erreur
//     On efface l'item car il n'est pas valide
if ((ret!=NO_ERRORS) && (ret!=ERR_EOF))
   Line.Free();

// --- Copie de la section
//     avec initialisation des param�tres de retour
if (  !Line.CopySection(Sec,LgSec,pLg)
   && ((ret==NO_ERRORS) || (ret==ERR_EOF))
   )
   ret = ERR_LEN;
      
// --- Conversion du code retour
//     Si une cl� est trouv�e en fin de fichier, on renvoie OK
//     pour simplifier le traitement dans l'appelant
if ( (ret==ERR_EOF) && Line.IsSection() )
   ret = NO_ERRORS;

_SetEofReached();

return ret;
}

// ***********************************************************************************
// * CStreamLine::_IniReadKey
// ***********************************************************************************
short CStreamLine::_IniReadKey( CIniLine& Line, unsigned char* Key, long LgKey, long* pLgKey, unsigned char* Val, long LgVal, long* pLgVal )
{
short ret;
long  MemoTell;

// --- Boucle de lecture d'un item
do {
   MemoTell = _mytell();
   ret = _ReadUntilEol( FALSE, Line.m_pLine, Line.m_LgMaxLine, Line.m_LgAnaLine );

   if (ret==ERR_LEN)
    {
    // Le buffer est trop petit. On se replace au d�but de la ligne,
    // on prend un buffer de la bonne taille, et on relit la ligne
    // Attention, cela entraine obligatoirement une analyse du fichier
    LnSeek(0,CE_SEEK_CUR);
    ret = Line.Alloc( LnGetLength() );
    if (ret==NO_ERRORS)
       ret = _ReadUntilEol( FALSE, Line.m_pLine, Line.m_LgMaxLine, Line.m_LgAnaLine );
    }

   if ((ret==NO_ERRORS) || (ret==ERR_EOF))
      if (Line.AnalyseForKey()==ERR_MEM)
         ret = ERR_MEM;
   }
while (  (ret==NO_ERRORS) 
      && !Line.IsKey() 
      && !Line.IsKeyValue() 
      && !Line.IsSection()
      );

// --- Traitement si l'item est une section
//     on se replace en d�but de ligne
if (Line.IsSection())
   {
   ret = ERR_SECTION;
   _myseek(MemoTell,SEEK_SET);
   }

// --- Traitement d'erreur
//     On efface l'item car il n'est pas valide
if ((ret!=NO_ERRORS) && (ret!=ERR_EOF))
   Line.Free();

// --- Copie de la cl� et de la valeur �ventuelle
//     avec initialisation des param�tres de retour
if (  !Line.CopyKey(Key,LgKey,pLgKey) 
   && ((ret==NO_ERRORS) || (ret==ERR_EOF)) 
   )
   ret = ERR_LEN;   

if (  !Line.CopyValue(Val,LgVal,pLgVal)
   && ((ret==NO_ERRORS) || (ret==ERR_EOF)) 
   )
   ret = ERR_LEN;
      
// --- Conversion du code retour
//     Si une cl� est trouv�e en fin de fichier, on renvoie OK
//     pour simplifier le traitement dans l'appelant
if ( (ret==ERR_EOF) && (Line.IsKey() || Line.IsKeyValue()) )
   ret = NO_ERRORS;

_SetEofReached();

return ret;
}













// ***********************************************************************************
// * CStreamLine::CStreamLine
// ***********************************************************************************
CStreamLine::CStreamLine(short LgTab, short IsPad, short IsFormFeed)
{
_Clean();
m_LgTab      = LgTab;
m_IsPad      = IsPad;
m_IsFormFeed = IsFormFeed;
}

// ***********************************************************************************
// * CStreamLine::~CStreamLine
// ***********************************************************************************
CStreamLine::~CStreamLine()
{
}

// ***********************************************************************************
// * CStreamLine::Open
// * Ouverture du fichier en mode binaire
// * Flags = - CE_F_CHK_NOEXIST        ouvre si fichier n'existe pas
// *         - CE_F_CHK_EXIST          ouvre si fichier existe
// *         - CE_F_NOCHK              (d�faut)
// *       +
// *         - CE_F_R                  lecture
// *         - CE_F_RW                 lecture et �criture partout
// *         - CE_F_RW_NEW             lecture et �criture partout, si existe efface le contenu
// *       +
// *         - CE_F_STREAM_F_ADD_CTRLZ
// *         - CE_F_STREAM_F_ADD_CR
// *
// * erreurs de Open , ERR_PARAM
// ***********************************************************************************
short CStreamLine::Open( const char* sFileName, WORD Flags )
{
MI_TRACE_DCL_TFN("stline_Open");
short ret = NO_ERRORS;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin"));

// ----------------------------------------------------------------
// - Coh�rence propre au mode texte
// - Il faut toujours �tre en lecture pour analyser le fichier.
// - De plus, le mode Append est interdit � cause du Ctrlz.
// ----------------------------------------------------------------
switch (Flags & CE_STREAM_F_MASK_MODE)
   {
   case CE_F_W_NEW:
   case CE_F_W_APPEND:
   case CE_F_RW_APPEND:
      ret = ERR_PARAM;
      break;
   }

if (ret != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// - Traitement
// ----------------------------------------------------------------
ret = CStreamBin::Open(sFileName,Flags);

// ----------------------------------------------------------------
// - Param�tres pour format d'�criture
// ----------------------------------------------------------------
if (ret == NO_ERRORS)
   {
   // --- For�age du format dans les flags
   m_IsFormatCtrlz = ((Flags&CE_F_SET_EOF) == CE_F_SET_EOF);
   m_IsFormatCr    = ((Flags&CE_F_SET_CR)  == CE_F_SET_CR);
   m_IsFormatForce = ((Flags&CE_F_SET_NONE)== CE_F_SET_NONE);

   // --- Format automatique, on g�n�re selon l'OS si le fichier est nouveau
   if (!m_IsFormatForce)
      {
      // Si le fichier est vide, donc on force le standard de l'OS
      m_IsFormatForce = (CStreamBin::_GetFileSize()==0);

      #if   defined(BDA_TWIN16)
      m_IsFormatCtrlz = TRUE;
      m_IsFormatCr    = TRUE;

      #elif defined(BDA_WIN32)
      m_IsFormatCtrlz = FALSE;
      m_IsFormatCr    = TRUE;

      #elif defined(BDA_UNIX)
      m_IsFormatCtrlz = FALSE;
      m_IsFormatCr    = FALSE;

      #endif

      }
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End (%08lX) %d", m_Handle, ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Close
// * erreurs de Close
// ***********************************************************************************
short CStreamLine::Close()
{
MI_TRACE_DCL_TFN("stline_Close");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// --- Gestion du Ctrlz avant fermeture
if ( m_MemoModif && _IsAddCtrlz() )
   {
   ret = (m_Eof_IsFound) ? NO_ERRORS : _CreateInfoLine();

   if (ret == NO_ERRORS)
      ret = CStreamBin::Seek(m_Eof_MemoTell, CE_SEEK_SET );

   if (ret==NO_ERRORS)
      CStreamBin::Write(0x1A);
   }

ret = CStreamBin::Close();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnSetExpandTab
// * Initialise la transformation des tabulations en espaces, 
// * mais n'a aucun effet lorsqu'une analyse a �t� effectu�e.
// * (il faut utiliser cette m�thode avant tout acc�s au fichier)
// * renvoie l'ancienne valeur ou -1 si interdit
// ***********************************************************************************
short CStreamLine::LnSetExpandTab( short LgTab )
{
short Old = m_LgTab;
if (m_Lines_IsValid)
   return -1;

if (LgTab>=0)
   m_LgTab = LgTab;

return Old;
}

// ***********************************************************************************
// * CStreamLine::LnGetExpandTab
// * renvoie la valeur courante
// ***********************************************************************************
short CStreamLine::LnGetExpandTab()
{
return m_LgTab;
}

// ***********************************************************************************
// * CStreamLine::LnSetPad
// * Initialise le padding du buffer avec des espaces,
// * mais n'a aucun effet lorsqu'une analyse a �t� effectu�e, pour avoir le m�me 
// * comportement que SetExpandTab.
// * (il faut utiliser cette m�thode avant tout acc�s au fichier)
// * renvoie l'ancienne valeur ou -1 si interdit
// ***********************************************************************************
short CStreamLine::LnSetPad( short IsPad )
{
short Old = m_IsPad;
if (m_Lines_IsValid)
   return -1;

m_IsPad = IsPad;

return Old;
}

// ***********************************************************************************
// * CStreamLine::LnGetPad
// * renvoie la valeur courante
// ***********************************************************************************
short CStreamLine::LnGetPad()
{
return m_IsPad;
}

// ***********************************************************************************
// * CStreamLine::LnSetFormFeed
// * Initialise la prise en compte de caract�re FormFeed comme un LineFeed
// * mais n'a aucun effet lorsqu'une analyse a �t� effectu�e, pour avoir le m�me 
// * comportement que SetExpandTab.
// * (il faut utiliser cette m�thode avant tout acc�s au fichier)
// * renvoie l'ancienne valeur ou -1 si interdit
// ***********************************************************************************
short CStreamLine::LnSetFormFeed( short IsFormFeed )
{
short Old = m_IsFormFeed;
if (m_Lines_IsValid)
   return -1;

m_IsFormFeed = IsFormFeed;

return Old;
}

// ***********************************************************************************
// * CStreamLine::LnGetFormFeed
// * renvoie la valeur courante
// ***********************************************************************************
short CStreamLine::LnGetFormFeed()
{
return m_IsFormFeed;
}

// ***********************************************************************************
// * CStreamLine::LnWrite
// * Ecriture d'une ligne de texte toujours en fin de fichier
// * Les caract�res sp�ciaux (Cr,Lf,Ctrlz) sont ajout�s
// ***********************************************************************************
short CStreamLine::LnWrite( const unsigned char* Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("stline_LnWrite");
short ret;
long  Lg;
long  OffsetBeginLine;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForWrite()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// Les diff�rentes �tapes sont :
//    - V�rifier si la ligne pr�c�dente est bien termin�e par un EOL
//      Si ce n'est pas le cas, il faut le rajouter.
//    - Ecrire le contenu de la ligne.
//    - Ajouter les EOL et EOF.
//    - Mettre � jour la liste des infos de lignes avec les infos 
//      sur cette nouvelle ligne. 
// ----------------------------------------------------------------

// Attention, apr�s l'appel � _PositBeforeWrite, on va faire des seek et des read
// Il faudra refaire � la main l'�quivalent d'un appel � cette fonction lors des passages
// read <--> write (ce sera indiqu� dans les commentaires)
ret = _PositBeforeWrite();

if (ret==NO_ERRORS)
   ret = (m_Eof_IsFound) ? NO_ERRORS : _CreateInfoLine();

if (ret==NO_ERRORS)
   {
   // On se place � la fin logique du fichier
   ret = _myseek(m_Eof_MemoTell, SEEK_SET);
   if (ret==NO_ERRORS)
      {
      // ----------------------------------------------------------
      // V�rifier si la ligne pr�c�dente est bien termin�e
      // ----------------------------------------------------------

      // On tente de se placer sur l'octet pr�c�dent
      ret = _myseek(-1, SEEK_CUR);
      if (ret==NO_ERRORS)
         {
         // --- Le seek est OK
         // On regarde si cet octet est une fin de ligne
         // Si ce n'est pas le cas, on l'ajoute
         // ( Rq: on n'a pas besoin d'appeler _PositBeforeRead )
         // ( car on a fait des seek avant                     )
         unsigned char car;
         ret = _mygetc(&car);

         // Blindage passage read --> write
         _myseek(0,SEEK_CUR);

         if ((ret==NO_ERRORS) && (car!=0x0A))
            {
            MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"preWrite add EOL",m_Handle));
            // Ajout du Cr si n�cessaire
            if ( (ret==NO_ERRORS) && _IsAddCr() )
               ret = _myputc(0x0D);
            // Ajout du Lf
            if (ret==NO_ERRORS)
               ret = _myputc(0x0A);
            }
         }
      else
         {
         // --- Le seek n'est pas bon
         // Il n'y a pas d'octet pr�c�dent, on est donc au d�but du fichier
         // on se repositionne correctement
         _myclearerr();
         ret = _myseek(m_Eof_MemoTell, SEEK_SET);
         }

      // ----------------------------------------------------------
      // Ecrire de la ligne
      // ----------------------------------------------------------
      if (ret==NO_ERRORS)
         {
         // M�morisation de la position pour la mise � jour
         OffsetBeginLine = _mytell();

         // Ecriture
         MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"Write ligne",m_Handle));
         ret = _mywrite( Buf, LgBuf, &Lg);

         // Si on veut la longueur en sortie, on la donne
         if (pLg!=NULL)
            *pLg = Lg;
         }

      // ----------------------------------------------------------
      // Ecrire la fin de ligne et fin de fichier
      // ----------------------------------------------------------

      // Ajout du Cr si n�cessaire
      if ( (ret==NO_ERRORS) && _IsAddCr() )
         {
         MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"postWrite 0D",m_Handle));
         ret = _myputc(0x0D);
         }

      // Ajout du Lf
      if (ret==NO_ERRORS)
         {
         MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"postWrite 0A",m_Handle));
         ret = _myputc(0x0A);
         }

      // Ajout du Ctrlz si n�cessaire
      if ( (ret==NO_ERRORS) && _IsAddCtrlz() )
         {
         MI_TRACE((CI_TRA_F_DEBUG,CI_MODULE_ID,TFN,"postWrite 1A",m_Handle));
         ret = _myputc(0x1A);
         // on se replace sur le Ctrlz
         _myseek(-1,CE_SEEK_CUR);
         }

      // ----------------------------------------------------------
      // Mettre � jour les infos de ligne
      // ----------------------------------------------------------
      if (ret==NO_ERRORS)
         _UpdateInfoLine(OffsetBeginLine);
      }
    }

// Remise � faux, pour avoir le m�me comportement qu'un write binaire
_ResetEofReached();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnRead
// * Lit depuis la position courante jusqu'� la fin de la ligne ou du buffer.
// * La position courante n'est pas forc�ment le d�but de la ligne, ce qui permet
// * de lire une ligne tr�s longue en plusieurs appels.
// *
// * NO_ERRORS , ERR_EOF , ERR_READ , ERR_BAD_CALL , ERR_SEEK , ERR_PARAM  , ERR_LEN
// ***********************************************************************************
short CStreamLine::LnRead( unsigned char* Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("stline_LnRead");
long Lg;
short ret = NO_ERRORS;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if ((Buf==NULL) || (LgBuf==0))
   {
   ret = ERR_PARAM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   ret = _ReadUntilEol( m_IsPad, Buf, LgBuf, Lg);

_SetEofReached();

if (pLg!=NULL)
   *pLg = Lg;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnGetLength
// * Renvoie la longueur jusqu'� la fin de la ligne.
// * Comme pour ReadToEndOfLine, on n'est pas foc�ment au d�but de la ligne.
// * Fait tomber le Eof pour avoir le m�me comportement que GetFileSize
// ***********************************************************************************
long CStreamLine::LnGetLength()
{
MI_TRACE_DCL_TFN("stline_LnGetLength");
short  ret;
long  Offset;
long  Lg;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   Offset = CStreamBin::Tell();
   _ReadUntilEol( Lg );
   CStreamBin::Seek( Offset, CE_SEEK_SET);
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", Lg));
return Lg;
}

// ***********************************************************************************
// * CStreamLine::LnAnalyse
// * Force l'analyse du fichier texte.
// *
// * L'analyse du fichier texte est effectu�e automatiquement lorsque cela est
// * n�cessaire. Cependant, pour des gros fichiers, il peut �tre int�ressant
// * d'effectuer cette analyse � un moment appropri�.
// *
// * NO_ERRORS , ERR_READ , ERR_MEM
// ***********************************************************************************
short CStreamLine::LnAnalyse()
{
MI_TRACE_DCL_TFN("stline_LnAnalyse");
short  ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _CreateInfoLine();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnGetFileFormat
// * Renvoie les infos de format
// * NO_ERRORS , ERR_READ , ERR_MEM
// ***********************************************************************************
short CStreamLine::LnGetFileFormat( WORD* pIsCr, WORD* pIsCtrlz )
{
MI_TRACE_DCL_TFN("stline_LnGetFileFormat");
short  ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

if (pIsCr)
   *pIsCr = m_Cr_IsFound;

if (pIsCtrlz)
   *pIsCtrlz = m_Ctrlz_IsFound;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnGetLengthLine
// ***********************************************************************************
long  CStreamLine::LnGetLengthLine()
{
MI_TRACE_DCL_TFN("stline_LnGetLengthLine");
short  ret;
long   Lg=-1;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", Lg)) , Lg;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

m_Lines_List.SetCurLineAtOffset(CStreamBin::Tell());
Lg = m_Lines_List.GetCurLineLg();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", Lg));
return Lg;
}

// ***********************************************************************************
// * CStreamLine::LnGetMaxLengthLine
// ***********************************************************************************
long  CStreamLine::LnGetMaxLengthLine()
{
MI_TRACE_DCL_TFN("stline_LnGetMaxLengthLine");
short  ret;
long   Lg=-1;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", Lg)) , Lg;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

Lg = m_Lines_List.GetLinesMaxLg();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", Lg));
return Lg;
}

// ***********************************************************************************
// * CStreamLine::LnIsLastLine
// ***********************************************************************************
short CStreamLine::LnIsLastLine()
{
MI_TRACE_DCL_TFN("stline_LnLengthLine");
short  ret;
long   Lig=-1;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", FALSE)) , FALSE;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

m_Lines_List.SetCurLineAtOffset(CStreamBin::Tell());
Lig = m_Lines_List.GetCurLineLine();

ret = ( (Lig!=-1) && (Lig==m_Lines_List.GetLines()-1) );
MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}


// ***********************************************************************************
// * CStreamLine::LnGetFileSize
// * Renvoie le nombre de ligne du fichier (-1 si erreur)
// ***********************************************************************************
long CStreamLine::LnGetFileSize()
{
MI_TRACE_DCL_TFN("stline_LnGetFileSize");
short  ret;
long   Lig = -1;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %ld", Lig)) , Lig;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

Lig = m_Lines_List.GetLines();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", Lig));
return Lig;
}

// ***********************************************************************************
// * CStreamLine::LnSeek
// * Positionnement au d�but d'une ligne
// * NO_ERRORS , ERR_BAD_CALL , ERR_PARAM , ERR_SEEK
// ***********************************************************************************
short CStreamLine::LnSeek ( long OffsetLine, short Orig )
{
MI_TRACE_DCL_TFN("stline_LnSeek");
short ret;
long  Lig = 0;
long  Offset;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();

switch(Orig)
   {
   case CE_SEEK_SET:
      m_Lines_List.SetCurLineAtBegin();
      break;
   case CE_SEEK_END:
      m_Lines_List.SetCurLineAtEnd();
      OffsetLine++;
      break;
   default:
      m_Lines_List.SetCurLineAtOffset(CStreamBin::Tell());
      break;
   }

Lig = m_Lines_List.GetCurLineLine() + OffsetLine;

if (Lig<0)
   {
   // Position avant le d�but du fichier
   ret = ERR_SEEK;
   }
else if ( (0<=Lig) && (Lig<m_Lines_List.GetLines()) )
   {
   // Position dans le fichier
   // (au d�but de la ligne choisie)
   // l'appel au Seek d�riv� efface EofReached
   m_Lines_List.SetCurLineAtLine( Lig );
   Offset = m_Lines_List.GetCurLineOffset();
   ret = Seek( Offset , CE_SEEK_SET );
   }
else if (Lig==m_Lines_List.GetLines())
   {
   // Position en fin de fichier (selon Eof ou Ctrlz)
   // (� la fin de la derni�re ligne ,c'est � dire au d�but d'une future nouvelle ligne)
   // l'appel au Seek d�riv� efface EofReached
   ret = Seek( m_Eof_MemoTell , SEEK_SET );
   }
else
   {
   // Position apr�s la fin de fichier
   ret = ERR_SEEK;
   }

// Remise � faux, pour avoir le m�me comportement qu'un seek binaire
_ResetEofReached();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnTell
// * Renvoie le num�ro de ligne courante
// ***********************************************************************************
long CStreamLine::LnTell()
{
MI_TRACE_DCL_TFN("stline_LnTell");
short  ret;
long   Lig = 0;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Eof_IsFound) ? NO_ERRORS : _CreateInfoLine();

m_Lines_List.SetCurLineAtOffset(CStreamBin::Tell());
Lig = m_Lines_List.GetCurLineLine();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", Lig));
return Lig;
}

// ***********************************************************************************
// * CStreamLine::LnEof
// * Idique si on a atteind ou d�passer la fin de fichier texte
// ***********************************************************************************
short CStreamLine::LnEof()
{
MI_TRACE_DCL_TFN("stline_LnEof");
short  ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
ret = m_Eof_IsReached;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Write( Buf , LgBuf , pLg )
// * Simple surcharge de la fonction CStreamBin, on casse l'analyse du fichier.
// ***********************************************************************************
short CStreamLine::Write( const unsigned char* Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("stline_WriteBuf");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = CStreamBin::Write( Buf, LgBuf, pLg);
if ((ret!=ERR_PARAM) && (ret!=ERR_BAD_CALL))
   _CleanInfoLine();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Write( c )
// * Simple surcharge de la fonction CStreamBin, on casse l'analyse du fichier.
// ***********************************************************************************
short CStreamLine::Write( unsigned char c  )
{
MI_TRACE_DCL_TFN("stline_Write");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = CStreamBin::Write(c);
if ((ret!=ERR_PARAM) && (ret!=ERR_BAD_CALL))
   _CleanInfoLine();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Read ( Buf , LgBuf , Lg )
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::Read ( unsigned char* Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("stline_ReadBuf");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::Read(Buf, LgBuf, pLg);
   _SetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Read ( c )
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::Read ( unsigned char* c )
{
MI_TRACE_DCL_TFN("stline_Read");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::Read(c);
   _SetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Find ( c , After )
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::Find ( unsigned char c, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stline_Find");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::Find(c,SeekAfter);
   _SetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Find ( Buf , LgBuf , After )
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::Find ( const unsigned char* Buf, long LgBuf, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stline_FindBuf");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::Find(Buf,LgBuf,SeekAfter);
   _SetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::FindInCollection
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::FindInCollection ( const unsigned char* Buf, long LgBuf, unsigned char* pc, BOOL SeekAfter )
{
MI_TRACE_DCL_TFN("stline_FindInColl");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::FindInCollection(Buf,LgBuf,pc,SeekAfter);
   _SetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::Seek
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::Seek( long Offset, short Orig  )
{
MI_TRACE_DCL_TFN("stline_Seek");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = (m_Lines_IsValid) ? NO_ERRORS : _CreateInfoLine();
if (ret==NO_ERRORS)
   {
   ret = CStreamBin::Seek(Offset,Orig);
   _ResetEofReached();
   }

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::ClearError
// * Simple surcharge de la fonction CStreamBin, on efface Eof.
// ***********************************************************************************
short CStreamLine::ClearError()
{
MI_TRACE_DCL_TFN("stline_ClearError");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

ret = CStreamBin::ClearError();
_ResetEofReached();

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnReadSection
// * 
// * Sp�cial fichier INI, lecture d'une section (ex: [Section1])
// * 
// * la lecture commence � la position binaire courante et se fait 
// * tant qu'une section n'est pas trouv�e ou que la fin du fichier n'est pas atteinte
// * 
// * NO_ERRORS : une section est trouv�e, on se situe sur le d�but de la ligne suivante
// *             Sec contient le nom de la section
// * 
// * ERR_EOF    : On est � la fin de fichier,
// *              Sec est vide
// * 
// ***********************************************************************************
short CStreamLine::LnReadSection( unsigned char* Sec, long LgSec, long* pLg )
{
MI_TRACE_DCL_TFN("stline_ReadSec");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if ((Sec==NULL) || (LgSec==0))
   {
   ret = ERR_PARAM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

// ----------------------------------------------------------------
// Pr�liminaire
// ----------------------------------------------------------------

// La gestion du padding est communiqu�e � l'objet d'analyse de ligne
CIniLine Line(m_IsPad);

// R�servation d'un buffer de taille suffisament grande 
// pour satisfaire les besoins les plus fr�quents
// (la taille est automatiquement adapt�e par _IniReadSection)
ret = Line.Alloc(1024);
if (ret==ERR_MEM)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   ret = _IniReadSection( Line, Sec, LgSec, pLg);

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnFindSection
// * 
// * Sp�cial fichier INI, recherche d'une section pr�cise (ex: [Section1])
// * 
// * la recherche commence � la position binaire courante et se fait 
// * tant que la section n'est pas trouv�e ou que la fin du fichier n'est pas atteinte
// * 
// * NO_ERRORS : la section est trouv�e, on se situe sur le d�but de la ligne suivante
// * 
// * ERR_EOF    : On est � la fin de fichier, on n'a pas trouv� la section
// * 
// ***********************************************************************************
short CStreamLine::LnFindSection( const unsigned char* Sec, long LgSec, short IsCaseSens)
{
short ret;
long  Lg;
unsigned char* Buf;
MI_TRACE_DCL_TFN("stline_FindSec");

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if ((Sec==NULL) || (LgSec==0))
   {
   ret = ERR_PARAM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

Buf = new unsigned char [LgSec];
if (Buf==NULL)
   {
   ret = ERR_MEM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

// ----------------------------------------------------------------
// Pr�liminaire
// ----------------------------------------------------------------

// La gestion du padding est communiqu�e � l'objet d'analyse de ligne
CIniLine Line(m_IsPad);

// R�servation d'un buffer de taille suffisament grande 
// pour satisfaire les besoins les plus fr�quents
// (la taille est automatiquement adapt�e par _IniReadSection)
ret = Line.Alloc(1024);
if (ret==ERR_MEM)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   do {
      ret = _IniReadSection( Line, Buf, LgSec, &Lg );
      if (ret == NO_ERRORS)
         ret = (_IsStrEqual( Sec, LgSec, Buf, Lg, IsCaseSens)) ? NO_ERRORS : ERR_KEY;
      }
   while ((ret!=NO_ERRORS) && (ret!=ERR_EOF));
   }

delete Buf;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnReadKey
// * 
// * Sp�cial fichier INI, lecture d'une cl� (ex: cle1 = valeur) ou (cle2_sans_valeur)
// * 
// * la lecture commence � la position binaire courante et se fait 
// * tant qu'une cle n'est pas trouv�e ou que la fin du fichier n'est pas atteinte
// * ou qu'une section n'est pas rencontr�e.
// * 
// * NO_ERRORS  : une cl� est trouv�e
// *              Key contient le nom de la cl�
// *              Val contient la valeur, si elle existe (vide sinon)
// * 
// * ERR_EOF    : On est � la fin de fichier,
// *              Key et Val sont vides
// * 
// * ERR_SECTION: On a rencontr� une nouvelle section, la position courante se trouve au 
// *              d�but de la ligne contenant la section.
// *              Key et Val sont vides
// * 
// ***********************************************************************************
short CStreamLine::LnReadKey( unsigned char* Key, long LgKey, long* pLgKey, unsigned char* Val, long LgVal, long* pLgVal )
{
MI_TRACE_DCL_TFN("stline_ReadKey");
short ret;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"Begin (%08lX)",m_Handle));

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if ((Key==NULL) || (LgKey==0))
   {
   ret = ERR_PARAM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

// ----------------------------------------------------------------
// Pr�liminaire
// ----------------------------------------------------------------

// La gestion du padding est communiqu�e � l'objet d'analyse de ligne
CIniLine Line(m_IsPad);

// R�servation d'un buffer de taille suffisament grande 
// pour satisfaire les besoins les plus fr�quents
// (la taille est automatiquement adapt�e par _IniReadKey)
ret = Line.Alloc(1024);
if (ret==ERR_MEM)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   ret = _IniReadKey( Line, Key, LgKey, pLgKey, Val, LgVal, pLgVal);

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}

// ***********************************************************************************
// * CStreamLine::LnFindKey
// * 
// * Sp�cial fichier INI, recherche d'une cl� (ex: cle1 = valeur) ou (cle2_sans_valeur)
// * 
// * la lecture commence � la position binaire courante et se fait 
// * tant que la cl� n'est pas trouv�e ou que la fin du fichier n'est pas atteinte
// * ou qu'une section n'est pas rencontr�e.
// * 
// * NO_ERRORS  : une cl� est trouv�e
// *              Val contient la valeur, si elle existe (vide sinon)
// * 
// * ERR_EOF    : On est � la fin de fichier,
// *              Val est vide
// * 
// * ERR_SECTION: On a rencontr� une nouvelle section, la position courante se trouve au 
// *              d�but de la ligne contenant la section.
// *              Val est vide
// * 
// ***********************************************************************************
short CStreamLine::LnFindKey( const unsigned char* Key, long LgKey, unsigned char* Val, long LgVal, long* pLgVal, short IsCaseSens )
{
short ret;
long  Lg;
unsigned char* Buf;
MI_TRACE_DCL_TFN("stline_FindKey");

// ----------------------------------------------------------------
// Coh�rence
// ----------------------------------------------------------------
if ( (ret=_IsOkForRead()) != NO_ERRORS)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

if ((Key==NULL) || (LgKey==0))
   {
   ret = ERR_PARAM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

Buf = new unsigned char [LgKey];
if (Buf==NULL)
   {
   ret = ERR_MEM;
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;
   }

// ----------------------------------------------------------------
// Pr�liminaire
// ----------------------------------------------------------------

// La gestion du padding est communiqu�e � l'objet d'analyse de ligne
CIniLine Line(m_IsPad);

// R�servation d'un buffer de taille suffisament grande 
// pour satisfaire les besoins les plus fr�quents
// (la taille est automatiquement adapt�e par _IniReadKey)
ret = Line.Alloc(1024);
if (ret==ERR_MEM)
   return MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret)) , ret;

// ----------------------------------------------------------------
// Traitement
// ----------------------------------------------------------------
ret = _PositBeforeRead();

if (ret==NO_ERRORS)
   {
   do {
      ret = _IniReadKey( Line, Buf, LgKey, &Lg, Val, LgVal, pLgVal );
      if (ret == NO_ERRORS)
         ret = (_IsStrEqual( Key, LgKey, Buf, Lg, IsCaseSens)) ? NO_ERRORS : ERR_KEY;
      }
   while ((ret!=NO_ERRORS) && (ret!=ERR_EOF) && (ret!=ERR_SECTION) );
   }

delete Buf;

MI_TRACE((CI_TRA_F_INFO_HIGH,CI_MODULE_ID,TFN,"End %d", ret));
return ret;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ClistLine
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////



// ***********************************************************************************
// * ClistLine::_New
// ***********************************************************************************
CLine* ClistLine::_New( long Offset, long Lg )
{
CLine* p = (CLine*) new CLine;
if (p)
   {
   p->Next   = NULL;
   p->Prev   = NULL;
   p->Lg     = Lg;
   p->Offset = Offset;
   }
else
   m_IsNewError = TRUE;

if (Lg>m_MaxLenLine)
  m_MaxLenLine = Lg;
return p;
}

// ***********************************************************************************
// * ClistLine::_Link
// ***********************************************************************************
void ClistLine::_Link( CLine* pCur, CLine* pNew, BOOL IsAfter )
{
if (!pNew)
   return;

if (!m_pFirst)
   {
   m_pFirst = pNew;
   m_pLast  = pNew;
   m_MaxLine= 1;
   return;
   }

if (!pCur)
   return;

if (IsAfter)
   {
   CLine* pNext = pCur->Next;
   pNew->Prev  = pCur;
   pNew->Next  = pNext;
   pCur->Next  = pNew;
   if (pNext)
      pNext->Prev = pNew;
   else
      m_pLast = pNew;
   }
else
   {
   CLine* pPrev = pCur->Prev;
   pNew->Prev  = pPrev;
   pNew->Next  = pCur;
   pCur->Prev  = pNew;
   if (pPrev)
      pPrev->Next = pNew;
   else
      m_pFirst = pNew;
   }

m_MaxLine++;
}

// ***********************************************************************************
// * ClistLine::_Unlink
// ***********************************************************************************
void ClistLine::_Unlink( CLine* pOld )
{
if (!pOld)
   return;

CLine* pPrev = pOld->Prev;
CLine* pNext = pOld->Next;

if (pPrev)
   pPrev->Next = pNext;
else
   m_pFirst = pNext;

if (pNext)
   pNext->Prev = pPrev;
else
   m_pLast = pPrev;

m_MaxLine--;
}

// ***********************************************************************************
// * ClistLine::ClistLine
// ***********************************************************************************
ClistLine::ClistLine()
{
m_pFirst     = NULL;
m_pLast      = NULL;
m_MaxLine    = 0;
m_IsNewError = FALSE;
m_pCur       = NULL;
m_CurLine    = 0;

}

// ***********************************************************************************
// * ClistLine::~ClistLine
// ***********************************************************************************
ClistLine::~ClistLine()
{
ClearAll();
}

// ***********************************************************************************
// * ClistLine::ClearAll
// ***********************************************************************************
void ClistLine::ClearAll()
{
CLine* pOld = m_pFirst;
CLine* p;
while(pOld)
   {
   p = pOld->Next;
   _Unlink(pOld);
   delete pOld;
   pOld = p;
   }
m_IsNewError = FALSE;
m_pCur       = NULL;
m_CurLine    = 0;
m_MaxLenLine = 0;
}

// ***********************************************************************************
// * ClistLine::InsertFromEnd
// * Mise � jour de la liste en partant de la fin. 
// * Si un �l�ment ayant le m�me offset existe d�j�, on met � jour l'�l�ment.
// * sinon, on insert un nouvel �l�ment.
// ***********************************************************************************
void ClistLine::InsertFromEnd( long Offset, long Lg )
{
CLine* p = m_pLast;

if (!p)
   {
   _Link( p, _New(Offset,Lg), TRUE);
   return;
   }

while( p )
   {
   if (Offset > p->Offset)
      {
      // insertion apres l'�l�ment
      _Link( p, _New(Offset,Lg), TRUE);
      break;
      }
   else if (Offset == p->Offset)
      {
      // mise � jour de l'�l�ment
      p->Lg = Lg;
      break;
      }
   else
      {
      // pas trouve
      if (p->Prev)
         {
         // on passe au pr�c�dent
         p = p->Prev;
         }
      else
         {
         // 1er �l�ment, on ins�re avant l'�l�ment
         _Link( p, _New(Offset,Lg), FALSE);
         break;
         }
      }
   }
}

// ***********************************************************************************
// * ClistLine::AddAtEnd
// * NO_ERRORS
// ***********************************************************************************
void ClistLine::AddAtEnd( long Offset, long Lg )
{
_Link( m_pLast, _New(Offset,Lg), TRUE);
}

// ***********************************************************************************
// * ClistLine::GetLines
// ***********************************************************************************
long  ClistLine::GetLines()
{
return (!m_IsNewError) ? m_MaxLine : -1;
}

// ***********************************************************************************
// * ClistLine::GetLinesMaxLg
// ***********************************************************************************
long  ClistLine::GetLinesMaxLg()
{
return (!m_IsNewError) ? m_MaxLenLine : -1;
}

// ***********************************************************************************
// * ClistLine::IsValid
// ***********************************************************************************
BOOL  ClistLine::IsValid()
{
return (m_pFirst!=NULL) && (!m_IsNewError);
}

// ***********************************************************************************
// * ClistLine::SetCurLineAtOffset
// ***********************************************************************************
void  ClistLine::SetCurLineAtOffset( long Offset)
{
if (m_IsNewError)
   return;

m_CurLine = 0;
m_pCur    = NULL;

if (Offset==-1)
   return;

CLine* p = m_pFirst;
while( p )
   {
   // if ((p->Offset <= Offset) && (Offset < p->Offset+p->Lg))
   if (p->Offset <= Offset)
      if (  (!p->Next)
         || ( p->Next && (Offset < p->Next->Offset))
         )
         {
         m_pCur = p;
         break;
         }
   m_CurLine++;
   p = p->Next;
   }
}

// ***********************************************************************************
// * ClistLine::SetCurLineAtLine
// ***********************************************************************************
void  ClistLine::SetCurLineAtLine( long Line)
{
if (m_IsNewError)
   return;

m_CurLine = 0;
m_pCur    = NULL;

if (Line==-1)
   return;

CLine* p = m_pFirst;
while( p )
   {
   if (m_CurLine == Line)
      {
      m_pCur = p;
      break;
      }
   m_CurLine++;
   p = p->Next;
   }
}

// ***********************************************************************************
// * ClistLine::SetCurLineAtBegin
// ***********************************************************************************
void  ClistLine::SetCurLineAtBegin()
{
if (m_IsNewError)
   return;
m_pCur    = m_pFirst;
m_CurLine = 0;
}

// ***********************************************************************************
// * ClistLine::SetCurLineAtEnd
// ***********************************************************************************
void  ClistLine::SetCurLineAtEnd()
{
if (m_IsNewError)
   return;
m_pCur    = m_pLast;
m_CurLine = m_MaxLine-1;
}

// ***********************************************************************************
// * ClistLine::GetCurLineOffset
// ***********************************************************************************
long  ClistLine::GetCurLineOffset()
{
if (m_pCur)
   return m_pCur->Offset;
else
   return -1;
}

// ***********************************************************************************
// * ClistLine::GetCurLineLg
// ***********************************************************************************
long  ClistLine::GetCurLineLg()
{
if (m_pCur)
   return m_pCur->Lg;
else
   return -1;
}

// ***********************************************************************************
// * ClistLine::GetCurLineLine
// ***********************************************************************************
long  ClistLine::GetCurLineLine()
{
if (m_pCur)
   return m_CurLine;
else
   return -1;
}

