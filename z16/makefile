! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/linbda.def 
! include $(ABAL)/common/allocate.def

TARGET  = $(ABAL)/lib/z.so
POBJ    =
OBJ     = .o
MF01    = ./mf/
IP00    = $(ABAL)/src/z
IP01    = $(ABAL)/include/bdas
IP02    = $(ABAL)/include
IP03    = $(ABAL)/src/zgr
IP04    = $(ABAL)/src/prltra
SP01    = $(IP00)/

DEFINE   = -Wall $(HOST) -DBDA_GNUC

EXCLUSION  = -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc
INCLUSION = -I$(IP00) -I$(IP01) -I$(IP02) -I$(IP03) -I$(IP04)

$(SP01)z.c: $(SP01)z.def $(LINBDA)
	$(LINBDA) -x -bZ16.$(MASTER2) $(SP01)$(@B)
! make
.c.mf:
	genmake -m$@ $(INCLUSION) $(EXCLUSION) -x $?


$(MF01)z.mf: $(SP01)z.c
$(MF01)zsoabal.mf: $(SP01)zsoabal.c
$(MF01)zsogui.mf: $(SP01)zsogui.c
$(MF01)zsosys.mf: $(SP01)zsosys.c
$(MF01)zsotxt.mf: $(SP01)zsotxt.c

! make 

.c.o:
	$(GCC) -g -c $(GDB) $(CC_SHARED) $(INCLUSION) $(DEFINE) $* $(PIPO)
! ifdef AGR
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! endif

! include $(MF01)z
! include $(MF01)zsoabal
! include $(MF01)zsogui
! include $(MF01)zsosys
! include $(MF01)zsotxt

! make 

$(TARGET): $(POBJ)z.o '
           $(POBJ)zsoabal.o '
           $(POBJ)zsogui.o '
           $(POBJ)zsosys.o '
           $(POBJ)zsotxt.o '
           $(ALLOCATE)
	$(GCC) $(LD_SHARED) $(GDB) -o $@ $?
! ifdef BDATESTER
	cp $@ $(EXALIB)/testz.so
	$(BDATESTER) testz
	rm $(EXALIB)/testz.so 
! endif
	$(LIBREF) $@ $(EXALIB)/z.so

! make


