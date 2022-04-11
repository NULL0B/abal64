#ifndef	_edmsgid_h
#define	_edmsgid_h

/*	Designation des messages pour les modules utilisateurs		*/
/*	------------------------------------------------------		*/

/*	messages generaux		*/
/*	-----------------		*/

#define titre 	 0	/* Editeur de texte ABAL */
#define msgerr	 1	/* ** Erreur */
#define msgabort 2	/* - Abandon de l'edition */
#define msgfic	 3	/* fichier : */
#define msgins	 4	/* INSERER */
#define msgidt	 5	/* INDENTER */
#define msgconf	 6	/* abandon (o/n) : */
#define msglgn	 7	/* ligne : */
#define msgcol	 8	/* colonne : */
#define errcom	 9	/* Commande incorrecte  */

/*	messages specifiques du noyau	*/
/*	-----------------------------	*/

#define ernoy01	 10	/* Fichier source inaccessible */
#define ernoy02	 11	/* Acces fichier impossible */
#define ernoy03	 12	/* Debordement capacite memoire */
#define ernoy04	 13	/* Fichier d'erreurs inaccessible */
#define ernoy05	 14	/* Acces fichier d'erreurs impossible */
#define ernoy06	 15	/* Fin du fichier des erreurs */
#define ficexist 16	/* Fichier deja existant */
#define ficnwrit 17	/* Ecriture SWORDerdite */
#define ficnexist 18	/* Fichier non trouve */
#define ficnread 19	/* Lecture SWORDerdite */
#define ficvide	 20	/* Fichier vide */
#define bufvide	 21	/* Tampon est vide */
#define absent	 22	/* Chaine non trouvee */
#define chgtfic	 23	/* Changement de fichier source */
#define msgsave	 24	/* Sauvegarde de l'etat courant (o/n) ? */

#ifdef	ver2K
#define errlng	 25	/* Ligne trop longue ( > 2048 caracteres ) */
#else
#define errlng	 25	/* Ligne trop longue ( > 320 caracteres ) */
#endif

#define memto	 26	/* Message de fin du memento */
#define errep	 27	/* fichier cfg incorrect  */

#define ernoy00	 28   /* Fichier non partageable */

#ifndef integre
#define msgcor 29	/* Message pour le mode corbeil */
#define msgaff 30	/* Presence de la corbeille en memoire */
#define banenv 31	/* Banniere environnement */
#define msgpath	 32 	/* Pour afficher le nom complet du fichier */
#define msgfich	 33
#define msgwait	 34	/* Attendre la frappe d'une touche */
#define tstcar	 35	/* test les car. non ascii */
#define errsau	 36	/* 1er message lors d'une erreur de sauvegarde */
#define msgsau	 37	/* Affichage du nom de fichier sauvegarde */
#define errcfg	 38	/* fichier de config incorrect */
#endif /* SWORDegre */

#endif	/* _edmsgid_h */
	/* ---------- */


