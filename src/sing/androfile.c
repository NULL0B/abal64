/*      ---------------------------------       */
/*      Android Files Production for SING       */
/*      ---------------------------------       */
/*      Copyright (c) 2015 Amenesik             */
/*      ---------------------------------       */
/*      Author    Iain James Marshall           */
/*      ---------------------------------       */

#ifndef	_androfile_c
#define	_androfile_c

#define	_JAVA_MC_BASECLASS	"mcFile"

/*	-------------------------------------------------------		*/
/*	a n d r o i d _ d a t a b a s e _ d e s c r i p t i o n 	*/
/*	-------------------------------------------------------		*/
private	struct	data_control * android_database_description( struct form_item * iptr, char * classname, int * fields )
{
        int                     item=0;
        struct  data_control *  dptr=(struct data_control *) 0;
        char            *       cptr;
        char            *       nptr;
        int                     i;
                
        if ((iptr->Contents.style & _FRAME_TYPE ) != _DATA_FRAME )
		return((struct data_control *) 0 );
	else if (!( is_file_Widget( iptr ) ))
		return((struct data_control *) 0 );
	else if (!(dptr = iptr->Contents.extra ))
		return((struct data_control *) 0 );
	else if (!( *fields = dptr->indexfields + dptr->datafields ))
		return((struct data_control *) 0 );
	else if (!( cptr = iptr->Contents.format ))
		return((struct data_control *) 0 );
	else if ( *(cptr++) != '(' )
		return((struct data_control *) 0 );
	{
                for (i=0; i < 1023; i++ ) 
		{
                        if ((*cptr == ' ')
                        ||  (*cptr == '.')
                        ||  (*cptr == ',')
                        ||  (*cptr == ';')
                        ||  (*cptr == ':')
                        ||  (*cptr == ')'))
                                break;
                        else 	classname[i] = *(cptr++);
		}
		classname[i] = 0;
		return(dptr);
	}
}

#include "specialsql.c"

/*	-----------------------------------------	*/
/*	r e s e t _ d a t a b a s e _ h e l p e r	*/
/*	-----------------------------------------	*/
private	int	databasehelper=0;
public	void	reset_database_helper()
{
	databasehelper = 0;
	return;
}

/*	-----------------------------------------------		*/
/*	g e n e r a t e _ d a t a b a s e _ i m p o r t 	*/
/*	-----------------------------------------------		*/
private	void	generate_database_import( FILE * h, char * domain, char * package,int sqlcipher )
{
	android_java_package( h, domain, package );
	android_java_import( h, "java.util.*" );
	android_java_import( h, "java.io.*" );
	android_java_import( h, "java.nio.ByteBuffer" );
	android_java_import( h, "java.text.*" );
	android_java_import( h, "android.content.*" );
	android_java_import( h, "android.util.*" );
	android_java_import( h, "android.media.*" );
	android_java_import( h, "android.os.*" );
	if ( sqlcipher & 1)
	{
		android_java_import( h, "net.sqlcipher.Cursor" );
		android_java_import( h, "net.sqlcipher.DatabaseUtils" );
		android_java_import( h, "net.sqlcipher.database.SQLiteDatabase" );
		android_java_import( h, "android.database.sqlite.SQLiteException" );
	}
	else
	{
		android_java_import( h, "android.database.Cursor" );
		android_java_import( h, "android.database.DatabaseUtils" );
		android_java_import( h, "android.database.sqlite.SQLiteDatabase" );
		android_java_import( h, "android.database.sqlite.SQLiteException" );
	}
	android_java_import( h, "android.database.sqlite.SQLiteCursor" );
	android_java_import( h, "android.database.sqlite.SQLiteCantOpenDatabaseException" );
	android_java_import( h, "javax.crypto.Cipher");
	android_java_import( h, "javax.crypto.spec.SecretKeySpec");
	return;
}

/*	-----------------------------------------------		*/
/*	g e n e r a t e _ d a t a b a s e _ c u r s o r 	*/
/*	-----------------------------------------------		*/
private	void	generate_database_cursor( FILE * jh, char * domain, struct form_control * fptr, char * package, char * rootpath )
{
	FILE *	h;
	char *	classname="VisualDatabaseCursor";
	char *	baseclass="SQLiteCursor";
        char	filename[1024];
	if ( databasehelper & 2 )
		return;
        else if (!( h = create_android_file( jh, domain ,fptr, rootpath, classname,"java" ) ))
                return;
	else if (!( generate_android_license( h, domain ) ))
		return;
        else    
	{
		generate_database_import(h,domain,package,0);
		android_java_import( h, "android.database.CursorWindow" );
		android_java_import( h, "android.database.sqlite.SQLiteCursorDriver" );
		android_java_import( h, "android.database.sqlite.SQLiteQuery" );

		fprintf(h,"\nclass %s extends %s \n{\n",classname,baseclass);
		fprintf(h,"\t%s(SQLiteDatabase db,SQLiteCursorDriver driver,String editTable,SQLiteQuery query){ super(db,driver,editTable,query); }\n",
			classname);
		fprintf(h,"\tpublic CursorWindow getVisualCursorWindow()\n{\n\treturn mWindow;\n}\n");
		android_class_footer( h, domain ,classname );
		fclose(h);
		databasehelper |= 2;
		return;
	}
}

/*	----------------------------------------------------------------	*/
/*	g e n e r a t e _ d a t a b a s e _ c u r s o r _ f a c t  o r y 	*/
/*	----------------------------------------------------------------	*/
private	void	generate_database_cursor_factory( FILE * jh, char * domain, struct form_control * fptr, char * package, char * rootpath )
{
	FILE *	h;
	char *	classname="VisualDatabaseCursorFactory";
	char *	baseclass="SQLiteDatabase.CursorFactory";
        char	filename[1024];
	if ( databasehelper & 4 )
		return;
        else if (!( h = create_android_file( jh, domain ,fptr, rootpath, classname,"java" ) ))
                return;
	else if (!( generate_android_license( h, domain ) ))
		return;
        else    
	{
		generate_database_import(h,domain,package,0);
		android_java_import( h, "android.database.sqlite.SQLiteCursorDriver" );
		android_java_import( h, "android.database.sqlite.SQLiteQuery" );
		android_java_import( h, "android.database.sqlite.SQLiteDatabase.CursorFactory" );

		fprintf(h,"\nclass %s extends %s \n{\n",classname,baseclass);
		fprintf(h,"%s()\n{\n}\n",classname);
		fprintf(h,"@Override\npublic VisualDatabaseCursor newCursor(SQLiteDatabase database,SQLiteCursorDriver driver,String editTable,SQLiteQuery query)\n");
		fprintf(h,"{\n\treturn new VisualDatabaseCursor(database,driver,editTable,query);\n}\n");
		android_class_footer( h, domain ,classname );
		fclose(h);
		databasehelper |= 4;
		return;
	}
}

