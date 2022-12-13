
#include <stdio.h>

#include "game.h"
#include "endGame.h"

/*
 * Functions in this module check for wins and draws
 */

// test all possible ways the game can be won for one player
int winGame( Game *game, char symbol ) {

  // return 1(true) if game is won, 0(false) otherwise
  //
  // You may wish to define further functions to test different win conditions
  // Games can be won with horizontal, vertical or diagonal lines

  // iteration through grid split into three functions
  if(testRows(game,symbol) == 1 || testColumns(game,symbol) == 1 || testDiag(game,symbol) == 1){
    return 1;
  }

  return 0;  // continue
}

// test for a draw
int drawGame( Game *game ) {

  // return 1(true) if game is drawn, 0(false) otherwise

  
  }
}

int testRows(Game *game, char symbol){
  int symbolCount;

  for(int i = 0; i < 3; i++){

  symbolCount = 0;
    // iterate through a row
    for(int k = 0; k < 3; k++){
      if(game->board[i][k] == symbol){
      symbolCount++;
      }
    }

    // full row of symbols found
   int testColumns(Game *game, char symbol){
  int symbolCount;

  for(int i = 0; i < 3; i++){

  symbolCount = 0;
    // iterate through a row
    for(int k = 0; k < 3; k++){
      if(game->board[k][i] == symbol){
      symbolCount++;
      }
    }

    // full row of symbols found
    if(symbolCount == 3){
      // winGame == 1
      return 1;
    }
  }

  
  return 0;
} }
  }

  // 
  return 0;
}

int testColumns(Game *game, char symbol){
  int symbolCount;

  for(int i = 0; i < 3; i++){

  symbolCount = 0;
    // iterate through a row
    for(int k = 0; k < 3; k++){
      if(game->board[k][i] == symbol){
      symbolCount++;
      }
    }

    // full row of symbols found
    if(symbolCount == 3){
      // winGame == 1
      return 1;
    }
  }

  
  return 0;
}
int testDiag(Game *game, char symbol){
  for (int i = )
}

