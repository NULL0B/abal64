! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/libimage.def
! include $(ABAL)/common/stdprod.def
! include $(ABAL)/common/common.def

SP01    = $(ABAL)/src/grasfun/
STUB    = asfun
XTRA    = -x -dTRACE_GRASFUN
INCLUDE = -I$(ABAL)/include/bdas/  -I$(ABAL)/src/pixel/ -I$(ABAL)/src/asfun/ -I$(ABAL)/src/sing/
VERSION = -DVERSION666 -DABAL32 -DABAL64
HOST    = -DUNIX -Dunix
COMPILE = gcc -c -g -ggdb -fPIC $(HOST) $(VERSION) $(INCLUDE)
RGRAPH  = $(ABAL)/pixel64/rgraph.o
AGR     = TRUE

$(SP01)i$(STUB).c: $(SP01)$(STUB).def
	linbda -bGrAsfun64 $(XTRA) -r$(SP01)i$(STUB) $(SP01)$(STUB)
! make

.c.o:
! ifdef AGR
	-$(COMPILE) $* > pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -a pipo
! else
	$(COMPILE) $* 

! endif

i$(STUB).o: $(SP01)i$(STUB).c
a$(STUB).o: $(SP01)a$(STUB).c

! make

SERVICES1 = $(ABAL)/asfun64/sfini.o $(ABAL)/asfun64/sfdyna.o $(ABAL)/asfun64/sfmd.o 
SERVICES2 = $(ABAL)/asfun64/wmem.o $(ABAL)/asfun64/xmouse.o $(ABAL)/asfun64/wlog.o 
SERVICES3 = $(ABAL)/asfun64/sfai.o
GENERAL  = $(FNPARSER) $(WILDCOMP) 
SERVICES = $(GENERAL)
STYLEMAN = $(ABAL)/pixel64/styleman.o 

.o.so:
	gcc -shared -o $@ $?
	cp $@ $(ABAL)/lib/test$(@B).so
	bdatester64 testgrasfun
	rm $(ABAL)/lib/test$(@B).so

$(ABAL)/lib/gr$(STUB)64.so: i$(STUB).o a$(STUB).o $(RGRAPH) $(SERVICES) $(STYLEMAN) $(STDPROD) $(LIBIMAGE) $(LIBACCESS)

! make
# shell @rm pipo* -f

