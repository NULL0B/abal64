ROOT = $(ABAL)
SP01 = $(ROOT)class/
SP02 = $(ROOT)class/include/

POBJ =

OBJ  = .apl

BN01 = $(SP01)

! make

.as.apl:
	otr32 -I$(SP01) -I$(SP02) -nSP01=$(SP01) -sas -o -m  $*

! include visual
! include files 

! make
printer.at: $(SP01)gprinter.as
	otr32 -I$(SP01) -I$(SP02) -sas -d$@ -o -m -x $*
! make


















