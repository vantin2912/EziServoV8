#include "FAS_EziMOTIONPlusR.h"
#include <stdlib.h>
int FAS_ServoEnable(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bOnOff)
{
    const uint8_t FrameType = 0x2A;
    const uint8_t SendDataLen = 1;
    const uint8_t RcvDataLen = 1;
    uint8_t *SendBuffer = (uint8_t*) calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t *RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, &bOnOff, 1, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer,&RcvDataLen);
    return FMM_OK;
}
int FAS_ServoAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo)
{
    const uint8_t FrameType = 0x2B;
    const uint8_t SendDataLen = 0;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, NULL, 0, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_StepAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bReset)
{
    return FMM_UNKNOWN_ERROR;
}
int FAS_BrakeSet(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bSet, int* nResult)
{
    return FMM_UNKNOWN_ERROR;
}
