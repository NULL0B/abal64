/* -------------------------------------------------------------------- */
/*									*/
/*		Project ABAL : Tcode Post optimiser			*/
/*		-----------------------------------			*/
/*									*/
/*		  Copyright (c) 1989,1991 Amenesik / Sologic s.a.			*/
/*		  --------------------------------			*/
/*									*/
/*		File	:	AOBLOCK.H 				*/
/*		Version :	1.4a					*/
/*		Date	:	04/10/1991				*/
/*									*/
/* -------------------------------------------------------------------- */
#ifndef	_AOBLOCK_H
#define	_AOBLOCK_H

#define	BLOCKPTR	struct block_control XPTR

struct	block_control {
	EXAWORD		sector;
	EXAWORD		longueur;
	BPTR		buffer;
	BLOCKPTR	next;
	};

#ifdef	_COPYAT_C

	BLOCKPTR	BlockControl;
	BLOCKPTR	BlockStore;

#else

extern	BLOCKPTR	BlockControl;
extern	BLOCKPTR	BlockStore;

#endif

/*	Function ProtoTypes	*/
/*	-------------------	*/
BLOCKPTR	allocate_for_block();
void		initialise_block_control();
void		terminate_block_control();
void		release_block_buffer( BLOCKPTR, BLOCKPTR );
EXAWORD		StoreBlock( EXAWORD, BPTR );
BPTR		LoadBlock( EXAWORD, EXAWORD, EXAWORD );
BPTR		MakeBlock( EXAWORD );

#endif	/* _AOBLOCK_H  */
	/* ----------- */

