
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "endGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main( int argc, char *argv[] ) {

  Game *game; // pointer for the game structure

  // allocate memory and assign starting values to the structure
  
  printf("player");

  // play a full game
  initGame(game, 3); 
  playGame(game); 


  free( game ); // free heap memory that was used

  return 0;
}

