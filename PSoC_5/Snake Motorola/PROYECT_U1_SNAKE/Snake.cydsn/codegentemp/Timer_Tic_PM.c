/*******************************************************************************
* File Name: Timer_Tic_PM.c
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

#include "Timer_Tic.h"

static Timer_Tic_backupStruct Timer_Tic_backup;


/*******************************************************************************
* Function Name: Timer_Tic_SaveConfig
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
*  Timer_Tic_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Tic_SaveConfig(void) 
{
    #if (!Timer_Tic_UsingFixedFunction)
        Timer_Tic_backup.TimerUdb = Timer_Tic_ReadCounter();
        Timer_Tic_backup.InterruptMaskValue = Timer_Tic_STATUS_MASK;
        #if (Timer_Tic_UsingHWCaptureCounter)
            Timer_Tic_backup.TimerCaptureCounter = Timer_Tic_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Tic_UDB_CONTROL_REG_REMOVED)
            Timer_Tic_backup.TimerControlRegister = Timer_Tic_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Tic_RestoreConfig
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
*  Timer_Tic_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Tic_RestoreConfig(void) 
{   
    #if (!Timer_Tic_UsingFixedFunction)

        Timer_Tic_WriteCounter(Timer_Tic_backup.TimerUdb);
        Timer_Tic_STATUS_MASK =Timer_Tic_backup.InterruptMaskValue;
        #if (Timer_Tic_UsingHWCaptureCounter)
            Timer_Tic_SetCaptureCount(Timer_Tic_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Tic_UDB_CONTROL_REG_REMOVED)
            Timer_Tic_WriteControlRegister(Timer_Tic_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Tic_Sleep
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
*  Timer_Tic_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Tic_Sleep(void) 
{
    #if(!Timer_Tic_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Tic_CTRL_ENABLE == (Timer_Tic_CONTROL & Timer_Tic_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Tic_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Tic_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Tic_Stop();
    Timer_Tic_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Tic_Wakeup
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
*  Timer_Tic_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Tic_Wakeup(void) 
{
    Timer_Tic_RestoreConfig();
    #if(!Timer_Tic_UDB_CONTROL_REG_REMOVED)
        if(Timer_Tic_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Tic_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
