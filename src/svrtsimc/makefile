
.as.o:
	otr64 -m $*

.o.at:
	old64 -m $?

psvsi.o: psvsi.as
prtsi.o: prtsi.as
svsi.o: svsi.as
rtsi.o: rtsi.as
svmc.o: svmc.as
rtmc.o: rtmc.as

! make

svsi.at: svsi.o psvsi.o
rtsi.at: rtsi.o prtsi.o
svmc.at: svmc.o psvsi.o
rtmc.at: rtmc.o prtsi.o

! make


