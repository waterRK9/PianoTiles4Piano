    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; Pin_1
Pin_1__0__INTTYPE EQU CYREG_PICU6_INTTYPE6
Pin_1__0__MASK EQU 0x40
Pin_1__0__PC EQU CYREG_PRT6_PC6
Pin_1__0__PORT EQU 6
Pin_1__0__SHIFT EQU 6
Pin_1__AG EQU CYREG_PRT6_AG
Pin_1__AMUX EQU CYREG_PRT6_AMUX
Pin_1__BIE EQU CYREG_PRT6_BIE
Pin_1__BIT_MASK EQU CYREG_PRT6_BIT_MASK
Pin_1__BYP EQU CYREG_PRT6_BYP
Pin_1__CTL EQU CYREG_PRT6_CTL
Pin_1__DM0 EQU CYREG_PRT6_DM0
Pin_1__DM1 EQU CYREG_PRT6_DM1
Pin_1__DM2 EQU CYREG_PRT6_DM2
Pin_1__DR EQU CYREG_PRT6_DR
Pin_1__INP_DIS EQU CYREG_PRT6_INP_DIS
Pin_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU6_BASE
Pin_1__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
Pin_1__LCD_EN EQU CYREG_PRT6_LCD_EN
Pin_1__MASK EQU 0x40
Pin_1__PORT EQU 6
Pin_1__PRT EQU CYREG_PRT6_PRT
Pin_1__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
Pin_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
Pin_1__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
Pin_1__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
Pin_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
Pin_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
Pin_1__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
Pin_1__PS EQU CYREG_PRT6_PS
Pin_1__SHIFT EQU 6
Pin_1__SLW EQU CYREG_PRT6_SLW

; LCD_Char_1_LCDPort
LCD_Char_1_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_Char_1_LCDPort__0__MASK EQU 0x01
LCD_Char_1_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_Char_1_LCDPort__0__PORT EQU 2
LCD_Char_1_LCDPort__0__SHIFT EQU 0
LCD_Char_1_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_Char_1_LCDPort__1__MASK EQU 0x02
LCD_Char_1_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_Char_1_LCDPort__1__PORT EQU 2
LCD_Char_1_LCDPort__1__SHIFT EQU 1
LCD_Char_1_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_Char_1_LCDPort__2__MASK EQU 0x04
LCD_Char_1_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_Char_1_LCDPort__2__PORT EQU 2
LCD_Char_1_LCDPort__2__SHIFT EQU 2
LCD_Char_1_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_Char_1_LCDPort__3__MASK EQU 0x08
LCD_Char_1_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_Char_1_LCDPort__3__PORT EQU 2
LCD_Char_1_LCDPort__3__SHIFT EQU 3
LCD_Char_1_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_Char_1_LCDPort__4__MASK EQU 0x10
LCD_Char_1_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_Char_1_LCDPort__4__PORT EQU 2
LCD_Char_1_LCDPort__4__SHIFT EQU 4
LCD_Char_1_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_Char_1_LCDPort__5__MASK EQU 0x20
LCD_Char_1_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_Char_1_LCDPort__5__PORT EQU 2
LCD_Char_1_LCDPort__5__SHIFT EQU 5
LCD_Char_1_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_Char_1_LCDPort__6__MASK EQU 0x40
LCD_Char_1_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_Char_1_LCDPort__6__PORT EQU 2
LCD_Char_1_LCDPort__6__SHIFT EQU 6
LCD_Char_1_LCDPort__AG EQU CYREG_PRT2_AG
LCD_Char_1_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_Char_1_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_Char_1_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_Char_1_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_Char_1_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_Char_1_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_Char_1_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_Char_1_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_Char_1_LCDPort__DR EQU CYREG_PRT2_DR
LCD_Char_1_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_Char_1_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_Char_1_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_Char_1_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_Char_1_LCDPort__MASK EQU 0x7F
LCD_Char_1_LCDPort__PORT EQU 2
LCD_Char_1_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_Char_1_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_Char_1_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_Char_1_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_Char_1_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_Char_1_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_Char_1_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_Char_1_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_Char_1_LCDPort__PS EQU CYREG_PRT2_PS
LCD_Char_1_LCDPort__SHIFT EQU 0
LCD_Char_1_LCDPort__SLW EQU CYREG_PRT2_SLW

