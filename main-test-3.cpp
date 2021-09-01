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
	game.piece_list.push_back(new PieceS(6,3));
	game.piece_list.push_back(new PieceS(2,5));	// add pieces in custom positions
	game.piece_list.push_back(new PieceS(0,3));
	game.piece_list.push_back(new PieceS(2,3));
	game.piece_list.push_back(new PieceS(3,2));
	game.piece_list.push_back(new PieceS(6,1));
	
	game.update_board();
	
 	
 	
	for(int i=0;i<8;i++){  			// print the board_array for debugging
		for(int j=0;j<8;j++){
			cout << game.board_array[j][i]<< " ";
		}
		cout << endl;
	}


	while(game.won==false){
		game.display();
		game.next_turn();
	}

	for(int i=0;i<game.piece_list.size()-1;i++){
		if(game.piece_list[i]!=NULL){
			delete game.piece_list[i];
		}
	}

	return 0;
}