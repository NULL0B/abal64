! include /home/abal3/tools.mf

.as.at:
	$(otr) -m $*
	$(ao) -l$(@B)$(tc) $@
	$(avnor)  $(@B)$(tc) q/$(@B)$(tc)

abal3sct.as: makefile
	$(gabal) -s2000 $@
abal3pct.as: makefile
	$(gabal) -p4000 $@
abal3vct.as: makefile
	$(gabal) -v4000 $@
abal3cct.as: makefile
	$(gabal) -c6000 $@
abal3ict.as: makefile
	$(gabal) -i4000 $@
abal3xct.as: makefile
	$(gabal) -s1000 -p1000 -v1000 -c1000 -i50 $@
! make

abal3sct.at: abal3sct.as
abal3pct.at: abal3pct.as
abal3vct.at: abal3vct.as
abal3cct.at: abal3cct.as
abal3ict.at: abal3ict.as
abal3xct.at: abal3xct.as

! make

.as.at:
	$(otr) -m $*
	$(ao) -l$(@B)$(tc) $@
	$(avnor)  $(@B)$(tc) q/$(@B)$(tc)

conv.at: conv.as  
space.at: space.as
gener.at: gener.as
chr.at: chr.as
bcd.at: bcd.as
notegal.at: notegal.as
cfile.at: cfile.as
xcri.at: xcri.as
eventman.at: eventman.as
pointer.at: pointer.as
ofgosub.at: ofgosub.as
! make

.s.at:
	$(otr) -m $*
	$(ao) -l$(@B)$(tc) $@
	$(avnor)  $(@B)$(tc) q/$(@B)$(tc)

testatb.at:   testatb.s
testcfile.at: testcfile.s
testptr.at:   testptr.s
testsubs.at:  testsubs.s
testfix.at:  testfix.s
testfix2.at:  testfix2.s
testcalz.at:  testcalz.s
testvirt.at:  testvirt.s
testconva.at:  testconva.s
testprint1.at:  testprint1.s
qif.at:         qif.as
if.at: if.as
! make

# 32 bit translation only 
# -----------------------

.as.at:
	$(otr) -m $*
	$(ao) -l$(@B)$(tc) $@
	$(avnor)  $(@B)$(tc) q/$(@B)$(tc)

ldf.at: ldf.as
minus.at: minus.as
mvirt.at:  mvirt.as

! make

# Optimised External Fields Module linkage tester 
# -----------------------------------------------
qprogram.o: qprogram.as
	$(otr) -m $*
qmodule1.o: qmodule1.as
	$(otr) -m $*
qmodule2.o: qmodule2.as
	$(otr) -m $*

! make

qprogram.at: qprogram.o qmodule1.o qmodule2.o
	$(old) -m qprogram.o qmodule1.o qmodule2.o 
	$(ao) -l$(@B)$(tc) $@
	$(avnor)  $(@B)$(tc) q/$(@B)$(tc)

! make
	

