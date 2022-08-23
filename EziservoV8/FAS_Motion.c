#include "FAS_EziMOTIONPlusR.h"
#include <string.h>
int FAS_MoveStop(uint8_t nPortNo, uint8_t iSlaveNo)
{
    const uint8_t FrameType = 0x31;
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
int FAS_EmergencyStop(uint8_t nPortNo, uint8_t iSlaveNo)
{
    const uint8_t FrameType = 0x32;
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

int FAS_MovePause(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bPause)
{
    const uint8_t FrameType = 0x33;
    const uint8_t SendDataLen = 1;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, &bPause, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}

int FAS_MoveOriginSingleAxis(uint8_t nPortNo, uint8_t iSlaveNo)
{
    const uint8_t FrameType = 0x33;
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
int FAS_MoveSingleAxisAbsPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity)
{
    const uint8_t FrameType = 0x34;
    const uint8_t SendDataLen = 8;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2*SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lAbsPos, 4);
    memcpy(Data + 4, &lVelocity, 4);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_MoveSingleAxisIncPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity)
{
    const uint8_t FrameType = 0x35;
    const uint8_t SendDataLen = 8;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lIncPos, 4);
    memcpy(Data + 4, &lVelocity, 4);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_MoveToLimit(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iLimitDir)
{
    const uint8_t FrameType = 0x36;
    const uint8_t SendDataLen = 5;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lVelocity, 4);
    memcpy(Data + 4, &iLimitDir, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_MoveVelocity(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir)
{
    const uint8_t FrameType = 0x37;
    const uint8_t SendDataLen = 5;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lVelocity, 4);
    memcpy(Data + 4, &iVelDir, 1);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_PositionAbsOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos)
{
    const uint8_t FrameType = 0x38;
    const uint8_t SendDataLen = 4;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lOverridePos, 4);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_PositionIncOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos)
{
    const uint8_t FrameType = 0x39;
    const uint8_t SendDataLen = 4;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lOverridePos, 4);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_VelocityOverride(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity)
{
    const uint8_t FrameType = 0x3A;
    const uint8_t SendDataLen = 4;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lVelocity, 4);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}

int FAS_MoveLinearAbsPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lAbsPos, uint32_t lFeedrate, uint16_t wAccelTime)
{
    return FMM_UNKNOWN_ERROR;
}
int FAS_MoveLinearIncPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lIncPos, uint32_t lFeedrate, uint16_t wAccelTime)
{
    return FMM_UNKNOWN_ERROR;
}

int FAS_MovePush(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwStartSpd, uint32_t dwMoveSpd, int32_t lPosition, uint16_t wAccel, uint16_t wDecel, uint16_t wPushRate, uint32_t dwPushSpd, int32_t lEndPosition, uint16_t wPushMode)
{
    return FMM_UNKNOWN_ERROR;
}
int FAS_GetPushStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nPushStatus)
{
    return FMM_UNKNOWN_ERROR;
}


int FAS_MoveSingleAxisAbsPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption)
{
    const uint8_t FrameType = 0x80;
    const uint8_t SendDataLen = 40;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lAbsPos, 4);
    memcpy(Data + 4, &lVelocity, 4);
    memcpy(Data + 8, lpExOption, 10);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_MoveSingleAxisIncPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption)
{
    const uint8_t FrameType = 0x81;
    const uint8_t SendDataLen = 40;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lIncPos, 4);
    memcpy(Data + 4, &lVelocity, 4);
    memcpy(Data + 8, lpExOption, 10);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
int FAS_MoveVelocityEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir, VELOCITY_OPTION_EX* lpExOption)
{
    const uint8_t FrameType = 0x82;
    const uint8_t SendDataLen = 40;
    const uint8_t RcvDataLen = 1;
    uint8_t* SendBuffer = (uint8_t*)calloc(15 + 2 * SendDataLen, 1);
    uint8_t SendLen;
    uint8_t* RcvBuffer = (uint8_t*)calloc(15 + SendDataLen, 1);

    uint8_t* Data = (uint8_t*)calloc(SendDataLen, 1);
    memcpy(Data, &lVelocity, 4);
    memcpy(Data + 4, &iVelDir, 1);
    memcpy(Data + 5, lpExOption, 6);
    uint8_t SyncByte = FAS_PackData(iSlaveNo, FrameType, Data, SendDataLen, SendBuffer, &SendLen);
    FAS_Send(nPortNo, SendBuffer, SendLen);
    free(SendBuffer);


    FAS_Receive(nPortNo, RcvBuffer, &RcvDataLen);
    return FMM_OK;
}
