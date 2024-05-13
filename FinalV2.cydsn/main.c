/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include "GUI.h"
#include "arm_math.h"
#include <arm_const_structs.h>
#include "tft.h"
#include "math.h"

char test_string[16]; // TODO: remove, for writing test values to for display
/* ------------------------------------------------------------------
* Global variables for LEDs
* ------------------------------------------------------------------- */
#define LED_NUM 144
//Allocate an array for LED_NUM NeoPixels
unsigned char pPixelArray[LED_NUM*3];
//Set up some variables for animation code
float power = 1;
float Deltapower = 0.005;
float offset = 0;

void clearLEDs(void);
void setPixel(int i, int r, int b, int g);

/* ------------------------------------------------------------------
* Global variables for FFT Bins
* ------------------------------------------------------------------- */
uint32_t adcResult = 0;
#define TEST_LENGTH_SAMPLES 2048
uint32_t fftSize = 1024;            // number of bins
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
arm_cfft_instance_f32 varInstCfftF32;
uint32_t testIndex = 0;
int middle_c_bin = 988;

float32_t testInput[TEST_LENGTH_SAMPLES];
float32_t testOutput[TEST_LENGTH_SAMPLES/2];
int detectNote(void);

/* ------------------------------------------------------------------
* Global variables for TFT Display
* ------------------------------------------------------------------- */
#define TOP_MARGIN 20
#define SCREEN_WIDTH 240
#define RIGHT_MARGIN SCREEN_WIDTH - TOP_MARGIN
#define BAR_SPACING 15
#define NOTE_SPACING BAR_SPACING/2
#define BETWEEN_CLEFS BAR_SPACING*3
#define LINE_NUM 5
#define LOWER_OFFSET BAR_SPACING*LINE_NUM + BETWEEN_CLEFS
#define NOTE_WIDTH 12
#define NOTE_HEIGHT 8
enum States {
    START,
    MODE_SELECT,
    SONG_SELECT,
    SONG_DONE,
    CALIBRATE_SETUP,
    CALIBRATE,
    RESET,
    TESTING
}; 

void testFunction(void);
void drawClefs(void);
void drawNote(char* input_name);
void setNote(char* input_name, int r, int g, int b);
void detectAndDrawNote(void);
char* getNoteName(int input_offset);
void drawStartScreen(void);
void drawCalibrateScreen(void);
int drawSongSelection(void);
void drawPlaySong(int song_index);

// name: english name of note
// offset: frequency_bin - middle_c_frequencybin
// key_num: key number of note
// led_unms: led indexes associated with note
//Reference: https://stackoverflow.com/questions/47880223/how-to-programmatically-map-integers-to-const-strings
struct Notes
{
    const char *name;
    int offset;             //fft offset from midde C/C4
    int key_num;            //key number on piano, TODO: use less memory by changing from strings to key numbers
    int led_nums[2];
};

