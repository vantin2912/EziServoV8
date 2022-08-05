// FAS_Ezi_SERVO.h:
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_)
#define AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_

#ifdef EZI_SERVO_PLUSR_EXPORTS
	#define EZI_SERVO_PLUSR_API __declspec(dllexport)

	#include "../MotionCommon/MOTION_DEFINE.h"
#else
	#define EZI_SERVO_PLUSR_API __declspec(dllimport)
	#pragma comment( lib, "EziMOTIONPlusR.lib" )

	#include "ReturnCodes_Define.h"
	#include "MOTION_DEFINE.h"
	#include "COMM_Define.h"
#endif

#define FAPI extern "C" EZI_SERVO_PLUSR_API

FAPI uint8_t 	FAS_Connect(uint8_t nPortNo, uint32_t dwBaud);

FAPI uint8_t 	FAS_OpenPort(uint8_t nPortNo, uint32_t dwBaud);
FAPI uint8_t 	FAS_AttachSlave(uint8_t nPortNo, uint8_t iSlaveNo);

FAPI void 	FAS_Close(uint8_t nPortNo);

FAPI void 	FAS_EnableLog(uint8_t bEnable);
FAPI uint8_t 	FAS_SetLogPath(char* lpPath);

FAPI uint8_t 	FAS_IsSlaveExist(uint8_t nPortNo, uint8_t iSlaveNo);

FAPI int 	FAS_GetSlaveInfo(uint8_t nPortNo, uint8_t iSlaveNo, DRIVE_INFO* lpDriveInfo);

FAPI int 	FAS_SaveAllParameters(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_SetParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t lParamValue);
FAPI int 	FAS_GetParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t* lParamValue);
FAPI int 	FAS_GetROMParameter(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iParamNo, int32_t* lRomParam);

//------------------------------------------------------------------------------
//					IO Functions
//------------------------------------------------------------------------------
FAPI int 	FAS_SetIOInput(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t uIOSETMask, uint64_t uIOCLRMask);
FAPI int 	FAS_SetIOInputEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwIOSETMaskLow, uint32_t dwIOSETMaskHigh, uint32_t dwIOCLRMaskLow, uint32_t dwIOCLRMaskHigh);
FAPI int 	FAS_GetIOInput(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uIOInput);
FAPI int 	FAS_GetIOInputEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwIOInputLow, uint32_t* dwIOInputHigh);

FAPI int 	FAS_SetIOOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwIOSETMask, uint32_t dwIOCLRMask);
FAPI int 	FAS_GetIOOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwIOOutput);

FAPI int 	FAS_GetInputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iInPinNo, uint8_t* nInLogicNo, uint8_t* bLevel);
FAPI int 	FAS_GetOutputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iOutPinNo, uint8_t* nOutLogicNo, uint8_t* bLevel);
FAPI int 	FAS_SetInputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iInPinNo, uint8_t nInLogicNo, uint8_t bLevel);
FAPI int 	FAS_SetOutputAssignMap(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t iOutPinNo, uint8_t nOutLogicNo, uint8_t bLevel);

FAPI int 	FAS_IOAssignMapReadROM(uint8_t nPortNo, uint8_t iSlaveNo);

//------------------------------------------------------------------------------
//					Servo Driver Control Functions
//------------------------------------------------------------------------------		
FAPI int 	FAS_ServoEnable(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bOnOff);
FAPI int 	FAS_ServoAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_StepAlarmReset(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bReset);
FAPI int 	FAS_BrakeSet(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bSet, int* nResult);

//------------------------------------------------------------------------------
//					Read Status and Position
//------------------------------------------------------------------------------
FAPI int 	FAS_GetAxisStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwAxisStatus);
FAPI int 	FAS_GetIOStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus);
FAPI int 	FAS_GetIOStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* dwInStatusLow, uint32_t* dwInStatusHigh, uint32_t* dwOutStatus);
FAPI int 	FAS_GetMotionStatus(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint32_t* dwAxisStatus);
FAPI int 	FAS_GetAllStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wPosItemNo);

FAPI int 	FAS_GetAllABSStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint64_t* uInStatus, uint32_t* dwOutStatus, uint32_t* dwAxisStatus, int32_t* lCmdPos, int32_t* lActPos, int32_t* lPosErr, int32_t* lActVel, uint16_t* wCurrentPosItemNo);
FAPI int 	FAS_GetAllStatusEx(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* pTypes, int32_t* pDatas);

FAPI int 	FAS_SetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lCmdPos);
FAPI int 	FAS_SetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lActPos);
FAPI int 	FAS_ClearPosition(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_GetCommandPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lCmdPos);
FAPI int 	FAS_GetActualPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActPos);
FAPI int 	FAS_GetPosError(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lPosErr);
FAPI int 	FAS_GetActualVel(uint8_t nPortNo, uint8_t iSlaveNo, int32_t* lActVel);

FAPI int 	FAS_GetAlarmType(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nAlarmType);
FAPI int 	FAS_GetRunPTStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t* wPosItemNo);

//------------------------------------------------------------------
//					Motion Functions.
//------------------------------------------------------------------
FAPI int 	FAS_MoveStop(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_EmergencyStop(uint8_t nPortNo, uint8_t iSlaveNo);

FAPI int 	FAS_MovePause(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bPause);

FAPI int 	FAS_MoveOriginSingleAxis(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_MoveSingleAxisAbsPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity);
FAPI int 	FAS_MoveSingleAxisIncPos(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity);
FAPI int 	FAS_MoveToLimit(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iLimitDir);
FAPI int 	FAS_MoveVelocity(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir);

FAPI int 	FAS_PositionAbsOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos);
FAPI int 	FAS_PositionIncOverride(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lOverridePos);
FAPI int 	FAS_VelocityOverride(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity);

