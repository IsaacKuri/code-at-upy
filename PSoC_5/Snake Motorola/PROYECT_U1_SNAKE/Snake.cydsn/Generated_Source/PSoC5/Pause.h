/*******************************************************************************
* File Name: Pause.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pause_H) /* Pins Pause_H */
#define CY_PINS_Pause_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pause_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pause__PORT == 15 && ((Pause__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pause_Write(uint8 value);
void    Pause_SetDriveMode(uint8 mode);
uint8   Pause_ReadDataReg(void);
uint8   Pause_Read(void);
void    Pause_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pause_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pause_SetDriveMode() function.
     *  @{
     */
        #define Pause_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pause_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pause_DM_RES_UP          PIN_DM_RES_UP
        #define Pause_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pause_DM_OD_LO           PIN_DM_OD_LO
        #define Pause_DM_OD_HI           PIN_DM_OD_HI
        #define Pause_DM_STRONG          PIN_DM_STRONG
        #define Pause_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pause_MASK               Pause__MASK
#define Pause_SHIFT              Pause__SHIFT
#define Pause_WIDTH              1u

/* Interrupt constants */
#if defined(Pause__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pause_SetInterruptMode() function.
     *  @{
     */
        #define Pause_INTR_NONE      (uint16)(0x0000u)
        #define Pause_INTR_RISING    (uint16)(0x0001u)
        #define Pause_INTR_FALLING   (uint16)(0x0002u)
        #define Pause_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pause_INTR_MASK      (0x01u) 
#endif /* (Pause__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pause_PS                     (* (reg8 *) Pause__PS)
/* Data Register */
#define Pause_DR                     (* (reg8 *) Pause__DR)
/* Port Number */
#define Pause_PRT_NUM                (* (reg8 *) Pause__PRT) 
/* Connect to Analog Globals */                                                  
#define Pause_AG                     (* (reg8 *) Pause__AG)                       
/* Analog MUX bux enable */
#define Pause_AMUX                   (* (reg8 *) Pause__AMUX) 
/* Bidirectional Enable */                                                        
#define Pause_BIE                    (* (reg8 *) Pause__BIE)
/* Bit-mask for Aliased Register Access */
#define Pause_BIT_MASK               (* (reg8 *) Pause__BIT_MASK)
/* Bypass Enable */
#define Pause_BYP                    (* (reg8 *) Pause__BYP)
/* Port wide control signals */                                                   
#define Pause_CTL                    (* (reg8 *) Pause__CTL)
/* Drive Modes */
#define Pause_DM0                    (* (reg8 *) Pause__DM0) 
#define Pause_DM1                    (* (reg8 *) Pause__DM1)
#define Pause_DM2                    (* (reg8 *) Pause__DM2) 
/* Input Buffer Disable Override */
#define Pause_INP_DIS                (* (reg8 *) Pause__INP_DIS)
/* LCD Common or Segment Drive */
#define Pause_LCD_COM_SEG            (* (reg8 *) Pause__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pause_LCD_EN                 (* (reg8 *) Pause__LCD_EN)
/* Slew Rate Control */
#define Pause_SLW                    (* (reg8 *) Pause__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pause_PRTDSI__CAPS_SEL       (* (reg8 *) Pause__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pause_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pause__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pause_PRTDSI__OE_SEL0        (* (reg8 *) Pause__PRTDSI__OE_SEL0) 
#define Pause_PRTDSI__OE_SEL1        (* (reg8 *) Pause__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pause_PRTDSI__OUT_SEL0       (* (reg8 *) Pause__PRTDSI__OUT_SEL0) 
#define Pause_PRTDSI__OUT_SEL1       (* (reg8 *) Pause__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pause_PRTDSI__SYNC_OUT       (* (reg8 *) Pause__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pause__SIO_CFG)
    #define Pause_SIO_HYST_EN        (* (reg8 *) Pause__SIO_HYST_EN)
    #define Pause_SIO_REG_HIFREQ     (* (reg8 *) Pause__SIO_REG_HIFREQ)
    #define Pause_SIO_CFG            (* (reg8 *) Pause__SIO_CFG)
    #define Pause_SIO_DIFF           (* (reg8 *) Pause__SIO_DIFF)
#endif /* (Pause__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pause__INTSTAT)
    #define Pause_INTSTAT            (* (reg8 *) Pause__INTSTAT)
    #define Pause_SNAP               (* (reg8 *) Pause__SNAP)
    
	#define Pause_0_INTTYPE_REG 		(* (reg8 *) Pause__0__INTTYPE)
#endif /* (Pause__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pause_H */


/* [] END OF FILE */
