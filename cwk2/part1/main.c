
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"
#include "endGame.h"
#include "playGame.h"

/*
 * main function: program entry point
 */

int main() {

  Game *game; // pointer for the game structure

  // allocate memory and assign starting values to the structure
  
  printf("player");
  game = initGame(3,3);
  // play a full game
  playGame(game); 


  free( game ); // free heap memory that was used

  return 0;
}

