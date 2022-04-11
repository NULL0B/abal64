! include $(ABAL)/common/host.def
! include $(ABAL)/common/rgraph.def
! include $(ABAL)/common/common.def
! include $(ABAL)/common/allocate16.def
! include $(ABAL)/common/libimage16.def
! include $(ABAL)/common/stdprod.def
! include $(ABAL)/common/linbda.def
! include $(ABAL)/common/jpeg16.def
! include $(ABAL)/common/ldap.def

SP01 = $(ABAL)/src/grafabal/
SP02 = $(ABAL)/src/grafabal/grafabal/
SP03 = $(ABAL)/src/grafabal/grafabal/abal/
IP01 = $(ABAL)/include/bdas
IP02 = $(ABAL)/src/sing

$(SP01)grabal.c: $(SP01)grafabal.def $(LINBDA)
	$(LINBDA) -r$(SP01)grabal -d -tTRACE_GRAFABAL -bGRAFABAL16.$(MASTER2) $(SP01)grafabal

! make

.c.o:
	-$(GCC) -c -g $(GDB) -DUNIX $(HOST) -I$(IP01) $* 1>pipo1 2>pipo2
	cat pipo1 pipo2 > pipo
	agr -apipo

grabal.o: $(SP01)grabal.c

! make

! include grafabal.mf
! make
! shell -@rm pipo*

