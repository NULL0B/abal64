BPTR	allocate_collect_storage(EXAWORD,EXAWORD,EXAWORD);
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
	EXAWORD remainder;
	EXALONG	total;
	EXAWORD	iwidth;
	EXAWORD	tbuflen=0;

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

	if ((err_val = errno = (int)EeEmc_collect(hfic,bptr,blen,FlagUnique,FlagSeq,0,TypePos,(WPTR)&iwidth,tbuffer,(WPTR)&tbuflen,(WPTR)&remainder)) != 0) 
		return((EXALONG)-1);
	if (!( total = remainder ))
		return( total );
	else if (!( iwidth )) {
		errno = 73;
		return((EXALONG) -1);
		}
	tptr = allocate_collect_storage((EXAWORD) pvarid ,(EXAWORD)iwidth, (EXAWORD) total );
	if (!( tptr ))
		return((EXALONG)-1);
	else	{
		memcpy( tptr, tbuffer, tbuflen );
		while (1) {
			tptr += tbuflen;
			remainder -= ( tbuflen / iwidth );
			if (!( remainder ))
				break;
			else	tbuflen = _MAX_COLLECT_BUFFER;
			if ((errno = (int)EeEmc_collect(hfic,bptr,blen,FlagUnique,FlagSeq,1,TypePos,(WPTR)&iwidth,tptr,(WPTR)&tbuflen,(WPTR)&remainder)) != 0) 
				return((EXALONG)-1);
			}
		liberate( tbuffer );					
		return((EXALONG)total);
		}

}


