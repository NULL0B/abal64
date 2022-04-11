extern w_conf();

main(argc,argv)
int argc;
char *argv[];
{
	int ret;

	if (argc == 1) {
		banniere();
	}
	else {
		w_conf(*argv[1]);
		switch(*argv[1]) {
			case '0':
				ret = w_conf(1);
				printf("\r\n   Lignes visibles   : %d",ret);
				ret = w_conf(2);
				printf("\r\n   Colonnes visibles : %d",ret);
				ret = w_conf(17);
				printf("\r\n   Couleur Texte     : %d",ret);
				ret = w_conf(18);
				printf("\r\n   Couleur Fond      : %d",ret);
				break;
			case '1':
				ret = w_conf(1);
				printf("\r\n   Nombre de ligne visible : %d",ret);
				break;
			case '2':
				ret = w_conf(2);
				printf("\r\n   Colonnes visibles : %d",ret);
				break;
			case '3':
				ret = w_conf(17);
				printf("\r\n   Couleur Texte     : %d",ret);
				break;
			case '4':
				ret = w_conf(18);
				printf("\r\n   Couleur Fond      : %d",ret);
				break;
			default:
				printf("\r\n   ben ALORS !!!");
		}
	}
}

banniere()
{
	printf("\r\n   Status de la fenetre courante.");
	printf("\r\n   Usage Interne ");
	printf("\r\n   Copyright Amenesik / Sologic s.a. 1992\r\n");
}






