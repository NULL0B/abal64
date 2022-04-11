#!/bin/bash

line(){
echo "-----------------------------------------------------"
}

line
echo  generation of the abal64 installation tarball package
line

# -----------------------------------------------------
# check the number of tools and libraries is a expected
# -----------------------------------------------------

export bincount=23
export libcount=30

export x=$(ls bin | wc -l)
export l=$(ls lib | wc -l)

if [ $bincount -gt $x ]; then
	echo "**error**" there should be $bincount tools and only $x were found
	ls -tl bin
	line
	exit 1
fi

if [ $libcount -gt $l ]; then
	echo "**error**" there should be $libcount shared libraries and only $l were found
	ls -tl lib
	line
	exit 1
fi

# -------------------------------------------------
# calculate the next indice for the current version
# -------------------------------------------------
export VERSION=v51a
. ./abal64-$VERSION.sh
export INDICE=$(($INDICE+1))

echo "#!/bin/bash"         > ./abal64-$VERSION.sh
echo GENDATE=\"$(date)\"  >> ./abal64-$VERSION.sh
echo VERSION=$VERSION     >> ./abal64-$VERSION.sh
echo INDICE=$INDICE       >> ./abal64-$VERSION.sh

export TARBALL=$ABAL/package/abal64${ABSQL}-${VERSION}.${INDICE}.tgz 
export ZIPFILE=$ABAL/package/abal64${ABSQL}-${VERSION}.${INDICE}.zip 

# -------------------------------------------
# generate the versioned installation package 
# -------------------------------------------

ls -tl bin lib

install -d $ABAL/package
install -d /var/www/html/openabal/depot

cd ..

# -------------------------------------------
# definition of the files included in package
# -------------------------------------------
export BIN="abal64/bin/*" 
export LIB="abal64/lib/*.so"
export ASH="abal64/*ash.sh"
export FMF="abal64/fonts/*.fmf"
export RGB="abal64/images/*.rgb"
export PNG="abal64/images/*.png"
export CSS="abal64/style/*.css"
export TIO="abal64/cico/lib/*"
export CLS="abal64/class/*.*"
export BDA="abal64/include/bdas/*.*"

tar -czf $TARBALL abal64/abal64-$VERSION.sh $BIN $LIB $ASH $TIO $FMF $RGB $PNG $CSS $CLS $BDA
zip $ZIPFILE abal64/abal64-$VERSION.sh $BIN $LIB $ASH $TIO $FMF $RGB $PNG $CSS $CLS $BDA > /dev/null

# ----------------------------------------------- 
# install the package as the current in the depot
# ----------------------------------------------- 
if [ -d /var/www/html/openabal ]; then
	cp $TARBALL /var/www/html/openabal/depot/abal64${ABSQL}.tgz
	chmod uog+r /var/www/html/openabal/depot/abal64${ABSQL}.tgz
	chown www-data:www-data /var/www/html/openabal/depot/abal64${ABSQL}.tgz
	cp $ZIPFILE /var/www/html/openabal/depot/abal64${ABSQL}.zip
	chmod uog+r /var/www/html/openabal/depot/abal64${ABSQL}.zip
	chown www-data:www-data /var/www/html/openabal/depot/abal64${ABSQL}.zip
fi
echo "-----------------------------------------------------"
ls -tl $TARBALL
echo "-----------------------------------------------------"

#eof
