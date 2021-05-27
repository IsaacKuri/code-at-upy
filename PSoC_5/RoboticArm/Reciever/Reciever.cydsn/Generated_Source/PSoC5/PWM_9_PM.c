/*******************************************************************************
* File Name: PWM_9_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_9.h"

static PWM_9_backupStruct PWM_9_backup;


/*******************************************************************************
* Function Name: PWM_9_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_9_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_9_SaveConfig(void) 
{

    #if(!PWM_9_UsingFixedFunction)
        #if(!PWM_9_PWMModeIsCenterAligned)
            PWM_9_backup.PWMPeriod = PWM_9_ReadPeriod();
        #endif /* (!PWM_9_PWMModeIsCenterAligned) */
        PWM_9_backup.PWMUdb = PWM_9_ReadCounter();
        #if (PWM_9_UseStatus)
            PWM_9_backup.InterruptMaskValue = PWM_9_STATUS_MASK;
        #endif /* (PWM_9_UseStatus) */

        #if(PWM_9_DeadBandMode == PWM_9__B_PWM__DBM_256_CLOCKS || \
            PWM_9_DeadBandMode == PWM_9__B_PWM__DBM_2_4_CLOCKS)
            PWM_9_backup.PWMdeadBandValue = PWM_9_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_9_KillModeMinTime)
             PWM_9_backup.PWMKillCounterPeriod = PWM_9_ReadKillTime();
        #endif /* (PWM_9_KillModeMinTime) */

        #if(PWM_9_UseControl)
            PWM_9_backup.PWMControlRegister = PWM_9_ReadControlRegister();
        #endif /* (PWM_9_UseControl) */
    #endif  /* (!PWM_9_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_9_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_9_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_9_RestoreConfig(void) 
{
        #if(!PWM_9_UsingFixedFunction)
            #if(!PWM_9_PWMModeIsCenterAligned)
                PWM_9_WritePeriod(PWM_9_backup.PWMPeriod);
            #endif /* (!PWM_9_PWMModeIsCenterAligned) */

            PWM_9_WriteCounter(PWM_9_backup.PWMUdb);

            #if (PWM_9_UseStatus)
                PWM_9_STATUS_MASK = PWM_9_backup.InterruptMaskValue;
            #endif /* (PWM_9_UseStatus) */

            #if(PWM_9_DeadBandMode == PWM_9__B_PWM__DBM_256_CLOCKS || \
                PWM_9_DeadBandMode == PWM_9__B_PWM__DBM_2_4_CLOCKS)
                PWM_9_WriteDeadTime(PWM_9_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_9_KillModeMinTime)
                PWM_9_WriteKillTime(PWM_9_backup.PWMKillCounterPeriod);
            #endif /* (PWM_9_KillModeMinTime) */

            #if(PWM_9_UseControl)
                PWM_9_WriteControlRegister(PWM_9_backup.PWMControlRegister);
            #endif /* (PWM_9_UseControl) */
        #endif  /* (!PWM_9_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_9_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_9_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_9_Sleep(void) 
{
    #if(PWM_9_UseControl)
        if(PWM_9_CTRL_ENABLE == (PWM_9_CONTROL & PWM_9_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_9_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_9_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_9_UseControl) */

    /* Stop component */
    PWM_9_Stop();

    /* Save registers configuration */
    PWM_9_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_9_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_9_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_9_Wakeup(void) 
{
     /* Restore registers values */
    PWM_9_RestoreConfig();

    if(PWM_9_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_9_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