/*	-----------------------------------------------------	*/
/*	g e n e r a t e _ d a t a b a s e _ b a s e c l a s s 	*/
/*	-----------------------------------------------------	*/
private	void	generate_database_baseclass( FILE * jh, char * domain, struct form_control * fptr, char * package, char * rootpath, int sqlcipher )
{
	FILE *	h;
	char *	classname="VisualDatabaseHelper";
        char	filename[1024];

	if ( sqlcipher & 2 )
	{
		generate_database_cursor(jh,domain,fptr,package,rootpath );
	}

	if ( databasehelper  & 1 )
		return;
        else if (!( h = create_android_file( jh, domain ,fptr, rootpath, classname,"java" ) ))
                return;
	else if (!( generate_android_license( h, domain ) ))
		return;
        else    
	{
		databasehelper |= 1;

		generate_database_import(h,domain,package,sqlcipher&1);
		android_java_import( h, "android.database.sqlite.SQLiteCursorDriver" );
		android_java_import( h, "android.database.sqlite.SQLiteQuery" );
		android_java_import( h, "android.database.sqlite.SQLiteDatabase.CursorFactory" );

		fprintf(h,"\nclass %s \n{\n",classname);

		/* ---------------- */
		/* standard members */
		/* ---------------- */

		fprintf(h,"protected static SQLiteDatabase database=null;\n");
		fprintf(h,"protected static int users=0;\n");
		if ( sqlcipher  & 2 )
		{
			fprintf(h,"protected static SQLiteDatabase.CursorFactory factory = null;\n"); 
			fprintf(h,"protected boolean encryption=false;\n");
			fprintf(h,"protected boolean autoencrypt=false;\n");
			fprintf(h,"protected byte [] key=null;\n");
			fprintf(h,"protected String keyname=\"\";\n");
		}	
		fprintf(h,"public String  tableName=\"filename\";\n");
		fprintf(h,"public String  basePath=\"\";\n");
		fprintf(h,"public String  baseName=\"database\";\n");
		fprintf(h,"public String  baseExtension=\".db\";\n");
		fprintf(h,"public String  userName=\"admin\";\n");
		fprintf(h,"public String  passWord=\"admin\";\n");
		fprintf(h,"public int dberror=0;\n");


		android_java_comment(h,"Constructor ","Method" );
		fprintf(h,"%s(String dbpath,String dbname,String tbname)\n{\n",classname);
		fprintf(h,"\tusers++;\n");
		fprintf(h,"\tbasePath = dbpath;\n");
		fprintf(h,"\tbaseName = basePath+\"/\"+dbname+baseExtension;\n");
		fprintf(h,"\ttableName = tbname;\n");
		if ( sqlcipher & 2 )
		{
			fprintf(h,"\tif ( factory == null )\n\t{\n");
			fprintf(h,"\t\tfactory = new SQLiteDatabase.CursorFactory() {\n");
			fprintf(h,"@Override public VisualDatabaseCursor newCursor(SQLiteDatabase db,SQLiteCursorDriver d,String e,SQLiteQuery q) { return new VisualDatabaseCursor(db,d,e,q); }\n};\n");
			fprintf(h,"\t}\n");
		}

		fprintf(h,"\tif ( database == null )\n\t{\n");
		if (!( sqlcipher & 1 ))
		{
			fprintf(h,"\ttry { database = SQLiteDatabase.openDatabase( baseName, ");
			if ( sqlcipher & 2 )
				fprintf(h,"factory");
			else	fprintf(h,"null");
			fprintf(h,", SQLiteDatabase.OPEN_READWRITE | SQLiteDatabase.CREATE_IF_NECESSARY ); }\n");
		}
		else
		{
			fprintf(h,"\ttry { database = SQLiteDatabase.openOrCreateDatabase( baseName, baseName, null ); dberror = 0; }\n");
		}
		fprintf(h,"\tcatch (SQLiteCantOpenDatabaseException e) { dberror = 40; }\n");
		fprintf(h,"\t}\n");
		fprintf(h,"}\n");

		android_java_comment(h,"Destructor","Method" );
		fprintf(h,"public void OnDestroy()\n{\n");
		fprintf(h,"\tif ( database != null )\n");
		fprintf(h,"\t{\n\t\tif ( users > 0 ) users--;\n\t\tif ( users ==0 ) { database.close(); database=null; }\n\t}\n");
		fprintf(h,"}\n");
		android_class_footer( h, domain ,classname );
		fclose(h);
		return;
	}

}

private	void	single_eid_response( FILE * h, struct data_control * dptr )
{
	int	i;
	fprintf(h,"\t\tif ( $F->error == 0 ) {\n");
	fprintf(h,"\t$response = $F->error");
	for (	i=0;
		i < dptr->indexfields;
		i++ )
		fprintf(h,".\"|\".$F->_%s",dptr->name[i]);
	for (	i=0;
		i < dptr->datafields;
		i++ )
		fprintf(h,".\"|\".$F->_%s",dptr->name[i+dptr->indexfields]);
	fprintf(h,".\"\\n\";\n");
	fprintf(h,"\t\t} else { $response .= $F->error.\"\\n\"; }\n");
	fprintf(h,"\t\t$a= explode( \"\\n\", $response );\n");
	fprintf(h,"\t\t$record = implode(\";\", $a);\n");
	fprintf(h,"\t\t$a= explode( \"\\r\", $record );\n");
	fprintf(h,"\t\t$record = implode(\"\", $a);\n");
	fprintf(h,"\t\t$a= explode( \"\\t\", $record );\n");
	fprintf(h,"\t\t$response= implode(\" \", $a);\n");
	fprintf(h,"\theader(\"Content-Type: text/plain\");\n");
	fprintf(h,"\theader(\"Content-Length: \".strlen($response));\n");
	fprintf(h,"\tprint $response;\n");
	return;
}

private	void	simple_e_response( FILE * h	) 
{
	fprintf(h,"\t$response = $F->error");
	fprintf(h,".\"\\n\";\n");
	fprintf(h,"\theader(\"Content-Type: text/plain\");\n");
	fprintf(h,"\theader(\"Content-Length: \".strlen($response));\n");
	fprintf(h,"\tprint $response;\n");
}

