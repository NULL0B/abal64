
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/host.def

SP01 = $(ABAL)/src/allocate/

allocate.o: $(SP01)allocate.c
! ifdef AGR
	-$(GCC) -c -g $(CC_SHARED) $(GDB) $* > pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	$(AGR)
! else
	$(GCC) -c -g $(CC_SHARED) $(GDB) $* 
! endif

! make

! ifdef SHARED_LIBRARIES

$(ABAL)/lib/allocate64.so: allocate.o
	$(GCC) -o $@ $(LD_SHARED)  $(GDB) allocate.o
	echo ALLOCATE = $(ABAL)/lib/allocate64.so > $(ABAL)/common/allocate64.def
	echo ALLOCATE = $(ABAL)/lib/allocate64.so > $(ABAL)/common/allocate.def

! make

! else
$(ABAL)/common/allocate.def: $(ABAL)/allocate/allocate.o
	echo ALLOCATE = $(ABAL)/allocate/allocate.o > $(ABAL)/common/allocate.def
! make
! endif
! shell @rm pipo* -f

