/*
 *  ------------------  ----------------------------
 *  Project : JavAbal Compiler and Virtual Machine  
 *  ------------------  ----------------------------
 *  Date  : 18/09/97
 *  ------------------  ----------------------------
 */

#ifndef _STDPSU_H
#define _STDPSU_H
#include"wdef.h"
//#include "jstdtypes.h"

/*  ---------------------------------------------------------------------
 ** from PSU.ASM  I.J. Marshall 10/09/1997  PIXEL_STORAGE_UNIT
 ** ---------------------------------------------------------------------
 ** Reworked  I.J.Marshall  04/08/1999  For NV Graphic Print
 ** ---------------------------------------------------------------------
 ** Modified  I.J.Marshall  16/02/2000  Commit Pixel Storage
 **             has been added for 
 **             GUI Smoothing of NV
 ** ---------------------------------------------------------------------
 ** This file provides the description of the multiple buffering mechanism
 ** implemented in the form of the ABAL++ class :
 **
 **   "pixel_storage_unit" 
 **
 ** Instances of this class are of variable length depending upon the
 ** quantity of pixel data required for storage. 
 ** They will all be at very least : 
 **
 **   ((SIZEOF pixel_storage_unit ) - 1)
 **
 ** and are normally 
 **
 **   ((SIZEOF pixel_storage_unit ) - 1) + (rowcount * columncount)
 ** 
 ** ---------------------------------------------------------------------
 **
 ** The current ABAL++ description of this class, in terms of its data 
 ** members only,  can be seen below :
 **
 ** class pixel_storage_unit
 **
 **   Public pixel_storage_unit Pointer NextBuffer
 **   Private Dcl AtColumn%
 **   Private Dcl AtRow%
 **   Public Dcl Columns%
 **   Public Dcl Rows%
 **   Private Dcl Storage$=1
 **
 ** endclass pixel_storage_unit
 ** 
 ** ---------------------------------------------------------------------
 ** The full description of this class, including its Methods, may be
 ** found in the ABAL++ Class File PIXELCC.AS
 ** ---------------------------------------------------------------------
 **
 ** ---------------------------------------------------------------------
 ** * * * * *   V E R Y   I M P O R T A N T   * * * * * * *
 ** ---------------------------------------------------------------------
 ** NB if any more data members are to be added then the following 'C'
 ** constants will need to be adjusted in order to reflect the true
 ** structure of instances of this class. 
 ** ---------------------------------------------------------------------
 */

#define _PSU_VALIDPTR      1

#define _PSU_NEXT_BUFFER_CHECK     0
#define _PSU_NEXT_BUFFER     1
#define _PSU_AT_COLUMN       5
#define _PSU_AT_ROW              7
#define _PSU_COLUMNS             9
#define _PSU_ROWS               11
#define _PSU_STORAGE            13

#define STDPSU    struct standard_pixel_storage
#define STDPSUPTR STDPSU FAR PTR

STDPSU  {
  WORD  descriptor[8];
  PTRC  root;
  PTRC  current;
  WORD  seekbase;
  WORD  seeksize;
  };

  STDPSUPTR allocate_graphic_storage( WORD, WORD, WORD, WORD );
  STDPSUPTR allocate_textual_storage( WORD, WORD, WORD, WORD );
  STDPSUPTR allocate_shadow_storage( STDPSUPTR );
  STDPSUPTR liberate_pixel_storage( STDPSUPTR );
  PTRC    resolve_pixel_storage( STDPSUPTR );
  VOID    background_pixel_capture( STDPSUPTR );
  VOID    foreground_pixel_capture( STDPSUPTR );
  VOID    cancel_pixel_capture( STDPSUPTR  );
  VOID    commit_pixel_storage( STDPSUPTR, WORD, WORD );
  VOID    reset_pixel_row( STDPSUPTR, WORD, WORD, WORD, WORD );
  WORD    collect_pixel_row( STDPSUPTR, WORD, WORD, WORD, PTRC);
  PTRC    connect_pixel_row( STDPSUPTR, WORD );

  VOID    capture_pixel_storage( STDPSUPTR storage );
  VOID    refresh_pixel_storage( STDPSUPTR storage );

  /* ------------ */
#endif  /* _STDPSU_H  */
  /* ------------ */



