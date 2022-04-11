! include $(ABAL)/common/host.def
! include $(ABAL)/common/agr.def
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/ixciconr.def
! include $(ABAL)/common/libaccess.def

AO = $(EXABIN)/ao64

SP02 = $(ABAL)/src/exa/
SP01 = $(ABAL)/src/ao/

CC = $(GCC) 
CC_FLAGS =  $(GDB)
CC_INCLUDES =  -I$(ABAL)/include -I$(SP02) -I$(ABAL)/src/global
CC_DEFINES = -DABAL21 $(HOST) -DUNIX -DVERSION666 -DABAL64

LINKER = $(GCC) -g 
LINKER_FLAGS = 
LINKER_ENTRY = 
.c.o:
! ifdef	AGR
	-$(CC) -c $* $(CC_FLAGS) $(CC_DEFINES) $(CC_INCLUDES) $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(CC) -c $* $(CC_FLAGS) $(CC_DEFINES) $(CC_INCLUDES) 
! endif

idbcode.o: $(SP01)idbcode.c $(SP01)aotclist.c

ao.o: $(SP01)ao.c $(SP01)aoblock.h $(SP01)aogesmes.c $(SP01)aoglobal.h $(SP01)aomacro.h $(SP01)aomain.h $(SP01)aoproto.h $(SP01)aostat.h $(SP01)aotcngf.h $(SP01)aotcode.h
aomotor.o: $(SP01)aomotor.c $(SP01)aogesmes.c $(SP01)aoglobal.h $(SP01)aomacro.h $(SP01)aomain.h $(SP01)aoproto.h $(SP01)aoreg.h $(SP01)aostat.h $(SP01)aotcngf.h $(SP01)aotcode.h
aostruct.o: $(SP01)aostruct.c $(SP01)aoblock.h $(SP01)aomain.h $(SP01)aostream.h $(SP01)aostruct.h $(SP01)aotcngf.h $(SP01)aotcode.h
aojump.o: $(SP01)aojump.c $(SP01)aogesmes.c $(SP01)aoglobal.h $(SP01)aomacro.h $(SP01)aomain.h $(SP01)aoproto.h $(SP01)aostat.h $(SP01)aotcngf.h $(SP01)aotcode.h
aostat.o: $(SP01)aostat.c $(SP01)aomain.h $(SP01)aostat.h
aovarb.o: $(SP01)aovarb.c $(SP01)aogesmes.c $(SP01)aoglobal.h $(SP01)aomacro.h $(SP01)aomain.h $(SP01)aoproto.h $(SP01)aostat.h $(SP01)aotcngf.h $(SP01)aotcode.h
aomath.o: $(SP01)aomath.c $(SP01)aobib.h $(SP01)aomain.h $(SP01)aomath.h
aoreg.o: $(SP01)aoreg.c $(SP01)aomain.h $(SP01)aoreg.h $(SP01)aotcesc.h $(SP01)aotclen.h $(SP01)aotcngf.h $(SP01)aotcode.h
aotcode.o: $(SP01)aotcode.c $(SP01)aobib.h $(SP01)aoclftc.c $(SP01)aofmt.h $(SP01)aomain.h $(SP01)aomnem.h $(SP01)aostat.h $(SP01)aostream.h $(SP01)aostruct.h $(SP01)aotcesc.h $(SP01)aotclist.c $(SP01)aotcngf.h $(SP01)aotcode.h
aolist.o: $(SP01)aolist.c $(SP01)aolist.h $(SP01)aomain.h
aocopyat.o: $(SP01)aocopyat.c  $(SP01)aoblock.h $(SP01)aomain.h
aopannel.o: $(SP01)aopannel.c $(SP01)aopannel.h $(SP01)stdtypes.h
aolabel.o: $(SP01)aolabel.c $(SP01)aolabel.h $(SP01)aomain.h
aorecov.o: $(SP01)aorecov.c $(SP01)aomain.h $(SP01)aorecov.h
! make

aosymb.o: $(SP01)aosymb.c $(SP02)exdbsymb.c
aostream.o: $(SP01)aostream.c $(SP02)exdbstre.c
! make

$(ABAL)/bin/ao64: ao.o '
        aomotor.o aostruct.o aojump.o aostat.o aovarb.o '
        aomath.o aoreg.o aotcode.o aolist.o aocopyat.o aopannel.o '
        aolabel.o aorecov.o aosymb.o aostream.o '
        $(FNPARSER) $(WILDCOMP) $(IXCICONR) $(ALLOCATE) $(LIBACCESS)
	$(LINKER) -o $@ $(LINKER_ENTRY) $(LINKER_FLAGS) $?

! make
$(ABAL)/common/idbcode.def: $(ABAL)/ao64/idbcode.o 
	echo IDBCODE = $(ABAL)/ao64/idbcode.o > $(ABAL)/common/idbcode.def
! make
! shell @rm pipo* -f

