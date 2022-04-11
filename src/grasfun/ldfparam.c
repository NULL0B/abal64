#ifndef	_ldfparam_c
#define	_ldfparam_c

private EXAWORD LdfAbalByte(char FAR PTR bptr)
{
	if (!( bptr ))
		return(0);
	else 	return(*bptr);
}

private EXAWORD LdfAbalWord(BYTE FAR PTR wptr)
{
	if (!( wptr ))
		return(0);
	else 	return(((*wptr<< 8) | *(wptr+1)));
}

private EXAWORD LdfAbalLong(BYTE FAR PTR wptr)
{
	if (!( wptr ))
		return(0);
	else	return((((*wptr)<< 24) | (*(wptr+1) << 16)  | (*(wptr+2) << 8)| *(wptr+3)));
}

#define LdfParaLen(n) ( rt_arg.l[n] )
#define LdfParaPtr(n) ( rt_arg.v[n] )
#define LdfValidPara(n) ( n < rt_arg.c )
#define LdfParaWord(n) ( rt_arg.t[n] == 1 ? LdfAbalWord(rt_arg.v[n]) : ( rt_arg.t[n] == 0 ?  LdfAbalByte(rt_arg.v[n]) : LdfAbalLong(rt_arg.v[n])) )
#define LdfParaWord(n) ( rt_arg.t[n] == 1 ? LdfAbalWord(rt_arg.v[n]) : ( rt_arg.t[n] == 0 ?  LdfAbalByte(rt_arg.v[n]) : LdfAbalLong(rt_arg.v[n])) )
#define LdfParaByte(n) ( rt_arg.t[n] == 1 ? (LdfAbalWord(rt_arg.v[n])&0x00FF) : ( rt_arg.t[n] == 0 ?  LdfAbalByte(rt_arg.v[n]) : (LdfAbalLong(rt_arg.v[n])&0x00FF) ) )

#endif	/* _ldfparam_c */
	/* ----------- */