public  int	generate_remote_php_file( 
	struct form_control * fptr , 
	struct form_item * iptr, 
	struct data_control * dptr,
	char * classname )
{
	FILE * h;
	int	i;
	char	tempname[2048];
	char *	databasename="database";
	char *	filename="filebase";
	sprintf(tempname,"remote-%s.php",classname);
	if ((h = fopen( tempname, "w")) != (FILE *) 0)
	{
		fprintf(h,"<?php\n");
		fprintf(h,"\t/* REMOTE FILE API for %s */\n",classname);

		fprintf(h,"\trequire_once(\"sing/html.inc\");\n");
		fprintf(h,"\trequire_once(\"sing/http.inc\");\n");
		fprintf(h,"\trequire_once(\"sing/soaparser.inc\");\n");
		fprintf(h,"\trequire_once(\"sing/soapclient.inc\");\n");
		fprintf(h,"\trequire_once(\"sing/visual.inc\");\n");
		fprintf(h,"\trequire_once(\"%s.inc\");\n",classname);

		fprintf(h,"\t$dtname=$_REQUEST['file'];\n");
		fprintf(h,"\t$dbname=$_REQUEST['base'];\n");
		fprintf(h,"\t$F = new %s($dbname,$dtname);\n",classname);
		fprintf(h,"\t$method=$_REQUEST['method'];\n");

		/* DELETE */
		fprintf(h,"\tif ( $method == 'DELETE' )\n\t{\n");
		fprintf(h,"\t/* %s.DELETE */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urlecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);
			fprintf(h,"\t$F->OnDelete();\n");
			simple_e_response(h);

		/* FIRST  */
		fprintf(h,"\t}\n\telse if ( $method == 'FIRST' )\n\t{\n");
		fprintf(h,"\t/* %s.FIRST */\n",classname);
			fprintf(h,"\t$F->OnFirst();\n");
			single_eid_response( h, dptr );

		/* PREVIOUS */
		fprintf(h,"\t}\n\telse if ( $method == 'PREVIOUS' )\n\t{\n");
		fprintf(h,"\t/* %s.PREVIOUS */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urldecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);
			fprintf(h,"\t$F->OnPrevious();\n");
			single_eid_response( h, dptr );

		/* NEXT */
		fprintf(h,"\t}\n\telse if ( $method == 'NEXT' )\n\t{\n");
		fprintf(h,"\t/* %s.NEXT */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urldecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);
			fprintf(h,"\t$F->OnNext();\n");
			single_eid_response( h, dptr );

		/* LAST */
		fprintf(h,"\t}\n\telse if ( $method == 'LAST' )\n\t{\n");
		fprintf(h,"\t/* %s.LAST */\n",classname);
			fprintf(h,"\t$F->OnLast();\n");
			single_eid_response( h, dptr );

		/* SEARCH */
		fprintf(h,"\t}\n\telse if ( $method == 'SEARCH' )\n\t{\n");
		fprintf(h,"\t/* %s.SEARCH */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urldecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);
			fprintf(h,"\t$F->OnSearch();\n");
			single_eid_response( h, dptr );

		/* INSERT */
		fprintf(h,"\t}\n\telse if ( $method == 'INSERT' )\n\t{\n");
		fprintf(h,"\t/* %s.INSERT */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urldecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);

			for (	i=0;
				i < dptr->datafields;
				i++ )
			{
				fprintf(h,"\tif ( isset ( $_REQUEST['%s'] ) ) ",dptr->name[i+dptr->indexfields]);
				fprintf(h,"{ $F->_%s = urldecode($_REQUEST['%s']); }\n" ,dptr->name[i+dptr->indexfields],dptr->name[i+dptr->indexfields]);
			}
			fprintf(h,"\t$F->OnInsert();\n");
			simple_e_response(h);

		fprintf(h,"\t}\n\telse if ( $method == 'UPDATE' )\n\t{\n");
		fprintf(h,"\t/* %s.UPDATE */\n",classname);
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,"\t$F->_%s = urldecode($_REQUEST['%s']);\n",dptr->name[i],dptr->name[i]);

			for (	i=0;
				i < dptr->datafields;
				i++ )
			{
				fprintf(h,"\tif ( isset ( $_REQUEST['%s'] ) ) ",dptr->name[i+dptr->indexfields]);
				fprintf(h,"{ $F->_%s = urldecode($_REQUEST['%s']); }\n" ,dptr->name[i+dptr->indexfields],dptr->name[i+dptr->indexfields]);
			}
			fprintf(h,"\t$F->OnModif();\n");
			simple_e_response(h);

		fprintf(h,"\t}\n\telse if ( $method == 'SELECT' )\n\t{\n");
		fprintf(h,"\t/* %s.SELECT */\n",classname);

			fprintf(h,"\t$response = \"\";\n");
			fprintf(h,"\t$F->question = urldecode($_REQUEST['question']);\n");
			fprintf(h,"\t$F->OnCollect();\n");
			fprintf(h,"\tfor ( $i=1; $i <= $F->response; $i = $i + 1 )\n\t{\n");
			fprintf(h,"\t\t$F->OnLocate($i);\n");
			fprintf(h,"\t\t$response .= $F->error");
			for (	i=0;
				i < dptr->indexfields;
				i++ )
				fprintf(h,".\"|\".$F->_%s",dptr->name[i]);
			for (	i=0;
				i < dptr->datafields;
				i++ )
				fprintf(h,".\"|\".$F->_%s",dptr->name[i+dptr->indexfields]);
			fprintf(h,".\"\\n\";\n");
	
			fprintf(h,"\t}\n");
			fprintf(h,"\theader(\"Content-Type: text/plain\");\n");
			fprintf(h,"\theader(\"Content-Length: \".strlen($response));\n");
			fprintf(h,"\tprint $response;\n");

		fprintf(h,"\t}\n\telse { die('incorrect request method'); }\n");
		fprintf(h,"?>");
		fclose(h);
	}
	return(0);
}


/*	-------------------------------------------	*/
/*	a n d r o i d - d a t a b a s e _ c l a s s 	*/
/*	-------------------------------------------	*/
public  int	android_database_class( FILE * jh, char *	domain, struct form_control * fptr , struct form_item * iptr, char * pathroot, char * package, int sqlcipher )
{
        FILE * 	h;
        char	classname[1024];
        char	filename[1024];
	struct data_control * dptr;
        int    fields=0;
	int	i;
	int	sep='(';
	char *	sptr;
	char	rootpath[2048];
	int	isocci=0;
	int	textplain=0;
	char *	prefix="";

	if ((iptr->Contents.align & 0x000F) == _OCCI_FRAME )
		isocci = 1;
	else if ((iptr->Contents.align & 0x000F) == _OCCI_MIRROR )
		isocci = 2;
	else if ((iptr->Contents.align & 0x000F) == _PHP_REPLICATE )
		isocci = 4;
	else	isocci = 0;

	sprintf(rootpath,"%s/%s",pathroot,"java");
        strcat(rootpath,"/");
        strcat(rootpath,domain);
        strcat(rootpath,"/");
        strcat(rootpath,package);
        for ( i = 0; rootpath[i]!= 0; i++ )
                if ( rootpath[i] == '.' )
                        rootpath[i] = '/';

	/* ---------------------------------- */
	/* collect database table information */
	/* ---------------------------------- */
	if (!( dptr = android_database_description( iptr, classname, &fields) ))
		return;
	else	printf("database(%s,%s)\r\n",classname,(sqlcipher&1?"SqlCipher":"SQLite"));

	generate_database_baseclass( jh, domain, fptr, package, rootpath, sqlcipher );

	if (!( fields ))
		return;
	else if (!( strlen( classname ) ))
		return;
        else if (!( h = create_android_file( jh, domain ,fptr, rootpath, classname,"java" ) ))
                return;
	else if (!( generate_android_license( h, domain ) ))
		return;
        else    
	{
		/* --------------------------------------------- */
		/* generate the remote php replication interface */
		/* --------------------------------------------- */
		if ( isocci & 4 )
			generate_remote_php_file( fptr, iptr, dptr, classname );

		/* --------------------------- */
		/* database table class header */
		/* --------------------------- */
		generate_database_import(h,domain,package,sqlcipher&1);

		if ( isocci )
		{
			if (!( isocci & 4 ))
				prefix="_";
			android_java_import(h,"java.security.cert.*");
			android_java_import(h,"java.security.*");
			android_java_import(h,"java.net.*");
			android_java_import(h,"javax.net.ssl.*");
			android_java_import(h,"android.net.*");
		}

		/* ------------------- */
		/* check for pure OCCI */
		/* ------------------- */
		if ( isocci & 1 )
		{
			fprintf(h,"\nclass %s \n{\n",classname);
		}
		else
		{
			/* ----------------------------- */
			/* file or hybrid requires these */
			/* ----------------------------- */
			fprintf(h,"\nclass %s extends %s \n{\n",classname,"VisualDatabaseHelper");
			fprintf(h,"public String[]parameters=null;\n");
			fprintf(h,"public ArrayList<String> answer=null;\n");
			if ( sqlcipher & 2 )
				fprintf(h,"public VisualDatabaseCursor cursor=null;\n");
			else	fprintf(h,"public Cursor cursor=null;\n");
		}

		/* ----------------------- */
		/* standard members of all */
		/* ----------------------- */
		fprintf(h,"public String  question=\"\";\n");
		fprintf(h,"public int error=0;\n");
		fprintf(h,"public int response=0;\n");
		fprintf(h,"private DecimalFormat formater;\n");

		/* ------------------------------- */
		/* communication control variables */
		/* ------------------------------- */
		if ( isocci )
		{
			fprintf(h,"public String hostname=\"\";\n");
			fprintf(h,"public String basicAuth=null;\n");
			if ( isocci < 4 )
			{
				fprintf(h,"public String authorization=null;\n");
				fprintf(h,"public String category=\"\";\n");
				fprintf(h,"public String source=\"\";\n");
				fprintf(h,"public String target=\"\";\n");
				fprintf(h,"public String location=\"\";\n");
			}
			else
			{
				fprintf(h,"public String apiRoot=\"/\";\n");
				fprintf(h,"public String httpAnswer=\"/\";\n");
				fprintf(h,"public String remoteBase=\"/\";\n");
				fprintf(h,"public String remoteFile=\"/\";\n");
				fprintf(h,"public Boolean remoteActive=false;\n");
			}
			fprintf(h,"public int timeOut=5000;\n");
			fprintf(h,"public int parts=0;\n");
			fprintf(h,"public ArrayList<String> query=null;\n");
			fprintf(h,"public int links=0;\n");
			fprintf(h,"public ArrayList<String> linkage=null;\n");
			fprintf(h,"public int items=0;\n");
			fprintf(h,"public ArrayList<String> list=null;\n");
		}

		/* ----------------------------------------------- */
		/* generate the data collection member description */
		/* ----------------------------------------------- */
		for (	i=0;
			i < dptr->indexfields;
			i++ )
			fprintf(h,"public String %s=\"\";\n",dptr->name[i]);
		for (	i=0;
			i < dptr->datafields;
			i++ )
			fprintf(h,"public String %s%s=\"\";\n",prefix,dptr->name[i+dptr->indexfields]);

		/* ----------------------------------- */
		/* generate the database table methods */
		/* ----------------------------------- */
		android_java_comment(h,"Constructor ","Method" );
		if (!( isocci & 1 ))
		{
			fprintf(h,"%s(String dbpath,String dbname,String tbname)\n{\n",classname);
			fprintf(h,"\tsuper(dbpath,dbname,tbname);\n");
			if ( isocci & 2 )
			{
				fprintf(h,"\tcategory = tbname;\n");
				fprintf(h,"\thostname = \"http://127.0.0.1\";\n");
			}
			if ( isocci & 4 )
			{
				fprintf(h,"\tremoteBase = dbname;\n");
				fprintf(h,"\tremoteFile = tbname;\n");
			}
			fprintf(h,"\tformater = new DecimalFormat(\"00000000\");\n");
			fprintf(h,"}\n");

			android_java_comment(h,"Destructor","Method" );
			fprintf(h,"public void OnDestroy()\n{\n");
			fprintf(h,"\tsuper.OnDestroy();\n");
			fprintf(h,"}\n");
		}
		else
		{
			fprintf(h,"%s(String hn, String cn)\n{\n",classname);
			fprintf(h,"\thostname = hn;\n");
			fprintf(h,"\tcategory = cn;\n");
			fprintf(h,"\tformater = new DecimalFormat(\"00000000\");\n");
			fprintf(h,"}\n");

			android_java_comment(h,"Destructor","Method" );
			fprintf(h,"public void OnDestroy()\n{\n");
			fprintf(h,"}\n");
		}

		/* ---------------------- */
		/* reset instance members */
		/* ---------------------- */
		android_java_comment(h,"Reset","Database Table");
		fprintf(h,"public void OnReset()\n{\n");
		for (	i=0;
			i < dptr->datafields;
			i++ )
			fprintf(h,"\t%s%s=\"\";\n",prefix,dptr->name[i+dptr->indexfields]);
		fprintf(h,"}\n");

		/* ----------------------------------------------- */
		/* check for OCCI communication functions required */
		/* ----------------------------------------------- */
		if ( isocci & 4 )
		{
			/* ------------------- */
			/* set server hostname */
			/* ------------------- */
			android_java_comment(h,"Set","Host Name" );
			fprintf(h,"public void OnHost(String n)\n{\n");
			fprintf(h,"\thostname = n;\n");
			fprintf(h,"}\n");

			/* ------------------- */
			/* set connect timeout */
			/* ------------------- */
			android_java_comment(h,"Set","Connect Time Out" );
			fprintf(h,"public void OnTimeOut(int n)\n{\n");
			fprintf(h,"\ttimeOut = n;\n");
			fprintf(h,"}\n");
	
			/* ------------------- */
			/* set remote status   */
			/* ------------------- */
			android_java_comment(h,"Set","Remote Status" );
			fprintf(h,"public void OnRemote(Boolean n)\n{\n");
			fprintf(h,"\tremoteActive = n;\n");
			fprintf(h,"}\n");
	
			/* ----------------------- */
			/* set basic authorisation */
			/* ----------------------- */
			android_java_comment(h,"Set","BasicAuth" );
			fprintf(h,"public void OnBasic(String u,String p)\n{\n");
			fprintf(h,"\tString s=u+\":\"+p;\n");
			fprintf(h,"\tbasicAuth = \"Basic \"+Base64.encodeToString(s.getBytes(),Base64.DEFAULT|Base64.NO_WRAP);\n");
			fprintf(h,"}\n");
	
			/* ------------------------------------ */
			/* the generic HTTP communicator method */
			/* ------------------------------------ */
			android_java_comment(h,"read","Stream");
			fprintf(h,"private String readStream(InputStream in,int bytes)\n{\n");
			fprintf(h,"\tint received=0;\n");
			fprintf(h,"\tint l=0;\n");
			fprintf(h,"\tbyte [] buffer = new byte[bytes];\n");
			fprintf(h,"\ttry\n\t{\n");
			fprintf(h,"\t\twhile ( received != bytes )\n\t\t{\n");
			fprintf(h,"\t\t\tl =in.read(buffer,received,bytes-received);\n");
			fprintf(h,"\t\t\tif ( l >= 0 ) { received = received + l; } else { break; }\n");
			fprintf(h,"\t\t}\n\t\treturn new String( buffer );\n");
			fprintf(h,"\t} catch ( IOException e  ) { return \"\"; }\n}\n");
			/* ------------------------------------ */
			/* the generic HTTP communicator method */
			/* ------------------------------------ */
			android_java_comment(h,"HTTP","Request");
			fprintf(h,"private int HttpRequest(String u)\n{\n");
			fprintf(h,"\thttpAnswer=\"\";\n");
			fprintf(h,"\ttry\n\t{\n");
			fprintf(h,"\t\tURL url = new URL( u );\n");
			fprintf(h,"\t\tString m=\"GET\";\n");
			fprintf(h,"\t\tint httpStatus=500;\n");
			fprintf(h,"\t\ttry\n\t\t{\n");
			fprintf(h,"\t\t\tHttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();\n");
			fprintf(h,"\t\t\turlConnection.setRequestProperty(\"Accept-Encoding\",\"identity\");\n");
			fprintf(h,"\t\t\tif ( basicAuth != null ) { urlConnection.setRequestProperty(\"Authorization\",basicAuth); }\n");
			/* -------------- */
			/* LAUNCH Request */
			/* -------------- */
			fprintf(h,"\t\t\ttry\n\t\t\t{\n");
			fprintf(h,"\t\t\t\tInputStream in = new BufferedInputStream(urlConnection.getInputStream());\n");
			fprintf(h,"\t\t\t\terror = urlConnection.getResponseCode();\n");
			fprintf(h,"\t\t\t\tint contentLength = urlConnection.getContentLength();\n");
			fprintf(h,"\t\t\t\tString contentType = urlConnection.getContentType();\n");
			fprintf(h,"\t\t\t\tif ( contentLength > 0 ) { httpAnswer = readStream(in,contentLength); }\n");
			fprintf(h,"\t\t\t} catch ( IOException e  ) { error = urlConnection.getResponseCode(); }\n");
			fprintf(h,"\t\t\turlConnection.disconnect();\n");
			fprintf(h,"\t\t} catch ( IOException e  ) { error = 666; }\n");
			fprintf(h,"\t} catch ( IOException e  ) { error = 600; }\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE FIRST  */
			/* ------------- */
			android_java_comment(h,"Remote","First");
			fprintf(h,"public int OnRemoteFirst()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=FIRST\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	
				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=0;\n");
				fprintf(h,"\t\tString e = fields[field++];\n");
				fprintf(h,"\t\terror = Integer.parseInt( e );\n");
				fprintf(h,"\t\tif ( error == 0 )\n\t\t{\n");
				for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\t\tOnUpdate();\n");
				fprintf(h,"\t\t}\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");


			/* ----------- */
			/* HTML ENCODE */
			/* ----------- */
			android_java_comment(h,"Html","Encode");
			fprintf(h,"private String HtmlEncode( String raw, String fmt )\n{\n");
			fprintf(h,"\ttry\n\t{\n");
			fprintf(h,"\t\treturn URLEncoder.encode( raw, fmt );\n");
			fprintf(h,"\t} catch ( Exception e ) { return raw; }\n");
			fprintf(h,"}\n");

			/* --------------- */
			/* REMOTE PREVIOUS */
			/* --------------- */
			android_java_comment(h,"Remote","Previous");
			fprintf(h,"public int OnRemotePrevious()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=PREVIOUS\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	
				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=0;\n");
				fprintf(h,"\t\tString e = fields[field++];\n");
				fprintf(h,"\t\terror = Integer.parseInt( e );\n");
				fprintf(h,"\t\tif ( error == 0 )\n\t\t{\n");
				for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\t\tOnUpdate();\n");
				fprintf(h,"\t\t}\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");

			/* ----------- */
			/* REMOTE NEXT */
			/* ----------- */
			android_java_comment(h,"Remote","Next");
			fprintf(h,"public int OnRemoteNext()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=NEXT\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	
				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=0;\n");
				fprintf(h,"\t\tString e = fields[field++];\n");
				fprintf(h,"\t\terror = Integer.parseInt( e );\n");
				fprintf(h,"\t\tif ( error == 0 )\n\t\t{\n");
				for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\t\tOnUpdate();\n");
				fprintf(h,"\t\t}\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");

			/* ----------- */
			/* REMOTE LAST */
			/* ----------- */
			android_java_comment(h,"Remote","Last");
			fprintf(h,"public int OnRemoteLast()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=LAST\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	
				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=0;\n");
				fprintf(h,"\t\tString e = fields[field++];\n");
				fprintf(h,"\t\terror = Integer.parseInt( e );\n");
				fprintf(h,"\t\tif ( error == 0 )\n\t\t{\n");
				for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\t\tOnUpdate();\n");
				fprintf(h,"\t\t}\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE SEARCH */
			/* ------------- */
			android_java_comment(h,"Remote","Search");
			fprintf(h,"public int OnRemoteSearch()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=SEARCH\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	
				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=0;\n");
				fprintf(h,"\t\tString e = fields[field++];\n");
				fprintf(h,"\t\terror = Integer.parseInt( e );\n");
				fprintf(h,"\t\tif ( error == 0 )\n\t\t{\n");
				for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\t\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\t\tOnUpdate();\n");
				fprintf(h,"\t\t}\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\treturn error;\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE SELECT */
			/* ------------- */
			android_java_comment(h,"Remote","Select");
			fprintf(h,"public int OnRemoteSelect()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=SELECT&question=\"+HtmlEncode(question,\"utf-8\");\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			fprintf(h,"\tint status = HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"\tif ( status != 200 ) { return status; }\n");
			fprintf(h,"\tremoteActive = false;\n");

			fprintf(h,"\tString [] lines = httpAnswer.split(\"\\n\");\n");
			fprintf(h,"\tfor ( String l : lines )\n\t{\n");	

				fprintf(h,"\t\tString [] fields = l.split(\"\\\\|\");\n");
				fprintf(h,"\t\tint field=1;\n");
				for (	i=0; i < dptr->indexfields; i++ )
					fprintf(h,"\t\t%s = fields[field++];\n",dptr->name[i]);
				fprintf(h,"\t\tOnDelete();\n");
				for (	i=0; i < dptr->datafields; i++ )
					fprintf(h,"\t\t%s = fields[field++];\n",dptr->name[i+dptr->indexfields]);
				fprintf(h,"\t\tOnInsert();\n");

			fprintf(h,"\t}\n");

			fprintf(h,"\tremoteActive = true;\n");
			fprintf(h,"\treturn 0;\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE INSERT */
			/* ------------- */
			android_java_comment(h,"Remote","Insert");
			fprintf(h,"public int OnRemoteInsert()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=INSERT\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i+dptr->indexfields],dptr->name[i+dptr->indexfields]);
			fprintf(h,"\treturn HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE UPDATE */
			/* ------------- */
			android_java_comment(h,"Remote","Update");
			fprintf(h,"public int OnRemoteUpdate()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=UPDATE\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			for (	i=0; i < dptr->datafields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i+dptr->indexfields],dptr->name[i+dptr->indexfields]);
			fprintf(h,"\treturn HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"}\n");

			/* ------------- */
			/* REMOTE DELETE */
			/* ------------- */
			android_java_comment(h,"Remote","Delete");
			fprintf(h,"public int OnRemoteDelete()\n{\n");
			fprintf(h,"\tif (!( remoteActive )) { return 666; }\n");
			fprintf(h,"\tString url=\"remote-%s.php?method=DELETE\";\n",classname);
			fprintf(h,"\turl = url+\"&base=\"+remoteBase+\"&file=\"+remoteFile;\n");
			for (	i=0; i < dptr->indexfields; i++ ) fprintf(h,"\turl = url+\"&%s=\"+HtmlEncode(%s,\"utf-8\");\n", dptr->name[i],dptr->name[i]);
			fprintf(h,"\treturn HttpRequest(hostname+apiRoot+url);\n");
			fprintf(h,"}\n");
		}
		else if ( isocci & 3 )
		{
			/* ------------------- */
			/* set server hostname */
			/* ------------------- */
			android_java_comment(h,"Set","Host Name" );
			fprintf(h,"public void OnHost(String n)\n{\n");
			fprintf(h,"\thostname = n;\n");
			fprintf(h,"}\n");
	
			/* ------------------- */
			/* set connect timeout */
			/* ------------------- */
			android_java_comment(h,"Set","Connect Time Out" );
			fprintf(h,"public void OnTimeOut(int n)\n{\n");
			fprintf(h,"\ttimeOut = n;\n");
			fprintf(h,"}\n");
	
			/* ------------------------- */
			/* set accords authorisation */
			/* ------------------------- */
			android_java_comment(h,"Set","AccordsAuth" );
			fprintf(h,"public void OnAuthorize(String a)\n{\n");
			fprintf(h,"\tauthorization= a;\n");
			fprintf(h,"}\n");
	
			/* ----------------------- */
			/* set basic authorisation */
			/* ----------------------- */
			android_java_comment(h,"Set","BasicAuth" );
			fprintf(h,"public void OnBasic(String u,String p)\n{\n");
			fprintf(h,"\tString s=u+\":\"+p;\n");
			fprintf(h,"\tbasicAuth = \"Basic \"+Base64.encodeToString(s.getBytes(),Base64.DEFAULT|Base64.NO_WRAP);\n");
			fprintf(h,"}\n");
	
			/* --------------------- */
			/* set certificate trust */
			/* --------------------- */
			android_java_comment(h,"On","Trust");
			fprintf(h,"public void OnTrust()\n{\n");
			fprintf(h,"\ttry\n\t{\n");
			fprintf(h,"\t\tHttpsURLConnection.setDefaultHostnameVerifier(new HostnameVerifier(){ \n");
			fprintf(h,"\t\t\tpublic boolean verify(String hostname, SSLSession session) { \n");
			fprintf(h,"\t\t\t\treturn true; }}); \n");
			fprintf(h,"\t\tSSLContext context = SSLContext.getInstance(\"TLS\"); \n");
			fprintf(h,"\t\tcontext.init(null, new X509TrustManager[]{new X509TrustManager(){ \n");
			fprintf(h,"\t\t\tpublic void checkClientTrusted(X509Certificate[] chain, \n");
			fprintf(h,"\t\t\t\tString authType) throws CertificateException {} \n");
			fprintf(h,"\t\t\tpublic void checkServerTrusted(X509Certificate[] chain, \n");
			fprintf(h,"\t\t\t\tString authType) throws CertificateException {} \n");
			fprintf(h,"\t\t\tpublic X509Certificate[] getAcceptedIssuers() { \n");
			fprintf(h,"\t\t\t\treturn new X509Certificate[0]; \n");
			fprintf(h,"\t\t\t}}}, new SecureRandom()); \n");
			fprintf(h,"\t\tHttpsURLConnection.setDefaultSSLSocketFactory(context.getSocketFactory()); \n");
			fprintf(h,"\t} catch (Exception e) { e.printStackTrace(); } \n");
			fprintf(h,"} \n");

			/* ------------------------------------ */
			/* the generic HTTP communicator method */
			/* ------------------------------------ */
			android_java_comment(h,"HTTP","Request");
			fprintf(h,"private int HttpRequest(String m,String u)\n{\n");
			fprintf(h,"\ttry\n\t{\n");
			fprintf(h,"\t\tURL url = new URL( u );\n");
			fprintf(h,"\t\ttry\n\t\t{\n");
			fprintf(h,"\t\t\tHttpURLConnection urlConnection = (HttpURLConnection) url.openConnection();\n");
			fprintf(h,"\t\t\turlConnection.setConnectTimeout(timeOut);\n");
			fprintf(h,"\t\t\tif ( m.equals(\"LIST\") ) {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestMethod(\"GET\");\n");
			fprintf(h,"\t\t\t} else if ( m.equals(\"ACTION\") ) {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestMethod(\"POST\");\n");
			fprintf(h,"\t\t\t} else if ( m.equals(\"LINK\") ) {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestMethod(\"POST\");\n");
			fprintf(h,"\t\t\t} else if ( m.equals(\"UNLINK\") ) {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestMethod(\"DELETE\");\n");
			fprintf(h,"\t\t\t} else {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestMethod(m);\n");
			fprintf(h,"\t\t\t}\n");
			fprintf(h,"\t\t\turlConnection.setRequestProperty(\"Accept\",\"text/occi\");\n");
			/* -------------- */	
			/* BEFORE REQUEST */
			/* -------------- */	
			fprintf(h,"\t\t\tif ( authorization != null ) { urlConnection.setRequestProperty(\"X-OCCI-AUTHORIZE\",authorization); }\n");
			fprintf(h,"\t\t\telse if ( basicAuth != null ) { urlConnection.setRequestProperty(\"Authorization\",basicAuth); }\n");
			/* ------------------------------ */
			/* LIST requires query parameters */
			/* ------------------------------ */
			fprintf(h,"\t\t\tif ( m.equals(\"LIST\") ) {\n");
			/* --------------------------------- */
			/* LIST may use query for parameters */
			/* --------------------------------- */
			fprintf(h,"\t\t\t\tif ( parts > 0 )\n");
			fprintf(h,"\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\tfor ( int i=0; i < parts; i = i + 1 ) { urlConnection.addRequestProperty(\"X-OCCI-ATTRIBUTE\",query.get(i)); }\n");
			fprintf(h,"\t\t\t\t}\n");
			/* ----------------------------------- */
			/* LIST may use question for parameter */
			/* ----------------------------------- */
			fprintf(h,"\t\t\t\telse if ( question.length() > 0 ) { urlConnection.addRequestProperty(\"X-OCCI-ATTRIBUTE\",question); }\n");
			/* ---------------------------------- */
			/* LINK and UNLINK source and targets */
			/* ---------------------------------- */
			fprintf(h,"\t\t\t} else if (( m.equals(\"LINK\") ) || ( m.equals(\"UNLINK\") )) {\n");
			fprintf(h,"\t\t\t\tif ( source.length() > 0 ) { urlConnection.addRequestProperty(\"X-OCCI-ATTRIBUTE\",\"occi.link.source=\\\"\"+source+\"\\\"\"); }\n");
			fprintf(h,"\t\t\t\tif ( target.length() > 0 ) { urlConnection.addRequestProperty(\"X-OCCI-ATTRIBUTE\",\"occi.link.target=\\\"\"+target+\"\\\"\"); }\n");
			/* ---------------------------------- */
			/* POST and PUT use the MEMBER values */
			/* ---------------------------------- */
			fprintf(h,"\t\t\t} else if (( m.equals(\"POST\") ) || ( m.equals(\"PUT\") )) {\n");
			fprintf(h,"\t\t\t\turlConnection.setRequestProperty(\"Content-Type\",\"text/occi\");\n");
			/* ------------------------------------------------ */
			/* OCCI Member Values will go here for POST and PUT */
			/* ------------------------------------------------ */
			for (	i=0;
				i < dptr->datafields;
				i++ )
			{
				fprintf(h,"\t\t\t\turlConnection.addRequestProperty(\"X-OCCI-ATTRIBUTE\",\"occi.%s.%s=\\\"\"+%s%s+\"\\\"\");\n",
					classname,dptr->name[i+dptr->indexfields], prefix,dptr->name[i+dptr->indexfields]);
			}

			fprintf(h,"\t\t\t}\n");
			/* -------------- */
			/* LAUNCH Request */
			/* -------------- */
			fprintf(h,"\t\t\ttry\n\t\t\t{\n");
			fprintf(h,"\t\t\t\tInputStream in = new BufferedInputStream(urlConnection.getInputStream());\n");
			fprintf(h,"\t\t\t\terror = urlConnection.getResponseCode();\n");

			/* ------------- */	
			/* AFTER REQUEST */
			/* ------------- */	

			/* --------------------------------------------- */
			/* POST returns the LOCATION of the new instance */
			/* --------------------------------------------- */
			fprintf(h,"\t\t\t\tif ( m.equals(\"POST\") ) {\n");
			fprintf(h,"\t\t\t\t\tlocation = urlConnection.getHeaderField(\"X-OCCI-LOCATION\");\n");
			fprintf(h,"\t\t\t\t\tString[] a = location.split(\"/\");\n");
			fprintf(h,"\t\t\t\t\tid = a[4];\n");

			/* ------------------------------------------- */
			/* LIST returns the LOCATIONs of the instances */
			/* ------------------------------------------- */
			fprintf(h,"\t\t\t\t} else if ( m.equals(\"LIST\") ) {\n");
			fprintf(h,"\t\t\t\t\titems=0;\n");
			fprintf(h,"\t\t\t\t\tlist= new ArrayList<String>();\n");
			fprintf(h,"\t\t\t\t\tint n=0;\n");
			fprintf(h,"\t\t\t\t\twhile (n != -1)\n");
			fprintf(h,"\t\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\t\tString field = urlConnection.getHeaderFieldKey(n);\n");
			fprintf(h,"\t\t\t\t\t\tif ( field == null ) { break; }\n");
			fprintf(h,"\t\t\t\t\t\telse if ( field.equalsIgnoreCase(\"X-OCCI-LOCATION\") )\n");
			fprintf(h,"\t\t\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\t\t\tlocation = urlConnection.getHeaderField(n);\n");
			fprintf(h,"\t\t\t\t\t\t\tn=n+1;\n");
			fprintf(h,"\t\t\t\t\t\t\tString[] a = location.split(\"/\");\n");
			fprintf(h,"\t\t\t\t\t\t\tlist.add( a[4] );\n");
			fprintf(h,"\t\t\t\t\t\t\titems=items+1;\n");
			fprintf(h,"\t\t\t\t\t\t}\n");
			fprintf(h,"\t\t\t\t\t\telse { n=n+1; }\n");
			fprintf(h,"\t\t\t\t\t}\n");

			/* ------------------------------------------------ */
			/* GET returns the ATTRIBUTE values for the MEMBERS */
			/* ------------------------------------------------ */
			fprintf(h,"\t\t\t\t} else if ( m.equals(\"GET\") ) {\n");
			fprintf(h,"\t\t\t\t\tint n=0;\n");
			fprintf(h,"\t\t\t\t\tlinks=0;\n");
			fprintf(h,"\t\t\t\t\tlinkage = new ArrayList<String>();\n");
			fprintf(h,"\t\t\t\t\twhile (n != -1)\n");
			fprintf(h,"\t\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\t\tString field = urlConnection.getHeaderFieldKey(n);\n");
			fprintf(h,"\t\t\t\t\t\tif ( field == null ) { break; }\n");
			fprintf(h,"\t\t\t\t\t\telse if ( field.equalsIgnoreCase(\"X-OCCI-ATTRIBUTE\") )\n");
			fprintf(h,"\t\t\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\t\t\tString expression = urlConnection.getHeaderField(n);\n");
			fprintf(h,"\t\t\t\t\t\t\tString[] parts = expression.split( \"=\" );\n");
			fprintf(h,"\t\t\t\t\t\t\tString member = parts[0].trim();\n");
			fprintf(h,"\t\t\t\t\t\t\tString value  = parts[1].trim();\n");
			fprintf(h,"\t\t\t\t\t\t\tvalue  = value.replace(\"\\\"\",\"\");\n");
			fprintf(h,"\t\t\t\t\t\t\tvalue  = value.replace(\"\(null)\",\"\");\n");
			fprintf(h,"\t\t\t\t\t\t\tn=n+1;\n");
			fprintf(h,"\t\t\t\t\t\t\tif ( member.equals(\"occi.core.id\" ) ) { id = value; continue; }\n");
			for (	i=0;
				i < dptr->datafields;
				i++ )
			{
				fprintf(h,"\t\t\t\t\t\t\telse if ( member.equals(\"occi.%s.%s\" ) ) { %s%s = value; continue; }\n",
					classname,dptr->name[i+dptr->indexfields], prefix, dptr->name[i+dptr->indexfields]);
			}
			fprintf(h,"\t\t\t\t\t\t}\n");
			fprintf(h,"\t\t\t\t\t\telse if ( field.equalsIgnoreCase(\"LINK\") )\n");
			fprintf(h,"\t\t\t\t\t\t{\n");
			fprintf(h,"\t\t\t\t\t\t\tString expression = urlConnection.getHeaderField(n);\n");
			fprintf(h,"\t\t\t\t\t\t\tn=n+1;\n");
			fprintf(h,"\t\t\t\t\t\t\tString[] parts = expression.split( \";\" );\n");
			fprintf(h,"\t\t\t\t\t\t\tString value  = parts[0].trim();\n");
			fprintf(h,"\t\t\t\t\t\t\tvalue = value.replace(\"<\",\"\");\n");
			fprintf(h,"\t\t\t\t\t\t\tvalue = value.replace(\">\",\"\");\n");
			fprintf(h,"\t\t\t\t\t\t\tlinkage.add( value );\n");
			fprintf(h,"\t\t\t\t\t\t\tlinks=links+1;\n");
			fprintf(h,"\t\t\t\t\t\t}\n");
			fprintf(h,"\t\t\t\t\t\telse { n=n+1; }\n");
			fprintf(h,"\t\t\t\t\t}\n");
			fprintf(h,"\t\t\t\t}\n");
			fprintf(h,"\t\t\t} catch ( IOException e  ) { error = urlConnection.getResponseCode(); }\n");
			fprintf(h,"\t\t\turlConnection.disconnect();\n");
			fprintf(h,"\t\t} catch ( IOException e  ) { error = 666; }\n");
			fprintf(h,"\t} catch ( IOException e  ) { error = 600; }\n");
			fprintf(h,"\treturn error;\n");

			fprintf(h,"}\n");

			/* -------------------------------------------------------- */
			/* OCCI Merthods : OnGet, OnPost, OnAction, OnPut, OnDelete */
			/* -------------------------------------------------------- */
			android_java_comment(h,"GET","OCCI Request");
			fprintf(h,"public int OnGet(String id)\n{\n");
			fprintf(h,"\terror = HttpRequest(\"GET\",hostname+\"/\"+category+\"/\"+id);\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"POST","OCCI Action");
			fprintf(h,"public int OnAction(String id,String action)\n{\n");
			fprintf(h,"\terror = HttpRequest(\"ACTION\",hostname+\"/\"+category+\"/\"+id+\"?action=\"+action);\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"POST","OCCI Request");
			fprintf(h,"public int OnPost()\n{\n");
			fprintf(h,"\terror = HttpRequest(\"POST\",hostname+\"/\"+category+\"/\");\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"PUT","OCCI Request");
			fprintf(h,"public int OnPut(String id)\n{\n");
			fprintf(h,"\terror = HttpRequest(\"PUT\",hostname+\"/\"+category+\"/\"+id);\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"DELETE","OCCI Request");
			fprintf(h,"public int OnDelete(String id)\n{\n");
			fprintf(h,"\terror = HttpRequest(\"DELETE\",hostname+\"/\"+category+\"/\"+id);\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			/* ------------------------------------------- */
			/* OCCI LIST : OnQuery, OnPart, OnList, OnItem */
			/* ------------------------------------------- */
			android_java_comment(h,"NEW","OCCI List Query ");
			fprintf(h,"public void OnQuery(String value)\n{\n");
			fprintf(h,"\tparts=0;\n");
			fprintf(h,"\tquery = new ArrayList<String>();\n");
			fprintf(h,"}\n");

			android_java_comment(h,"NEW","OCCI List Query Part");
			fprintf(h,"public int OnPart(String value)\n{\n");
			fprintf(h,"\tif ( query == null ) { return 0; }\n");
			fprintf(h,"\tquery.add( value );\n");
			fprintf(h,"\tparts=parts+1;\n");
			fprintf(h,"\treturn parts;\n");
			fprintf(h,"}\n");

			android_java_comment(h,"LIST","OCCI Request");
			fprintf(h,"public int OnList()\n{\n");
			fprintf(h,"\terror = HttpRequest(\"LIST\",hostname+\"/\"+category+\"/\");\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"GET","OCCI List Item");
			fprintf(h,"public int OnItem(int n)\n{\n");
			fprintf(h,"\tif ( list == null ) return 618;\n");
			fprintf(h,"\telse if ( n == 0 )     return 603;\n");
			fprintf(h,"\telse if ( n > items )  return 602;\n");
			fprintf(h,"\telse return OnGet(list.get(n-1));\n");
			fprintf(h,"}\n");

			/* ---------------------------------------- */
			/* OCCI LINKS : OnGetLink, OnLink, OnUnlink */
			/* ---------------------------------------- */
			android_java_comment(h,"GET","OCCI Link");
			fprintf(h,"public String OnGetLink(int n)\n{\n");
			fprintf(h,"\tif ( linkage == null ) return \"\";\n");
			fprintf(h,"\telse if ( n == 0 )     return \"\";\n");
			fprintf(h,"\telse if ( n > links )  return \"\";\n");
			fprintf(h,"\telse return linkage.get(n-1);\n");
			fprintf(h,"}\n");

			android_java_comment(h,"LINK","OCCI Request");
			fprintf(h,"public int OnLink(String t)\n{\n");
			fprintf(h,"\tsource = hostname+\"/\"+category+\"/\"+id;\n");
			fprintf(h,"\ttarget = t;\n");
			fprintf(h,"\terror = HttpRequest(\"LINK\",hostname+\"/\link/\");\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");

			android_java_comment(h,"UNLINK","OCCI Request");
			fprintf(h,"public int OnUnlink(String t)\n{\n");
			fprintf(h,"\tsource = hostname+\"/\"+category+\"/\"+id;\n");
			fprintf(h,"\ttarget = t;\n");
			fprintf(h,"\terror = HttpRequest(\"UNLINK\",hostname+\"/\link/\");\n");
			fprintf(h,"\treturn( error );\n");
			fprintf(h,"}\n");
		}
		/* ------------------------------------- */
		/* check for database functions required */
		/* ------------------------------------- */
		if (!( isocci & 1 ))	
		{	
			/* -------------------------------------- */
			/* check for home made encryption of base */
			/* -------------------------------------- */
			if ( sqlcipher  & 2 )
			{
			android_java_comment(h,"Start","Database Table Data");
			fprintf(h,"public void OnStart(String userkey,String name,boolean automode)\n{\n");
				fprintf(h,"\tbyte [] b = userkey.getBytes();\n");
				fprintf(h,"\tint kl = b.length;\n");
				fprintf(h,"\tif (kl >= 32) { kl = 32; } else if ( kl >= 24 ) { kl = 24; } else { kl = 16; }\n");
				fprintf(h,"\tkey = new byte[kl];\n");
				fprintf(h,"\tfor ( int i=0; i < kl; i=i+1 ) { key[i] = b[i]; }\n");
				fprintf(h,"\tkeyname = name;\n");
				fprintf(h,"\tautoencrypt = automode;\n");
				fprintf(h,"\tencryption=true;\n");
			fprintf(h,"}\n");
	
			fprintf(h,"public String OnHide(String data)\n{\n");
				fprintf(h,"\tif (!( encryption )) { return data; }\n");
				fprintf(h,"\ttry\n\t{\n\t\tSecretKeySpec secret = new SecretKeySpec(key,keyname);\n");
				fprintf(h,"\t\tCipher cipher = Cipher.getInstance(keyname);\n");
				fprintf(h,"\t\tcipher.init(Cipher.ENCRYPT_MODE,secret);\n");
				fprintf(h,"\t\tbyte [] result = cipher.doFinal( data.getBytes() );\n");
				fprintf(h,"\t\treturn Base64.encodeToString( result, Base64.DEFAULT|Base64.NO_WRAP );\n");
				fprintf(h,"\t} catch ( Exception e ) { return \"\"; }\n");
			fprintf(h,"}\n");

			fprintf(h,"public String OnShow(String data)\n{\n");
				fprintf(h,"\tif (!( encryption )) { return data; }\n");
				fprintf(h,"\ttry\n\t{\n\t\tSecretKeySpec secret = new SecretKeySpec(key,keyname);\n");
				fprintf(h,"\t\tCipher cipher = Cipher.getInstance(keyname);\n");
				fprintf(h,"\t\tcipher.init(Cipher.DECRYPT_MODE,secret);\n");
				fprintf(h,"\t\tbyte [] result = cipher.doFinal( Base64.decode( data, Base64.DEFAULT) );\n");
				fprintf(h,"\t\treturn new String( result );\n");
				fprintf(h,"\t} catch ( Exception e ) { return \"\"; }\n");
			fprintf(h,"}\n");
			}

			fprintf(h,"private String autoEnCrypt(String data)\n{\n");
			if ( sqlcipher  & 2)
			{
				fprintf(h,"\t if (!( autoencrypt )) { return( data ); }\n");
				fprintf(h,"\t else { return OnHide( data ); }\n");
			}
			else	fprintf(h,"\treturn(data);\n");
			fprintf(h,"}\n");
	
			fprintf(h,"private String autoDeCrypt(String data)\n{\n");
			if ( sqlcipher  & 2)
			{
				fprintf(h,"\t if (!( autoencrypt )) { return( data ); }\n");
				fprintf(h,"\t else { return OnShow( data ); }\n");
			}
			else	fprintf(h,"\treturn(data);\n");
			fprintf(h,"}\n");
	
			/* --------------------- */
			/* new   database record */
				/* --------------------- */
			android_java_comment(h,"New","Database Record");
			fprintf(h,"public void OnNew()\n{\n");
			fprintf(h,"\tOnLast();\n");
			fprintf(h,"\tOnReset();\n");
			fprintf(h,"\tif ( error == 0 ) { %s  = formater.format(Integer.valueOf(%s)+1); }\n",dptr->name[0],dptr->name[0]);
			fprintf(h,"\telse { %s = \"00000001\"; }\n",dptr->name[0]);
			fprintf(h,"\tOnInsert();\n");
			fprintf(h,"}\n");
	
			/* --------------------- */
			/* create database table */
			/* --------------------- */
			set_special_prefix("x");
			android_java_comment(h,"Create ","Database Table");
			fprintf(h,"public void OnCreate()\n{\n");
			fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
			fprintf(h,"\tString Q=\"CREATE TABLE IF NOT EXISTS \"+tableName+\" ");
			sep = '(';
			for (	i=0;
				i < dptr->indexfields;
				i++ )
			{
				fprintf(h,"%c %s",sep,check_sql_name(dptr->name[i]));
				fprintf(h," CHAR(%u)",dptr->width[i]);
				fprintf(h," PRIMARY KEY");
				sep = ',';
			}
			for (	i=0;
				i < dptr->datafields;
				i++ )
			{
				fprintf(h,"%c %s",sep,check_sql_name(dptr->name[i+dptr->indexfields]));
				fprintf(h," CHAR(%u)",dptr->width[i+dptr->indexfields]);
				sep = ',';
			}
			fprintf(h," )\";\n");
			fprintf(h,"\tdatabase.execSQL(Q);\n");
			fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
		
			android_java_comment(h,"Remove","Database Table");
			fprintf(h,"public void OnRemove()\n{\n");
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString Q=\"DROP TABLE IF EXISTS \"+tableName;\n");
				fprintf(h,"\tdatabase.execSQL(Q);\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
			
			fprintf(h,"private boolean OnFetch(Cursor c)\n{\n");
				fprintf(h,"\tif (!( c.moveToFirst() )) { c.close(); return false; }\n");
				for (	i=0;
					i < dptr->indexfields;
					i++ )
					fprintf(h,"\t%s = c.getString(%u);\n",dptr->name[i],i);
				for (	i=0;
					i < dptr->datafields;
					i++ )
					fprintf(h,"\t%s%s = autoDeCrypt(c.getString(%u));\n",prefix,dptr->name[i+dptr->indexfields],i+dptr->indexfields);
				fprintf(h,"\tc.close(); return true;\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Search","Database Table Record");
			fprintf(h,"public void OnSearch()\n{\n");
				fprintf(h,"if ( %s == null ) { error = 78; return; }\n",dptr->name[0]);
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString[] keyValues = new String[]");
				for (	i=0,sep='{'; i < dptr->indexfields; i++ )
				{
					fprintf(h,"%c%s",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"};\n");
				fprintf(h,"\tCursor results;\n");
				fprintf(h,"\tresults = database.query(tableName,null,");
				sep = '"';
				for (	i=0;
					i < dptr->indexfields;
					i++ )
				{
					fprintf(h,"%c%s=?",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"\",keyValues,null,null,null,\"1\");\n");
				fprintf(h,"\tif (!( OnFetch(results) )) { error = 78; }\n");
				fprintf(h,"\telse { error = 0; }\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
	
			/* --------------------- */		
			/* first database record */
			/* --------------------- */		
			android_java_comment(h,"First","Database Table Record");
			fprintf(h,"public void OnFirst()\n{\n");
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString Q = \"Select Min( %s ) As %s From \"+tableName;\n",dptr->name[0],dptr->name[0]);
				if ( sqlcipher & 2 )
					fprintf(h,"\tVisualDatabaseCursor R = (VisualDatabaseCursor) database.rawQuery( Q, null);\n");
				else	fprintf(h,"\tCursor R = database.rawQuery( Q, null);\n");
				fprintf(h,"\tif (!( R.moveToFirst() )) { R.close(); error = 64; }\n");
				fprintf(h,"\telse { %s = R.getString(0); R.close(); error = 0; OnSearch(); }\n",dptr->name[0]);
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");

			/* -------------------- */		
			/* last database record */
			/* -------------------- */		
			android_java_comment(h,"Last","Database Table Record");
			fprintf(h,"public void OnLast()\n{\n");
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString Q = \"Select Max( %s ) As %s From \"+tableName;\n",dptr->name[0],dptr->name[0]);
				if ( sqlcipher & 2 )
					fprintf(h,"\tVisualDatabaseCursor R = (VisualDatabaseCursor) database.rawQuery( Q, null);\n");
				else	fprintf(h,"\tCursor R = database.rawQuery( Q, null);\n");
				fprintf(h,"\tif (!( R.moveToFirst() )) { R.close(); error = 48; }\n");
				fprintf(h,"\telse { %s = R.getString(0); R.close(); error = 0; OnSearch(); }\n",dptr->name[0]);
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");

			/* -------------------- */		
			/* next database record */
			/* -------------------- */		
			android_java_comment(h,"Next","Database Table Record");
			fprintf(h,"public void OnNext()\n{\n");
				fprintf(h,"\tOnSearch();\n");
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString[] keyValues = new String[]");
				for (	i=0,sep='{'; i < dptr->indexfields; i++ )
				{
					fprintf(h,"%c%s",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"};\n");
				fprintf(h,"\tCursor results;\n");
				fprintf(h,"\tresults = database.query(tableName,null,");
				sep = '"';
				for (	i=0;
					i < dptr->indexfields;
					i++ )
				{
					fprintf(h,"%c%s>?",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"\",keyValues,null,null,null,\"1\");\n");
				fprintf(h,"\tif (!( OnFetch(results) )) { error = 48; }\n");
				fprintf(h,"\telse { error = 0; }\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
			
			android_java_comment(h,"Previous","Database Table Record");
			fprintf(h,"public void OnPrevious()\n{\n");
				fprintf(h,"\tOnSearch();\n");
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString[] keyValues = new String[]");
				for (	i=0,sep='{'; i < dptr->indexfields; i++ )
				{
					fprintf(h,"%c%s",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"};\n");
				fprintf(h,"\tCursor results;\n");
				fprintf(h,"\tresults = database.query(tableName,null,");
				sep = '"';
				for (	i=0;
					i < dptr->indexfields;
					i++ )
				{
					fprintf(h,"%c%s<?",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"\",keyValues,null,null,null,\"1\");\n");
				fprintf(h,"\tif (!( OnFetch(results) )) { error = 64; }\n");
				fprintf(h,"\telse { error = 0; }\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
			
			android_java_comment(h,"Insert","Database Table Record");
			fprintf(h,"public void OnInsert()\n{\n");
				fprintf(h,"\tif ( %s == null ) { error = 78; return; }\n",dptr->name[0]);
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tContentValues contentValues = new ContentValues();\n");
				for (	i=0;
					i < dptr->indexfields;
					i++ )
					fprintf(h,"\tcontentValues.put(\"%s\",%s);\n",check_sql_name(dptr->name[i]),dptr->name[i]);
				for (	i=0;
					i < dptr->datafields;
					i++ )
					fprintf(h,"\tcontentValues.put(\"%s\",autoEnCrypt(%s%s));\n",check_sql_name(dptr->name[i+dptr->indexfields]),prefix,dptr->name[i+dptr->indexfields]);
				fprintf(h,"\tdatabase.insert(tableName,null,contentValues);\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
			
			android_java_comment(h,"Update","Database Table Record");
			fprintf(h,"public void OnModif()\n{\n");
				fprintf(h,"\tif ( %s == null ) { error = 78; return; }\n",dptr->name[0]);
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString[] keyValues = new String[]");
				for (	i=0,sep='{'; i < dptr->indexfields; i++ )
				{
					fprintf(h,"%c%s",sep,check_sql_name(dptr->name[i]));
					sep = ',';
				}
				fprintf(h,"};\n");
				fprintf(h,"\tContentValues contentValues = new ContentValues();\n");
				for (	i=0;
					i < dptr->datafields;
					i++ )
					fprintf(h,"\tcontentValues.put(\"%s\",autoEnCrypt(%s%s));\n",check_sql_name(dptr->name[i+dptr->indexfields]),prefix,dptr->name[i+dptr->indexfields]);
				fprintf(h,"\tdatabase.update(tableName,contentValues,");
				sep = '"';
				for (	i=0;
					i < dptr->indexfields;
					i++ )
				{
					fprintf(h,"%c%s=?",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"\",keyValues);\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Delete","Database Table Record");
			fprintf(h,"public void OnDelete()\n{\n");
				fprintf(h,"\tif ( %s == null ) { error = 78; return; }\n",dptr->name[0]);
				fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
				fprintf(h,"\tString[] keyValues = new String[]");
				for (	i=0,sep='{'; i < dptr->indexfields; i++ )
				{
					fprintf(h,"%c%s",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"};\n");
				fprintf(h,"\tdatabase.delete(tableName,");
				sep = '"';
				for (	i=0;
					i < dptr->indexfields;
					i++ )
				{
					fprintf(h,"%c%s=?",sep,dptr->name[i]);
					sep = ',';
				}
				fprintf(h,"\",keyValues);\n");
				fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Insert or Modify","Database Table Record");
			fprintf(h,"public void OnUpdate()\n{\n");
			fprintf(h,"\tOnModif();\n");
			fprintf(h,"\tif ( error == 78 ) { OnInsert(); }\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Prepare","Database Table Question");
			fprintf(h,"public void OnPrepare(int count)\n{\n");
			fprintf(h,"\tparameters = new String[count];\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Bind","Database Table Question Value");
			fprintf(h,"public void OnBind(int item, String value)\n{\n");
			fprintf(h,"\tparameters[item] = value;\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Cursor","Database Table Records");
			fprintf(h,"public void OnCursor(String fields)\n{\n");
			fprintf(h,"\tif ( cursor != null ) { cursor.close(); }\n");
			fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
			fprintf(h,"\tanswer = null;\n");
			fprintf(h,"\tresponse = 0;\n");
			fprintf(h,"\tString Q=\"Select \"+fields+\" From \"+tableName+\" Where \"+question;\n");
			if ( sqlcipher & 2 )
				fprintf(h,"\tcursor = (VisualDatabaseCursor) database.rawQuery( Q, null);\n");
			else	fprintf(h,"\tcursor = database.rawQuery( Q, null);\n");
			fprintf(h,"\tresponse = cursor.getCount();\n");
			fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");
	
			android_java_comment(h,"Collect","Database Table Records");
			fprintf(h,"public void OnCollect()\n{\n");
			fprintf(h,"\ttry\n\t{\n\terror = 0;\n");	
			fprintf(h,"\tresponse = 0;\n");
			if ( sqlcipher & 2 )
				fprintf(h,"\tVisualDatabaseCursor R = null;\n");
			else	fprintf(h,"\tCursor R = null;\n");
			fprintf(h,"\tanswer = new ArrayList<String>();\n");
			fprintf(h,"\tif ( parameters == null ) {\n");
			fprintf(h,"\tString Q=\"Select %s From \"+tableName+\" Where \"+question;\n",dptr->name[0]);
			if ( sqlcipher & 2 )
				fprintf(h,"\tR = (VisualDatabaseCursor) database.rawQuery( Q, null);\n");
			else	fprintf(h,"\tR = database.rawQuery( Q, null);\n");
			fprintf(h,"\t} else {\n");
			if ( sqlcipher & 2 )
				fprintf(h,"\tR = (VisualDatabaseCursor) database.query(tableName,new String[]{ \"%s\" }, question, parameters, null, null, null);\n", dptr->name[0]);
			else	fprintf(h,"\tR = database.query(tableName,new String[]{ \"%s\" }, question, parameters, null, null, null);\n", dptr->name[0]);
			fprintf(h,"\tparameters = null;\n");
			fprintf(h,"\t}\n");
			fprintf(h,"\tresponse = R.getCount();\n");
			fprintf(h,"\tif (!( R.moveToFirst() )) { return; }\n");
			fprintf(h,"\tfor ( int i=0; i < response; i = i + 1 )  {\n");
			fprintf(h,"\t\tanswer.add(R.getString(0));\n");
			fprintf(h,"\t\tif (!( R.moveToNext() )) { break; }}\n");
			fprintf(h,"\tR.close();\n");
			fprintf(h,"\t} catch (SQLiteException e) { error = 55; }\n");
			fprintf(h,"}\n");

			android_java_comment(h,"Locate","Database Table Record");
			fprintf(h,"public void OnLocate(int n)\n{\n");
			fprintf(h,"\tif ( answer == null ) { error = 118; }\n");
			fprintf(h,"\telse if ( n <= 0 )    { error = 102; }\n");
			fprintf(h,"\telse if ( n > response ) { error = 103; }\n");
			fprintf(h,"\telse { %s = answer.get(n-1); OnSearch(); }\n",dptr->name[0]);
			fprintf(h,"}\n");

		} 

		android_class_footer( h, domain ,classname );
		fclose(h);
		return;
	}
}

	/* ------------ */
#endif	/* _androfile_c */
	/* ------------ */

