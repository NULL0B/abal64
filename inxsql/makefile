# --------------------------------------------
# INXSQL DATABASE ENGINE TYPE
# --------------------------------------------
# To set the DATABASE ENGINE type for INXSQL
# ABALSQL can be set as ABALMYSQL or ABALPGSQL 
# It should not be UNSET or Exception Here
# if set to NONE it will select DEFAULT MYSQL
# --------------------------------------------
$(ABALSQL) = TRUE
# --------------------------------------------
# The rest of the standard Makefile stuff
# --------------------------------------------
! include $(ABAL)/common/allocate.def
! include $(ABAL)/common/inxsql.def

LIBRARY = $(ALLOCATE) $(LIBSQL)
OPTIONS = -fPIC -DUNIX $(DEFSQL) -D_INXS_STUB_A -D_INXS_STUB_SQ -DENGINE=$(INXSENGINE)
SP01 = $(ABAL)/src/inxsql

inxsql.o: '
        $(SP01)/inxsql.c '
        $(SP01)/inxsql.h '
        $(SP01)/inxsql_lock.c '
        $(SP01)/inxsql_file.c '
        $(SP01)/inxsql_base.c '
        $(SP01)/inxsql_index.c '
        $(SP01)/inxsql_record.c '
        $(SP01)/inxsql_join.c '
        $(SP01)/inxsql_view.c '
        $(SP01)/inxsql_table.c '
        $(SP01)/inxsql_field.c '
        $(SP01)/inxsql_query.c
	gcc -g -ggdb -c $(OPTIONS) $(SP01)/inxsql.c

libinxsql.o: $(SP01)/libinxsql.c $(SP01)/inxsql.h
	gcc -g -ggdb -c $(OPTIONS) $(SP01)/libinxsql.c


$(ABAL)/lib/libinxsql64.so: libinxsql.o inxsql.o
	gcc -g -ggdb -shared -o $@ $? $(LIBRARY)
	echo "DATABASE = "$@ > $(ABAL)/common/database.def

! make
! ifdef genqinx

qinx.o: $(SP01)/qinx.c 
	gcc -g -ggdb -c $(OPTIONS) $(SP01)/qinx.c

../bin/qinx: qinx.o 
	gcc -g -ggdb -o $@ $? /lib/libinxsql64.so $(LIBRARY)
	cp $@ /bin
	tar -czvf /tmp/inxsql.tgz *
! make
! endif
