#ifndef EEPROM_H
#define	EEPROM_H
#include "Defines.h"
#include "p30F4013.h"

unsigned short Eeprom_ReadWord(unsigned short  pushAddressOffset);
void Eeprom_WriteWord(unsigned short  pushAddressOffset, unsigned short value);
#endif	/* CB_EEPROM_H */
