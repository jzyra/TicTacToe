/*!
	* \file Game.cpp
	* \brief Class for implement game.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#include "Game.hpp"

Game::Game(){
	//Init _matrice game with empty position.
	for(int i=0; i < MATRICE_SIZE; ++i){
		for(int j=0; j < MATRICE_SIZE; ++j)
			_matrice[i][j] = CELL_EMPTY;
	}
	//IA begin.
	_round = false;
}

bool Game::getRound(){
	return _round;
}

void Game::setRound(bool round){
	_round = round;
}

bool Game::isEndGame(){
	int nbEmptyCell = 0;
	nbEmptyCell = countPawns(CELL_EMPTY);
	//If there are more than 0 empty cell.
	if(nbEmptyCell > 0)
		return false;
	else
		return true;
}

int Game::countPawns(int pawn){
	int count = 0;
	for(int i=0; i < MATRICE_SIZE; ++i){
		for(int j=0; j < MATRICE_SIZE; ++j){
			if(_matrice[i][j] == pawn)
				++count;
		}
	}
	return count;
}

int Game::getMatriceData(int x, int y){
	//If position can be played.
	if(x >= 0 && x < MATRICE_SIZE && y >= 0 && y < MATRICE_SIZE)
		return _matrice[y][x];
	else
		return -1;
}

void Game::setMatriceData(int x, int y, int value){
	//If position can be played.
	if(x >= 0 && x < MATRICE_SIZE && y >= 0 && y < MATRICE_SIZE)
		_matrice[y][x] = value;
}

bool Game::checkWin(int x, int y){
	int player = _matrice[y][x];
	int line1, line2, line3, line4;
	line1 = line2 = line3 = line4 = 1;
	//Count pawn in vertical line.
	for(int i=x+1; i < MATRICE_SIZE && _matrice[y][i] == player; ++i)
		++line1;
	for(int i=x-1; i > -1 && _matrice[y][i] == player; --i)
		++line1;
	//Count pawn in horizontal line.
	for(int i=y+1; i < MATRICE_SIZE && _matrice[i][x] == player; ++i)
		++line2;
	for(int i=y-1; i > -1 && _matrice[i][x] == player; --i)
		++line2;
	//Count pawn in first diagonal line.
	for(int i=x+1, j=y+1; i < MATRICE_SIZE && _matrice[j][i] == player && j < MATRICE_SIZE; ++i, ++j)
		++line3;
	for(int i=x-1, j=y-1; i > -1 && _matrice[j][i] == player && j > -1; --i, --j)
		++line3;
	//Count pawn in second diagonal line.
	for(int i=x+1, j=y-1; i < MATRICE_SIZE && _matrice[j][i] == player && j > -1; ++i, --j)
		++line4;
	for(int i=x-1, j=y+1; i > -1 && _matrice[j][i] == player && j < MATRICE_SIZE; --i, ++j)
		++line4;
	//If there are 3 pawns in line, position wine.
	if(line1 > 2 
		|| line2 > 2 
		|| line3 > 2 
		|| line4 > 2)
		return true;
	else
		return false;
}

void Game::printGame(){
	cout << endl;
	//For each pawns in _matrice.
	for(int i=0; i < MATRICE_SIZE; ++i){
		for(int j=0; j < MATRICE_SIZE; ++j){
			switch(_matrice[i][j]){
				//If cell is empty, display cell's number.
				case CELL_EMPTY:
					if(((i*MATRICE_SIZE)+j) < 10){
						cout << " " << (i*MATRICE_SIZE)+j;
					} else {
						cout << (i*MATRICE_SIZE)+j;
					}
					break;
				//If cell is human's cell, display X.
				case CELL_HUMAN:
					cout << " X";
					break;
				//If cell is IA's cell, display O.
				default:
					cout << " O";
					break;
			}
			if(j < MATRICE_SIZE-1)
				cout << "|";
			else{
				cout << endl; 
				if(i < MATRICE_SIZE-1){
					cout << "__";
					for(int i=0; i < MATRICE_SIZE-1; ++i)
						cout << "|__";
					cout << endl;
				}
			}
		}
	}
}
