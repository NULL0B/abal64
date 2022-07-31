! echo building cico parameter files 
! echo for use with emulation xfree version 4xx
! echo for use with emulation xfree version 3xx
! echo and for emulation useit mv text mode

.c.run:
	@cc -c $(*B).c
	@cc -c mkp.c
	@cc -o $@ $(*B).o mkp.o
	@./$@
	chmod +x $(*B)
	cp $(*B) /home/abal64/cico/lib

xfree324.run: xfree324.c
xfree424.run: xfree424.c

xfree325.run: xfree325.c
xfree425.run: xfree425.c

xfree340.run: xfree340.c
xfree440.run: xfree440.c

xfree3dyn.run: xfree3dyn.c
xfree4dyn.run: xfree4dyn.c

useitmv24.run: useitmv24.c
useitmv25.run: useitmv25.c
useitmv40.run: useitmv40.c

! make

xcico.run: xcico.c
xcicodyn.run: xcicodyn.c
cgi.run: cgi.c
cgi-plain.run: cgi-plain.c
cgi-html.run: cgi-html.c
html.run: html.c
xmimo.run: xmimo.c

! make

