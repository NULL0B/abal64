! include $(ABAL)/common/host.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/libaccess.def

VERSION666 = -DVERSION666 -DABAL64

target  = tty64.so
target2 = tracetty
SP01 = $(ABAL)/src/tty/
SP02 = $(ABAL)/include/bdas/

GCC = gcc 
CC = $(GCC)
CC_FLAGS = -g    
CC_INCLUDES = -I$(SP02)
CC_DEFINES = -DTRACEON -DUNIX -D_LINUX -Dunix $(HOST) -DABAL3 $(VERSION666) $(CC_SHARED)
LINKER = $(GCC)
LINKER_FLAGS = $(LD_SHARED)

$(SP01)itty.c: $(SP01)tty.def $(LINBDA)
	$(LINBDA) -x -r$(SP01)itty -d -tTRACE_TTY -bTTY64.$(MASTER3) $(SP01)tty
! make

$(ABAL)/lib/$(target): itty.o utty.o $(ALLOCATE) $(LIBACCESS)
	$(LINKER) -o $@ $(LINKER_FLAGS) $? 
! ifdef BDATESTER64
	cp $@ $(ABAL)/lib/check$(target)
	$(BDATESTER64) checktty
	rm $(ABAL)/lib/check$(target)
! endif
	
$(ABAL)/bin/$(target2): tracetty.o
	$(LINKER) -o $@ $?
 
.c.o:
	-$(CC) -c $(CC_FLAGS) $(CC_SHARED) $(CC_DEFINES) $(CC_INCLUDES) $* 1> pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

itty.o: $(SP01)itty.c $(SP02)ldfbda.h
utty.o: $(SP01)utty.c $(SP02)bda.h $(SP01)utty.h $(SP01)abal.h
tracetty.o: $(SP01)tracetty.c $(SP02)_type.h

