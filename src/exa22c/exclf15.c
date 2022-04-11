/*----------------------------------------------------------------------*/
/*									*/
/*		E X E C U T E U R 	A . B . A . L			*/
/*		-------------------------------------			*/
/*									*/
/*		Copyright (c) 1987,1993 Amenesik / Sologic S.A.			*/
/*									*/
/*		Module  :	EXCLF15.C				*/
/*		Date 	:	09/04/1993				*/
/*		Version :	1.4d / 2.1a                		*/
/*									*/
/*----------------------------------------------------------------------*/

#ifndef	_EXCLF15_C
#define	_EXCLF15_C

/*
 *	F _ C L F F ( x )
 *	-----------------
 *	Fonctions Divers rendent des valeurs de type Integer
 *	
 *	IV = COL [ (x) ]	Colonne courante de device x (0 Ecran 1 Impr)
 *	IV = LIN [ (x) ]	Ligne   courante de device x (0 Ecran 1 Impr)
 *	IV = PROCESS		Numero de poste courant
 *	IV = RND [ (x) ]	Nombre aleatoire ( Valeur d'init )
 *	IV = MASK		Masque de controle de saisie courante
 *	IV = CONF ( x )		Element de la configuration
 *	IV = ERRADR		Adresse du dernier erreur apres ON ERROR
 *	IV = RESTORE   		Returns current Data Index for READ=0
 *	IV = EVENTADR		Returns adresse of current Event 
 *	IV = HOTKEY		Returns key which last caused a debranchement
 *	IV = EVENT( x )		Returns event parameter
 */

