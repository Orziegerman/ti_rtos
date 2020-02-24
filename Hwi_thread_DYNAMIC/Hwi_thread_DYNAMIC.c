/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== empty.c ========
 */
#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"


#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Hwi.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>


/* Board Header file */
#include "Board.h"

static void Timer2A_Interrupt_Init(void);
uint32_t Timer2A_Vector = 39;

void hwi_ledController(UArg arg0)
{

    TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
    GPIO_toggle(Board_LED0);

}
int main(void)
{

    Hwi_Params  hwiParams;
    Hwi_Handle  hwi0;
    Error_Block eb;
    Error_init(&eb);


    Hwi_Params_init(&hwiParams);
    /* Call board init functions */
    Board_initGeneral();
    Board_initGPIO();
    Timer2A_Interrupt_Init();

    hwi0 = Hwi_create(Timer2A_Vector, hwi_ledController, &hwiParams, &eb);
    if(hwi0 == NULL)
    {
        System_abort("Hwi0 create failed");
    }
    /* Start BIOS */
    BIOS_start();

    return (0);
}



static void Timer2A_Interrupt_Init(void)
{
   uint32_t  ui32Period;
    /* Set CPU Clock to 40MHZ */
   SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN );
   SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
   TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);
   ui32Period = (SysCtlClockGet() / 2); // period = CPU clk div 2 (500ms)
   TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period); // set Timer 2 period
   TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);
   TimerEnable(TIMER2_BASE, TIMER_A);

}
