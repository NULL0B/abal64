#ifndef _PRINTHQ_H_
#define _PRINTHQ_H_

// Ancienne m�thode
WORD printhq_set_dpi( unsigned short nolog, unsigned short* phdpi , unsigned short* pvdpi);

// Nouvelle m�thode
WORD printhq_buffer( WORD nolog, STDPSUPTR OriBuf, WORD Mode, WORD Zoom);

#endif

