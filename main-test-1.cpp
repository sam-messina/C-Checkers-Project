#include <iostream>
#include "Board.h"
#include "Piece.h"
#include "PieceH.h"
#include "PieceS.h"
#include <string>

using namespace std;

int main(void){

	Board game;
	
	//game.initialise(); dont initialise the board normally
	
	
	game.piece_list.push_back(new PieceH(3,6));
	game.piece_list.push_back(new PieceS(4,5));
	game.piece_list.push_back(new PieceS(5,4));
	game.piece_list.push_back(new PieceS(2,5));	// add pieces in custom positions

	
	game.update_board();
	
 	
 	
	for(int i=0;i<8;i++){  			// print the board_array for debugging
		for(int j=0;j<8;j++){
			cout << game.board_array[j][i]<< " ";
		}
		cout << endl;
	}


	while(game.won==false){ // loop until the game is finished
		game.display();
		game.next_turn();
	}

	for(int i=0;i<game.piece_list.size()-1;i++){ // delete allocated memory afterwards
		if(game.piece_list[i]!=NULL){
			delete game.piece_list[i];
		}
	}

	return 0;
}