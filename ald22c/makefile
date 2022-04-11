! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def

ABAL3 = $(ABAL)
ABAL2 = $(ABAL)

! include $(ABAL3)/common/allocate16.def
! include $(ABAL3)/common/common16.def
! include $(ABAL3)/common/libaccess16.def
! include $(ABAL3)/common/libassert.def
! include $(ABAL3)/common/ixciconr.def

SPECIAL = -DUNIX  $(HOST)

SP01 = $(ABAL2)/src/ald22c/
IP01 = $(ABAL)/include/

CC = -gcc
CC_FLAGS =  -g -ggdb    
CC_INCLUDES = -I$(ABAL)/src/global/ -I$(SP01) -I$(IP01)
CC_DEFINES = -DABAL21 -Dpilote -Dunix -Dver21 $(SPECIAL)

LINKER = gcc -g 

.h.o,.c.o:
	genmake -f -x -a $(CC_INCLUDES) $* > $(@B).mf 
	$(CC) -w -c $* $(CC_FLAGS) $(CC_DEFINES) $(CC_INCLUDES) $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

lkfile.o: $(SP01)lkfile.c $(SP01)lkdef.h 
lklib.o: $(SP01)lklib.c $(SP01)lkdef.h 
lkecran.o: $(SP01)lkecran.c $(SP01)lkdef.h 
lkmes.o: $(SP01)lkmes.c $(SP01)lkdef.h 
lkfich.o: $(SP01)lkfich.c $(SP01)lkdef.h 
lklist.o: $(SP01)lklist.c $(SP01)lkdef.h 
lkmain.o: $(SP01)lkmain.c $(SP01)lkdef.h 
lkdebug.o: $(SP01)lkdebug.c 
lksignal.o: $(SP01)lksignal.c
lktable.o: $(SP01)lktable.c $(SP01)lkdef.h 

! make
! echo IXCICONR = $(IXCICONR)

../bin/ald22c: lktable.o lkfile.o lklib.o lkecran.o lkmes.o lkfich.o '
        lklist.o lkmain.o lkdebug.o lksignal.o $(ALLOCATE) '
        $(LIBACCESS) $(WILDCOMP) $(IXCICONR) $(SYSTEME) $(LIBASSERT) $(FNPARSER)
	$(LINKER) -o $@ $?
	cp $@ $(EXABIN)
! make
! shell cat *.mf > liste


