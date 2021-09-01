#include "Board.h"
#include "Piece.h"
#include "PieceH.h"
#include "PieceS.h"
#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "functions.h"

using namespace std;

Board::Board(){
	// create all the pieces and put them into the array
	int i;

	limit=24;

	//piece_list = new Piece[limit];

	board_array = new int*[8];
	for(i=0;i<8;i++){
		board_array[i]=new int[8];
	}

	turn=1;
	number_of_pieces=0;
	cout << "Board initialised" << endl;
	won = false;
}

void Board::add_piece(Piece *new_piece){
	if(number_of_pieces<limit){ 			// create a new piece and add it to the piece list
		piece_list.push_back(new_piece); 	// note this does not add its position to the board array
		number_of_pieces++; 				// still need the update_board function
	}
}

void Board::update_board(){
	int i,j,piece_x,piece_y;

	for (i=0;i<8;i++){ // clear the board and re draw it
		for(j=0;j<8;j++){
			board_array[i][j]=0;
		}
	}

	// loop through the piece array and put the id into the coordinate in the board array
	for(i=0;i<piece_list.size();i++){
		if(piece_list[i]!=NULL){
			piece_x=piece_list.at(i)->position[0];
			piece_y=piece_list.at(i)->position[1];
			board_array[piece_x][piece_y]=piece_list.at(i)->id*piece_list.at(i)->team;
		}
	}
	// check for Hollow win
	for(i=0;i<8;i++){
		if(board_array[i][0]>0){
			win(1);
		}
	}// check for Solid win
	for(i=0;i<8;i++){
		if(board_array[i][7]<0){
			win(-1);
		}
	}

}

void Board::initialise(){
	
	cout << "Loading..." << endl;
	update_board();


	Piece** piece_pointer;				// make all the solid pieces and use add_piece()
	piece_pointer = new Piece*[24];

	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			if(i==1){
				piece_pointer[i+j] = new PieceS(2*j,i);
			}else{
				piece_pointer[i+j] = new PieceS(2*j+1,i);
			}
			add_piece(piece_pointer[i+j]);
		}
	}
	cout << "Solid Pieces allocated" << endl;

	for(int i=5;i<8;i++){								// make all the hollow pieces
		for(int j=0;j<4;j++){
			if(i==6){
				piece_pointer[i+j] = new PieceH(2*j+1,i);
			}else{
				piece_pointer[i+j] = new PieceH(2*j,i);
			}
			add_piece(piece_pointer[i+j]);
		}
	}
	cout << "Hollow Pieces allocated" << endl;
	
	update_board();
	cout << "Ready!" << endl;
}

int Board::check_position(int x,int y){ // return ID at that location
	return board_array[x][y];
}
void Board::move_piece(Piece* piece_pointer){
	//int moves[][]=piece_pointer->get_moves(); // get the 2d array of available moves
	// display to user available moves
	// get input from the user to pick
	//piece_pointer->move();
}


void Board::display(){
	// go through the board array, print ascii characters based on the number in the array


	int i,j,x,character; // corresponding to ascii set order
	string ascii_set[4] = {" ","█","o","●"}; // {board_black,board_white,piece_black,piece_white}
	string letters[8]={"A","B","C","D","E","F","G","H"};
	// █ ▄ ▀  ░ ▓ ⬛ ▇	▔‾_⎹_⎸

	// piece.team: -1 = solid, 1 = hollow
	

	cout << "  ";
	for(i=0;i<8;i++){ // column lettering
		cout << " " << letters[i] << " ";
	}
	cout << endl;

	for(i=0;i<8;i++){ // y direction
		cout << i+1 << " "; // row numbering
		for(j=0;j<24;j++){ // x direction
			x=floor(j/3);

			if(board_array[x][i]==0 || (j-1)%3!=0){
				if((i+x)%2==0){ // white board square
					cout << ascii_set[1];
				}else{
					cout << ascii_set[0];			// black board square
				}
			}else if((j-1)%3==0){ // if currently drawing the center of a black square check for piece
				if(board_array[x][i]<0){ 
					cout << ascii_set[3]; // white piece
				}
				else{
					cout << ascii_set[2]; // black piece
				}
			}
		}
		cout << "|"<< endl;
	}
	

	cout << "  ";
	for(i=0;i<24;i++){
		cout << "‾" ; // jadding a line underneath the board
	} cout << endl;
}

void Board::next_turn(){
	string input;
	int x=-1,y=-1,current_id;
	bool valid_input=false;
	vector<int*> valid_moves;

	if(turn>0){
		cout <<"--- Hollow Team's Turn ---" << endl << endl;	// declare who's turn it is
	}else{
		cout <<"--- Solid Team's Turn ---" << endl << endl;
	}

	while(valid_input==false){ 					// make sure piece selection is valid
		cout << "Which Piece would you like to move?" << endl;
		cout << "(enter in the form: >> C3)" << endl<<endl;
		cout << ">> ";
		cin >> input;

		// automatically converts string to int char-value
		if(input.length()>=2){
			x=input.at(0)-65; // A = 65
			y=input.at(1)-49; // 0 = 48 use these offsets to get coordinates
		}

		if(on_board(x,y)==true){ // check position is in array range

			// this check is that the piece has the same sign as the turn (select piece of right colour)

			if(check_position(x,y)*turn>0){
				current_id=check_position(x,y);

				current_id=abs(current_id)-1; // get this in terms of piece_list
				
				valid_moves = piece_list[current_id]->get_moves(board_array); // get all the valid moves of this piece

				if(valid_moves.size()>1){ // make sure there is at least 1 valid move
					valid_input=true;
				}
			}
		}
		if(valid_input==false){
			cout << endl << "**Invalid input**" << endl<< endl;
		}

	}

	// reset values
	x=-1;
	y=-1;
	valid_input=false;

	// get move input
	while(valid_input==false){
		cout << endl << "Where would you like to move?" << endl<<endl;
		cout << ">> ";
		cin >> input;

		// automatically converts string to int char-value
		if(input.length()>=2){
			x=input.at(0)-65; // A = 65
			y=input.at(1)-49; // 0 = 48 use these offsets to get coordinates
		}
		
		for(int i=0;i<valid_moves.size()-1;i++){
			if(valid_moves[i][0]==x && valid_moves[i][1]==y){
				valid_input=true;
			}
		}
		if(valid_input==false){
			cout << endl << "**Invalid input**" << endl<< endl;
		}
	}

	// delete pieces by setting their pointer to NULL, so that piece list remains in order
	for(int i=0;i<7;i++){
		if(valid_moves[valid_moves.size()-1][i]!=0){ // if its not zero
			int ID_ = abs(valid_moves[valid_moves.size()-1][i])-1;
			piece_list[ID_]=NULL;
		}
	}
	
	// move piece
	piece_list[current_id]->move(x,y);

	

	turn=turn*(-1); // flip turn to -1

	update_board();

	// DELETE THE VALID MOVE POINTERS
	for(int i=0;i<valid_moves.size()-1;i++){
		delete valid_moves[i];
	}
}

void Board::win(int player){
	if(player>0){
		cout <<endl<<endl<<endl<<"<<<**** Hollow Team Wins!!! ***>>>>" << endl << endl<<endl<<endl;	
		}else{
		cout <<endl<<endl<<endl<<"<<<**** Solid Team Wins!!! ***>>>>" << endl << endl<<endl<<endl;
	}
	won = true;
}

Board::~Board(){
}