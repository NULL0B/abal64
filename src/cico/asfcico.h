/*
 *	ASFCICO - Interface ECRAN / CLAVIER / IMPRIMANTE
 *	------------------------------------------------
 *
 *	Copyright (c) 1993 Amenesik / Sologic s.a.
 *
 *	asfcico.h - redefinition du nom de toutes les fcts et vars globales
 *	de ixcico.c
 *
 *	$Header: /home/Produits/Abal3/cico/asfcico.h,v 1.1.1.1 2003/11/04 23:40:46 root Exp $
 *
 */

/* _cico.h : OK */
/* cico.h  : OK */

#define x_getch		asf_x_getch
#define x_kbhit		asf_x_kbhit
#define prfo		asf_prfo   
#ifdef CPYFO
#define cpyfo		asf_cpyfo		/*CPYFO*/
#endif
#define lcfo		asf_lcfo   
#define x_putch		asf_x_putch
#define x_cprintf	asf_x_cprintf
#define pos    		asf_pos    
#define atb    		asf_atb    
#define backgr 		asf_backgr 
#define foregr 		asf_foregr 
#define x_clear		asf_x_clear
#define x_bell 		asf_x_bell 
#define x_col  		asf_x_col  
#define x_lin  		asf_x_lin  
#define x_bstart	asf_x_bstart
#define x_bflush	asf_x_bflush
#define mima   		asf_mima   
#define conf   		asf_conf   
#define x_npos 		asf_x_npos 
#define im_open		asf_im_open
#define im_close	asf_im_close
#define initerm		asf_initerm
#define finterm		asf_finterm

/* ixcico.h : OK */

#define bda_cico	asf_bda_cico
#define flag_finterm	asf_flag_finterm
#define flag_bios	asf_flag_bios

#define flag_couleur	asf_flag_couleur
#define flag_init 	asf_flag_init
#define flag_curseur 	asf_flag_curseur
#define flag_buf	asf_flag_buf
#define flag_scroll	asf_flag_scroll

#define max_ligne	asf_max_ligne 
#define max_colonne     asf_max_colonne
#define nb_ligne        asf_nb_ligne  
#define nb_colonne      asf_nb_colonne

#define courant		asf_courant

#define flag_second	asf_flag_second
#define flag_cursor	asf_flag_cursor
#define flag_delay	asf_flag_delay


#define redir_CO	asf_redir_CO
#define redir_CI	asf_redir_CI
#define redir_LO	asf_redir_LO

#ifdef CICO_BDA
#define redir		asf_redir
#endif /* fin CICO_BDA */

#define seqinit		asf_seqinit

/* Extern !!! */
#define prndest		asf_prndest
#define prnfid 		asf_prnfid 
#define prnptr 		asf_prnptr 
#define prnleng		asf_prnleng

#define _co			asf_co                     
#define _co_car         	asf_co_car                 
#define _co_conv        	asf_co_conv                
#define _co_pos         	asf_co_pos                 
#define _co_out         	asf_co_out                 
#define _co_attribut    	asf_co_attribut            
#define _co_set_attribut	asf_co_set_attribut        
#define _co_reset_attribut	asf_co_reset_attribut      
#define _co_couleur_fond	asf_co_couleur_fond        
#define _co_couleur_texte	asf_co_couleur_texte       	
#define _co_ins_line    	asf_co_ins_line            
#define _co_del_line    	asf_co_del_line            
#define _co_ins_character	asf_co_ins_character       
#define _co_del_character	asf_co_del_character       
#define _co_clear       	asf_co_clear               
#define _co_clear_eos   	asf_co_clear_eos           
#define _co_clear_eol   	asf_co_clear_eol           
#define _co_cursor      	asf_co_cursor              
#define _co_capacite    	asf_co_capacite            
#define _co_sequence    	asf_co_sequence            
#define _co_scroll      	asf_co_scroll              
#define _co_push        	asf_co_push                
#define _co_pop         	asf_co_pop                 
#define _co_ligne       	asf_co_ligne               
#define _co_colonne     	asf_co_colonne             
#define _co_start       	asf_co_start               
#define _co_flush       	asf_co_flush               
#define _lo             	asf_lo                     
#define modterm			asf_modterm                 	

/* ixcico.c : */
#define XCICO_nbl		asf_XCICO_nbl
#define XCICO_start		asf_XCICO_start

#ifdef CICO_DEBUG
#define DEBUG			asf_DEBUG
#endif /* CICO_DEBUG */

#define _co_chaine		asf_co_chaine
#define x_push			asf_x_push
#define x_pop			asf_x_pop
#define x_redir			asf_x_redir
#define establish_process_number	asf_establish_process_number
/* ---------------- Fin du fichier : asfcico.h ----------------------*/

