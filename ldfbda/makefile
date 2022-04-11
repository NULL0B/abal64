! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def

! ifdef ABALDEBIAN
EXALIB = -DABALDEBIAN
! else
EXALIB = 
! endif

SP01 = $(ABAL)/src/ldfbda/
INCLUDE = -I$(ABAL)/include/bdas/
DEFINE  = -DUNIX -Dunix $(HOST) -DUSEIT -DVERSION666 -DABAL64 $(EXALIB)
COMPILE = $(GCC) -c -g $(INCLUDE) $(DEFINE)
LINK    = $(GCC) -g -ggdb 

exbda64.o: $(SP01)exbda64.c $(SP01)exbda.c
	-$(COMPILE) $* 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
	echo LIBBDA = $(ABAL)/ldfbda/$@ > $(ABAL)/common/libbda.def

! make
testbda64.o: $(SP01)testbda64.c $(SP01)exbda.c
	-$(COMPILE) $(SP01)testbda64.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

! make
$(ABAL)/bin/bdatester64: testbda64.o $(ALLOCATE)
	$(LINK) -o $@ $? $(LIBDL)
! make
$(ABAL)/bin/bdapreload: $(SP01)bdapreload.c 
	$(LINK) -o $@ $? > pipo 2> pipo
! make
! shell @rm pipo* -f

