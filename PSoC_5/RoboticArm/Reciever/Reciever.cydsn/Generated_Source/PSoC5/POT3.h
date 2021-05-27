/*******************************************************************************
* File Name: POT3.h  
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

#if !defined(CY_PINS_POT3_H) /* Pins POT3_H */
#define CY_PINS_POT3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT3__PORT == 15 && ((POT3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    POT3_Write(uint8 value);
void    POT3_SetDriveMode(uint8 mode);
uint8   POT3_ReadDataReg(void);
uint8   POT3_Read(void);
void    POT3_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the POT3_SetDriveMode() function.
     *  @{
     */
        #define POT3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define POT3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define POT3_DM_RES_UP          PIN_DM_RES_UP
        #define POT3_DM_RES_DWN         PIN_DM_RES_DWN
        #define POT3_DM_OD_LO           PIN_DM_OD_LO
        #define POT3_DM_OD_HI           PIN_DM_OD_HI
        #define POT3_DM_STRONG          PIN_DM_STRONG
        #define POT3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define POT3_MASK               POT3__MASK
#define POT3_SHIFT              POT3__SHIFT
#define POT3_WIDTH              1u

/* Interrupt constants */
#if defined(POT3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT3_SetInterruptMode() function.
     *  @{
     */
        #define POT3_INTR_NONE      (uint16)(0x0000u)
        #define POT3_INTR_RISING    (uint16)(0x0001u)
        #define POT3_INTR_FALLING   (uint16)(0x0002u)
        #define POT3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define POT3_INTR_MASK      (0x01u) 
#endif /* (POT3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT3_PS                     (* (reg8 *) POT3__PS)
/* Data Register */
#define POT3_DR                     (* (reg8 *) POT3__DR)
/* Port Number */
#define POT3_PRT_NUM                (* (reg8 *) POT3__PRT) 
/* Connect to Analog Globals */                                                  
#define POT3_AG                     (* (reg8 *) POT3__AG)                       
/* Analog MUX bux enable */
#define POT3_AMUX                   (* (reg8 *) POT3__AMUX) 
/* Bidirectional Enable */                                                        
#define POT3_BIE                    (* (reg8 *) POT3__BIE)
/* Bit-mask for Aliased Register Access */
#define POT3_BIT_MASK               (* (reg8 *) POT3__BIT_MASK)
/* Bypass Enable */
#define POT3_BYP                    (* (reg8 *) POT3__BYP)
/* Port wide control signals */                                                   
#define POT3_CTL                    (* (reg8 *) POT3__CTL)
/* Drive Modes */
#define POT3_DM0                    (* (reg8 *) POT3__DM0) 
#define POT3_DM1                    (* (reg8 *) POT3__DM1)
#define POT3_DM2                    (* (reg8 *) POT3__DM2) 
/* Input Buffer Disable Override */
#define POT3_INP_DIS                (* (reg8 *) POT3__INP_DIS)
/* LCD Common or Segment Drive */
#define POT3_LCD_COM_SEG            (* (reg8 *) POT3__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT3_LCD_EN                 (* (reg8 *) POT3__LCD_EN)
/* Slew Rate Control */
#define POT3_SLW                    (* (reg8 *) POT3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT3_PRTDSI__CAPS_SEL       (* (reg8 *) POT3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT3_PRTDSI__OE_SEL0        (* (reg8 *) POT3__PRTDSI__OE_SEL0) 
#define POT3_PRTDSI__OE_SEL1        (* (reg8 *) POT3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT3_PRTDSI__OUT_SEL0       (* (reg8 *) POT3__PRTDSI__OUT_SEL0) 
#define POT3_PRTDSI__OUT_SEL1       (* (reg8 *) POT3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT3_PRTDSI__SYNC_OUT       (* (reg8 *) POT3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(POT3__SIO_CFG)
    #define POT3_SIO_HYST_EN        (* (reg8 *) POT3__SIO_HYST_EN)
    #define POT3_SIO_REG_HIFREQ     (* (reg8 *) POT3__SIO_REG_HIFREQ)
    #define POT3_SIO_CFG            (* (reg8 *) POT3__SIO_CFG)
    #define POT3_SIO_DIFF           (* (reg8 *) POT3__SIO_DIFF)
#endif /* (POT3__SIO_CFG) */

/* Interrupt Registers */
#if defined(POT3__INTSTAT)
    #define POT3_INTSTAT            (* (reg8 *) POT3__INTSTAT)
    #define POT3_SNAP               (* (reg8 *) POT3__SNAP)
    
	#define POT3_0_INTTYPE_REG 		(* (reg8 *) POT3__0__INTTYPE)
#endif /* (POT3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT3_H */


/* [] END OF FILE */
