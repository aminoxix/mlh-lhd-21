#include <Windows.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Piece.h"
#include "PBoard.h"

using namespace std;
void playGame(vector <Piece>& pieces, int currenPlayer);
bool validateMoveFormat(string);
bool validateFileName(string);
void setAtPositions(PBoard&, vector<Piece>&);

struct p {
    int x;
    int y;
    int player;
    string name;

};

int main()
{
    while (true) {
        string command;
        system("cls");
        cout << "Welcome to Chess cpp command line!" << endl;

            cout << "Enter one of the available commands: " << endl;
            cout << "Start, Load " << endl;
            getline(cin, command);
            if (command == "Start" || command == "start") {
                vector <Piece> piecesAtDefPos{
         Piece("RW", 1, 0, 0,0),
         Piece("NW", 1, 0, 1,0),
         Piece("BW", 1, 0, 2,0),
         Piece("QW", 1, 0, 3,0),
         Piece("KW", 1, 0, 4,0),
         Piece("BW", 1, 0, 5,0),
         Piece("NW", 1, 0, 6,0),
         Piece("RW", 1, 0, 7,0),

         Piece("PW", 1, 1, 0,0),
         Piece("PW", 1, 1, 1,0),
         Piece("PW", 1, 1, 2,0),
         Piece("PW", 1, 1, 3,0),
         Piece("PW", 1, 1, 4,0),
         Piece("PW", 1, 1, 5,0),
         Piece("PW", 1, 1, 6,0),
         Piece("PW", 1, 1, 7,0),

         Piece("RB", 2, 7, 0,0),
         Piece("NB", 2, 7, 1,0),
         Piece("BB", 2, 7, 2,0),
         Piece("QB", 2, 7, 3,0),
         Piece("KB", 2, 7, 4,0),
         Piece("BB", 2, 7, 5,0),
         Piece("NB", 2, 7, 6,0),
         Piece("RB", 2, 7, 7,0),

         Piece("PB", 2, 6, 0,0),
         Piece("PB", 2, 6, 1,0),
         Piece("PB", 2, 6, 2,0),
         Piece("PB", 2, 6, 3,0),
         Piece("PB", 2, 6, 4,0),
         Piece("PB", 2, 6, 5,0),
         Piece("PB", 2, 6, 6,0),
         Piece("PB", 2, 6, 7,0)
                };
                int currentPlayer = 2;
                playGame(piecesAtDefPos, currentPlayer);
            }
            else if (command == "Load" || command == "load") {
                cout << "Enter file name" << endl;
                string fileName;
                getline(cin, fileName);
                // VALIDATE FILE NAME 
                while (validateFileName(fileName) == false) {
                    cout << "Invalid format. Please re-enter." << endl;
                    getline(cin, fileName);
                }
                fileName = fileName + ".txt";
                ifstream input(fileName);
                p pieceInGame{ 0, 0, 0, " " };
                int currentPlayer = 0;
                vector <Piece> piecesAtLoPos;
                if (input.is_open()) {

                    for (string line; getline(input, line);) {
                        stringstream stream;
                    
                        if (line.size() == 1) {
                            stream << line[0];	//convert the char number to an int number
                            stream >> currentPlayer;
                            stream.clear();
                        }
                        else {
                            int movesMade = 0;

                            stream << line[0];	//convert the char number to an int number
                            stream >> pieceInGame.x;
                            stream.clear();
                            stream << line[1];	//convert the char number to an int number
                            stream >> pieceInGame.y;
                            stream.clear();
               
                            stream << line[2];	//convert the char number to an int number
                            stream >> pieceInGame.player;
                            stream.clear();

                            stream << line[3];	//convert the char number to an int number
                            stream >> movesMade;
                            stream.clear();
                            string s1(1, line[4]);
                            string s2(1, line[5]);
                            pieceInGame.name = s1 + s2;
                   
                    
                            Piece piece(pieceInGame.name, pieceInGame.player, pieceInGame.y, pieceInGame.x, movesMade);
                            piecesAtLoPos.push_back(piece);
                            stream.clear();
                        }
                    }
   
                    cout << "Loading!" << endl;
                    playGame(piecesAtLoPos, currentPlayer);
                }
                else {
                    cout << "No such file!!!" << endl;
                    Sleep(2000);
                }
            }
            else if (command == "Exit" || command == "exit") {
               return 0;
            }
            else {
                cout << "Uncknown command" << endl;
            }
    }
}
void playGame(vector <Piece>& pieces, int currentPlayer) {

    PBoard board;
    setAtPositions(board, pieces);
    string move;

    while (true) {
        string player = "White";
        if (currentPlayer == 1) {
            player = "Black";
        }
        else {
            player = "White";
        }
        system("cls");
        board.Display();

        cout << "Player " << player << " please enter your move in the following format \"Move d2 to d3\": " << endl;
        cout << "Or use one of the available commands" << endl;
        cout << "Save, Restart, Test, Exit" << endl;
        getline(cin, move);

        if (move == "Exit" || move == "exit") {
            break;
        }
        else if (move == "Test" || move == "test") {
            cout << "Choose what do you want to test:" << endl;
            cout << "Pieces" << endl;
            string totest;
            getline(cin, totest);
            if (totest == "pieces" || totest == "Pieces") {
                board.testAvailablePositions(1);
                board.testAvailablePositions(2);
            }
            else if (totest == "exit" || totest == "Exit") {
                break;
            }
            else {
                continue;
            }
        }
        else if (move == "Restart" || move == "restart") {
            board.clearBoard();
            vector <Piece> piecesAtDefPos{
                     Piece("RW", 1, 0, 0,0),
                     Piece("NW", 1, 0, 1,0),
                     Piece("BW", 1, 0, 2,0),
                     Piece("QW", 1, 0, 3,0),
                     Piece("KW", 1, 0, 4,0),
                     Piece("BW", 1, 0, 5,0),
                     Piece("NW", 1, 0, 6,0),
                     Piece("RW", 1, 0, 7,0),
                                        
                     Piece("PW", 1, 1, 0,0),
                     Piece("PW", 1, 1, 1,0),
                     Piece("PW", 1, 1, 2,0),
                     Piece("PW", 1, 1, 3,0),
                     Piece("PW", 1, 1, 4,0),
                     Piece("PW", 1, 1, 5,0),
                     Piece("PW", 1, 1, 6,0),
                     Piece("PW", 1, 1, 7,0),
                                        
                     Piece("RB", 2, 7, 0,0),
                     Piece("NB", 2, 7, 1,0),
                     Piece("BB", 2, 7, 2,0),
                     Piece("QB", 2, 7, 3,0),
                     Piece("KB", 2, 7, 4,0),
                     Piece("BB", 2, 7, 5,0),
                     Piece("NB", 2, 7, 6,0),
                     Piece("RB", 2, 7, 7,0),
                                        
                     Piece("PB", 2, 6, 0,0),
                     Piece("PB", 2, 6, 1,0),
                     Piece("PB", 2, 6, 2,0),
                     Piece("PB", 2, 6, 3,0),
                     Piece("PB", 2, 6, 4,0),
                     Piece("PB", 2, 6, 5,0),
                     Piece("PB", 2, 6, 6,0),
                     Piece("PB", 2, 6, 7,0)
            };
            for (int i = 0; i < 32; i++) {
                pieces[i] = piecesAtDefPos[i];
            }
            setAtPositions(board, pieces);
            currentPlayer = 2;
        }
        else if (move == "Save" || move == "save") {

            p pieceInGame{ 0, 0, 0, " " };
            cout << "Enter file name" << endl;
            string fileName;
            getline(cin, fileName);
            // VALIDATE FILE NAME 
            while (validateFileName(fileName) == false) {
                cout << "Invalid format. Please re-enter." << endl;
                getline(cin, fileName);
            }
            fileName = fileName + ".txt";
            ofstream fout(fileName);
            if (fout.is_open()) {
                for (int y = 0; y < 8; y++) {
                    for (int x = 0; x < 8; x++) {
                        if (board.board[y][x].piece != nullptr) {
                        
                            pieceInGame.name = board.board[y][x].piece->name;
                            pieceInGame.player = board.board[y][x].piece->player;
                            int movesMade = board.board[y][x].piece->movesMade;
                            pieceInGame.x = x;
                            pieceInGame.y = y;
                            fout << pieceInGame.x  << pieceInGame.y  << pieceInGame.player << movesMade << pieceInGame.name << endl;
                        }
                    }
                }
                fout << currentPlayer;
                fout.close();
            }
            else {
                cout << "Unable to open file";
            }
             
            cout << "Saved!" << endl;
        }
        else if ((move[0] == 'm' || move[0] == 'M') && move[1] == 'o' && move[2] == 'v' && move[3] == 'e') {
            if (currentPlayer == 1) {
                currentPlayer = 2;
            }
            else {
                currentPlayer = 1;
            }
            while (validateMoveFormat(move) == false) {
                cout << "Invalid format. Please re-enter your move" << endl;
                getline(cin, move);
            }
            board.convertMovetoPositions(move);

            while (board.validateMoveRules(move, currentPlayer) == false) {
                cout << "Please re-enter your move" << endl;
                getline(cin, move);
                while (validateMoveFormat(move) == false) {
                    cout << "Invalid format. Please re-enter your move" << endl;
                    getline(cin, move);
                }
            }
            
            int check = board.isCheck();
            if (check == 1 && check == currentPlayer) {
               
                    cout << "Player " << player << " lost!";
                    Sleep(2000);
                    break;
                
            }
            if (check == 2 && check == currentPlayer) {
                cout << "Player " << player << " lost!";
                Sleep(2000);
                break;
            }
            if (check == 1 ) {
                cout << "White King is in check!" << endl;
                Sleep(1000);
                system("cls");
                board.Display();
                bool checkMate = board.isCheckMate(check);
                if (checkMate) {
                    cout << "CHECK MATE!" << endl;
                    cout << "Player " << player << " won!";
                    system("PAUSE");
                    Sleep(2000);
                    break;
                }

            }
            if (check == 2) {
                cout << "Black King is in check!" << endl;
                Sleep(1000);
                system("cls");
                board.Display();
                bool checkMate = board.isCheckMate(check);
                if (checkMate) {
                    cout << "CHECK MATE!" << endl;
                    cout << "Player " << player << " won!";
                    system("PAUSE");
                    Sleep(2000);
                    break;
                }
            }

        }
        else {
            cout << "Unknown command!" << endl;
            Sleep(500);
        }
        }

    cout << endl;
}
bool validateMoveFormat(string move) {
    // move has 13 characters
    if (move.length() != 13) {

        return false;

    }
  
    if (move[5] != 'a' && move[5] != 'b' && move[5] != 'c' && move[5] != 'd' &&
        move[5] != 'e' && move[5] != 'f' && move[5] != 'g' && move[5] != 'h') {

        return false;

    }	
    if (move[6] != '1' && move[6] != '2' && move[6] != '3' && move[6] != '4' && move[6] != '5'
        && move[6] != '6' && move[6] != '7' && move[6] != '8') {

        return false;

    }
    if (move[8] != 't' || move[9] != 'o') {

        return false;

    }
    if (move[11] != 'a' && move[11] != 'b' && move[11] != 'c' && move[11] != 'd' && move[11] != 'e'
        && move[11] != 'f' && move[11] != 'g' && move[11] != 'h') {

        return false;

    }
    if (move[12] != '1' && move[12] != '2' && move[12] != '3' && move[12] != '4' && move[12] != '5'
        && move[12] != '6' && move[12] != '7' && move[12] != '8') {

        return false;

    }

    else return true;
    
}
bool validateFileName(string name) {
    if (name.size() > 10) {
        return false;
    }
    return true;
}

void setAtPositions(PBoard &board, vector <Piece> &pieces) {
    int length = pieces.size();
    for (int i = 0; i < length; i++ ) {
        board.board[pieces[i].defaultPosition.y][pieces[i].defaultPosition.x] = &pieces[i];
    }
}