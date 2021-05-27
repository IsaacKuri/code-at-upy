/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* LED */
#define LED__0__INTTYPE CYREG_PICU0_INTTYPE0
#define LED__0__MASK 0x01u
#define LED__0__PC CYREG_PRT0_PC0
#define LED__0__PORT 0u
#define LED__0__SHIFT 0u
#define LED__AG CYREG_PRT0_AG
#define LED__AMUX CYREG_PRT0_AMUX
#define LED__BIE CYREG_PRT0_BIE
#define LED__BIT_MASK CYREG_PRT0_BIT_MASK
#define LED__BYP CYREG_PRT0_BYP
#define LED__CTL CYREG_PRT0_CTL
#define LED__DM0 CYREG_PRT0_DM0
#define LED__DM1 CYREG_PRT0_DM1
#define LED__DM2 CYREG_PRT0_DM2
#define LED__DR CYREG_PRT0_DR
#define LED__INP_DIS CYREG_PRT0_INP_DIS
#define LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define LED__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define LED__LCD_EN CYREG_PRT0_LCD_EN
#define LED__MASK 0x01u
#define LED__PORT 0u
#define LED__PRT CYREG_PRT0_PRT
#define LED__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define LED__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define LED__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define LED__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define LED__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define LED__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define LED__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define LED__PS CYREG_PRT0_PS
#define LED__SHIFT 0u
#define LED__SLW CYREG_PRT0_SLW

/* CapSense_BufCH0 */
#define CapSense_BufCH0__CFG0 CYREG_CAPSL_CFG0
#define CapSense_BufCH0__CFG1 CYREG_CAPSL_CFG1
#define CapSense_BufCH0__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define CapSense_BufCH0__PM_ACT_MSK 0x10u
#define CapSense_BufCH0__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define CapSense_BufCH0__PM_STBY_MSK 0x10u

