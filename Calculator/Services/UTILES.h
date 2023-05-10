
/*
 * UTILES.h
 *
 * Created: 8/7/2021 2:04:56 PM
 *  Author: 
 */ 
#ifndef UTILES_H_
#define UTILES_H_

#define SETBIT(REG , BITno)              REG |= (1 << BITno)
#define CLRBIT(REG , BITno)              REG &= ~(1 << BITno)
#define GETBIT(REG , BITno)              (REG >> BITno) & (1)
#define ASSIGNBIT(REG , BITno , VALUE)   REG = (REG & ~(1 << BITno))|(VALUE << BITno)
#define TOGGLEBIT(REG , BITno)           REG ^= (1 << BITno)
#define Rotateleft(REG , BITno)          REG = (REG << BITno) | (REG >> (8*sizeof(REG)-BITno))

#define SETPORT(REG)                     REG |= 0xFF
#define CLRPORT(REG)                     REG &= 0x00
#define GETPORT(REG)                     REG & 0xFF
#define ASSIGNPORT(REG , VALUE)          REG = ((REG & 0x00)|VALUE)
#define TOGGLEPORT(REG)                  REG ^= 0xFF

#endif /* UTILES_H_ */
