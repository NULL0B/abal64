//  ------------------------------------------------------------------
//  Project   Web Navigator/Browser for Amenesik / Sologic / Twin Server
//  ------------------------------------------------------------------
#ifndef _standard_bda_c
#define _standard_bda_c

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

#include <stdio.h>

#include "zint.h"
#include "ztools.h"
#include "jstdbda.h"

static  int initialised = 0;
static  int allocated[10];

struct standard_bda * dllopen( char * nptr, int strsize )
{
  int i;
  struct standard_bda * lptr;

  if (!( initialised ))
    for (initialised=0; initialised < 10; initialised++ )
      allocated[initialised] = 0;

  if (!(lptr = allocate( sizeof( struct standard_bda ) ) ))
    return( lptr );

  lptr->stringwork = (char *) 0;

  for ( lptr->stringdex=
    lptr->workindex=
    lptr->heapindex=
    lptr->loaded= 
    lptr->librarynumber=0,i=0; 
    i < 10; i++ )
    if (!(allocated[i])) {
      allocated[i] = lptr->librarynumber = (i+1);
      break;
      }

  if (!( lptr->librarynumber )) 
    return(lptr);

  if ((lptr->loaded = InitRunTime(lptr->librarynumber,(unsigned char *) (lptr->libraryname = nptr),0,&lptr->context,sizeof( BDA_INIT ))) != 0 )
    if ( strsize )
      lptr->stringwork = allocate( strsize );

  return( lptr );
}

void  dllclose( struct standard_bda * lptr )
{
  if (( lptr->librarynumber )
  &&  ( lptr->loaded )) {
    (void) FinRunTime(lptr->librarynumber);
    allocated[(lptr->librarynumber-1)] = 0;
    }

  if ( lptr->stringwork )
    lptr->stringwork = liberate( lptr->stringwork );

  lptr->stringdex   = lptr->loaded    = 
  lptr->librarynumber   = lptr->workindex = 
          lptr->heapindex = 0;

  lptr = liberate( lptr );

  return;
}

int dllcallfunction(struct standard_bda * lptr, int functionid )
{
  int parameters=lptr->heapindex;
  lptr->stringdex = lptr->workindex = lptr->heapindex = 0;
  if (!( lptr->librarynumber )) 
    return(-1);
  else if (!( lptr->loaded )) 
    return(-1);
  else  return( CallRunTime(  lptr->librarynumber, 
          functionid, 
          parameters,
              lptr->byteheap,   
          lptr->longheap,     
          lptr->wordheap ) );
}

int dlladdparameter(struct standard_bda * lptr,  void * vptr, int vlen, int vtype )
{
  if (!( lptr->librarynumber )) 
    return(-1);
  else  {
    lptr->longheap[lptr->heapindex] = vptr;
    lptr->wordheap[lptr->heapindex] = vlen;
    lptr->byteheap[lptr->heapindex] = (vtype & 0x00FF);
    lptr->heapindex++;
    return(0);
    }
}

int dllbyteresult( struct standard_bda * lptr, void * vptr )
{
  return( dlladdparameter(lptr, vptr, 1, 0x0080 ) );
}

int dllwordresult( struct standard_bda * lptr, void * vptr )
{
  return( dlladdparameter( lptr, vptr, 2, 0x0081 ) );
}

int dllbcdresult( struct standard_bda * lptr, void * vptr , int vlen )
{
  return( dlladdparameter( lptr, vptr, vlen, 0x0082 ) );
}

int dllstringresult( struct standard_bda * lptr, void * vptr, int vlen )
{
  return( dlladdparameter( lptr, vptr, vlen, 0x0083 ) );
}

int dllbytevalue( struct standard_bda * lptr, int v )
{
  char *  vptr;
  vptr = &lptr->workheap[lptr->workindex]; lptr->workindex++;
  *vptr = (v & 0x00FF);
  return( dlladdparameter( lptr, vptr, 1, 0x0000 ) );
}

int dllwordvalue( struct standard_bda * lptr, int v )
{

  char *  vptr;
  vptr = &lptr->workheap[lptr->workindex]; lptr->workindex += 2;
  *vptr = ((v >> 8) & 0x00FF);
  *(vptr+1) = (v & 0x00FF);
  return( dlladdparameter( lptr, vptr, 2, 0x0001 ) );
}

int dllbytepointer( struct standard_bda * lptr, void * vptr )
{
  return( dlladdparameter( lptr, vptr, 1, 0x0000 ) );
}

int dllwordpointer( struct standard_bda * lptr, void * vptr )
{
  return( dlladdparameter( lptr, vptr, 2, 0x0001 ) );
}

int dllbcdvalue( struct standard_bda * lptr, void * vptr , int vlen )
{
  return( dlladdparameter( lptr, vptr, vlen, 0x0002 ) );
}

int dllstringvalue( struct standard_bda * lptr, void * vptr, int vlen )
{
  return( dlladdparameter( lptr, vptr, vlen, 0x0003 ) );
}

int dllabalstring( struct standard_bda * lptr, char * sptr, int slen , int tlen, int mode )
{
  char * tptr;
  int i;
  if (!(lptr->stringwork)) return(-1);
  else  {
    tptr = (lptr->stringwork + lptr->stringdex);
    lptr->stringdex += (tlen + 1);
    }
  for ( i=0; i < tlen; i++ ) {
    if (!(*sptr)) break;
    else *(tptr +i) = *(sptr++);
    }
  if ( i < tlen ) {
    if ( mode ) {
      *(tptr+i) = 0;
      i++;
      }
    for ( ; i < tlen; i++)
      *(tptr +i) = ' ';

    }
  *(tptr+i) = 0;

  return( dlladdparameter( lptr, tptr, tlen, 0x0003 ) );
}

void  dllswapbytes( struct standard_bda * lptr, short int  * rptr )
{
  short int v;
  v = *rptr;
  *rptr = (((v >> 8) & 0x00FF)  | (( v & 0x00FF) << 8));
  return;
}

#endif  // _bdacontrol_cpp