/* CapSense_ClockGen */
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_A0_REG CYREG_B0_UDB10_11_A0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_A1_REG CYREG_B0_UDB10_11_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_D0_REG CYREG_B0_UDB10_11_D0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_D1_REG CYREG_B0_UDB10_11_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB10_11_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_F0_REG CYREG_B0_UDB10_11_F0
#define CapSense_ClockGen_sC16_PRSdp_u0__16BIT_F1_REG CYREG_B0_UDB10_11_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__A0_A1_REG CYREG_B0_UDB10_A0_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__A0_REG CYREG_B0_UDB10_A0
#define CapSense_ClockGen_sC16_PRSdp_u0__A1_REG CYREG_B0_UDB10_A1
#define CapSense_ClockGen_sC16_PRSdp_u0__D0_D1_REG CYREG_B0_UDB10_D0_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__D0_REG CYREG_B0_UDB10_D0
#define CapSense_ClockGen_sC16_PRSdp_u0__D1_REG CYREG_B0_UDB10_D1
#define CapSense_ClockGen_sC16_PRSdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB10_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__F0_F1_REG CYREG_B0_UDB10_F0_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__F0_REG CYREG_B0_UDB10_F0
#define CapSense_ClockGen_sC16_PRSdp_u0__F1_REG CYREG_B0_UDB10_F1
#define CapSense_ClockGen_sC16_PRSdp_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_A0_REG CYREG_B0_UDB11_12_A0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_A1_REG CYREG_B0_UDB11_12_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_D0_REG CYREG_B0_UDB11_12_D0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_D1_REG CYREG_B0_UDB11_12_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_F0_REG CYREG_B0_UDB11_12_F0
#define CapSense_ClockGen_sC16_PRSdp_u1__16BIT_F1_REG CYREG_B0_UDB11_12_F1
#define CapSense_ClockGen_sC16_PRSdp_u1__A0_A1_REG CYREG_B0_UDB11_A0_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__A0_REG CYREG_B0_UDB11_A0
#define CapSense_ClockGen_sC16_PRSdp_u1__A1_REG CYREG_B0_UDB11_A1
#define CapSense_ClockGen_sC16_PRSdp_u1__D0_D1_REG CYREG_B0_UDB11_D0_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__D0_REG CYREG_B0_UDB11_D0
#define CapSense_ClockGen_sC16_PRSdp_u1__D1_REG CYREG_B0_UDB11_D1
#define CapSense_ClockGen_sC16_PRSdp_u1__DP_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define CapSense_ClockGen_sC16_PRSdp_u1__F0_F1_REG CYREG_B0_UDB11_F0_F1
#define CapSense_ClockGen_sC16_PRSdp_u1__F0_REG CYREG_B0_UDB11_F0
#define CapSense_ClockGen_sC16_PRSdp_u1__F1_REG CYREG_B0_UDB11_F1
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB10_11_ACTL
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB10_11_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB10_11_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB10_11_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_COUNT_COUNT_REG CYREG_B0_UDB10_11_CTL
#define CapSense_ClockGen_ScanSpeed__16BIT_MASK_MASK_REG CYREG_B0_UDB10_11_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_MASK_PERIOD_REG CYREG_B0_UDB10_11_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_PERIOD_MASK_REG CYREG_B0_UDB10_11_MSK
#define CapSense_ClockGen_ScanSpeed__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB10_11_MSK
#define CapSense_ClockGen_ScanSpeed__CONTROL_AUX_CTL_REG CYREG_B0_UDB10_ACTL
#define CapSense_ClockGen_ScanSpeed__CONTROL_REG CYREG_B0_UDB10_CTL
#define CapSense_ClockGen_ScanSpeed__CONTROL_ST_REG CYREG_B0_UDB10_ST_CTL
#define CapSense_ClockGen_ScanSpeed__COUNT_REG CYREG_B0_UDB10_CTL
#define CapSense_ClockGen_ScanSpeed__COUNT_ST_REG CYREG_B0_UDB10_ST_CTL
#define CapSense_ClockGen_ScanSpeed__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define CapSense_ClockGen_ScanSpeed__PER_CTL_AUX_CTL_REG CYREG_B0_UDB10_MSK_ACTL
#define CapSense_ClockGen_ScanSpeed__PERIOD_REG CYREG_B0_UDB10_MSK
#define CapSense_ClockGen_SyncCtrl_CtrlReg__0__MASK 0x01u
#define CapSense_ClockGen_SyncCtrl_CtrlReg__0__POS 0
#define CapSense_ClockGen_SyncCtrl_CtrlReg__1__MASK 0x02u
#define CapSense_ClockGen_SyncCtrl_CtrlReg__1__POS 1
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_SyncCtrl_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define CapSense_ClockGen_SyncCtrl_CtrlReg__2__MASK 0x04u
#define CapSense_ClockGen_SyncCtrl_CtrlReg__2__POS 2
#define CapSense_ClockGen_SyncCtrl_CtrlReg__4__MASK 0x10u
#define CapSense_ClockGen_SyncCtrl_CtrlReg__4__POS 4
#define CapSense_ClockGen_SyncCtrl_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__CONTROL_REG CYREG_B0_UDB09_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__COUNT_REG CYREG_B0_UDB09_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__MASK 0x17u
#define CapSense_ClockGen_SyncCtrl_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define CapSense_ClockGen_SyncCtrl_CtrlReg__PERIOD_REG CYREG_B0_UDB09_MSK
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_A0_REG CYREG_B0_UDB08_09_A0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_A1_REG CYREG_B0_UDB08_09_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_D0_REG CYREG_B0_UDB08_09_D0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_D1_REG CYREG_B0_UDB08_09_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB08_09_ACTL
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_F0_REG CYREG_B0_UDB08_09_F0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__16BIT_F1_REG CYREG_B0_UDB08_09_F1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A0_A1_REG CYREG_B0_UDB08_A0_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A0_REG CYREG_B0_UDB08_A0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__A1_REG CYREG_B0_UDB08_A1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D0_D1_REG CYREG_B0_UDB08_D0_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D0_REG CYREG_B0_UDB08_D0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__D1_REG CYREG_B0_UDB08_D1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__DP_AUX_CTL_REG CYREG_B0_UDB08_ACTL
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F0_F1_REG CYREG_B0_UDB08_F0_F1
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F0_REG CYREG_B0_UDB08_F0
#define CapSense_ClockGen_UDB_PrescalerDp_u0__F1_REG CYREG_B0_UDB08_F1

