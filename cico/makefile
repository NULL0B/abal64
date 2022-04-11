! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/archive.def

CC_VERSION  = -DABAL64
CC_STAT64   = -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 
CC          = $(GCC)
CC_FLAGS    =   -g -ggdb     
CC_INCLUDES = -I$(ABAL)/include -I$(ABAL)/src/access -I$(ABAL)/src/exa
CC_DEFINES  = -DABAL21 -DABALCONF -DENFORCED_CONSTANTS -DAIX_VERS -DCICO_BDA -DEXABAL -DIDIRECT -DIMPLOC $(HOST) -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX
SP01        = $(ABAL)/src/cico/

! ifdef	AGR
PIPO = 1> pipo1 2> pipo2
! else
PIPO =
! endif

.c.o:
! ifdef AGR
	-$(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $* $(PIPO)
	-cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $*
! endif

ixcico.o: $(SP01)ixcico.c $(SP01)excico.c $(SP01)ixim.h
ixcico64.o: $(SP01)ixcico64.c $(SP01)ixcico.c $(SP01)excico.c $(SP01)ixim.h
libprint.o: $(SP01)libprint.c $(SP01)ixlo.c $(SP01)ixim.c $(SP01)iximploc.c
libprint64.o: $(SP01)libprint64.c $(SP01)libprint.c $(SP01)ixlo.c $(SP01)ixim.c $(SP01)iximploc.c

! make
! shell echo LIBCICO = $(ABAL)/cico/ixcico64.o > $(ABAL)/common/libcico.def

! ifdef SHARED_LIBRARIES
$(ABAL)/lib/libprint64.so: libprint64.o
	$(GCC) -g -ggdb -o $@ $(LD_SHARED) $? $(ALLOCATE)
	echo LIBPRINT = $(ABAL)/lib/libprint64.so > $(ABAL)/common/libprint.def
! else
! shell @echo LIBPRINT = $(ABAL)/cico/libprint64.o > $(ABAL)/common/libprint.def
! endif
! make

CC_DEFINES  = -DABAL21 -DABALCONF -DAIX_VERS -DCICO_BDA -DIDIRECT -DIMPLOC $(HOST) -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX
ixciconr.o: $(SP01)ixcico.c $(SP01)excico.c $(SP01)ixciconr.c
! ifdef AGR
	- $(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $(SP01)ixciconr.c $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $(SP01)ixciconr.c
! endif
	echo IXCICONR = $(ABAL)/cico/$@ > $(ABAL)/common/ixciconr.def

! make
CC_DEFINES  = -DABAL21 -DABALCONF -DAIX_VERS -DCICO_BDA -DIDIRECT -DIMPLOC $(HOST) -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX
ixciconr64.o: $(SP01)ixcico.c $(SP01)excico.c $(SP01)ixciconr64.c
! ifdef AGR
	-$(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $(SP01)ixciconr64.c $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(CC) -c  $(CC_VERSION) $(CC_FLAGS) $(CC_DEFINES) $(CC_STAT64) $(CC_INCLUDES) $(SP01)ixciconr64.c
! endif
	echo IXCICONR64 = $(ABAL)/cico/$@ > $(ABAL)/common/ixciconr64.def

! make

! shell @rm pipo* -f



