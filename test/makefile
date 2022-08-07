
.as.o:
	otr64 -m $*

.o.at:
	old64 -m $?

svsi.o: svsi.as
rtsi.o: rtsi.as
svmc.o: svmc.as
rtmc.o: rtmc.as

! make

svmc.at: svmc.o svsi.o
rtmc.at: rtmc.o rtsi.o

! make


