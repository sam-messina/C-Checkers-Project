#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "PieceH.h"
#include <string>

using namespace std;

int main(void){

	Board game;

	game.initialise(); // Put create pieces in the default positions
	game.update_board(); // update the board

	while(game.won==false){ // loop until the game is finished
		game.display();
		game.next_turn();
	}

	for(int i=0;i<game.piece_list.size()-1;i++){ // clear all the dynamically allocated memory
		if(game.piece_list[i]!=NULL){
			delete game.piece_list[i];
		}
	}

	return 0;
}