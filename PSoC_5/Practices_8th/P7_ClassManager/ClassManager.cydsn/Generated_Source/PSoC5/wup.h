/*******************************************************************************
* File Name: wup.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_wup_H)
#define CY_ISR_wup_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void wup_Start(void);
void wup_StartEx(cyisraddress address);
void wup_Stop(void);

CY_ISR_PROTO(wup_Interrupt);

void wup_SetVector(cyisraddress address);
cyisraddress wup_GetVector(void);

void wup_SetPriority(uint8 priority);
uint8 wup_GetPriority(void);

void wup_Enable(void);
uint8 wup_GetState(void);
void wup_Disable(void);

void wup_SetPending(void);
void wup_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the wup ISR. */
#define wup_INTC_VECTOR            ((reg32 *) wup__INTC_VECT)

/* Address of the wup ISR priority. */
#define wup_INTC_PRIOR             ((reg8 *) wup__INTC_PRIOR_REG)

/* Priority of the wup interrupt. */
#define wup_INTC_PRIOR_NUMBER      wup__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable wup interrupt. */
#define wup_INTC_SET_EN            ((reg32 *) wup__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the wup interrupt. */
#define wup_INTC_CLR_EN            ((reg32 *) wup__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the wup interrupt state to pending. */
#define wup_INTC_SET_PD            ((reg32 *) wup__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the wup interrupt. */
#define wup_INTC_CLR_PD            ((reg32 *) wup__INTC_CLR_PD_REG)


#endif /* CY_ISR_wup_H */


/* [] END OF FILE */
