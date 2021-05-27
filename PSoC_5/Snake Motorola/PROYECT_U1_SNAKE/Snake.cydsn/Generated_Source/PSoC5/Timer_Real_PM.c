/*******************************************************************************
* File Name: Timer_Real_PM.c
* Version 2.80
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "Timer_Real.h"

static Timer_Real_backupStruct Timer_Real_backup;


/*******************************************************************************
* Function Name: Timer_Real_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Real_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Real_SaveConfig(void) 
{
    #if (!Timer_Real_UsingFixedFunction)
        Timer_Real_backup.TimerUdb = Timer_Real_ReadCounter();
        Timer_Real_backup.InterruptMaskValue = Timer_Real_STATUS_MASK;
        #if (Timer_Real_UsingHWCaptureCounter)
            Timer_Real_backup.TimerCaptureCounter = Timer_Real_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Real_UDB_CONTROL_REG_REMOVED)
            Timer_Real_backup.TimerControlRegister = Timer_Real_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Real_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Real_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Real_RestoreConfig(void) 
{   
    #if (!Timer_Real_UsingFixedFunction)

        Timer_Real_WriteCounter(Timer_Real_backup.TimerUdb);
        Timer_Real_STATUS_MASK =Timer_Real_backup.InterruptMaskValue;
        #if (Timer_Real_UsingHWCaptureCounter)
            Timer_Real_SetCaptureCount(Timer_Real_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Real_UDB_CONTROL_REG_REMOVED)
            Timer_Real_WriteControlRegister(Timer_Real_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Real_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Real_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Real_Sleep(void) 
{
    #if(!Timer_Real_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Real_CTRL_ENABLE == (Timer_Real_CONTROL & Timer_Real_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Real_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Real_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Real_Stop();
    Timer_Real_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Real_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  Timer_Real_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Real_Wakeup(void) 
{
    Timer_Real_RestoreConfig();
    #if(!Timer_Real_UDB_CONTROL_REG_REMOVED)
        if(Timer_Real_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Real_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
