# PianoTiles4Piano
This project for MIT Course 6.115/6.2060 in Spring 2024 was implmented with a
* CY8CKIT-050 PSoC™ 5LP Development Kit
* 2.8 TFT LCD Display
* 144 Count Addressable LED
* MAX4466 Microphone Module
  
<img width="876" alt="image" src="https://github.com/waterRK9/PianoTiles4Piano/assets/96558257/363e99de-91c4-44a6-982d-1bb314e89515">

This project will demonstrate a system that implements the popular 2014 mobile game “Piano Tiles” on a piano. On the mobile version of “Piano Tiles”, players would tap on black tiles as they scroll down the screen. However, there was no association between the position of the tiles, and the sounds the user heard. This system aims to bridge that gap by integrating the gameplay mechanics of Piano Tiles with an actual piano, creating a tangible and interactive experience for players. Instead of tapping tiles on a screen, users will interact with physical piano keys.

In order accomplish this LED lights and an LCD screen will indicate which notes users should play. This piano tutor system will overlay an LED strip onto an existing piano, and light up LEDs above the specific piano keys that the user should play to generate sound for each note/chord. The LCD screen will display the note that should be played as it would be shown on sheet music. Each step is associated with the sequence of notes/chord in a song. In order to determine whether the player is playing the correct piano keys at the correct time, the system will use a microphone to sample the frequencies of the notes/chords the user plays on the piano, and compare it to the frequencies that the system expects. 

The invidiual example project libraries that were used (TFT_emWin, NeoPixel, SoundDetection) in the development of this project are included.
The final project can be found in FinalV2.
