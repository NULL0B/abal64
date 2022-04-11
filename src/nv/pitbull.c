#include <stdio.h>

/*	INITIALISER VITESSE D'HORLOGE		*/
/*	-----------------------------		*/

#define	PRG_HTR			0x036	/* Commande Programmation HTR		*/
#define	PORT_COM		0x043	/* Port de commande HTR			*/
#define	PORT_DAT		0x040	/* Port de passation des valeurs HTR 	*/

#define	PORT_8259_M		0x020

/*	Value for 0.5 microseconds 	*/

#define	TIMER_LO		0x0074	/*  Valeur basse (Top Horloge 0,5 ms) 	*/
#define	TIMER_HI		0x0002	/*  Valeur haute			*/
#define	MOTOR_TIMER  		190

#define	TIMER_05	0x0274		

void	program_pit(int value)
{

	_asm	{
		IN	AL,PORT_8259_M+1	; Lecture du masque des IT
		JMP	SHORT $+2

		OR	AL,1			; Bit 0 = 1 
		OUT	PORT_8259_M+1,AL
		JMP	SHORT $+2
	
		MOV	AL,PRG_HTR
		OUT	PORT_COM,AL
		JMP	SHORT $+2

		MOV	AX,value
		OUT	PORT_DAT,AL
		JMP	SHORT $+2

		MOV	AL,AH	
		OUT	PORT_DAT,AL
		JMP	SHORT $+2

		IN	AL,PORT_8259_M+1	; Lecture du masque des IT
		JMP	SHORT $+2
	
		AND	AL,0FEH			; Bit 0 = 0 
		OUT	PORT_8259_M+1,AL
		JMP	SHORT $+2


		}

	return;

}

int	integer(char * vptr)
{
	int	result=0;
	while ( *vptr ) {
		if (( *vptr >= '0' ) 
		&&  ( *vptr <= '9' ))
			result = ((result * 10) + ( *(vptr++) - '0' ));
		else	break;
		}
	return(result);
}

int	main(int argc, char* argv[] )
{
	int	value;
	int	walue;
	char *	vptr;

	if ((  argc == 1      )
	||  (!(vptr = argv[1]))
	||  (!(value= integer(vptr)))) {
		printf("\n   PitBull : Version 1.1a");
		printf("\n   Provisoire du 8/3/2002");
		printf("\n   Copyright (c) 2002,2006 Amenesik / Sologic \n");
		}
	else	{
		walue = ((value*2)*TIMER_05);
		printf("\n   Pit : %xh = %u ms\n",walue,value);
		program_pit(walue);
		}
	return(0);
	
}