struct Notes notes[] = {
    { .offset = -179,  .name = "G5", .key_num = 59, .led_nums = {99, 100}},
    { .offset = -66,  .name = "F#5", .key_num = 58, .led_nums = {97, 98}},
    { .offset = -60,  .name = "F5", .key_num = 57, .led_nums = {95, 96}},
    { .offset = -54,  .name = "E5", .key_num = 56, .led_nums = {93, 94}},
    { .offset = -49,  .name = "D#5", .key_num = 55, .led_nums = {91, 92}},
    { .offset = -44,  .name = "D5", .key_num = 54, .led_nums = {89, 90}},
    { .offset = -40,  .name = "C#5", .key_num = 53, .led_nums = {87, 88}},
    { .offset = -36,  .name = "C5", .key_num = 52, .led_nums = {85, 86}},
    { .offset = -32,  .name = "B4", .key_num = 51, .led_nums = {83, 84}},
    { .offset = -28,  .name = "A#4", .key_num = 50, .led_nums = {82, 0}},
    { .offset = -24,  .name = "A4", .key_num = 49, .led_nums = {80, 0}},
    { .offset = -21,  .name = "G#4", .key_num = 48, .led_nums = {78, 0}},
    { .offset = -18,  .name = "G4", .key_num = 47, .led_nums = {76, 77}},
    { .offset = -15,  .name = "F#4", .key_num = 46, .led_nums = {74, 0}},
    { .offset = -12,  .name = "F4", .key_num = 45, .led_nums = {72, 73}},
    { .offset = -9,  .name = "E4", .key_num = 44, .led_nums = {70 ,71}},
    { .offset = -7,  .name = "D#4", .key_num = 43, .led_nums = {68, 69}},
    { .offset = -4,  .name = "D4", .key_num = 42, .led_nums = {66, 67}},
    { .offset = -2,  .name = "C#4", .key_num = 41, .led_nums = {64, 65}},
    { .offset = 0,  .name = "C4", .key_num = 40, .led_nums = {62, 63}},   // Middle C, 988 Hz
    { .offset = 2,  .name = "B3", .key_num = 39, .led_nums = {60, 61}},
    { .offset = 4,  .name = "A#3", .key_num = 38, .led_nums = {58, 59}},
    { .offset = 7,  .name = "A3", .key_num = 37, .led_nums = {56, 57}},
    { .offset = 9,  .name = "G#3", .key_num = 36, .led_nums = {55, 0}},
    { .offset = 12,  .name = "G3", .key_num = 35, .led_nums = {53, 0}},
    { .offset = 15,  .name = "F#3", .key_num = 34, .led_nums = {51, 0}},
    { .offset = 18,  .name = "F3", .key_num = 33, .led_nums = {49, 50}},
    { .offset = 21,  .name = "E3", .key_num = 32, .led_nums = {47, 48}},
    { .offset = 24,  .name = "D#3", .key_num = 31, .led_nums = {45, 46}},
    { .offset = 28,  .name = "D3", .key_num = 30, .led_nums = {43, 44}},
    { .offset = 32,  .name = "C#3", .key_num = 29, .led_nums = {41, 0}},
    { .offset = 36,  .name = "C3", .key_num = 28, .led_nums = {39, 40}},
    { .offset = 40,  .name = "B2", .key_num = 27, .led_nums = {37, 38}},
    { .offset = 44,  .name = "A#2", .key_num = 26, .led_nums = {35, 0}},
    { .offset = 49,  .name = "A2", .key_num = 25, .led_nums = {33, 34}},
    { .offset = 54,  .name = "G#2", .key_num = 24, .led_nums = {31, 32}},
    { .offset = 60,  .name = "G2", .key_num = 23, .led_nums = {29, 30}},
    { .offset = 66,  .name = "F#2", .key_num = 22, .led_nums = {27, 28}},
    { .offset = -179,  .name = "F2", .key_num = 21, .led_nums = {25, 26}},
    { .offset = -201,  .name = "E2", .key_num = 20, .led_nums = {23, 24}},
    { .name = NULL }
};

// song_number: index of song in songs array
// name: English name of song
// note_seq: array of names of notes in song
// song_length: number of note names in song
struct Songs
{
    const int song_number;
    const char *name;
    const char **note_seq;
    const int song_length;
};

const char *SONG0_SEQ[] = 
    {"E5", "D#5", "E5", "D#5", "E5", "B4", "D5", "C5",
     "A4", "C4", "E4", "A4", "B4", "E4", "G#4", "B4",
     "C5", "E4", "E5", "D#5", "E5", "D#5", "E5", "B4", "D5", "C5", "A4", "C4", "E4", "A4",
     "B4", "E4", "C5", "B4", "A4", "B4", "C5", "D5",
     "E5", "G4", "F5", "E5", "D5", "F4", "E5", "D5", "C5", "E4", "D5", "C5",
     "B4", "E5", "D#5", "E5", "D#5", "E5", "B4", "D5", "C5", "A4", "C4", "E4", "A4",
     "B4", "E4", "G#4", "B4", "C5", "E4", "E5", "D#5", "E5", "D#5", "E5", "B4", "D5", "C5",
     "A4", "C4", "E4", "A4", "B4", "E4", "C5", "A4"
    };
const char *SONG1_SEQ[] = 
    {"C4", "C4", "G4", "G4", "A4", "A4", "G4",
     "F4", "F4", "E4", "E4", "D4", "D4", "C4",
     "G4", "G4", "F4", "F4", "E4", "E4", "D4",
     "G4", "G4", "F4", "F4", "E4", "E4", "D4",
     "C4", "C4", "G4", "G4", "A4", "A4", "G4",
     "F4", "F4", "E4", "E4", "D4", "D4", "C4"
    };

