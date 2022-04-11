
//  ------------------------------------------------------------------
//  Project   Web Navigator/Browser for Amenesik / Sologic / Twin Server
//  ------------------------------------------------------------------
#ifndef _standard_bda_h
#define _standard_bda_h

#include "pubsbda.h"

#ifndef _BDA_MAX_HEAP
#define _BDA_MAX_HEAP 5
#endif

struct  standard_bda  {

  int   librarynumber;
  char *    libraryname;
  int   heapindex;
  int   workindex;
  BDA_INIT  context;
  void *    longheap[_BDA_MAX_HEAP];
  unsigned short  wordheap[_BDA_MAX_HEAP];
  unsigned char   byteheap[_BDA_MAX_HEAP];
  char    workheap[_BDA_MAX_HEAP*2];
  int   stringdex;
  char *    stringwork;
  int   loaded;

  };

struct standard_bda *   dllopen( char *, int);
void      dllclose(struct standard_bda * );
void      dllreset();
int     dllcallfunction(struct standard_bda *, int );
int     dlladdparameter(struct standard_bda *, void * , int , int );
int     dllbyteresult(struct standard_bda *, void *  );
int     dllwordresult(struct standard_bda *, void *  );
int     dllbcdresult(struct standard_bda *, void *  , int  );
int     dllstringresult(struct standard_bda *, void * , int  );
int     dllbytepointer(struct standard_bda *, void *  );
int     dllwordpointer(struct standard_bda *, void *  );
int     dllbytevalue(struct standard_bda *, int  );
int     dllwordvalue(struct standard_bda *, int  );
int     dllbcdvalue(struct standard_bda *, void *  , int  );
int     dllstringvalue(struct standard_bda *, void * , int  );
int     dllabalstring(struct standard_bda *, char * , int , int , int );
void      dllswapbytes(struct standard_bda *, short int * );


#endif  // _standard_bda





