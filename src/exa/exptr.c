#ifndef	_exptr_c
#define	_exptr_c

#include "exptr.h"

#ifdef  ABAL64
/*      --------------------------------------  */
/*              ABAL INDEXED POINTERS           */
/*      --------------------------------------  */
/*      The ABAL PTR variable has storage for   */
/*      only 4 bytes of PTR data so pointers    */
/*      greater than 4 bytes must be indexed    */
/*      --------------------------------------  */
#define         MAXABALPTR 4096

EXAWORD         NewAbalPointer=0;
EXAWORD         MaxAbalPointer=MAXABALPTR;
VPTR *          MemAbalPointer=(VPTR *) 0;

EXAWORD	TcodeWord(BPTR TcW)
{
	switch ( WORDSIZE )
	{
	case	WORD16SIZE 	: return(TcodeWord16(TcW));
	case	WORD32SIZE 	: return(TcodeWord32(TcW));
	default			: return(TcodeWord64(TcW));
	}
}

/*      ----------------------- */
/*      AllocateIndexedPointers */
/*      ----------------------- */
VOID    AllocateIndexedPointers()
{
        NewAbalPointer = 0;
        MemAbalPointer = allocate(  sizeof(BPTR) * MaxAbalPointer);
        memset( (VPTR) MemAbalPointer, 0, sizeof(BPTR) * MaxAbalPointer);
        return;
}

/*      ----------------------  */
/*      ReleaseIndexedPointers  */
/*      ----------------------  */
VOID    ReleaseIndexedPointers()
{
        NewAbalPointer = 0;
        if ( MemAbalPointer )
                liberate( MemAbalPointer );
        MemAbalPointer = (VPTR *) 0;
        return;
}

/*      -----------------       */
/*      SetIndexedPointer       */
/*      -----------------       */
EXAWORD SetIndexedPointer(VPTR value)
{
        if (!( value ))
                return(0);
        else if (!( MemAbalPointer ))
                return(0);

        if ( NewAbalPointer >= MaxAbalPointer )
                NewAbalPointer = 0;

        do
        {
                if (!( MemAbalPointer[NewAbalPointer] ))
                        break;
                else    NewAbalPointer++;
        }
        while ( NewAbalPointer < MaxAbalPointer );

        if ( NewAbalPointer >= MaxAbalPointer )
                return( 0 );

        else
        {
                MemAbalPointer[NewAbalPointer++] = value;
                printf("SetIndexPointer[%llu] = %016x\r\n",NewAbalPointer,value);
                return(NewAbalPointer);
        }
}

/*      -----------------       */
/*      RazIndexedPointer       */
/*      -----------------       */
VOID    RazIndexedPointer(EXAWORD value)
{
        if (( value ) && ( MemAbalPointer ) && ( value <= MaxAbalPointer ))
        {
                printf("RazIndexPointer[%llu] = %016x\r\n",value, MemAbalPointer[value-1]);
                MemAbalPointer[(NewAbalPointer=(value-1))] = 0;
        }
        return;
}

/*      -----------------       */
/*      RazIndexedAddress       */
/*      -----------------       */
VOID    RazIndexedAddress(VPTR vptr)
{
        EXAWORD i;
        if (( vptr ) && ( MemAbalPointer ))
        {
                for ( i=0; i < MaxAbalPointer; i++ )
                {
                        if ( MemAbalPointer[i] == vptr )
                        {
                                printf("RazIndexPointer[%llu] = %016x\r\n",i+1,vptr);
                                MemAbalPointer[(NewAbalPointer=i)] = (VPTR) 0;
                                break;
                        }
                }
        }
        return;
}

/*      -----------------       */
/*      GetIndexedPointer       */
/*      -----------------       */
VPTR    GetIndexedPointer(ULONG value)
{
        if (( value ) && ( MemAbalPointer ) && ( value <= MaxAbalPointer ))
        {
                printf("GetIndexPointer[%llu] = %016x\r\n",value,MemAbalPointer[value-1]);
                return( MemAbalPointer[value-1] );
        }
        else    return((VPTR) 0);
}

/*      --------------------------------------  */
/*       END of ABAL INDEXED POINTER HANDLER    */
/*      --------------------------------------  */
#endif

/*      -----------------       */
/*       TcodePutPointer        */
/*      -----------------       */
VOID    TcodePutPointer( dptr , vptr )
BPTR    dptr;
BPTR    vptr;
{
        ULONG   dbyte;
        dptr++;
        dbyte   = (ULONG) vptr;
#ifdef  IDIRECT
#ifndef AIX
        memcpy((BPTR) dptr , (BPTR) & dbyte, (PTRSIZE-1) );
#else
        *(dptr++) = (EXABYTE) (dbyte & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >> 8) & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >>16) & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >> 24) & 0x00FF);
#ifdef  ABAL64
	if ( PTRSIZE > 5 )
	{
       		*(dptr++) = (EXABYTE) ((dbyte >> 32) & 0x00FF);
       		*(dptr++) = (EXABYTE) ((dbyte >> 40) & 0x00FF);
       		*(dptr++) = (EXABYTE) ((dbyte >> 48) & 0x00FF);
       		*(dptr++) = (EXABYTE) ((dbyte >> 56) & 0x00FF);
	}
#endif
#endif
#else
        *(dptr++) = (EXABYTE) (dbyte & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >> 8) & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >>16) & 0x00FF);
        *(dptr++) = (EXABYTE) ((dbyte >> 24) & 0x00FF);
#ifdef  ABAL64
	if ( PTRSIZE > 5 )
	{
        	*(dptr++) = (EXABYTE) ((dbyte >> 32) & 0x00FF);
        	*(dptr++) = (EXABYTE) ((dbyte >> 40) & 0x00FF);
        	*(dptr++) = (EXABYTE) ((dbyte >> 48) & 0x00FF);
        	*(dptr++) = (EXABYTE) ((dbyte >> 56) & 0x00FF);
	}
#endif
#endif
        return;
}

/*      -----------------       */
/*       TcodeRazPointer        */
/*      -----------------       */
VOID    TcodeRazPointer( descptr )
BPTR    descptr;
{
        raz_pointer_variable( descptr );
}

/*      -----------------       */
/*       TcodeGetPointer        */
/*      -----------------       */
BPTR    TcodeGetPointer( descptr )
BPTR    descptr;
{
#ifdef  VERSION666
        descptr++;
#ifdef  ABAL64
        if ( PTRSIZE < ABALPTRSIZE )
	{
        	ULONG   result32 = TcodeWord32( descptr );
                return( GetIndexedPointer(result32) );
	}
        else
	{
	    return((BPTR) (TcodeWord64( descptr )) );
	}
#else
        return((BPTR) (TcodeWord32( descptr )));
#endif
        ULONG   dbyte;
        descptr++;
        dbyte = ((ULONG) Tcodeword((descptr + WORDSIZE)) ) << 16;
        dbyte += (ULONG) Tcodeword(descptr);
        return((BPTR) dbyte );
#endif
}

/*	---------------------	*/
/*	reset_event_procedure	*/
/*	---------------------	*/
VOID    reset_event_procedure()
{
        HardEvent = 0;
        timersem &= ~EVENT_FLAG;
        memset( eventproc, 0, PTRSIZE );
        return;
}

/*	---------------------	*/
/*	reset_timer_procedure	*/
/*	---------------------	*/
VOID    reset_timer_procedure()
{
        memset( timerproc, 0, PTRSIZE );
        return;
}


#endif	/* _exptr_c */
	/* -------- */

