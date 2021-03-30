#ifndef _PIECE_H
#define _PIECE_H
#include<string>
#include<vector>
#include<iostream>
#pragma comment(lib, "gdiplus.lib")
using namespace std;

class Piece {
public:
	Piece();
	~Piece();
	Piece(string nm, int pl, int iny, int inx, int mm);
	int player = 0;
	int movesMade = 0;
	int x = 0;
	string name;
	struct positions {
		int x;
		int y;
	};
	positions defaultPosition = { 0, 0 };
	vector<positions> movements;
	vector<positions> pawnTakes;
	vector<positions> availablePositions;
	bool direction = false;
	bool pawn = false;
	
};

#endif