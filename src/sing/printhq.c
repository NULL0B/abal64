/*
 *	Projet  : ABAL			Copyright Amenesik / Sologic s.a. (c) 2003
 *	Fichier : printhq.c
 *	Date    : 04/11/2005
 *	Systeme : Windows
 * Auteurs : FCh
 */

/* --------------------------------------------------------------------------
 * Mises a jour : 
 * ------------
*/

#include <windows.h>

#include	"bda.h"
#ifndef	BPTR
#define	BPTR BYTE FAR PTR
#endif
#ifndef	WPTR
#define	WPTR WORD FAR PTR
#endif
#ifndef	LPTR
#define	LPTR LONG FAR PTR
#endif

#include "allocate.h"
#include "rgraphapi.h"
#include "vobjapi.h"
#include "vimage.h"
#include "strucpsu.h"

#include "tablecico.h"
extern TABLE_CICO* gPtrCurrent;

#define CI_MODULE_ID 0x8000 // pour la trace

void makefit_buffer_byexa( int atx,int aty, int nbx, int nby , STDPSUPTR vptr );
int  visual_buffer_put(STDPSUPTR pptr, int atx, int aty );
int  visual_buffer_get(STDPSUPTR pptr, int atx, int aty );

void style_set_hq( int xdpiDes, int ydpiDes, int scaleDes, int cxDes, int cxOri, int cyDes, int cyOri );
void style_set_screen( int xdpi, int ydpi );

