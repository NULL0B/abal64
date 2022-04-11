! include $(ABAL)/common/host.def
! include $(ABAL)/common/archive.def
! include $(ABAL)/common/agr.def
# ---------------------------------
# JPEG Image Loader Dynamic Library
# ---------------------------------
JPEGPATH = $(ABAL)/src/jpeg
JPEGINCL = -I$(JPEGPATH) -I$(ABAL)/src/pixel
JPEGEXCL = "-Zobsolete/*" "-Z*-mac-*" -zallocate.h
SP01     = $(JPEGPATH)/
LF       = .lf
MF       = .mf
ECHO     = echo
COMPILE  = $(GCC) -c -g $(GDB) -DUNIX $(HOST) -DABAL64 -DUSEIT -I$(ABAL)/include/
LINK     = $(GCC) 
POBJ     =
OBJ      = .o

.c.mf:
	genmake -m$@ -x $(JPEGINCL) $(JPEGEXCL) $?

jutils.mf:   $(JPEGPATH)/jutils.c
cdjpeg.mf:   $(JPEGPATH)/cdjpeg.c
jdapimin.mf: $(JPEGPATH)/jdapimin.c
jdapistd.mf: $(JPEGPATH)/jdapistd.c
jdatadst.mf: $(JPEGPATH)/jdatadst.c
jdatasrc.mf: $(JPEGPATH)/jdatasrc.c
jdcoefct.mf: $(JPEGPATH)/jdcoefct.c
jdcolor.mf:  $(JPEGPATH)/jdcolor.c
jddctmgr.mf: $(JPEGPATH)/jddctmgr.c
jdhuff.mf:   $(JPEGPATH)/jdhuff.c
jdinput.mf:  $(JPEGPATH)/jdinput.c
jdmainct.mf: $(JPEGPATH)/jdmainct.c
jdmarker.mf: $(JPEGPATH)/jdmarker.c
jdmaster.mf: $(JPEGPATH)/jdmaster.c
jdmerge.mf:  $(JPEGPATH)/jdmerge.c
jdphuff.mf:  $(JPEGPATH)/jdphuff.c
jdpostct.mf: $(JPEGPATH)/jdpostct.c
jdsample.mf: $(JPEGPATH)/jdsample.c
jidctflt.mf: $(JPEGPATH)/jidctflt.c
jidctfst.mf: $(JPEGPATH)/jidctfst.c
jidctint.mf: $(JPEGPATH)/jidctint.c
jidctred.mf: $(JPEGPATH)/jidctred.c
jquant1.mf:  $(JPEGPATH)/jquant1.c
jquant2.mf:  $(JPEGPATH)/jquant2.c
jmemmgr.mf:  $(JPEGPATH)/jmemmgr.c
jmemansi.mf: $(JPEGPATH)/jmemansi.c
jcomapi.mf:  $(JPEGPATH)/jcomapi.c
jerror.mf:   $(JPEGPATH)/jerror.c
jpeg.mf: $(JPEGPATH)/jpeg.c
! make
# required for writer
# -------------------
jpegrite.mf: $(JPEGPATH)/jpegrite.c
jcapimin.mf: $(JPEGPATH)/jcapimin.c
jcapistd.mf: $(JPEGPATH)/jcapistd.c
j.mf: $(JPEGPATH)/j.c
jcparam.mf:  $(JPEGPATH)/jcparam.c
jccoefct.mf: $(JPEGPATH)/jccoefct.c
jcmaster.mf: $(JPEGPATH)/jcmaster.c
jcinit.mf:  $(JPEGPATH)/jcinit.c
jchuff.mf:  $(JPEGPATH)/jchuff.c
jcphuff.mf:  $(JPEGPATH)/jcphuff.c
jccolor.mf:  $(JPEGPATH)/jccolor.c
jcmarker.mf:  $(JPEGPATH)/jcmarker.c
jcsample.mf: $(JPEGPATH)/jcsample.c
jcprepct.mf: $(JPEGPATH)/jcprepct.c
jcdctmgr.mf: $(JPEGPATH)/jcdctmgr.c
jcmainct.mf: $(JPEGPATH)/jcmainct.c
jfdctint.mf: $(JPEGPATH)/jfdctint.c
jfdctflt.mf: $(JPEGPATH)/jfdctflt.c
jfdctfst.mf: $(JPEGPATH)/jfdctfst.c
! make

.c.o:
! ifdef AGRZ
	-$(COMPILE) $(CC_SHARED) $(JPEGINCL) $* $(PIPO)
	cat pipo1 pipo2 > pipo
	$(AGR) -apipo
! else
	$(COMPILE) $(CC_SHARED) $(JPEGINCL) $* 
! endif
! ifndef SHARED_LIBRARIES
	$(REMOVE) $(ABAL)/lib/libjpeg.a $@
	$(ARCHIVE) $(ABAL)/lib/libjpeg.a $@
! endif

! include jutils
! include cdjpeg
! include jdapimin
! include jdapistd
! include jdatadst
! include jdatasrc
! include jdcoefct
! include jdcolor
! include jddctmgr
! include jdhuff
! include jdinput
! include jdmainct
! include jdmarker
! include jdmaster
! include jdmerge
! include jdphuff
! include jdpostct
! include jdsample
! include jidctflt
! include jidctfst
! include jidctint
! include jidctred
! include jquant1
! include jquant2
! include jmemmgr
! include jmemansi
! include jcomapi
! include jerror
! include jpeg
! make
! include jpegrite
! include jcapimin
! include jcapistd
! include jcparam
! include jcinit 
! include jchuff 
! include jcphuff
! include jccolor
! include jcmarker
! include jcmaster
! include jcsample
! include jcprepct
! include jcdctmgr
! include jccoefct
! include jcmainct
! include jfdctint
! include jfdctflt
! include jfdctfst
! include j
! make

! ifdef SHARED_LIBRARIES
$(ABAL)/lib/libjpeg64.so: jpeg.o '
       cdjpeg.o   jcomapi.o  jquant1.o  jquant2.o '
       jdapimin.o jdapistd.o jdatadst.o jdatasrc.o jdcoefct.o jdcolor.o '
       jddctmgr.o jdhuff.o   jdinput.o  jdmainct.o jdmarker.o jdmaster.o '
       jdmerge.o  jdphuff.o  jdpostct.o jdsample.o jerror.o   jidctflt.o '
       jidctfst.o jidctint.o jidctred.o jmemansi.o jmemmgr.o  jutils.o '
       jcapimin.o jcparam.o jcapistd.o jcmarker.o jcinit.o '
       jchuff.o jcphuff.o jcmaster.o jccolor.o jcsample.o jcprepct.o jcdctmgr.o '
       jccoefct.o jcmainct.o jfdctint.o jfdctflt.o jfdctfst.o jpegrite.o
	$(GCC) -g $(GDB) -o $@ $(LD_SHARED) $?
	echo LIBJPEG = $(ABAL)/lib/libjpeg64.so > $(ABAL)/common/jpeg.def
! make
! else
$(ABAL)/common/jpeg.def: $(ABAL)/lib/libjpeg.a
	echo LIBJPEG = $(ABAL)/lib/libjpeg.a > $(ABAL)/common/jpeg.def
! make
! endif
! shell @rm pipo* -f




