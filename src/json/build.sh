#!/bin/bash

export ABALHOME="/home/abal64"
export VERSION="-DABAL64"
export BDAS="${ABALHOME}/include/bdas/"
export SP01="${ABALHOME}/src/json/"
export ALLOCATE="/home/abal64/lib/allocate64.so"

gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 ${VERSION} -DUNIX   -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}abaljson.c

gcc -fPIC -O0 -c -fPIC -O0  -g -DVERSION666 ${VERSION} -DUNIX   -I${BDAS} -DLINUX -DUNIX -DUSEIT -Dunix -DABAL32A -DABAL32B -DABALXML -DABAL33A -DABALSQL  -Dunix  ${SP01}jsonabal.c

gcc -fPIC -O0 -g -DVERSION666 ${VERSION} -DUNIX  -shared -o ./json64.so abaljson.o jsonabal.o ${ALLOCATE}

#eof
