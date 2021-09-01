#include "Piece.h"
#include "functions.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;


int Piece::currentID = 1;

Piece::Piece(){ // default constructor
	position[0]=0;
	position[1]=0;
	team=1;				// -1 is solid, 1 is hollow
	id=currentID++;
}

// custom piece creation, 
Piece::Piece(int x,int y,int player){
	
	position[0]=x;
	position[1]=y;

	team = player; // -1 = white, 1 = black
	id=currentID++;
}

int* Piece::get_position(){
	return position;
}

vector<int*> Piece::get_moves(int** map){
	// pure virtual function, return a vector filled with available moves
}

void Piece::move(int x, int y){
	position[0]=x;
	position[1]=y;
}		

void Piece::upgrade(){

}

Piece::~Piece(){
}