FAPI int 	FAS_MoveLinearAbsPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lAbsPos, uint32_t lFeedrate, uint16_t wAccelTime);
FAPI int 	FAS_MoveLinearIncPos(uint8_t nPortNo, uint8_t nNoOfSlaves, uint8_t* iSlavesNo, int32_t* lIncPos, uint32_t lFeedrate, uint16_t wAccelTime);

FAPI int 	FAS_MovePush(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t dwStartSpd, uint32_t dwMoveSpd, int32_t lPosition, uint16_t wAccel, uint16_t wDecel, uint16_t wPushRate, uint32_t dwPushSpd, int32_t lEndPosition, uint16_t wPushMode);
FAPI int 	FAS_GetPushStatus(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t* nPushStatus);

//------------------------------------------------------------------
//					Ex-Motion Functions.
//------------------------------------------------------------------
FAPI int 	FAS_MoveSingleAxisAbsPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lAbsPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption);
FAPI int 	FAS_MoveSingleAxisIncPosEx(uint8_t nPortNo, uint8_t iSlaveNo, int32_t lIncPos, uint32_t lVelocity, MOTION_OPTION_EX* lpExOption);
FAPI int 	FAS_MoveVelocityEx(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t lVelocity, int iVelDir, VELOCITY_OPTION_EX* lpExOption);

//------------------------------------------------------------------
//					All-Motion Functions.
//------------------------------------------------------------------
FAPI int 	FAS_AllMoveStop(uint8_t nPortNo);
FAPI int 	FAS_AllEmergencyStop(uint8_t nPortNo);
FAPI int 	FAS_AllMoveOriginSingleAxis(uint8_t nPortNo);
FAPI int 	FAS_AllMoveSingleAxisAbsPos(uint8_t nPortNo, int32_t lAbsPos, uint32_t lVelocity);
FAPI int 	FAS_AllMoveSingleAxisIncPos(uint8_t nPortNo, int32_t lIncPos, uint32_t lVelocity);

//------------------------------------------------------------------
//					Position Table Functions.
//------------------------------------------------------------------
FAPI int 	FAS_PosTableReadItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, LPITEM_NODE lpItem);
FAPI int 	FAS_PosTableWriteItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, LPITEM_NODE lpItem);
FAPI int 	FAS_PosTableWriteROM(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_PosTableReadROM(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_PosTableRunItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo);

FAPI int 	FAS_PosTableReadOneItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, uint16_t wOffset, int32_t* lPosItemVal);
FAPI int 	FAS_PosTableWriteOneItem(uint8_t nPortNo, uint8_t iSlaveNo, uint16_t wItemNo, uint16_t wOffset, int32_t lPosItemVal);
FAPI int 	FAS_PosTableSingleRunItem(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t bNextMove, uint16_t wItemNo);

//------------------------------------------------------------------
//					I/O Module Functions.
//------------------------------------------------------------------
FAPI int 	FAS_GetInput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uInput, uint32_t* uLatch);

FAPI int 	FAS_ClearLatch(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uLatchMask);
FAPI int 	FAS_GetLatchCount(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char iInputNo, uint32_t* uCount);
FAPI int 	FAS_GetLatchCountAll(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t** ppuAllCount);
FAPI int 	FAS_ClearLatchCount(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uInputMask);

FAPI int 	FAS_GetOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uOutput, uint32_t* uStatus);
FAPI int 	FAS_SetOutput(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uSetMask, uint32_t uClearMask);

FAPI int 	FAS_SetTrigger(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char uOutputNo, TRIGGER_INFO* pTrigger);
FAPI int 	FAS_SetRunStop(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uRunMask, uint32_t uStopMask);
FAPI int 	FAS_GetTriggerCount(uint8_t nPortNo, uint8_t iSlaveNo, unsigned char uOutputNo, uint32_t* uCount);

FAPI int 	FAS_GetIOLevel(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t* uIOLevel);
FAPI int 	FAS_SetIOLevel(uint8_t nPortNo, uint8_t iSlaveNo, uint32_t uIOLevel);
FAPI int 	FAS_LoadIOLevel(uint8_t nPortNo, uint8_t iSlaveNo);
FAPI int 	FAS_SaveIOLevel(uint8_t nPortNo, uint8_t iSlaveNo);

FAPI int 	FAS_GetInputFilter(uint8_t nPortNo, uint8_t iSlaveNo, unsigned short* filter);
FAPI int 	FAS_SetInputFilter(uint8_t nPortNo, uint8_t iSlaveNo, unsigned short filter);

//------------------------------------------------------------------
//					Ezi-IO AD Functions
//------------------------------------------------------------------
FAPI int 	FAS_GetAllADResult(uint8_t nPortNo, uint8_t iSlaveNo, AD_RESULT* result);
FAPI int 	FAS_GetADResult(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t channel, float* adresult);
FAPI int 	FAS_SetADRange(uint8_t nPortNo, uint8_t iSlaveNo, uint8_t channel, AD_RANGE range);

#endif // !defined(AFX_FAS_EZI_SERVO_H__9185E608_0EDA_4C3B_8E92_B518968D037B__INCLUDED_)