const int SONGS_LENGTH = 2;
struct Songs songs[] = {
    { .song_number = 0, .name = "Fur Elise", .note_seq = SONG0_SEQ, .song_length = 85},
    { .song_number = 1, .name = "Twinkle, Twinkle,\nLittle Star", .note_seq = SONG1_SEQ, .song_length = 42}
};

int main()
{
    // Setup of hardware components
    CyGlobalIntEnable;                      // Enable global interrupts
    ADC_DelSig_1_Start();				    // start the ADC_DelSig_1
    ADC_DelSig_1_StartConvert();		    // start the ADC_DelSig_1 conversion
    SPIM_1_Start();                         // initialize SPIM component 
    GUI_Init();                             // initilize graphics library
    NP_Start(LED_NUM, pPixelArray, 12.8);   //Start the NeoPixel component (LED_NUM pix, User array, 12.8 MHz base clock)

    int state = START;

    // Main loop, state machine
    for(;;) {
        switch (state) {
            case START: // draw start screen
                clearLEDs();
                drawStartScreen();
                state = MODE_SELECT;    // TODO: switch back to Mode_select
                break;
            case MODE_SELECT: // wait for user to select mode
                if (!SW2_Read()) {
                    while(!SW2_Read());
                    state = SONG_SELECT;
                } else if (!SW3_Read()) {
                    while(!SW3_Read());
                    state = CALIBRATE_SETUP;
                }
                break;
            case SONG_SELECT: // draw song selection and song
                drawPlaySong(drawSongSelection());
                state = SONG_DONE;
                break;
            case SONG_DONE: // wait for user to press SW3 after song is done
                if (!SW3_Read()) {
                    while(!SW3_Read());
                    state = START;
                }
                break;
            case CALIBRATE_SETUP: // draws calibrate screen
                drawCalibrateScreen();
                setPixel(63, 0, 100, 100);      //leds associated with middle C
                setPixel(62, 0, 100, 100);
                NP_Update();
                state = CALIBRATE;
                break;
            case CALIBRATE: // calibrate
                middle_c_bin = detectNote();
                
                GUI_SetBkColor(GUI_WHITE);
                GUI_SetColor(GUI_BLACK);
                GUI_SetFont(&GUI_Font24B_ASCII);
                GUI_Clear();
                
                sprintf(test_string, "Middle C Bin\n%d", middle_c_bin);
                GUI_DispStringHCenterAt(test_string, 120, 160);
                   
                setPixel(63, 0, 0, 0);
                setPixel(62, 0, 0, 0);
                NP_Update();
                state = START;
                break;
            case TESTING: // for switching to testing mode
                testFunction();
                break;
            default: // reset to start screen if unexpected state
                state = START;
                break;
        }
    }                             
}

// Called in TESTING mode for testing functionaliy of various systems
void testFunction()
{
    // Function: Display Each Note (for testing purposes)
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_Clear();

    struct Notes *cur_note = notes;
    const char *note = "Unrecognized note";

    while (cur_note->name) {
        GUI_Clear();
        drawClefs();
        drawNote(cur_note->name);

        setPixel(cur_note->led_nums[0], 0, 100, 100);
        setPixel(cur_note->led_nums[1], 0, 100, 100);
        NP_Update();
        CyDelay(1000);
        setPixel(cur_note->led_nums[0], 0, 0, 0);
        setPixel(cur_note->led_nums[1], 0, 0, 0);
        NP_Update();
        ++cur_note;
    }

    return note;
}

// Function: Wait for a note to be played, then display the note on clefs
void detectAndDrawNote() {
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_Clear();
    drawClefs();
    drawNote(getNoteName(detectNote() - middle_c_bin));
}

// Function: Turn off all LEDs on the strip
void clearLEDs(void){
    for(int i = 0; i < LED_NUM; i++) {
        setPixel(i, 0, 0, 0);
    }
    NP_Update();

}

