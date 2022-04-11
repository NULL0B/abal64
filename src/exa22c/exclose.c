#ifndef	_EXCLOSE_C
#define	_EXCLOSE_C

/*
 *	S F _ C L O S E ()
 *	-------------------------------
 *	General Device / File closing routines
 *
 *	renvoie 0 si OK, -1 sinon, errno positionnee
 */

EXAWORD	sf_close()
{
	EXAWORD	holdtrap;
	EXAWORD ret_cod;
		

	if ( fidreel == EX_UNUSED_HANDLE ) 
		return(0);

	switch( fidperm & NGF_TYP ) {

#ifdef PROLOGUE
		case NGF_GR	:
			/* Attempt low level file close then Exit */
			/* -------------------------------------- */
			ret_cod=close(fidreel);
			break;
#endif	/* PROLOGUE	*/

		case NGF_IM   :
			if ( fidreel != EX_UNUSED_HANDLE ) {
				err_val = Establish_Printer();
				holdtrap = sicico; 
				sicico |= ONSEM_TRP;
#ifdef	PROLOGUE
				(VOID)  printer_close(fidreel);
#else
				(VOID)  im_close((EXAWORD)fidreel);
#endif
				sicico = holdtrap;
				fidreel = EX_UNUSED_HANDLE;
				prnfid  = EX_UNUSED_HANDLE;
#ifdef AIX_VERS
#ifdef SPARC
				prndex  = 0; fidmc1  = 0;
#else
				prndex  = 0; fidmc  = 0;
#endif
#else  /* AIX_VERS */
				prndex  = 0; fidmc  = 0;
#endif /* AIX_VERS */
				ret_cod=0; errno=0;
				prndest = 1;
				}
			else	{ 
				fidreel = EX_UNUSED_HANDLE;
				prnfid  = EX_UNUSED_HANDLE;
#ifdef AIX_VERS
#ifdef SPARC
				prndex  = 0; fidmc1  = 0;
#else
				prndex  = 0; fidmc  = 0;
#endif
#else  /* AIX_VERS */
				prndex  = 0; fidmc  = 0;
#endif /* AIX_VERS */
				}
#ifdef UNIX
			liberlox(fidname);
#endif
			break;
		case NGF_DV   :
/*==========================================================================*/
#ifndef UNIX
#ifndef	VMS
			/* =============================================== */
			/* VIRTUAL VARIABLES DEVICE LIBERATION CHECK 	   */
			/* =============================================== */
			/* Since Neither VMS nor UNIX have specialised     */
			/* Device access functions this check needs only   */
			/* to be performed for Amenesik / Sologic and Dos Versions   */
			/* =============================================== */
			/* Check for External Variable Device to be Closed */
			/* ----------------------------------------------- */
			if ( fidperm & ASS_VIRT_VALID )

				/* Perform Liberate precautions */
				/* ---------------------------- */
				VmemLiberate();
			/* No Errors and Exit */
			/* ------------------ */
			ret_cod=0;
			break;
#endif
#endif
/* sinon, idem IO	*/
		case NGF_IO   :

			/* ============================================= */
			/* VIRTUAL VARIABLES FILE : LIBERATION CHECK 	 */
			/* ============================================= */
			/* Check for External Variable File to be Closed */
			/* --------------------------------------------- */
			if ( fidperm & ASS_VIRT_VALID )

				/* Perform Liberate precautions */
				/* ---------------------------- */
				VmemLiberate();

			/* Attempt low level file close then Exit */
			/* -------------------------------------- */
			if (errno=(int)EeEad_close(fidreel))
				ret_cod=MOINS_UN;
			else	ret_cod=0;
			break;

		case NGF_SQ   :	
			if (errno=(int)EeEsq_close(fidreel))
				ret_cod=MOINS_UN;
			else	ret_cod=0;
			break;

		case NGF_SI   : 
		case NGF_MC   : 
				simcprep(_NGF_CLOSE);
				if (errno=(int)aig_cri())
					ret_cod=MOINS_UN;
				else	ret_cod=0;
				break;
		case NGF_MCBD :	
				basefile(0);
				remove_bd_record(fidbd,lfh);
				simcprep(_NGF_CLOSE);
				if (errno=(int)aig_cri())
					ret_cod=MOINS_UN;
				else	ret_cod=0;
				break;
		case NGF_BD   : 
				close_base_files( lfh );
				simcprep(_NGF_CLOSE);
				if (errno=(int)aig_cri())
					ret_cod=MOINS_UN;
				else	ret_cod=0;
				break;

/*==========================================================================*/
		default	    : 
				errno=EXER_FUNCWOT; ret_cod=MOINS_UN; break;
		}
	return(ret_cod);
}

#endif	/* _EXCLOSE_C */
	/* ---------- */



