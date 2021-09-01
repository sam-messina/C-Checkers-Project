#include "Piece.h"
#include "PieceS.h"
#include <string>
#include <vector>
#include <iostream>
#include "functions.h"
#include <cstdlib>

using namespace std;

PieceS::PieceS(){
}

PieceS::PieceS(int x,int y){
	
	position[0]=x;
	position[1]=y;

	team = -1;
}

vector<int*> PieceS::get_moves(int** map){
	
	int** board = map; // this is the 2d board_array

	vector<int*> movelist;
	vector<int*> unfinished;		// used to evaluate multiple jumps
	int target_square [2];

	int move_counter=0;			// keeps track of the number of moves

	int* take_list;
	take_list=new int[7];
	for(int i=0;i<7;i++){
		take_list[i]=0;
	}

	unfinished.push_back(position); // start at origin
	// Go back through the unfinished vector, go through all moves

	for(int j=0;j<unfinished.size();j++){ // go through the moves
		//cout << ":::: " << j << endl;
		target_square[0] = unfinished[j][0]-1; // x
		target_square[1] = unfinished[j][1]+1; // y down

		int direction=-1; // -1 is left, 1 is right

		for(int i=0;i<2;i++){ // repeat for left and right
			
				// check the immediate left and right squares
				if(on_board(target_square[0],target_square[1])==true && j==0 && board[target_square[0]][target_square[1]]==0){// check for empty case
						// if hasnt already jumped && move is on the board && space is empty
					
				movelist.push_back(new int[3]);		 
				movelist[move_counter][0]=target_square[0];
				movelist[move_counter][1]=target_square[1];
				movelist[move_counter][2]=0;				// no enemies to delete


				move_counter++;

				}else if(on_board(target_square[0]+direction,target_square[1]+1)==true && board[target_square[0]][target_square[1]]*team < 0 && board[target_square[0]+direction][target_square[1]+1]==0){
				// 					move is on the board &&	there is an enemy on this square && a gap behind

					movelist.push_back(new int[2]);				
					//puts the move into the valid move list
					movelist[move_counter][0]=target_square[0]+direction;
					movelist[move_counter][1]=target_square[1]+1; // down

					take_list[move_counter]=(board[target_square[0]][target_square[1]]);

					unfinished.push_back(movelist[move_counter]);

					move_counter++;
				}
				target_square[0] += 2; // change to check right square

				direction = 1; // change to right side
			
		}
	}

	// put which piece ID's to remove at the end of this vector
	movelist.push_back(take_list);

	return movelist;
}


PieceS::~PieceS(){
}