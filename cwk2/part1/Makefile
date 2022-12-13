
# code details

EXE = ./bin/tictactoe
SRC = main.c endGame.c initGame.c playGame.c            # ** list source code here **
OBJ = main.o endGame.o initGame.o playGame.o            # ** list object code here **

# generic build details

CC     = gcc
CFLAGS = -std=c99 -Wall
CLIBS  = 
CLINK  = -lm

# compile to object code

%.o: %.c
	$(CC) -c $(CFLAGS) $(CLIBS) $< -o $@

# build executable: type 'make'

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

# clean up and remove object code and executable: type 'make clean'

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c game.c game.h initGame.c initGame.h endGame.c endGame.h game.c  
initGame.o: initGame.c initGame.h game.h
endGame.o: endGame.c endGame.h game.h
playGame.o: playGame.c playGame.h game.h
game.o: game.h

