#include "FAS_EziMOTIONPlusR.h"


int FAS_GetAxisStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwAxisStatus)
{
    const uint8_t FrameType = 0x2A;
    const uint8_t SendDataLen = 1;
    const uint8_t RcvDataLen = 1;
    uint8_t *SendBuffer = (uint8_t*) calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t *RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, 0, 0, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer,RcvDataLen);
    return FMM_OK;
}
int FAS_GetIOStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus);
int FAS_GetIOStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwInStatusLow, uint32_t* dwInStatusHigh, uint32_t* dwOutStatus);
int FAS_GetMotionStatus(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint32_t* dwAxisStatus);
int FAS_GetAllStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wPosItemNo);

int FAS_GetAllABSStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wCurrentPosItemNo);
int FAS_GetAllStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* pTypes, int32_t* pDatas);

int FAS_SetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lCmdPos);
int FAS_SetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lActPos);
int FAS_ClearPosition(uint8_t nPortNo, uint8_t iSlaveNo);
int FAS_GetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos);
int FAS_GetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActPos);
int FAS_GetPosError(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lPosErr);
int FAS_GetActualVel(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActVel);

int FAS_GetAlarmType(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nAlarmType);
int FAS_GetRunPTStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t* wPosItemNo);
