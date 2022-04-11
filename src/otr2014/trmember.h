#ifndef	_TRMEMBER_H
#define _TRMEMBER_H

#define	_MEMBER_SPECIAL	0xFFFC
#define	_MEMBER_ACCESS  0x0007

#define	_MEMBER_PRIVATE		0x0001	/* Marks private members 	*/
#define	_MEMBER_PUBLIC 		0x0002	/* Marks public  members 	*/
#define	_MEMBER_DYNAMIC		0x0004	/* Marks dynamic ! static	*/
#define	_MEMBER_PROTECT		0x0008	/* Marks protected members	*/

#define	_MEMBER_COMMON		0x0010	/* Marks common members		*/
#define	_MEMBER_EXTERN		0x0020	/* Marks extern members		*/
#define	_MEMBER_INDIRECT 	0x0040	/* Marks indirect members	*/
#define	_MEMBER_OVERLOAD 	0x0080	/* Marks overload indirect base	*/

#define	_MEMBER_OVERLAY  	0x0100	/* Marks overlay members	*/
#define	_MEMBER_VIRTUAL	 	0x0200	/* Marks overloadable members	*/
#define	_MEMBER_GENERIC _MEMBER_VIRTUAL /* Marks overloadable members	*/
#define	_MEMBER_DELAYED		0x0400	/* Marks delayed Inherit 	*/
#define	_MEMBER_OCX    		0x0800	/* Marks OCX Status      	*/
#define	_MEMBER_INHERIT		0x1000	/* Marks static inheritance	*/

#define	_MEMBER_APL		0x1FFF	/* Keeps valid access field	*/

#define	_MEMBER_LIBRARY		0x2000	/* Class loaded from APL	*/

#define	_MEMBER_LOCAL		0x4000	/* Local Common Flag		*/

/*	-----------		------------	------		*/	
/*	class->lock	and	member->lock	fields		*/
/*	-----------		------------	------		*/	

#define	_MEMBER_SIZED		0x0001	/* Marks sized member		*/
#define	_MEMBER_LOCKED		0x8000	/* Marks locked member		*/

#endif	/* _TRMEMBER_H */
	/* ----------- */


