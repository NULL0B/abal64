/* Fichier include pour boite de dialogue */






/* includes sp‚cifiques fenetrage */

#include 	"sfundef.h"
#include 	"bda.h"





#define DIM_DATA_BOX	 512	/* dimension de la data box 		*/
#define DIM_DATA_BOX1	1024	/* dimension de la data box 		*/
#define DIM_DATA_BOX2	2048	/* dimension de la data box 		*/

#define MAX_ELEM	 32	/* dimension de la table d'aiguillage 	*/
#define MAX_ELEM1	 64	/* dimension de la table d'aiguillage 	*/
#define MAX_ELEM2	128	/* dimension de la table d'aiguillage 	*/

#define MAX_BOUT_R_C	15	/* nb max bouton dans radio et check	*/




#define ACTIF		1       /* Activit‚ des elements du dialogue 	*/
#define INACTIF 	0
#define	ACTIF2		2	/* mode interaction 2			*/



/* codes erreur */

#define No_err		0

#define Bd_err_arg	10	/* erreur de nombre d'arguments 	*/
#define Bd_err_pos       1	/* erreur de taille ou position dialog 	*/
#define Bd_err_sty	 1	/* erreur nø de style */
#define Bd_err_tit	 1	/* erreur dans longueur du titre 	*/
#define Bd_err_max	 4	/* pas de place dans TB_BOX 		*/
#define Bd_err_typ	11	/* erreur dans type arg 		*/


#define Bd_err_nobd	 2	/* nø de boite de dialogue inconnu 	*/
#define Bd_err_maxel	 4	/* nb ‚l‚ment max atteint pour dialog 	*/
#define Bd_err_type	 1	/* type d'‚l‚ment inconnu 		*/
#define Bd_err_data	 5	/* d‚bordement data_box			*/


#define Bd_err_noel	 1	/* nø element inconnu			*/



#define Bd_err_type_c_b	 1	/* type check_bouton inconnu		*/



#define Bd_err_l_open	 6	/* liste non ferm‚e			*/

#define Bd_err_code_b	 1	/* code bouton n‚gatif			*/

#define Bd_err_nonact	 7	/* aucun ‚l‚ment actif			*/

#define Bd_err_non_imp  99	/* non implant‚				*/



/* d‚finition des types des ‚l‚ments */

#define MESSAGE		1
#define BOUTON		2
#define R_BOUTON	3
#define C_BOUTON	4
#define SAISIE		5
#define LISTE		6
#define AIDE		7
#define FUNFREE         8


/* d‚finition du type de traitement */

#define INIT		1
#define TRAIT 		2
#define FIN		3
#define KILL		4
#define ACTION		5


/* d‚finition des codes de retour des fonctions de traitement */

#define D_ESCAPE	-254
#define D_INTERACTION	-255
#define D_SUIVANT	-256
#define D_PRECEDENT	-257
#define D_GAUCHE	-258
#define D_DROIT		-259
#define D_HAUT          -260
#define D_BAS           -261
#define D_OLD		-262


#define D_EQUIV		-300	/* base de retour sur equiv. clavier		*/

#define D_TCH_ESC	-400	/* base de retour su touche d'echappement	*/


#define NO_RETOUR	0
#define NO_EQUIV	0

#define VALIDER 	1
#define ANNULER         2


/* d‚finition du masque interaction */

#define E_INTERACTIF	256
#define E_INTERACTIF2	512
#define INTER_VALID 	1
#define INTER_NEXT 	2
#define INTER_PREV 	3
#define INTER_MOUSE 	4

#define INTER_CURUP	5
#define INTER_CURDOWN	6
#define INTER_PGUP	7
#define INTER_PGDOWN	8


/* structure de correspondance caractŠre -> ‚l‚ment */

typedef struct {
		BYTE car;
		BYTE no_elem;
	       } ASS_CAR;

/* structure d'‚quivalence caractŠre */

typedef struct {
		ASS_CAR tab_eq[MAX_ELEM2];	/* tableau des ‚quivalences clavier	*/
		BYTE nb_eq;			/* nb d'‚quivalences			*/
		BPTR aig_bd_eq;			/* ptr sur table d'aiguillage dialogue	*/
	       } EQUIV;



/* structure data element */

