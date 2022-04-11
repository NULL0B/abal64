! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def

SP01 = $(ABAL)/src/fac/
IP01 = $(ABAL)/include/bdas/
IP02 = $(ABAL)/include/
IP03 = $(ABAL)/src/zgr/
GPP  = g++
POBJ =
WARNINGS = 
INCLUDE = -I$(SP01) -I$(IP01) -I$(IP02) -I$(IP03)
DEFINE  = $(HOST)

$(SP01)fac.c: $(SP01)fac.def $(LINBDA)
	$(LINBDA) -x -bFAC16.$(MASTER2) $(SP01)fac
! make

.c.o:
	-$(GCC) -c $(GDB) $(WARNINGS)  $(CC_SHARED) $(INCLUDE) $(DEFINE) $* $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

.cpp.o:
	-$(GPP) -c $(GDB) $(WARNINGS)  $(CC_SHARED) $(INCLUDE) $(DEFINE) $* $(PIPO)
! ifdef AGR
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



$(ABAL)/lib/fac.so: $(POBJ)fac.o $(POBJ)FacAbal.o '
       $(POBJ)fnconver.o '
       $(POBJ)IniLine.o  '
       $(POBJ)ToolAbal.o '
       $(POBJ)FacTrace.o '
       $(POBJ)SysAPI.o   '
       $(POBJ)FileAPI.o  '
       $(POBJ)StrmAPI.o  '
       $(POBJ)Strm.o
	$(GPP) $(LD_SHARED) $(GDB) -o $@ $?
! ifdef BDATESTER
	cp $@ $(EXALIB)/testfac.so
	$(BDATESTER) testfac
	rm $(EXALIB)/testfac.so
! endif
	$(LIBREF) $@ $(EXALIB)/fac.so

!make



