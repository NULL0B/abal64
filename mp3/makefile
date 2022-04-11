SP01 = $(ABAL)/src/mp3/
IP01 = $(SP01)include/
.c.o: 
	-$(GCC) -g -ggdb -c -DUNIX -I$(IP01) $* 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr32 -apipo

bstream.o: $(SP01)bstream.c
fdct.o: $(SP01)fdct.c
imdct.o: $(SP01)imdct.c
l1dec.o: $(SP01)l1dec.c
l1init.o: $(SP01)l1init.c
l2dec.o: $(SP01)l2dec.c
l2init.o: $(SP01)l2init.c
l3alias.o: $(SP01)l3alias.c
l3dec.o: $(SP01)l3dec.c
l3huff.o: $(SP01)l3huff.c
l3hybrid.o: $(SP01)l3hybrid.c
l3init.o: $(SP01)l3init.c
l3msis.o: $(SP01)l3msis.c
l3quant.o: $(SP01)l3quant.c
l3sf.o: $(SP01)l3sf.c
l3side.o: $(SP01)l3side.c
mp3dec.o: $(SP01)mp3dec.c
sbtb.o: $(SP01)sbtb.c
sbt.o: $(SP01)sbt.c
windowb.o: $(SP01)windowb.c
window.o: $(SP01)window.c
mp3test.o: $(SP01)mp3test.c

! make

$(ABAL)/lib/libmp3.a: 
bstream.o
fdct.o '
imdct.o '
l1dec.o '
l1init.o '
l2dec.o '
l2init.o '
l3alias.o '
l3dec.o '
l3huff.o '
l3hybrid.o '
l3init.o '
l3msis.o '
l3quant.o '
l3sf.o '
l3side.o '
mp3dec.o '
sbtb.o '
sbt.o '
windowb.o '
window.o 
	ar -ru $@ $?
	echo LIBMP3 = $@ > $(ABAL)/common/libmp3.def

! make
! error mp3 library ok
! include $(ABAL)/common/libmp3.def

mp3test: mp3test.o $(LIBMP3)
	gcc -g -ggdb -o $@ $? -lm

! make

