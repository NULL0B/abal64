! include $(ABAL)/common/host.def
VERSION666 = -DVERSION666
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/allocate.def

MACHIN = machin
SP02 = $(ABAL)/include/bdas/
SP01 = $(ABAL)/src/asfun/
CC_DEFINES = -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS $(HOST) -Dunix -Dver14 $(CC_SHARED) 
COMPILER   = $(GCC) -c -g $(VERSION666)

.c.o:
	-$(COMPILER) $(GDB) -I$(SP02) $(CC_DEFINES) $* 1> pipo1 2> pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

wini.o: $(SP01)wini.c
wcreat.o: $(SP01)wcreat.c 
wwrite.o: $(SP01)wwrite.c
wvis.o: $(SP01)wvis.c
wgen.o: $(SP01)wgen.c
winfo.o: $(SP01)winfo.c
wrequi.o: $(SP01)wrequi.c
wmem.o: $(SP01)wmem.c 
wmove.o: $(SP01)wmove.c 
wombre.o: $(SP01)wombre.c
sfini.o: $(SP01)sfini.c    
sfls.o: $(SP01)sfls.c 
sfbv.o: $(SP01)sfbv.c  
sfld.o: $(SP01)sfld.c $(SP02)bda.h    
sfai.o: $(SP01)sfai.c  
sfsai.o: $(SP01)sfsai.c  
sfmd.o: $(SP01)sfmd.c $(SP02)bda.h   
runco.o: $(SP01)runco.c
sftch.o: $(SP01)sftch.c 
mv2_14.o: $(SP01)mv2_14.c   
sfbd.o: $(SP01)sfbd.c   
sfdyna.o: $(SP01)sfdyna.c 
t_el_bd.o: $(SP01)t_el_bd.c  
wcadre.o: $(SP01)wcadre.c $(SP02)bda.h 
wscroll.o: $(SP01)wscroll.c 
xmouse.o: $(SP01)xmouse.c $(SP02)bda.h  
bsamf.o: $(SP01)bsamf.c $(SP02)bda.h 
$(MACHIN).o: $(SP01)$(MACHIN).c $(SP02)ldfbda.h

wlog.o: $(SP01)wlog.c

! make
LINKER = $(GCC) -o
LINKER_FLAGS = $(LD_SHARED)


$(ABAL)/lib/asfun32.so:  wini.o wcreat.o wwrite.o wvis.o wgen.o winfo.o wrequi.o wmem.o wmove.o wombre.o sfini.o sfls.o sfbv.o sfld.o sfai.o sfsai.o sfmd.o runco.o sftch.o mv2_14.o sfbd.o sfdyna.o t_el_bd.o wcadre.o wscroll.o xmouse.o bsamf.o $(MACHIN).o $(ALLOCATE)
	$(LINKER) $@ $(LINKER_FLAGS) $? $(LIBACCESS)
! ifdef BDATESTER32
	cp $@ $(EXALIB)/checkasfun32.so
	$(BDATESTER32) checkasfun
	rm $(EXALIB)/checkasfun32.so
! endif
	$(LIBREF) $@ $(EXALIB)/asfun32.so
! make