typedef struct {
		BPTR data_ptr;		/* pointeur sur zone dans DATA_BOX	*/
		EQUIV_PTR equi_c;	/* pointeur sur table d'‚quivalence car.*/
		WORD x;         	/* colonne du pt sup gauche 		*/
		WORD y;			/* ligne du pt sup gauche 		*/
		WORD w;			/* largeur element 			*/
		WORD h;	 		/* hauteur element 			*/
		WORD o_h;
		WORD o_v;		/* offset vertical et horizontal	*/
		BYTE etat;		/* etat de l'‚l‚ment (actif/inactif)    */
		BYTE v_g;		/* voisin de gauche			*/
		BYTE v_d;		/* voisin de droite			*/
		BYTE v_h;		/* voisin du haut			*/
		BYTE v_b;		/* voisin du bas			*/
		BYTE mode_inter;	/* interation ou non			*/
		BPTR desc_elem;		/* ptr sur descritption de l'‚l‚ment 	*/
	       } DATA_ELEM;



/* structure de BD_AIG */

typedef struct {
		fct_far_ptr 	traitement;	/* ptr sur fct de traitement TC	*/
		DATA_ELEM_PTR 	dat_elem;	/* ptr sur data de l'‚l‚ment	*/
	       } AIG_;


/* structure de boite de dialogue */

typedef struct {
		WORD x;				/* colonne du pt sup gauche 		*/
		WORD y;                         /* ligne du pt sup gauche 		*/
		WORD w;				/* largeur dialogue 			*/
		WORD h;				/* hauteur dialogue 			*/
		WORD len_box;
		WORD max_elem;

		BYTE fl_aff;			/* flag d'affichage du dialog		*/
/*		BYTE data_box[DIM_DATA_BOX];	** la data box 				*/
/*		BYTE data_box_c[DIM_DATA_BOX];  ** copie de la data box 		*/
		BPTR data_box;
		BPTR data_box_c;
		WORD i_data;			/* indice courant dans data box 	*/
		BYTE nb_elem;			/* nb elements de la boite 		*/
/*		BYTE stf_bd;			** m‚mo style fenˆtre du dialogue	*/
		stf_desc * stf_bd;
/*		AIG_ bd_aig[MAX_ELEM];		** la table d'aiguillage 		*/
		AIG_PTR bd_aig;
		EQUIV bd_equiv;
	       } B_DIAL;
/***********
typedef struct {
		WORD x;				** colonne du pt sup gauche 		**
		WORD y;                         ** ligne du pt sup gauche 		**
		WORD w;				** largeur dialogue 			**
		WORD h;				** hauteur dialogue 			**
		WORD len_box;
		WORD max_elem;

		BYTE fl_aff;			** flag d'affichage du dialog		**
		BYTE data_box[DIM_DATA_BOX1];	** la data box 				**
		BYTE data_box_c[DIM_DATA_BOX1]; ** copie de la data box 		**
		WORD i_data;			** indice courant dans data box 	**
		BYTE nb_elem;			** nb elements de la boite 		**
		BYTE stf_bd;			** m‚mo style fenˆtre du dialogue	**
		AIG_ bd_aig[MAX_ELEM1];		** la table d'aiguillage 		**
		EQUIV bd_equiv;
	       } B_DIAL1;
***********/



/* structure TB_BOX (tableau des entr‚es dialog) */

typedef struct {
		WORD no_log;
		B_DIAL_PTR dial;
	       } TB_STR;







/*----------------------------------------------
   Definition des boutons
 ---------------------------------------------*/


/* Structure d'un bouton */


typedef struct {
		WORD code;      /* le code de sortie  			*/
		BYTE car_ex;	/* le caractŠre de selection du bouton	*/
		BYTE car_ex_pos;/* position du caractŠre de validation	*/
	       } DESC_BOUTON;




#define Nb_data_bouton	1	/* (1) ETAT				*/

#define I_etat_bouton	0





/*----------------------------------------------
   Definition des radio_boutons
 ---------------------------------------------*/


/* Structure de donn‚e */


typedef struct {
		BYTE nb_elem;	/* le nombre d'elements du radio bouton	*/
		BYTE atb_v;	/* m‚mo attribut vid‚o 			*/
		BYTE col_f; 	/* m‚mo couleur fond			*/
		BYTE col_t;	/* m‚mo couleur texte			*/
	       } DESC_R_BOUTON;




