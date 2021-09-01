#ifndef PIECEH_H
#define PIECEH_H

#include "Piece.h"
#include <string>
#include <vector>
using namespace std;

class PieceH : public Piece
{
	public:
		PieceH();
		PieceH(int x, int y);
		vector<int*> get_moves(int** map); // return available moves (hollow moves upwards)
		~PieceH();
};


#endif