// **************************************************************************************************
// * imp_image_old 
// * Envoi de l'image ligne par ligne
// * ne pas supprimer car algo plus portable car tout le stretch peut être fait à la main ici
// **************************************************************************************************
static WORD imp_image_old( WORD nolog, STDPSUPTR pptr, LONG xPrn, LONG yPrn, LONG cxPrn, LONG cyPrn)
{
WORD	ret;
char*	bptr;
LONG	cx;
LONG	cy;
// Pas de Stretch en x LONG*		tabx;
LONG*		taby;
// Pas de Stretch en x int		ix;
int		iy;
unsigned long tmp;
int		IsNewLine;
union 
	{ 
	BYTE* b;
	LONG* l;
	} RgbRow /*,RgbRowPrn*/;

cx = pptr->descriptor[0];
cy = pptr->descriptor[1];

//tabx        = NULL;
taby        = NULL;
RgbRow.b    = NULL;
//RgbRowPrn.b = NULL;
ret         = FALSE;

/*
--------------------------------------------------------------
- Cas particulier sans mise à l'échelle algo rapide
--------------------------------------------------------------
*/
if ((cxPrn == cx) && (cyPrn == cy))
	{
	RgbRow.b = allocate( cx * 4);
	if (!RgbRow.b)
		return FALSE;

	for ( iy=0,ret=TRUE ; (iy<cyPrn) && (ret) ; iy++ )
		{
		bptr = connect_pixel_row( pptr, iy );
		if (bptr)
			{
			rgbzone( RgbRow.b, cx, 1, bptr, 0xF8);
			ret = (! gPtrCurrent->Function.x_printimg( nolog, RgbRow.b, cxPrn, 1, xPrn, (LONG)(yPrn+iy), cxPrn, 1));  
			}
		else
			ret = FALSE; 
		}

	return ret;
	}

/*
--------------------------------------------------------------
- Allocations en fonction des tailles trouvées
--------------------------------------------------------------
*/

RgbRow.b = allocate( cx * 4);
if (!RgbRow.b)
	goto etiq_fin;

/* Pas de Stretch en x

Sous Windows, il vaut mieux ne pas faire le stretch en x nous même
On laisse faire le GDI.
Le fichier d'impression est de taille beaucoup plus petite que si
on le fait à la main ici
(ex: 20 Mo en 100dpi --> 115 Mo en 600dpi pour du A4)

RgbRowPrn.b = allocate( cxPrn * 4);
if (!RgbRowPrn.b)
	goto etiq_fin;

tabx = allocate( cxPrn*sizeof(LONG) );
if (!tabx)
	goto etiq_fin;
*/

taby = allocate( cyPrn*sizeof(LONG) );
if (!taby)
	goto etiq_fin;

/*
--------------------------------------------------------------
- Calcul de la mise à l'échelle en x et y
--------------------------------------------------------------
*/

/* Pas de Stretch en x
for (ix=0 ; ix<cxPrn ; ix++)
   {
   tmp = (unsigned long)ix * (unsigned long)cx / (unsigned long)cxPrn; 
   tabx[ix] = (WORD) tmp;
   }
*/

for (iy=0 ; iy<cyPrn ; iy++)
   {
   tmp = (unsigned long)iy * (unsigned long)cy / (unsigned long)cyPrn; 
   taby[iy] = (WORD) tmp;
   }
   
/*
--------------------------------------------------------------
- Impression
--------------------------------------------------------------
*/
for ( iy=0,ret=TRUE ; (iy<cyPrn) && (ret) ; iy++ )
   {
	/*
   -- Fabrication d'une nouvelle ligne
      Si la ligne est identique à celle utilisée par l'itération précédente, on garde 
      Sinon, on en refabrique une nouvelle
	*/
   IsNewLine = ((iy==0) || (taby[iy-1]!=taby[iy]));
         
   if (IsNewLine)
      {
		bptr = connect_pixel_row( pptr, taby[iy] );
		if (bptr)
			{
			rgbzone( RgbRow.b, cx, 1, bptr, 0xF8);
			/*	Pas de Stretch en x
			for( ix=0 ; ix<cxPrn ; ix++)
				RgbRowPrn.l[ix] = RgbRow.l[tabx[ix]];
			*/
			ret = TRUE;
			}
		else
			ret = FALSE;
		}
	if (ret)
		{
		/*	Pas de Stretch en x
		ret = (! gPtrCurrent->Function.x_printimg( nolog, RgbRowPrn.b, cxPrn, 1, xPrn, (LONG)(yPrn+iy), cxPrn, 1));   
		*/
		ret = (! gPtrCurrent->Function.x_printimg( nolog, RgbRow.b, cx, 1, xPrn, (LONG)(yPrn+iy), cxPrn, 1));   
		}
   }

/*
--------------------------------------------------------------
- Libérations
--------------------------------------------------------------
*/
etiq_fin:
if (RgbRow.b)
	liberate(RgbRow.b);

/*	Pas de Stretch en x
if (RgbRowPrn.b)
	liberate(RgbRowPrn.b);

if (tabx)
	liberate(tabx);
*/

if (taby)
	liberate(taby);

return ret;
}

// **************************************************************************************************
// * imp_image 
// * Envoi de l'image ligne par ligne
// * nouvel algo encore plus mieux qu'avant
// * en s'appuyant sur le stretch du GDI en horizontal et en vertical
// * (gain en temps de traitement et volume de données)
// **************************************************************************************************
static WORD imp_image( WORD nolog, STDPSUPTR pptr, LONG xPrn, LONG yPrn, LONG cxPrn, LONG cyPrn)
{
WORD	ret;
char*	bptr;
LONG	cx;
LONG	cy;
LONG*		taby;
int		iy;
int		iyPrn;
unsigned long tmp;
union 
	{ 
	BYTE* b;
	LONG* l;
	} RgbRow;

cx = pptr->descriptor[0];
cy = pptr->descriptor[1];

taby        = NULL;
RgbRow.b    = NULL;
ret         = FALSE;

/*
--------------------------------------------------------------
- Allocations en fonction des tailles trouvées
--------------------------------------------------------------
*/

RgbRow.b = allocate( cx * 4);
if (!RgbRow.b)
	goto etiq_fin;

taby = allocate( cy*sizeof(LONG) );
if (!taby)
	goto etiq_fin;

/*
--------------------------------------------------------------
- Calcul de la mise à l'échelle en x et y
--------------------------------------------------------------
*/

memset( taby, 0 , cy*sizeof(LONG)); 
for (iy=0 ; iy<cyPrn ; iy++)
   {
   tmp = (unsigned long)iy * (unsigned long)cy / (unsigned long)cyPrn; 
   taby[tmp]++;
   }
   
/*
--------------------------------------------------------------
- Impression
--------------------------------------------------------------
*/

for ( iy=0 , iyPrn=yPrn , ret=TRUE ; (iy<cy) && (ret) ; iy++  )
	{
	bptr = connect_pixel_row( pptr, iy );
	if (bptr)
		{
		rgbzone( RgbRow.b, cx, 1, bptr, 0xF8);
		ret = (! gPtrCurrent->Function.x_printimg( nolog, RgbRow.b, cx, 1, xPrn, iyPrn, cxPrn, taby[iy]));   
		}
	else
		ret = FALSE; 

	iyPrn += taby[iy];
	}

/*
--------------------------------------------------------------
- Libérations
--------------------------------------------------------------
*/
etiq_fin:
if (RgbRow.b)
	liberate(RgbRow.b);

if (taby)
	liberate(taby);

return ret;
}

