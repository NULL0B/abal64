#!/bin/bash

export XXSQL=$1
if [ -z "$XXSQL" ]
then
	export XXSQL=MYSQL
fi

if [ "$XXSQL" == "MYSQL" ]
then
	export ABSQL=mysql
	export ABALSQL=MYSQL
fi

if [ "$XXSQL" == "PGSQL" ]
then
	export ABSQL=pgsql
	export ABALSQL=PGSQL
fi

clear

echo building binaries for $ABALSQL deployment and tar ball 

# remove all librararies, binaries, archives and objects
bash clean.sh

# force build all
amake -b > build-one.out

# allow cyclic update
amake > build-two.out

# build the binary package
bash build-abal64.sh

# build the source tarball
bash build-tarball.sh

#eof
