// *************************************************************************************
// * TraVer.h
// *
// * D�finition de la version
// *  
// *   - pour Win16 et Win32 (exe ou dll)
// *     la version doit �tre visible dans les propri�t�s du fichier
// *     ce fichier doit �tre inclu dans les RESSOURCES
// *     (donc compatible avec le compilateur de ressource)
// * 
// *   - pour tous les OS (y compris Windows)
// *     le fichier doit r�pondre aux normes d�finies par Amenesik / Sologic concernant les banni�res
// *     et les outils d'installation et de visualisation des versions (voir Emmanuel Beck)
// *     ce fichier doit �tre inclu dans un FICHIER C.
// * 
// * ATTENTION  : mettre toujours un \0 � la fin des strings
// *              (compatibilit� avec les ressources Win32)
// *
// **************************************************************************************

// --- Version (C et Res) ----------------------------------------------------
//     Obligatoire
//     Format pour Res (windows): "N.NN.N.NN\0"
//     Format pour C   (tout OS): "NNNNNN"
// ---------------------------------------------------------------------------

#define VER_FILEVERSION_STR      "3.2a.0.00\0"
#define VER_FILEVERSION_STRC     "32a000"
#define VER_FILEDESCRIPTION_STR  VER_FILEVERSION_STR

// --- Status (C) -------------------------------------------------
//     '0': Module d�finitif
//     '1': Module provisoire
//     '2': Module b�ta test (d�faut)
// ----------------------------------------------------------------
#define VER_STATUS    '2'

// --- Type de fichier (Res) --------------------------------------
//     Obligatoire
// VER_FILETYPE               0x00000001L pour EXE ou 0x00000002L pour DLL
// VER_FILESUBTYPE            (0)
// ----------------------------------------------------------------
#define VER_FILETYPE                    0x00000002L
#define VER_FILESUBTYPE                 (0)

// --- Identification du fichier (C et Res) -----------------------
// VER_ORIGINALFILENAME_STR   Nom du fichier 
// VER_PRODUCTNAME_STR        Nom produit du fichier 
// VER_INTERNALNAME_STR       Nom interne avec info de build
// ----------------------------------------------------------------

#if defined(BDA_TWIN16)
#define VER_ORIGINALFILENAME_STR     "PrlTra.xp\0"
#define VER_PRODUCTNAME_STR          "BDA de trace ABAL pour TwinServer\0"

#elif defined(BDA_UNIX)
#define VER_ORIGINALFILENAME_STR     "prltra.so\0"
#define VER_PRODUCTNAME_STR          "BDA de trace ABAL pour UseIt\0"

#elif defined(WIN32) || defined(BDA_WIN32)
#define VER_ORIGINALFILENAME_STR     "PrlTra32.dll\0"
#define VER_PRODUCTNAME_STR          "BDA de trace ABAL pour Win32\0"

#else // Win16
#define VER_ORIGINALFILENAME_STR     "PrlTra16.dll\0"
#define VER_PRODUCTNAME_STR          "BDA de trace ABAL pour Win16\0"
#endif

#define VER_INTERNALNAME_STR         "PrlTra\0"

// --- Identification du build (C et Res) -------------------------
//     3 m�thodes possibles :
//     1�) standard, infos debug,trace, sans langue
//         #include "banbuild.h"
//     2�) standard, infos debug,trace,langue
//         #define BUILD_LANG
//         #include "banbuild.h"
//     3�) personnalis�, on met ce qu'on veut
//         il faut d�finir soi-m�me VER_BUILD_STR
//         Format pour Res et C: "xxxxxxxxx\0" (toujours 9 caract�res+\0)
// ----------------------------------------------------------------

#include "banbuild.h"

// --- Commentaires (C) -------------------------------------------
// ----------------------------------------------------------------
#define VER_COMMENT  " "

#if defined(BDA_VC) || defined(BDA_GNUC) || defined(BDA_BORLAND) || defined(UNIX)
// inlusion C
#include "bancode.h"
#else
// inlusion Res
#include "version.rc"
#endif