// **************************************************************************************************
// * printhq_buffer
// **************************************************************************************************
WORD printhq_buffer( WORD nolog, STDPSUPTR OriBuf, WORD Mode, WORD Zoom)
{
// Taille du buffer d'origine
// (généralement taille pour affichage à l'écran)
LONG	cxOri;
LONG	cyOri;
// Coordonnées sur la feuille 
// (dépend des caractéristiques physiques de l'imprimante et de sa configuration)
LONG	xPrn;
LONG	yPrn;
LONG	cxPrn;
LONG	cyPrn;
// Taille du buffer de travail (compris entre cBuf et cPrn)
// (dépend de la résolution de travail définie par configuration)
// Permet de travailler sur des tailles inférieures à la résolution physique de l'imprimante
// et donc d'éviter des buffers énormes en mémoire (ex 300dpi au lieu de 4800dpi)
LONG	cxWork;
LONG	cyWork;
// Divers
STDPSUPTR		WorkBuf;
STDPSUPTR		CopyScreenBuf;
WORD	ret;
WORD  dpi;

dpi = gethqfont();
sethqfont(75);

// ------------------------------------------------------------------
// - Définition de toutes les tailles
// - Fabrication du buffer de travail
// ------------------------------------------------------------------

cxOri = OriBuf->descriptor[0];
cyOri = OriBuf->descriptor[1];

switch(Mode)
	{
	case 1:
		// Prévisualisation à l'écran avec zoom
		// Gadget pratique
		// Petit algo affichant l'image et attendant une frappe clavier
		// pour l'effacer
		if (Zoom==0)
			Zoom = 75 * 100 / dpi;

		cxWork = cxOri * Zoom / 100;
		cyWork = cyOri * Zoom / 100;

		WorkBuf = allocate_graphic_storage(0, 0, cxWork, cyWork);
		background_pixel_capture(WorkBuf);
		makefit_buffer_byexa( 0, 0, cxWork, cyWork, OriBuf);
		cancel_pixel_capture(WorkBuf);

		CopyScreenBuf = allocate_graphic_storage(0, 0, cxWork, cyWork);
		ret = visual_buffer_get( CopyScreenBuf, 0, 0);
		ret = visual_buffer_put( WorkBuf, 0, 0);
		visual_getch();
		ret = visual_buffer_put( CopyScreenBuf, 0, 0);
		liberate_pixel_storage(CopyScreenBuf);
		liberate_pixel_storage(WorkBuf);
		break;

	default:
		// Impression optimisée
		ret = imp_compute_coordinates_byexa( nolog, cxOri, cyOri, &xPrn, &yPrn, &cxPrn, &cyPrn, &cxWork, &cyWork);
		if (!ret)
			ret = imp_image( nolog, OriBuf, xPrn, yPrn, cxPrn, cyPrn);
		break;
	}

// ------------------------------------------------------------------
// - Ménage
// ------------------------------------------------------------------

sethqfont(dpi);

return ret;
}

