#ifndef _PRINTHQ_H_
#define _PRINTHQ_H_

// Ancienne méthode
WORD printhq_set_dpi( unsigned short nolog, unsigned short* phdpi , unsigned short* pvdpi);

// Nouvelle méthode
WORD printhq_buffer( WORD nolog, STDPSUPTR OriBuf, WORD Mode, WORD Zoom);

#endif

