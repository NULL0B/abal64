! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/ixciconr64.def
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/pixilib.def
! include $(ABAL)/common/ixmisc.def 
! include $(ABAL)/common/repmisc.def 
! include $(ABAL)/common/dirmisc.def 
! include $(ABAL)/common/misc.def 
! include $(ABAL)/common/jpeg.def 
! include $(ABAL)/common/ldap.def 
! include $(ABAL)/common/vobject.def
! include $(ABAL)/common/libimage.def
! include $(ABAL)/common/stdprod.def
! include $(ABAL)/common/trace.def

SP01 = $(ABAL)/src/abal/
SP02 = $(ABAL)/include/bdas/
SP03 = $(ABAL)/src/pixel/

CC = $(GCC) -c -g $(HOST) -DHX -Dver2K -Dver21 -DLINT_ARGS -DUSEIT -DVERSION666 -I$(SP03)
LD = $(GCC) -o

REPLIB  = $(IXMISC) $(MISC) $(REPMISC) $(DIRMISC) 
SYSLIB  = $(SYSTEMD) $(STDPROD) $(FNPARSER) $(ALLOCATE) $(LIBACCESS) 
GRLIB   =  $(PIXILIB) $(IXCICONR64) $(XLIB) $(VOBJECT) $(LIBIMAGE) $(LIBJPEG)


.c.o:
	-$(CC) $(CC_SHARED) $* $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo

abal.o: $(SP01)/abal.c
misc.o: $(SP01)/misc.c
iboite.o: $(SP01)/iboite.c
saisie.o: $(SP01)/saisie.c

$(ABAL)/bin/abal: abal.o misc.o iboite.o saisie.o $(SYSLIB) $(REPLIB) $(GRLIB) $(TRACE)
	$(LD) $@ $? -lldap
	cp $@ $(EXABIN)
! make

	



