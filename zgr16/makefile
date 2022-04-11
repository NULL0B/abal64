
! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/grapil.def 
! include $(ABAL)/common/libimage.def
! include $(ABAL)/common/stdprod.def
! include $(ABAL)/common/rgraph.def 
! include $(ABAL)/common/linbda.def 
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/jpeg.def 

TARGET  = $(ABAL)/lib/zgr.so
POBJ    =
OBJ     = .o
MF01    = ./mf/
IP00    = $(ABAL)/src/zgr
IP01    = $(ABAL)/include/bdas
IP02    = $(ABAL)/include
IP03    = $(ABAL)/src/pixel
SP01    = $(IP00)/

DEFINE   =  -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC

EXCLUSION  = -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zVersion.rc -zutilzgrmain.h -zwincicoapi.h
INCLUSION = -I$(IP00) -I$(IP01) -I$(IP02) -I$(IP03)

$(SP01)z.c: $(SP01)z.def $(LINBDA)
	$(LINBDA) -bZGR16.$(MASTER2) $(SP01)$(@B)
! make
.c.mf:
	genmake -m$@ $(INCLUSION) $(EXCLUSION) -x $?


$(MF01)z.mf: $(SP01)z.c
$(MF01)vlink.mf: $(SP01)vlink.c
$(MF01)ztrace.mf: $(SP01)ztrace.c
$(MF01)ztools.mf: $(SP01)ztools.c
$(MF01)zlook.mf: $(SP01)zlook.c
$(MF01)jimage.mf: $(SP01)jimage.c
$(MF01)jlinuxmouse.mf: $(SP01)jlinuxmouse.c
$(MF01)vgrhold.mf: $(SP01)vgrhold.c
$(MF01)vthobase.mf: $(SP01)vthobase.c
$(MF01)zglobal.mf: $(SP01)zglobal.c
$(MF01)zabal.mf: $(SP01)zabal.c
$(MF01)zgraphic.mf: $(SP01)zgraphic.c
$(MF01)zgui.mf: $(SP01)zgui.c
$(MF01)zsys.mf: $(SP01)zsys.c
$(MF01)ztext.mf: $(SP01)ztext.c

! make 

.c.o:
	-$(GCC) -g -c $(GDB) $(CC_SHARED) $(INCLUSION) $(DEFINE) $* $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! include $(MF01)z
! include $(MF01)vlink 
! include $(MF01)ztrace
! include $(MF01)ztools
! include $(MF01)zlook 
! include $(MF01)jimage
! include $(MF01)jlinuxmouse
! include $(MF01)vgrhold 
! include $(MF01)vthobase
! include $(MF01)zglobal 
! include $(MF01)zabal 
! include $(MF01)zgraphic
! include $(MF01)zgui 
! include $(MF01)zsys 
! include $(MF01)ztext

! make 

$(TARGET): $(POBJ)z.o '
           $(POBJ)vlink.o  '
           $(POBJ)ztrace.o '
           $(POBJ)ztools.o '
           $(POBJ)zlook.o '
           $(POBJ)jimage.o '
           $(POBJ)jlinuxmouse.o '
           $(POBJ)vgrhold.o '
           $(POBJ)vthobase.o '
           $(POBJ)zglobal.o '
           $(POBJ)zabal.o '
           $(POBJ)zgraphic.o '
           $(POBJ)zgui.o '
           $(POBJ)zsys.o '
           $(POBJ)ztext.o '
           $(ALLOCATE) $(LIBIMAGE) $(STDPROD) $(LIBJPEG) $(RGRAPH)
	$(GCC) $(LD_SHARED) $(GDB) -o $@ $?
! ifdef BDATESTER
	cp $@ $(EXALIB)/testzgr.so
	$(BDATESTER) testzgr
	rm $(EXALIB)/testzgr.so 
! endif
	$(LIBREF) $@ $(EXALIB)/zgr.so
! make


