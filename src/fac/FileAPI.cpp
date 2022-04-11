// ***********************************************************************************************
// * FileAPI.cpp
// ***********************************************************************************************

#include "bda.h"
#include "FacTrace.h"

#include "CstExt.h"
#include "CstInt.h"
#include "FileAPI.h"
#include "Strm.h"

#include <string.h>

#define CI_MODULE_ID 0x0002

// ****************************************************************************
// * CherchePattern
// ****************************************************************************
short CherchePattern( CStreamBin& Strm, const char * Prl, short LgPrl, short* pLg )
{
short          ret;
unsigned char  c;
unsigned char  Lg;

// --- Recherche de la chaine
ret = Strm.Find((const unsigned char*)Prl, LgPrl, TRUE);
if (ret!=NO_ERRORS)
  return ret;

// --- Analyse de la suite
if (Strm.Read(&c) != NO_ERRORS)
  return ERR_FORMAT;

if (Strm.Read(&Lg) != NO_ERRORS)
  return ERR_FORMAT;

if (c=='$')
   {
   // Convention Longueur en ASCII
   Lg = Lg - '0';
   if (Strm.Seek(1,CE_SEEK_CUR) != NO_ERRORS)
      ret = ERR_FORMAT;
   }

*pLg = Lg;
return NO_ERRORS;
}

