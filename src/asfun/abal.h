
#ifndef	_abal_h
#define	_abal_h

/*	This file provides the definitions required for access to ABAL Variable Types	*/
/*	-----------------------------------------------------------------------------	*/



#define	GetAbalWord( p ) ( (( *((BYTE *)(p)) & 0x00FF) << 8 ) | ( *((BYTE*)(p)+1) & 0x00FF ))
#define	GetAbalLong( p ) ( (( *((BYTE *)(p)) & 0x00FF) << 24) | (( *((BYTE*)(p)+1) & 0x00FF ) << 16) | (( *((BYTE*)(p)+2) & 0x00FF ) << 8) | ( *((BYTE*)(p)+3) & 0x00FF ) )
#define	GetAbalByte( p ) *(((BYTE *)(p)))

#define	GetParaByte( p ) ( rt_arg.t[p] == 1 ? GetAbalWord(rt_arg.v[p]) : GetAbalByte( rt_arg.v[p] ) )

#define	PutAbalLong( p, v ) *(((BYTE *)(p))+3) = (v & 0x00FF),*(((BYTE *)(p))+2) = ((v >> 8) & 0x00FF),*(((BYTE *)(p))+1) = ((v >> 16) & 0x00FF),*((BYTE *) (p))    = ((v >> 24) & 0x00FF);
#define	PutAbalWord( p, v ) *(((BYTE *)(p))+1) = (v & 0x00FF),*((BYTE *) (p)) = ((v >> 8) & 0x00FF);
#define PutAbalByte( p, v ) *(((BYTE *)(p))+1) = (v & 0x00FF);


#endif	/* _abal_h */
	/* ------- */


	
 
	

