#ifndef _dataelement_c_
#define _dataelement_c_

//      ------------------------------------------
//      Electronic Document Exchange : DataElement
//      ------------------------------------------
//
//      Copyright (c) 2021 Amenesik SARL
//
//      Iain James MArshall <ijm@amenesik.com>
//
//      ------------------------------------------

#include "dataelement.h"

/*	------------------------------------------	*/
/*	l i b e r a t e _ d a t a _ e l e m e n t 	*/
/*	------------------------------------------	*/
public struct data_element * liberate_data_element(struct data_element * sptr)
{
	struct data_element * mptr;
	if ( sptr )
	{
		while ((mptr = sptr->first) != (struct data_element *) 0)
		{
			sptr->first = mptr->next;
			mptr = liberate_data_element( mptr );
		}
		if ( sptr->name )
			 sptr->name = liberate(sptr->name);
		if ( sptr->value )
			 sptr->value = liberate(sptr->value);
		sptr = liberate( sptr);
	}
	return((struct data_element *) 0);

}

/*	------------------------------------	*/
/*	r e s e t _ d a t a _ e l e m e n t 	*/
/*	------------------------------------	*/
public struct data_element * reset_data_element(struct data_element * sptr)
{
	if ( sptr )
	{
		sptr->previous = (struct data_element*) 0;
		sptr->next = (struct data_element*) 0;
		sptr->parent = (struct data_element*) 0;
		sptr->first = (struct data_element*) 0;
		sptr->last = (struct data_element*) 0;
		sptr->name = (char*) 0;
		sptr->value = (char*) 0;
	}
	return(sptr);

}

/*	------------------------------------------	*/
/*	a l l o c a t e _ d a t a _ e l e m e n t 	*/
/*	------------------------------------------	*/
public struct data_element * allocate_data_element()
{
	struct data_element * sptr;
	if (!( sptr = trallocate( sizeof( struct data_element ), "allocate_data_element") ))
		return( sptr );
	else	return( reset_data_element(sptr) );
}

/*	--------------------------------	*/
/*	a d d _ d a t a _ e l e m e n t 	*/
/*	--------------------------------	*/
public struct data_element * add_data_element(struct data_element * pptr)
{
	struct data_element * sptr;
	if (!( sptr = trallocate( sizeof( struct data_element),"add_data_element" ) ))
		return( sptr );
	else if (!( sptr = reset_data_element(sptr) ))
		return( sptr );
	else
	{
		if (!( sptr->previous = pptr->last ))
			pptr->first = sptr;
		else	sptr->previous->next = sptr;
		pptr->last = sptr;
		sptr->parent = pptr;
		return( sptr );
	}

}

/*	----------------------------------	*/
/*	d r o p _ d a t a _ e l e m e n t 	*/
/*	----------------------------------	*/
public struct data_element * drop_data_element(struct data_element * sptr)
{
	if ( sptr )
	{
		if ( sptr->parent )
		{
			if (!( sptr->previous ))
			{
				if (!( sptr->parent->first = sptr->next ))
					sptr->parent->last = (struct data_element *) 0;
				else	sptr->parent->first->previous = (struct data_element *) 0;
			}
			else if (!( sptr->previous->next = sptr->next ))
				sptr->parent->last = sptr->previous;
			if (!( sptr->next ))
			{
				if (!( sptr->parent->last = sptr->previous ))
					sptr->parent->first = (struct data_element *) 0;
				else	sptr->parent->last->next = (struct data_element *) 0;
			}
			else if (!( sptr->next->previous = sptr->previous ))
				sptr->parent->first = sptr->next;
		}
		sptr = liberate_data_element(sptr);
	}
	return((struct data_element *) 0);
}

/*      ------------------------------------------------        */
/*              c o p y _ d a t a _ e l e m e n t               */
/*      ------------------------------------------------        */
/*      copies the member and its substructure to parent        */
/*      ------------------------------------------------        */
public  struct data_element *   copy_data_element(struct data_element * mptr, struct data_element * pptr)
{
        struct  data_element * nptr = (struct data_element *) 0;
        struct  data_element * optr = (struct data_element *) 0;
        struct  data_element * qptr = (struct data_element *) 0;

