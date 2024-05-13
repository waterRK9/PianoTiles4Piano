#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* DC */
DC__0__INTTYPE EQU CYREG_PICU2_INTTYPE5
DC__0__MASK EQU 0x20
DC__0__PC EQU CYREG_PRT2_PC5
DC__0__PORT EQU 2
DC__0__SHIFT EQU 5
DC__AG EQU CYREG_PRT2_AG
DC__AMUX EQU CYREG_PRT2_AMUX
DC__BIE EQU CYREG_PRT2_BIE
DC__BIT_MASK EQU CYREG_PRT2_BIT_MASK
DC__BYP EQU CYREG_PRT2_BYP
DC__CTL EQU CYREG_PRT2_CTL
DC__DM0 EQU CYREG_PRT2_DM0
DC__DM1 EQU CYREG_PRT2_DM1
DC__DM2 EQU CYREG_PRT2_DM2
DC__DR EQU CYREG_PRT2_DR
DC__INP_DIS EQU CYREG_PRT2_INP_DIS
DC__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
DC__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
DC__LCD_EN EQU CYREG_PRT2_LCD_EN
DC__MASK EQU 0x20
DC__PORT EQU 2
DC__PRT EQU CYREG_PRT2_PRT
DC__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
DC__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
DC__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
DC__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
DC__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
DC__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
DC__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
DC__PS EQU CYREG_PRT2_PS
DC__SHIFT EQU 5
DC__SLW EQU CYREG_PRT2_SLW

/* SS */
SS__0__INTTYPE EQU CYREG_PICU2_INTTYPE7
SS__0__MASK EQU 0x80
SS__0__PC EQU CYREG_PRT2_PC7
SS__0__PORT EQU 2
SS__0__SHIFT EQU 7
SS__AG EQU CYREG_PRT2_AG
SS__AMUX EQU CYREG_PRT2_AMUX
SS__BIE EQU CYREG_PRT2_BIE
SS__BIT_MASK EQU CYREG_PRT2_BIT_MASK
SS__BYP EQU CYREG_PRT2_BYP
SS__CTL EQU CYREG_PRT2_CTL
SS__DM0 EQU CYREG_PRT2_DM0
SS__DM1 EQU CYREG_PRT2_DM1
SS__DM2 EQU CYREG_PRT2_DM2
SS__DR EQU CYREG_PRT2_DR
SS__INP_DIS EQU CYREG_PRT2_INP_DIS
SS__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
SS__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
SS__LCD_EN EQU CYREG_PRT2_LCD_EN
SS__MASK EQU 0x80
SS__PORT EQU 2
SS__PRT EQU CYREG_PRT2_PRT
SS__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
SS__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
SS__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
SS__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
SS__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
SS__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
SS__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
SS__PS EQU CYREG_PRT2_PS
SS__SHIFT EQU 7
SS__SLW EQU CYREG_PRT2_SLW

/* LED */
LED__0__INTTYPE EQU CYREG_PICU2_INTTYPE2
LED__0__MASK EQU 0x04
LED__0__PC EQU CYREG_PRT2_PC2
LED__0__PORT EQU 2
LED__0__SHIFT EQU 2
LED__AG EQU CYREG_PRT2_AG
LED__AMUX EQU CYREG_PRT2_AMUX
LED__BIE EQU CYREG_PRT2_BIE
LED__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LED__BYP EQU CYREG_PRT2_BYP
LED__CTL EQU CYREG_PRT2_CTL
LED__DM0 EQU CYREG_PRT2_DM0
LED__DM1 EQU CYREG_PRT2_DM1
LED__DM2 EQU CYREG_PRT2_DM2
LED__DR EQU CYREG_PRT2_DR
LED__INP_DIS EQU CYREG_PRT2_INP_DIS
LED__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LED__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LED__LCD_EN EQU CYREG_PRT2_LCD_EN
LED__MASK EQU 0x04
LED__PORT EQU 2
LED__PRT EQU CYREG_PRT2_PRT
LED__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LED__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LED__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LED__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LED__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LED__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LED__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LED__PS EQU CYREG_PRT2_PS
LED__SHIFT EQU 2
LED__SLW EQU CYREG_PRT2_SLW

