! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def
SP01 = $(ABAL)/src/fac/
IP01 = $(ABAL)/include/bdas/
IP02 = $(ABAL)/include/
IP03 = $(ABAL)/src/zgr/

# -----------------------------------------------------------------------------------------
# hmmmmmmmmmm fucking fac ... only thing that uses C++ always causes problems when porting
# or just even recompiling on new versions of the system.
# found a hack to get around it on useit 3.1 D2 ( september 2009 ) the g++ compiler is used
# for the cpp objects and the link, and the standard gcc for the library interface/
# -----------------------------------------------------------------------------------------
GPP  = g++
GCC  = gcc
# -----------------------------------------------------------------------------------------
# all the rest is as usual 
# -----------------------------------------------------------------------------------------

POBJ =
WARNINGS = 
INCLUDE = -I$(SP01) -I$(IP01) -I$(IP02) -I$(IP03)
DEFINE  = -DVERSION666 $(HOST)

$(SP01)fac.c: $(SP01)fac.def $(LINBDA)
	$(LINBDA) -x -bFAC32.$(MASTER3) $(SP01)fac
! make

.c.o:
	-$(GCC) -c $(GDB) $(WARNINGS)  $(CC_SHARED) $(INCLUDE) $(DEFINE) $*  $(PIPO)
! ifdef AGRX
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif



.cpp.o:
	-$(GPP) -c $(GDB) $(WARNINGS)  $(CC_SHARED) $(INCLUDE) $(DEFINE) $*  $(PIPO)
! ifdef AGRX
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif




$(POBJ)fac.o:   $(SP01)fac.c
$(POBJ)FacAbal.o:   $(SP01)FacAbal.c
$(POBJ)fnconver.o:  $(SP01)fnconver.c
$(POBJ)IniLine.o:   $(SP01)IniLine.cpp
$(POBJ)ToolAbal.o:  $(SP01)ToolAbal.c
$(POBJ)FacTrace.o:  $(SP01)FacTrace.c
$(POBJ)SysAPI.o:    $(SP01)SysAPI.cpp
$(POBJ)FileAPI.o:   $(SP01)FileAPI.cpp
$(POBJ)StrmAPI.o:   $(SP01)StrmAPI.cpp
$(POBJ)Strm.o:      $(SP01)Strm.cpp
! make



$(ABAL)/lib/fac32.so: $(POBJ)fac.o $(POBJ)FacAbal.o '
       $(POBJ)fnconver.o '
       $(POBJ)IniLine.o  '
       $(POBJ)ToolAbal.o '
       $(POBJ)FacTrace.o '
       $(POBJ)SysAPI.o   '
       $(POBJ)FileAPI.o  '
       $(POBJ)StrmAPI.o  '
       $(POBJ)Strm.o
	$(GPP) $(LD_SHARED) $(GDB) -o $@ $?
! ifdef BDATESTER32
	cp $@ $(EXALIB)/testfac32.so
	$(BDATESTER32) testfac
	rm $(EXALIB)/testfac32.so
! endif
	$(LIBREF) $@ $(EXALIB)/fac32.so
!make