; ADC_DelSig_1_DEC
ADC_DelSig_1_DEC__COHER EQU CYREG_DEC_COHER
ADC_DelSig_1_DEC__CR EQU CYREG_DEC_CR
ADC_DelSig_1_DEC__DR1 EQU CYREG_DEC_DR1
ADC_DelSig_1_DEC__DR2 EQU CYREG_DEC_DR2
ADC_DelSig_1_DEC__DR2H EQU CYREG_DEC_DR2H
ADC_DelSig_1_DEC__GCOR EQU CYREG_DEC_GCOR
ADC_DelSig_1_DEC__GCORH EQU CYREG_DEC_GCORH
ADC_DelSig_1_DEC__GVAL EQU CYREG_DEC_GVAL
ADC_DelSig_1_DEC__OCOR EQU CYREG_DEC_OCOR
ADC_DelSig_1_DEC__OCORH EQU CYREG_DEC_OCORH
ADC_DelSig_1_DEC__OCORM EQU CYREG_DEC_OCORM
ADC_DelSig_1_DEC__OUTSAMP EQU CYREG_DEC_OUTSAMP
ADC_DelSig_1_DEC__OUTSAMPH EQU CYREG_DEC_OUTSAMPH
ADC_DelSig_1_DEC__OUTSAMPM EQU CYREG_DEC_OUTSAMPM
ADC_DelSig_1_DEC__OUTSAMPS EQU CYREG_DEC_OUTSAMPS
ADC_DelSig_1_DEC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG10
ADC_DelSig_1_DEC__PM_ACT_MSK EQU 0x01
ADC_DelSig_1_DEC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG10
ADC_DelSig_1_DEC__PM_STBY_MSK EQU 0x01
ADC_DelSig_1_DEC__SHIFT1 EQU CYREG_DEC_SHIFT1
ADC_DelSig_1_DEC__SHIFT2 EQU CYREG_DEC_SHIFT2
ADC_DelSig_1_DEC__SR EQU CYREG_DEC_SR
ADC_DelSig_1_DEC__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DEC_M1
ADC_DelSig_1_DEC__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DEC_M2
ADC_DelSig_1_DEC__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DEC_M3
ADC_DelSig_1_DEC__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DEC_M4
ADC_DelSig_1_DEC__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DEC_M5
ADC_DelSig_1_DEC__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DEC_M6
ADC_DelSig_1_DEC__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DEC_M7
ADC_DelSig_1_DEC__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DEC_M8

; ADC_DelSig_1_DSM
ADC_DelSig_1_DSM__BUF0 EQU CYREG_DSM0_BUF0
ADC_DelSig_1_DSM__BUF1 EQU CYREG_DSM0_BUF1
ADC_DelSig_1_DSM__BUF2 EQU CYREG_DSM0_BUF2
ADC_DelSig_1_DSM__BUF3 EQU CYREG_DSM0_BUF3
ADC_DelSig_1_DSM__CLK EQU CYREG_DSM0_CLK
ADC_DelSig_1_DSM__CR0 EQU CYREG_DSM0_CR0
ADC_DelSig_1_DSM__CR1 EQU CYREG_DSM0_CR1
ADC_DelSig_1_DSM__CR10 EQU CYREG_DSM0_CR10
ADC_DelSig_1_DSM__CR11 EQU CYREG_DSM0_CR11
ADC_DelSig_1_DSM__CR12 EQU CYREG_DSM0_CR12
ADC_DelSig_1_DSM__CR13 EQU CYREG_DSM0_CR13
ADC_DelSig_1_DSM__CR14 EQU CYREG_DSM0_CR14
ADC_DelSig_1_DSM__CR15 EQU CYREG_DSM0_CR15
ADC_DelSig_1_DSM__CR16 EQU CYREG_DSM0_CR16
ADC_DelSig_1_DSM__CR17 EQU CYREG_DSM0_CR17
ADC_DelSig_1_DSM__CR2 EQU CYREG_DSM0_CR2
ADC_DelSig_1_DSM__CR3 EQU CYREG_DSM0_CR3
ADC_DelSig_1_DSM__CR4 EQU CYREG_DSM0_CR4
ADC_DelSig_1_DSM__CR5 EQU CYREG_DSM0_CR5
ADC_DelSig_1_DSM__CR6 EQU CYREG_DSM0_CR6
ADC_DelSig_1_DSM__CR7 EQU CYREG_DSM0_CR7
ADC_DelSig_1_DSM__CR8 EQU CYREG_DSM0_CR8
ADC_DelSig_1_DSM__CR9 EQU CYREG_DSM0_CR9
ADC_DelSig_1_DSM__DEM0 EQU CYREG_DSM0_DEM0
ADC_DelSig_1_DSM__DEM1 EQU CYREG_DSM0_DEM1
ADC_DelSig_1_DSM__MISC EQU CYREG_DSM0_MISC
ADC_DelSig_1_DSM__OUT0 EQU CYREG_DSM0_OUT0
ADC_DelSig_1_DSM__OUT1 EQU CYREG_DSM0_OUT1
ADC_DelSig_1_DSM__REF0 EQU CYREG_DSM0_REF0
ADC_DelSig_1_DSM__REF1 EQU CYREG_DSM0_REF1
ADC_DelSig_1_DSM__REF2 EQU CYREG_DSM0_REF2
ADC_DelSig_1_DSM__REF3 EQU CYREG_DSM0_REF3
ADC_DelSig_1_DSM__RSVD1 EQU CYREG_DSM0_RSVD1
ADC_DelSig_1_DSM__SW0 EQU CYREG_DSM0_SW0
ADC_DelSig_1_DSM__SW2 EQU CYREG_DSM0_SW2
ADC_DelSig_1_DSM__SW3 EQU CYREG_DSM0_SW3
ADC_DelSig_1_DSM__SW4 EQU CYREG_DSM0_SW4
ADC_DelSig_1_DSM__SW6 EQU CYREG_DSM0_SW6
ADC_DelSig_1_DSM__TR0 EQU CYREG_NPUMP_DSM_TR0
ADC_DelSig_1_DSM__TST0 EQU CYREG_DSM0_TST0
ADC_DelSig_1_DSM__TST1 EQU CYREG_DSM0_TST1

