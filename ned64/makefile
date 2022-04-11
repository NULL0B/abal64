SHARED_EDITOR = TRUE

! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/ixciconr.def
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
! include $(ABAL)/common/grapil.def
! include $(ABAL)/common/stdprod.def
! include $(ABAL)/common/trace.def
! include $(ABAL)/common/rgraph.def
! include $(ABAL)/common/stdprod.def

$1 = TRUE

SP01 = $(ABAL)/src/ned/
SP02 = $(ABAL)/include/bdas/
SP03 = $(ABAL)/src/pixel/
SP04 = $(ABAL)/include/

CC = $(GCC) -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I$(SP03) -I$(SP04)
LD = $(GCC) -o

LIBREP = $(IXMISC) $(MISC) $(REPMISC) $(DIRMISC) 

! ifdef	SHARED_EDITOR
# ---------------------------------------------------------
# The Abal Editor Functions are in a Shared Overlay Package 
# ---------------------------------------------------------
$(SP01)bdaedit.c: $(SP01)bdaedit.def
# ---------------------------------------------------
#       first time only : creates the function stubs
# ---------------------------------------------------
#linbda -c$(SP01)nededit.c $(SP01)$(*B)
# ---------------------------------------------------
	linbda -bBdaEdit3.2a.0.01 $(SP01)$(*B)
	cp $* $(ABALINCLUDE)
! make


LIBRARY = $(PIXILIB) $(IXCICONR) $(XLIB) $(FNPARSER)
EDILIB  = $(ABAL)/lib/libedit64.so
TGTEDILIB  = $(ABAL)/lib/libedit64.so
AGR    = TRUE

.c.o:
! ifdef AGR
	-$(CC) $* 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(CC) $* 
! endif
! make

bdaedit.o:    $(SP01)bdaedit.c
! ifdef AGR
	-$(GCC) -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I$(SP03) -I$(SP02) $* > pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(GCC) -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I$(SP03) -I$(SP02) $*
! endif
! make

nededit.o:    $(SP01)nededit.c
! ifdef AGR
	-$(GCC) -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I$(SP03) -I$(SP02) $* > pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(GCC) -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I$(SP03) -I$(SP02) $* 
! endif
! make

! else
# -------------------------------------------------------------
# The Abal Editor Functions are Linked from the Archive Library
# -------------------------------------------------------------
LIBRARY = $(PIXILIB) $(IXCICONR) $(XLIB) $(FNPARSER) $(LIBREP)
LIBRARY = $(IXCICONR) $(FNPARSER) $(LIBREP)
EDILIB  = $(ABAL)/lib/editor.a
REMOVE  = ar d $(EDILIB)
ARCHIVE = ar q $(EDILIB)
AGR     = TRUE

.c.o:
! ifdef AGR
	-$(CC) $* $(PIPO)
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(CC) $* 
! endif
	$(REMOVE) $@
	$(ARCHIVE) $@

! endif

ednoy.o:    $(SP01)ednoy.c $(SP01)ed.h $(SP01)ednoy.h $(SP01)edmsg.h $(SP01)ednoy2.c $(SP01)traceman.h $(SP01)edwindow.c $(SP01)edrelief.c $(SP01)edsing.c
edvideo.o:  $(SP01)edvideo.c $(SP01)ed.h $(SP01)edvideo.h $(SP01)traceman.h
nogigo.o:  $(SP01)nogigo.c 
traceman.o: $(SP01)traceman.c $(SP01)traceman.h $(SP01)memory.h $(SP01)stdtypes.h
aedask.o:   $(SP01)aedask.c $(SP01)saisie.c

! make

! ifdef SHARED_EDITOR
$(TGTEDILIB): ednoy.o nogigo.o edvideo.o traceman.o aedask.o $(LIBREP)
	$(GCC) -g $(GDB) -o $@ -shared $? $(LIBLDAP)

! endif

! make

$(ABAL)/common/editor.def: $(EDILIB)
	echo EDILIB = $(EDILIB) > $@
! ifdef SHARED_EDITOR
	echo LIBREP = >> $@
! else
	echo LIBREP = $(LIBREP) >> $@
! endif

! make
.c.o:
	-$(CC) $* 1> pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

edmain.o:   $(SP01)edmain.c $(SP01)ed.h $(SP01)ednoy.h $(SP01)edmsg.h 
! ifdef AGR
	-$(CC) $* 1> pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(CC) $*
! endif

$(ABAL)/bin/aed64: edmain.o $(STDPROD) $(EDILIB) $(LIBRARY) $(ALLOCATE) $(LIBACCESS) $(VOBJECT) $(LIBIMAGE) $(LIBJPEG) $(TRACE) $(GRAPIL)
	$(LD) $@ $? $(LIBLDAP) 
! make

# Dynamic Library For Abal
# ------------------------
! include $(ABAL)/common/linbda.def


INCLUSION = -I$(SP01) -I$(SP02) -I$(SP03) -I$(SP04)
EXCLUSION = -zstdio.h -zstdlib.h -zmalloc.h
COMPILE = $(CC) $(GDB) -DVERSION666 -DUNIX -Dunix $(INCLUSION)

$(SP01)ieditor.c: $(SP01)editor.def $(LINBDA)
	$(LINBDA) -v -r$(SP01)ieditor -d -tEDITOR_TRACE -bEDITOR64.$(MASTER3) $(SP01)editor

! make

ieditor.o: $(SP01)ieditor.c
! ifdef AGR
	-$(COMPILE) $(SP01)ieditor.c 1> pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo
! else
	$(COMPILE) $(SP01)ieditor.c
! endif
! make


! ifdef	SHARED_EDITOR
$(ABAL)/lib/bdaedit64.so: bdaedit.o nededit.o ednoy.o edvideo.o traceman.o aedask.o $(LIBREP) $(RGRAPH) $(STDPROD) $(LIBIMAGE) $(ALLOCATE) $(FNPARSER) $(WILDCOMP) $(VOBJECT) $(TRACE) $(LIBACCESS) $(GRAPIL)
	$(GCC) -g $(GDB) -o $@ -shared $? $(LIBLDAP)
	cp $@ $(ABAL)/lib/testbdaedit64.so
	-bdatester64 testbdaedit
	rm $(ABAL)/lib/testbdaedit64.so
!endif

! make
! shell @rm pipo* -f

