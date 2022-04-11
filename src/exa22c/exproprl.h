#ifndef _EXPROPRL_H
#define _EXPROPRL_H

#include "exprow16.h"

EXAWORD HaltAsg(void);
EXAWORD low_level_spawn(void);
EXAWORD low_level_kill(EXAWORD);
void reset_parent_identity(void);
EXAWORD liberate_tcode_stacks(EXAWORD);
EXAWORD tcode_stack_allocation(EXAWORD);
EXAWORD get_parent_identity(void);
void low_level_raise(BPTR);
void low_level_drop(BPTR);
void low_level_synch(BPTR);
EXAWORD low_level_interrupt(EXAWORD);
void prologue_special_atb(EXAWORD);
EXAWORD prlvolis(BPTR,EXAWORD,EXAWORD);
void abandon_quantum(void);
EXAWORD stack_inspecter(void);
void exputch(EXAWORD);
EXAWORD LocalLink(EXAWORD);
EXAWORD printer_flush(void);
EXAWORD flush_printer_buffer(void);

#endif /* _EXPROPRL_H */