#define Nb_data_r_bouton	3	/* (1) ETAT, (2) VALEUR		*/

#define I_etat_r_bouton		0
#define I_val_r_bouton		1






/*----------------------------------------------
   Definition des check_boutons
 ---------------------------------------------*/


/* Structure de donn‚e */


typedef struct {
		BYTE nb_elem;	/* le nombre d'elements du check bouton */
		BYTE type;	/* type du check_bouton			*/
		BYTE pos_w;	/* position d'‚criture			*/
		BYTE atb_v;	/* m‚mo attribut vid‚o 			*/
		BYTE col_f; 	/* m‚mo couleur fond			*/
		BYTE col_t;	/* m‚mo couleur texte			*/
	       } DESC_C_BOUTON;




#define Nb_data_c_bouton	3	/* (1) ETAT, (2) VALEUR		*/

#define I_etat_c_bouton		0
#define I_val_c_bouton		1





/*----------------------------------------------
   Definition des listes
 ---------------------------------------------*/


/* Structure d'une liste */


typedef struct {
		WORD old_x;     /* pcol initial de la liste		*/
		WORD old_y;	/* plig initial 			*/
		WORD nol;	/* nø de la liste			*/
		LD_INFO info_l; /* info liste				*/
		BYTE fl_aff;	/* flag d'affichage			*/
	       } DESC_LISTE;




#define Nb_data_liste	6	/* (1) ETAT, (2) EL_INIT, (2) EL_SELEC, (N) VALEUR ELEMENT SAISI	*/

#define I_etat_liste	0
#define I_el_init	1
#define I_el_selec	3
#define I_val_liste	5





/*----------------------------------------------
   Definition des saisies
 ---------------------------------------------*/


/* Structure d'une saisie */


typedef struct {
		WORD nof;	/* nø de la fenˆtre de saisie		*/
		WORD size_buff;	/* taille buffer de saisie 		*/
		BYTE atb_v;	/* m‚mo attribut vid‚o 			*/
		BYTE col_f; 	/* m‚mo couleur fond			*/
		BYTE col_t;	/* m‚mo couleur texte			*/
		BYTE fl_aff;	/* flag d'affichage			*/
		BPTR sauve_sais;/* ptr sur copie de saisie dans data_box*/
	       } DESC_SAISIE;





#define Nb_data_saisie	4	/* (1) ETAT, (2) NB CAR SAISIS, (N) VALEUR DE LA SAISIE		*/

#define I_etat_saisie	0
#define I_size_saisie	1
#define I_val_saisie	3


/*----------------------------------------------
   Definition de l'aide
 ---------------------------------------------*/


/* Structure de l'aide */


typedef struct {
		BYTE car_ex;	/* le caractŠre de selection du bouton	*/
		BYTE car_ex_pos;/* position du caractŠre de validation	*/
	       } DESC_AIDE;



/*----------------------------------------------
   Definition des fenetres free
 ---------------------------------------------*/


/* Structure d'une fenetre */


typedef struct {
		WORD old_x;     /* pcol initial de la liste		*/
		WORD old_y;	/* plig initial 			*/
		WORD nof;	/* nø de la liste			*/
	       } DESC_FUN;

#define Nb_data_f_free	1	/* (1) ETAT				*/

#define I_etat_f_free	0



/* Prototypes des fonctions internes */

/*
WORD init_message(WORD, DATA_ELEM *, WORD, WORD, BPTR);
WORD init_bouton(WORD, DATA_ELEM *, WORD, WORD, BPTR, WORD);
WORD init_r_bouton(WORD, stf_desc *, DATA_ELEM *, WORD, WORD, BYTE, BPTR *);
WORD init_c_bouton(WORD, stf_desc *, DATA_ELEM *, WORD, WORD, BYTE, BYTE, BPTR *);
WORD init_liste(WORD, DATA_ELEM *, WORD, WORD, WORD, WORD, WPTR, WORD);
WORD init_saisie(WORD, stf_desc *, DATA_ELEM *, WORD, WORD, WORD, WORD, WORD, WORD);
WORD init_aide(WORD, DATA_ELEM *, WORD, WORD, BPTR);
TYPF calc_retour(DATA_ELEM *, BYTE);
WORD get_bit(WORD, BYTE);
WORD clear_bit(WORD, BYTE);
WORD set_bit(WORD, BYTE);
BYTE li_car();
*/

