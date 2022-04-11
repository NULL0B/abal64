! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/libssl.def

SP01 = $(ABAL)/src/bdanet/
SP02 = $(ABAL)/include/bdas/

$(ABAL)/lib/bdanet.so: connect.o url.o global.o files.o httpabal.o httpfunc.o http.o bdanet.o 
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ connect.o url.o global.o files.o httpabal.o httpfunc.o http.o bdanet.o $(LIBSSL) $(EXALIB)/libprotb32.so
! ifdef BDATESTER
	cp $@ $(EXALIB)/checkbdanet.so
	$(BDATESTER) checkbdanet
	rm $(EXALIB)/checkbdanet.so
! endif
	$(LIBREF) $@ $(EXALIB)/bdanet.so

$(SP01)bdanet.c: $(SP01)bdanet.def $(LINBDA)
	$(LINBDA) -bBd@Net16.$(MASTER2) $(SP01)bdanet

bdanet.o: $(SP01)bdanet.c
	-$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix $* $(PIPO)
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

http.o: $(SP01)http.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif


httpabal.o: $(SP01)httpabal.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif


httpfunc.o: $(SP01)httpfunc.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

connect.o: $(SP01)connect.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif


url.o: $(SP01)url.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

global.o: $(SP01)global.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif


files.o: $(SP01)files.c
	$(GCC) -c $(CC_SHARED) -g $(GDB)  -I$(SP02) $(HOST) $(SYSSSL) -Dunix  $* $(PIPO) 
! ifdef	AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif
! make