/* SW2 */
SW2__0__INTTYPE EQU CYREG_PICU6_INTTYPE1
SW2__0__MASK EQU 0x02
SW2__0__PC EQU CYREG_PRT6_PC1
SW2__0__PORT EQU 6
SW2__0__SHIFT EQU 1
SW2__AG EQU CYREG_PRT6_AG
SW2__AMUX EQU CYREG_PRT6_AMUX
SW2__BIE EQU CYREG_PRT6_BIE
SW2__BIT_MASK EQU CYREG_PRT6_BIT_MASK
SW2__BYP EQU CYREG_PRT6_BYP
SW2__CTL EQU CYREG_PRT6_CTL
SW2__DM0 EQU CYREG_PRT6_DM0
SW2__DM1 EQU CYREG_PRT6_DM1
SW2__DM2 EQU CYREG_PRT6_DM2
SW2__DR EQU CYREG_PRT6_DR
SW2__INP_DIS EQU CYREG_PRT6_INP_DIS
SW2__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU6_BASE
SW2__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
SW2__LCD_EN EQU CYREG_PRT6_LCD_EN
SW2__MASK EQU 0x02
SW2__PORT EQU 6
SW2__PRT EQU CYREG_PRT6_PRT
SW2__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
SW2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
SW2__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
SW2__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
SW2__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
SW2__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
SW2__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
SW2__PS EQU CYREG_PRT6_PS
SW2__SHIFT EQU 1
SW2__SLW EQU CYREG_PRT6_SLW

/* SW3 */
SW3__0__INTTYPE EQU CYREG_PICU15_INTTYPE5
SW3__0__MASK EQU 0x20
SW3__0__PC EQU CYREG_IO_PC_PRT15_PC5
SW3__0__PORT EQU 15
SW3__0__SHIFT EQU 5
SW3__AG EQU CYREG_PRT15_AG
SW3__AMUX EQU CYREG_PRT15_AMUX
SW3__BIE EQU CYREG_PRT15_BIE
SW3__BIT_MASK EQU CYREG_PRT15_BIT_MASK
SW3__BYP EQU CYREG_PRT15_BYP
SW3__CTL EQU CYREG_PRT15_CTL
SW3__DM0 EQU CYREG_PRT15_DM0
SW3__DM1 EQU CYREG_PRT15_DM1
SW3__DM2 EQU CYREG_PRT15_DM2
SW3__DR EQU CYREG_PRT15_DR
SW3__INP_DIS EQU CYREG_PRT15_INP_DIS
SW3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU15_BASE
SW3__LCD_COM_SEG EQU CYREG_PRT15_LCD_COM_SEG
SW3__LCD_EN EQU CYREG_PRT15_LCD_EN
SW3__MASK EQU 0x20
SW3__PORT EQU 15
SW3__PRT EQU CYREG_PRT15_PRT
SW3__PRTDSI__CAPS_SEL EQU CYREG_PRT15_CAPS_SEL
SW3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT15_DBL_SYNC_IN
SW3__PRTDSI__OE_SEL0 EQU CYREG_PRT15_OE_SEL0
SW3__PRTDSI__OE_SEL1 EQU CYREG_PRT15_OE_SEL1
SW3__PRTDSI__OUT_SEL0 EQU CYREG_PRT15_OUT_SEL0
SW3__PRTDSI__OUT_SEL1 EQU CYREG_PRT15_OUT_SEL1
SW3__PRTDSI__SYNC_OUT EQU CYREG_PRT15_SYNC_OUT
SW3__PS EQU CYREG_PRT15_PS
SW3__SHIFT EQU 5
SW3__SLW EQU CYREG_PRT15_SLW

/* LED3 */
LED3__0__INTTYPE EQU CYREG_PICU6_INTTYPE2
LED3__0__MASK EQU 0x04
LED3__0__PC EQU CYREG_PRT6_PC2
LED3__0__PORT EQU 6
LED3__0__SHIFT EQU 2
LED3__AG EQU CYREG_PRT6_AG
LED3__AMUX EQU CYREG_PRT6_AMUX
LED3__BIE EQU CYREG_PRT6_BIE
LED3__BIT_MASK EQU CYREG_PRT6_BIT_MASK
LED3__BYP EQU CYREG_PRT6_BYP
LED3__CTL EQU CYREG_PRT6_CTL
LED3__DM0 EQU CYREG_PRT6_DM0
LED3__DM1 EQU CYREG_PRT6_DM1
LED3__DM2 EQU CYREG_PRT6_DM2
LED3__DR EQU CYREG_PRT6_DR
LED3__INP_DIS EQU CYREG_PRT6_INP_DIS
LED3__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU6_BASE
LED3__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
LED3__LCD_EN EQU CYREG_PRT6_LCD_EN
LED3__MASK EQU 0x04
LED3__PORT EQU 6
LED3__PRT EQU CYREG_PRT6_PRT
LED3__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
LED3__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
LED3__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
LED3__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
LED3__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
LED3__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
LED3__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
LED3__PS EQU CYREG_PRT6_PS
LED3__SHIFT EQU 2
LED3__SLW EQU CYREG_PRT6_SLW

