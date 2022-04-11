! include $(ABAL)/common/host.def
SP01 = $(ABAL)/src/access/
CC_STAT64 = -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

.c.o:
	$(GCC) -c $(GDB) -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS $(HOST) $(CC_STAT64) -DVERSION666 -DUNIX -Dx8086 $* > pipo 2> pipo

coexa.o: $(SP01)/coexa.c /usr/include/signal.h $(SP01)/exuser.h $(SP01)/portage.h
exlock.o: $(SP01)/exlock.c /usr/include/stdio.h $(SP01)/exlock.h $(SP01)/exuser.h $(SP01)/portage.h
exdaemon.o: $(SP01)/exdaemon.c /usr/include/signal.h /usr/include/stdio.h /usr/include/string.h $(SP01)/exuser.h $(SP01)/portage.h
exetat.o: $(SP01)/exetat.c /usr/include/signal.h /usr/include/string.h $(SP01)/exaccess.h $(SP01)/exlock.h $(SP01)/portage.h
stdsignal.o: $(SP01)/stdsignal.c

! make

$(ABAL)/bin/access: coexa.o exlock.o exdaemon.o exetat.o stdsignal.o
	$(GCC) -g -o $@ $?
! make

exaccess.o: $(SP01)/exaccess.c $(SP01)/exaccess.h
	$(GCC) -c -g $(CC_SHARED) $(GDB) $(HOST) -DVERSION666 -DNOACCESS $(CC_STAT64)  $(SP01)/exaccess.c 
! make

! ifdef SHARED_LIBRARIES
$(ABAL)/lib/libaccess32.so: exaccess.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@  exaccess.o
	echo LIBACCESS = $(EXALIB)/libaccess32.so   > $(ABAL)/common/libaccess.def
	echo OBJACCESS = $(ABAL)/access32/exaccess.o >> $(ABAL)/common/libaccess.def
!else
! shell	echo LIBACCESS = $(ABAL)/access32/exaccess.o > $(ABAL)/common/libaccess.def
	echo OBJACCESS = $(ABAL)/access32/exaccess.o >> $(ABAL)/common/libaccess.def
! endif
! make
! error no cri check required
$(ABAL)/bin/cricheck: $(SP01)cricheck.c
	$(GCC) -g $(GDB) -o $@ $*
! make



