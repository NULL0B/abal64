#!/bin/bash

export ABAL=/home/abal64
export CICO=useitmv40:$ABAL/cico/lib:1
export GCC=gcc
export GDB="-g -ggdb"
export SHARED_LIBRARIES=1

export INXSHOST=www.amenesik.com
export INXSUSER=inxsql
export INXSPASS=inxsql
export INXSBASE=inxsql
export INXSTLS=ON
#export INXSCERTIFICATE="/home/cosacs/amenesik.com/cert.pem"
#export INXSPRIVATEKEY="/home/cosacs/amenesik.com/privkey.pem"
#export INXSCA="/home/cosacs/amenesik.com/chain.pem"

export PATH=$PATH:$ABAL/bin
export ABALUTF8=0

echo "#!/bin/bash" 						>  $ABAL/bin/inxs
echo "if [ ! -z \"\$INXSTLS\" ]" 				>> $ABAL/bin/inxs
echo "then"							>> $ABAL/bin/inxs
echo "export MYSQLTLS=\"--ssl-mode=REQUIRED\"" 			>> $ABAL/bin/inxs
echo "else"							>> $ABAL/bin/inxs
echo "export MYSQLTLS=\" \""					>> $ABAL/bin/inxs
echo "fi"							>> $ABAL/bin/inxs
echo "mysql \${MYSQLTLS} --host=$INXSHOST --user=\$INXSUSER --password=\$INXSPASS \$INXSBASE" >> $ABAL/bin/inxs
echo "#eof"       						>> $ABAL/bin/inxs

chmod +x $ABAL/bin/inxs

export INXSHOST=$INXSHOST:3306:0
export LTSHOSTNAME="https://www.amenesik.com"
export LTSPATHNAME="/var/www/html"
export LTSUPLOAD="/home/open-lts/upload"

#eof