// Function: Given name of a note, sets the associated LEDs to the given color and updates
// Inputs: input_name: name of note, r: red component, g: green component, b: blue component
void setNote(char* input_name, int r, int g, int b) {
    struct Notes *cur_note = notes;
    while (cur_note->name) {
        if (strcmp(cur_note->name, input_name) == 0) {
            if (cur_note->led_nums[0] != 0) setPixel(cur_note->led_nums[0], r, g, b);
            if (cur_note->led_nums[1] != 0) setPixel(cur_note->led_nums[1], r, g, b);
            NP_Update();
            break;
        }
        ++cur_note;
    }

}

// Function: Given index of an LED, sets the associated LEDs to the given color
// Inputs: i: index of LED, r: red component, g: green component, b: blue component
void setPixel(int i, int r, int g, int b) {
    //Compute Green Component
    pPixelArray[i*3] = g;
    //Compute Red Component
    pPixelArray[1+i*3] = r;
    //Compute Blue Component
    pPixelArray[2+i*3] = b;
}

// Function: Waits for a note to be played, then 
// Returns: int, which is the offset from middle C
int detectNote() {
    int fft_start = 0;
    uint16_t i = 0;

    while (SW3_Read()) {
        if(ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT) )
        {
            adcResult = ADC_DelSig_1_GetResult32();		// read the adc and assign the value adcResult 
            
            // if the adc is above a certain threshold, start sampling for fft
            if (adcResult > 36000 || adcResult < 30000) {
                adc_threshold_Write(1);
                fft_start = 1;
            }
            
            if (fft_start) {
                testInput[i] = adcResult;
                i++;
            
                if (i > 2047) {
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
                    
                    i = 0;
                    adc_threshold_Write(0);
                    fft_start = 0;
                    CyDelay(250);									// delay in milliseconds
                    return testIndex;
                }
            }
        }
    }
}

// Function: Given offset of frequency bin from middle C, determines note name
// Inputs: input_offset offset from middle C
// Returns: char*, which is the name of the note
char* getNoteName(int input_offset)
{
    struct Notes *cur_note = notes;
    const char *note = "Unrecognized note";

    while (cur_note->name) {
        if (cur_note->offset == input_offset) {
                note = cur_note->name;
                break;
        }
        ++cur_note;
    }

    return note;
}

// Function: Given a song index, displays each note in the song and waits for the note to be played
void drawPlaySong(int song_index) {
    // Setup
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_VCENTER); // Bug: GUI_TA_HCENTER fails to center text horizontally

    GUI_Clear();
    drawClefs();
    
    int note_index = 0;
    char score_buf[3];
    struct Songs cur_song = songs[song_index];
    
    // Display first note
    drawNote(cur_song.note_seq[note_index]);
    setNote(cur_song.note_seq[note_index], 0, 0, 100);
    GUI_SetFont(&GUI_Font24B_ASCII);

    sprintf(score_buf, "%d", note_index);   //put index into str buffer for displaying score
    GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
    GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
    
    // Exits playing if SW3 is pressed
    while (SW3_Read()) {
        // Detect if note is played
        // If correct note, flash LEDs green, then move onto the next note
        if (strcmp(getNoteName(detectNote() - middle_c_bin), cur_song.note_seq[note_index]) == 0) {
            while(!SW2_Read());
            // flash LEDs green
            setNote(cur_song.note_seq[note_index], 0, 100, 0);
            CyDelay(50);

            // Erase current note and score drawing, turn off associated leds
            GUI_SetColor(GUI_WHITE);
            drawNote(cur_song.note_seq[note_index]);
            clearLEDs();
            
            GUI_SetFont(&GUI_Font24B_ASCII);
            GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
            GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
            
            // Redraw clefs
            GUI_SetColor(GUI_BLACK);
            drawClefs();
            
            // Determine next note
            note_index++;
            sprintf(score_buf, "%d", note_index);   //put index into str buffer for displaying score
            
            if (note_index >= cur_song.song_length) {
                // print final score then exit playing mode
                GUI_DispStringHCenterAt("Well Done!", SCREEN_WIDTH/2, 240);
                GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
                GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
                break;
            } else {
                // show next note and display score, turn on associated leds
                GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
                GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
                drawNote(cur_song.note_seq[note_index]);
                setNote(cur_song.note_seq[note_index], 0, 0, 100);
            }
        } else {
            // If incorrect note, flash LEDs red, then let user try again
            setNote(cur_song.note_seq[note_index], 100, 0, 0);
            CyDelay(50);
            setNote(cur_song.note_seq[note_index], 0, 0, 100);
        }
    }
}

