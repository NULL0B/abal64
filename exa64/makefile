! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

VERSION666 = -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $(VABAL) -DABALV33 -DINXSQL
VERSIONXX  = -DVERSION_XX

$1 = TRUE

! ifndef PASSONE
! ifndef PASSTWO
PASSONE = TRUE
PASSTWO = TRUE
! endif
! endif

! include $(ABAL)/common/idbcode.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/libbda.def
! include $(ABAL)/common/libcico.def
! include $(ABAL)/common/libprint.def
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/pixilib.def
! include $(ABAL)/common/exmafl.def
! include $(ABAL)/common/database.def
! include $(ABAL)/common/libimage.def
! include $(ABAL)/common/vexadb.def
! include $(ABAL)/common/editor.def
! include $(ABAL)/common/ixmisc.def 
! include $(ABAL)/common/repmisc.def 
! include $(ABAL)/common/dirmisc.def 
! include $(ABAL)/common/stdprod.def 
! include $(ABAL)/common/misc.def 
! include $(ABAL)/common/jpeg.def 
! include $(ABAL)/common/ldap.def 
! include $(ABAL)/common/libconv.def 
! include $(ABAL)/common/idbcode.def

CABOOM = $(VERSION666) $(VERSIONXX) -DTRACEON -DTRACEABAL -DCRIVER40 $(USEICONV) 

exa   = $(EXABIN)/exa64
exadb = $(EXABIN)/exadb64

SP01    = $(ABAL)/src/exa/
SP02    = $(ABAL)/include
SP03    = $(ABAL)/src/global
TGTPATH = $(ABAL)/bin
EXA = $(TGTPATH)/exa64
EXADB = $(TGTPATH)/exadb64

EXASO = $(ABAL)/lib/libexa64.so

LIBTRACE = $(ABAL)/exa32/extrace.o
GENTRACE = $(ABAL)/z/common

ABALX11 = -DABALX11
EXMIMO  = 

.c.o:
! ifdef	AGR
	-$(GCC) -c -g -I$(SP02) -I$(SP03) $(GDB) $(ABALX11) $(CABOOM) -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP $* $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(GCC) -c -g -I$(SP02) -I$(SP03) $(GDB) $(ABALX11) $(CABOOM) -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP $*
! endif

! ifdef PASSONE
! include exa.mf
! make
# include rpc.mf
# make
! endif

! ifdef PASSTWO
! include vdb.mf
! make
! endif

# shell @rm pipo* -f


