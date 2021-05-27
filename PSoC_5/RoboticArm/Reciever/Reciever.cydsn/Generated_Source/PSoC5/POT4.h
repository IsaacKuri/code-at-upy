/*******************************************************************************
* File Name: POT4.h  
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

#if !defined(CY_PINS_POT4_H) /* Pins POT4_H */
#define CY_PINS_POT4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT4__PORT == 15 && ((POT4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    POT4_Write(uint8 value);
void    POT4_SetDriveMode(uint8 mode);
uint8   POT4_ReadDataReg(void);
uint8   POT4_Read(void);
void    POT4_SetInterruptMode(uint16 position, uint16 mode);
uint8   POT4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the POT4_SetDriveMode() function.
     *  @{
     */
        #define POT4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define POT4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define POT4_DM_RES_UP          PIN_DM_RES_UP
        #define POT4_DM_RES_DWN         PIN_DM_RES_DWN
        #define POT4_DM_OD_LO           PIN_DM_OD_LO
        #define POT4_DM_OD_HI           PIN_DM_OD_HI
        #define POT4_DM_STRONG          PIN_DM_STRONG
        #define POT4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define POT4_MASK               POT4__MASK
#define POT4_SHIFT              POT4__SHIFT
#define POT4_WIDTH              1u

/* Interrupt constants */
#if defined(POT4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in POT4_SetInterruptMode() function.
     *  @{
     */
        #define POT4_INTR_NONE      (uint16)(0x0000u)
        #define POT4_INTR_RISING    (uint16)(0x0001u)
        #define POT4_INTR_FALLING   (uint16)(0x0002u)
        #define POT4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define POT4_INTR_MASK      (0x01u) 
#endif /* (POT4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT4_PS                     (* (reg8 *) POT4__PS)
/* Data Register */
#define POT4_DR                     (* (reg8 *) POT4__DR)
/* Port Number */
#define POT4_PRT_NUM                (* (reg8 *) POT4__PRT) 
/* Connect to Analog Globals */                                                  
#define POT4_AG                     (* (reg8 *) POT4__AG)                       
/* Analog MUX bux enable */
#define POT4_AMUX                   (* (reg8 *) POT4__AMUX) 
/* Bidirectional Enable */                                                        
#define POT4_BIE                    (* (reg8 *) POT4__BIE)
/* Bit-mask for Aliased Register Access */
#define POT4_BIT_MASK               (* (reg8 *) POT4__BIT_MASK)
/* Bypass Enable */
#define POT4_BYP                    (* (reg8 *) POT4__BYP)
/* Port wide control signals */                                                   
#define POT4_CTL                    (* (reg8 *) POT4__CTL)
/* Drive Modes */
#define POT4_DM0                    (* (reg8 *) POT4__DM0) 
#define POT4_DM1                    (* (reg8 *) POT4__DM1)
#define POT4_DM2                    (* (reg8 *) POT4__DM2) 
/* Input Buffer Disable Override */
#define POT4_INP_DIS                (* (reg8 *) POT4__INP_DIS)
/* LCD Common or Segment Drive */
#define POT4_LCD_COM_SEG            (* (reg8 *) POT4__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT4_LCD_EN                 (* (reg8 *) POT4__LCD_EN)
/* Slew Rate Control */
#define POT4_SLW                    (* (reg8 *) POT4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT4_PRTDSI__CAPS_SEL       (* (reg8 *) POT4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT4_PRTDSI__OE_SEL0        (* (reg8 *) POT4__PRTDSI__OE_SEL0) 
#define POT4_PRTDSI__OE_SEL1        (* (reg8 *) POT4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT4_PRTDSI__OUT_SEL0       (* (reg8 *) POT4__PRTDSI__OUT_SEL0) 
#define POT4_PRTDSI__OUT_SEL1       (* (reg8 *) POT4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT4_PRTDSI__SYNC_OUT       (* (reg8 *) POT4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(POT4__SIO_CFG)
    #define POT4_SIO_HYST_EN        (* (reg8 *) POT4__SIO_HYST_EN)
    #define POT4_SIO_REG_HIFREQ     (* (reg8 *) POT4__SIO_REG_HIFREQ)
    #define POT4_SIO_CFG            (* (reg8 *) POT4__SIO_CFG)
    #define POT4_SIO_DIFF           (* (reg8 *) POT4__SIO_DIFF)
#endif /* (POT4__SIO_CFG) */

/* Interrupt Registers */
#if defined(POT4__INTSTAT)
    #define POT4_INTSTAT            (* (reg8 *) POT4__INTSTAT)
    #define POT4_SNAP               (* (reg8 *) POT4__SNAP)
    
	#define POT4_0_INTTYPE_REG 		(* (reg8 *) POT4__0__INTTYPE)
#endif /* (POT4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT4_H */


/* [] END OF FILE */
