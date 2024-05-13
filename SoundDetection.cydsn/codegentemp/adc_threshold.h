/*******************************************************************************
* File Name: adc_threshold.h  
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

#if !defined(CY_PINS_adc_threshold_H) /* Pins adc_threshold_H */
#define CY_PINS_adc_threshold_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "adc_threshold_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 adc_threshold__PORT == 15 && ((adc_threshold__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    adc_threshold_Write(uint8 value);
void    adc_threshold_SetDriveMode(uint8 mode);
uint8   adc_threshold_ReadDataReg(void);
uint8   adc_threshold_Read(void);
void    adc_threshold_SetInterruptMode(uint16 position, uint16 mode);
uint8   adc_threshold_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the adc_threshold_SetDriveMode() function.
     *  @{
     */
        #define adc_threshold_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define adc_threshold_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define adc_threshold_DM_RES_UP          PIN_DM_RES_UP
        #define adc_threshold_DM_RES_DWN         PIN_DM_RES_DWN
        #define adc_threshold_DM_OD_LO           PIN_DM_OD_LO
        #define adc_threshold_DM_OD_HI           PIN_DM_OD_HI
        #define adc_threshold_DM_STRONG          PIN_DM_STRONG
        #define adc_threshold_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define adc_threshold_MASK               adc_threshold__MASK
#define adc_threshold_SHIFT              adc_threshold__SHIFT
#define adc_threshold_WIDTH              1u

/* Interrupt constants */
#if defined(adc_threshold__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in adc_threshold_SetInterruptMode() function.
     *  @{
     */
        #define adc_threshold_INTR_NONE      (uint16)(0x0000u)
        #define adc_threshold_INTR_RISING    (uint16)(0x0001u)
        #define adc_threshold_INTR_FALLING   (uint16)(0x0002u)
        #define adc_threshold_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define adc_threshold_INTR_MASK      (0x01u) 
#endif /* (adc_threshold__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define adc_threshold_PS                     (* (reg8 *) adc_threshold__PS)
/* Data Register */
#define adc_threshold_DR                     (* (reg8 *) adc_threshold__DR)
/* Port Number */
#define adc_threshold_PRT_NUM                (* (reg8 *) adc_threshold__PRT) 
/* Connect to Analog Globals */                                                  
#define adc_threshold_AG                     (* (reg8 *) adc_threshold__AG)                       
/* Analog MUX bux enable */
#define adc_threshold_AMUX                   (* (reg8 *) adc_threshold__AMUX) 
/* Bidirectional Enable */                                                        
#define adc_threshold_BIE                    (* (reg8 *) adc_threshold__BIE)
/* Bit-mask for Aliased Register Access */
#define adc_threshold_BIT_MASK               (* (reg8 *) adc_threshold__BIT_MASK)
/* Bypass Enable */
#define adc_threshold_BYP                    (* (reg8 *) adc_threshold__BYP)
/* Port wide control signals */                                                   
#define adc_threshold_CTL                    (* (reg8 *) adc_threshold__CTL)
/* Drive Modes */
#define adc_threshold_DM0                    (* (reg8 *) adc_threshold__DM0) 
#define adc_threshold_DM1                    (* (reg8 *) adc_threshold__DM1)
#define adc_threshold_DM2                    (* (reg8 *) adc_threshold__DM2) 
/* Input Buffer Disable Override */
#define adc_threshold_INP_DIS                (* (reg8 *) adc_threshold__INP_DIS)
/* LCD Common or Segment Drive */
#define adc_threshold_LCD_COM_SEG            (* (reg8 *) adc_threshold__LCD_COM_SEG)
/* Enable Segment LCD */
#define adc_threshold_LCD_EN                 (* (reg8 *) adc_threshold__LCD_EN)
/* Slew Rate Control */
#define adc_threshold_SLW                    (* (reg8 *) adc_threshold__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define adc_threshold_PRTDSI__CAPS_SEL       (* (reg8 *) adc_threshold__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define adc_threshold_PRTDSI__DBL_SYNC_IN    (* (reg8 *) adc_threshold__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define adc_threshold_PRTDSI__OE_SEL0        (* (reg8 *) adc_threshold__PRTDSI__OE_SEL0) 
#define adc_threshold_PRTDSI__OE_SEL1        (* (reg8 *) adc_threshold__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define adc_threshold_PRTDSI__OUT_SEL0       (* (reg8 *) adc_threshold__PRTDSI__OUT_SEL0) 
#define adc_threshold_PRTDSI__OUT_SEL1       (* (reg8 *) adc_threshold__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define adc_threshold_PRTDSI__SYNC_OUT       (* (reg8 *) adc_threshold__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(adc_threshold__SIO_CFG)
    #define adc_threshold_SIO_HYST_EN        (* (reg8 *) adc_threshold__SIO_HYST_EN)
    #define adc_threshold_SIO_REG_HIFREQ     (* (reg8 *) adc_threshold__SIO_REG_HIFREQ)
    #define adc_threshold_SIO_CFG            (* (reg8 *) adc_threshold__SIO_CFG)
    #define adc_threshold_SIO_DIFF           (* (reg8 *) adc_threshold__SIO_DIFF)
#endif /* (adc_threshold__SIO_CFG) */

/* Interrupt Registers */
#if defined(adc_threshold__INTSTAT)
    #define adc_threshold_INTSTAT            (* (reg8 *) adc_threshold__INTSTAT)
    #define adc_threshold_SNAP               (* (reg8 *) adc_threshold__SNAP)
    
	#define adc_threshold_0_INTTYPE_REG 		(* (reg8 *) adc_threshold__0__INTTYPE)
#endif /* (adc_threshold__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_adc_threshold_H */


/* [] END OF FILE */
