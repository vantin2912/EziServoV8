#include "FAS_EziMOTIONPlusR.h"

int 	FAS_ServoEnable(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bOnOff);
int 	FAS_ServoAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_StepAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bReset);
int 	FAS_BrakeSet(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bSet, int* nResult);