// Function: Displays and controls user interface associated with song selection
int drawSongSelection(){
    // Setup
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_SetFont(&GUI_Font16B_ASCII);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_VCENTER); // Bug: GUI_TA_HCENTER fails to center text horizontally
    
    GUI_Clear();

    // Display page title + first song name
    int song_index = 0;
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_DispStringHCenterAt("Song Selection", SCREEN_WIDTH/2, 20);
    
    GUI_SetFont(&GUI_Font16B_ASCII);
    GUI_DispStringHCenterAt("Press SW2 for next option.", SCREEN_WIDTH/2,60);
    GUI_DispStringHCenterAt("Press SW3 to confirm selection.", SCREEN_WIDTH/2,80);
    
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_DispStringHCenterAt(songs[song_index].name, SCREEN_WIDTH/2, 320/2);
    
    // Wait for song to be selected
    while (SW3_Read()) {
        // Cycle to next song when SW3 pressed
        if (!SW2_Read()) {
            song_index++;
            song_index %= SONGS_LENGTH;
            GUI_SetColor(GUI_GetBkColor());
            GUI_FillRect(0, 100, 240, 300);
            GUI_SetColor(GUI_BLACK);
            GUI_DispStringHCenterAt(songs[song_index].name, SCREEN_WIDTH/2, 160);
        }   
    }
    
    while (!SW3_Read())

    //Song Selection Confirmation
    GUI_Clear();
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_DispStringHCenterAt("Song Selected!\nPlay the keys as\nthey are shown!", SCREEN_WIDTH/2, 100);
    CyDelay(500);
    return song_index;
}

// Function: Displays buttons and text of calibrate screen
void drawCalibrateScreen(){
    // Setup
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_SetFont(&GUI_Font20B_ASCII);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_VCENTER); // Bug: GUI_TA_HCENTER fails to center text horizontally
    
    GUI_Clear();

    GUI_DispStringHCenterAt("Line up lit LEDs over\nthe middle C key.\nThen, play it.", SCREEN_WIDTH/2, 120);
}

// Function: Displays buttons and text of start screen
void drawStartScreen(){
    // Setup
    GUI_SetBkColor(GUI_WHITE);
    GUI_SetColor(GUI_BLACK);
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_VCENTER); // Bug: GUI_TA_HCENTER fails to center text horizontally
    
    GUI_Clear();

    GUI_DispStringHCenterAt("Welcome to\nPiano Tiles!", SCREEN_WIDTH/2, 40);

    // Button 1: Play
    GUI_SetColor(GUI_GREEN);
    GUI_FillRoundedRect(40, 120, 200, 200, 10);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt("Play", SCREEN_WIDTH/2, 160);

    // Button 2: Calibrate
    GUI_SetColor(GUI_BLUE);
    GUI_FillRoundedRect(40, 220, 200, 300, 10);
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt("Calibrate", SCREEN_WIDTH/2, 260);
}

