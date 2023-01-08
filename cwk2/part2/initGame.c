
#include <stdio.h>
#include <stdlib.h>

#include "game.h"
#include "initGame.h"

/*
 * Intialise game data for a new game
 */

Game initGame( int boardSize, int winLength ) {
  printf("initgame");
  

  game->board = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
  game->boardSize = 3;
  game->winLength = 3;
  game->maxTurns = 9;
  game->turns = 0;

  // for incorrect boardSize or winLength you should return a NULL pointer
  if(boardSize != 3 || winLength != 3){
    printf("Incorrect parameter values for board size or win length. Exiting\n");
    return;
  }
  

  // allocate the Game data structure
  // intialise the Game data structure values 
  // board values should be set to '.' (unused location)
  for(int i = 0; i < sizeof())


  return game;
}


