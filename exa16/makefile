! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

VERSION666 = $(VABAL) 
# -DVERSION666  -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $(VABAL)
VERSIONXX  = 
# -DVERSION_XX

! include $(ABAL)/common/idbcode.def
! include $(ABAL)/common/allocate16.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/libbda16.def
! include $(ABAL)/common/libcico16.def
! include $(ABAL)/common/libprint16.def
! include $(ABAL)/common/libaccess16.def
! include $(ABAL)/common/pixilib.def
! include $(ABAL)/common/libmafl16.def
! include $(ABAL)/common/libcri16.def
! include $(ABAL)/common/libimage16.def

! include $(ABAL)/common/vexadb.def
! include $(ABAL)/common/editor.def
! include $(ABAL)/common/ixmisc.def 
! include $(ABAL)/common/repmisc.def 
! include $(ABAL)/common/dirmisc.def 
! include $(ABAL)/common/stdprod.def 
! include $(ABAL)/common/misc.def 
! include $(ABAL)/common/jpeg16.def 
! include $(ABAL)/common/ldap.def 
! include $(ABAL)/common/libconv.def 

CABOOM = $(VERSION666) $(VERSIONXX) -DTRACEON -DTRACEABAL -DCRIVER36 $(USEICONV)

exa   = $(EXABIN)/exa16
exadb = $(EXABIN)/exadb16

SP01    = $(ABAL)/src/exa/
SP02    = $(ABAL)/include
TGTPATH = $(ABAL)/bin
EXA = $(TGTPATH)/exa16
EXADB = $(TGTPATH)/exadb16

LIBTRACE = $(ABAL)/exa32/extrace.o
GENTRACE = $(ABAL)/z/common

ABALX11 = -DABALX11
EXMIMO  = 

.c.o:
	-$(GCC) -c -g -I$(SP02) $(GDB) $(ABALX11) $(CABOOM) -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP $* $(PIPO)
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! include exa.mf
! include vdb.mf
! make
! shell $(ABAL)/product/cricheck






















