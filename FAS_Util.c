#include "FAS_Util.h"
#include <string.h>
uint16_t FAS_CalcCRC(uint8_t* Data, uint8_t Len)
{
    unsigned char nTemp;
    unsigned short wCRCWord = 0xFFFF;
    while (Len--)
    {
        nTemp = wCRCWord ^ *(Data++);
        wCRCWord >>= 8;
        wCRCWord ^= TABLE_CRCVALUE[nTemp];
    }
    return wCRCWord;
}

uint8_t FAS_GetSync()
{
    static uint8_t Sync = 0;
    return Sync++;
}


uint8_t FAS_PackData(uint8_t SlaveID, uint8_t FrameType ,uint8_t* Data, uint8_t DataLen, uint8_t* PackedData, uint8_t* PackedLen)
{
    uint8_t _PackedLen = 0;
    uint8_t Sync = FAS_GetSync();
    /*  Add Slave ID*/
    memcpy(PackedData + _PackedLen, &SlaveID, 1); 
    _PackedLen +=1;
    /*  Add Sync Byte*/
    memcpy(PackedData + _PackedLen, &Sync, 1);
    _PackedLen +=1;
    /*  Add FrameType */
    memcpy(PackedData + _PackedLen, &FrameType, 1);
    _PackedLen +=1;
    /*  Add Data*/
    memcpy(PackedData+ _PackedLen, Data, DataLen);
    _PackedLen += DataLen;
    /* Add CRC */
    uint16_t CRC = FAS_CalcCRC(PackedData, _PackedLen);
    memcpy(PackedData + _PackedLen, &CRC, 2);
    _PackedLen += 2;
    /* Add Header*/
    memmove(PackedData + 2, FAS_Header, 2);
    memcpy(PackedData, FAS_Header,2);
    _PackedLen+=2;
    /*  Add Tail*/
    memcpy(PackedData + _PackedLen, FAS_Tail, 2);
    _PackedLen +=2;

    *PackedLen = _PackedLen;
    return Sync;
}