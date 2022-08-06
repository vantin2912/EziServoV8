// FAS_Ezi_SERVO.h:
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_)
#define AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_

#ifdef EZI_SERVO_PLUSR_EXPORTS
	#define EZI_SERVO_PLUSR_API __declspec(dllexport)

	#include "../MotionCommon/MOTION_DEFINE.h"
#else
	#include "FAS_Util.h"	
	#include "ReturnCodes_Define.h"
	#include "MOTION_DEFINE.h"
	#include "COMM_Define.h"
#endif


uint8_t 	FAS_Connect(uint8_t nPortNo, uint32_t dwBaud);

uint8_t 	FAS_OpenPort(uint8_t nPortNo, uint32_t dwBaud);
uint8_t 	FAS_AttachSlave(uint8_t nPortNo, uint8_t iSlaveNo);

void 	FAS_Close(uint8_t nPortNo);

void 	FAS_EnableLog(uint8_t bEnable);
uint8_t 	FAS_SetLogPath(char* lpPath);

uint8_t 	FAS_IsSlaveExist(uint8_t nPortNo, uint8_t iSlaveNo);

int 	FAS_GetSlaveInfo(uint8_t nPortNo, uint8_t iSlaveNo, DRIVE_INFO* lpDriveInfo);

int 	FAS_SaveAllParameters(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_SetParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t lParamValue);
int 	FAS_GetParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t* lParamValue);
int 	FAS_GetROMParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t* lRomParam);

//------------------------------------------------------------------------------
//					IO Functions
//------------------------------------------------------------------------------
int 	FAS_SetIOInput(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t uIOSETMask, uint64_t uIOCLRMask);
int 	FAS_SetIOInputEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwIOSETMaskLow, uint32_t dwIOSETMaskHigh, uint32_t dwIOCLRMaskLow, uint32_t dwIOCLRMaskHigh);
int 	FAS_GetIOInput(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uIOInput);
int 	FAS_GetIOInputEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwIOInputLow, uint32_t* dwIOInputHigh);

int 	FAS_SetIOOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwIOSETMask, uint32_t dwIOCLRMask);
int 	FAS_GetIOOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwIOOutput);

int 	FAS_GetInputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iInPinNo, uint8_t* nInLogicNo, uint8_t* bLevel);
int 	FAS_GetOutputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iOutPinNo, uint8_t* nOutLogicNo, uint8_t* bLevel);
int 	FAS_SetInputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iInPinNo, uint8_t nInLogicNo, uint8_t bLevel);
int 	FAS_SetOutputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iOutPinNo, uint8_t nOutLogicNo, uint8_t bLevel);

int 	FAS_IOAssignMapReadROM(uint8_t nPortNo, uint8_t iSlaveNo);

//------------------------------------------------------------------------------
//					Servo Driver Control Functions
//------------------------------------------------------------------------------		
int 	FAS_ServoEnable(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bOnOff);
int 	FAS_ServoAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_StepAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bReset);
int 	FAS_BrakeSet(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bSet, int* nResult);

//------------------------------------------------------------------------------
//					Read Status and Position
//------------------------------------------------------------------------------
int 	FAS_GetAxisStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwAxisStatus);
int 	FAS_GetIOStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus);
int 	FAS_GetIOStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwInStatusLow, uint32_t* dwInStatusHigh, uint32_t* dwOutStatus);
int 	FAS_GetMotionStatus(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint32_t* dwAxisStatus);
int 	FAS_GetAllStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wPosItemNo);

int 	FAS_GetAllABSStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wCurrentPosItemNo);
int 	FAS_GetAllStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* pTypes, int32_t* pDatas);

int 	FAS_SetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lCmdPos);
int 	FAS_SetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lActPos);
int 	FAS_ClearPosition(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_GetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos);
int 	FAS_GetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActPos);
int 	FAS_GetPosError(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lPosErr);
int 	FAS_GetActualVel(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActVel);

int 	FAS_GetAlarmType(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nAlarmType);
int 	FAS_GetRunPTStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t* wPosItemNo);

//------------------------------------------------------------------
//					Motion Functions.
//------------------------------------------------------------------
int 	FAS_MoveStop(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_EmergencyStop(uint8_t nPortNo, uint8_t iSlaveNo);

int 	FAS_MovePause(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bPause);

int 	FAS_MoveOriginSingleAxis(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_MoveSingleAxisAbsPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity);
int 	FAS_MoveSingleAxisIncPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity);
int 	FAS_MoveToLimit(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iLimitDir);
int 	FAS_MoveVelocity(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir);

