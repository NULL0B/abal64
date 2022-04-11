#!/bin/bash
# ------------------------
# A B A L  6 4  Production
# ------------------------
export ABAL=/home/abal64
export CICO=linuxvtm25:$ABAL/cico/lib:1
export GCC=gcc
export GDB="-g -ggdb"
export SHARED_LIBRARIES=1

export PATH=$PATH:$ABAL/bin

# -------------------
# install dependances
# -------------------
apt-get --yes update
apt-get --yes install gcc
apt-get --yes install libmysqlclient-dev
apt-get --yes install libpq-dev
apt-get --yes install libiconv-hook-dev
apt-get --yes install libx11-dev
apt-get --yes install libxt-dev
apt-get --yes install x11-xserver-utils
apt-get --yes install libpng-dev
apt-get --yes install libldap-dev
apt-get --yes install zip

# ------------------------
# rebuild the abal product
# ------------------------
cd $ABAL
install -d $ABAL/bin
install -d $ABAL/lib
install -d $ABAL/archive
install -d $ABAL/package

echo "#!/bin/bash" > $ABAL/bin/agr
echo "echo OK" >> $ABAL/bin/agr
echo "#eof" >> $ABAL/bin/agr
chmod +x $ABAL/bin/agr

if [ -f "bin/amake64x" ]; then
	cp bin/amake64x bin/amake64
fi

amake64 -b -d 
amake64 -d 

rm bin/agr
cp bin/amake64x bin/amake64

# ------------------------
# build the binary package
# ------------------------
bash build-abal64.sh

# ---------------
# confidence test
# ---------------
if [ 1 \> 2 ]; then
	cd qualification
	bash qma reset
	bash qma 
fi

# ------------------------
# end of abal64 production
# ------------------------

#eof