// ****************************************************************************
// * FileGetVersion
// * La fonction balaye le fichier à la recherche de l'identification de la 
// * version en supposant que *PRL@INFO* se situe avant *PRL@BUILD*.
// ****************************************************************************
short FileGetVersion(const char * sFileOri, char * Buf, long LgBuf, long* pLg )
{
MI_TRACE_DCL_TFN("FileGetVersion");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgBuf=%ld sFileOri='%s'",LgBuf,sFileOri));

CStreamBin     Strm;
unsigned char  c;
char           Prl[15];
short          LgData;
short          iPrl;
short          iBuf;
*pLg = 0;

ret = Strm.Open(sFileOri,CE_F_R);
if (ret!=NO_ERRORS)
  MI_TRACE_RETURN(ret);

iBuf = 0;

// ----------------------------------------------------------------------------
// - Recherche de la version
// ----------------------------------------------------------------------------

// --- Fabrication de la chaine à la main
//     (si on l'a met en constante, on l'a retrouve dans le binaire
//      et donc elle peut être lue à la place de la vraie entête de version...)
iPrl=0;
Prl[iPrl++]='*';
Prl[iPrl++]='P';
Prl[iPrl++]='R';
Prl[iPrl++]='L';
Prl[iPrl++]='@';
Prl[iPrl++]='I';
Prl[iPrl++]='N';
Prl[iPrl++]='F';
Prl[iPrl++]='O';
Prl[iPrl++]='*';

// --- Recherche de la chaine
ret = CherchePattern( Strm, Prl, iPrl, &LgData);
if (ret!=NO_ERRORS)
   MI_TRACE_RETURN(ret);

// --- Lecture de la version
if ((LgData<3) || (LgData>6))
   MI_TRACE_RETURN(ERR_FORMAT);

if ( iBuf+LgData+3 > LgBuf)
   MI_TRACE_RETURN(ERR_PARAM);

if (LgData>=3) // N.NN
   {
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = c;
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = '.';
   Buf[iBuf++] = c;
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = c;
   }
  
if (LgData>=4) // .N
   {
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = '.';
   Buf[iBuf++] = c;
   }
  
if (LgData>=6) // .NN
   {
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = '.';
   Buf[iBuf++] = c;
   if (Strm.Read(&c)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   Buf[iBuf++] = c;
   }

// L'info de version est prise en compte
*pLg = iBuf;
  
// ----------------------------------------------------------------------------
// - Recherche du build (optionel)
// ----------------------------------------------------------------------------

// --- Fabrication de la chaine à la main
//     (si on l'a met en constante, on l'a retrouve dans le binaire
//      et donc elle peut être lue à la place de la vraie entête de version...)
iPrl=0;
Prl[iPrl++]='*';
Prl[iPrl++]='P';
Prl[iPrl++]='R';
Prl[iPrl++]='L';
Prl[iPrl++]='@';
Prl[iPrl++]='B';
Prl[iPrl++]='U';
Prl[iPrl++]='I';
Prl[iPrl++]='L';
Prl[iPrl++]='D';
Prl[iPrl++]='*';

// --- Recherche de la chaine
ret = CherchePattern( Strm, Prl, iPrl, &LgData);
if (ret!=NO_ERRORS)
   MI_TRACE_RETURN(NO_ERRORS);

// --- Lecture de la valeur
if ( iBuf+LgData+1 < LgBuf)
   {
   Buf[iBuf++] = ' ';
   if (Strm.Read((unsigned char*)&Buf[iBuf], (long)LgData)!=NO_ERRORS)
      MI_TRACE_RETURN(ERR_FORMAT);
   iBuf += LgData;
   }

// ----------------------------------------------------------------------------
// - Fin
// ----------------------------------------------------------------------------

*pLg = iBuf;
ret = Strm.Close();

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%ld Buf='%s'",*pLg,Buf));
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileLnCopy
// * Copie en mode Ligne d'un (ou d'une partie) d'un fichier dans un autre
// * (les offset et longueurs sont en LIGNES)
// *
// * sFileOri   = Fichier Source
// * sFileDes   = Fichier Destination
// * Flags      = - Test d'existence de sFileDes
// *              - CE_F_CAT pour ajouter à la fin de sFileDes au lieu d'une simple copie
// *              - Format d'écriture de sFileDes
// * OffsetCopy = Numéro de la 1ère ligne (débute à 0)
// * LgCopy     = Nombre de lignes (-1==jusqu'à la fin)
// *
// * NO_ERRORS , ERR_SEEK (offset hors du fichier), autres
// ****************************************************************************
short FileLnCopy(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy )
{
MI_TRACE_DCL_TFN("FileLnCopy");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileDes='%s'",sFileDes));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flags=%04X"   ,Flags));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%ld Lg=%ld",OffsetCopy,LgCopy));

CStreamLine*   pStrmOri;
CStreamLine*   pStrmDes;
long           Lg;
long           LgMax;
unsigned char* pLine;

/* Avoid copying file to itself */
/* ---------------------------- */
if (( sFileOri != (const char *) 0 )
&&  ( sFileDes != (const char *) 0 )) {
	if (!( strcmp( sFileOri, sFileDes ) )) {
		MI_TRACE_RETURN(ERR_EXIST);
		}
	}


// ---------------------------------------------------------------
// - Cohérence des flags et paramètres
// ---------------------------------------------------------------
if ((OffsetCopy<0) || (LgCopy<-1))
   MI_TRACE_RETURN(ERR_PARAM);
   
if (LgCopy==0)
   MI_TRACE_RETURN(NO_ERRORS);
   
Flags &= ( CE_F_MASK_CHK | CE_STREAM_F_MASK_SET | CE_F_CAT);
Flags |= ( (Flags&CE_F_CAT) ? CE_F_RW : CE_F_RW_NEW);
Flags &= (~CE_F_CAT);

pStrmOri = new CStreamLine(0,0,0);
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

pStrmDes = new CStreamLine(0,0,0);
if (pStrmDes==NULL)
   {
   delete pStrmOri;   
   MI_TRACE_RETURN(ERR_MEM);
   }

// ---------------------------------------------------------------
// - Ouverture des fichiers
// - et vérification de l'offset
// ---------------------------------------------------------------

// --- Réservation d'un buffer de taille suffisament grande 
//     pour satisfaire les besoins les plus fréquents
LgMax = 1024;
pLine = new unsigned char[LgMax];
if (!pLine)
  {
  ret = ERR_MEM;
  goto TheEnd;
  }

// --- Ouverture Source
ret = pStrmOri->Open(sFileOri,CE_F_R | CE_F_LINE);
if (ret!=NO_ERRORS)
  goto TheEnd;

// --- Offset dans Source
//     Uniquement si != 0 pour éviter une analyse du fichier
//     qui peut être longue
if (OffsetCopy!=0)
   {
   ret = pStrmOri->LnSeek(OffsetCopy,CE_SEEK_SET);
   if (ret!=NO_ERRORS)
     goto TheEnd;
   }

// --- Ouverture Destination
ret = pStrmDes->Open(sFileDes, Flags | CE_F_LINE);
if (ret!=NO_ERRORS)
  goto TheEnd;

// ---------------------------------------------------------------
// - Boucle de copie
// ---------------------------------------------------------------

// --- Boucle de copie
//     Tant que Ok et pas la fin du fichier
//     ou que l'on a pas encore lu le nombre de lignes souhaité 
while (  (ret==NO_ERRORS)
      && ( (LgCopy<0) || (pStrmOri->LnTell() < OffsetCopy + LgCopy) )
      )
  {
  // Lecture d'une ligne 
  ret = pStrmOri->LnRead(pLine, LgMax, &Lg);
  if (ret==ERR_LEN)
    {
    // Le buffer est trop petit
    // On se replace au début de la ligne,
    // on prend un buffer de la bonne taille,
    // et on relit la ligne
    pStrmOri->LnSeek(0,CE_SEEK_CUR);
    LgMax = pStrmOri->LnGetLength();
    delete pLine;
    pLine = new unsigned char[LgMax];
    ret= (pLine) ? pStrmOri->LnRead(pLine, LgMax, &Lg) : ERR_MEM;
    }

  // Ecriture de la ligne
  if (  (ret==NO_ERRORS) 
      || ((ret==ERR_EOF) && (Lg!=0))
      )
    ret = pStrmDes->LnWrite(pLine,Lg);
  }

if (ret==ERR_EOF)
   ret = NO_ERRORS;

// ---------------------------------------------------------------
// - Fermeture et fin
// ---------------------------------------------------------------
TheEnd:
if (!pLine)
   delete pLine;
delete pStrmOri;
delete pStrmDes;
MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileBinCopy
// * Copie binaire d'un (ou d'une partie) d'un fichier dans un autre
// * (les offset et longueurs sont en OCTETS)
// *
// * sFileOri   = Fichier Source
// * sFileDes   = Fichier Destination
// * Flags      = - Test d'existence de sFileDes
// *              - CE_F_CAT pour ajouter à la fin de sFileDes au lieu d'une simple copie
// * OffsetCopy = Offset du 1er octet (débute à 0)
// * LgCopy     = Nombre d'octets (-1==jusqu'à la fin)
// *
// * NO_ERRORS , ERR_SEEK (offset hors du fichier), autres
// ****************************************************************************
short FileBinCopy(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy )
{
MI_TRACE_DCL_TFN("FileBinCopy");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileDes='%s'",sFileDes));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flags=%04X"   ,Flags));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%ld Lg=%ld",OffsetCopy,LgCopy));


