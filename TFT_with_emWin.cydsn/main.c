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
#include "tft.h"

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
    CALIBRATE,
    RESET
}; 

struct Notes
{
    const char *name;
    int offset;             //fft offset from midde C/C4
    int key_num;            //key number on piano, TODO: use less memory by changing from strings to key numbers
};

//https://stackoverflow.com/questions/47880223/how-to-programmatically-map-integers-to-const-strings
struct Notes notes[] = {
    { .offset = 0,  .name = "G5", .key_num = 59},
    { .offset = 0,  .name = "F#5", .key_num = 58},
    { .offset = 0,  .name = "F5", .key_num = 57},
    { .offset = 0,  .name = "E5", .key_num = 56},
    { .offset = 0,  .name = "D#5", .key_num = 55},
    { .offset = 0,  .name = "D5", .key_num = 54},
    { .offset = 0,  .name = "C#5", .key_num = 53},
    { .offset = 0,  .name = "C5", .key_num = 52},
    { .offset = 0,  .name = "B4", .key_num = 51},
    { .offset = 0,  .name = "A#4", .key_num = 50},
    { .offset = 0,  .name = "A4", .key_num = 49},
    { .offset = 0,  .name = "G#4", .key_num = 48},
    { .offset = 0,  .name = "G4", .key_num = 47},
    { .offset = 0,  .name = "F#4", .key_num = 46},
    { .offset = 0,  .name = "F4", .key_num = 45},
    { .offset = 0,  .name = "E4", .key_num = 44},
    { .offset = 0,  .name = "D#4", .key_num = 43},
    { .offset = 0,  .name = "D4", .key_num = 42},
    { .offset = 0,  .name = "C#4", .key_num = 41},
    { .offset = 0,  .name = "C4", .key_num = 40},
    { .offset = 0,  .name = "B3", .key_num = 39},
    { .offset = 0,  .name = "A#3", .key_num = 38},
    { .offset = 0,  .name = "A3", .key_num = 37},
    { .offset = 0,  .name = "G#3", .key_num = 36},
    { .offset = 0,  .name = "G3", .key_num = 35},
    { .offset = 0,  .name = "F#3", .key_num = 34},
    { .offset = 0,  .name = "F3", .key_num = 33},
    { .offset = 0,  .name = "E3", .key_num = 32},
    { .offset = 0,  .name = "D#3", .key_num = 31},
    { .offset = 0,  .name = "D3", .key_num = 30},
    { .offset = 0,  .name = "C#3", .key_num = 29},
    { .offset = 0,  .name = "C3", .key_num = 28},
    { .offset = 0,  .name = "B2", .key_num = 27},
    { .offset = 0,  .name = "A#2", .key_num = 26},
    { .offset = 0,  .name = "A2", .key_num = 25},
    { .offset = 0,  .name = "G#2", .key_num = 24},
    { .offset = 0,  .name = "G2", .key_num = 23},
    { .offset = 0,  .name = "F#2", .key_num = 22},
    { .offset = 0,  .name = "F2", .key_num = 21},
    { .offset = 0,  .name = "E2", .key_num = 20},
    { .name = NULL }
};

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
    {"G3", "G3", "D4", "D4", "E4", "E4", "D4",
     "C4", "C4", "B3", "B3", "A3", "A3", "G3",
     "D4", "D4", "C4", "C4", "B3", "B3", "A3",
     "D4", "D4", "C4", "C4", "B3", "B3", "A3",
     "G3", "G3", "D4", "D4", "E4", "E4", "D4",
     "C4", "C4", "B3", "B3", "A3", "A3", "G3",
    };

const int SONGS_LENGTH = 2;
struct Songs songs[] = {
    { .song_number = 0, .name = "Fur Elise", .note_seq = SONG0_SEQ, .song_length = 85},
    { .song_number = 1, .name = "Twinkle, Twinkle,\nLittle Star", .note_seq = SONG1_SEQ, .song_length = 42}
};

void MainTask(void);
void drawClefs(void);
void drawNote(char* input_name);
const char* getNoteName(int input_offset);
void drawStartScreen(void);
int drawSongSelection(void);
void drawPlaySong(int song_index);
int detectNote(void);

int main()
{
    CyGlobalIntEnable;                      // Enable global interrupts
    SPIM_1_Start();                         // initialize SPIM component 
    GUI_Init();                             // initilize graphics library

    int state = START;

    for(;;) {
        switch (state) {
            case START: // draw start screen
                drawStartScreen();
                state = MODE_SELECT;
                break;
            case MODE_SELECT: // wait for mode selection
                if (!SW2_Read()) {
                    while(!SW2_Read());
                    state = SONG_SELECT;
                } else if (!SW3_Read()) {
                    while(!SW3_Read());
                    state = CALIBRATE;
                }
                break;
            case SONG_SELECT: // draw song selection and song
                drawPlaySong(drawSongSelection());
                state = START;
                break;
            case CALIBRATE: // calibrate
                state = START;
                break;
            default: // reset if unexpected state
                state = START;
                break;
        }
    }                             
}

void MainTask()
{
    /// Function: Display Each Note (for testing purposes)
    // GUI_SetBkColor(GUI_WHITE);
    // GUI_SetColor(GUI_BLACK);
    // GUI_Clear();
    // char *note_names[] = 
    //     {"G5", "F#5", "F5", "E5", "D#5", "D5", "C#5", "C5",
    //      "B4", "A#4", "A4", "G#4", "G4", "F#4", "F4", "E4",
    //      "D#4", "D4", "C#4", "C4", "B3", "A#3", "A3", "G#3",
    //      "G3", "F#3", "F3", "E3", "D#3", "D3", "C#3", "C3", 
    //      "B2", "A#2", "A2", "G#2", "G2", "F#2", "F2", "E2"};
    
    // int i = 0;
    // for(;i < 40; i++) {
    //     GUI_Clear();
    //     drawClefs();
    //     drawNote(note_names[i]);
    //     CyDelay(1000);
    // }
    ///
}

const char* getNoteName(int input_offset)
{
    struct Notes *current = notes;
    const char *note = "Unrecognized note";

    while (current->name) {
        if (current->offset == input_offset) {
                note = current->name;
                break;
        }
        ++current;
    }

    return note;
}

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
    GUI_SetFont(&GUI_Font24B_ASCII);

    sprintf(score_buf, "%d", note_index);   //put index into str buffer for displaying score
    GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
    GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
    
    // Display each note after previous is played
    while (SW3_Read()) {
        if (!SW2_Read()) {
            while(!SW2_Read());
            // Erase current note and score drawing
            GUI_SetColor(GUI_WHITE);
            drawNote(cur_song.note_seq[note_index]);
            
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
                // show next note and display score
                GUI_DispStringHCenterAt("Score", SCREEN_WIDTH/2 - 20, 280);
                GUI_DispStringHCenterAt(score_buf, SCREEN_WIDTH/2 + 40, 280);
                drawNote(cur_song.note_seq[note_index]);
            }
        }
    }
}

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
    GUI_DispStringHCenterAt("Song Selected!", SCREEN_WIDTH/2, 320/2);
    CyDelay(500);
    return song_index;
}

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
