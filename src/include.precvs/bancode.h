#ifndef __BANNER_C__
#define __BANNER_C__
// ***************************************************************************************************
// 
//    Automatisation de la gestion d'une bannière d'un programme
//    
//    REGLE D'UTILISATION : 
//    Ce fichier doit être inclu dans un fichier père où sont préalablement définis
//     VER_FILEVERSION_STRC       numéro de la version aux normes Amenesik / Sologic (nnnnnn)
//     VER_STATUS                 format de la version selon les normes Amenesik / Sologic
//     VER_ORIGINALFILENAME_STR   Nom du fichier
//     VER_PRODUCTNAME_STR        Nom produit avec infos sur la langue si besoin
//     VER_INTERNALNAME_STR       Nom interne avec infos de build si besoin -debug,trace,...-) 
//     VER_COMMENT                libre
//     VER_BUILD_STR              Infos sur les spécificité de compilation
// 
//    21/11/2000 Emmanuel BECK     Created
//    31/05/2001 FRC               add GetXxx functions
//    17/04/2002 FRC               Evolution portabilité
//    25/07/2002 FRC               Evolution portabilité (constantes de compil)
//    11/12/2002 FRC               Ajout de nouvelles fonctions
// 
// ***************************************************************************************************
//     Pour identifier l'OS cîble, il faut utiliser les définitions suivantes
//     _WIN32 _WINDOWS _CONSOLE
//     __linux__   (spécification POSIX)
//     __Prl
// ***************************************************************************************************

#ifndef VER_I_DONT_WANT_INCLUDE
#include <stdio.h>
#include <string.h>
#endif

/* -------
   Version
   ------- */

#ifndef VER_FILEVERSION_STRC
  #error VER_FILEVERSION_STRC undefined
#endif

#define VER_MAJEURE    VER_FILEVERSION_STRC[0]  
#define VER_MINEURE    VER_FILEVERSION_STRC[1]
#define VER_RELEASE    VER_FILEVERSION_STRC[2]
#define VER_RELEASE1   VER_FILEVERSION_STRC[3]
#define VER_PROV1      VER_FILEVERSION_STRC[4]
#define VER_PROV2      VER_FILEVERSION_STRC[5]

#ifndef VERSION_STATUS
#define VERSION_STATUS    '2'
#endif

#ifndef VER_ORIGINALFILENAME_STR
#define VER_ORIGINALFILENAME_STR      ""
#endif

#ifndef VER_INTERNALNAME_STR
#define VER_INTERNALNAME_STR  ""
#endif

#ifndef VER_BUILD_STR
#define VER_BUILD_STR  ""
#endif

#ifndef VER_PRODUCTNAME_STR
#define VER_PRODUCTNAME_STR  ""
#endif

#ifndef VER_COMMENT
#define VER_COMMENT  ""
#endif

/* -----------------
   Copyright et Date
   ----------------- */

#define COPYRIGHT_VAR   "Copyright (c) 1998-%4s Amenesik / Sologic  ", & __DATE__ [7]
#define COPYRIGHT       "\n   Copyright (c) 1998-%4s Amenesik / Sologic  ", & __DATE__ [7]
#define BUILD_DATE_VAR  "%s %s", __DATE__, __TIME__
#define BUILD_DATE      "\n   %s %s", __DATE__, __TIME__

#if defined(__linux__)
#warning PROLOGUE: banner included
#else
#pragma message("PROLOGUE MSG: banner included")
#endif

/* ---------------------------------------------------------------------------------------------------  
   Pattern version
      status = 0 -> Module définitif
      status = 1 -> Module provisoire (version provisoire)
      status = 2 -> Module béta test (version provisoire + libellé personnel avec date)            
   ---------------------------------------------------------------------------------------------------  
*/

struct T_VerPattern 
   {
   char prlinfo[11];
  char versionsize;
   char version[6];
  char sep1;
  char date[11];
  char sep2;
  char time[8];
  char sep3;
   char libstatus[15];
   char status;
  char sep4;
   char prlbuild[12];
  char buildsize;
   char build[15];
   }
   s_VersionPattern = { "*PRL@INFO*#",6,VER_FILEVERSION_STRC, 
                '-',__DATE__, 
                '-',__TIME__,
                '-',"VERSION_STATUS:",VER_STATUS, 
                        '-',"*PRL@BUILD*#",9,VER_BUILD_STR
                } ;

// ****************************************************************************
/** Banner_DisplayBanner:
    Display banner depending on current VersionStatus
    "   name of the program, and version
    "   date of compil
    "   copyright
    "   3 lines of comments if not empty

 * @param   nothing
 * @return: 0
 * @author EMB
 */