CStreamBin*    pStrmOri;
CStreamBin*    pStrmDes;
long           Lg;
long           LgMax = 1024;
static unsigned char pLine[1024];

/* Avoid copying file to itself */
/* ---------------------------- */
if (( sFileOri != (const char *) 0 )
&&  ( sFileDes != (const char *) 0 )) {
	if (!( strcmp( sFileOri, sFileDes ) )) {
		MI_TRACE_RETURN(ERR_EXIST);
		}
	}


// ---------------------------------------------------------------
// - Cohérence des flags et paramètres
// ---------------------------------------------------------------
if ((OffsetCopy<0) || (LgCopy<-1))
   MI_TRACE_RETURN(ERR_PARAM);
   
if (LgCopy==0)
   MI_TRACE_RETURN(NO_ERRORS);
   
Flags &= ( CE_F_MASK_CHK | CE_F_CAT);
Flags |= ( (Flags&CE_F_CAT) ? CE_F_W_APPEND : CE_F_W_NEW);
Flags &= (~CE_F_CAT);

pStrmOri = new CStreamBin;
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

pStrmDes = new CStreamBin;
if (pStrmDes==NULL)
   {
   delete pStrmOri;   
   MI_TRACE_RETURN(ERR_MEM);
   }

// ---------------------------------------------------------------
// - Ouverture des fichiers
// - et vérification de l'offset
// ---------------------------------------------------------------

// --- Ouverture Source
ret = pStrmOri->Open(sFileOri,CE_F_R);
if (ret!=NO_ERRORS)
  goto TheEnd;

// --- Offset dans Source
if (OffsetCopy!=0)
   {
   ret = pStrmOri->Seek(OffsetCopy,CE_SEEK_SET);
   if (ret==NO_ERRORS)
      {
      unsigned char Car;
      ret = pStrmOri->Read(&Car);
      if (ret==NO_ERRORS)
         pStrmOri->Seek(-1,CE_SEEK_CUR);
      }
   if (ret!=NO_ERRORS)
      {
      ret = ERR_SEEK;
     goto TheEnd;
      }
   }

