#ifndef PIECES_H
#define PIECES_H

#include "Piece.h"
#include <string>
#include <vector>
using namespace std;

class PieceS : public Piece
{
	public:
		PieceS();
		PieceS(int x, int y);
		vector<int*> get_moves(int** map); // return available moves (solid moves down)
		~PieceS();
};


#endif