/* LED4 */
LED4__0__INTTYPE EQU CYREG_PICU6_INTTYPE3
LED4__0__MASK EQU 0x08
LED4__0__PC EQU CYREG_PRT6_PC3
LED4__0__PORT EQU 6
LED4__0__SHIFT EQU 3
LED4__AG EQU CYREG_PRT6_AG
LED4__AMUX EQU CYREG_PRT6_AMUX
LED4__BIE EQU CYREG_PRT6_BIE
LED4__BIT_MASK EQU CYREG_PRT6_BIT_MASK
LED4__BYP EQU CYREG_PRT6_BYP
LED4__CTL EQU CYREG_PRT6_CTL
LED4__DM0 EQU CYREG_PRT6_DM0
LED4__DM1 EQU CYREG_PRT6_DM1
LED4__DM2 EQU CYREG_PRT6_DM2
LED4__DR EQU CYREG_PRT6_DR
LED4__INP_DIS EQU CYREG_PRT6_INP_DIS
LED4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU6_BASE
LED4__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
LED4__LCD_EN EQU CYREG_PRT6_LCD_EN
LED4__MASK EQU 0x08
LED4__PORT EQU 6
LED4__PRT EQU CYREG_PRT6_PRT
LED4__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
LED4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
LED4__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
LED4__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
LED4__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
LED4__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
LED4__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
LED4__PS EQU CYREG_PRT6_PS
LED4__SHIFT EQU 3
LED4__SLW EQU CYREG_PRT6_SLW

/* MISO */
MISO__0__INTTYPE EQU CYREG_PICU2_INTTYPE1
MISO__0__MASK EQU 0x02
MISO__0__PC EQU CYREG_PRT2_PC1
MISO__0__PORT EQU 2
MISO__0__SHIFT EQU 1
MISO__AG EQU CYREG_PRT2_AG
MISO__AMUX EQU CYREG_PRT2_AMUX
MISO__BIE EQU CYREG_PRT2_BIE
MISO__BIT_MASK EQU CYREG_PRT2_BIT_MASK
MISO__BYP EQU CYREG_PRT2_BYP
MISO__CTL EQU CYREG_PRT2_CTL
MISO__DM0 EQU CYREG_PRT2_DM0
MISO__DM1 EQU CYREG_PRT2_DM1
MISO__DM2 EQU CYREG_PRT2_DM2
MISO__DR EQU CYREG_PRT2_DR
MISO__INP_DIS EQU CYREG_PRT2_INP_DIS
MISO__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
MISO__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
MISO__LCD_EN EQU CYREG_PRT2_LCD_EN
MISO__MASK EQU 0x02
MISO__PORT EQU 2
MISO__PRT EQU CYREG_PRT2_PRT
MISO__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
MISO__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
MISO__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
MISO__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
MISO__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
MISO__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
MISO__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
MISO__PS EQU CYREG_PRT2_PS
MISO__SHIFT EQU 1
MISO__SLW EQU CYREG_PRT2_SLW

/* MOSI */
MOSI__0__INTTYPE EQU CYREG_PICU2_INTTYPE4
MOSI__0__MASK EQU 0x10
MOSI__0__PC EQU CYREG_PRT2_PC4
MOSI__0__PORT EQU 2
MOSI__0__SHIFT EQU 4
MOSI__AG EQU CYREG_PRT2_AG
MOSI__AMUX EQU CYREG_PRT2_AMUX
MOSI__BIE EQU CYREG_PRT2_BIE
MOSI__BIT_MASK EQU CYREG_PRT2_BIT_MASK
MOSI__BYP EQU CYREG_PRT2_BYP
MOSI__CTL EQU CYREG_PRT2_CTL
MOSI__DM0 EQU CYREG_PRT2_DM0
MOSI__DM1 EQU CYREG_PRT2_DM1
MOSI__DM2 EQU CYREG_PRT2_DM2
MOSI__DR EQU CYREG_PRT2_DR
MOSI__INP_DIS EQU CYREG_PRT2_INP_DIS
MOSI__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
MOSI__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
MOSI__LCD_EN EQU CYREG_PRT2_LCD_EN
MOSI__MASK EQU 0x10
MOSI__PORT EQU 2
MOSI__PRT EQU CYREG_PRT2_PRT
MOSI__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
MOSI__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
MOSI__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
MOSI__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
MOSI__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
MOSI__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
MOSI__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
MOSI__PS EQU CYREG_PRT2_PS
MOSI__SHIFT EQU 4
MOSI__SLW EQU CYREG_PRT2_SLW

