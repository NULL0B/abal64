
private	void	lsl_file_menu_data(FILE * h)
{
	fprintf(h,"list\tmenu_choices = [ %cFirst%c, %cDown%c, %cUpdate%c, %cUp%c, %cLast%c, %cDelete%c ];\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE,__QUOTE);
	fprintf(h,"string\tmenu_message =%cFile Functions%c;\n",__QUOTE,__QUOTE);
	fprintf(h,"integer\tmenu_id=0;\n");
	fprintf(h,"integer\tmenu_port=0;\n");
	fprintf(h,"key\towner_key=NULL_KEY;\n");
	return;
}


private	void	lsl_file_menu_show(FILE * h)
{
	fprintf(h,"MenuShow()\n");
	fprintf(h,"{\n");
	fprintf(h,"\tllListenRemove(menu_id);\n");
	fprintf(h,"\towner_key = llGetOwner();\n");
	fprintf(h,"\tmenu_port = ( -1 * (integer)(%c0x%c+llGetSubString((string)llGetKey(),-5,-1)) );\n",__QUOTE,__QUOTE);     
	fprintf(h,"\tllDialog(owner_key,menu_message,menu_choices,menu_port);\n");
	fprintf(h,"\tmenu_id  = llListen(menu_port,%c%c,owner_key,%c%c);\n",__QUOTE,__QUOTE,__QUOTE,__QUOTE); 
	fprintf(h,"}\n");
	return;
}

private	void	lsl_file_menu_event( FILE * h, struct form_item * iptr )
{
	fprintf(h,"\tif ( message == %cFirst%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sFirst();\n",iptr->Contents.name);
	fprintf(h,"\t} else if ( message == %cDown%c ) \n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sDown();\n",iptr->Contents.name);
	fprintf(h,"\t} else if ( message == %cLast%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sLast();\n",iptr->Contents.name);
	fprintf(h,"\t} else if ( message == %cUp%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sUp();\n",iptr->Contents.name);
	fprintf(h,"\t} else if ( message == %cUpdate%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sUpdate();\n",iptr->Contents.name);
	fprintf(h,"\t} else if ( message == %cDelete%c )\n",__QUOTE,__QUOTE);
	fprintf(h,"\t{\n");
	fprintf(h,"\t\t%sDelete();\n",iptr->Contents.name);
	fprintf(h,"\t}\n");
	return;
}

private	void	lsl_file_record_show( FILE * h, struct form_item * iptr); 
{
	fprintf(h,"%sShow()\n",iptr->Contents.name);
	fprintf(h,"{\n");
	llOwnerSay( "oid ="+_%s_oid);
	llOwnerSay( "name="+_%s_name);
	llOwnerSay("keyid="+_%s_keyid);
	llOwnerSay("where="+_%s_where);
	llOwnerSay("date="+_%s_date);
	llOwnerSay("extra="+_%s_extra);
	llOwnerSay("encore="+_%s_encore);
	return;
}

