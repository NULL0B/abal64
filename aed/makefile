! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/ixciconr.def
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/pixilib.def
! include $(ABAL)/common/ixmisc.def 
! include $(ABAL)/common/repmisc.def 
! include $(ABAL)/common/dirmisc.def 
! include $(ABAL)/common/misc.def 

SP01 = $(ABAL)/src/ned/

CC = $(GCC) -c -g $(GDB) -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS $(HOST) -DUSEIT 

LD = $(GCC) -o
LIBREP = $(IXMISC) $(MISC) $(REPMISC) $(DIRMISC) 

LIBRARY = $(PIXILIB) $(IXCICONR) $(XLIB) $(FNPARSER) $(LIBREP)

.c.o:
! ifdef	AGR
	-$(CC) $* $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(CC) $* 
! endif

ednoy.o:    $(SP01)ednoy.c $(SP01)ed.h $(SP01)ednoy.h $(SP01)edmsg.h $(SP01)ednoy2.c $(SP01)traceman.h
edvideo.o:  $(SP01)edvideo.c $(SP01)ed.h $(SP01)edvideo.h $(SP01)traceman.h
traceman.o: $(SP01)traceman.c $(SP01)traceman.h $(SP01)memory.h $(SP01)stdtypes.h
aedask.o:   $(SP01)aedask.c $(SP01)saisie.c
$(ABAL)/bin/aed64: ednoy.o edvideo.o traceman.o aedask.o $(LIBRARY) $(ALLOCATE) $(LIBACCESS)
	$(LD) $@ $?
	cp $@ $(EXABIN)
! make





