// *************************************************************************************
// * cicover.h
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

#ifdef ABAL32A
#define VER_FILEVERSION_STR      "3.2a.1.12\0"
#define VER_FILEVERSION_STRC     "32a112"
#else
#define VER_FILEVERSION_STR      "3.1e.1.12\0"
#define VER_FILEVERSION_STRC     "31e112"
#endif

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
#define VER_ORIGINALFILENAME_STR     "visual.xp\0"
#define VER_PRODUCTNAME_STR          "Biblioth�que Visual pour TwinServer\0"

#elif defined(BDA_UNIX)
#define VER_ORIGINALFILENAME_STR     "visual.so\0"
#define VER_PRODUCTNAME_STR          "Biblioth�que Visual pour UseIt\0"

#elif defined(WIN32) || defined(BDA_WIN32)
#define VER_ORIGINALFILENAME_STR     "visual.dll\0"
#define VER_PRODUCTNAME_STR          "Biblioth�que Visual pour Windows\0"

#else // Win16
#define VER_ORIGINALFILENAME_STR     "visual.dll\0"
#define VER_PRODUCTNAME_STR          "Biblioth�que Visual pour Win16\0"
#endif

#define VER_INTERNALNAME_STR         "visual ABAL3\0"

// --- Commentaires (C) -------------------------------------------
// ----------------------------------------------------------------

#define VER_COMMENT  "Biblioth�que d'outils visuels pour ABAL3"

// --- Identification du build (C et Res) -------------------------
//     3 m�thodes possibles :
//     1�) standard Ligne Outils = infos debug,trace
//         #define BUILD_LIGNE_OUTILS
//     2�) standard Ligne Outils = infos debug,trace + langue
//         #define BUILD_LIGNE_OUTILS
//         #define BUILD_LANG
//     3�) personnalis�, on met ce qu'on veut
//         il faut d�finir soi-m�me VER_BUILD_STR
//         Format pour Res et C: "xxxxxxxxx\0" (TOUJOURS 9 caract�res+\0)
// ----------------------------------------------------------------
//    REGLE D'UTILISATION pour le standard Ligne Outils: 
//    Cette partie g�n�re les infos de build selon les conventions suivantes : 
//    D = debug
//    T = trace
//    FR = fran�ais
//    EN = anglais
// ----------------------------------------------------------------

#if defined(BDA_ABAL2) //////////////////////////////////
#if defined(BUILD_LANG)
   // ---------------------------------------------------
   // - Avec infos de langage
   // ---------------------------------------------------
   #if defined (US_VERSION)
      // --- Anglais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "2DT EN   \0"
        #else
          #define VER_BUILD_STR "2D EN    \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "2T EN    \0"
        #else
          #define VER_BUILD_STR "2 EN     \0"
        #endif
      #endif
   #else
      // --- Fran�ais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "2DT FR   \0"
        #else
          #define VER_BUILD_STR "2D FR    \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "2T FR    \0"
        #else
          #define VER_BUILD_STR "2 FR     \0"
        #endif
      #endif
   #endif

#else
   // ---------------------------------------------------
   // - Pas d'infos de langage
   // ---------------------------------------------------
   #if defined(_DEBUG) || defined(DEBUG)
     #if defined(TRACEON)  //"123456789\0"
       #define VER_BUILD_STR "2DT      \0"
     #else
       #define VER_BUILD_STR "2D       \0"
     #endif
   #else
     #if defined(TRACEON)
       #define VER_BUILD_STR "2T       \0"
     #else
       #define VER_BUILD_STR "2        \0"
     #endif
   #endif

#endif

#else ///////////////////////////////////////////////////

#if defined(BUILD_LANG)
   // ---------------------------------------------------
   // - Avec infos de langage
   // ---------------------------------------------------
   #if defined (US_VERSION)
      // --- Anglais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "3DT EN   \0"
        #else
          #define VER_BUILD_STR "3D EN    \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "3T EN    \0"
        #else
          #define VER_BUILD_STR "3 EN     \0"
        #endif
      #endif
   #else
      // --- Fran�ais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "3DT FR   \0"
        #else
          #define VER_BUILD_STR "3D FR    \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "3T FR    \0"
        #else
          #define VER_BUILD_STR "3 FR     \0"
        #endif
      #endif
   #endif

#else
   // ---------------------------------------------------
   // - Pas d'infos de langage
   // ---------------------------------------------------
   #if defined(_DEBUG) || defined(DEBUG)
     #if defined(TRACEON)  //"123456789\0"
       #define VER_BUILD_STR "3DT      \0"
     #else
       #define VER_BUILD_STR "3D       \0"
     #endif
   #else
     #if defined(TRACEON)
       #define VER_BUILD_STR "3T       \0"
     #else
       #define VER_BUILD_STR "3        \0"
     #endif
   #endif

#endif
#endif //////////////////////////////////////////////////

// --- Inclusions (C et Res) --------------------------------------
// ----------------------------------------------------------------
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__BORLANDC__)
#include "bankrnl.h"
#else
#include "bankrnl.rc"
#endif
