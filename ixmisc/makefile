! include $(ABAL)/common/host.def

SP01 = $(ABAL)/src/ixmisc/
SP02 = $(ABAL)/src/global/
SP03 = $(ABAL)/include/

INCLUDE = -I$(SP02) -I$(SP03)
DEFINE  = -DABAL21 -DAIX_VERS $(HOST)

dir.o: $(SP01)dir.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
ixmisc.o: $(SP01)ixmisc.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
misc.o: $(SP01)misc.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
repmisc.o: $(SP01)repmisc.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*

! make

$(ABAL)/archive/dirmisc.a: dir.o
	ar cr $@ $?
	echo DIRMISC = $@ > $(ABAL)/common/dirmisc.def

$(ABAL)/archive/ixmisc.a: ixmisc.o
	ar cr $@ $?
	echo IXMISC = $@ > $(ABAL)/common/ixmisc.def

$(ABAL)/archive/misc.a: misc.o
	ar cr $@ $?
	echo MISC = $@ > $(ABAL)/common/misc.def

$(ABAL)/archive/repmisc.a: repmisc.o
	ar cr $@ $?
	echo REPMISC = $@ > $(ABAL)/common/repmisc.def


! make
! shell @rm pipo* -f
