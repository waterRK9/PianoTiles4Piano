# PianoTiles4Piano
This project was implmented with a
*CY8CKIT-050 PSoC™ 5LP Development Kit
*2.8 TFT LCD Display
*144 Count Addressable LED
*MAX4466 Microphone Module

This project will demonstrate a system that implements the popular 2014 mobile game “Piano Tiles” on a piano. On the mobile version of “Piano Tiles”, players would tap on black tiles as they scroll down the screen. However, there was no association between the position of the tiles, and the sounds the user heard. This system aims to bridge that gap by integrating the gameplay mechanics of Piano Tiles with an actual piano, creating a tangible and interactive experience for players. Instead of tapping tiles on a screen, users will interact with physical piano keys.

In order accomplish this LED lights and an LCD screen will indicate which notes users should play. This piano tutor system will overlay an LED strip onto an existing piano, and light up LEDs above the specific piano keys that the user should play to generate sound for each note/chord. The LCD screen will display the note that should be played as it would be shown on sheet music. Each step is associated with the sequence of notes/chord in a song. In order to determine whether the player is playing the correct piano keys at the correct time, the system will use a microphone to sample the frequencies of the notes/chords the user plays on the piano, and compare it to the frequencies that the system expects. 
