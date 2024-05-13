//PSOC5 Control for 144 LEDs

#include <project.h>
#include "math.h"
#define LED_NUM 144
//Allocate an array for LED_NUM NeoPixels
unsigned char pPixelArray[LED_NUM*3];
//Set up some variables for animation code
float power = 1;
float Deltapower = 0.005;
float offset = 0;

void setPixel(int i, int r, int b, int g);

//Main function
int main()
{
    //Start the NeoPixel component (LED_NUM pix, User array, 12.8 MHz base clock)
    NP_Start(LED_NUM, pPixelArray, 12.8);
    
    int i;
    for(i = 0; i < LED_NUM; i++) //Update each of the 16 pixels in turn here
    {
        if (i == 80 || i == 81) setPixel(i, 0, i, 144 - i);
        else setPixel(i, 0, 0, 0);
    }
    //Call NeoPixel update function (non blocking) to trigger DMA pixel update
    NP_Update();
 
    //Endless loop...
    for(;;)
    {      
       
       //Delay before next frame
        CyDelay(5);
    }
}

void setPixel(int i, int r, int g, int b) {
    //Compute Green Component
    pPixelArray[i*3] = g;
    //Compute Red Component
    pPixelArray[1+i*3] = r;
    //Compute Blue Component
    pPixelArray[2+i*3] = b;
}