#include "xgraph.h"

#define	private	static
#define	public 

private	void **	XgraphPtr=(void*) 0;

#define	_MAX_WINDOWS	 132
#define	_MAX_MENUS	  32
#define	_MAX_OPTIONS	  30
#define	_MAX_CHAINS	   5
#define	_MAX_LISTS	  32
#define	_MAX_ITEMS 	9999
#define	_MAX_DBOXS	   8
#define	_MAX_ELEMENTS	 128 
#define	_MAX_VALUE	  80
#define	_MAX_COMMENT	  80
#define	_MAX_STATUS_MSG	 256

#define	WORDSIZE	2

#define Bmere_nbr	0	/* numero mere ou console		*/
#define Bpos_lig	2	/* position ligne			*/
#define Bpos_col	4	/* position colonne			*/
#define Bnb_lig 	6	/* Nombre de lignes			*/
#define Bnb_col 	8	/* Nombre de colonnes			*/
#define Batb_vid	10	/* attribut video texte 		*/
#define Batbcol_text	11	/* couleur texte			*/
#define Batbcol_fond	12	/* couleur fond 			*/
#define Bcontrol	13	/* bit 0 = 1  (1): Invisible		*/
				/* bit 1 = 1  (2): Curseur actif	*/
				/* bit 2 = 1  (4): SCROLL actif 	*/
				/* bit 3 = 1  (8): Cadre simple trait	*/
				/* bit 4 = 1 (16): Cadre double trait	*/
				/* bit 5 = 1 (32): Cadre utilisateur	*/
#define Bln_tit 	15	/* Longueur titre			*/
#define Btitre		17	/* Titre fenetre			*/
#define Bcad_usr	49	/* Cadre utilisateur			*/
#define Bcad_atb	57	/* attribut cadre user			*/
#define Bcad_text	58	/* couleur texte cadre user		*/
#define Bcad_fond	59	/* couleur fond cadre user		*/
#define Breserve	60

struct	asfun_control	{

	int	statusbar;
	int	statusline;
	int	statustype;
	int	freeze;
	int	language;

	/* WINIT Options */
	/* ------------- */
	int	nbc;
	int	nbl;
	int	capture;
	int	basefont;

	int	options;
	int	filler;
	int	atb;
	int	fg;
	int	bg;

	/* Operational PArameters */
	/* ---------------------- */
	int	w;
	int	h;
	int	gfh;
	int	gfw;
	int	status;
	int	mode;
	int	implicite;
	int	active;
	char	Escape[33];
	int	nesting;
	int	nested[16];
	int	choice[16];
	struct	asfun_menu   * menus[_MAX_MENUS];
	struct	asfun_list   * lists[_MAX_LISTS];
	struct	asfun_dbox   * dboxs[_MAX_DBOXS];
	struct	asfun_window * windows[_MAX_WINDOWS];

	char	statusmessage[_MAX_STATUS_MSG+1];

	} Control = {
	0,0,0,
	0,
	0,
	0,0,
	0,0,
	0,0,0,0,0,	
	800,600,
	24,10,
	0,0,0,0
	};