int 	FAS_PositionAbsOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos);
int 	FAS_PositionIncOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos);
int 	FAS_VelocityOverride(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity);

int 	FAS_MoveLinearAbsPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lAbsPos, uint32_t lFeedrate, uint16_t wAccelTime);
int 	FAS_MoveLinearIncPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lIncPos, uint32_t lFeedrate, uint16_t wAccelTime);

int 	FAS_MovePush(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwStartSpd, uint32_t dwMoveSpd, int32_t lPosition, uint16_t wAccel, uint16_t wDecel, uint16_t wPushRate, uint32_t dwPushSpd, int32_t lEndPosition, uint16_t wPushMode);
int 	FAS_GetPushStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nPushStatus);

//------------------------------------------------------------------
//					Ex-Motion Functions.
//------------------------------------------------------------------
int 	FAS_MoveSingleAxisAbsPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption);
int 	FAS_MoveSingleAxisIncPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption);
int 	FAS_MoveVelocityEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir, VELOCITY_OPTION_EX* lpExOption);

//------------------------------------------------------------------
//					All-Motion Functions.
//------------------------------------------------------------------
int 	FAS_AllMoveStop(uint8_t nPortNo);
int 	FAS_AllEmergencyStop(uint8_t nPortNo);
int 	FAS_AllMoveOriginSingleAxis(uint8_t nPortNo);
int 	FAS_AllMoveSingleAxisAbsPos(uint8_t nPortNo, int32_t lAbsPos, uint32_t lVelocity);
int 	FAS_AllMoveSingleAxisIncPos(uint8_t nPortNo, int32_t lIncPos, uint32_t lVelocity);

//------------------------------------------------------------------
//					Position Table Functions.
//------------------------------------------------------------------
int 	FAS_PosTableReadItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, LPITEM_NODE lpItem);
int 	FAS_PosTableWriteItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, LPITEM_NODE lpItem);
int 	FAS_PosTableWriteROM(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_PosTableReadROM(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_PosTableRunItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo);

int 	FAS_PosTableReadOneItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, uint16_t wOffset, int32_t* lPosItemVal);
int 	FAS_PosTableWriteOneItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, uint16_t wOffset, int32_t lPosItemVal);
int 	FAS_PosTableSingleRunItem(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bNextMove, uint16_t wItemNo);

//------------------------------------------------------------------
//					I/O Module Functions.
//------------------------------------------------------------------
int 	FAS_GetInput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uInput, uint32_t* uLatch);

int 	FAS_ClearLatch(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uLatchMask);
int 	FAS_GetLatchCount(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char iInputNo, uint32_t* uCount);
int 	FAS_GetLatchCountAll(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t** ppuAllCount);
int 	FAS_ClearLatchCount(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uInputMask);

int 	FAS_GetOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uOutput, uint32_t* uStatus);
int 	FAS_SetOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uSetMask, uint32_t uClearMask);

int 	FAS_SetTrigger(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char uOutputNo, TRIGGER_INFO* pTrigger);
int 	FAS_SetRunStop(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uRunMask, uint32_t uStopMask);
int 	FAS_GetTriggerCount(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char uOutputNo, uint32_t* uCount);

int 	FAS_GetIOLevel(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uIOLevel);
int 	FAS_SetIOLevel(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uIOLevel);
int 	FAS_LoadIOLevel(uint8_t nPortNo, uint8_t iSlaveNo);
int 	FAS_SaveIOLevel(uint8_t nPortNo, uint8_t iSlaveNo);

int 	FAS_GetInputFilter(uint8_t nPortNo, uint8_t iSlaveNo, unsigned short* filter);
int 	FAS_SetInputFilter(uint8_t nPortNo, uint8_t iSlaveNo, unsigned short filter);

//------------------------------------------------------------------
//					Ezi-IO AD Functions
//------------------------------------------------------------------
int 	FAS_GetAllADResult(uint8_t nPortNo, uint8_t iSlaveNo, AD_RESULT* result);
int 	FAS_GetADResult(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t channel, float* adresult);
int 	FAS_SetADRange(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t channel, AD_RANGE range);

#endif // !defined(AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_)
