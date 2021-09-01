#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <vector>
using namespace std;

class Piece
{
	public:
		Piece();
		Piece(int x, int y,int player);
		static int currentID;

		int team; // -1 = solid, 1 = hollow
		int *position = new int[2]; // store the position as a coordinate pointer
		int id;// store an id
		
		int* get_position(); // return the position of the piece

		virtual vector<int*> get_moves(int** map); //return valid moves

		void move(int x, int y); // move piece
		
		void upgrade(); // destroy the piece and create a king piece

		~Piece();
};

#endif