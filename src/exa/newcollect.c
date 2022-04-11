EXALONG MC_collect(func,hfic,bptr,blen,mode,pvarid)
EXAWORD 	func;
EX_FILE_HANDLE 	hfic;
BPTR 		bptr;
EXAWORD 	blen;
EXAWORD 	mode;
EXAWORD		pvarid;
{
	BPTR	tptr;
	BPTR	tbuffer;
	EXAWORD tbuflen=0;
	EXAWORD iwidth;
	EXAWORD TypePos;
	EXAWORD FlagUnique;
	EXAWORD FlagSeq;
	EXALONG Count=0;
	EXALONG CountTotal;
	EXALONG CountRemain;

	if (!( iwidth = fidinfo2 )) {
		errno = 73;
		return((EXALONG)-1);
		}
	else if (!( tbuffer = allocate((tbuflen = _MAX_COLLECT_BUFFER)))) {
		errno = err_val = 27;
		return((EXALONG) -1);
		}

	/* Determine le type de positionnement : premier/dernier */
	TypePos = (func == 0x22AB) ? 0 : 1;

	/* Puis le type de traitement des doublons */
	FlagUnique = ((mode & 0x0020) == 0) ? 0 : 1;

	/* Puis le type de recherche sequentielle/selective */
	FlagSeq = ((mode & 0x0040) == 0) ? 0 : 1;

	/* Premier appel pour recuperer le nombre de reponses */
	if ((err_val = errno = (int)EeEmc_collect(hfic, bptr, (WORD)blen, (WORD)FlagUnique, (WORD)FlagSeq, 0, (WORD)TypePos, (WORD PTR)&iwidth, tbuffer, (WORD PTR)&tbuflen, (LONG PTR)&Count)) != 0) 
		return((EXALONG)-1);

	CountTotal = Count;
	CountRemain = Count;

	if (!CountTotal)
		return( CountTotal );
	else if (!( iwidth )) {
		errno = 73;
		return((EXALONG) -1);
		}

	/* Allocation d'une zone pointee correspondant à la taille exacte des reponses (pas un multiple de 32k) */
	tptr = allocate_collect_storage((EXAWORD) pvarid ,(EXAWORD)iwidth, (EXAWORD) CountTotal );
	if (!( tptr ))
		return((EXALONG)-1);
	
	/* Copie des premieres reponses */
	memcpy(tptr, tbuffer, tbuflen);
	tptr += tbuflen;

	/* Y a t-il d'autres reponses? */
	if (CountTotal <= (tbuflen/iwidth))
		CountRemain = 0;

	/* Reponses suivantes */
	while (CountRemain) {
		CountRemain -= (tbuflen/iwidth);

		if (CountRemain > (_MAX_COLLECT_BUFFER/iwidth))
			tbuflen = _MAX_COLLECT_BUFFER;
		else
			tbuflen = CountRemain * iwidth;

		if ((errno = (int)EeEmc_collect(hfic, bptr, (WORD)blen, (WORD)FlagUnique, (WORD)FlagSeq, 1, (WORD)TypePos, (WORD PTR)&iwidth, tptr, (WORD PTR)&tbuflen, (LONG PTR)&Count)) != 0) 
			return((EXALONG)-1);

		tptr += tbuflen;
	}

	liberate( tbuffer );					
	return((EXALONG)CountTotal);
}


