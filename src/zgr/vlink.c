

#include "vlink.h"
#include "zint.h"
#include "zglobal.h"

#include <string.h>
#include <stdlib.h>

#include"zsys.h"
#include"zgui.h"
#include"zintctx.h"
#include "ztools.h"
#include "zext.h"
#include "ztrace.h"
#include <stdlib.h>

	struct link* get_head(struct link* any_link){
		if(!any_link) return 0;
		while(any_link->prev) any_link=any_link->prev;
		return any_link;
	}

	struct link* get_tail(struct link* any_link){
		if(!any_link) return 0;
		while(any_link->succ) any_link=any_link->succ;
		return any_link;
	}

    struct link* create(void* any_data){
       struct link* tail_head=( struct link*)allocate(sizeof(struct link));
       tail_head->prev=0;
       tail_head->succ=0;
       tail_head->data=any_data;
       return tail_head;
    }

    struct link* tail_link( struct link* any_link,void* any_data){
		if(!(any_link=get_tail(any_link))){
			return(create(any_data));
		}
		else{
			struct link* new_link=( struct link*)allocate(sizeof(struct  link));
			new_link->succ=0;
			new_link->data=any_data;
			new_link->prev=any_link;
			any_link->succ=new_link;
			return new_link;
       }
    }
   
    struct link* head_link( struct link* any_link,void* any_data){
		if(!(any_link=get_head(any_link))){
			return(create(any_data));
		}
		else{
	       struct link* new_link=( struct link*)allocate(sizeof(struct link));
		    new_link->prev=0;
			new_link->data=any_data;
			new_link->succ=any_link;
			any_link->prev=new_link;
			return new_link;
       }
    }


	struct link* shift_to_tail(struct link* any_link,long shift){
		while((shift--) && (any_link=any_link->succ) );
		return any_link;
	}	

	struct link* shift_to_head(struct link* any_link,long shift){
		while((shift--) && (any_link=any_link->prev) );
		return any_link;
	}	

	struct link* find(struct link* start,void* any_data)
	{
		while(start)
		   {
			if(start->data==any_data) 
			   return start;
			start=start->succ;
		}
		return 0;
	}

	struct link* destroy_link_and_shift_right(struct link* pos){
		if(!pos) 
			return 0;
		else{
			struct link* succ_link=pos->succ;
			if(!succ_link) return 0;
			succ_link->prev=pos->prev;
			if(pos->prev){
				pos->prev->succ=succ_link;
			}
			liberate(pos);
			return succ_link;
		}
		return 0;
	}

	struct link* destroy_link_and_shift_left(struct link* pos){
		if(!pos) 
			return 0;
		else{
			struct link* prev_link=pos->prev;
			if(!prev_link) return 0;
			prev_link->succ=pos->succ;
			if(pos->succ){
				pos->succ->prev=prev_link;
			}
			liberate(pos);
			return prev_link;
		}
		return 0;
	}
	
	/*struct link* reverse_find(struct link* start,void* any_data){
		if(!any_link) return 0;
		while(any_link){
			if(any_link->data==any_data) return any_link;
			any_link=any_link->prev;				
		}
	}*/	

    void destroy_all(struct link* any_link){
        if(!any_link) return;
        any_link=get_head(any_link);
		{
        struct link*     deleted_link=any_link->succ;
        while(deleted_link){
            struct link* temporary=deleted_link->succ;
            liberate(deleted_link->data);
            liberate(deleted_link);
            deleted_link=temporary;
        }
		liberate(any_link->data);
		liberate(any_link);
        }
    }

	void destroy_all_links(struct link* any_link){
        if(!any_link) return;
        any_link=get_head(any_link);
		{
        struct link*     deleted_link=any_link->succ;
        while(deleted_link){
            struct link* temporary=deleted_link->succ;
            liberate(deleted_link);
            deleted_link=temporary;
        }
		liberate(any_link);
        }
	}




