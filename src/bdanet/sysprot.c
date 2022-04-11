/************************************************************************
;			Fonction AskJetonUseIT				;
;-----------------------------------------------------------------------;
; FNT_LOC ULONG AskJetonUseIT(Jeton,AdressIP,MACAdress,NumPoste)	;
; BYTE  SPTR Jeton - vaut 1 en retour si jeton demande			;
; CPTR AdressIP		- Adresse IP du client				;
; CPTR MACAdress	- Mac Adress du client				;
; WORD NumPoste		- Numero de poste du client			;
;									;
;	Cette fonction se connecte a la protection Use IT et demande un	;
; jeton d'acces pour le prochain fils. Elle retourne 0 si OK, le code	;
; erreur sinon.								;
;									;
************************************************************************/
FNT_LOC ULONG AskJetonUseIT(Jeton, AdressIP, MACAdress, NumPoste)
	BYTE  SPTR Jeton;
	CPTR AdressIP;
	CPTR MACAdress;
	WORD NumPoste;
{
	int socketProt = -1;
	BYTE  cpt = 0;
	int RetourProt;
	ULONG errConn = 0;
	ushort nbAcces = 1;
	ULONG ErrProt = 0;

	if (!Testprot) {
		/* on ne doit pas tester la protection */
		Jeton = 0;
		return((ULONG)errConn);
		}


	if (AskTermsys(AdressIP, MACAdress, NumPoste)) {
		/* Poste non present, il faut demander un jeton			*/
		/* On se connecte tout d'abord a la protection 			*/
		/* Il se peut que l'on soit plusieurs a se connecter, il faut	*/
		/* donc attendre son tour					*/
		while ( (cpt < MAX_CONN_PROT) && (socketProt == -1)) {
			socketProt = protConnect();
			if (socketProt == ERR) {
				/* Connexion non etablie */
				if ( (errno == EISCONN)	|| (errno == ECONNREFUSED)) {
					/* Quelqu'un est deja connecte */
					xabqt((HCRIENV)0);
					cpt++;
					}
				else	{
					cpt = MAX_CONN_PROT;
					errConn = 221;
					}
				}
			}

		if (socketProt == -1) {
			/* Connexion refusee */
			return((ULONG)221);
			}

		/* Ici on a pu passer, on demande effectivement le jeton	*/
		if ((RetourProt = protLoadPgm((ushort)CODE_USEIT, (CPTR)VersionProtection, (ushort *)&nbAcces, (pid_t)getpid(), (int *)&ErrProt)) != REQ_OK) {
			errConn = 221;
			}
		else	{
			*Jeton = 1;
			}

		if (nbAcces != NB_ACCES) {
			errConn = 221;
			}
		
		/* Demande du nombre d'acces restants */
		if (protAccessNumber(CODE_USEIT, VersionProtection, &nbAcces, (int *)&ErrProt) == REQ_OK) {
			NbAccesRestants = nbAcces;
			}
		
		/* On se deconnecte du service 	*/
		if (protDisconnect() != OK) {
			errConn = 221;
			}
		}
	else 	{
		/* il ne faut pas demander de jeton */
		*Jeton = 0;
		}

	return((ULONG)errConn);
}

/************************************************************************
;			Fonction AskTermsys				;
;-----------------------------------------------------------------------;
; FNT_LOC BYTE  AskTermsys(AdressIP, MACAdress, NumPoste)			;
; CPTR AdressIP		- Adresse IP du client				;
; CPTR MACAdress	- Mac Adress du client				;
; WORD NumPoste		- Numero de poste du client			;
;									;
;	Cette fonction execute une demande vers Termsys pour savoir si	;
; le poste est deja connecte par Termsys.				;
; Retourne 1 s'il faut demander un jeton, 0 sinon.			;
;									;
************************************************************************/
#ifdef USEIT
FNT_LOC BYTE  AskTermsys(AdressIP, MACAdress, NumPoste)
	CPTR AdressIP;
	CPTR MACAdress;
	WORD NumPoste;

{
	BYTE 	commande[200];
	int 	retour;

	xmemset((CPTR)commande, 0x00, sizeof(commande));
	
	sprintf(commande, "/usr/prologue/bin/tsstate --findterm --tadr %u.%u.%u.%u --tmac %02X%02X%02X%02X%02X%02X --tpost %u >/dev/null 2>&1",
	    (BYTE)AdressIP[0], (BYTE)AdressIP[1], (BYTE)AdressIP[2], (BYTE)AdressIP[3],
	    (BYTE)MACAdress[0], (BYTE)MACAdress[1], (BYTE)MACAdress[2], (BYTE)MACAdress[3], 
	    (BYTE)MACAdress[4], (BYTE)MACAdress[5], NumPoste);
	
	/* Execution de la commande */
	if (!( retour = system(commande))) {
		/* Pas de jeton a prendre */
		return((BYTE )0);
		}
	else	{
		/* Il faut prendre un jeton */
		return((BYTE )1);
		}


}
#endif

************************************************************************
;			Fonction LibJetonUseIT				;
;-----------------------------------------------------------------------;
; FNT_LOC ULONG LibJetonUseIT(Jeton)					;	
; BYTE  SPTR Jeton		- vaut 1 si le jeton Use It doit être libere	;
;			remis a zero si OK				;
;									;
;	Cette fonction se connecte a la protection Use IT et libere un	;
; jeton d'acces pour le fils qui se deconnecte. Elle retourne 0 si OK,  ;
; le code erreur sinon.							;
;									;
************************************************************************/
FNT_LOC ULONG LibJetonUseIT(Jeton)
	BYTE  SPTR Jeton;
{

	int socketProt = -1;
	BYTE  cpt = 0;
	ULONG errConn = 0;
	ushort nbAcces = 1;
	ULONG ErrProt = 0;
	int RetourProt = 0;	

	if (*Jeton != 1)
		return(0);

	/* On se connecte tout d'abord a la protection 	*/
	/* Il se peut que l'on soit plusieurs a se connecter, il faut	*/
	/* donc attendre son tour					*/
	while ( (cpt < MAX_CONN_PROT) && (socketProt == -1)) {
		socketProt = protConnect();
		if (socketProt == ERR) {
			/* Connexion non etablie */
			if ( (errno == EISCONN)	|| (errno == ECONNREFUSED)) {
				/* Quelqu'un est deja connecte */
				xabqt((HCRIENV)0);
				cpt++;
				}
			else	{
				cpt = MAX_CONN_PROT;
				errConn = 221;
				}
			}
		}
	if (socketProt == -1) {
		/* Connexion refusee */
		return((ULONG)221);
		}

	/* Ici on a pu passer, on libere effectivement le jeton	*/
	if ( (RetourProt = protUnloadPgm((ushort)CODE_USEIT, (CPTR)VersionProtection, (ushort *)&nbAcces, (pid_t)getpid(), (int *)&ErrProt)) != REQ_OK) {
		errConn = 221;
		}
	else	{
		*Jeton = 0;
		}

	/* On se deconnecte du service 	*/
	if (protDisconnect() != OK) {
		errConn = 221;
		}

	return((ULONG)errConn);
}