// Function: Given a note name, displays the note without clefs
void drawNote(char* input_name){
    // Center text and set size
    GUI_SetFont(&GUI_Font32B_ASCII);
    GUI_SetTextMode(GUI_TM_TRANS);
    GUI_SetTextAlign(GUI_TA_HCENTER | GUI_TA_VCENTER);
    
    int text_x = SCREEN_WIDTH/2;
    int text_y = 240;
    
    if (strcmp(input_name, "G5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN - NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G5", text_x, text_y);
    } else if (strcmp(input_name, "F#5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F#5", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN);
    } else if (strcmp(input_name, "F5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F5", text_x, text_y);
    } else if (strcmp(input_name, "E5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("E5", text_x, text_y);
    } else if (strcmp(input_name, "D#5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 2*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D#5", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 2*NOTE_SPACING);
    } else if (strcmp(input_name, "D5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 2*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D5", text_x, text_y);
    } else if (strcmp(input_name, "C#5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 3*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C#5", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 3*NOTE_SPACING);
    } else if (strcmp(input_name, "C5") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 3*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C5", text_x, text_y);
    } else if (strcmp(input_name, "B4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 4*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("B4", text_x, text_y);
    } else if (strcmp(input_name, "A#4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 5*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A#4", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 5*NOTE_SPACING);
    } else if (strcmp(input_name, "A4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 5*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A4", text_x, text_y);
    } else if (strcmp(input_name, "G#4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 6*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G#4", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 6*NOTE_SPACING);
    } else if (strcmp(input_name, "G4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 6*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G4", text_x, text_y);
    } else if (strcmp(input_name, "F#4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 7*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F#4", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 7*NOTE_SPACING);
    } else if (strcmp(input_name, "F4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 7*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F4", text_x, text_y);
    } else if (strcmp(input_name, "E4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 8*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("E4", text_x, text_y);
    } else if (strcmp(input_name, "D#4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 9*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D#4", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 9*NOTE_SPACING);
    } else if (strcmp(input_name, "D4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 9*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D4", text_x, text_y);
    } else if (strcmp(input_name, "C#4") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 10*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C#4", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, TOP_MARGIN + 10*NOTE_SPACING);
    } else if (strcmp(input_name, "C4") == 0) { //Middle C
        GUI_FillEllipse(SCREEN_WIDTH/2, TOP_MARGIN + 10*NOTE_HEIGHT, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C4", text_x, text_y);
    } else if (strcmp(input_name, "B3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET - NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("B3", text_x, text_y);
    } else if (strcmp(input_name, "A#3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A#3", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET);
    } else if (strcmp(input_name, "A3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A3", text_x, text_y);
    } else if (strcmp(input_name, "G#3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G#3", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + NOTE_SPACING);
    } else if (strcmp(input_name, "G3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G3", text_x, text_y);
    } else if (strcmp(input_name, "F#3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 2*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F#3", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + 2*NOTE_SPACING);
    } else if (strcmp(input_name, "F3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 2*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F3", text_x, text_y);
    } else if (strcmp(input_name, "E3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 3*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("E3", text_x, text_y);
    } else if (strcmp(input_name, "D#3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 4*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D#3", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + 4*NOTE_SPACING);
    } else if (strcmp(input_name, "D3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 4*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("D3", text_x, text_y);
    } else if (strcmp(input_name, "C#3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 5*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C#3", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + 5*NOTE_SPACING);
    } else if (strcmp(input_name, "C3") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 5*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("C3", text_x, text_y);
    } else if (strcmp(input_name, "B2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 6*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("B2", text_x, text_y);
    } else if (strcmp(input_name, "A#2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 7*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A#2", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + 7*NOTE_SPACING);
    } else if (strcmp(input_name, "A2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 7*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("A2", text_x, text_y);
    } else if (strcmp(input_name, "G#2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 8*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G#2", text_x, text_y);
    } else if (strcmp(input_name, "G2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 8*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("G2", text_x, text_y);
    } else if (strcmp(input_name, "F#2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 9*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F#2", text_x, text_y);

        GUI_SetFont(&GUI_Font24B_ASCII);
        GUI_DispStringAt("#", SCREEN_WIDTH/2 + 2*NOTE_WIDTH, LOWER_OFFSET + 9*NOTE_SPACING);
    } else if (strcmp(input_name, "F2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 9*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("F2", text_x, text_y);
    } else if (strcmp(input_name, "E2") == 0) {
        GUI_FillEllipse(SCREEN_WIDTH/2, LOWER_OFFSET + 10*NOTE_SPACING, NOTE_WIDTH, NOTE_HEIGHT);
        GUI_DispStringAt("E2", text_x, text_y);
    } else {
        GUI_DispStringAt("Invalid!", text_x, text_y);
    }
}

// Function: Displays the clefs on the screen
void drawClefs(){
    int i;
    for (i = 0; i < LINE_NUM; i++) {
        // Draw treble clef lines
        GUI_DrawRect(TOP_MARGIN, i*BAR_SPACING + TOP_MARGIN, RIGHT_MARGIN, i*BAR_SPACING + TOP_MARGIN + 1);
        // Draw bass clef lines
        GUI_DrawRect(TOP_MARGIN, LOWER_OFFSET + i*BAR_SPACING, RIGHT_MARGIN, LOWER_OFFSET + i*BAR_SPACING + 1);
    }
}

/* [] END OF FILE */