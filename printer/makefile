! include $(ABAL)/common/host.def
! include $(ABAL)/common/host.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/rgraph.def

$1 = TRUE

BDATESTER64 = $(ABAL)/bin/bdatester64
SP01 = $(ABAL)/src/printer/
# TRACE = -d/tmp/printer.trace
TRACE = 

CC = $(GCC) -c -g $(CC_SHARED) $(GDB) -DBOOLI -DUNIX $(HOST) -DVERSION666 -DUSEIT -I$(ABAL)/include/bdas/ -I$(ABAL)/src/pixel

! ifdef PASSONE
paper.o: $(SP01)paper.c
	-$(CC) $(SP01)paper.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
	echo PAPER = $ABAL/printer/paper.o > $ABAL/common/paper.def 
! else

$(SP01)printer.c: $(SP01)printer.def $(LINBDA)
	$(LINBDA) $(TRACE) -bPRINTER64.$(MASTER3) $(SP01)printer

! make

printer.o: $(SP01)printer.c
	$(CC) $(SP01)printer.c

psiii.o: $(SP01)psiii.c $(SP01)lodriver.c $(SP01)psiii.h $(SP01)lodriver.h
	-$(CC) $(SP01)psiii.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

psiiit.o: $(SP01)psiiit.c $(SP01)lodriver.c $(SP01)psiii.h $(SP01)lodriver.h
	-$(CC) $(SP01)psiiit.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

gdit.o: $(SP01)gdit.c $(SP01)lodriver.c $(SP01)gdit.h $(SP01)lodriver.h
	-$(CC) $(SP01)gdit.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

psiiihq.o: $(SP01)psiiihq.c $(SP01)lodriver.c $(SP01)psiii.h $(SP01)lodriver.h
	-$(CC) $(SP01)psiiihq.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

bj300330.o: $(SP01)bj300330.c $(SP01)lodriver.c $(SP01)psiii.h $(SP01)lodriver.h
	-$(CC) $(SP01)bj300330.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

ljii.o: $(SP01)ljii.c $(SP01)lodriver.c $(SP01)ljii.h $(SP01)lodriver.h
	$(CC) $(SP01)ljii.c 

ljiv.o: $(SP01)ljiv.c $(SP01)lodriver.c $(SP01)ljiv.h $(SP01)lodriver.h
	-$(CC) $(SP01)ljiv.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

svg.o: $(SP01)svg.c $(SP01)lodriver.c $(SP01)svg.h $(SP01)lodriver.h
	-$(CC) $(SP01)svg.c 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

$(ABAL)/lib/ljiv64.so: ljiv.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checklj64.so
	$(BDATESTER64) checklj
	rm $(ABAL)/lib/checklj64.so
! endif

$(ABAL)/lib/ljii64.so: ljii.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checklj64.so
	$(BDATESTER64) checklj
	rm $(ABAL)/lib/checklj64.so
! endif

$(ABAL)/lib/psiii64.so: psiii.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checkps64.so
	$(BDATESTER64) checkps
	rm $(ABAL)/lib/checkps64.so
! endif

$(ABAL)/lib/psiiit64.so: psiiit.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checkps64.so
	$(BDATESTER64) checkps
	rm $(ABAL)/lib/checkps64.so
! endif

$(ABAL)/lib/gdit64.so: gdit.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checkps64.so
	$(BDATESTER64) checkps
	rm $(ABAL)/lib/checkps64.so
! endif

$(ABAL)/lib/svg64.so: svg.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checksvg64.so
	$(BDATESTER64) checksvg
	rm $(ABAL)/lib/checksvg64.so
! endif

$(ABAL)/lib/psiiihq64.so: psiiihq.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checkps64.so
	$(BDATESTER64) checkps
	rm $(ABAL)/lib/checkps64.so
! endif

$(ABAL)/lib/bj30033064.so: bj300330.o printer.o paper.o $(RGRAPH)
	$(GCC) $(LD_SHARED) -g $(GDB)  -o $@ $?
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/checkps64.so
	$(BDATESTER64) checkps
	rm $(ABAL)/lib/checkps64.so
! endif

! make

! endif


