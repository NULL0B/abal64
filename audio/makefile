! include $(ABAL)/common/host.def

MASTER = abal3.2b.0.01

! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/libmp3.def

SP01 = $(ABAL)/src/blaster/
IP01 = $(ABAL)/src/mp3/include/

CC = $(GCC) -c $(CC_SHARED) -DABALAUDIO -DABALMP3 -g -I$(ABAL)/include/bdas/

$(SP01)audio.c: $(SP01)audio.def $(LINBDA)
	$(LINBDA) -bAUDIO32.$(MASTER) $(SP01)audio

! make

audio.o: $(SP01)audio.c
	$(CC) -DUNIX $(HOST) -DABAL32  $*

sb.o: $(SP01)sb.c
	$(CC) -DUNIX $(HOST) -DABAL32 -I$(IP01) $*

wavetool.o: $(SP01)wavetool.c
	$(CC) -DUNIX $(HOST) -DABAL32 -I$(IP01) $*

! make

$(ABAL)/lib/audio32.so: audio.o sb.o
	$(GCC) $(LD_SHARED) -o $@ $? $(LIBMP3) -lm
! ifdef BDATESTER32
	cp $@ $(EXALIB)/check32.so
	$(BDATESTER32) check
	rm $(EXALIB)/check32.so
! endif
	$(LIBREF) $@ $(EXALIB)/audio32.so

! make

$(ABAL)/bin/wavetool: wavetool.o 
	$(GCC) -o $@ $? $(LIBMP3) -lm
! make

! error oops

.as.at: 
	otr32 -m -I$(ABALINCLUDE)/ $*

example1.at: example1.as
example2.at: example2.as
example3.at: example3.as

