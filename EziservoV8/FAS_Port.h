#pragma once
#ifndef __FAS_PORT__
#define __FAS_PORT__
#include <stdint.h>

uint8_t FAS_Send(uint8_t Port, uint8_t* SendBuffer, uint8_t Len);
uint8_t FAS_Receive(uint8_t Port, uint8_t* RcvBuffer, uint8_t* Len);
#endif
