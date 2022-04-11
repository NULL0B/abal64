
#ifndef	_abal_h
#define	_abal_h

/*	This file provides the definitions required for access to ABAL Variable Types	*/
/*	-----------------------------------------------------------------------------	*/



#define	GetAbalWord( p ) ((( *((BYTE *)(p)) & 0x00FF) << 8 ) + ( *((BYTE*)(p)+1) & 0x00FF ))
#define	GetAbalByte( p ) *(((BYTE *)(p)))

#define	GetParaByte( p ) ( rt_arg.t[p] == 1 ? GetAbalWord(rt_arg.v[p]) : GetAbalByte( rt_arg.v[p] ) )
#define	GetParaWord( p ) ( rt_arg.t[p] == 1 ? GetAbalWord(rt_arg.v[p]) : GetAbalByte( rt_arg.v[p] ) )

#define	PutAbalWord( p, v ) *(((BYTE *)(p))+1) = (v & 0x00FF),*((BYTE *) (p)) = ((v >> 8) & 0x00FF);
#define PutAbalByte( p, v ) *(((BYTE *)(p))+1) = (v & 0x00FF);


#endif	/* _abal_h */
	/* ------- */


	
 
	

