! include $(ABAL)/common/host.def
! make
$(ABAL)/bin/linbda: $(ABAL)/src/linbda/linbda.c
	$(GCC) -g -o $@ -DUNIX -Dunix $*
	echo LINBDA = $(ABAL)/bin/linbda > $(ABAL)/common/linbda.def
! make
! shell @rm pipo* -f

