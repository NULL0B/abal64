SP01 = $(ABAL)/src/common/

.c.o:
	$(GCC) -c -g $(GDB) -fPIC -DABAL64 -DUNIX -Dunix $*


fnparser.o: $(SP01)fnparser.c
systemd.o: $(SP01)systemd.c
systeme.o: $(SP01)systeme.c
systemp.o: $(SP01)systemp.c
wildcomp.o: $(SP01)wildcomp.c

! make

