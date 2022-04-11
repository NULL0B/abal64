#!/bin/bash
clear
export VERSION="-DABAL32"
export MACHINE="-m32 -march=i386 "
export BDAS="/usr/include/bda/"
export SP01="./"
export ALLOCATE="/usr/lib/abal4/allocate32.so"
export LIB="-L /lib/i386-linux-gnu/"

echo gcc ${MACHINE} -fPIC -O0 -c -fPIC -O0 ${LIB}  -g -DVERSION666 ${VERSION} -DUNIX -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}abaljson.c
gcc ${MACHINE} -fPIC -O0 -c -fPIC -O0 ${LIB}  -g -DVERSION666 ${VERSION} -DUNIX -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}abaljson.c 2> shite


echo gcc ${MACHINE} -fPIC -O0 -c -fPIC -O0 ${LIB}  -g -DVERSION666 ${VERSION} -DUNIX -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}jsonabal.c
gcc ${MACHINE} -fPIC -O0 -c -fPIC -O0 ${LIB}  -g -DVERSION666 ${VERSION} -DUNIX -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}jsonabal.c 2> shite

ld -melf_i386 -fPIC -O0 -g -shared ${LIB} -o ./json32.so abaljson.o jsonabal.o ${ALLOCATE}

#eof

