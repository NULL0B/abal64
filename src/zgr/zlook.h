// ****************************************************************************
// * zLook.h
// * Look module
// ****************************************************************************

#ifndef ZLOOK_H
#define ZLOOK_H

extern char	*	helpskin; // from Jamie must ne removed

#ifdef __cplusplus
  extern "C" {
#endif

// ----------------------------------------------------------------------------
// - Internal functions
// ----------------------------------------------------------------------------

// zLooSkin
WORD	LookLoadSkin( char * nptr );
WORD	LookLoadSkinByImages(VOID);
void	LookApplySkin( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags );
void  LookApplySkinButton( int atcol , int atlin, int nbcol, int nblin, char * sptr, int flags );
void	LookRelief(int atx,int aty, int nbx, int nby, int hl, int bg, int ll );

// zLooPal
WORD LookInitPalette(VOID);
VOID LookEndPalette(VOID);
VOID	zcicocolour(WORD f, WORD b);

// zLooComp
WORD LookInitAllComponents(VOID);
VOID LookEndAllComponents(VOID);

#ifdef __cplusplus
  }
#endif

#endif