; ADC_DelSig_1_Ext_CP_Clk
ADC_DelSig_1_Ext_CP_Clk__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
ADC_DelSig_1_Ext_CP_Clk__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
ADC_DelSig_1_Ext_CP_Clk__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
ADC_DelSig_1_Ext_CP_Clk__CFG2_SRC_SEL_MASK EQU 0x07
ADC_DelSig_1_Ext_CP_Clk__INDEX EQU 0x00
ADC_DelSig_1_Ext_CP_Clk__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ADC_DelSig_1_Ext_CP_Clk__PM_ACT_MSK EQU 0x01
ADC_DelSig_1_Ext_CP_Clk__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ADC_DelSig_1_Ext_CP_Clk__PM_STBY_MSK EQU 0x01

; ADC_DelSig_1_IRQ
ADC_DelSig_1_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_DelSig_1_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_DelSig_1_IRQ__INTC_MASK EQU 0x20000000
ADC_DelSig_1_IRQ__INTC_NUMBER EQU 29
ADC_DelSig_1_IRQ__INTC_PRIOR_NUM EQU 7
ADC_DelSig_1_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_29
ADC_DelSig_1_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_DelSig_1_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ADC_DelSig_1_theACLK
ADC_DelSig_1_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
ADC_DelSig_1_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
ADC_DelSig_1_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
ADC_DelSig_1_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
ADC_DelSig_1_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
ADC_DelSig_1_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
ADC_DelSig_1_theACLK__INDEX EQU 0x00
ADC_DelSig_1_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
ADC_DelSig_1_theACLK__PM_ACT_MSK EQU 0x01
ADC_DelSig_1_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
ADC_DelSig_1_theACLK__PM_STBY_MSK EQU 0x01

; adc_threshold
adc_threshold__0__INTTYPE EQU CYREG_PICU6_INTTYPE2
adc_threshold__0__MASK EQU 0x04
adc_threshold__0__PC EQU CYREG_PRT6_PC2
adc_threshold__0__PORT EQU 6
adc_threshold__0__SHIFT EQU 2
adc_threshold__AG EQU CYREG_PRT6_AG
adc_threshold__AMUX EQU CYREG_PRT6_AMUX
adc_threshold__BIE EQU CYREG_PRT6_BIE
adc_threshold__BIT_MASK EQU CYREG_PRT6_BIT_MASK
adc_threshold__BYP EQU CYREG_PRT6_BYP
adc_threshold__CTL EQU CYREG_PRT6_CTL
adc_threshold__DM0 EQU CYREG_PRT6_DM0
adc_threshold__DM1 EQU CYREG_PRT6_DM1
adc_threshold__DM2 EQU CYREG_PRT6_DM2
adc_threshold__DR EQU CYREG_PRT6_DR
adc_threshold__INP_DIS EQU CYREG_PRT6_INP_DIS
adc_threshold__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU6_BASE
adc_threshold__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
adc_threshold__LCD_EN EQU CYREG_PRT6_LCD_EN
adc_threshold__MASK EQU 0x04
adc_threshold__PORT EQU 6
adc_threshold__PRT EQU CYREG_PRT6_PRT
adc_threshold__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
adc_threshold__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
adc_threshold__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
adc_threshold__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
adc_threshold__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
adc_threshold__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
adc_threshold__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
adc_threshold__PS EQU CYREG_PRT6_PS
adc_threshold__SHIFT EQU 2
adc_threshold__SLW EQU CYREG_PRT6_SLW

; Miscellaneous
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
    ENDIF
    END
