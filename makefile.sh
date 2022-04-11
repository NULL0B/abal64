gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb /home/abal64/src/allocate/allocate.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr
gcc -fPIC -O0 -o /home/abal64/lib/allocate64.so -shared  -g -ggdb allocate.o
echo ALLOCATE = /home/abal64/lib/allocate64.so > /home/abal64/common/allocate64.def
echo ALLOCATE = /home/abal64/lib/allocate64.so > /home/abal64/common/allocate.def
rm pipo* -f
gcc -c -g -g -ggdb -fPIC -DABAL64 -DUNIX -Dunix /home/abal64/src/common/fnparser.c
gcc -c -g -g -ggdb -fPIC -DABAL64 -DUNIX -Dunix /home/abal64/src/common/systemd.c
gcc -c -g -g -ggdb -fPIC -DABAL64 -DUNIX -Dunix /home/abal64/src/common/systeme.c
gcc -c -g -g -ggdb -fPIC -DABAL64 -DUNIX -Dunix /home/abal64/src/common/systemp.c
gcc -c -g -g -ggdb -fPIC -DABAL64 -DUNIX -Dunix /home/abal64/src/common/wildcomp.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/ixmisc/dir.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/ixmisc/ixmisc.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/ixmisc/misc.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/ixmisc/repmisc.c
ar cr /home/abal64/archive/dirmisc.a dir.o
echo DIRMISC = /home/abal64/archive/dirmisc.a > /home/abal64/common/dirmisc.def
ar cr /home/abal64/archive/ixmisc.a ixmisc.o
echo IXMISC = /home/abal64/archive/ixmisc.a > /home/abal64/common/ixmisc.def
ar cr /home/abal64/archive/misc.a misc.o
echo MISC = /home/abal64/archive/misc.a > /home/abal64/common/misc.def
ar cr /home/abal64/archive/repmisc.a repmisc.o
echo REPMISC = /home/abal64/archive/repmisc.a > /home/abal64/common/repmisc.def
rm pipo* -f
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/assert/slist.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/assert/snode.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/assert/excep.c
gcc -fPIC -O0 -c -g -g -ggdb -DABAL21 -DAIX_VERS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/src/global/ -I/home/abal64/include/ /home/abal64/src/assert/albox.c
ar cr /home/abal64/archive/assert.a slist.o snode.o albox.o excep.o
echo LIBASSERT = /home/abal64/archive/assert.a > /home/abal64/common/libassert.def
rm pipo* -f
gcc -c -DUNIX -DABAL64 -I/home/abal64/include/bdas/ -I/home/abal64/src/common/ -I/home/abal64/include/ -g -g -ggdb /home/abal64/src/prltra/tramain.c 1>pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -c -DUNIX -DABAL64 -I/home/abal64/include/bdas/ -I/home/abal64/src/common/ -I/home/abal64/include/ -g -g -ggdb /home/abal64/src/prltra/tractx.c 1>pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -c -DUNIX -DABAL64 -I/home/abal64/include/bdas/ -I/home/abal64/src/common/ -I/home/abal64/include/ -g -g -ggdb /home/abal64/src/common/toolabal.c 1>pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -c -DUNIX -DABAL64 -I/home/abal64/include/bdas/ -I/home/abal64/src/common/ -I/home/abal64/include/ -g -g -ggdb /home/abal64/include/trace.c 1>pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo TRACE = /home/abal64/prltra/trace.o > /home/abal64/common/trace.def
rm pipo* -f
gcc -fPIC -O0 -c   -g -ggdb      -DABAL21 -DABALCONF -DENFORCED_CONSTANTS -DAIX_VERS -DCICO_BDA -DEXABAL -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/ixcico.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c   -g -ggdb      -DABAL21 -DABALCONF -DENFORCED_CONSTANTS -DAIX_VERS -DCICO_BDA -DEXABAL -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/ixcico64.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo LIBCICO = /home/abal64/cico/ixcico64.o > /home/abal64/common/libcico.def
gcc -fPIC -O0 -c -fPIC -O0   -g -ggdb      -DABAL21 -DABALCONF -DENFORCED_CONSTANTS -DAIX_VERS -DCICO_BDA -DEXABAL -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/libprint.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -fPIC -O0   -g -ggdb      -DABAL21 -DABALCONF -DENFORCED_CONSTANTS -DAIX_VERS -DCICO_BDA -DEXABAL -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/libprint64.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -ggdb -o /home/abal64/lib/libprint64.so -shared libprint64.o /home/abal64/lib/allocate64.so
echo LIBPRINT = /home/abal64/lib/libprint64.so > /home/abal64/common/libprint.def
gcc -fPIC -O0 -c   -g -ggdb      -DABAL21 -DABALCONF -DAIX_VERS -DCICO_BDA -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/ixciconr.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo IXCICONR = /home/abal64/cico/ixciconr.o > /home/abal64/common/ixciconr.def
gcc -fPIC -O0 -c   -g -ggdb      -DABAL21 -DABALCONF -DAIX_VERS -DCICO_BDA -DIDIRECT -DIMPLOC -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DNPOS_SYSTEM_V -DSHAREDLO -DSVR4_TEMPO -DTEMPO=0 -DXENIX386 -Dunix -DLIBPRINT -DUNIX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  -I/home/abal64/include /home/abal64/src/cico/ixciconr64.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo IXCICONR64 = /home/abal64/cico/ixciconr64.o > /home/abal64/common/ixciconr64.def
gcc -fPIC -O0 -g -ggdb -o /home/abal64/lib/libprint.so -shared libprint.o /home/abal64/lib/allocate64.so
echo LIBPRINT = /home/abal64/lib/libprint.so > /home/abal64/common/libprint16.def
rm pipo* -f
gcc -fPIC -O0 -c -g -ggdb -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DVERSION666 -DUNIX -Dx8086 /home/abal64/src/access//coexa.c > pipo 2> pipo
gcc -fPIC -O0 -c -g -ggdb -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DVERSION666 -DUNIX -Dx8086 /home/abal64/src/access//exlock.c > pipo 2> pipo
gcc -fPIC -O0 -c -g -ggdb -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DVERSION666 -DUNIX -Dx8086 /home/abal64/src/access//exdaemon.c > pipo 2> pipo
gcc -fPIC -O0 -c -g -ggdb -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DVERSION666 -DUNIX -Dx8086 /home/abal64/src/access//exetat.c > pipo 2> pipo
gcc -fPIC -O0 -c -g -ggdb -DNOACCESS -DABAL21 -DABALSP -DAIX_VERS -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DVERSION666 -DUNIX -Dx8086 /home/abal64/src/access//stdsignal.c > pipo 2> pipo
gcc -fPIC -O0 -g -o /home/abal64/bin/access coexa.o exlock.o exdaemon.o exetat.o stdsignal.o
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DNOACCESS -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  /home/abal64/src/access//exaccess.c 
gcc -fPIC -O0 -g -g -ggdb -shared -o /home/abal64/lib/libaccess64.so  exaccess.o
echo LIBACCESS = /home/abal64/lib/libaccess64.so   > /home/abal64/common/libaccess.def
echo OBJACCESS = /home/abal64/access64/exaccess.o >> /home/abal64/common/libaccess.def
rm pipo* -f
gcc -fPIC -O0 -g -o /home/abal64/bin/linbda -DUNIX -Dunix /home/abal64/src/linbda/linbda.c
echo LINBDA = /home/abal64/bin/linbda > /home/abal64/common/linbda.def
rm pipo* -f
gcc -fPIC -O0 -c -g -I/home/abal64/include/bdas/ -DUNIX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -DVERSION666 -DABAL64 -DABALDEBIAN /home/abal64/src/ldfbda/exbda64.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo LIBBDA = /home/abal64/ldfbda/exbda64.o > /home/abal64/common/libbda.def
gcc -fPIC -O0 -c -g -I/home/abal64/include/bdas/ -DUNIX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -DVERSION666 -DABAL64 -DABALDEBIAN /home/abal64/src/ldfbda/testbda64.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -ggdb  -o /home/abal64/bin/bdatester64 testbda64.o /home/abal64/lib/allocate64.so /usr/lib/x86_64-linux-gnu/libdl.so
gcc -fPIC -O0 -g -ggdb  -o /home/abal64/bin/bdapreload /home/abal64/src/ldfbda/bdapreload.c > pipo 2> pipo
rm pipo* -f
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/paper.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo PAPER = $ABAL/printer/paper.o > $ABAL/common/paper.def 
gcc -fPIC -O0 -c -g -g -ggdb  -DABAL21 -DAIX_VERS -DC_ISAM_410 -DINXSQL -DISINTEL -DISUNIX -DIX386 -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL64 -DVERSION666 -DUSEIT -DCRIVER40 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64  /home/abal64/src/exmafl/exma.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -fPIC -O0  -DABAL21 -DAIX_VERS -DC_ISAM_410 -DINXSQL -DISINTEL -DISUNIX -DIX386 -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL64 -DVERSION666 -DUSEIT -DCRIVER40 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64   /home/abal64/src/exmafl/flfile.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
ar cr /home/abal64/archive/exmafl.a exma.o
echo LIBMAFL = /home/abal64/archive/exmafl.a > /home/abal64/common/libmafl.def
gcc -fPIC -O0 -g -g -ggdb -shared -o /home/abal64/lib/libflfile64.so flfile.o
echo LIBFLFILE = /home/abal64/lib/libflfile64.so  > /home/abal64/common/libflfile.def
rm pipo* -f
genmake -mjutils.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jutils.c
genmake -mcdjpeg.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/cdjpeg.c
genmake -mjdapimin.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdapimin.c
genmake -mjdapistd.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdapistd.c
genmake -mjdatadst.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdatadst.c
genmake -mjdatasrc.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdatasrc.c
genmake -mjdcoefct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdcoefct.c
genmake -mjdcolor.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdcolor.c
genmake -mjddctmgr.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jddctmgr.c
genmake -mjdhuff.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdhuff.c
genmake -mjdinput.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdinput.c
genmake -mjdmainct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdmainct.c
genmake -mjdmarker.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdmarker.c
genmake -mjdmaster.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdmaster.c
genmake -mjdmerge.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdmerge.c
genmake -mjdphuff.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdphuff.c
genmake -mjdpostct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdpostct.c
genmake -mjdsample.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jdsample.c
genmake -mjidctflt.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jidctflt.c
genmake -mjidctfst.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jidctfst.c
genmake -mjidctint.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jidctint.c
genmake -mjidctred.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jidctred.c
genmake -mjquant1.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jquant1.c
genmake -mjquant2.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jquant2.c
genmake -mjmemmgr.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jmemmgr.c
genmake -mjmemansi.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jmemansi.c
genmake -mjcomapi.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcomapi.c
genmake -mjerror.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jerror.c
genmake -mjpeg.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jpeg.c
genmake -mjpegrite.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jpegrite.c
genmake -mjcapimin.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcapimin.c
genmake -mjcapistd.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcapistd.c
genmake -mj.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/j.c
genmake -mjcparam.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcparam.c
genmake -mjccoefct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jccoefct.c
genmake -mjcmaster.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcmaster.c
genmake -mjcinit.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcinit.c
genmake -mjchuff.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jchuff.c
genmake -mjcphuff.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcphuff.c
genmake -mjccolor.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jccolor.c
genmake -mjcmarker.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcmarker.c
genmake -mjcsample.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcsample.c
genmake -mjcprepct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcprepct.c
genmake -mjcdctmgr.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcdctmgr.c
genmake -mjcmainct.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jcmainct.c
genmake -mjfdctint.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jfdctint.c
genmake -mjfdctflt.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jfdctflt.c
genmake -mjfdctfst.mf -x -I/home/abal64/src/jpeg -I/home/abal64/src/pixel "-Zobsolete/*" "-Z*-mac-*" -zallocate.h /home/abal64/src/jpeg/jfdctfst.c
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jutils.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/cdjpeg.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdapimin.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdapistd.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdatadst.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdatasrc.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdcoefct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdcolor.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jddctmgr.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdhuff.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdinput.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdmainct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdmarker.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdmaster.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdmerge.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdphuff.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdpostct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jdsample.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jidctflt.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jidctfst.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jidctint.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jidctred.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jquant1.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jquant2.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jmemmgr.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jmemansi.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcomapi.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jerror.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jpeg.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jpegrite.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcapimin.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcapistd.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcparam.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcinit.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jchuff.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcphuff.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jccolor.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcmarker.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcmaster.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcsample.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcprepct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcdctmgr.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jccoefct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jcmainct.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jfdctint.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jfdctflt.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/jfdctfst.c 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUSEIT -I/home/abal64/include/ -fPIC -O0  -I/home/abal64/src/jpeg -I/home/abal64/src/pixel /home/abal64/src/jpeg/j.c 
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/lib/libjpeg64.so -shared jpeg.o cdjpeg.o jcomapi.o jquant1.o jquant2.o jdapimin.o jdapistd.o jdatadst.o jdatasrc.o jdcoefct.o jdcolor.o jddctmgr.o jdhuff.o jdinput.o jdmainct.o jdmarker.o jdmaster.o jdmerge.o jdphuff.o jdpostct.o jdsample.o jerror.o jidctflt.o jidctfst.o jidctint.o jidctred.o jmemansi.o jmemmgr.o jutils.o jcapimin.o jcparam.o jcapistd.o jcmarker.o jcinit.o jchuff.o jcphuff.o jcmaster.o jccolor.o jcsample.o jcprepct.o jcdctmgr.o jccoefct.o jcmainct.o jfdctint.o jfdctflt.o jfdctfst.o jpegrite.o
echo LIBJPEG = /home/abal64/lib/libjpeg64.so > /home/abal64/common/jpeg.def
rm pipo* -f
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/console.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  console.o
ar q /home/abal64/archive/libpixel.a console.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/stdgigo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  stdgigo.o
ar q /home/abal64/archive/libpixel.a stdgigo.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/stdevent.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  stdevent.o
ar q /home/abal64/archive/libpixel.a stdevent.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/inipixel.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  inipixel.o
ar q /home/abal64/archive/libpixel.a inipixel.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/filzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  filzone.o
ar q /home/abal64/archive/libpixel.a filzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/xorzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  xorzone.o
ar q /home/abal64/archive/libpixel.a xorzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/putzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  putzone.o
ar q /home/abal64/archive/libpixel.a putzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/mixzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  mixzone.o
ar q /home/abal64/archive/libpixel.a mixzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/movezone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  movezone.o
ar q /home/abal64/archive/libpixel.a movezone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/shadzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  shadzone.o
ar q /home/abal64/archive/libpixel.a shadzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/putch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  putch.o
ar q /home/abal64/archive/libpixel.a putch.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/mixch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  mixch.o
ar q /home/abal64/archive/libpixel.a mixch.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/getzone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  getzone.o
ar q /home/abal64/archive/libpixel.a getzone.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/setmouse.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  setmouse.o
ar q /home/abal64/archive/libpixel.a setmouse.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/stdpsu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  stdpsu.o
ar q /home/abal64/archive/libpixel.a stdpsu.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/relief.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  relief.o
ar q /home/abal64/archive/libpixel.a relief.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/xgraph.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  xgraph.o
ar q /home/abal64/archive/libpixel.a xgraph.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/drawline.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  drawline.o
ar q /home/abal64/archive/libpixel.a drawline.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/circle.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  circle.o
ar q /home/abal64/archive/libpixel.a circle.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/rounded.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  rounded.o
ar q /home/abal64/archive/libpixel.a rounded.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 -I/home/abal64/src/pixel/  /home/abal64/src/pixel/image.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo /home/abal64/archive/libpixel.a
ar d /home/abal64/archive/libpixel.a  image.o
ar q /home/abal64/archive/libpixel.a image.o
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -DUNIX -Dunix -I/home/abal64/include/ -DVERSION666 -DABAL64 /home/abal64/src/pixel/rgraph.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo CONSOLE = /home/abal64/pixel64/console.o > /home/abal64/common/console.def
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zico.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zpng.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zbmp.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zgif.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zjpeg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zimage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/zvga.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL /home/abal64/src/pixel/grapil.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
ar -ru /home/abal64/archive/grapil.a grapil.o zvga.o zimage.o zbmp.o zico.o zpng.o zgif.o zjpeg.o
echo GRAPIL = /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 > /home/abal64/common/grapil.def
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -g -ggdb -DVERSION666 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/src/jpeg/ /home/abal64/src/sing/vcapture.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -ggdb -shared -o /home/abal64/lib/libimage64.so vcapture.o grapil.o zvga.o zimage.o zbmp.o zico.o zpng.o zgif.o zjpeg.o /home/abal64/lib/libjpeg64.so
echo  LIBIMAGE = /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16> /home/abal64/common/libimage.def
gcc -fPIC -O0 -c -g -g -ggdb  -DVERSION666 -DABAL64 -I/home/abal64/include/ -g -ggdb -DVERSION666 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/src/jpeg/ /home/abal64/src/sing/stdprod.c 1>pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo STDPROD = /home/abal64/pixel64/stdprod.o > /home/abal64/common/stdprod.def
linbda -bBdaEdit3.2a.0.01 /home/abal64/src/ned/bdaedit
cp /home/abal64/src/ned/bdaedit.def /home/abal64/include
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/bdas/ /home/abal64/src/ned/bdaedit.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/bdas/ /home/abal64/src/ned/nededit.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/ednoy.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/edvideo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/nogigo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/traceman.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/aedask.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/lib/libedit64.so -shared ednoy.o nogigo.o edvideo.o traceman.o aedask.o /home/abal64/archive/ixmisc.a /home/abal64/archive/misc.a /home/abal64/archive/repmisc.a /home/abal64/archive/dirmisc.a -lldap
echo EDILIB = /home/abal64/lib/libedit64.so > /home/abal64/common/editor.def
echo LIBREP = >> /home/abal64/common/editor.def
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/edmain.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -o /home/abal64/bin/aed64 edmain.o /home/abal64/pixel64/stdprod.o /home/abal64/lib/libedit64.so /home/abal64/archive/libpixel.a /home/abal64/cico/ixciconr.o /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so /home/abal64/pixel64/vobject.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/libjpeg64.so /home/abal64/prltra/trace.o /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 -lldap 
/home/abal64/bin/linbda -v -r/home/abal64/src/ned/ieditor -d -tEDITOR_TRACE -bEDITOR64.Abal.3.3u.0.01 /home/abal64/src/ned/editor
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ -g -ggdb -DVERSION666 -DUNIX -Dunix -I/home/abal64/src/ned/ -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/ieditor.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/lib/bdaedit64.so -shared bdaedit.o nededit.o ednoy.o edvideo.o traceman.o aedask.o /home/abal64/archive/ixmisc.a /home/abal64/archive/misc.a /home/abal64/archive/repmisc.a /home/abal64/archive/dirmisc.a /home/abal64/pixel64/rgraph.o /home/abal64/pixel64/stdprod.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/allocate64.so /home/abal64/common/fnparser.o /home/abal64/common/wildcomp.o /home/abal64/pixel64/vobject.o /home/abal64/prltra/trace.o /home/abal64/lib/libaccess64.so /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 -lldap
cp /home/abal64/lib/bdaedit64.so /home/abal64/lib/testbdaedit64.so
bdatester64 testbdaedit
rm /home/abal64/lib/testbdaedit64.so
rm pipo* -f
gcc -fPIC -O0 -c -g -g -ggdb -D_PROTOTYPES -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/utmain.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -D_PROTOTYPES -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/utana.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -D_PROTOTYPES -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/utfile.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -D_PROTOTYPES -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/utmacro.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -D_PROTOTYPES -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/utbibunx.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -o /home/abal64/bin/amake64x utmain.o utana.o utfile.o utmacro.o utbibunx.o /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/gmmain.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DLINUX -DUNIX -Dunix -DUNX -I/home/abal64/include -DHX -DMSG_HX /home/abal64/src/amake/gmfile.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -o /home/abal64/bin/genmake gmmain.o gmfile.o utbibunx.o /home/abal64/common/fnparser.o /home/abal64/lib/libaccess64.so /home/abal64/lib/allocate64.so /home/abal64/common/wildcomp.o
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX /home/abal64/src/amake/yabal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/yabal yabal.o /home/abal64/common/wildcomp.o /home/abal64/common/fnparser.o 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX /home/abal64/src/amake/sandr.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/sandr sandr.o 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX /home/abal64/src/amake/asbcore.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo ASBCORE = /home/abal64/utmake/asbcore.o > /home/abal64/common/asbcore.def
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX /home/abal64/src/amake/asb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/asb asb.o asbcore.o 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/include /home/abal64/src/amake/avnfile.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
echo AVNFILE = /home/abal64/utmake/avnfile.o > /home/abal64/common/avnfile.def
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX /home/abal64/src/amake/avnor.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/avnor avnor.o avnfile.o /home/abal64/lib/allocate64.so 
gcc -fPIC -O0 -c -g -g -ggdb -DGCC -DUNIX /home/abal64/src/amake/apb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/apb apb.o 
gcc -fPIC -O0 -o /home/abal64/bin/abalprocess /home/abal64/src/amake/abalprocess.c
gcc -fPIC -O0 -c  -g -g -ggdb -DVERSION666 -DUNIX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL21 /home/abal64/src/agr/browse.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/agr64 browse.o /home/abal64/common/systeme.o /home/abal64/common/wildcomp.o
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trmain.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trbuffer.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trparser.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trsyntax.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trerrors.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trtables.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trsymbol.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trinput.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trproc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trexpres.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trmethod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trshadow.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/triter.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trngf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trclf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/triof.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trldf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trdirect.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trapl.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trabal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trstdc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trstruct.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trclass.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/troutput.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trlabels.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trabmsg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/trnurone.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/src/cico/ -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUBUNTU20 -Dotr64 /home/abal64/src/otr/tratoc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -ggdb -o /home/abal64/bin/otr64 trabal.o /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so trabmsg.o trapl.o trbuffer.o trclass.o trclf.o trdirect.o trerrors.o trexpres.o trinput.o triof.o triter.o trlabels.o trldf.o trmain.o trmethod.o trngf.o troutput.o trparser.o trproc.o trshadow.o trstdc.o trstruct.o trsymbol.o trsyntax.o trtables.o /usr/lib/libiconv_hook.so 
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trbuffer.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/cbparser.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trcbmsg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trfctrl.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trscreen.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/traccept.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trpctrl.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DUNIX -I/home/abal64/src/otr/ -I/home/abal64/include/ -Dotr32 /home/abal64/src/otr/trcobol.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -w -apipo
gcc -fPIC -O0 -g -ggdb -o /home/abal64/bin/ctr64 trcobol.o /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so trcbmsg.o trapl.o trbuffer.o trclass.o trclf.o trdirect.o trerrors.o trexpres.o trinput.o triof.o triter.o trlabels.o trldf.o trmain.o trmethod.o trngf.o troutput.o cbparser.o trproc.o trshadow.o trstdc.o trstruct.o trsymbol.o trsyntax.o trtables.o trfctrl.o trscreen.o traccept.o trpctrl.o
genmake -mldmain.mf -x -yOLDOBJ -I/home/abal64/include -I/home/abal64/src/cico "-zban*" "-ztrace.h" "-zwold*"  /home/abal64/src/old/ldmain.c /home/abal64/src/old/lderrors.c /home/abal64/src/old/ldabmsg.c
gcc -fPIC -O0 -c -g -ggdb -DUNIX -DVERSION666 -Dold64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL32DBG -I/home/abal64/include -I/home/abal64/src/cico /home/abal64/src/old/ldmain.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -DVERSION666 -Dold64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL32DBG -I/home/abal64/include -I/home/abal64/src/cico /home/abal64/src/old/lderrors.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -ggdb -DUNIX -DVERSION666 -Dold64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL32DBG -I/home/abal64/include -I/home/abal64/src/cico /home/abal64/src/old/ldabmsg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -ggdb  -o /home/abal64/bin/old64 ldmain.o lderrors.o ldabmsg.o /home/abal64/lib/allocate64.so
gcc -fPIC -O0  -c /home/abal64/src/ao/idbcode.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/ao.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aomotor.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aostruct.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aojump.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aostat.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aovarb.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aomath.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aoreg.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aotcode.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aolist.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aocopyat.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aopannel.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aolabel.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aorecov.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aosymb.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0  -c /home/abal64/src/ao/aostream.c -g -ggdb -DABAL21 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DUNIX -DVERSION666 -DABAL64 -I/home/abal64/include -I/home/abal64/src/exa/ -I/home/abal64/src/global 
gcc -fPIC -O0 -g  -o /home/abal64/bin/ao64   ao.o aomotor.o aostruct.o aojump.o aostat.o aovarb.o aomath.o aoreg.o aotcode.o aolist.o aocopyat.o aopannel.o aolabel.o aorecov.o aosymb.o aostream.o /home/abal64/common/fnparser.o /home/abal64/common/wildcomp.o /home/abal64/cico/ixciconr.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so
echo IDBCODE = /home/abal64/ao64/idbcode.o > /home/abal64/common/idbcode.def
rm pipo* -f
gcc -g -ggdb -c -fPIC -DUNIX -D_INXSQL_MYSQL -D_INXS_STUB_A -D_INXS_STUB_SQ -DENGINE=MYSQL /home/abal64/src/inxsql/inxsql.c
gcc -g -ggdb -c -fPIC -DUNIX -D_INXSQL_MYSQL -D_INXS_STUB_A -D_INXS_STUB_SQ -DENGINE=MYSQL /home/abal64/src/inxsql/libinxsql.c
gcc -g -ggdb -shared -o /home/abal64/lib/libinxsql64.so libinxsql.o inxsql.o /home/abal64/lib/allocate64.so -lmysqlclient
echo "DATABASE = "/home/abal64/lib/libinxsql64.so > /home/abal64/common/database.def
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/extrace.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exa.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exio.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exldf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exmotor.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/excode.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exclf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/examsg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/excalc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exmath.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/extvarb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exngf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exmc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exbd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exparser.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exmimo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exllfind.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/anaquest.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exadll.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/exa64        exa.o             exio.o            exldf.o           exmotor.o          excode.o         exclf.o           examsg.o        excalc.o        exmath.o        extvarb.o        exngf.o        exmc.o        exbd.o        anaquest.o        exllfind.o        exparser.o        extrace.o          /home/abal64/ldfbda/exbda64.o  /home/abal64/archive/libpixel.a   /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so  /home/abal64/lib/allocate64.so /home/abal64/lib/libprint64.so /home/abal64/pixel64/stdprod.o /usr/lib/libiconv_hook.so        /home/abal64/cico/ixcico64.o /home/abal64/archive/exmafl.a /home/abal64/lib/libflfile64.so /home/abal64/lib/libaccess64.so /home/abal64/lib/libinxsql64.so /home/abal64/lib/libflfile64.so /home/abal64/lib/libjpeg64.so /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /usr/lib/x86_64-linux-gnu/libdl.so -lldap
gcc -fPIC -O0 -g -g -ggdb -shared -o /home/abal64/lib/libexa64.so        exadll.o             exio.o            exldf.o           exmotor.o          excode.o         exclf.o           examsg.o        excalc.o        exmath.o        extvarb.o        exngf.o        exmc.o        exbd.o        anaquest.o        exllfind.o        exparser.o        extrace.o          /home/abal64/ldfbda/exbda64.o  /home/abal64/archive/libpixel.a   /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so  /home/abal64/lib/allocate64.so /home/abal64/lib/libprint64.so /home/abal64/pixel64/stdprod.o        /home/abal64/cico/ixcico64.o /home/abal64/archive/exmafl.a /home/abal64/lib/libflfile64.so /home/abal64/lib/libaccess64.so /home/abal64/lib/libinxsql64.so /home/abal64/lib/libflfile64.so /home/abal64/lib/libjpeg64.so /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /usr/lib/x86_64-linux-gnu/libdl.so -lldap 
rm pipo* -f
genmake -msingmain.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/sing.c
genmake -msingdesk.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singdesk.c
genmake -msingcam.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singcam.c /home/abal64/src/sing/threed.c
genmake -msingform.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singform.c
genmake -msingfont.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singfont.c
genmake -msingc.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singc.c
genmake -mstyleman.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/styleman.c
genmake -msinga.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singa.c
genmake -msingexpo.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singexpo.c
genmake -msingabal.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singabal.c
genmake -msingplus.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singplus.c
genmake -msingcob.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singcob.c
genmake -msingws.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singws.c
genmake -msingother.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/singother.c
genmake -mxmlparse.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/xmlparse.c
genmake -mxmlform.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/xmlform.c
genmake -mxmlthree.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/xmlthree.c
genmake -mvisual.mf -I/home/abal64/src/pixel -I/home/abal64/include  -zstrucpsu.h -zpubmanagercicoapi.h -zstdio.h -zallocate.h -zstdlib.h -zmalloc.h "-zwin*" -x /home/abal64/src/sing/visual.c /home/abal64/src/sing/vobject.c
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/basemenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/flowmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/linkmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/modelmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/actormenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/membermenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/widgetmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/methodmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vxmlname.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcssname.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vabalname.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vrelate.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vbase.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmodel.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vreader.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vdomain.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vdepmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vdepmodmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmodmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vsheet.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vformhelp.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwsgen.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vphp.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vlaser.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcppprod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/editmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/evenmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmethopt.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/filemenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/formmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/methmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/imagmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/mainmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/optimenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/projmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/tracmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/viewmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/viewmenu32a.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/viewmenu31e.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/formmenu31e.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/widgmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vaed.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vstatus.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vconsult.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vlocate.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfileref.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/valign.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vorder.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/verror.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcompose.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcompare.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vnation.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vhelper.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vaprod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vnatrad.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcobprod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcamera.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcprod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vshell.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcube.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vtree.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vseek.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfile.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcursor.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vpiece.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vdebug.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vedcmd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vexit.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfextr.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfload.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vform.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmethod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfsave.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vtsave.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfselect.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vhtml.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vrgb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vnewpal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vpaledit.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwebgen.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/viload.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vimage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vimport.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vintro.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/visave.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vlink.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vload.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmload.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmprod.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vmsave.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vamake.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vpage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vparam.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vrecrep.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vrefer.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vreplace.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vsave.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vsearch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vexadb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwatch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vdbok.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcss.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vshow.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vtrad.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwidget.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcolours.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vstdfont.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vsysfont.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vfexport.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vgridlock.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcompare.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/velement.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vilabel.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/velabel.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vvalid.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vyna.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/cstyleman.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vcmpform.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vpopup.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwall.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwbutton.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwcheck.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwdata.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwedit.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwfill.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwform.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwframe.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwgraph.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwimage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwwindow.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwline.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwprogress.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwradio.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwscroll.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwselect.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwswitch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwtabpage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vwtext.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/sing.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singdesk.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singcam.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/threed.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singform.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singfont.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singa.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/styleman.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singexpo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singabal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singplus.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singcob.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singws.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/singother.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/xmlparse.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/xmlform.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/xmlthree.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/visual.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vobject.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/exmpegcl.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo 
agr -apipo
gcc -fPIC -O0 -g -ggdb -shared -o /home/abal64/lib/singother.so singother.o 
gcc -fPIC -O0 -g -ggdb -shared -o /home/abal64/lib/singws.so singws.o 
gcc -fPIC -O0 -g -o  /home/abal64/bin/sing sing.o singdesk.o singcam.o  singfont.o singform.o xmlparse.o singexpo.o singc.o xmlform.o xmlthree.o singcob.o singabal.o singplus.o singa.o /home/abal64/lib/singws.so threed.o /home/abal64/common/fnparser.o /home/abal64/exa64/exllfind.o /home/abal64/common/systemd.o /home/abal64/printer/paper.o /home/abal64/utmake/asbcore.o vrefer.o vintro.o vparam.o vrecrep.o vexit.o vfselect.o vstatus.o vshell.o vilabel.o velabel.o vvalid.o visave.o viload.o vimage.o vcolours.o vrgb.o vpaledit.o vnewpal.o cstyleman.o vcmpform.o vpopup.o vconsult.o vfload.o vfsave.o vimport.o vfextr.o vstdfont.o vsysfont.o vgridlock.o vfexport.o vwidget.o vform.o vsave.o vload.o vcompose.o vmethod.o vlocate.o vcss.o basemenu.o modelmenu.o membermenu.o linkmenu.o vxmlname.o vrelate.o vbase.o vmodel.o flowmenu.o actormenu.o widgetmenu.o methodmenu.o vreader.o vdomain.o vdepmenu.o vdepmodmenu.o vmodmenu.o vsheet.o vformhelp.o vcssname.o vabalname.o vcppprod.o vwsgen.o vphp.o vlaser.o vaed.o vedcmd.o vsearch.o vreplace.o vnation.o vhelper.o vtsave.o  vcompare.o /home/abal64/utmake/avnfile.o vdebug.o vtrad.o vlink.o vamake.o vfile.o vtree.o vseek.o vfileref.o vcamera.o vcube.o vmsave.o vmload.o vcursor.o  verror.o valign.o vorder.o  vnatrad.o vcprod.o vaprod.o vmprod.o vhtml.o vpage.o vwebgen.o vcobprod.o  editmenu.o evenmenu.o filemenu.o formmenu.o imagmenu.o mainmenu.o optimenu.o projmenu.o tracmenu.o viewmenu.o widgmenu.o methmenu.o vmethopt.o  vwtext.o vwtabpage.o vwswitch.o vwselect.o vwscroll.o vwradio.o vwprogress.o vwline.o vwimage.o vwwindow.o vwgraph.o vwframe.o vwform.o vwfill.o vwedit.o vwdata.o vwcheck.o vwbutton.o vwall.o vyna.o vpiece.o  /home/abal64/archive/libpixel.a /home/abal64/cico/ixciconr64.o /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so  /home/abal64/lib/libaccess64.so /home/abal64/lib/libjpeg64.so /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/prltra/trace.o /home/abal64/lib/allocate64.so /home/abal64/lib/libedit64.so -lldap  
rm pipo* -f
/home/abal64/bin/linbda -bVisual64.Abal.3.3u.0.01 -v -r/home/abal64/src/sing/vgui -d -tVISUAL_TRACE /home/abal64/src/pixel/visual
gcc -fPIC -O0 -c -g -ggdb  -fPIC -O0  -fPIC -O0  -g -ggdb -DVERSION666 -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ -DSYSTEM_LDAP /home/abal64/src/sing/vgui.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
genmake -mvisual.mf -x -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ -zstdio.h -zstdlib.h -zmalloc.h "-zwin*" /home/abal64/src/sing/visual.c /home/abal64/src/sing/vobject.c /home/abal64/src/sing/exmpegcl.c
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/visual.c 1>pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/vobject.c 1>pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/sing/exmpegcl.c 1>pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
genmake -mtextual.mf -x -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ -zstdio.h -zstdlib.h -zmalloc.h "-zwin*" /home/abal64/src/sing/textual.c
genmake -mrgraph.mf -x -I/home/abal64/include/bdas/ -I/home/abal64/src/sing/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ -zstdio.h -zstdlib.h -zmalloc.h "-zwin*" /home/abal64/src/pixel/rgraph.c
gcc -fPIC -O0 -c -g -g -ggdb -DVERSION666 -DABAL64 -fPIC -O0  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Wmissing-prototypes -I/home/abal64/src/pixel -I/home/abal64/include  -DP3D32 -DSYSTEM_LDAP -DSING_MODEL_EDITOR -DABAL34A /home/abal64/src/pixel/rgraph.c 1>pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -ggdb -shared -o /home/abal64/lib/visual64.so vgui.o visual.o vobject.o rgraph.o stdprod.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/allocate64.so /home/abal64/common/fnparser.o /home/abal64/lib/libjpeg64.so /home/abal64/common/wildcomp.o /home/abal64/pixel64/exmpegcl.o  -lldap /home/abal64/prltra/trace.o
cp /home/abal64/lib/visual64.so /home/abal64/lib/testvisual64.so
bdatester64 testvisual
rm /home/abal64/lib/testvisual64.so -f
echo VOBJECT = /home/abal64/pixel64/vobject.o > /home/abal64/common/vobject.def
echo VEXADB = /home/abal64/pixel64/vexadb.o /home/abal64/pixel64/vwatch.o /home/abal64/pixel64/velement.o /home/abal64/pixel64/vdbok.o /home/abal64/pixel64/vshow.o /home/abal64/pixel64/vobject.o /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 > /home/abal64/common/vexadb.def
gcc -fPIC -O0 -c -g -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DHX -Dver2K -Dver21 -DABAL64 -DLINT_ARGS -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -fPIC -O0  /home/abal64/src/abal//abal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DHX -Dver2K -Dver21 -DABAL64 -DLINT_ARGS -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -fPIC -O0  /home/abal64/src/abal//misc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DHX -Dver2K -Dver21 -DABAL64 -DLINT_ARGS -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -fPIC -O0  /home/abal64/src/abal//iboite.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DHX -Dver2K -Dver21 -DABAL64 -DLINT_ARGS -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -fPIC -O0  /home/abal64/src/abal//saisie.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -o /home/abal64/bin/abal64 abal.o misc.o iboite.o saisie.o /home/abal64/common/systemd.o /home/abal64/pixel64/stdprod.o /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so /home/abal64/archive/ixmisc.a /home/abal64/archive/misc.a /home/abal64/archive/repmisc.a /home/abal64/archive/dirmisc.a /home/abal64/archive/libpixel.a /home/abal64/cico/ixciconr64.o /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so /home/abal64/pixel64/vobject.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/libjpeg64.so /home/abal64/prltra/trace.o /home/abal64/lib/allocate64.so -lldap
linbda -bBdaEdit3.2a.0.01 /home/abal64/src/ned/bdaedit
cp /home/abal64/src/ned/bdaedit.def /home/abal64/include
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/bdas/ /home/abal64/src/ned/bdaedit.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/bdas/ /home/abal64/src/ned/nededit.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/ednoy.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/edvideo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/nogigo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/traceman.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/aedask.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/lib/libedit64.so -shared ednoy.o nogigo.o edvideo.o traceman.o aedask.o /home/abal64/archive/ixmisc.a /home/abal64/archive/misc.a /home/abal64/archive/repmisc.a /home/abal64/archive/dirmisc.a -lldap
echo EDILIB = /home/abal64/lib/libedit64.so > /home/abal64/common/editor.def
echo LIBREP = >> /home/abal64/common/editor.def
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/edmain.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -o /home/abal64/bin/aed64 edmain.o /home/abal64/pixel64/stdprod.o /home/abal64/lib/libedit64.so /home/abal64/archive/libpixel.a /home/abal64/cico/ixciconr.o /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so /home/abal64/common/fnparser.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so /home/abal64/pixel64/vobject.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/libjpeg64.so /home/abal64/prltra/trace.o /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 -lldap 
/home/abal64/bin/linbda -v -r/home/abal64/src/ned/ieditor -d -tEDITOR_TRACE -bEDITOR64.Abal.3.3u.0.01 /home/abal64/src/ned/editor
gcc -fPIC -O0 -c -g -DUNIX -Dunix -Dver2K -Dver21 -DLINT_ARGS -DLINUX -DUSEIT -DVERSION666 -I/home/abal64/src/pixel/ -I/home/abal64/include/ -g -ggdb -DVERSION666 -DUNIX -Dunix -I/home/abal64/src/ned/ -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel/ -I/home/abal64/include/ /home/abal64/src/ned/ieditor.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/lib/bdaedit64.so -shared bdaedit.o nededit.o ednoy.o edvideo.o traceman.o aedask.o /home/abal64/archive/ixmisc.a /home/abal64/archive/misc.a /home/abal64/archive/repmisc.a /home/abal64/archive/dirmisc.a /home/abal64/pixel64/rgraph.o /home/abal64/pixel64/stdprod.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/allocate64.so /home/abal64/common/fnparser.o /home/abal64/common/wildcomp.o /home/abal64/pixel64/vobject.o /home/abal64/prltra/trace.o /home/abal64/lib/libaccess64.so /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 -lldap
cp /home/abal64/lib/bdaedit64.so /home/abal64/lib/testbdaedit64.so
bdatester64 testbdaedit
rm /home/abal64/lib/testbdaedit64.so
rm pipo* -f
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exadb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbio.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbldf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbcmd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbfunc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbmenu.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbmoto.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbcico.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbproc.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbtrap.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbwtch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbafun.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbsymb.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbstre.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbrdui.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbtrac.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbstak.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbobs.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbcode.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exdbclf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -c -g -I/home/abal64/include -I/home/abal64/src/global -g -ggdb -DABALX11 -DABAL4 -DVERSION666 -DABAL64 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABALV33 -DINXSQL -DVERSION_XX -DTRACEON -DTRACEABAL -DCRIVER40 -DUSEICONV  -DLIBPRINT -DUSEIT  -DABAL21 -DABALSP /home/abal64/src/exa/exadbmsg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
IDBCODE = /home/abal64/ao64/idbcode.o
gcc -fPIC -O0 -g -g -ggdb -o /home/abal64/bin/exadb64        exadb.o             exdbio.o            exdbldf.o           exdbcmd.o           exdbfunc.o          exdbmenu.o          exdbmoto.o          exdbcico.o          exdbproc.o          exdbtrap.o          exdbwtch.o          exdbafun.o          exdbsymb.o          exdbstre.o          exdbrdui.o          exdbtrac.o          exdbstak.o         exdbobs.o           exdbcode.o         exdbclf.o           exadbmsg.o        excalc.o        exmath.o        extvarb.o        exngf.o        exmc.o        exbd.o        extrace.o        anaquest.o        exllfind.o        exparser.o        /home/abal64/pixel64/vexadb.o /home/abal64/pixel64/vwatch.o /home/abal64/pixel64/velement.o /home/abal64/pixel64/vdbok.o /home/abal64/pixel64/vshow.o /home/abal64/pixel64/vobject.o /home/abal64/archive/grapil.a /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/archive/libpixel.a /usr/lib/x86_64-linux-gnu/libX11.so /usr/lib/x86_64-linux-gnu/libXt.so  /home/abal64/lib/libjpeg64.so /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16        /home/abal64/common/systeme.o /usr/lib/libiconv_hook.so        /home/abal64/ldfbda/exbda64.o         /home/abal64/ao64/idbcode.o        /home/abal64/lib/allocate64.so /home/abal64/lib/libprint64.so        /home/abal64/cico/ixcico64.o /home/abal64/archive/exmafl.a /home/abal64/lib/libflfile64.so /home/abal64/lib/libaccess64.so /home/abal64/lib/libinxsql64.so /home/abal64/lib/libflfile64.so /usr/lib/x86_64-linux-gnu/libdl.so /home/abal64/lib/libedit64.so /home/abal64/pixel64/stdprod.o  -lldap
rm pipo* -f
/home/abal64/bin/linbda  -bPRINTER64.Abal.3.3u.0.01 /home/abal64/src/printer/printer
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/printer.c
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/psiii.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/psiiit.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/gdit.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/psiiihq.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/bj300330.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/ljii.c 
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/ljiv.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -fPIC -O0  -g -ggdb -DBOOLI -DUNIX -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DVERSION666 -DUSEIT -I/home/abal64/include/bdas/ -I/home/abal64/src/pixel /home/abal64/src/printer/svg.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/ljiv64.so ljiv.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/ljiv64.so /home/abal64/lib/checklj64.so
/home/abal64/bin/bdatester64 checklj
rm /home/abal64/lib/checklj64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/ljii64.so ljii.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/ljii64.so /home/abal64/lib/checklj64.so
/home/abal64/bin/bdatester64 checklj
rm /home/abal64/lib/checklj64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/psiii64.so psiii.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/psiii64.so /home/abal64/lib/checkps64.so
/home/abal64/bin/bdatester64 checkps
rm /home/abal64/lib/checkps64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/psiiit64.so psiiit.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/psiiit64.so /home/abal64/lib/checkps64.so
/home/abal64/bin/bdatester64 checkps
rm /home/abal64/lib/checkps64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/gdit64.so gdit.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/gdit64.so /home/abal64/lib/checkps64.so
/home/abal64/bin/bdatester64 checkps
rm /home/abal64/lib/checkps64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/svg64.so svg.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/svg64.so /home/abal64/lib/checksvg64.so
/home/abal64/bin/bdatester64 checksvg
rm /home/abal64/lib/checksvg64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/psiiihq64.so psiiihq.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/psiiihq64.so /home/abal64/lib/checkps64.so
/home/abal64/bin/bdatester64 checkps
rm /home/abal64/lib/checkps64.so
gcc -fPIC -O0 -shared -g -g -ggdb  -o /home/abal64/lib/bj30033064.so bj300330.o printer.o paper.o /home/abal64/pixel64/rgraph.o
cp /home/abal64/lib/bj30033064.so /home/abal64/lib/checkps64.so
/home/abal64/bin/bdatester64 checkps
rm /home/abal64/lib/checkps64.so
/home/abal64/bin/linbda -r/home/abal64/src/bibmath/ibibmath -x -bBIBMATH64.Abal.3.3u.0.01  /home/abal64/src/bibmath/bibmath
gcc -fPIC -O0 -g -g -ggdb -c -fPIC -O0  -I/home/abal64/include/bdas/ -DUNIX -DVERSION666 -DABAL64 -Dunix /home/abal64/src/bibmath/ibibmath.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -c -fPIC -O0  -I/home/abal64/include/bdas/ -DUNIX -DVERSION666 -DABAL64 -Dunix -DFCT_ENTETE /home/abal64/src/bibmath/bibmath.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -g -ggdb -shared -o /home/abal64/lib/bibmath64.so ibibmath.o bibmath.o -lm
/home/abal64/bin/linbda -x -r/home/abal64/src/tty/itty -d -tTRACE_TTY -bTTY64.Abal.3.3u.0.01 /home/abal64/src/tty/tty
gcc  -c -g     -fPIC -O0  -DTRACEON -DUNIX -D_LINUX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL3 -DVERSION666 -DABAL64 -fPIC -O0  -I/home/abal64/include/bdas/ /home/abal64/src/tty/itty.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc  -c -g     -fPIC -O0  -DTRACEON -DUNIX -D_LINUX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL3 -DVERSION666 -DABAL64 -fPIC -O0  -I/home/abal64/include/bdas/ /home/abal64/src/tty/utty.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc  -o /home/abal64/lib/tty64.so -shared itty.o utty.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so 
gcc  -c -g     -fPIC -O0  -DTRACEON -DUNIX -D_LINUX -Dunix -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DABAL3 -DVERSION666 -DABAL64 -fPIC -O0  -I/home/abal64/include/bdas/ /home/abal64/src/tty/tracetty.c 1> pipo1 2>pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc  -o /home/abal64/bin/tracetty tracetty.o
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wini.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wcreat.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wwrite.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wvis.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wgen.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/winfo.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wrequi.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wmem.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wmove.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wombre.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfini.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfls.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfbv.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfld.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfai.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfsai.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfmd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/runco.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sftch.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/mv2_14.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfbd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/sfdyna.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/t_el_bd.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wcadre.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wscroll.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/xmouse.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/bsamf.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/machin.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -c -g -DVERSION666 -DABAL64 -g -ggdb -I/home/abal64/include/bdas/ -DAIX_VERS -DASFCICO -DDG -DIDIRECT -DUNIX -DLINT_ARGS -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -Dunix -Dver14 -fPIC -O0   /home/abal64/src/asfun/wlog.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -o /home/abal64/lib/asfun64.so -shared wini.o wcreat.o wwrite.o wvis.o wgen.o winfo.o wrequi.o wmem.o wmove.o wombre.o sfini.o sfls.o sfbv.o sfld.o sfai.o sfsai.o sfmd.o runco.o sftch.o mv2_14.o sfbd.o sfdyna.o t_el_bd.o wcadre.o wscroll.o xmouse.o bsamf.o machin.o /home/abal64/lib/allocate64.so /home/abal64/lib/libaccess64.so
linbda -bGrAsfun64 -x -dTRACE_GRASFUN -r/home/abal64/src/grasfun/iasfun /home/abal64/src/grasfun/asfun
gcc -c -g -ggdb -fPIC -DUNIX -Dunix -DVERSION666 -DABAL32 -DABAL64 -I/home/abal64/include/bdas/  -I/home/abal64/src/pixel/ -I/home/abal64/src/asfun/ -I/home/abal64/src/sing/ /home/abal64/src/grasfun/iasfun.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -a pipo
fuck
gcc -c -g -ggdb -fPIC -DUNIX -Dunix -DVERSION666 -DABAL32 -DABAL64 -I/home/abal64/include/bdas/  -I/home/abal64/src/pixel/ -I/home/abal64/src/asfun/ -I/home/abal64/src/sing/ /home/abal64/src/grasfun/aasfun.c > pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -a pipo
fuck
gcc -shared -o /home/abal64/lib/grasfun64.so iasfun.o aasfun.o /home/abal64/pixel64/rgraph.o /home/abal64/common/fnparser.o /home/abal64/common/wildcomp.o /home/abal64/pixel64/styleman.o /home/abal64/pixel64/stdprod.o /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/lib/libaccess64.so
cp /home/abal64/lib/grasfun64.so /home/abal64/lib/testgrasfun64.so
bdatester64 testgrasfun
rm /home/abal64/lib/testgrasfun64.so
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/connect.c 1> pipo1 2> pipo2 
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/url.c 1> pipo1 2> pipo2 
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/global.c 1> pipo1 2> pipo2 
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/files.c 1> pipo1 2> pipo2 
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -I/home/abal64/src/sing/ -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/httpabal.c 1> pipo1 2> pipo2 
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/httpfunc.c
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix  /home/abal64/src/bdanet/http.c 1> pipo1 2> pipo2 
ar r /home/abal64/archive/bdanet.a connect.o url.o global.o files.o httpabal.o httpfunc.o http.o
/home/abal64/bin/linbda -bBd@Net64.Abal.3.3u.0.01 /home/abal64/src/bdanet/bdanet
gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL  -I/home/abal64/include/bdas/  -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DSYSTEM_SSL  -Dunix /home/abal64/src/bdanet/bdanet.c 1> pipo1 2> pipo2
gcc -fPIC -O0 -g -DVERSION666 -DABAL64 -DUNIX -DSYSTEM_SSL -shared -o /home/abal64/lib/bdanet64.so bdanet.o /home/abal64/archive/bdanet.a -lssl 
/home/abal64/bin/linbda -x -bZ64.Abal.3.3u.0.01 /home/abal64/src/z/z
genmake -m./mf/z.mf -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc -zversion.rc -x /home/abal64/src/z/z.c
genmake -m./mf/zsoabal.mf -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc -zversion.rc -x /home/abal64/src/z/zsoabal.c
genmake -m./mf/zsogui.mf -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc -zversion.rc -x /home/abal64/src/z/zsogui.c
genmake -m./mf/zsosys.mf -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc -zversion.rc -x /home/abal64/src/z/zsosys.c
genmake -m./mf/zsotxt.mf -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanBuild.h -zVersion.rc -zversion.rc -x /home/abal64/src/z/zsotxt.c
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -DVERSION666 -Wall -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DBDA_GNUC /home/abal64/src/z/z.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -DVERSION666 -Wall -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DBDA_GNUC /home/abal64/src/z/zsoabal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -DVERSION666 -Wall -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DBDA_GNUC /home/abal64/src/z/zsogui.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -DVERSION666 -Wall -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DBDA_GNUC /home/abal64/src/z/zsosys.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/z -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/zgr -I/home/abal64/src/prltra -DVERSION666 -Wall -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL -DBDA_GNUC /home/abal64/src/z/zsotxt.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -shared -g -ggdb -o /home/abal64/lib/z64.so z.o zsoabal.o zsogui.o zsosys.o zsotxt.o /home/abal64/lib/allocate64.so
rm pipo* -f
/home/abal64/bin/linbda -bZGR64.Abal.3.3u.0.01 /home/abal64/src/zgr/z
genmake -m./mf/z.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/z.c
genmake -m./mf/vlink.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/vlink.c
genmake -m./mf/ztrace.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/ztrace.c
genmake -m./mf/ztools.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/ztools.c
genmake -m./mf/zlook.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zlook.c
genmake -m./mf/jimage.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/jimage.c
genmake -m./mf/jlinuxmouse.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/jlinuxmouse.c
genmake -m./mf/vgrhold.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/vgrhold.c
genmake -m./mf/vthobase.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/vthobase.c
genmake -m./mf/zglobal.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zglobal.c
genmake -m./mf/zabal.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zabal.c
genmake -m./mf/zgraphic.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zgraphic.c
genmake -m./mf/zgui.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zgui.c
genmake -m./mf/zsys.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/zsys.c
genmake -m./mf/ztext.mf -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -zTrace.h -zTrace.c -zstdio.h -zstdlib.h -zmalloc.h -zbanbuild.h -zversion.rc -zbankrnl.rc -zVersion.rc -zutilzgrmain.h -zwincicoapi.h -x /home/abal64/src/zgr/ztext.c
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/z.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/vlink.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/ztrace.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/ztools.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zlook.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/jimage.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/jlinuxmouse.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/vgrhold.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/vthobase.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zglobal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zabal.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zgraphic.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zgui.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/zsys.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -g -c -g -ggdb -fPIC -O0  -I/home/abal64/src/zgr -I/home/abal64/include/bdas -I/home/abal64/include -I/home/abal64/src/pixel -DVERSION666 -Wall -DUNIX -Dunix   -D_LINUX -DBDA_GNUC /home/abal64/src/zgr/ztext.c 1> pipo1 2> pipo2
cat pipo1 pipo2 > pipo
agr -apipo
gcc -fPIC -O0 -shared -g -ggdb -o /home/abal64/lib/zgr64.so z.o vlink.o ztrace.o ztools.o zlook.o jimage.o jlinuxmouse.o vgrhold.o vthobase.o zglobal.o zabal.o zgraphic.o zgui.o zsys.o ztext.o /home/abal64/lib/allocate64.so /home/abal64/lib/libimage64.so /usr/lib/x86_64-linux-gnu/libpng16.so.16 /home/abal64/pixel64/stdprod.o /home/abal64/lib/libjpeg64.so /home/abal64/pixel64/rgraph.o
rm pipo* -f
echo Enter ABAL 64 Production
cd allocate;   amake -b -n
cd common;     amake -b -n
cd ixmisc;     amake -b -n
cd assert;     amake -b -n
cd prltra;     amake -b -n
cd cico;       amake -b -n
cd access64;   amake -b -n
cd linbda;     amake -b -n
cd ldfbda;     amake -b -n
cd printer;    amake -b -n -a PASSONE
cd exmafl;     amake -b -n
cd jpeg64;     amake -b -n
cd pixel64;    amake -b -n -a PASSONE
cd ned64;      amake -b -n -a PASSONE
cd utmake;     amake -b -n
cd agr64;      amake -b -n
cd otr64;      amake -b -n
cd old64;      amake -b -n
cd ao64;       amake -b -n
cd inxsql;     amake -b -n
cd exa64;      amake -b -n -a PASSONE
cd pixel64;    amake -b -n -a PASSTWO
cd abal64;     amake -b -n
cd ned64;      amake -b -n -a PASSTWO
cd exa64;      amake -b -n -a PASSTWO
cd printer;    amake -b -n -a PASSTWO
cd bibmath64;  amake -b -n
cd tty64;      amake -b -n
cd asfun64;    amake -b -n
cd grasfun64;  amake -b -n
cd bdanet64;   amake -b -n
cd z64;        amake -b -n
cd zgr64;      amake -b -n
echo Leave ABAL 64 Production
