# EziServoV8_Lib


## Description
Unofficially C library source for Fastech Eziservo V8


## Installation

Add library to your build system

Include Library Header
'''
#include "FAS_EziMOTIONPlusR.h"
'''

Implement send and receive function

'''
uint8_t FAS_Send(uint8_t Port, uint8_t* SendBuffer, uint8_t Len)
{
    /*
        Your Send function
        return FMM_OK           if Port is open and available to send
        return FMM_NOT_OPEN     if Port is not open and unavailable to send
    
    */
	return FMM_OK;
}

uint8_t FAS_Receive(uint8_t Port, uint8_t* RcvBuffer, uint8_t* RxLen)
{
    /*
        Your Receive function
        return FMM_OK           if Port is open and available to send
        return FMM_NOT_OPEN     if Port is not open and unavailable to send
    
    */
	return FMM_OK;
}
'''


## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.


## Project status
Working on Progress
Just only implement ServoControl, Motion, and get Status function