// --- Ouverture Destination
ret = pStrmDes->Open(sFileDes,Flags);
if (ret!=NO_ERRORS)
  goto TheEnd;

// ---------------------------------------------------------------
// - Boucle de copie
// - On fait 2 boucles distinctes pour optimiser
// - selon les paramètres (longueur à copier)
// ---------------------------------------------------------------

// --- Boucle de copie
if (LgCopy<0)
   {
   // --- Pas de tests de longueur
   //     on copie jusqu'à la fin
   //     Tant que Ok et pas la fin du fichier
   while (ret==NO_ERRORS)
     {
     // Lecture d'une ligne 
     ret = pStrmOri->Read(pLine, LgMax, &Lg);

     // Ecriture de la ligne
     if (  (ret==NO_ERRORS) 
         || ((ret==ERR_EOF) && (Lg!=0))
         )
       ret = pStrmDes->Write(pLine,Lg);
     }
   }
else
   {
   // --- Tests de longueur
	long LgBuf;
	long LgTmp = LgCopy;

	while (  (ret==NO_ERRORS)
         && (pStrmOri->Tell() < OffsetCopy + LgCopy)
         )
     {
      LgBuf = (LgMax < LgTmp) ? LgMax : LgTmp;

     // Lecture d'une ligne 
     ret = pStrmOri->Read(pLine, LgBuf, &Lg);
     LgTmp -= Lg;

     // Ecriture de la ligne
     if (  (ret==NO_ERRORS) 
         || ((ret==ERR_EOF) && (Lg!=0))
         )
        ret = pStrmDes->Write(pLine,Lg);
     }
   }

if (ret==ERR_EOF)
   ret = NO_ERRORS;

// ---------------------------------------------------------------
// - Fermeture et fin
// ---------------------------------------------------------------
TheEnd:
delete pStrmOri;
delete pStrmDes;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileLnCompare
// * Comparaison en mode Ligne de fichiers
// *
// * sFileOri   = Fichier Source
// * sFileDes   = Fichier Destination
// * Flags      = - CE_F_SIZE la comparaison s'arrête si les tailles sont différentes
// *              - 0         la comparaison se fait jusqu'à la 1ère ligne différente
// * OffsetCopy = Offset du 1er octet (débute à 0)
// * LgCopy     = Nombre d'octets (-1==jusqu'à la fin)
// * 
// * pOffset  = Si retour==ERR_SEEK, Numéro de la 1ère ligne mauvaise 
// *            sinon, non défini.
// *
// * NO_ERRORS , ERR_SEEK , autres
// ****************************************************************************
short FileLnCompare(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy, long* pOffset )
{
MI_TRACE_DCL_TFN("FileLnComp");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileDes='%s'",sFileDes));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flags=%04X"   ,Flags));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%ld Lg=%ld",OffsetCopy,LgCopy));

CStreamLine*   pStrmOri;
CStreamLine*   pStrmDes;
long           LgOri;
long           LgDes;
long           LgMax;
unsigned char* pLinOri;
unsigned char* pLinDes;

// ---------------------------------------------------------------
// - Cohérence des flags et paramètres
// ---------------------------------------------------------------
if ((OffsetCopy<0) || (LgCopy<-1))
   MI_TRACE_RETURN(ERR_PARAM);
   
if (LgCopy==0)
   MI_TRACE_RETURN(NO_ERRORS);
   
Flags &= ( CE_F_SIZE );

pStrmOri = new CStreamLine(0,0,0);
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

pStrmDes = new CStreamLine(0,0,0);
if (pStrmDes==NULL)
   {
   delete pStrmOri;   
   MI_TRACE_RETURN(ERR_MEM);
   }

// ---------------------------------------------------------------
// - Ouverture des fichiers
// - et vérification de l'offset
// ---------------------------------------------------------------

// --- Réservation d'un buffer de taille suffisament grande 
//     pour satisfaire les besoins les plus fréquents
LgMax = 1024;
pLinOri = new unsigned char[LgMax];
pLinDes = new unsigned char[LgMax];
if (!pLinOri || !pLinDes)
  {
  ret = ERR_MEM;
  goto TheEnd;
  }
  
// --- Ouverture Source
ret = pStrmOri->Open(sFileOri,CE_F_R | CE_F_LINE);
if (ret!=NO_ERRORS)
  goto TheEnd;

