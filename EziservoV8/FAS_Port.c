#include "FAS_Port.h"
#include <stdio.h>



__attribute__((weak)) uint8_t FAS_Send(uint8_t Port, uint8_t* SendBuffer, uint8_t Len)
{
    for(uint8_t i = 0; i < Len; ++i)
    {
        printf("0x%.2x ",SendBuffer[i]);
    }
    printf("\r\n");

    return 0;
}
__attribute__((weak)) uint8_t FAS_Receive(uint8_t Port, uint8_t* RcvBuffer, uint8_t* RxLen)
{

    return 0;
}
