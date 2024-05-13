/*******************************************************************************
* File Name: ledr.h  
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

#if !defined(CY_PINS_ledr_H) /* Pins ledr_H */
#define CY_PINS_ledr_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ledr_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ledr__PORT == 15 && ((ledr__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ledr_Write(uint8 value);
void    ledr_SetDriveMode(uint8 mode);
uint8   ledr_ReadDataReg(void);
uint8   ledr_Read(void);
void    ledr_SetInterruptMode(uint16 position, uint16 mode);
uint8   ledr_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ledr_SetDriveMode() function.
     *  @{
     */
        #define ledr_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ledr_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ledr_DM_RES_UP          PIN_DM_RES_UP
        #define ledr_DM_RES_DWN         PIN_DM_RES_DWN
        #define ledr_DM_OD_LO           PIN_DM_OD_LO
        #define ledr_DM_OD_HI           PIN_DM_OD_HI
        #define ledr_DM_STRONG          PIN_DM_STRONG
        #define ledr_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ledr_MASK               ledr__MASK
#define ledr_SHIFT              ledr__SHIFT
#define ledr_WIDTH              1u

/* Interrupt constants */
#if defined(ledr__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ledr_SetInterruptMode() function.
     *  @{
     */
        #define ledr_INTR_NONE      (uint16)(0x0000u)
        #define ledr_INTR_RISING    (uint16)(0x0001u)
        #define ledr_INTR_FALLING   (uint16)(0x0002u)
        #define ledr_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ledr_INTR_MASK      (0x01u) 
#endif /* (ledr__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ledr_PS                     (* (reg8 *) ledr__PS)
/* Data Register */
#define ledr_DR                     (* (reg8 *) ledr__DR)
/* Port Number */
#define ledr_PRT_NUM                (* (reg8 *) ledr__PRT) 
/* Connect to Analog Globals */                                                  
#define ledr_AG                     (* (reg8 *) ledr__AG)                       
/* Analog MUX bux enable */
#define ledr_AMUX                   (* (reg8 *) ledr__AMUX) 
/* Bidirectional Enable */                                                        
#define ledr_BIE                    (* (reg8 *) ledr__BIE)
/* Bit-mask for Aliased Register Access */
#define ledr_BIT_MASK               (* (reg8 *) ledr__BIT_MASK)
/* Bypass Enable */
#define ledr_BYP                    (* (reg8 *) ledr__BYP)
/* Port wide control signals */                                                   
#define ledr_CTL                    (* (reg8 *) ledr__CTL)
/* Drive Modes */
#define ledr_DM0                    (* (reg8 *) ledr__DM0) 
#define ledr_DM1                    (* (reg8 *) ledr__DM1)
#define ledr_DM2                    (* (reg8 *) ledr__DM2) 
/* Input Buffer Disable Override */
#define ledr_INP_DIS                (* (reg8 *) ledr__INP_DIS)
/* LCD Common or Segment Drive */
#define ledr_LCD_COM_SEG            (* (reg8 *) ledr__LCD_COM_SEG)
/* Enable Segment LCD */
#define ledr_LCD_EN                 (* (reg8 *) ledr__LCD_EN)
/* Slew Rate Control */
#define ledr_SLW                    (* (reg8 *) ledr__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ledr_PRTDSI__CAPS_SEL       (* (reg8 *) ledr__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ledr_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ledr__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ledr_PRTDSI__OE_SEL0        (* (reg8 *) ledr__PRTDSI__OE_SEL0) 
#define ledr_PRTDSI__OE_SEL1        (* (reg8 *) ledr__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ledr_PRTDSI__OUT_SEL0       (* (reg8 *) ledr__PRTDSI__OUT_SEL0) 
#define ledr_PRTDSI__OUT_SEL1       (* (reg8 *) ledr__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ledr_PRTDSI__SYNC_OUT       (* (reg8 *) ledr__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ledr__SIO_CFG)
    #define ledr_SIO_HYST_EN        (* (reg8 *) ledr__SIO_HYST_EN)
    #define ledr_SIO_REG_HIFREQ     (* (reg8 *) ledr__SIO_REG_HIFREQ)
    #define ledr_SIO_CFG            (* (reg8 *) ledr__SIO_CFG)
    #define ledr_SIO_DIFF           (* (reg8 *) ledr__SIO_DIFF)
#endif /* (ledr__SIO_CFG) */

/* Interrupt Registers */
#if defined(ledr__INTSTAT)
    #define ledr_INTSTAT            (* (reg8 *) ledr__INTSTAT)
    #define ledr_SNAP               (* (reg8 *) ledr__SNAP)
    
	#define ledr_0_INTTYPE_REG 		(* (reg8 *) ledr__0__INTTYPE)
#endif /* (ledr__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ledr_H */


/* [] END OF FILE */
