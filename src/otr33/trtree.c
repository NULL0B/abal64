#ifndef	_TRTREE_C
#define	_TRTREE_C

#ifndef	UNIX
#include "trinput.h"
#include "trapl.h"
#include "trecho.h"
#else
BPTR	source_file_name();
BPTR	library_file_name();
#endif

VOID	show_class_source( class )
TCSTRUCTPTR	class;
{
	if (( class != (TCSTRUCTPTR) 0  )
	&&  ( class->source != (BPTR) 0 ))
		sysprintf("[%s]",class->source);
	return;
}

WORD		class_tree_node( class )
TCSTRUCTPTR	class;
{
	TREEPTR	nptr;
	TREEPTR	root;
	BPTR	fptr;
	WORD	h;

	if ((nptr = (TREEPTR) allocate( sizeof ( struct tcode_class_tree ) )) == (TREEPTR) 0)
		return( allocation_failure() );
	else	{

		if ((fptr = library_file_name()) == (BPTR) 0)
			fptr = source_file_name();
		if ( fptr != (BPTR) 0 )
			class->source = allocate_for_string( fptr );

		if ( OtrOption.Verbose & 8 ) {
			sysprintf("Class : %s",class->name);
			show_class_source( class );
			sysprintf("\n");
			}

		nptr->class = class;
		nptr->left  = (TREEPTR) 0;
		nptr->right = (TREEPTR) 0;
		nptr->next  = World->TreesUsed;
		World->TreesUsed = nptr;
		h = (class->hash % CLASS_TREE_HASH);
		if ((root = World->ClassTree[h]) == (TREEPTR) 0 )
			World->ClassTree[h] = nptr;
		else	{
			while ( 1 ) {
				if ( class->hash > root->class->hash  ) {
					if ( root->left != (TREEPTR) 0 )
						root = root->left;
					else	{
						root->left = nptr;
						break;
						}
					}
				else  if ( root->right != (TREEPTR) 0 )
					root = root->right;
				else	{
					root->right = nptr;
					break;
					}
				}
			}
		return( 0 );
		}
}

static TCSTRUCTPTR	is_known_structure( name )
BPTR		name;
{
	WORD	hash;
	WORD	h;
	TREEPTR	root;

	if ((name == (BPTR) 0)
	||  ((root = World->ClassTree[(h = ((hash = keyword_hash( name )) % CLASS_TREE_HASH))]) == (TREEPTR) 0))
		return( (TCSTRUCTPTR) 0);

	while ( root != (TREEPTR) 0) {
		if (( hash == root->class->hash )
		&&  ( compare_tokens( name, root->class->name ) ))
			return( root->class );
		if ( hash > root->class->hash )
			root = root->left;
		else 	root = root->right;
		}

	return((TCSTRUCTPTR) 0);
}

#endif	/* _TRTREE_C */
	/* --------- */



