# json library makefile

! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/allocate64.def
! include $(ABAL)/common/linbda.def

SP01 = $(ABAL)/src/json/
SP02 = $(ABAL)/include/bdas/
VERSION666 = -g -DVERSION666 -DABAL64 -DUNIX 

$(SP01)abaljson.c: $(SP01)abaljson.def 
	$(LINBDA) -bJson64 $(SP01)abaljson

! make

.c.o:
! ifdef AGR
	-$(GCC) -c $(CC_SHARED) $(VERSION666)  -I$(SP02) $(HOST) -Dunix  $* > pipo1 2> pipo2
        cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(GCC) -c $(CC_SHARED) $(VERSION666)  -I$(SP02) $(HOST)  -Dunix  $*
! endif

abaljson.o: $(SP01)abaljson.c
jsonabal.o: $(SP01)jsonabal.c

! make
$(ABAL)/lib/json64.so: abaljson.o jsonabal.o
	$(GCC) $(VERSION666) $(LD_SHARED) -o $@ $? $(ALLOCATE)
	cp $@ $(ABAL)/lib/checkjson64.so
	bdatester64 checkjson
	rm $(ABAL)/lib/checkjson64.so
! make

! shell -@rm -f pipo*