/* Miscellaneous */
#define CapSense_CmodCH0__0__INTTYPE CYREG_PICU15_INTTYPE4
#define CapSense_CmodCH0__0__MASK 0x10u
#define CapSense_CmodCH0__0__PC CYREG_IO_PC_PRT15_PC4
#define CapSense_CmodCH0__0__PORT 15u
#define CapSense_CmodCH0__0__SHIFT 4u
#define CapSense_CmodCH0__AG CYREG_PRT15_AG
#define CapSense_CmodCH0__AMUX CYREG_PRT15_AMUX
#define CapSense_CmodCH0__BIE CYREG_PRT15_BIE
#define CapSense_CmodCH0__BIT_MASK CYREG_PRT15_BIT_MASK
#define CapSense_CmodCH0__BYP CYREG_PRT15_BYP
#define CapSense_CmodCH0__Cmod_CH0__INTTYPE CYREG_PICU15_INTTYPE4
#define CapSense_CmodCH0__Cmod_CH0__MASK 0x10u
#define CapSense_CmodCH0__Cmod_CH0__PC CYREG_IO_PC_PRT15_PC4
#define CapSense_CmodCH0__Cmod_CH0__PORT 15u
#define CapSense_CmodCH0__Cmod_CH0__SHIFT 4u
#define CapSense_CmodCH0__CTL CYREG_PRT15_CTL
#define CapSense_CmodCH0__DM0 CYREG_PRT15_DM0
#define CapSense_CmodCH0__DM1 CYREG_PRT15_DM1
#define CapSense_CmodCH0__DM2 CYREG_PRT15_DM2
#define CapSense_CmodCH0__DR CYREG_PRT15_DR
#define CapSense_CmodCH0__INP_DIS CYREG_PRT15_INP_DIS
#define CapSense_CmodCH0__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU15_BASE
#define CapSense_CmodCH0__LCD_COM_SEG CYREG_PRT15_LCD_COM_SEG
#define CapSense_CmodCH0__LCD_EN CYREG_PRT15_LCD_EN
#define CapSense_CmodCH0__MASK 0x10u
#define CapSense_CmodCH0__PORT 15u
#define CapSense_CmodCH0__PRT CYREG_PRT15_PRT
#define CapSense_CmodCH0__PRTDSI__CAPS_SEL CYREG_PRT15_CAPS_SEL
#define CapSense_CmodCH0__PRTDSI__DBL_SYNC_IN CYREG_PRT15_DBL_SYNC_IN
#define CapSense_CmodCH0__PRTDSI__OE_SEL0 CYREG_PRT15_OE_SEL0
#define CapSense_CmodCH0__PRTDSI__OE_SEL1 CYREG_PRT15_OE_SEL1
#define CapSense_CmodCH0__PRTDSI__OUT_SEL0 CYREG_PRT15_OUT_SEL0
#define CapSense_CmodCH0__PRTDSI__OUT_SEL1 CYREG_PRT15_OUT_SEL1
#define CapSense_CmodCH0__PRTDSI__SYNC_OUT CYREG_PRT15_SYNC_OUT
#define CapSense_CmodCH0__PS CYREG_PRT15_PS
#define CapSense_CmodCH0__SHIFT 4u
#define CapSense_CmodCH0__SLW CYREG_PRT15_SLW
#define CapSense_CompCH0_ctComp__CLK CYREG_CMP3_CLK
#define CapSense_CompCH0_ctComp__CMP_MASK 0x08u
#define CapSense_CompCH0_ctComp__CMP_NUMBER 3u
#define CapSense_CompCH0_ctComp__CR CYREG_CMP3_CR
#define CapSense_CompCH0_ctComp__LUT__CR CYREG_LUT3_CR
#define CapSense_CompCH0_ctComp__LUT__MSK CYREG_LUT_MSK
#define CapSense_CompCH0_ctComp__LUT__MSK_MASK 0x08u
#define CapSense_CompCH0_ctComp__LUT__MSK_SHIFT 3u
#define CapSense_CompCH0_ctComp__LUT__MX CYREG_LUT3_MX
#define CapSense_CompCH0_ctComp__LUT__SR CYREG_LUT_SR
#define CapSense_CompCH0_ctComp__LUT__SR_MASK 0x08u
#define CapSense_CompCH0_ctComp__LUT__SR_SHIFT 3u
#define CapSense_CompCH0_ctComp__PM_ACT_CFG CYREG_PM_ACT_CFG7
#define CapSense_CompCH0_ctComp__PM_ACT_MSK 0x08u
#define CapSense_CompCH0_ctComp__PM_STBY_CFG CYREG_PM_STBY_CFG7
#define CapSense_CompCH0_ctComp__PM_STBY_MSK 0x08u
#define CapSense_CompCH0_ctComp__SW0 CYREG_CMP3_SW0
#define CapSense_CompCH0_ctComp__SW2 CYREG_CMP3_SW2
#define CapSense_CompCH0_ctComp__SW3 CYREG_CMP3_SW3
#define CapSense_CompCH0_ctComp__SW4 CYREG_CMP3_SW4
#define CapSense_CompCH0_ctComp__SW6 CYREG_CMP3_SW6
#define CapSense_CompCH0_ctComp__TR0 CYREG_CMP3_TR0
#define CapSense_CompCH0_ctComp__TR1 CYREG_CMP3_TR1
#define CapSense_CompCH0_ctComp__TRIM__TR0 CYREG_FLSHID_MFG_CFG_CMP3_TR0
#define CapSense_CompCH0_ctComp__TRIM__TR0_HS CYREG_FLSHID_CUST_TABLES_CMP3_TR0_HS
#define CapSense_CompCH0_ctComp__TRIM__TR1 CYREG_FLSHID_MFG_CFG_CMP3_TR1
#define CapSense_CompCH0_ctComp__TRIM__TR1_HS CYREG_FLSHID_CUST_TABLES_CMP3_TR1_HS
#define CapSense_CompCH0_ctComp__WRK CYREG_CMP_WRK
#define CapSense_CompCH0_ctComp__WRK_MASK 0x08u
#define CapSense_CompCH0_ctComp__WRK_SHIFT 3u
#define CapSense_IdacCH0_viDAC8__CR0 CYREG_DAC1_CR0
#define CapSense_IdacCH0_viDAC8__CR1 CYREG_DAC1_CR1
#define CapSense_IdacCH0_viDAC8__D CYREG_DAC1_D
#define CapSense_IdacCH0_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define CapSense_IdacCH0_viDAC8__PM_ACT_MSK 0x02u
#define CapSense_IdacCH0_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define CapSense_IdacCH0_viDAC8__PM_STBY_MSK 0x02u
#define CapSense_IdacCH0_viDAC8__STROBE CYREG_DAC1_STROBE
#define CapSense_IdacCH0_viDAC8__SW0 CYREG_DAC1_SW0
#define CapSense_IdacCH0_viDAC8__SW2 CYREG_DAC1_SW2
#define CapSense_IdacCH0_viDAC8__SW3 CYREG_DAC1_SW3
#define CapSense_IdacCH0_viDAC8__SW4 CYREG_DAC1_SW4
#define CapSense_IdacCH0_viDAC8__TR CYREG_DAC1_TR
#define CapSense_IdacCH0_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC1_M1
#define CapSense_IdacCH0_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC1_M2
#define CapSense_IdacCH0_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC1_M3
#define CapSense_IdacCH0_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC1_M4
#define CapSense_IdacCH0_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC1_M5
#define CapSense_IdacCH0_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC1_M6
#define CapSense_IdacCH0_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC1_M7
#define CapSense_IdacCH0_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC1_M8
#define CapSense_IdacCH0_viDAC8__TST CYREG_DAC1_TST
#define CapSense_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define CapSense_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define CapSense_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define CapSense_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define CapSense_IntClock__INDEX 0x00u
#define CapSense_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define CapSense_IntClock__PM_ACT_MSK 0x01u
#define CapSense_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define CapSense_IntClock__PM_STBY_MSK 0x01u
#define CapSense_IsrCH0__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define CapSense_IsrCH0__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define CapSense_IsrCH0__INTC_MASK 0x01u
#define CapSense_IsrCH0__INTC_NUMBER 0u
#define CapSense_IsrCH0__INTC_PRIOR_NUM 7u
#define CapSense_IsrCH0__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define CapSense_IsrCH0__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define CapSense_IsrCH0__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_A0_REG CYREG_B0_UDB13_14_A0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_A1_REG CYREG_B0_UDB13_14_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_D0_REG CYREG_B0_UDB13_14_D0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_D1_REG CYREG_B0_UDB13_14_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB13_14_ACTL
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_F0_REG CYREG_B0_UDB13_14_F0
#define CapSense_MeasureCH0_UDB_Counter_u0__16BIT_F1_REG CYREG_B0_UDB13_14_F1
#define CapSense_MeasureCH0_UDB_Counter_u0__A0_A1_REG CYREG_B0_UDB13_A0_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__A0_REG CYREG_B0_UDB13_A0
#define CapSense_MeasureCH0_UDB_Counter_u0__A1_REG CYREG_B0_UDB13_A1
#define CapSense_MeasureCH0_UDB_Counter_u0__D0_D1_REG CYREG_B0_UDB13_D0_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__D0_REG CYREG_B0_UDB13_D0
#define CapSense_MeasureCH0_UDB_Counter_u0__D1_REG CYREG_B0_UDB13_D1
#define CapSense_MeasureCH0_UDB_Counter_u0__DP_AUX_CTL_REG CYREG_B0_UDB13_ACTL
#define CapSense_MeasureCH0_UDB_Counter_u0__F0_F1_REG CYREG_B0_UDB13_F0_F1
#define CapSense_MeasureCH0_UDB_Counter_u0__F0_REG CYREG_B0_UDB13_F0
#define CapSense_MeasureCH0_UDB_Counter_u0__F1_REG CYREG_B0_UDB13_F1
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_A0_REG CYREG_B0_UDB12_13_A0
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_A1_REG CYREG_B0_UDB12_13_A1
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_D0_REG CYREG_B0_UDB12_13_D0
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_D1_REG CYREG_B0_UDB12_13_D1
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB12_13_ACTL
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_F0_REG CYREG_B0_UDB12_13_F0
#define CapSense_MeasureCH0_UDB_Window_u0__16BIT_F1_REG CYREG_B0_UDB12_13_F1
#define CapSense_MeasureCH0_UDB_Window_u0__A0_A1_REG CYREG_B0_UDB12_A0_A1
#define CapSense_MeasureCH0_UDB_Window_u0__A0_REG CYREG_B0_UDB12_A0
#define CapSense_MeasureCH0_UDB_Window_u0__A1_REG CYREG_B0_UDB12_A1
#define CapSense_MeasureCH0_UDB_Window_u0__D0_D1_REG CYREG_B0_UDB12_D0_D1
#define CapSense_MeasureCH0_UDB_Window_u0__D0_REG CYREG_B0_UDB12_D0
#define CapSense_MeasureCH0_UDB_Window_u0__D1_REG CYREG_B0_UDB12_D1
#define CapSense_MeasureCH0_UDB_Window_u0__DP_AUX_CTL_REG CYREG_B0_UDB12_ACTL
#define CapSense_MeasureCH0_UDB_Window_u0__F0_F1_REG CYREG_B0_UDB12_F0_F1
#define CapSense_MeasureCH0_UDB_Window_u0__F0_REG CYREG_B0_UDB12_F0
#define CapSense_MeasureCH0_UDB_Window_u0__F1_REG CYREG_B0_UDB12_F1
#define CapSense_PortCH0__0__INTTYPE CYREG_PICU1_INTTYPE4
#define CapSense_PortCH0__0__MASK 0x10u
#define CapSense_PortCH0__0__PC CYREG_PRT1_PC4
#define CapSense_PortCH0__0__PORT 1u
#define CapSense_PortCH0__0__SHIFT 4u
#define CapSense_PortCH0__AG CYREG_PRT1_AG
#define CapSense_PortCH0__AMUX CYREG_PRT1_AMUX
#define CapSense_PortCH0__BIE CYREG_PRT1_BIE
#define CapSense_PortCH0__BIT_MASK CYREG_PRT1_BIT_MASK
#define CapSense_PortCH0__BYP CYREG_PRT1_BYP
#define CapSense_PortCH0__CTL CYREG_PRT1_CTL
#define CapSense_PortCH0__DM0 CYREG_PRT1_DM0
#define CapSense_PortCH0__DM1 CYREG_PRT1_DM1
#define CapSense_PortCH0__DM2 CYREG_PRT1_DM2
#define CapSense_PortCH0__DR CYREG_PRT1_DR
#define CapSense_PortCH0__INP_DIS CYREG_PRT1_INP_DIS
#define CapSense_PortCH0__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define CapSense_PortCH0__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define CapSense_PortCH0__LCD_EN CYREG_PRT1_LCD_EN
#define CapSense_PortCH0__MASK 0x10u
#define CapSense_PortCH0__PORT 1u
#define CapSense_PortCH0__ProximitySensor0_0__PROX__INTTYPE CYREG_PICU1_INTTYPE4
#define CapSense_PortCH0__ProximitySensor0_0__PROX__MASK 0x10u
#define CapSense_PortCH0__ProximitySensor0_0__PROX__PC CYREG_PRT1_PC4
#define CapSense_PortCH0__ProximitySensor0_0__PROX__PORT 1u
#define CapSense_PortCH0__ProximitySensor0_0__PROX__SHIFT 4u
#define CapSense_PortCH0__PRT CYREG_PRT1_PRT
#define CapSense_PortCH0__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define CapSense_PortCH0__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define CapSense_PortCH0__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define CapSense_PortCH0__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define CapSense_PortCH0__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define CapSense_PortCH0__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define CapSense_PortCH0__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define CapSense_PortCH0__PS CYREG_PRT1_PS
#define CapSense_PortCH0__SHIFT 4u
#define CapSense_PortCH0__SLW CYREG_PRT1_SLW
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "ProxSensor"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */