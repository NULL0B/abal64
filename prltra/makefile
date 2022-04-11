SP01 = $(ABAL)/src/prltra/
IP02 = $(ABAL)/src/common/
IP03 = $(ABAL)/include/
IP01 = $(ABAL)/include/bdas/
.c.o:
	-$(GCC) -c -DUNIX -DABAL64 -I$(IP01) -I$(IP02) -I$(IP03) -g $(GDB) $* 1>pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

tramain.o: $(SP01)tramain.c
tractx.o: $(SP01)tractx.c
toolabal.o: $(IP02)toolabal.c
trace.o: $(IP03)trace.c

! make
$(ABAL)/common/trace.def: $(ABAL)/prltra/trace.o
	echo TRACE = $(ABAL)/prltra/trace.o > $(ABAL)/common/trace.def
! make
! shell @rm pipo* -f

