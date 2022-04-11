#ifndef VLINK_H
#define VLINK_H

#if defined(__linux__) || defined(UNIX)
#include "wdef.h"
#else
#if defined(BDA_ABAL2)
#include "wdef.h"
#else
#include "bda.h"
#endif
#endif

// Ful Unsafety Double Linked List
// One Iterator List
 
    struct link{
        struct   link* prev;
        struct   link* succ;
        void*    data;
    };


    struct link* create(void* any_data);

    struct link* tail_link(struct link* any_link,void* any_data);
    struct link* head_link(struct link* any_link,void* any_data);
	
	struct link* get_head(struct link* any_link);
	struct link* get_tail(struct link* any_link);

	//dangerous op a=shift_to...(a,too_big_value)
	//recomendation:  Store any_link in intermediate variable

	struct link* shift_to_tail(struct link* any_link,long shift);
	struct link* shift_to_head(struct link* any_link,long shift);

	//if we can't move left/right no any destroying(return 0)
	//recomendation:  Store pos in intermediate variable
	struct link* destroy_link_and_shift_right(struct link* pos);
	struct link* destroy_link_and_shift_left(struct link* pos);
	//
	//dangerous op a=0(find(a,?)
	struct link* find(struct link* start,void* any_data);
	//

	void destroy_all_links(struct link* any_link);
    void destroy_all(struct link* any_link);


#endif
