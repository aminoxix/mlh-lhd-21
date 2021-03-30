#include "Piece.h"

Piece::Piece(void) {};
Piece::~Piece(void) {};
Piece::Piece(string nm, int pl, int iny, int inx, int mm) {
	name = nm;
	player = pl;
	defaultPosition.x = inx;
	defaultPosition.y = iny;
	movesMade = mm;
	
	if (nm == "KB" || nm == "KW") {
								// x y
		movements.push_back({ 1, 0 });
		movements.push_back({ 1, 1 });
		movements.push_back({ 0, 1 });
		movements.push_back({ -1, 1 });
		movements.push_back({ -1, 0 });
		movements.push_back({ -1, -1 });
		movements.push_back({ 0, -1 });
		movements.push_back({ 1, -1 });
		
	} 
	else if (nm == "QB" || nm == "QW") {
		movements.push_back({ 1, 0 });
		movements.push_back({ 1, 1 });
		movements.push_back({ 0, 1 });
		movements.push_back({ -1, 1 });
		movements.push_back({ -1, 0 });
		movements.push_back({ -1, -1 });
		movements.push_back({ 0, -1 });
		movements.push_back({ 1, -1 });
		direction = true;
	} 
	else if (nm == "NB" || nm == "NW") {
		movements.push_back({ 2, 1 });
		movements.push_back({ 2, -1 });
		movements.push_back({ -2, 1 });
		movements.push_back({ -2, -1 });
		movements.push_back({ 1, 2 });
		movements.push_back({ 1, -2 });
		movements.push_back({ -1, -2 });
		movements.push_back({ -1, 2 });
	} 
	else if (nm == "BB" || nm == "BW") {
		movements.push_back({ 1, 1 });
		movements.push_back({ 1, -1 });
		movements.push_back({ -1, 1 });
		movements.push_back({ -1, -1 });

		direction = true;
	} else if (nm == "RB" || nm == "RW") {
		movements.push_back({ 0, 1 });
		movements.push_back({ 0, -1 });
		movements.push_back({ 1, 0 });
		movements.push_back({ -1, 0 });

		direction = true;
	} 
	else if (nm == "PB") {
		movements.push_back({ 0, -1 });
		pawnTakes.push_back({ 1, -1 });
		pawnTakes.push_back({ -1, -1 });
		pawn = true;
	} else if (nm == "PW") {
		movements.push_back({ 0, 1 });
		pawnTakes.push_back({ -1, 1 });
		pawnTakes.push_back({ 1, 1 });
		pawn = true;
	}
}
