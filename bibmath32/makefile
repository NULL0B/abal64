! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def

VERSION666 = -DVERSION666

SP01 = $(ABAL)/src/bibmath/
SP02 = $(ABAL)/include/bdas/


$(SP01)ibibmath.c: $(SP01)bibmath.def $(LINBDA)
	$(LINBDA) -r$(SP01)ibibmath -x -bBIBMATH32.$(MASTER3)  $(SP01)bibmath

! make

ibibmath.o: $(SP01)ibibmath.c 
	$(GCC) -g $(GDB) -c $(CC_SHARED) -I$(SP02) -DUNIX $(VERSION666) -Dunix $(SP01)ibibmath.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif


bibmath.o: $(SP01)bibmath.c
	$(GCC) -g $(GDB) -c $(CC_SHARED) -I$(SP02) -DUNIX $(VERSION666) -Dunix -DFCT_ENTETE $(SP01)bibmath.c $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! make

$(ABAL)/lib/bibmath32.so: ibibmath.o bibmath.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ ibibmath.o bibmath.o -lm
! ifdef BDATESTER32
	cp $@ $(EXALIB)/checkmath32.so
	$(BDATESTER32) checkmath
	rm $(EXALIB)/checkmath32.so
! endif
	$(LIBREF) $@ $(EXALIB)/bibmath32.so

! make











