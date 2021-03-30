#ifndef _SQUARE_H
#define _SQUARE_H
#include "Piece.h"

class Square {
public:
	Square(void);
	Piece* piece;
	Square(Piece* piece);
};

#endif