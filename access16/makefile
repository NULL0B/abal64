! include $(ABAL)/common/host.def
SP01 = $(ABAL)/src/access
.c.o:
	$(GCC) -c $(GDB) -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS $(HOST) -DUNIX -Dx8086 $*

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
	$(GCC) -c -g $(CC_SHARED) $(GDB) $(HOST) $(SP01)/exaccess.c
! make

! ifdef SHARED_LIBRARIES
$(ABAL)/lib/libaccess.so: exaccess.o
	$(GCC) -g $(GDB) $(LD_SHARED) -o $@ exaccess.o
	echo LIBACCESS = /lib/libaccess.so > $(ABAL)/common/libaccess16.def

! else
! shell echo LIBACCESS = $(ABAL)/access/exaccess.o > $(ABAL)/common/libaccess16.def
! endif


! make














