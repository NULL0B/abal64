#ifndef	_data_element_h
#define	_data_element_h

//      ------------------------------------------
//      Electronic Document Exchange : DataElement
//      ------------------------------------------
//
//      Copyright (c) 2021 Amenesik SARL
//
//      Iain James MArshall <ijm@amenesik.com>
//
//      ------------------------------------------

/*	------------	*/
/*	data_element	*/
/*	------------	*/
struct	data_element
{
	struct	data_element 	* previous;
	struct	data_element 	* next;
	struct	data_element 	* parent;
	struct	data_element 	* first;
	struct	data_element 	* last;
	char 			* name;
	char 			* value;
};
	
public struct data_element * allocate_data_element();
public struct data_element * add_data_element(struct data_element * pptr);
public struct data_element * liberate_data_element(struct data_element * sptr);
public struct data_element * drop_data_element(struct data_element * sptr);
public struct data_element * find_data_element( struct data_element * sptr, char * nptr );
public struct data_element * copy_data_element(struct data_element * mptr, struct data_element * pptr);
public struct data_element * copy_data_elements_to( struct data_element * iptr, struct data_element * optr);
public struct data_element * empty_data_element( struct data_element * dptr );
public int                   is_data_array( struct data_element * dptr );

#endif	

