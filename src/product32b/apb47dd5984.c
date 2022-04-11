#include <stdio.h>
unsigned char * directory="/home/abal3";
unsigned char * target_name="/home/abal3/abal16criteria.tgz";
unsigned char * source_name="/home/Dev/abal32/product32b/abal16criteria.tgz";
unsigned char * source_file="./apb47dd5984.c";
unsigned char * product_name="/home/Dev/abal32/release/abal3.2b.0.04.abal16criteria";
unsigned char * semicolon=";";
unsigned char * space    =" ";
unsigned int    control  =1;
unsigned char * payload="[*(+</{--./apb47dd5984.c--}/>+)*]";
unsigned int    payload_offset=1;
unsigned char * preinstall="cd /home/abal3";
unsigned char * install="tar -xzf";
unsigned char * postinstall="./install.abal16criteria";
static char buffer[2048];
static int option(char * aptr)
{
	if ((*aptr == '-') && (*(aptr+1) =='i')) { control=0; return(1); }
	if ((*aptr != '-') || (*(aptr+1) !='v')) { return(0); }
	printf("Product Name    : %s\n",product_name);
	printf("Generation      : %s\n",source_file);
	printf("Directory       : %s\n",directory);
	printf("Product Source  : %s\n",source_name);
	printf("Product Target  : %s\n",target_name);
	printf("PreInstall      : %s\n",preinstall);
	printf("Installation    : %s\n",install);
	printf("PostInstall     : %s\n",postinstall);
	return(0);
}

static FILE * payload_detect(char * aptr)
{
	FILE * h=(FILE*)0;
	int    i=0;
	int    v=0;
	int pass=0;
	if (!(h = fopen(aptr,"rb"))) { return(h); }
	while(1) {
		payload_offset++;
		if ((v = fgetc(h)) == -1) { break; }
		else if (!( payload[i] )) { if (!( v )) { i=0; continue; } else { return(h); } }
		else if ((v & 0x00FF) != payload[i]) { i=0; continue; }
		else { i++; continue; }
		}
	fclose(h);
	return((FILE *)0);
}
int main(int argc,char * argv[])
{
	FILE * h=(FILE*)0;
	FILE * bh=(FILE*)0;
	int    i=0;
	if ( argc != 1 ) { if (!( option(argv[1]))) return(0); }
	if ( geteuid() ) { printf("Super user mode required for the installation of this package\n"); return(0); }
	if (!( bh = payload_detect(argv[0]) )) { return(0); }
	printf("product installation : %s\n",argv[0]);
	strcpy(buffer,"mkdir ");
	strcat(buffer,directory);
	strcat(buffer," 2>/dev/null ");
	system(buffer);
	if (!(h = fopen(target_name,"wb"))) { return(1); }
	while ((i = fgetc(bh)) != -1) { fputc((i & 0x00FF),h); }
	fclose(bh);
	fclose(h);
	buffer[0]=0;
	if ( preinstall )  {
		strcat(buffer,preinstall);
		strcat(buffer,semicolon );
	}
	if ( install )  {
		strcat(buffer,install);
		strcat(buffer,space);
		strcat(buffer,target_name);
		strcat(buffer,semicolon );
	}
	if (( postinstall ) && ( control ))  {
		strcat(buffer,postinstall);
		strcat(buffer,semicolon );
	}
	system(buffer);
	return(0);
}

/*end of file*/

