#include "FAS_EziMOTIONPlusR.h"
#include <stdlib.h>
int FAS_ServoEnable(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bOnOff)
{
    const uint8_t FrameType = 0x2A;
    const uint8_t SendDataLen = 1;
    const uint8_t RcvDataLen = 1;
    uint8_t ComStatus;
    uint8_t *SendBuffer = (uint8_t*) calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t *RcvBuffer = (uint8_t*)calloc(15 + 2*RcvDataLen, 1);
    uint8_t RcvLen;
    uint8_t* RespData = (uint8_t*)calloc(RcvDataLen + 2, 1);
    uint8_t RespDataLen;

    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, &bOnOff, 1, SendBuffer, &SendLen);
    ComStatus = FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    ComStatus = FAS_Receive(nPortNo, RcvBuffer,&RcvLen);
    ComStatus = FAS_UnPackData(RcvBuffer, RcvLen, iSlaveNo, SyncByte, FrameType, RespData, &RespDataLen);
    if(ComStatus != FMM_OK) return ComStatus;

    if(RespDataLen != RcvDataLen)
    {
    	free(RcvBuffer);
    	free(RespData);
    	return FMM_UNKNOWN_ERROR;
    }

    ComStatus = RespData[0];
    free(RcvBuffer);
	free(RespData);
    return ComStatus;
}
int FAS_ServoAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo)
{
    const uint8_t FrameType = 0x2B;
    const uint8_t SendDataLen = 0;
    const uint8_t RcvDataLen = 1;
    uint8_t ComStatus;

    uint8_t* SendBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + 2*RcvDataLen, 1);
    uint8_t RcvLen;
    uint8_t* RespData = (uint8_t*)calloc(RcvDataLen + 2, 1);
    uint8_t RespDataLen;

    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, NULL, 0, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    ComStatus = FAS_Receive(nPortNo, RcvBuffer,&RcvLen);
	ComStatus = FAS_UnPackData(RcvBuffer, RcvLen, iSlaveNo, SyncByte, FrameType, RespData, &RespDataLen);
	if(ComStatus != FMM_OK) return ComStatus;

	if(RespDataLen != RcvDataLen)
	{
		free(RcvBuffer);
		free(RespData);
		return FMM_UNKNOWN_ERROR;
	}

	ComStatus = RespData[0];
	free(RcvBuffer);
	free(RespData);
	return ComStatus;
}
int FAS_StepAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bReset)
{
    return FMM_UNKNOWN_ERROR;
}
int FAS_BrakeSet(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bSet, int* nResult)
{
    return FMM_UNKNOWN_ERROR;
}
