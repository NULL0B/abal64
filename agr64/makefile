! include $(ABAL)/common/host.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/agr.def

SP01 = $(ABAL)/src/agr/
SP02 = $(ABAL)/include

browse.o: $(SP01)browse.c
! ifdef AGR
	-$(GCC) -c  -g $(GDB) -DVERSION666 -DUNIX -Dunix $(HOST) -DABAL21 -I$(SP02) $(SP01)browse.c $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(GCC) -c  -g $(GDB) -DVERSION666 -DUNIX -Dunix $(HOST) -DABAL21 -I$(SP02) $(SP01)browse.c 
! endif
! make

$(ABAL)/bin/agr64: browse.o $(SYSTEME) $(WILDCOMP)
	$(GCC) -g $(GDB) -o $@ browse.o $(SYSTEME) $(WILDCOMP)


! make










