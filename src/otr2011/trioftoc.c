#ifndef	_TRIOFTOC_C
#define	_TRIOFTOC_C

#include "trioftoc.h"


PRIVATE	WORD	iof_FIO_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
	rtl_void_statement( _RTL_IOF_FIO );
	return(i);
}

PRIVATE	WORD	iof_HOT_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{

	return(i);
}

 
PRIVATE	WORD	iof_TABC_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_TABC, tcode, i ) );
#else
	return(0);
#endif
}


PRIVATE	WORD	iof_ATB_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_ATB, tcode, i ) );
#else
	return(0);
#endif
}

	
PRIVATE	WORD	iof_PRN_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_typed_statement( _RTL_IOF_PRN, tcode, i ) );
#else
	return(0);
#endif
}

	
PRIVATE	WORD	iof_TABV_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_TABV, tcode, i ) );
#else
	return(0);
#endif
}


PRIVATE	WORD	iof_FMT_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_FMT, tcode, i ) );
#else
	return(0);
#endif
}


PRIVATE	WORD	iof_DEV_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_DEV, tcode, i ) );
#else
	return(0);
#endif
}


PRIVATE	WORD	iof_BACK_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_BACK, tcode, i ) );
#else
	return(0);
#endif
}


PRIVATE	WORD	iof_CLEAR_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	rtl_void_statement( _RTL_IOF_CLEAR );
#endif
	return(i);
}


PRIVATE	WORD	iof_HOME_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	rtl_void_statement( _RTL_IOF_HOME );
#endif
	return(i);
}

PRIVATE	WORD	iof_BELL_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	rtl_void_statement( _RTL_IOF_BELL );
#endif
	return(i);
}
 	
PRIVATE	WORD	iof_FORE_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_FORE, tcode, i ) );
#else
	return(0);
#endif
}

	
PRIVATE	WORD	iof_TABL_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_TABL, tcode, i ) );
#else
	return(0);
#endif
}

	
PRIVATE	WORD	iof_ASK_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{
#ifdef	WITH_ATOC
	return( atoc_statement( _RTL_IOF_ASK, tcode, i ) );
#else
	return(0);
#endif
}

		
PRIVATE	WORD	iof_GSBX_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{

	return(i);
}

	
PRIVATE	WORD	iof_HOTX_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{

	return(i);
}

	
PRIVATE	WORD	iof_GSBH_to_c( tcode, i )
	WORD	tcode;
	WORD	i;
{

	return(i);
}

PRIVATE	WORD	iof_to_c( i )
	WORD	i;
{
	WORD	tcode;

	rtl_void_statement( _RTL_IOF_START );

	while (1) {

		switch ((tcode = GetTcodeByte( i++ )) & 0x000F) {
			case	_iof_FIO   : /* 0x0000 */
				i = iof_FIO_to_c(tcode,i);
				break;

			case	_iof_HOT   : /* 0x0001 */
				if ((i = iof_HOT_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_TABC  : /* 0x0002 */
				if ((i = iof_TABC_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_ATB   : /* 0x0003 */
				if ((i = iof_ATB_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_PRN   : /* 0x0004 */
				if ((i = iof_PRN_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_TABV  : /* 0x0005 */
				if ((i = iof_TABV_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_FMT   : /* 0x0006 */
				if ((i = iof_FMT_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_DEV   : /* 0x0007 */
				if ((i = iof_DEV_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_BACK  : /* 0x0008 */
				if ((i = iof_BACK_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_CLEAR : /* 0x0009 */
				if ((i = iof_CLEAR_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_HOME  : /* 0x0029 */
				if ((i = iof_HOME_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_BELL  : /* 0x0049 */
				if ((i = iof_BELL_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_FORE  : /* 0x000A */
				if ((i = iof_FORE_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_TABL  : /* 0x000B */
				if ((i = iof_TABL_to_c(tcode,i)) != 0)
					continue;
				else	break;
			case	_iof_ASK   : /* 0x000C */
				if ((i = iof_ASK_to_c(tcode,i)) != 0)
					break;
				else	return(i);

			case	_iof_GSBX  : /* 0x000D */
				if ((i = iof_GSBX_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_HOTX  : /* 0x000E */
				if ((i = iof_HOTX_to_c(tcode,i)) != 0)
					continue;
				else	break;

			case	_iof_GSBH  : /* 0x000F */
				if ((i = iof_GSBH_to_c(tcode,i)) != 0)
					continue;
				else	break;
			}
		break;
		}
	return(i);
}

#endif	/* _TRIOFTOC_C */
	/* ----------- */