// * VarGlob:
//   versionStatus
// ****************************************************************************
int Banner_DisplayBanner(void) 
{
#if (defined (_WIN32) || defined(_WINDOWS)) && !defined(_CONSOLE)

  return 0;

#else

  printf ("\n   %s " ,VER_ORIGINALFILENAME_STR);

  printf ("%c.%c%c", VER_MAJEURE, VER_MINEURE, VER_RELEASE); 

  switch (s_VersionPattern.status) 
  {
    case '0':
      if (VER_RELEASE1 > '0') printf (".%c", VER_RELEASE1);
      printf(" %s",VER_BUILD_STR);
      break;
    case '1':
      printf (".%c.%c%c", VER_RELEASE1, VER_PROV1, VER_PROV2); 
      printf(" %s",VER_BUILD_STR);
      break;
    case '2':
      printf (".%c.%c%c", VER_RELEASE1, VER_PROV1, VER_PROV2); 
      printf(" %s",VER_BUILD_STR);
      printf (BUILD_DATE);
      break;
  }

  printf (COPYRIGHT);

  if (VER_INTERNALNAME_STR!='\0')
    printf("\n   %s",VER_INTERNALNAME_STR);
  if (VER_PRODUCTNAME_STR!='\0')
    printf("\n   %s",VER_PRODUCTNAME_STR);
  if (VER_COMMENT!='\0')
    printf("\n   %s",VER_COMMENT);

  printf("\n");

  return 0;
  
#endif  
  }

// ****************************************************************************
//  Banner_GetVersionStatus:
//  Get the current VersionStatus
//  return: VersionStatus
//  author FRC
// 
//  VarGlob:
//   s_VersionPattern
// ****************************************************************************
char Banner_GetVersionStatus(void)
{
return s_VersionPattern.status;
}

// ****************************************************************************
//  Banner_GetVersionItem:
//  Get a char from versionID
//  param i : index of item (0 -> 5)
//  return: char
//  author FRC
// 
//  VarGlob:
//   s_VersionPattern
// ****************************************************************************
char Banner_GetVersionItem( int i )
{
if ((i>=0) && (i<=5))
  return s_VersionPattern.version[i];
else
  return ' ';
}

// ****************************************************************************
//  Banner_GetVersionID:
//  Get a string with version, and date depending on a VersionStatus value
//  param Dst           = pointer on a string (size of 80 is assumed)
//        VersionStatus = '0','1','2'
//  return: pointer on Dst
//  author FRC
// 
//  VarGlob:
//   Nothing
// ****************************************************************************
char* Banner_GetVersionID( char * Dst, char StatusValue )
{
int i = 0;

  if (Dst==NULL)
    return NULL;
  
  i += sprintf ( &Dst[i], "%c.%c%c" , VER_MAJEURE, VER_MINEURE, VER_RELEASE); 

  switch (StatusValue) 
    {
    case '0':
      if (VER_RELEASE1 > '0') 
        i += sprintf ( &Dst[i], ".%c", VER_RELEASE1);
      break;
    case '1':
      i += sprintf ( &Dst[i], ".%c.%c%c", VER_RELEASE1, VER_PROV1, VER_PROV2); 
      break;
    case '2':
      i += sprintf ( &Dst[i], ".%c.%c%c ", VER_RELEASE1, VER_PROV1, VER_PROV2); 
      i += sprintf ( &Dst[i],BUILD_DATE_VAR);
      break;
    }

return Dst;
}

// ****************************************************************************
//  Banner_GetXxxxx:
//  Get a string with info
//  param Dst           = pointer on a string (size of 80 is assumed)
//  return: pointer on Dst
//  author FRC
// 
//  VarGlob:
//   Nothing
// ****************************************************************************
char* Banner_GetBuild( char * Dst )
{
strcpy( Dst, VER_BUILD_STR );
return Dst;
}

char* Banner_GetDate( char * Dst )
{
sprintf( Dst, BUILD_DATE_VAR );
return Dst;
}

char* Banner_GetOriginalFilename( char * Dst )
{
strcpy( Dst, VER_ORIGINALFILENAME_STR );
return Dst;
}

char* Banner_GetProductName( char * Dst )
{
strcpy( Dst, VER_PRODUCTNAME_STR );
return Dst;
}

char* Banner_GetInternalName( char * Dst )
{
strcpy( Dst, VER_INTERNALNAME_STR );
return Dst;
}

char* Banner_GetComment( char * Dst )
{
strcpy( Dst, VER_COMMENT );
return Dst;
}

char* Banner_GetCopyright( char * Dst )
{
sprintf( Dst, COPYRIGHT_VAR );
return Dst;
}

#endif  // __BANNER_C__
