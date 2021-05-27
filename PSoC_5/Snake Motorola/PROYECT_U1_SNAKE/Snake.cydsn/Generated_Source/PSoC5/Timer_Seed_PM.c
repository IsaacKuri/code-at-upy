/*******************************************************************************
* File Name: Timer_Seed_PM.c
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

#include "Timer_Seed.h"

static Timer_Seed_backupStruct Timer_Seed_backup;


/*******************************************************************************
* Function Name: Timer_Seed_SaveConfig
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
*  Timer_Seed_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Timer_Seed_SaveConfig(void) 
{
    #if (!Timer_Seed_UsingFixedFunction)
        Timer_Seed_backup.TimerUdb = Timer_Seed_ReadCounter();
        Timer_Seed_backup.InterruptMaskValue = Timer_Seed_STATUS_MASK;
        #if (Timer_Seed_UsingHWCaptureCounter)
            Timer_Seed_backup.TimerCaptureCounter = Timer_Seed_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Timer_Seed_UDB_CONTROL_REG_REMOVED)
            Timer_Seed_backup.TimerControlRegister = Timer_Seed_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Timer_Seed_RestoreConfig
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
*  Timer_Seed_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Seed_RestoreConfig(void) 
{   
    #if (!Timer_Seed_UsingFixedFunction)

        Timer_Seed_WriteCounter(Timer_Seed_backup.TimerUdb);
        Timer_Seed_STATUS_MASK =Timer_Seed_backup.InterruptMaskValue;
        #if (Timer_Seed_UsingHWCaptureCounter)
            Timer_Seed_SetCaptureCount(Timer_Seed_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Timer_Seed_UDB_CONTROL_REG_REMOVED)
            Timer_Seed_WriteControlRegister(Timer_Seed_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Timer_Seed_Sleep
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
*  Timer_Seed_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Timer_Seed_Sleep(void) 
{
    #if(!Timer_Seed_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Timer_Seed_CTRL_ENABLE == (Timer_Seed_CONTROL & Timer_Seed_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Timer_Seed_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Timer_Seed_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Timer_Seed_Stop();
    Timer_Seed_SaveConfig();
}


/*******************************************************************************
* Function Name: Timer_Seed_Wakeup
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
*  Timer_Seed_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Timer_Seed_Wakeup(void) 
{
    Timer_Seed_RestoreConfig();
    #if(!Timer_Seed_UDB_CONTROL_REG_REMOVED)
        if(Timer_Seed_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Timer_Seed_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
