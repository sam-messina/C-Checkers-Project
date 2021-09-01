#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include "Piece.h"
using namespace std;

class Board
{
	public:
		Board(); // create pieces, give them positions, record board array of ID's
		
		vector<Piece*> piece_list; // store an array of all the pieces
		int** board_array; // store a 2d array of the board and piece ID's
		int turn; // either -1 or 1
		int limit;
		int number_of_pieces;
		bool won;

		void add_piece(Piece *new_piece); // add a piece object pointer to the board array

		void initialise(); // create piece objects in standard checkers positions and add them to the board array

		int check_position(int x,int y); // get the desired piece and return availble moves

		void update_board(); // go through the piece array and place ID's in the board array

		void display(); // output what the board currently looks like

		void next_turn(); // go to the next turn

		void move_piece(Piece* piece_pointer); // move a piece 

		void win(int player); // end the game and send a message congratulating the winner

		~Board();
};

#endif