/* SCLK */
SCLK__0__INTTYPE EQU CYREG_PICU2_INTTYPE3
SCLK__0__MASK EQU 0x08
SCLK__0__PC EQU CYREG_PRT2_PC3
SCLK__0__PORT EQU 2
SCLK__0__SHIFT EQU 3
SCLK__AG EQU CYREG_PRT2_AG
SCLK__AMUX EQU CYREG_PRT2_AMUX
SCLK__BIE EQU CYREG_PRT2_BIE
SCLK__BIT_MASK EQU CYREG_PRT2_BIT_MASK
SCLK__BYP EQU CYREG_PRT2_BYP
SCLK__CTL EQU CYREG_PRT2_CTL
SCLK__DM0 EQU CYREG_PRT2_DM0
SCLK__DM1 EQU CYREG_PRT2_DM1
SCLK__DM2 EQU CYREG_PRT2_DM2
SCLK__DR EQU CYREG_PRT2_DR
SCLK__INP_DIS EQU CYREG_PRT2_INP_DIS
SCLK__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
SCLK__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
SCLK__LCD_EN EQU CYREG_PRT2_LCD_EN
SCLK__MASK EQU 0x08
SCLK__PORT EQU 2
SCLK__PRT EQU CYREG_PRT2_PRT
SCLK__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
SCLK__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
SCLK__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
SCLK__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
SCLK__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
SCLK__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
SCLK__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
SCLK__PS EQU CYREG_PRT2_PS
SCLK__SHIFT EQU 3
SCLK__SLW EQU CYREG_PRT2_SLW

/* RESET */
RESET__0__INTTYPE EQU CYREG_PICU2_INTTYPE6
RESET__0__MASK EQU 0x40
RESET__0__PC EQU CYREG_PRT2_PC6
RESET__0__PORT EQU 2
RESET__0__SHIFT EQU 6
RESET__AG EQU CYREG_PRT2_AG
RESET__AMUX EQU CYREG_PRT2_AMUX
RESET__BIE EQU CYREG_PRT2_BIE
RESET__BIT_MASK EQU CYREG_PRT2_BIT_MASK
RESET__BYP EQU CYREG_PRT2_BYP
RESET__CTL EQU CYREG_PRT2_CTL
RESET__DM0 EQU CYREG_PRT2_DM0
RESET__DM1 EQU CYREG_PRT2_DM1
RESET__DM2 EQU CYREG_PRT2_DM2
RESET__DR EQU CYREG_PRT2_DR
RESET__INP_DIS EQU CYREG_PRT2_INP_DIS
RESET__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
RESET__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
RESET__LCD_EN EQU CYREG_PRT2_LCD_EN
RESET__MASK EQU 0x40
RESET__PORT EQU 2
RESET__PRT EQU CYREG_PRT2_PRT
RESET__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
RESET__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
RESET__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
RESET__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
RESET__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
RESET__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
RESET__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
RESET__PS EQU CYREG_PRT2_PS
RESET__SHIFT EQU 6
RESET__SLW EQU CYREG_PRT2_SLW

