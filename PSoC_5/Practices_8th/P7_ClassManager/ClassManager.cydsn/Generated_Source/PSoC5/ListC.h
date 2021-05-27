/*******************************************************************************
* File Name: ListC.h  
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

#if !defined(CY_PINS_ListC_H) /* Pins ListC_H */
#define CY_PINS_ListC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ListC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ListC__PORT == 15 && ((ListC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ListC_Write(uint8 value);
void    ListC_SetDriveMode(uint8 mode);
uint8   ListC_ReadDataReg(void);
uint8   ListC_Read(void);
void    ListC_SetInterruptMode(uint16 position, uint16 mode);
uint8   ListC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ListC_SetDriveMode() function.
     *  @{
     */
        #define ListC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ListC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ListC_DM_RES_UP          PIN_DM_RES_UP
        #define ListC_DM_RES_DWN         PIN_DM_RES_DWN
        #define ListC_DM_OD_LO           PIN_DM_OD_LO
        #define ListC_DM_OD_HI           PIN_DM_OD_HI
        #define ListC_DM_STRONG          PIN_DM_STRONG
        #define ListC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ListC_MASK               ListC__MASK
#define ListC_SHIFT              ListC__SHIFT
#define ListC_WIDTH              1u

/* Interrupt constants */
#if defined(ListC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ListC_SetInterruptMode() function.
     *  @{
     */
        #define ListC_INTR_NONE      (uint16)(0x0000u)
        #define ListC_INTR_RISING    (uint16)(0x0001u)
        #define ListC_INTR_FALLING   (uint16)(0x0002u)
        #define ListC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ListC_INTR_MASK      (0x01u) 
#endif /* (ListC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ListC_PS                     (* (reg8 *) ListC__PS)
/* Data Register */
#define ListC_DR                     (* (reg8 *) ListC__DR)
/* Port Number */
#define ListC_PRT_NUM                (* (reg8 *) ListC__PRT) 
/* Connect to Analog Globals */                                                  
#define ListC_AG                     (* (reg8 *) ListC__AG)                       
/* Analog MUX bux enable */
#define ListC_AMUX                   (* (reg8 *) ListC__AMUX) 
/* Bidirectional Enable */                                                        
#define ListC_BIE                    (* (reg8 *) ListC__BIE)
/* Bit-mask for Aliased Register Access */
#define ListC_BIT_MASK               (* (reg8 *) ListC__BIT_MASK)
/* Bypass Enable */
#define ListC_BYP                    (* (reg8 *) ListC__BYP)
/* Port wide control signals */                                                   
#define ListC_CTL                    (* (reg8 *) ListC__CTL)
/* Drive Modes */
#define ListC_DM0                    (* (reg8 *) ListC__DM0) 
#define ListC_DM1                    (* (reg8 *) ListC__DM1)
#define ListC_DM2                    (* (reg8 *) ListC__DM2) 
/* Input Buffer Disable Override */
#define ListC_INP_DIS                (* (reg8 *) ListC__INP_DIS)
/* LCD Common or Segment Drive */
#define ListC_LCD_COM_SEG            (* (reg8 *) ListC__LCD_COM_SEG)
/* Enable Segment LCD */
#define ListC_LCD_EN                 (* (reg8 *) ListC__LCD_EN)
/* Slew Rate Control */
#define ListC_SLW                    (* (reg8 *) ListC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ListC_PRTDSI__CAPS_SEL       (* (reg8 *) ListC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ListC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ListC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ListC_PRTDSI__OE_SEL0        (* (reg8 *) ListC__PRTDSI__OE_SEL0) 
#define ListC_PRTDSI__OE_SEL1        (* (reg8 *) ListC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ListC_PRTDSI__OUT_SEL0       (* (reg8 *) ListC__PRTDSI__OUT_SEL0) 
#define ListC_PRTDSI__OUT_SEL1       (* (reg8 *) ListC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ListC_PRTDSI__SYNC_OUT       (* (reg8 *) ListC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ListC__SIO_CFG)
    #define ListC_SIO_HYST_EN        (* (reg8 *) ListC__SIO_HYST_EN)
    #define ListC_SIO_REG_HIFREQ     (* (reg8 *) ListC__SIO_REG_HIFREQ)
    #define ListC_SIO_CFG            (* (reg8 *) ListC__SIO_CFG)
    #define ListC_SIO_DIFF           (* (reg8 *) ListC__SIO_DIFF)
#endif /* (ListC__SIO_CFG) */

/* Interrupt Registers */
#if defined(ListC__INTSTAT)
    #define ListC_INTSTAT            (* (reg8 *) ListC__INTSTAT)
    #define ListC_SNAP               (* (reg8 *) ListC__SNAP)
    
	#define ListC_0_INTTYPE_REG 		(* (reg8 *) ListC__0__INTTYPE)
#endif /* (ListC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ListC_H */


/* [] END OF FILE */
