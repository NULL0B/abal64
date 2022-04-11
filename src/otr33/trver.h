// *************************************************************************************
// * MyVersion.h
// * Modèle pour l'implémentation des paternes dans un exécutable C
// *
// * Définition de la version
// *  
// *   - pour Win16 et Win32 (exe ou dll)
// *     la version doit être visible dans les propriétés du fichier
// *     ce fichier doit être inclu dans les RESSOURCES
// *     (donc compatible avec le compilateur de ressource)
// * 
// *   - pour tous les OS (y compris Windows)
// *     le fichier doit répondre aux normes définies par Amenesik / Sologic concernant les bannières
// *     et les outils d'installation et de visualisation des versions (voir Emmanuel Beck)
// *     ce fichier doit être inclu dans un FICHIER C.
// * 
// * ATTENTION  : mettre toujours un \0 à la fin des strings
// *              (compatibilité avec les ressources Win32)
// *
// **************************************************************************************

// *************************************
// * constantes de compilation         *
// *************************************
// * Standards      * BDA ligne outils * 
// *************************************
// * _WIN32         * BDA_WIN32        * C Win32
// * _WINDOWS       * BDA_WIN16        * C Win16
// * _CONSOLE       * -                * Appli console
// * WIN32          * -                * Res Windows
// * __linux__      * BDA_UNIX         * Linux
// * __Prl          * BDA_TWIN16       * Amenesik / Sologic
// *************************************
// * _MSC_VER       * BDA_VC           * VisualC
// * __BORLANDC__   * BDA_BORLAND      * Borland
// * __GNUC__       * BDA_GNUC         * GnuC
// *************************************

// --- Version (C et Res) ----------------------------------------------------
//     Obligatoire
//     Format pour Res (windows): "N.NN.N.NN\0"
//     Format pour C   (tout OS): "NNNNNN"
// ---------------------------------------------------------------------------
#ifdef ABAL33A
#define VER_FILEVERSION_STR      "otr 3.3a.0.05\0"
#define VER_FILEVERSION_STRC     "33a005"
#else
#ifdef ABAL32A
#define VER_FILEVERSION_STR      "otr 3.2a.0.05\0"
#define VER_FILEVERSION_STRC     "32a005"
#else
#define VER_FILEVERSION_STR      "otr 3.1e.0.05\0"
#define VER_FILEVERSION_STRC     "31e005"
#endif
#endif

#define VER_FILEDESCRIPTION_STR  VER_FILEVERSION_STR

// --- Status (C) -------------------------------------------------
//     '0': Module définitif
//     '1': Module provisoire
//     '2': Module béta test (défaut)
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

#if defined(__Prl) || defined(BDA_TWIN16)
#define VER_ORIGINALFILENAME_STR     "otr.xp\0"
#define VER_PRODUCTNAME_STR          "ABAL Object Translator for TwinServer\0"

#elif defined(__linux__) || defined(BDA_UNIX)
#define VER_ORIGINALFILENAME_STR     "otr\0"
#define VER_PRODUCTNAME_STR          "ABAL Object Translator for UseIT\0"

#elif defined(WIN32) || defined(_WIN32) || defined(BDA_WIN32)
#ifdef otr32
#define VER_ORIGINALFILENAME_STR     "wotr32.exe\0"
#define VER_PRODUCTNAME_STR          "ABAL 32 bits Object Translator for Windows\0"
#else
#define VER_ORIGINALFILENAME_STR     "wotr16.exe\0"
#define VER_PRODUCTNAME_STR          "ABAL 16 bits Object Translator for Windows\0"
#endif

#else // Win16
#define VER_ORIGINALFILENAME_STR     "\0"
#define VER_PRODUCTNAME_STR          "\0"
#endif

#define VER_INTERNALNAME_STR         "Otr\0"

// --- Commentaires (C) -------------------------------------------
// ----------------------------------------------------------------
#define VER_COMMENT  ""


// --- Identification du build (C et Res) -------------------------
//     3 méthodes possibles :
//     1°) standard Ligne Outils = infos debug,trace
//         #define BUILD_LIGNE_OUTILS
//     2°) standard Ligne Outils = infos debug,trace + langue
//         #define BUILD_LIGNE_OUTILS
//         #define BUILD_LANG
//     3°) personnalisé, on met ce qu'on veut
//         il faut définir soi-même VER_BUILD_STR
//         Format pour Res et C: "xxxxxxxxx\0" (TOUJOURS 9 caractères+\0)
// ----------------------------------------------------------------
//    REGLE D'UTILISATION pour le standard Ligne Outils: 
//    Cette partie génère les infos de build selon les conventions suivantes : 
//    D = debug
//    T = trace
//    FR = français
//    EN = anglais
// ----------------------------------------------------------------

#if defined (TRACEON)

	#if defined (_DEBUG)
		#ifdef otr32
			#define VER_BUILD_STR		"DT32     \0"	
		#else
			#define VER_BUILD_STR		"DT16     \0"	
		#endif
	#else
		#ifdef otr32
			#define VER_BUILD_STR		"RT32     \0"	
		#else
			#define VER_BUILD_STR		"RT16     \0"	
		#endif
	#endif

#else

	#if defined (_DEBUG)
		#ifdef otr32
			#define VER_BUILD_STR		"D32      \0"	
		#else
			#define VER_BUILD_STR		"D16      \0"	
		#endif
	#else
		#ifdef otr32
			#define VER_BUILD_STR		"R32      \0"	
		#else
			#define VER_BUILD_STR		"R16      \0"	
		#endif
	#endif

#endif


// --- Inclusions (C et Res) --------------------------------------
// ----------------------------------------------------------------
#if defined(_MSC_VER) || defined(__GNUC__) || defined(__BORLANDC__)
// inlusion C
#include "bankrnl.h"
#else
// inlusion Res
#include "bankrnl.rc"
#endif
