#!/bin/bash

cd /home

tar -czf \
	/var/www/html/openabal/depot/abal64${ABSQL}-tarball.tgz \
	abal64/production.sh \
	abal64/build-*.sh \
	abal64/build.sh \
	abal64/gash.sh \
	abal64/ash.sh \
	abal64/makefile  \
	abal64/include/*.c \
	abal64/include/*.h \
	abal64/include/*.def \
	abal64/include/bdas/*.c \
	abal64/include/bdas/*.h \
	abal64/src/*/*.c \
	abal64/src/*/*.cpp \
	abal64/src/*/*.h \
	abal64/src/*/*.hx \
	abal64/src/*/*.def \
	abal64/*/makefile \
	abal64/*/*.mf \
	abal64/*/*/*.mf \
	abal64/*/*.def \
	abal64/cico/lib/* \
	abal64/build-tarball.sh \
	abal64/build-abal64.sh \
	abal64/qualification

zip \
        /var/www/html/openabal/depot/abal64${ABSQL}-tarball.zip \
        abal64/production.sh \
        abal64/build-*.sh \
	abal64/build.sh \
	abal64/gash.sh \
	abal64/ash.sh \
        abal64/makefile  \
        abal64/include/*.c \
        abal64/include/*.h \
        abal64/include/*.def \
        abal64/include/bdas/*.c \
        abal64/include/bdas/*.h \
        abal64/src/*/*.c \
        abal64/src/*/*.cpp \
        abal64/src/*/*.h \
        abal64/src/*/*.hx \
        abal64/src/*/*.def \
        abal64/*/makefile \
        abal64/*/*.mf \
        abal64/*/*/*.mf \
        abal64/*/*.def \
        abal64/cico/lib/* \
        abal64/build-tarball.sh \
        abal64/build-abal64.sh \
        abal64/qualification > /dev/null

#eof

