/*******************************************************************************
* File Name: ReadyS.h  
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

#if !defined(CY_PINS_ReadyS_H) /* Pins ReadyS_H */
#define CY_PINS_ReadyS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ReadyS_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ReadyS__PORT == 15 && ((ReadyS__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ReadyS_Write(uint8 value);
void    ReadyS_SetDriveMode(uint8 mode);
uint8   ReadyS_ReadDataReg(void);
uint8   ReadyS_Read(void);
void    ReadyS_SetInterruptMode(uint16 position, uint16 mode);
uint8   ReadyS_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ReadyS_SetDriveMode() function.
     *  @{
     */
        #define ReadyS_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ReadyS_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ReadyS_DM_RES_UP          PIN_DM_RES_UP
        #define ReadyS_DM_RES_DWN         PIN_DM_RES_DWN
        #define ReadyS_DM_OD_LO           PIN_DM_OD_LO
        #define ReadyS_DM_OD_HI           PIN_DM_OD_HI
        #define ReadyS_DM_STRONG          PIN_DM_STRONG
        #define ReadyS_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ReadyS_MASK               ReadyS__MASK
#define ReadyS_SHIFT              ReadyS__SHIFT
#define ReadyS_WIDTH              1u

/* Interrupt constants */
#if defined(ReadyS__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ReadyS_SetInterruptMode() function.
     *  @{
     */
        #define ReadyS_INTR_NONE      (uint16)(0x0000u)
        #define ReadyS_INTR_RISING    (uint16)(0x0001u)
        #define ReadyS_INTR_FALLING   (uint16)(0x0002u)
        #define ReadyS_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ReadyS_INTR_MASK      (0x01u) 
#endif /* (ReadyS__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ReadyS_PS                     (* (reg8 *) ReadyS__PS)
/* Data Register */
#define ReadyS_DR                     (* (reg8 *) ReadyS__DR)
/* Port Number */
#define ReadyS_PRT_NUM                (* (reg8 *) ReadyS__PRT) 
/* Connect to Analog Globals */                                                  
#define ReadyS_AG                     (* (reg8 *) ReadyS__AG)                       
/* Analog MUX bux enable */
#define ReadyS_AMUX                   (* (reg8 *) ReadyS__AMUX) 
/* Bidirectional Enable */                                                        
#define ReadyS_BIE                    (* (reg8 *) ReadyS__BIE)
/* Bit-mask for Aliased Register Access */
#define ReadyS_BIT_MASK               (* (reg8 *) ReadyS__BIT_MASK)
/* Bypass Enable */
#define ReadyS_BYP                    (* (reg8 *) ReadyS__BYP)
/* Port wide control signals */                                                   
#define ReadyS_CTL                    (* (reg8 *) ReadyS__CTL)
/* Drive Modes */
#define ReadyS_DM0                    (* (reg8 *) ReadyS__DM0) 
#define ReadyS_DM1                    (* (reg8 *) ReadyS__DM1)
#define ReadyS_DM2                    (* (reg8 *) ReadyS__DM2) 
/* Input Buffer Disable Override */
#define ReadyS_INP_DIS                (* (reg8 *) ReadyS__INP_DIS)
/* LCD Common or Segment Drive */
#define ReadyS_LCD_COM_SEG            (* (reg8 *) ReadyS__LCD_COM_SEG)
/* Enable Segment LCD */
#define ReadyS_LCD_EN                 (* (reg8 *) ReadyS__LCD_EN)
/* Slew Rate Control */
#define ReadyS_SLW                    (* (reg8 *) ReadyS__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ReadyS_PRTDSI__CAPS_SEL       (* (reg8 *) ReadyS__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ReadyS_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ReadyS__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ReadyS_PRTDSI__OE_SEL0        (* (reg8 *) ReadyS__PRTDSI__OE_SEL0) 
#define ReadyS_PRTDSI__OE_SEL1        (* (reg8 *) ReadyS__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ReadyS_PRTDSI__OUT_SEL0       (* (reg8 *) ReadyS__PRTDSI__OUT_SEL0) 
#define ReadyS_PRTDSI__OUT_SEL1       (* (reg8 *) ReadyS__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ReadyS_PRTDSI__SYNC_OUT       (* (reg8 *) ReadyS__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ReadyS__SIO_CFG)
    #define ReadyS_SIO_HYST_EN        (* (reg8 *) ReadyS__SIO_HYST_EN)
    #define ReadyS_SIO_REG_HIFREQ     (* (reg8 *) ReadyS__SIO_REG_HIFREQ)
    #define ReadyS_SIO_CFG            (* (reg8 *) ReadyS__SIO_CFG)
    #define ReadyS_SIO_DIFF           (* (reg8 *) ReadyS__SIO_DIFF)
#endif /* (ReadyS__SIO_CFG) */

/* Interrupt Registers */
#if defined(ReadyS__INTSTAT)
    #define ReadyS_INTSTAT            (* (reg8 *) ReadyS__INTSTAT)
    #define ReadyS_SNAP               (* (reg8 *) ReadyS__SNAP)
    
	#define ReadyS_0_INTTYPE_REG 		(* (reg8 *) ReadyS__0__INTTYPE)
#endif /* (ReadyS__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ReadyS_H */


/* [] END OF FILE */
