/* 

	+---------------+-------------------------------------------------------+
	|				|														|
	| MODULE 		|	ascoderror.h										|
	|				|														|
	| DESCRIPTION	|	Contient l'ensemble des codes erreurs de la DLL		|
	|				|														|
	|				|														|
	| HISTORY		| 08/11/2011 : Creation									|
	|				|														|
	|				|														|
	+---------------+-------------------------------------------------------+

*/

#ifndef ASCODERROR_H_DEFINED
#define ASCODERROR_H_DEFINED

// Erreurs standard
#define ABSQLerr_Success					0			// OK
#define ABSQLerr_OutOfMemory				27			// Plus possible d'allouer
#define ABSQLerr_Undefined					56			// Fonction non definie

// Erreur Postgres
#define ABSQLerr_SqlError					3000		// Erreur SQL

// Erreurs spécifiques de la librairie SQLpgres.
#define ABSQLerr_InvalidConnexionString		3001		// Chaine de connexion invalide.
#define ABSQLerr_InvalidBuffer				3002		// Sur GetSqlErrorMessage si l'adresse est nulle, Erreur interne ne devrait pas arriver en exécution.
#define ABSQLerr_InvalidBufferLength		3003		// Sur GetSqlErrorMessage si la longueur du buffer est nulle, Erreur interne ne devrait pas arriver en exécution.
#define ABSQLerr_DataTruncated				3004		// Sur toutes les fonctions de conversions, sur GetSqlErrorMessage, sur GetColName si le buffer de reception est trop court.
#define ABSQLerr_InvalidConnexionHandle		3005		// Sur toutes les fonctions.
#define ABSQLerr_InvalidTransactionLevel	3006		// Sur un Begin si le niveau n'est pas connu.
#define ABSQLerr_InvalidSQLDataType			3007		// Pas utilisé pour le moment.
#define ABSQLerr_InvalidStmtHandle			3008		// Sur chaque fonction utilisant le handle de requête (mauvais handle).
#define ABSQLerr_InvalidNumberParameter		3009		// Sur les fonctions BIND, GETVALUE si le numéro du paramètre ou de la colonne est incorrect. Sur GETVALUE, on doit avoir d'abord RowNumberOutOfRange ou ColumnNumberOutOfRange. C'est plus une erreur interne dans ce cas.
#define ABSQLerr_InvalidAbalDataType		3010		// Sur toutes les fonctions BIND, FETCH, GETVALUE si le type de la variable Abal est incorrect (non connu).
#define ABSQLerr_InvalidAbalSizeType		3011		// La longueur de la variable Abal n'est pas concordante avec le type. Par exemple, un # plus grand que 1.
#define ABSQLerr_ConversionNotPossible		3012		// Conversion de données non prévues.
#define ABSQLerr_NumBadNumeric				3013		// Le numérique fourni n'a pas une valeur correct.
#define ABSQLerr_NumOverflow				3014
#define ABSQLerr_NumUnderflow				3015
#define ABSQLerr_NumDivideZero				3016
#define ABSQLerr_DateBadDate				3017
#define ABSQLerr_DateErrEargs				3018
#define ABSQLerr_DateErrEnoshortdate		3019
#define ABSQLerr_IntvlBadInterval			3020
#define ABSQLerr_DateErrEnotdmy				3021
#define ABSQLerr_DateBadDay					3022
#define ABSQLerr_DateBadMonth				3023
#define ABSQLerr_TsBadTimestamp				3024
#define ABSQLerr_TsErrEinftime				3025
#define ABSQLerr_ColumnNumberOutOfRange		3026		// Sur GetCOLNAME et GETFIELD (mauvais numéro de colonne)
#define ABSQLerr_InvalidOption				3027		// Option invalide demandée sur la fonction GetSERVICEINFOS.
#define ABSQLerr_RowNumberOutOfRange		3028		// Sur GetFIELD (mauvais numéro de ligne).
#define ABSQLerr_BindMissing				3029		// Sur le FETCH ou le EXEC, tous les paramètres d'entrée ou de sortie n'ont pas bindés.
#define ABSQLerr_FetchOrientation			3030		// Le sens demandé sur le fetch est incorrect (logiquement ne devrait pas arriver, le traducteur devrait déjà faire son boulot).
#define ABSQLerr_EndOfAnswer				3031		// Pour le fetch, tout est dans le nom.
#define ABSQLerr_StartOfAnswer				3032		// Pour le fetch, tout est dans le nom.
#define ABSQLerr_InvalidNumberColumn		3033		// Sur le BINDCOL, pas de colonne avec ce numéro dans le result set.
#define ABSQLerr_IncompatibleLibrary		3034		// Librairie incompatible avec l'exécuteur (équivalent 137 pour Criteria).

// Erreurs spécifiques de l'Executeur Abal pour les instructions SQL.
#define EXABSQLerr_InvalidAssignation		3200
#define EXABSQLerr_InvalidAbalParamType		3201
#define EXABSQLerr_InvalidAbalParamValue	3202
#define EXABSQLerr_NumOverflow				3203
#define EXABSQLerr_InvalidConnexionHandle	3205
#define EXABSQLerr_InvalidStmtHandle		3208


#endif	// ASCODERROR_H_DEFINED