        // append a new element to the parent
        if (!( nptr = add_data_element( pptr )))
                return( nptr );
        else
        {
                // if it is not an array member copy name
                if ( mptr->name )
                        if (!( nptr->name = allocate_string( mptr->name ) ))
                                return( drop_data_element( nptr ) );

                // handle a terminal leaf node
                if ( mptr->value )
                {
                        if (!( nptr->value = allocate_string( mptr->value ) ))
                                return( drop_data_element( nptr ) );
                        else    return( nptr );
                }
                // handle a complex element
                else
                {
                        // run the list of members
                        for (   optr = mptr->first;
                                optr != (struct data_element *) 0;
                                optr = optr->next )
                                // duplicate and append
                                if (!( qptr = copy_data_element( optr, nptr )))
                                        return( qptr );
                        return( nptr );
                }
        }
}

/*      -------------------------------------------------       */
/*             e m p t y _ d a t a _ e l e m e n t		*/
/*      -------------------------------------------------       */
/*      emptys contents of a data element node as empty.        */
/*      -------------------------------------------------       */
public struct data_element * empty_data_element( struct data_element * dptr )
{
        struct  data_element * mptr = (struct data_element *) 0;
	if ( dptr )
	{
		if ( dptr->value )
			dptr->value = liberate( dptr->value );
		else
		{
                        while ((mptr = dptr->first) != (struct data_element *) 0)
			{
				dptr->first = mptr->next;
				mptr = drop_data_element( mptr );
			}
			dptr->first = dptr->last = (struct data_element *)0;
		}
	}
	return( dptr );
}

/*	-------------------------------------------------	*/
/*	    c o p y _ d a t a _ e l e m e n t s _ t o		*/
/*	-------------------------------------------------	*/
/*	resets an element and copies elements from source	*/
/*	-------------------------------------------------	*/
public	struct data_element * copy_data_elements_to( struct data_element * iptr, struct data_element * optr)
{
        struct  data_element * mptr;
        struct  data_element * nptr;

        // drop the current members of OPTR
        if (!( optr = empty_data_element( optr )))
                return(optr);
	else
	{
        	// copy the members of IPTR as members to OPTR
        	for (   mptr = iptr->first;
        	        mptr != (struct data_element *) 0;
        	        mptr = mptr->next )
			// dismantle the entire chain on error
        	        if (!( nptr = copy_data_element( mptr, optr )))
      				return( drop_data_element( optr ) );

		// return the updated chain 
		return( optr );
	}
}

/*	---------------------------------------------------	*/
/*		f i n d _ d a t a _ e l e m e n t		*/
/*	---------------------------------------------------	*/
/*	run the list of members and find the requested name	*/
/*	---------------------------------------------------	*/
public struct data_element * find_data_element( struct data_element * sptr, char * nptr )
{
	if (!( nptr ))
		return( ( struct data_element * ) 0 );
	else
	{
		for ( 	;
			sptr != (struct data_element *) 0;
			sptr = sptr->next )
		{
			if (!( sptr->name ))
				continue;
			else if (!( strcmp( sptr->name, nptr ) ))
				break;
		}
		return( sptr );
	}
}

/*      -------------------------------------------------       */
/*                  i s - d a t a _ a r r a y                   */
/*      -------------------------------------------------       */
/*      returns true or false if JSON element is an array       */
/*      -------------------------------------------------       */
public  int     is_data_array( struct data_element * dptr )
{
        struct  data_element * mptr;

        // no name means an array member */
        if (!( dptr->name ))
                return(0);

        // a valid value means terminal  */
        else if ( dptr->value )
                return(0);

        // no substructure so  could be */
        else if (!( mptr = dptr->first ))
                return(1);

        // array members have no name */
        else if (!( mptr->name ))
                return(1);
        else    return(0);
}

#endif	/* _dataelement_c_ */
