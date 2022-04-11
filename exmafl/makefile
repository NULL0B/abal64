! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

SP01        = $(ABAL)/src/exmafl/
CV          = 40
CC_STAT64   = -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 
CC_DEFINES  = -DABAL21 -DAIX_VERS -DC_ISAM_410 -DINXSQL -DISINTEL -DISUNIX -DIX386 -DLINT_ARGS $(HOST) -DABAL64 -DVERSION666 -DUSEIT -DCRIVER$(CV)

exma.o: $(SP01)exma.c $(SP01)exma.h $(SP01)exmabd.c $(SP01)exmafl.c $(SP01)exmamc.c $(SP01)exmasi.c $(SP01)exmaunix.c 
	-$(GCC) -c -g $(GDB)  $(CC_DEFINES) $(CC_STAT64) $(SP01)exma.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

flfile.o: $(SP01)flfile.c $(SP01)flfile.h $(SP01)flfiled.c $(SP01)flunix.c
	-$(GCC) -c -g $(GDB) $(CC_SHARED) $(CC_DEFINES) $(CC_STAT64)  $(SP01)flfile.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! make

$(ABAL)/archive/exmafl.a: exma.o 
	ar cr $@ $?
	echo LIBMAFL = $@ > $(ABAL)/common/libmafl.def


$(ABAL)/lib/libflfile64.so: flfile.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ $?
	echo LIBFLFILE = $(ABAL)/lib/libflfile64.so  > $(ABAL)/common/libflfile.def

! make
! shell @rm pipo* -f

