#ifndef _PBOARD_H
#define _PBOARD_H
#include "Piece.h"
#include "Square.h"
#include <iostream>
#include <sstream>
#include <Windows.h>
#include<vector>


	using namespace std;
	class PBoard {
	public:
		PBoard(void);
		~PBoard(void);
		struct positions {
			int x;
			int y;
		};
		Square board[8][8];
		void Display();
		void clearBoard();
		void testAvailablePositions(int curPlayer);
		int isCheck();
		bool isCheckMate(int);
		bool validateMoveRules(string, int);
		void convertMovetoPositions(string);
		void clearPositions(int);
	private:
		void movePiece();
		void availablePositions(int);
		bool isValidMove(Piece*);
		void pieceAtPosition();
		positions targetPositionCoor = { 0, 0 };
		positions selectedPieceCoor = { 0, 0 };
		string displayBoard[17][19];
	};

#endif