// --- Offset dans Source
//     Uniquement si != 0 pour éviter une analyse du fichier
//     qui peut être longue
if (OffsetCopy!=0)
   {
   ret = pStrmOri->LnSeek(OffsetCopy,CE_SEEK_SET);
   if (ret!=NO_ERRORS)
     goto TheEnd;
   }

// --- Ouverture Destination
ret = pStrmDes->Open(sFileDes,CE_F_R | CE_F_LINE);
if (ret!=NO_ERRORS)
  goto TheEnd;

// ---------------------------------------------------------------
// - Test sur la taille
// ---------------------------------------------------------------
if (Flags==CE_F_SIZE)
   {
   if ((pStrmOri->LnGetFileSize()==-1) || (pStrmDes->LnGetFileSize()==-1))
      {
      ret = ERR_READ;
    goto TheEnd;
      }
   else if (pStrmOri->LnGetFileSize() != pStrmDes->LnGetFileSize())
      {
      ret = ERR_SIZE;
    goto TheEnd;
      }
   }

// ---------------------------------------------------------------
// - Boucle de comparaison
// ---------------------------------------------------------------

// --- Boucle de copie
//     Tant que Ok et pas la fin du fichier
//     ou que l'on a pas encore lu le nombre de lignes souhaité 
//while (  !StrmOri.LnEof() 
//      && (ret==NO_ERRORS)
//      && ( (LgCopy<0) || (pStrmOri->LnTell() < OffsetCopy + LgCopy) )
//      )
while (  (ret==NO_ERRORS)
      && ( (LgCopy<0) || (pStrmOri->LnTell() < OffsetCopy + LgCopy) )
      )
  {
  // --- Memo de l'offset courant
   *pOffset = pStrmOri->LnTell();

  // --- Lecture d'une ligne fichier 1 
  ret = pStrmOri->LnRead(pLinOri, LgMax, &LgOri);
  if (ret==ERR_LEN)
    {
    // Le buffer est trop petit
    // On se replace au début de la ligne,
    // on prend un buffer de la bonne taille,
    // et on relit la ligne
    pStrmOri->LnSeek(0,CE_SEEK_CUR);
    LgMax = pStrmOri->LnGetLength();
    delete pLinOri;
    delete pLinDes;
    pLinOri = new unsigned char[LgMax];
    pLinDes = new unsigned char[LgMax];
    ret     = (pLinOri && pLinDes) ? pStrmOri->LnRead(pLinOri, LgMax, &LgOri) : ERR_MEM;
    }

  // --- Lecture d'une ligne fichier 2
  if (  (ret==NO_ERRORS) 
      || ((ret==ERR_EOF) && (LgOri!=0)) 
      )
    ret = pStrmDes->LnRead(pLinDes, LgMax, &LgDes);

   // --- Comparaison
  if (  (ret==NO_ERRORS) 
      || ((ret==ERR_EOF) && (LgOri!=0)) 
      )
      {
      // Lecture OK
      if (LgOri==LgDes)
         {
         // Les 2 lignes sont de même taille, on compare le contenu
         BOOL IsEqual;
         long i;
         for (i=0 , IsEqual=TRUE ; (IsEqual) && (i<LgOri) ; i++)
            IsEqual = (pLinOri[i] == pLinDes[i]);
         if (!IsEqual)
            ret = ERR_SEEK;
         }
      else
         {
         // Les 2 lignes ont une taille différente
         ret = ERR_SEEK;
         }
      }
   else if (ret==ERR_LEN)
      {
      // Le buffer ligne 2 est trop petit, donc les 2 lignes sont différentes
      ret = ERR_SEEK;
      }
  }

if (ret==ERR_EOF)
   ret = NO_ERRORS;
     
// ---------------------------------------------------------------
// - Fermeture et fin
// ---------------------------------------------------------------
TheEnd:
if (!pLinOri)
   delete pLinOri;
if (!pLinDes)
   delete pLinDes;

