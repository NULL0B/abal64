/************************************/
/* Prototype des fonctions ... */
/************************************/
#define OK	0

#define	_DAS_BUFFER_SIZE	256

#define	_DASSV1_DIALING		0x0001		// CONNECTE	???
#define	_DASSV1_READY		0x0010		// LINE UP 	???
#define	_DASSV1_CONNECTING	0x0100		// TACHE ACTIVE ???

#define	_DASSV1_DEAD		0x0000		// PHASE DEAD	
						// PPP inactive

#define	_DASSV1_ESTABLISH	0x0001		// PHASE ESTABLISH
						// PPP establishing connection

#define	_DASSV1_AUTHENTICATE	0x0002		// PHASE AUTHENTICATE
						// PPP Authentification under way

#define	_DASSV1_NETWORK		0x0003		// PHASE NETWORD
						// PPP Connected

#define	_DASSV1_TERMINATE	0x0004		// PHASE TERMINATE
						// PPP Disconntecting

#define NUMERO_PREMIERE_ERREUR  	298 // Toujours la mettre a jour

#define ERREUR_PROFIL_INEXISTANT   	298
#define ERREUR_LIGNE_DEJA_CONNECTEE	299
#define ERREUR_OUVERTURE_PROFIL_RW	300      
#define ERREUR_OUVERTURE_PROFIL_W	301 
#define ERREUR_OUVERTURE_PROFIL_R	302
#define ERREUR_LECTURE_PROFIL		303
#define ERREUR_ECRITURE_PROFIL		304
#define ERREUR_FERMETURE_PROFIL		305
#define ERREUR_OUVERTURE_OPTIONS_RW	306
#define ERREUR_FERMETURE_OPTIONS	307
#define ERREUR_OUVERTURE_SECRETS_RW	308
#define ERREUR_FERMETURE_SECRETS	309

#define NUMERO_DERNIERE_ERREUR  	309 // Toujours la mettre a jour





#define MAX_PROFILS 50 


extern "C" {

 short int  InitDassv1( int );
 short int  FinDassv1( void);
 short int  VersDassv1( char * );
 short int  DasConnect( char * numlog,char * profil,char * number,char * user,char * passwd);  
 short int  DasDisconnect( char numlog);  
 short int  DasGetListProfiles(void * buffer, short int  * nb_elt, short int  * jeton);

 short int  DasGetProfile(char * NomProfil,char * buffer, short int  * size, char * numlog);
 short int  DasSetProfile(char * NomProfil,char * buffer, short int  * size);
 short int  DasDelProfile(char * NomProfil);

 short int  DasGetPPPLineStatus( char numlog,struct ppp_stats * buffer );

 short int  DasGetLineStatus( char numlog,int * Status);
 short int  DasGetPPPPhase( char numlog,int * Phase);

	};


