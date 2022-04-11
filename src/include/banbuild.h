// ***************************************************************************************************
// 
//    banbuild.h
//    Compl&eacute;ment pour l'automatisation de la gestion d'une banni&egrave;re d'un programme.
//  
//    REGLE D'UTILISATION : 
//    Ce fichier g&eacute;n&egrave;re les infos de build selon les conventions suivantes : 
//    D = debug
//    T = trace
//    FR = fran&ccedil;ais
//    EN = anglais
// 
// ***************************************************************************************************

#if defined(BUILD_LANG)

   // ---------------------------------------------------
   // - Avec infos de langage
   // ---------------------------------------------------
   #if defined (US_VERSION)
      // --- Anglais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "DT EN    \0"
        #else
          #define VER_BUILD_STR "D EN     \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "T EN     \0"
        #else
          #define VER_BUILD_STR "EN       \0"
        #endif
      #endif
   #else
      // --- Fran&ccedil;ais
      #if defined(_DEBUG) || defined(DEBUG)
        #if defined(TRACEON)  //"123456789\0"
          #define VER_BUILD_STR "DT FR    \0"
        #else
          #define VER_BUILD_STR "D FR     \0"
        #endif
      #else
        #if defined(TRACEON)
          #define VER_BUILD_STR "T FR     \0"
        #else
          #define VER_BUILD_STR "FR       \0"
        #endif
      #endif
   #endif

#else

   // ---------------------------------------------------
   // - Pas d'infos de langage
   // ---------------------------------------------------
   #if defined(_DEBUG) || defined(DEBUG)
     #if defined(TRACEON)  //"123456789\0"
       #define VER_BUILD_STR "DT       \0"
     #else
       #define VER_BUILD_STR "D        \0"
     #endif
   #else
     #if defined(TRACEON)
       #define VER_BUILD_STR "T        \0"
     #else
       #define VER_BUILD_STR "         \0"
     #endif
   #endif

#endif
