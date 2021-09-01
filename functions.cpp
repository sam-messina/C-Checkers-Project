#include "functions.h" // assorted global functions

bool on_board(int x, int y){ // check if an x and y value are on the board
	if(x>-1 && x<8 && y>-1 && y<8){
		return true;
	}
	else{
		return false;
	}
}
