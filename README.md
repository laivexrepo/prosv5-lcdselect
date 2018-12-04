# prosv5-lcdselect

Example program on hos to use the V5 LCD display to select between a variety of Autonomous routines.  It uses the the Legacy LCD Emulator (LLEMU) to achieve this.

The LCD is intialized in the initialize() function and the actual selection routines (dispaly based selection) occurs in the competition_initailize() routine.

The various autonomus routines are defined functions in the autonomous.cpp program file, and caleld based on a selection made on the LCD in the autonomous() function.

The example is on purpose rather verbose as to writing to the LCD to help understand what happens, in production code you will likely want to be a bit less verbose.
