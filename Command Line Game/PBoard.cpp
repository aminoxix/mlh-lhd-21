#include "PBoard.h"

PBoard::PBoard(void) {
}
PBoard::~PBoard(void) {

}
bool PBoard::validateMoveRules(string move, int currentPlayer) {
	bool valid;
	convertMovetoPositions(move);
	Piece* selectedPiece = board[selectedPieceCoor.y][selectedPieceCoor.x].piece;
	Piece* targetPosition = board[targetPositionCoor.y][targetPositionCoor.x].piece;

	if (selectedPiece == nullptr) {
		cout << "There's no piece at the specified location." << endl;
		return false;
	}
	else if (selectedPiece->player != currentPlayer) {
		cout << "This is not your piece" << endl;
		return false;
	}
	if (targetPosition != nullptr && targetPosition->player == currentPlayer && selectedPiece->player == currentPlayer) {
		cout << "You already have a piece there." << endl;
		return false;
	}

	availablePositions(1);
	availablePositions(2);
	valid = isValidMove(selectedPiece);
	selectedPiece->movesMade += 1;
	if (valid) {
		movePiece();

	}
	clearPositions(1);
	clearPositions(2);
	availablePositions(1);
	availablePositions(2);

	return valid;
}
void PBoard::movePiece() {
	board[targetPositionCoor.y][targetPositionCoor.x] = board[selectedPieceCoor.y][selectedPieceCoor.x].piece;
	board[selectedPieceCoor.y][selectedPieceCoor.x] = nullptr;
	cout << "Move successful" << endl;
	//Sleep(450);
}
void PBoard::availablePositions(int targetPlayer) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			// looping trhough all pieces
			if (currentPiece != nullptr && currentPiece->player == targetPlayer) {
				
				// looping trhough all possible movements of a piece
				int length = currentPiece->movements.size();
				for (int i = 0; i < length; i++) {
					if (currentPiece->direction && !currentPiece->pawn) {

						// find all available positions in a direction
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						

						// up
						if (movement.y < 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = currentPos.x;
							while (iy >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
							}
						}else if (movement.y > 0 && movement.x == 0) {
						// down
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = currentPos.x;
							while (iy < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
							}
						}else if (movement.y == 0 && movement.x > 0) {
						//right
							// loop for step movement
							int iy = currentPos.y;
							int ix = (currentPos.x + 1);
							while (ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								ix++;
							}
						} else if (movement.y == 0 && movement.x < 0) {
						//left
							// loop for step movement
							int iy = currentPos.y;
							int ix = (currentPos.x - 1);
							while (ix >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								ix--;
							}
						} else if (movement.y < 0 && movement.x > 0) {
						// up & right
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = (currentPos.x + 1);
							while (iy >= 0 && iy < 8 && ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
								ix++;
							}
						} else if (movement.y < 0 && movement.x < 0) {
						// up & left
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = (currentPos.x - 1);
							while (iy >= 0 && iy < 8 && ix >= 0)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy--;
								ix--;
							}
						} else if (movement.y > 0 && movement.x > 0) {
						// down & right
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = (currentPos.x + 1);
							while (iy < 8 && ix < 8)
							{
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
								ix++;
							}
						} else if (movement.y > 0 && movement.x < 0){
						// down & left
							// loop for step movement
							int iy = (currentPos.y + 1);
							int ix = (currentPos.x - 1);
							while (iy < 8 && ix >= 0)
							{	
								// check if there is no piece on the way
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
								}
								else if (board[iy][ix].piece->player != currentPiece->player) {
									currentPiece->availablePositions.push_back({ ix, iy });
									break;
								}
								else {
									break;
								}
								iy++;
								ix--;
							}
						}
					}
					else if (!currentPiece->direction && !currentPiece->pawn) {
						// find available pos around a piece (for N, K)
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						int ix = (currentPos.x + movement.x);
						int iy = (currentPos.y + movement.y);
						if (ix >= 0 && iy >= 0 && ix < 8 && iy < 8) {
							if (board[iy][ix].piece == nullptr || board[iy][ix].piece->player != currentPiece->player) {
								currentPiece->availablePositions.push_back({ ix, iy });
							}
						};
					}
					else if (currentPiece->pawn && currentPiece->player == 1) {
					// white pawn logic
					Piece* pawn = board[y][x].piece;
						positions movement = { pawn->movements[i].x, pawn->movements[i].y };
						positions currentPos = { x, y };

						// down
						if (movement.y > 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y + movement.y);
							int ix = currentPos.x;
							if (board[iy][ix].piece == nullptr) {
								pawn->availablePositions.push_back({ ix, iy });
								if (pawn->movesMade == 0) {
									iy = iy + 1;
									if (board[iy][ix].piece == nullptr) {
										pawn->availablePositions.push_back({ ix, iy });
									}
								}
							}
						}
						// down & left
						// looping trhough pawntakes 
						int lengthpw = currentPiece->pawnTakes.size();
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y > 0 && currentPiece->pawnTakes[i].x < 0) {
								int iy = (currentPos.y + 1);
								int ix = (currentPos.x - 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {

									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// down & right
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y > 0 && currentPiece->pawnTakes[i].x > 0) {
								int iy = (currentPos.y + 1);
								int ix = (currentPos.x + 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}

					}
					else if (currentPiece->pawn && currentPiece->player == 2) {
					// black pawn logic
						positions movement = { currentPiece->movements[i].x, currentPiece->movements[i].y };
						positions currentPos = { x, y };
						
						// up
						if (movement.y < 0 && movement.x == 0) {
							// loop for step movement
							int iy = (currentPos.y - 1);
							int ix = currentPos.x;
							if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
								if (board[iy][ix].piece == nullptr) {
									currentPiece->availablePositions.push_back({ ix, iy });
									if (currentPiece->movesMade == 0 && iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
										iy = iy - 1;
										if (board[iy][ix].piece == nullptr) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// up & left
						// looping trhough pawntakes 
						int lengthpw = currentPiece->pawnTakes.size();
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y < 0 && currentPiece->pawnTakes[i].x < 0) {
								int iy = (currentPos.y - 1);
								int ix = (currentPos.x - 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
						// up & right
						for (int i = 0; i < lengthpw; i++) {
							if (currentPiece->pawnTakes[i].y < 0 && currentPiece->pawnTakes[i].x > 0) {
								int iy = (currentPos.y - 1);
								int ix = (currentPos.x + 1);
								if (iy < 8 && iy >= 0 && ix < 8 && ix >= 0) {
									if (board[iy][ix].piece != nullptr) {
										if (board[iy][ix].piece->player != currentPiece->player) {
											currentPiece->availablePositions.push_back({ ix, iy });
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
bool PBoard::isValidMove(Piece* selectedPiece) {
	// if target position  == to availablePosition return true
	int length = selectedPiece->availablePositions.size();
	for (int i = 0; i < length; i++) {
		positions availablePosition = { selectedPiece->availablePositions[i].x, selectedPiece->availablePositions[i].y};
		if (targetPositionCoor.x == availablePosition.x && targetPositionCoor.y == availablePosition.y) {
			return true;
		}
	}
	cout << selectedPiece->name << " can not move this way!" << endl;
	return false;	   
}
int PBoard::isCheck() {
	// if any of the opponent's pieces available position is the position of the King return true
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			if (currentPiece != nullptr) {
				if (currentPiece->name == "KB") {
					positions blackKing = { x, y };
					for (int iy = 0; iy < 8; iy++) {
						for (int ix = 0; ix < 8; ix++) {
							Piece* currentPiece = board[iy][ix].piece;

							if (currentPiece != nullptr && currentPiece->player != 2) {
								int length = currentPiece->availablePositions.size();
									for (int i = 0; i < length; i++) {
										if (currentPiece->availablePositions[i].x == blackKing.x && currentPiece->availablePositions[i].y == blackKing.y) {
											return 2;
									}
								}
							}
						}
					}
				}
				if (currentPiece->name == "KW") {
					positions whiteKing = { x, y };
					for (int iy = 0; iy < 8; iy++) {
						for (int ix = 0; ix < 8; ix++) {
							Piece* currentPiece = board[iy][ix].piece;
							if (currentPiece != nullptr && currentPiece->player != 1) {
								int length = currentPiece->availablePositions.size();
								for (int i = 0; i < length; i++) {

									if (currentPiece->availablePositions[i].x == whiteKing.x && currentPiece->availablePositions[i].y == whiteKing.y) {
										return 1;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
bool PBoard::isCheckMate(int curPlayer) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			if (currentPiece != nullptr) {
				int length = currentPiece->availablePositions.size();
				for (int i = 0; i < length; i++) {
					
					if (currentPiece->player == curPlayer) {

						//move current piece to each available position it has if !inCheck move back and return false
						Piece* temp = board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x].piece;
						board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x] = currentPiece;
						board[y][x] = nullptr;
						if (curPlayer == 1) {
						clearPositions(2);
						availablePositions(2);
						}
						if (curPlayer == 2) {
							clearPositions(1);
							availablePositions(1);
						}

						int check = isCheck();
						if (check == 0) {
							board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x] = temp;
							board[y][x] = currentPiece;
							if (curPlayer == 1) {
								clearPositions(2);
								availablePositions(2);
							}
							if (curPlayer == 2) {
								clearPositions(1);
								availablePositions(1);
							}

							return false;
						}
						board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x] = temp;
						board[y][x] = currentPiece;
						if (curPlayer == 1) {
							clearPositions(2);
							availablePositions(2);
						}
						if (curPlayer == 2) {
							clearPositions(1);
							availablePositions(1);
						}
					}
				}
			}
		}
	}
	return true;
}
void PBoard::clearPositions(int targetPlayer){
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x].piece != nullptr && board[y][x].piece->player == targetPlayer) {
				board[y][x].piece->availablePositions.clear();
			}
		}
	}
};
void PBoard::convertMovetoPositions(string move) {
	//convert move sections to useable format

	stringstream stream;

	int selectedY;
	int selectedX;	//selectedX is the number equivalent of the letter they enter...see the switch statements below

	stream << move[6];	//convert the char number to an int number
	stream >> selectedY;

	//these "ifs" just convert the letter to a number so it can be used
	//as an index
	if (move[5] == 'a')
		selectedX = 0;
	else if (move[5] == 'b')
		selectedX = 1;
	else if (move[5] == 'c')
		selectedX = 2;
	else if (move[5] == 'd')
		selectedX = 3;
	else if (move[5] == 'e')
		selectedX = 4;
	else if (move[5] == 'f')
		selectedX = 5;
	else if (move[5] == 'g')
		selectedX = 6;
	else
		selectedX = 7;
	stream.clear();	//clear
	selectedPieceCoor.x = selectedX;
	selectedPieceCoor.y = (selectedY-1);

	int targetY;
	int targetX;

	stream << move[12];
	stream >> targetY;

	if (move[11] == 'a')
		targetX = 0;
	else if (move[11] == 'b')
		targetX = 1;
	else if (move[11] == 'c')
		targetX = 2;
	else if (move[11] == 'd')
		targetX = 3;
	else if (move[11] == 'e')
		targetX = 4;
	else if (move[11] == 'f')
		targetX = 5;
	else if (move[11] == 'g')
		targetX = 6;
	else
		targetX = 7;
	targetPositionCoor.x = targetX;
	targetPositionCoor.y = (targetY-1);
}
void PBoard::Display() {
	string white((19 * 3), ' ');
	white.insert(21, "white");
	cout << white;
	cout << endl;
	// display letters
	string space5(5, ' ');
	string space2(2, ' ');
	string space3(2, ' ');
	for (char letter = 'a'; letter <= 'h'; letter++) {
		if (letter == 'a') {
			cout << space5;
			cout << letter;
			cout << space2;
		}
		else {
			cout << space3;
			cout << letter;
			cout << space2;
		}
	}
	// create board
	for (int y = 0; y < 17; y++) {
		// left & right digits
		if ((y % 2) == 0) {
			displayBoard[y][0] = " ";
			displayBoard[y][18] = " ";
		}
		if (y >= 1 && y <= 8) {
			char c = '0' + y;
			displayBoard[(y * 2) - 1][0] = c;
			displayBoard[(y * 2) - 1][18] = c;
		}
		// row borders
		for (int x = 1; x < 18; x++) {
			if ((y % 2) == 0) {
				if ((x % 2) == 0) {
					displayBoard[y][x] = "--";

				}
				else {
					displayBoard[y][x] = "---";

				}
				if (x == 1) {
					displayBoard[y][x] = " -";
				}
			}
			// column borders
			else {
				if ((x % 2) == 1) {
					displayBoard[y][x] = " | ";
				}
				// place for piece
				else {
					displayBoard[y][x] = "  ";
				}
			}
		}
	}
	// add pieces

	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x].piece != nullptr) {
				//string c =  board[y][x].piece->name;
				displayBoard[(y * 2) + 1][(x * 2) + 2] = board[y][x].piece->name;;
			}
		}
	}

	// display board
	for (int y = 0; y < 17; y++) {
		cout << endl;
		for (int x = 0; x < 19; x++) {
			cout << displayBoard[y][x];
		}
	}
	cout << endl;
	// display letters
	for (char letter = 'a'; letter <= 'h'; letter++) {
		if (letter == 'a') {
			cout << space5;
			cout << letter;
			cout << space2;
		}
		else {
			cout << space3;
			cout << letter;
			cout << space2;
		}
	}
	cout << endl;
	string black((19 * 3), ' ');
	black.insert(21, "black");
	cout << black;
	cout << endl;

};
void PBoard::clearBoard(){
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			if (currentPiece != nullptr) {
				board[y][x] = nullptr;
			}
		}
	}
}
void PBoard::testAvailablePositions(int curPlayer) {
	clearPositions(curPlayer);
	availablePositions(curPlayer);
	
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			Piece* currentPiece = board[y][x].piece;
			if (currentPiece != nullptr) {
				int length = currentPiece->availablePositions.size();
				for (int i = 0; i < length; i++) {

					if (currentPiece->player == curPlayer) {

						//move current piece to each available position it has if !inCheck move back and return false
						Piece* temp = board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x].piece;
						board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x] = currentPiece;
						board[y][x] = nullptr;
						if (curPlayer == 1) {
							clearPositions(2);
							availablePositions(2);
						}
						if (curPlayer == 2) {
							clearPositions(1);
							availablePositions(1);
						}
						Sleep(1000);
						system("cls");
						Display();
						
						board[currentPiece->availablePositions[i].y][currentPiece->availablePositions[i].x] = temp;
						board[y][x] = currentPiece;
						if (curPlayer == 1) {
							clearPositions(2);
							availablePositions(2);
						}
						if (curPlayer == 2) {
							clearPositions(1);
							availablePositions(1);
						}
						Sleep(1000);
						system("cls");
						Display();
					}
				}
			}
		}
	}
	clearPositions(curPlayer);
	availablePositions(curPlayer);
}