EXAWORD f_clff(x)
EXAWORD	x;
{
	EXAWORD	desc;
	EXABYTE	c;
	EXAWORD	work1,work2,opr1,opr2,reg1,reg2;


if (((desc = (EXAWORD) *(fdex++)) & 0x0060) == 0x0060 ) { 
	reg1 = (EXAWORD) *(fdex++); 
	worktyp1 = 0; 
	}
else 	{
 	if ( argsetw(((desc & 0x0060) >> 5),0) == SOFTERROR) 
		return(SOFTERROR);
	if (worktyp1 > 1) { 
		err_val = EXER_PARAM; 
		return(SOFTERROR); 
		}
	}

if ( (desc & 0x0010 ) != 0 ) { 	
	if ( argset(((desc &0x0006) >> 1),0,2) == SOFTERROR) 
		return(SOFTERROR);
	switch (worktyp2) {
		case 0 :
		case 1 : break;
		case 2 : workval2 = bcdtoi(workptr2,worklen2); 
			 break;
		case 3 : workval2 = atoi(workptr2,worklen2);
			 break;
		}
	worktyp2 = 1;
	}
else 	workval2 = 0;

/*	Select CLF Function X 	*/
/*	---------------------	*/

switch ( x ) {

	case 0 : /* X% = COL( [Y%] ) */
		 /* ---------------- */
		 workval3 = prndest;
		 if ( workval2 > 0 ) 	
			prndest = workval2;
		 else	prndest = 1;

		/* Check for Printer device and initialise cico interface */
		/* ------------------------------------------------------ */
		if ( prndest > 1 )
			if ( activate_cico_printer( prndest ) == SOFTERROR )
				return( SOFTERROR );

#ifdef	ABALPS
		if ( prndest != 1 )	
			workval1 = x_col();
		else	{
			workval1 = AskInfos(1);
			x_bflush();
			}
#else
		workval1 = x_col();
#endif
		prndest = workval3;
		break;

	case 1 : /* X% = LIN( [Y%] ) */
		 /* ---------------- */
		 workval3 = prndest;

		 if ( workval2 > 0 )
			prndest = workval2;
		 else	prndest = 1;

		/* Check for Printer device and initialise cico interface */
		/* ------------------------------------------------------ */
		if ( prndest > 1 )
			if ( activate_cico_printer( prndest ) == SOFTERROR )
				return( SOFTERROR );

#ifdef	ABALPS
		 if ( prndest != 1 )
			workval1 = x_lin();
		 else	{
			workval1 = AskInfos(2);
			x_bflush();
			}
#else
		workval1 = x_lin();
#endif
		 prndest = workval3;
		 break;

	case 2 : /* X% = PROCESS */
		 /* ------------ */
		 workval1 = x_npos(); 
		 break;

	case 3 : /* X% = RND( [Y%] ) */
		 /* ---------------- */
		 workval1 = x_rand(workval2); 
		 break;

	case 4 : /* X% = MASK */
		 /* --------- */
		 workval1 = askmask;
		 break;

	case 5 : /* X% = CONF( Y% ) */
		 /* --------------- */
		 switch ( workval2 ) {
			case 200 : workval1 = allocated_error_traps();
				   break;
			case 201 : workval1 = get_allocation_tracer();
				   break;
			case 202 : workval1 = get_allocation_counter();
				   break;
			case 203 : workval1 = get_liberation_counter();
				   break;

			case 205 :  
			case 206 :  
			case 207 :  
			case 208 :  
			case 209 :
			case 210 : workval1 = version_component( workval2 - 205 );
				   break;
#ifdef	VERSION_XX
			case 211 :
				if ( ISLOCAL & ISLOCAL3 )
					workval1 = 3;
				else	workval1 = 4;
				break;
#endif
			case 50 : workval1 = diezfic;
				  break;
			case 51 : workval1 = dieztmp;
				  break;
			case 52 : workval1 = diezstk;
				  break;
			case 53 : workval1 = diezlds;
				  break;
			case 54 : workval1 = 64;
				  break;
#ifdef	NO_BUGS
			case 55 : workval1 = (EXAWORD) trad_ver;
				  break;
			case 56 :	workval1 = (EXAWORD) trad_ind; 	break;
			case 57 :	workval1 = (EXAWORD) trad_typ; 	break;
#endif
#ifdef	ABAL21
			case 58 :	workval1 = DiezePageSize; 	break;
			case 59 :	workval1 = DiezeSwapSize; 	break;
			case 60 :	workval1 = DiezeEtendu;   	break;
			case 61 :	workval1 = extended_page_counter(); break;
			case 62 :	workval1 = loaded_procedures();     break;
			case 5 :	workval1 = NationalLanguage;
					break;
#endif
			/* ------------------------------------ */
			/* ABAL WINDOWS : WINCICO		*/
			/* ------------------------------------ */
			/* CONF(64) : MAIN WINDOW HANDLE 	*/
			/* CONF(65) : EXA INSTANCE HANDLE	*/
			/* ------------------------------------ */

			case 6 :
			case 7 :	workval1 = (conf(workval2) - ((EXAWORD) '0'));
					break;
			case 15 :	workval1 = OS_ID; 
					break;

#ifdef	ABAL14
			/* Mask des Attributs et Couleurs courantes 	*/
			/* ---------------------------------------- 	*/

			/*	Current Screen atribut			*/
			/* 	----------------------			*/
			case 16 :	workval1 = (AtbContext | 0x4000); 
					break;

			/*	Current Forground Colour		*/
			/* 	------------------------		*/
			case 17 :	workval1 = LastFore;
					break;

			/*	Current Background Colour		*/
			/* 	-------------------------		*/
			case 18 :	workval1 = LastBack;
					break;

			/*	Current Ask Atribut			*/
			/* 	-------------------			*/
			case 19 :	workval1 = askatrib;
					break;

			/*	Current Ask ForGround Colour		*/
			/* 	----------------------------		*/
			case 20 :	workval1 = ((askcolour & 0x0F00) >> 8);
					break;

			/*	Current Ask BackGround Colour		*/
			/* 	-----------------------------		*/
			case 21 :	workval1 = (askcolour & 0x000F);
					break;

			/* 	Executer Version ( * 10 )		*/
			/*	-------------------------		*/
			case 22 :	workval1 = 21;
					break;

			/* 	IS ON ERROR GOTO ?			*/
			/*	------------------			*/
			case 23 :	workval1 = error_trapping_status();
					break; 
			/* Code Block Type */
			/* --------------- */
			case 24 :
				workval1 = ( sicico & ONSEM_PRC ? 1 : 0 );
				break;

			/* Segment Identity */
			/* ---------------- */
			case 25 :
				workval1 = cur_seg;
				break;

			/* Procedure Identity */
			/* ------------------ */
			case 26 :
				workval1 = ( sicico & ONSEM_PRC ? procid : MOINS_UN );
				break;
#ifdef ABAL21
			/* Numero d'ASSIGN du dernier operation NGF */
			/* ---------------------------------------- */
			case 27 : workval1 = LastHandle; break;
#endif
#endif

			case 1  :
#ifdef	ABALPS
					workval1 = AskInfos(4); 
					x_bflush();
					break;
#endif
			case 2  :
#ifdef	ABALPS
					workval1 = AskInfos(3);
					x_bflush();
					break;
#endif
			default :
#ifdef	ABAL21
					if ( workval2 >= 100 )
						workval1 = get_event_parameter((workval2-100));
					else	
#endif
						workval1 = conf(workval2); 
					break;
			}
		break;

	case 6 : /* X% = ERRADR */
		 /* ----------- */
		 if (( sicico & ONSEM_ERR )
		 &&  ( GlobalErrorTrap != (ERRORPTR) 0))	
			workval1 = (BINAIRE) GlobalErrorTrap->err_adr;
		 else 	workval1 = LastErreur;
		 break;

	case 7 : /* X% = RESTORE */
		 /* ------------ */
		 workval1 = (BINAIRE) datadex; break;

#ifdef	ABAL14

	case 8 : /* X% = EVENTADR */
		 /* ------------- */
		 if ((timersem & EVENT_ACTIF) != 0 )
			workval1 = ip_hold [ (ip_next - 1) ]; 
		 else	workval1 = 0xFFFF;
	 	 break;

	case 9 : /* X% = HOTKEY  */
		 /* ------------  */
		 workval1 = LastJumpKey;
		 break;
#endif

#ifdef	ABAL21
	case 11: /* X% = procedure_callers( procid ) */
		workval1 = procedure_callers( workval2 );
		break;

	case 12: /* X% = procedure_loaded( procid )  */
		workval1 = procedure_loaded( workval2 );
		break;

	case 10: /* X% = EVENT( ID ) */
		 /* ---------------- */
		workval1 = get_event_parameter( workval2 );

		/* Check for EVENT SPAWN */
		/* --------------------- */
		if ( workval2 == 10 ) {
			switch ( workval1 ) {
				case 0 		: return( GOODRESULT );
				case -1       	: break;
				default         :
					if (( desc & 0x0060) == 0x0060 ) { 
						freg [reg1] = (EXAWORD) workval1;
						xreg [reg1] = 0;
						}
					else 	{
					 	switch ( worktyp1 ) {
							case 0 : *((CPTR) workptr1) = (char) (workval1 & 0x00FF); break;
							case 1 : balputw(((EXAWORD) workval1),workptr1); break;
							}
						} 
#ifdef	PROLOGUE
					abandon_quantum();
					return( GOODRESULT );
#endif
				}
			}
		break;
#endif
		 
	default: return(SOFTERROR);

	}
if (( desc & 0x0060) == 0x0060 ) { 
	freg [reg1] = (EXAWORD) workval1;
	xreg [reg1] = 0;
	}
else 	{
 	switch ( worktyp1 ) {
		case 0 : *((CPTR) workptr1) = (char) (workval1 & 0x00FF); break;
		case 1 : balputw(((EXAWORD) workval1),workptr1); break;
		}
	} 
	return(1);
}

	/* ---------- */
#endif	/* _EXCLF15_C */
	/* ---------- */
