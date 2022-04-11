#ifndef	_EXOPEN_C
#define	_EXOPEN_C

/*
 *	S F _ O P E N ( )
 *	-----------------
 *	File or device opening routine (Automatique ! )
 *
 *	renvoie 0 si OK, -1 sinon, errno positionnee (et err_val aussi)
 *
 */

EXAWORD sf_open()
{
	EXAWORD	y;
	EXAWORD	ph;

switch( fidperm & NGF_TYP ) {

#ifdef ABALMSG
	case NGF_CM : /* IPC Message file */
		fidreel = EX_UNUSED_HANDLE; 
		errno=0;
		break;
#endif

	case NGF_IO :
		if (!(fidreel=EeEad_open(fidname,fidperm, (WPTR)&y)))
			{ fidreel=EX_UNUSED_HANDLE; errno=(int)y; }
		else	{ errno=0; }
		break;

	case NGF_SQ :	
		if (!(fidreel=EeEsq_open(fidname,fidperm, (WPTR)&y)))
			{ fidreel=EX_UNUSED_HANDLE; errno=(int)y; }
		else	{ errno=0; }
		break;

	case NGF_SI   :	/* Sequentiel indexe 	*/
	case NGF_MC   :	/* Multicritere		*/
	case NGF_MCBD : /* Data base File	*/
	case NGF_BD   : /* Dictionaire database	*/
		simcprep(_NGF_OPEN);
		errno=(int)aig_cri();
		break;
#ifndef UNIX
#ifndef VMS
#ifdef	PROLOGUE
	case NGF_GR :
		if ((fidreel = open( fidname , fidperm )) == EX_UNUSED_HANDLE)
			traitfilerror(MOINS_UN,errno); 
		break;
#endif
	case NGF_IM :
		if (( fidperm & NGF_P_E ) != 0 ) {
			if ((ph = printer_open( fidname, fidperm )) != MOINS_UN)
				fidreel = (EX_FILE_HANDLE) ph;
			else	fidreel = EX_UNUSED_HANDLE;
			errno = err_val;
			}
		else	{
			fidreel = EX_UNUSED_HANDLE; 
			errno = 56;
			}
		break;
	case NGF_DV :
		fidreel = io_open( fidname );
		break;
#endif /* ! VMS */
#endif /* ! NIX */
#ifndef PROLOGUE
#ifndef DOS
	case NGF_IM :	/* Printer file / Device opening 	*/
			/* -----------------------------	*/
#ifdef RT_AIX
	ph = im_open(fidname,(fidperm | NGF_I_C));
	if (ph == MOINS_UN)
			fidreel = EX_UNUSED_HANDLE;
		else	fidreel = (EX_FILE_HANDLE)ph;
		errno = err_val;
#else
	if ((ph = im_open(fidname,(fidperm | NGF_I_C))) == MOINS_UN)
			fidreel = EX_UNUSED_HANDLE;
		else	fidreel = (EX_FILE_HANDLE)ph;
		errno = err_val;
#endif
		break;
		if ((ph = im_open(fidname,(fidperm | NGF_I_C))) == MOINS_UN)
			fidreel = EX_UNUSED_HANDLE;
		else	fidreel = (EX_FILE_HANDLE)ph;
		errno = err_val;
		break;
	case NGF_DV :	/* Raw device Disk etc opening		*/
			/* ---------------------------		*/

#ifdef VMS
		fidreel = open( fidname , fidperm );
#else
		/* First Check for Access Rights */
		/* ----------------------------- */
		if ( Access(fidname,0,((fidperm & NGF_P_E) ? 1 : 0 )) != 0 ) {
			if ( errno != 44 ) 
				errno = 40;
			fidreel = EX_UNUSED_HANDLE;
			break;
			}

		/* Check first for Differred READ/WRITE only */
		/* ----------------------------------------- */ 
		if ((fidperm & NGF_I_D) != 0 ) {		/* Alors Stream Open */
			if ((fidperm & NGF_R_W) != 0 ) {	/* WRITE ONLY	     */
				fidreel = open ( fidname , O_WRONLY , 0);
				}
			else	fidreel = open ( fidname , O_RDONLY , 0);
			}
		/* Else Classique IO / Acces Direct Methods */
		/* ---------------------------------------- */
		else	{
			if ((( fidperm & NGF_R_W) != 0 ) || (( fidperm & NGF_P_E) != 0 )) 
				y = (O_RDWR | O_BINARY);
			else	y = (XO_RDONLY | O_BINARY);
			if ( ( fidperm & NGF_I_C) == 0 ) 
				y |= O_SYNC;
			fidreel = open( fidname , y , 0 );
			}
		if ( fidreel == EX_UNUSED_HANDLE ) { 
			(VOID) liberlox((BPTR) fidname);
			traitfilerror(MOINS_UN,errno);
			}

#endif	/* VMS	      */

		break;
#endif /* ! PROLOGUE */
#endif /* ! DOS */

	default	    : /* Non Active Options */
			errno   = EXER_FUNCWOT; 
			fidreel = EX_UNUSED_HANDLE;
			break;
	}

if ( fidreel == EX_UNUSED_HANDLE ) 
	return((err_val = errno));
else	return( 0 );
}


#endif	/* _EXOPEN_C */

