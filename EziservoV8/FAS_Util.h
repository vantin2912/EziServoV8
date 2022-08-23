#pragma once
#ifndef __FAS_UTIL__
#define __FAS_UTIL__
#include "FAS_Port.h"

uint8_t FAS_PackData(uint8_t SlaveID, uint8_t FrameType ,uint8_t* Data, uint8_t Len, uint8_t* PackedData, uint8_t* PackedLen);
#endif