/* SPIM_1_BSPIM */
SPIM_1_BSPIM_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
SPIM_1_BSPIM_BitCounter__CONTROL_REG EQU CYREG_B0_UDB15_CTL
SPIM_1_BSPIM_BitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB15_ST_CTL
SPIM_1_BSPIM_BitCounter__COUNT_REG EQU CYREG_B0_UDB15_CTL
SPIM_1_BSPIM_BitCounter__COUNT_ST_REG EQU CYREG_B0_UDB15_ST_CTL
SPIM_1_BSPIM_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
SPIM_1_BSPIM_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
SPIM_1_BSPIM_BitCounter__PERIOD_REG EQU CYREG_B0_UDB15_MSK
SPIM_1_BSPIM_BitCounter_ST__MASK_REG EQU CYREG_B0_UDB15_MSK
SPIM_1_BSPIM_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
SPIM_1_BSPIM_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB15_MSK_ACTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB15_ACTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB15_ST_CTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB15_ST_CTL
SPIM_1_BSPIM_BitCounter_ST__STATUS_REG EQU CYREG_B0_UDB15_ST
SPIM_1_BSPIM_RxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
SPIM_1_BSPIM_RxStsReg__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
SPIM_1_BSPIM_RxStsReg__4__MASK EQU 0x10
SPIM_1_BSPIM_RxStsReg__4__POS EQU 4
SPIM_1_BSPIM_RxStsReg__5__MASK EQU 0x20
SPIM_1_BSPIM_RxStsReg__5__POS EQU 5
SPIM_1_BSPIM_RxStsReg__6__MASK EQU 0x40
SPIM_1_BSPIM_RxStsReg__6__POS EQU 6
SPIM_1_BSPIM_RxStsReg__MASK EQU 0x70
SPIM_1_BSPIM_RxStsReg__MASK_REG EQU CYREG_B0_UDB13_MSK
SPIM_1_BSPIM_RxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
SPIM_1_BSPIM_RxStsReg__STATUS_REG EQU CYREG_B0_UDB13_ST
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
SPIM_1_BSPIM_sR8_Dp_u0__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
SPIM_1_BSPIM_sR8_Dp_u0__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
SPIM_1_BSPIM_sR8_Dp_u0__A0_REG EQU CYREG_B0_UDB13_A0
SPIM_1_BSPIM_sR8_Dp_u0__A1_REG EQU CYREG_B0_UDB13_A1
SPIM_1_BSPIM_sR8_Dp_u0__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
SPIM_1_BSPIM_sR8_Dp_u0__D0_REG EQU CYREG_B0_UDB13_D0
SPIM_1_BSPIM_sR8_Dp_u0__D1_REG EQU CYREG_B0_UDB13_D1
SPIM_1_BSPIM_sR8_Dp_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
SPIM_1_BSPIM_sR8_Dp_u0__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
SPIM_1_BSPIM_sR8_Dp_u0__F0_REG EQU CYREG_B0_UDB13_F0
SPIM_1_BSPIM_sR8_Dp_u0__F1_REG EQU CYREG_B0_UDB13_F1
SPIM_1_BSPIM_TxStsReg__0__MASK EQU 0x01
SPIM_1_BSPIM_TxStsReg__0__POS EQU 0
SPIM_1_BSPIM_TxStsReg__1__MASK EQU 0x02
SPIM_1_BSPIM_TxStsReg__1__POS EQU 1
SPIM_1_BSPIM_TxStsReg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
SPIM_1_BSPIM_TxStsReg__16BIT_STATUS_REG EQU CYREG_B0_UDB14_15_ST
SPIM_1_BSPIM_TxStsReg__2__MASK EQU 0x04
SPIM_1_BSPIM_TxStsReg__2__POS EQU 2
SPIM_1_BSPIM_TxStsReg__3__MASK EQU 0x08
SPIM_1_BSPIM_TxStsReg__3__POS EQU 3
SPIM_1_BSPIM_TxStsReg__4__MASK EQU 0x10
SPIM_1_BSPIM_TxStsReg__4__POS EQU 4
SPIM_1_BSPIM_TxStsReg__MASK EQU 0x1F
SPIM_1_BSPIM_TxStsReg__MASK_REG EQU CYREG_B0_UDB14_MSK
SPIM_1_BSPIM_TxStsReg__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
SPIM_1_BSPIM_TxStsReg__STATUS_REG EQU CYREG_B0_UDB14_ST

/* SPIM_1_IntClock */
SPIM_1_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
SPIM_1_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
SPIM_1_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
SPIM_1_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
SPIM_1_IntClock__INDEX EQU 0x00
SPIM_1_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
SPIM_1_IntClock__PM_ACT_MSK EQU 0x01
SPIM_1_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
SPIM_1_IntClock__PM_STBY_MSK EQU 0x01

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 19
CYDEV_CHIP_DIE_PSOC4A EQU 11
CYDEV_CHIP_DIE_PSOC5LP EQU 18
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 11
CYDEV_CHIP_MEMBER_4C EQU 16
CYDEV_CHIP_MEMBER_4D EQU 7
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 12
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 10
CYDEV_CHIP_MEMBER_4I EQU 15
CYDEV_CHIP_MEMBER_4J EQU 8
CYDEV_CHIP_MEMBER_4K EQU 9
CYDEV_CHIP_MEMBER_4L EQU 14
CYDEV_CHIP_MEMBER_4M EQU 13
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 18
CYDEV_CHIP_MEMBER_5B EQU 17
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */