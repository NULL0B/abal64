/********************************************************
* Services Fenetres - Gestion des touches d'echappement	*
*-------------------------------------------------------*
* Source : sftch.c                  			*
*-------------------------------------------------------*
* Version : 1.1b                    			*
* Mise a jour le : 14/04/92 EDS (CERVIX)		*
*							*
*********************************************************
* Fonctions                         			*
*                                   			*
* - sfset_tch_esc Positionnement des touches.		*
* - sffind_tch    Recherche touche     			*
*							*
********************************************************/


#include "sfundef.h"



#define NO_TCH		0		/* l'absence de touche		*/



static BYTE tab_tch_esc[NB_MAX_TCH_ESC];       /* le tableau des touches 	*/

static BYTE nb_tch_esc = 0;






/************************************************
*
* POSITIONNEMENT DES TOUCHES D'ECHAPPEMENT
*
*
* Input
*
*   nb    : nb de touches
*   l_tch : liste des touches d'echappement
*
*
* Output
*
*   0 ou code erreur de descripteur
*
*************************************************/

TYPF sfset_tch_esc(BYTE nb, BPTR l_tch)
{

  BYTE i;			/* variable de boucle		*/


  /* controle du nombre de touches */
  if(nb > NB_MAX_TCH_ESC)
    return(werr_desc);

  /* initialisation du tableau */
  for(i = 0; i < nb; i++)
    tab_tch_esc[i] = l_tch[i];

  nb_tch_esc = nb;

  return(OK);
}






/************************************************
*
* TESTE LA PRESENCE D'UNE TOUCHE D'ECHAPPEMENT
* EN RETOURNANT LA TOUCHE SI TROUVEE
*
* Input
*
*   tch : touche d'echappement
*
* Output
*
*   0 ou tch
*
*************************************************/

TYPF sffind_tch(BYTE tch)
{

  BYTE i;			/* variable de boucle		*/


  /* recxherche dans le tableau */
  for(i = 0; i < nb_tch_esc; i++)
    if(tch == tab_tch_esc[i])
      return(i+1);

  return(NO_TCH);

}





