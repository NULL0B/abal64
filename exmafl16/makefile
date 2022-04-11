! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

SP01 = $(ABAL)/src/exmafl/
! ifdef ABAL22B
FLFILE = flfile.o
! else
FLFILE = 
! endif

# ---------------------------------------------------------------------------------------
# On a rejout‚ USEIT ici pour les problems dans flfile.c concernant les FFbegin et FFend
# qui ont pass‚ des choses un peut n'importe comment depuis on ne sais quand 
# ---------------------------------------------------------------------------------------
CC_DEFINES = -DABAL21 -DAIX_VERS -DC_ISAM_410 -DISINTEL -DISUNIX -DIX386 -DLINT_ARGS $(HOST) -DUSEIT

$(ABAL)/lib/exmafl16.a: exma.o $(FLFILE)
	ar cru $@ $?
	echo LIBMAFL = $@ > $(ABAL)/common/libmafl16.def

$(ABAL)/lib/libflfile.so: flfile.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ $?
	cp $@ $(EXALIB)/libflfile.so
	echo LIBFLFILE = $(EXALIB)/libflfile.so > $(ABAL)/common/libflfile16.def

exma.o: $(SP01)exma.c $(SP01)exma.h $(SP01)exmabd.c $(SP01)exmafl.c $(SP01)exmamc.c $(SP01)exmasi.c $(SP01)exmaunix.c 
	-$(GCC) -c -g $(GDB)  $(CC_DEFINES) $(SP01)exma.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

flfile.o: $(SP01)flfile.c $(SP01)flfile.h $(SP01)flfiled.c $(SP01)flunix.c
	-$(GCC) -c -g $(GDB) $(CC_SHARED) $(CC_DEFINES)  $(SP01)flfile.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! make














