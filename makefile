! shell @echo Enter ABAL 64 Production
/home/abal64/bin/access -l
# ---------------------------
# ABAL 64 v 5.1a  Production
# ---------------------------
# Common Objects
# ---------------------------
! shell cd allocate;   $(MAKE)
! shell cd common;     $(MAKE)
! shell cd ixmisc;     $(MAKE)
! shell cd assert;     $(MAKE)
! shell cd prltra;     $(MAKE)
! shell cd cico;       $(MAKE)
! shell cd access64;   $(MAKE)
! shell cd linbda;     $(MAKE)
! shell cd ldfbda;     $(MAKE)
! shell cd printer;    $(MAKE) -a PASSONE
! shell cd exmafl;     $(MAKE)
! shell cd utmake;     $(MAKE)
! shell cd jpeg64;     $(MAKE)
! shell cd pixel64;    $(MAKE) -a PASSONE
! shell cd ned64;      $(MAKE) -a PASSONE
# ---------------------------
# development product modules
# ---------------------------
! shell cd agr64;      $(MAKE)
! shell cd otr64;      $(MAKE)
! shell cd old64;      $(MAKE)
! shell cd ao64;       $(MAKE)
# ---------------------------
# runtime product modules
# ---------------------------
! shell cd inxsql;     $(MAKE)
! shell cd exa64;      $(MAKE) -a PASSONE
! shell cd pixel64;    $(MAKE) -a PASSTWO
! shell cd abal64;     $(MAKE)
! shell cd ned64;      $(MAKE) -a PASSTWO
! shell cd exa64;      $(MAKE) -a PASSTWO
! shell cd printer;    $(MAKE) -a PASSTWO
! shell cd bibmath64;  $(MAKE)
! shell cd tty64;      $(MAKE)
! shell cd json64;     $(MAKE)
! shell cd asfun64;    $(MAKE)
! shell cd grasfun64;  $(MAKE)
! shell cd bdanet64;   $(MAKE)
! shell cd bdamail64;  $(MAKE)
! shell cd z64;        $(MAKE)
! shell cd zgr64;      $(MAKE)
! shell cd fac64;      $(MAKE)
! shell cd svrtsimc;   $(MAKE)
# shell cd grafabal64; $(MAKE)
# --------------------------
# end of production makefile
# --------------------------
! shell @echo Leave ABAL 64 Production
/home/abal64/bin/access -i
