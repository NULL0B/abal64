! include $(ABAL)/common/host.def

SP01 = $(ABAL)/src/assert/
SP02 = $(ABAL)/src/global/
SP03 = $(ABAL)/include/

INCLUDE = -I$(SP02) -I$(SP03)
DEFINE  = -DABAL21 -DAIX_VERS $(HOST)

slist.o: $(SP01)slist.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
snode.o: $(SP01)snode.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
excep.o: $(SP01)excep.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*
albox.o: $(SP01)albox.c
	$(GCC) -c -g $(GDB) $(DEFINE) $(INCLUDE) $*

! make

$(ABAL)/archive/assert.a: slist.o snode.o albox.o excep.o
	ar cr $@ $?
	echo LIBASSERT = $@ > $(ABAL)/common/libassert.def

! make
! shell @rm pipo* -f

