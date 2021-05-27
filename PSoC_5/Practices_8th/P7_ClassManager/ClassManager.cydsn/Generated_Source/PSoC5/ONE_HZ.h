/*******************************************************************************
* File Name: ONE_HZ.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ONE_HZ_H)
#define CY_CLOCK_ONE_HZ_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void ONE_HZ_Start(void) ;
void ONE_HZ_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ONE_HZ_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ONE_HZ_StandbyPower(uint8 state) ;
void ONE_HZ_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ONE_HZ_GetDividerRegister(void) ;
void ONE_HZ_SetModeRegister(uint8 modeBitMask) ;
void ONE_HZ_ClearModeRegister(uint8 modeBitMask) ;
uint8 ONE_HZ_GetModeRegister(void) ;
void ONE_HZ_SetSourceRegister(uint8 clkSource) ;
uint8 ONE_HZ_GetSourceRegister(void) ;
#if defined(ONE_HZ__CFG3)
void ONE_HZ_SetPhaseRegister(uint8 clkPhase) ;
uint8 ONE_HZ_GetPhaseRegister(void) ;
#endif /* defined(ONE_HZ__CFG3) */

#define ONE_HZ_Enable()                       ONE_HZ_Start()
#define ONE_HZ_Disable()                      ONE_HZ_Stop()
#define ONE_HZ_SetDivider(clkDivider)         ONE_HZ_SetDividerRegister(clkDivider, 1u)
#define ONE_HZ_SetDividerValue(clkDivider)    ONE_HZ_SetDividerRegister((clkDivider) - 1u, 1u)
#define ONE_HZ_SetMode(clkMode)               ONE_HZ_SetModeRegister(clkMode)
#define ONE_HZ_SetSource(clkSource)           ONE_HZ_SetSourceRegister(clkSource)
#if defined(ONE_HZ__CFG3)
#define ONE_HZ_SetPhase(clkPhase)             ONE_HZ_SetPhaseRegister(clkPhase)
#define ONE_HZ_SetPhaseValue(clkPhase)        ONE_HZ_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ONE_HZ__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ONE_HZ_CLKEN              (* (reg8 *) ONE_HZ__PM_ACT_CFG)
#define ONE_HZ_CLKEN_PTR          ((reg8 *) ONE_HZ__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ONE_HZ_CLKSTBY            (* (reg8 *) ONE_HZ__PM_STBY_CFG)
#define ONE_HZ_CLKSTBY_PTR        ((reg8 *) ONE_HZ__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ONE_HZ_DIV_LSB            (* (reg8 *) ONE_HZ__CFG0)
#define ONE_HZ_DIV_LSB_PTR        ((reg8 *) ONE_HZ__CFG0)
#define ONE_HZ_DIV_PTR            ((reg16 *) ONE_HZ__CFG0)

/* Clock MSB divider configuration register. */
#define ONE_HZ_DIV_MSB            (* (reg8 *) ONE_HZ__CFG1)
#define ONE_HZ_DIV_MSB_PTR        ((reg8 *) ONE_HZ__CFG1)

/* Mode and source configuration register */
#define ONE_HZ_MOD_SRC            (* (reg8 *) ONE_HZ__CFG2)
#define ONE_HZ_MOD_SRC_PTR        ((reg8 *) ONE_HZ__CFG2)

#if defined(ONE_HZ__CFG3)
/* Analog clock phase configuration register */
#define ONE_HZ_PHASE              (* (reg8 *) ONE_HZ__CFG3)
#define ONE_HZ_PHASE_PTR          ((reg8 *) ONE_HZ__CFG3)
#endif /* defined(ONE_HZ__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ONE_HZ_CLKEN_MASK         ONE_HZ__PM_ACT_MSK
#define ONE_HZ_CLKSTBY_MASK       ONE_HZ__PM_STBY_MSK

/* CFG2 field masks */
#define ONE_HZ_SRC_SEL_MSK        ONE_HZ__CFG2_SRC_SEL_MASK
#define ONE_HZ_MODE_MASK          (~(ONE_HZ_SRC_SEL_MSK))

#if defined(ONE_HZ__CFG3)
/* CFG3 phase mask */
#define ONE_HZ_PHASE_MASK         ONE_HZ__CFG3_PHASE_DLY_MASK
#endif /* defined(ONE_HZ__CFG3) */

#endif /* CY_CLOCK_ONE_HZ_H */


/* [] END OF FILE */
