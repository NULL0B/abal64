# json library makefile

! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/allocate64.def
! include $(ABAL)/common/linbda.def

SP01 = $(ABAL)/src/bdamail/
SP02 = $(ABAL)/include/bdas/
VERSION666 = -g -DVERSION666 -DABAL64 -DUNIX 

$(SP01)bdamail.c: $(SP01)bdamail.def 
	$(LINBDA) -bbdamail64 $(SP01)bdamail

! make

.c.o:
! ifdef AGR
	-$(GCC) -c $(CC_SHARED) $(VERSION666)  -I$(SP02) $(HOST) -Dunix  $* > pipo1 2> pipo2
        cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(GCC) -c $(CC_SHARED) $(VERSION666)  -I$(SP02) $(HOST)  -Dunix  $*
! endif

bdamail.o: $(SP01)bdamail.c
abalmail.o: $(SP01)abalmail.c

! make
$(ABAL)/lib/bdamail64.so: bdamail.o abalmail.o
	$(GCC) $(VERSION666) $(LD_SHARED) -o $@ $? $(ALLOCATE)
	cp $@ $(ABAL)/lib/checkbdamail64.so
	bdatester64 checkbdamail
	rm $(ABAL)/lib/checkbdamail64.so
! make

! shell -@rm -f pipo*
