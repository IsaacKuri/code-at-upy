/*******************************************************************************
* File Name: POT5.h  
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

#if !defined(CY_PINS_POT5_H) /* Pins POT5_H */
#define CY_PINS_POT5_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT5_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT5__PORT == 15 && ((POT5__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    POT5_Write(uint8 value);
void    POT5_SetDriveMode(uint8 mode);
uint8   POT5_ReadDataReg(void);
uint8   POT5_Read(void);
void    POT5_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT5_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the POT5_SetDriveMode() function.
     *  @{
     */
        #define POT5_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define POT5_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define POT5_DM_RES_UP          PIN_DM_RES_UP
        #define POT5_DM_RES_DWN         PIN_DM_RES_DWN
        #define POT5_DM_OD_LO           PIN_DM_OD_LO
        #define POT5_DM_OD_HI           PIN_DM_OD_HI
        #define POT5_DM_STRONG          PIN_DM_STRONG
        #define POT5_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define POT5_MASK               POT5__MASK
#define POT5_SHIFT              POT5__SHIFT
#define POT5_WIDTH              1u

/* Interrupt constants */
#if defined(POT5__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT5_SetInterruptMode() function.
     *  @{
     */
        #define POT5_INTR_NONE      (uint16)(0x0000u)
        #define POT5_INTR_RISING    (uint16)(0x0001u)
        #define POT5_INTR_FALLING   (uint16)(0x0002u)
        #define POT5_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define POT5_INTR_MASK      (0x01u) 
#endif /* (POT5__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT5_PS                     (* (reg8 *) POT5__PS)
/* Data Register */
#define POT5_DR                     (* (reg8 *) POT5__DR)
/* Port Number */
#define POT5_PRT_NUM                (* (reg8 *) POT5__PRT) 
/* Connect to Analog Globals */                                                  
#define POT5_AG                     (* (reg8 *) POT5__AG)                       
/* Analog MUX bux enable */
#define POT5_AMUX                   (* (reg8 *) POT5__AMUX) 
/* Bidirectional Enable */                                                        
#define POT5_BIE                    (* (reg8 *) POT5__BIE)
/* Bit-mask for Aliased Register Access */
#define POT5_BIT_MASK               (* (reg8 *) POT5__BIT_MASK)
/* Bypass Enable */
#define POT5_BYP                    (* (reg8 *) POT5__BYP)
/* Port wide control signals */                                                   
#define POT5_CTL                    (* (reg8 *) POT5__CTL)
/* Drive Modes */
#define POT5_DM0                    (* (reg8 *) POT5__DM0) 
#define POT5_DM1                    (* (reg8 *) POT5__DM1)
#define POT5_DM2                    (* (reg8 *) POT5__DM2) 
/* Input Buffer Disable Override */
#define POT5_INP_DIS                (* (reg8 *) POT5__INP_DIS)
/* LCD Common or Segment Drive */
#define POT5_LCD_COM_SEG            (* (reg8 *) POT5__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT5_LCD_EN                 (* (reg8 *) POT5__LCD_EN)
/* Slew Rate Control */
#define POT5_SLW                    (* (reg8 *) POT5__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT5_PRTDSI__CAPS_SEL       (* (reg8 *) POT5__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT5_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT5__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT5_PRTDSI__OE_SEL0        (* (reg8 *) POT5__PRTDSI__OE_SEL0) 
#define POT5_PRTDSI__OE_SEL1        (* (reg8 *) POT5__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT5_PRTDSI__OUT_SEL0       (* (reg8 *) POT5__PRTDSI__OUT_SEL0) 
#define POT5_PRTDSI__OUT_SEL1       (* (reg8 *) POT5__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT5_PRTDSI__SYNC_OUT       (* (reg8 *) POT5__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(POT5__SIO_CFG)
    #define POT5_SIO_HYST_EN        (* (reg8 *) POT5__SIO_HYST_EN)
    #define POT5_SIO_REG_HIFREQ     (* (reg8 *) POT5__SIO_REG_HIFREQ)
    #define POT5_SIO_CFG            (* (reg8 *) POT5__SIO_CFG)
    #define POT5_SIO_DIFF           (* (reg8 *) POT5__SIO_DIFF)
#endif /* (POT5__SIO_CFG) */

/* Interrupt Registers */
#if defined(POT5__INTSTAT)
    #define POT5_INTSTAT            (* (reg8 *) POT5__INTSTAT)
    #define POT5_SNAP               (* (reg8 *) POT5__SNAP)
    
	#define POT5_0_INTTYPE_REG 		(* (reg8 *) POT5__0__INTTYPE)
#endif /* (POT5__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT5_H */


/* [] END OF FILE */