delete pStrmOri;
delete pStrmDes;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileBinCompare
// * Comparaison binaire de fichiers
// *
// * sFileOri   = Fichier Source
// * sFileDes   = Fichier Destination
// * Flags      = - CE_F_SIZE la comparaison s'arrête si les tailles sont différentes
// *              - 0         la comparaison se fait jusqu'à la 1ère ligne différente
// * OffsetCopy = Offset du 1er octet (débute à 0)
// * LgCopy     = Nombre d'octets (-1==jusqu'à la fin)
// * 
// * pOffset  = Si retour==ERR_SEEK, Numéro de la 1ère ligne mauvaise 
// *            sinon, non défini.
// * 
// * NO_ERRORS , ERR_SEEK , autres
// ****************************************************************************
short FileBinCompare(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy, long* pOffset )
{
MI_TRACE_DCL_TFN("FileBinComp");
short ret;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileDes='%s'",sFileDes));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Flags=%04X"   ,Flags));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN Offset=%l Lg=%l",OffsetCopy,LgCopy));

CStreamBin*    pStrmOri;
CStreamBin*    pStrmDes;
unsigned char  CarOri;
unsigned char  CarDes;
long           OffsetCur;
long           OffsetEnd;

// ---------------------------------------------------------------
// - Cohérence des flags et paramètres
// ---------------------------------------------------------------
if ((OffsetCopy<0) || (LgCopy<-1))
   MI_TRACE_RETURN(ERR_PARAM);
   
if (LgCopy==0)
   MI_TRACE_RETURN(NO_ERRORS);
   
Flags &= ( CE_F_SIZE );

pStrmOri = new CStreamBin;
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

pStrmDes = new CStreamBin;
if (pStrmDes==NULL)
   {
   delete pStrmOri;   
   MI_TRACE_RETURN(ERR_MEM);
   }

// ---------------------------------------------------------------
// - Ouverture des fichiers
// - et vérification de l'offset
// ---------------------------------------------------------------

// --- Ouverture Source
ret = pStrmOri->Open(sFileOri,CE_F_R);
if (ret!=NO_ERRORS)
  goto TheEnd;

// --- Offset dans Source
if (OffsetCopy!=0)
   {
   ret = pStrmOri->Seek(OffsetCopy,CE_SEEK_SET);
   if (ret==NO_ERRORS)
      {
      unsigned char Car;
      ret = pStrmOri->Read(&Car);
      if (ret==NO_ERRORS)
         pStrmOri->Seek(-1,CE_SEEK_CUR);
      }
   if (ret!=NO_ERRORS)
      {
      ret = ERR_SEEK;
     goto TheEnd;
      }
   }

// --- Ouverture Destination
ret = pStrmDes->Open(sFileDes,CE_F_R);
if (ret!=NO_ERRORS)
  goto TheEnd;

// ---------------------------------------------------------------
// - Test sur la taille
// ---------------------------------------------------------------
if (Flags==CE_F_SIZE)
   {
   if ((pStrmOri->GetFileSize()==-1) || (pStrmDes->GetFileSize()==-1))
      {
      ret = ERR_READ;
    goto TheEnd;
      }
   else if (pStrmOri->GetFileSize() != pStrmDes->GetFileSize())
      {
      ret = ERR_SIZE;
    goto TheEnd;
      }
   }

// ---------------------------------------------------------------
// - Boucle de copie
// ---------------------------------------------------------------

OffsetCur = OffsetCopy;
OffsetEnd = OffsetCopy + LgCopy;

// --- Boucle de copie
//     On compare octet par octet, ce n'est pas optimiser, on améliorera plus tard
//     Tant que Ok
//     ou que l'on a pas encore lu le nombre d'octets souhaité 
while (  (ret==NO_ERRORS)
      && ( (LgCopy<0) || (OffsetCur < OffsetEnd) )
      )
  {
  // Offset courant
   OffsetCur++;

  // Lecture fichier 1 
  ret = pStrmOri->Read(&CarOri);

  // Lecture fichier 2
  if (ret==NO_ERRORS)
    ret = pStrmDes->Read(&CarDes);

   // Comparaison
  if (ret==NO_ERRORS)
      {
     if (CarOri!=CarDes)
         ret = ERR_SEEK;
      }
  }

if (ret==ERR_EOF)
   ret = NO_ERRORS;

if (ret==ERR_SEEK)     
   *pOffset = OffsetCur;

// ---------------------------------------------------------------
// - Fermeture et fin
// ---------------------------------------------------------------
TheEnd:
delete pStrmOri;
delete pStrmDes;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileLnSize
// * NO_ERRORS , autres
// ****************************************************************************
short FileLnSize(const char * sFileOri, long* pLg)
{
MI_TRACE_DCL_TFN("FileLnSize");
short ret;
long  Lg;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));

