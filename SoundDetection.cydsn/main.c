/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * This file is necessary for your project to build.
 * Please do not delete it.
 *
 * ========================================
*/

#include <project.h>
#include <stdio.h>
#include "arm_math.h"
#include <arm_const_structs.h>
#define TEST_LENGTH_SAMPLES 2048

void DigitLED_Write( int);
void DigitLED_WriteHex( int);
uint32_t adcResult = 0;

/* ------------------------------------------------------------------
* Global variables for FFT Bin Example
* ------------------------------------------------------------------- */
uint32_t fftSize = 1024;            // number of bins
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
arm_cfft_instance_f32 varInstCfftF32;
/* Reference index at which max energy of bin ocuurs */
uint32_t testIndex = 0;

/* -------------------------------------------------------------------
* External Input and Output buffer Declarations for FFT Bin Example
* ------------------------------------------------------------------- */
float32_t testInput[TEST_LENGTH_SAMPLES];
float32_t testOutput[TEST_LENGTH_SAMPLES/2];
    

int detectNote(void);

void main()
{		
	LCD_Char_1_Start();					// initialize lcd
	LCD_Char_1_ClearDisplay();
	//LCD_Char_1_PrintString("ADC : ");
	
	ADC_DelSig_1_Start();				// start the ADC_DelSig_1
	ADC_DelSig_1_StartConvert();		// start the ADC_DelSig_1 conversion
        
    /******** Initialize FFT data **********/
    uint16_t i = 0;

    for(;;)
    {
		detectNote();
    }
}

int detectNote() {
    int fft_start = 0;
    uint16_t i = 0;

    while (1==1) {
        if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT) )
        {
            adcResult = ADC_DelSig_1_GetResult32();		// read the adc and assign the value adcResult 
            
            // if the adc is above a certain threshold, start sampling for fft
            if (adcResult > 36000 || adcResult < 30000) {
                adc_threshold_Write(1);
                i = 0;
                fft_start = 1;
            }
            
            if (fft_start) {
                testInput[i] = adcResult;
                i++;
            
                if (i > 4095) {
                    float32_t maxValue;
                    arm_cfft_init_f32(&varInstCfftF32,fftSize);
                    /* Process the data through the CFFT/CIFFT module */
                    arm_cfft_f32(&varInstCfftF32, testInput, ifftFlag, doBitReverse);
                    /* Process the data through the Complex Magnitude Module for
                    calculating the magnitude at each bin */
                    arm_cmplx_mag_f32(testInput, testOutput, fftSize);
                    /* Calculates maxValue and returns corresponding BIN value */
                    testOutput[0] = 0;
                    arm_max_f32(testOutput, fftSize, &maxValue, &testIndex);
                    
                    LCD_Char_1_ClearDisplay();
        			LCD_Char_1_Position(0, 0);
        			LCD_Char_1_PrintString("!");			    // clean up the previous display
                    
                    char cur_string[16];
                    sprintf(cur_string, "%d", testIndex);
                    LCD_Char_1_PrintString(cur_string);
                   
                    adc_threshold_Write(0);
                    fft_start = 0;
                    CyDelay(500);									// delay in milliseconds
                    return testIndex;
                }
            }
        }
    }
}

/* [] END OF FILE */