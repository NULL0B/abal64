! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

SP01 = $(ABAL)/src/exmafl/
CV   = $1

# ---------------------------------------------------------------------------------------
# On a rejout‚ USEIT ici pour les problems dans flfile.c concernant les FFbegin et FFend
# qui ont pass‚ des choses un peut n'importe comment depuis on ne sais quand 
# ---------------------------------------------------------------------------------------
CC_STAT64   = -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 
CC_DEFINES = -DABAL21 -DAIX_VERS -DC_ISAM_410 -DISINTEL -DISUNIX -DIX386 -DLINT_ARGS $(HOST) -DVERSION666 -DUSEIT -DCRIVER$(CV)

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

$(ABAL)/lib/exmafl$(CV).a: exma.o 
	ar cru $@ $?
	echo LIBMAFL$(CV) = $@ > $(ABAL)/common/libmafl$(CV).def


$(ABAL)/lib/libflfile32.so: flfile.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ $?
	cp $@ $(EXALIB)/libflfile32.so
	echo LIBFLFILE = $(EXALIB)/libflfile32.so  > $(ABAL)/common/libflfile.def

! make



