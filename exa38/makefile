! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

VERSION666 = -DVERSION666  -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 $(VABAL)
VERSIONXX  = -DVERSION_XX
CRIVER     = 38
CRIVER$(CRIVER) =

! include $(ABAL)/common/idbcode.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/libbda.def
! include $(ABAL)/common/libcico.def
! include $(ABAL)/common/libprint.def
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/pixilib.def
! shell cp $(ABAL)/Cri$(CRIVER)/libcriter32.so $(EXALIB)/libcriter32.so -f
! include $(ABAL)/common/exmafl$(CRIVER).def
! include $(ABAL)/common/libcri.def
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

CABOOM = $(VERSION666) $(VERSIONXX) -DTRACEON -DTRACEABAL -DCRIVER$(CRIVER) $(USEICONV) 

exa   = $(EXABIN)/exa32.$(CRIVER)
exadb = $(EXABIN)/exadb32.$(CRIVER)

SP01    = $(ABAL)/src/exa/
SP02    = $(ABAL)/include
TGTPATH = $(ABAL)/bin
EXA = $(TGTPATH)/exa32.$(CRIVER)
EXADB = $(TGTPATH)/exadb32.$(CRIVER)

EXASO = $(ABAL)/lib/libexa32.so

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






















