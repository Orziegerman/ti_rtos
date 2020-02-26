/****************************************************************************
* Title                 :   System monitor
* Filename              :   sysmonitor.c
* Author                :   Or Zaigerman
* Origin Date           :   04.12.2019
* Version               :   1.0.0
* Compiler              :   8.32.1
* Target                :   SmartMirror
* Copyright             :   Elcatech LTD
* All Rights Reserved
*
* COPYRIGHT(c) Elcatech LTD
*
* Redistribution and use in source and binary forms, with or without modification,
* are permitted provided that the following conditions are met:
*   1. Redistributions of source code must retain the above copyright notice,
*      this list of conditions and the following disclaimer.
*   2. Redistributions in binary form must reproduce the above copyright notice,
*      this list of conditions and the following disclaimer in the documentation
*      and/or other materials provided with the distribution.
*   3. Neither the name of Elcatech nor the names of its contributors
*      may be used to endorse or promote products derived from this software
*      without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*******************************************************************************/


/*============================================================================*
* Includes
*============================================================================*/
#include <stdbool.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Event.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Watchdog.h>

/* Example/Board Header files */
#include "Board.h"

/* Application Header files */
#include "sysmonitor.h"
/*============================================================================*
* Macros
*============================================================================*/
#define BIT_MASK_OF_TASK_IN_USED_1   Event_Id_00 | Event_Id_01 | Event_Id_02

/*============================================================================*
* Typedefs
*============================================================================*/


/*============================================================================*
* Constants
*============================================================================*/


/*============================================================================*
* Members
*============================================================================*/
Watchdog_Handle watchdogHandle;
extern Event_Handle sysmonitor_Event_mask_1;
/*============================================================================*
* Function Prototypes
*============================================================================*/
static void sysmonitor_wdtInit(void);
void watchdogCallback(uintptr_t unused);
/*============================================================================*
* Global Functions
*============================================================================*/



/*******************************************************************************
*  Function Name  : sysmonitor_init();
*  Description    : TBD
*  Input          : None
*  Output         : None
*  Return         : None
*******************************************************************************/
void sysmonitor_init(void)
{
    sysmonitor_wdtInit();

}





/*============================================================================*
 *  Static Functions
 *============================================================================*/

/*******************************************************************************
*  Function Name  : sysmonitor_wdtInit();
*  Description    : Init WDT
*
*
*  Input          : None
*
*  Return         : None
*******************************************************************************/
Void sysmonitor_clockHandle(UArg arg0)
{
    UInt32 Event_mask_1 = 0;
    UInt32 time;
    GPIO_toggle(Board_LED1);
    time = Clock_getTicks();
    System_printf("System time in clk0Fxn = %lu\n", (ULong)time);

    Event_mask_1 = Event_getPostedEvents(sysmonitor_Event_mask_1);
    if(Event_mask_1 == BIT_MASK_OF_TASK_IN_USED_1)
    {
        Watchdog_clear(watchdogHandle);
    }
}

/*******************************************************************************
*  Function Name  : sysmonitor_wdtInit();
*  Description    : Init WDT
*
*
*  Input          : None
*
*  Return         : None
*******************************************************************************/
static void sysmonitor_wdtInit(void)
{
    Board_initWatchdog();
    Watchdog_Params params;
    /* Create and enable a Watchdog with resets disabled */
    Watchdog_Params_init(&params);
    params.callbackFxn = (Watchdog_Callback)watchdogCallback;
    params.resetMode = Watchdog_RESET_ON;

    watchdogHandle = Watchdog_open(Board_WATCHDOG0, &params);
    if (watchdogHandle == NULL)
    {
      System_abort("Error opening Watchdog!\n");
    }

}
/*******************************************************************************
*  Function Name  : watchdogCallback();
*  Description    :
*
*  Watchdog interrupt callback function. It toggles and LED, and if a button
*  has not been pressed, clears the watchdog interrupt flag.
*
*  Input          : None
*
*  Return         : None
*******************************************************************************/
void watchdogCallback(uintptr_t unused)
{
   /* Clear watchdog interrupt flag */
   //GPIO_toggle(Board_LED0);
}





