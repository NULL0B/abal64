! include $(ABAL)/common/common.def

SP01    = $(ABAL)/src/md5
IP01    = $(ABAL)/include/bdas/
GCC     = gcc -g -ggdb 
DEFINE  = -DUNIX -Dunix -DVERSION666 -I$(IP01)
 
$(SP01)/bdamd5.c: $(SP01)/bdamd5.def
	linbda -bBdaMd532.$(MASTER3) $(SP01)/bdamd5

! make

bdamd5.o: $(SP01)/bdamd5.c
	$(GCC) -c $(DEFINE) $*

md5abal.o: $(SP01)/md5abal.c
	$(GCC) -c $(DEFINE) $* 

! make

$(ABAL)/lib/bdamd532.so: bdamd5.o md5abal.o
	$(GCC) -shared -o $@ $?
	cp $@ /lib
	bdatester32 bdamd5
! make
testmd5.at: testmd5.as
	otr32 -m testmd5.as
! make
md5c.o: md5c.c md5.h global.h
	gcc -g -c md5c.c
mddriver.o: mddriver.c
	gcc -g -c mddriver.c
! make
qmd5: md5c.o mddriver.o
	gcc -o $@ $?
! make