CStreamLine*   pStrmOri;

pStrmOri = new CStreamLine(0,0,0);
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

ret = pStrmOri->Open(sFileOri, CE_F_LINE | CE_F_CHK_EXIST );
if (ret==NO_ERRORS)
   {
   Lg = pStrmOri->LnGetFileSize();
   if (Lg==-1)
      ret = ERR_READ;
   else
      {
      *pLg = Lg;
      MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%l",*pLg));
      }
   }

delete pStrmOri;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileBinSize
// * NO_ERRORS , autres
// ****************************************************************************
short FileBinSize(const char * sFileOri, long* pLg)
{
MI_TRACE_DCL_TFN("FileBinSize");
short ret;
long  Lg;
MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));

CStreamBin*    pStrmOri;

pStrmOri = new CStreamBin;
if (pStrmOri==NULL)
   MI_TRACE_RETURN(ERR_MEM);

ret = pStrmOri->Open(sFileOri, CE_F_CHK_EXIST );
if (ret==NO_ERRORS)
   {
   Lg = pStrmOri->GetFileSize();
   if (Lg==-1)
      ret = ERR_READ;
   else
      {
      *pLg = Lg;
      MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT Lg=%l",*pLg));
      }
   }

delete pStrmOri;

MI_TRACE_RETURN(ret);
}

// ****************************************************************************
// * FileCpy
// ****************************************************************************
short FileCpy(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy)
{
if (Flags & CE_F_LINE)
   return FileLnCopy ( sFileOri, sFileDes, Flags, OffsetCopy, LgCopy);
else
   return FileBinCopy( sFileOri, sFileDes, Flags, OffsetCopy, LgCopy);
}

// ****************************************************************************
// * FileCmp
// ****************************************************************************
short FileCmp(const char * sFileOri, const char * sFileDes, unsigned short Flags, long OffsetCopy, long LgCopy, long* pOffset)
{
if (Flags & CE_F_LINE)
   return FileLnCompare ( sFileOri, sFileDes, Flags, OffsetCopy, LgCopy, pOffset);
else
   return FileBinCompare( sFileOri, sFileDes, Flags, OffsetCopy, LgCopy, pOffset);
}

// ****************************************************************************
// * FileSize
// ****************************************************************************
short FileSize(const char * sFileOri, unsigned short Flags, long* pLg)
{
if (Flags & CE_F_LINE)
   return FileLnSize ( sFileOri, pLg);
else
   return FileBinSize ( sFileOri, pLg);
}

// ****************************************************************************
// * FileIniFind
// ****************************************************************************
short FileIniFind(const char * sFileOri, unsigned char* Sec, long LgSec, unsigned char* Key, long LgKey, unsigned char* Val, long LgVal, long* pLgVal)
{
MI_TRACE_DCL_TFN("FileIniFind");
short ret;
short IsCaseSens = FALSE;

MI_TRACE_BEGIN();
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN sFileOri='%s'",sFileOri));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Sec=%08lX",(DWORD)Sec));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgSec=%ld",LgSec));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Key=%08lX",(DWORD)Key));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgKey=%ld",LgKey));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN @Val=%08lX",(DWORD)Val));
MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"IN LgVal=%ld",LgVal));

if (pLgVal)
   *pLgVal = 0;

CStreamLine*   pStrm;

pStrm = new CStreamLine;
if (pStrm==NULL)
   MI_TRACE_RETURN(ERR_MEM);

ret = pStrm->Open(sFileOri, CE_F_CHK_EXIST );

// Recherche de la section si on le souhaite
if ((ret==NO_ERRORS) && (Sec!=NULL) && (LgSec!=0))
   ret = pStrm->LnFindSection(Sec, LgSec, IsCaseSens);

if (ret==NO_ERRORS)
   ret = pStrm->LnFindKey(Key, LgKey, Val, LgVal, pLgVal, IsCaseSens);

delete pStrm;

MI_TRACE((CI_TRA_F_PARAM,CI_MODULE_ID,TFN,"OUT LgVal=%ld",*pLgVal));
MI_TRACE((CI_TRA_F_DUMP ,CI_MODULE_ID,TFN,"OUT Val",Val,*pLgVal));
MI_TRACE_RETURN(ret);
}
