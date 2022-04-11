! include $(ABAL)/common/ixciconr32.def
! include $(ABAL)/common/libaccess.def
! include $(ABAL)/common/allocate.def

ciconv: ciconv.c
	gcc -g -ggdb -o $@ $* $(IXCICONR32) $(LIBACCESS) $(ALLOCATE)
! make
capture: capture.c
	gcc -g -ggdb -o capture capture.c
	cp capture $(ABAL)/bin
	cp capture /opt/prologue/bin
! make
replay: replay.c
	gcc -g -ggdb -o replay replay.c
	cp replay $(ABAL)/bin
	cp replay /opt/prologue/bin
! make


! shell cd $(ABAL)/cico; $(MAKE)

