main: functions.cpp Board.cpp Piece.cpp main.cpp PieceH.cpp PieceS.cpp
	g++ -c functions.cpp
	g++ -c Board.cpp 
	g++ -c Piece.cpp
	g++ -c PieceH.cpp
	g++ -c PieceS.cpp
	g++ -c main.cpp
	g++ -o executable main.o functions.o Piece.o Board.o PieceH.o PieceS.o
	./executable

test1: functions.cpp Board.cpp Piece.cpp main-test-1.cpp PieceH.cpp PieceS.cpp
	g++ -c functions.cpp
	g++ -c Board.cpp 
	g++ -c Piece.cpp
	g++ -c PieceH.cpp
	g++ -c PieceS.cpp
	g++ -c main-test-1.cpp
	g++ -o test_executable main-test-1.o functions.o Piece.o Board.o PieceH.o PieceS.o
	./test_executable

test2: functions.cpp Board.cpp Piece.cpp main-test-2.cpp PieceH.cpp PieceS.cpp
	g++ -c functions.cpp
	g++ -c Board.cpp 
	g++ -c Piece.cpp
	g++ -c PieceH.cpp
	g++ -c PieceS.cpp
	g++ -c main-test-2.cpp
	g++ -o test_executable main-test-2.o functions.o Piece.o Board.o PieceH.o PieceS.o
	./test_executable

test3: functions.cpp Board.cpp Piece.cpp main-test-3.cpp PieceH.cpp PieceS.cpp
	g++ -c functions.cpp
	g++ -c Board.cpp 
	g++ -c Piece.cpp
	g++ -c PieceH.cpp
	g++ -c PieceS.cpp
	g++ -c main-test-3.cpp
	g++ -o test_executable main-test-3.o functions.o Piece.o Board.o PieceH.o PieceS.o
	./test_executable

auto: functions.cpp Board.cpp Piece.cpp main.cpp PieceH.cpp PieceS.cpp inputs.txt
	g++ -c functions.cpp
	g++ -c Board.cpp 
	g++ -c Piece.cpp
	g++ -c PieceH.cpp
	g++ -c PieceS.cpp
	g++ -c main.cpp
	g++ -o executable main.o functions.o Piece.o Board.o PieceH.o PieceS.o
	./executable < inputs.txt