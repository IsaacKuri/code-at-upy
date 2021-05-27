/*******************************************************************************
* File Name: com.h
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
#if !defined(CY_ISR_com_H)
#define CY_ISR_com_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void com_Start(void);
void com_StartEx(cyisraddress address);
void com_Stop(void);

CY_ISR_PROTO(com_Interrupt);

void com_SetVector(cyisraddress address);
cyisraddress com_GetVector(void);

void com_SetPriority(uint8 priority);
uint8 com_GetPriority(void);

void com_Enable(void);
uint8 com_GetState(void);
void com_Disable(void);

void com_SetPending(void);
void com_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the com ISR. */
#define com_INTC_VECTOR            ((reg32 *) com__INTC_VECT)

/* Address of the com ISR priority. */
#define com_INTC_PRIOR             ((reg8 *) com__INTC_PRIOR_REG)

/* Priority of the com interrupt. */
#define com_INTC_PRIOR_NUMBER      com__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable com interrupt. */
#define com_INTC_SET_EN            ((reg32 *) com__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the com interrupt. */
#define com_INTC_CLR_EN            ((reg32 *) com__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the com interrupt state to pending. */
#define com_INTC_SET_PD            ((reg32 *) com__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the com interrupt. */
#define com_INTC_CLR_PD            ((reg32 *) com__INTC_CLR_PD_REG)


#endif /* CY_ISR_com_H */


/* [] END OF FILE */
