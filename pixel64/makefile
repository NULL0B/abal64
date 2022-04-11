! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/ixciconr.def
! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/libpng.def

V666 = -DVERSION666 -DABAL64
$1   = TRUE

! ifndef PASSONE
! ifndef PASSTWO
PASSONE = TRUE
PASSTWO = TRUE
! endif
! endif
! endif

#
# file         : makefile
# description  : for the compilation of the pixel library X11 function objects
# date         : 11/12/2001
# version      : 1.1a.0.01
# status       : provisionary
#

C    = .c
H    = .h
O    = .o
CC      = $(GCC) -c $(GDB) $(SYSPNG) $(CC_SHARED)
LD      = $(GCC) -g -o 
POBJ    =
OBJ     =
SP04    = -I$(ABAL)/include/

COMPILE = $(CC) -DUNIX -Dunix $(SP04)

# primary libraries and objects

! ifdef PASSONE
! include library.mf
! include grapil.mf
! endif
! make

# secondary production targets

! ifdef PASSTWO
! include sing.mf
! include vis.mf
! include vexadb.mf
! endif
! make

# deprecated production targets

! ifdef PASSFOUR
! include manedit.mf
! include iview.mf
! include xml.mf
! include gwb.mf
! endif
! make

# shell @rm pipo* -f

