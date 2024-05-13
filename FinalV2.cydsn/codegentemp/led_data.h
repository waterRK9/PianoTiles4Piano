/*******************************************************************************
* File Name: led_data.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_led_data_H) /* Pins led_data_H */
#define CY_PINS_led_data_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "led_data_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 led_data__PORT == 15 && ((led_data__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    led_data_Write(uint8 value) ;
void    led_data_SetDriveMode(uint8 mode) ;
uint8   led_data_ReadDataReg(void) ;
uint8   led_data_Read(void) ;
uint8   led_data_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define led_data_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define led_data_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define led_data_DM_RES_UP          PIN_DM_RES_UP
#define led_data_DM_RES_DWN         PIN_DM_RES_DWN
#define led_data_DM_OD_LO           PIN_DM_OD_LO
#define led_data_DM_OD_HI           PIN_DM_OD_HI
#define led_data_DM_STRONG          PIN_DM_STRONG
#define led_data_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define led_data_MASK               led_data__MASK
#define led_data_SHIFT              led_data__SHIFT
#define led_data_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define led_data_PS                     (* (reg8 *) led_data__PS)
/* Data Register */
#define led_data_DR                     (* (reg8 *) led_data__DR)
/* Port Number */
#define led_data_PRT_NUM                (* (reg8 *) led_data__PRT) 
/* Connect to Analog Globals */                                                  
#define led_data_AG                     (* (reg8 *) led_data__AG)                       
/* Analog MUX bux enable */
#define led_data_AMUX                   (* (reg8 *) led_data__AMUX) 
/* Bidirectional Enable */                                                        
#define led_data_BIE                    (* (reg8 *) led_data__BIE)
/* Bit-mask for Aliased Register Access */
#define led_data_BIT_MASK               (* (reg8 *) led_data__BIT_MASK)
/* Bypass Enable */
#define led_data_BYP                    (* (reg8 *) led_data__BYP)
/* Port wide control signals */                                                   
#define led_data_CTL                    (* (reg8 *) led_data__CTL)
/* Drive Modes */
#define led_data_DM0                    (* (reg8 *) led_data__DM0) 
#define led_data_DM1                    (* (reg8 *) led_data__DM1)
#define led_data_DM2                    (* (reg8 *) led_data__DM2) 
/* Input Buffer Disable Override */
#define led_data_INP_DIS                (* (reg8 *) led_data__INP_DIS)
/* LCD Common or Segment Drive */
#define led_data_LCD_COM_SEG            (* (reg8 *) led_data__LCD_COM_SEG)
/* Enable Segment LCD */
#define led_data_LCD_EN                 (* (reg8 *) led_data__LCD_EN)
/* Slew Rate Control */
#define led_data_SLW                    (* (reg8 *) led_data__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define led_data_PRTDSI__CAPS_SEL       (* (reg8 *) led_data__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define led_data_PRTDSI__DBL_SYNC_IN    (* (reg8 *) led_data__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define led_data_PRTDSI__OE_SEL0        (* (reg8 *) led_data__PRTDSI__OE_SEL0) 
#define led_data_PRTDSI__OE_SEL1        (* (reg8 *) led_data__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define led_data_PRTDSI__OUT_SEL0       (* (reg8 *) led_data__PRTDSI__OUT_SEL0) 
#define led_data_PRTDSI__OUT_SEL1       (* (reg8 *) led_data__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define led_data_PRTDSI__SYNC_OUT       (* (reg8 *) led_data__PRTDSI__SYNC_OUT) 


#if defined(led_data__INTSTAT)  /* Interrupt Registers */

    #define led_data_INTSTAT                (* (reg8 *) led_data__INTSTAT)
    #define led_data_SNAP                   (* (reg8 *) led_data__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_led_data_H */


/* [] END OF FILE */
