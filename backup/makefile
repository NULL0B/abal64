PRODUCT = $(ABAL)/product/abal3.tgz

abal32.tgz: makefile             '
        $(PRODUCT)               '
        $(ABAL)/fonts   '
        $(ABAL)/images  '
        $(ABAL)/src     '
	tar -czf $@ $(ABAL)/makefile $(ABAL)/src $(ABAL)/include $(ABAL)/*/makefile* $(ABAL)/*/*.mf $(ABAL)/*/mf/*.mf $(ABAL)/*/*.def $(ABAL)/*/*.sng $(ABAL)/*/*.3d $(ABAL)/fonts/*.fmf $(ABAL)/images/*.rgb $(ABAL)/images/*.gif
#	scp $@ jamie@172.17.160.50:/home/jamie
#	scp $@ root@172.17.110.95:/home/Dev
! error
! make
abal32.tar: makefile             '
        $(PRODUCT)               '
        $(ABAL)/fonts   '
        $(ABAL)/images  '
        $(ABAL)/src     '
	tar -cf $@ $(ABAL)/makefile $(ABAL)/src $(ABAL)/include $(ABAL)/*/makefile* $(ABAL)/*/*.mf $(ABAL)/*/mf/*.mf $(ABAL)/*/*.def $(ABAL)/*/*.sng $(ABAL)/*/*.3d $(ABAL)/fonts/*.fmf $(ABAL)/images/*.rgb $(ABAL)/images/*.gif
! make


