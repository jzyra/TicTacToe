/*!
	* \file Ia.cpp
	* \brief Class for implement IA game (minmax and alpha-beta pruning).
	* \author Jeremy ZYRA
	* \version 1.0
*/
#include "Ia.hpp"

Ia::Ia(Game game){
	_game = game;
}

int Ia::eval(Game game, int x, int y){
	int player = game.getMatriceData(x, y);
	int line1, line2, line3, line4;
	int gameValue = 0;
	line1 = line2 = line3 = line4 = 1;
	//Count pawn in vertical line.
	for(int i=x+1; i < MATRICE_SIZE && game.getMatriceData(i, y) == player; ++i)
		++line1;
	for(int i=x-1; i > -1 && game.getMatriceData(i, y) == player; --i)
		++line1;
	//Count pawn in horizontal line.
	for(int i=y+1; i < MATRICE_SIZE && game.getMatriceData(x, i) == player; ++i)
		++line2;
	for(int i=y-1; i > -1 && game.getMatriceData(x, i) == player; --i)
		++line2;
	//Count pawn in first diagonal line.
	for(int i=x+1, j=y+1; i < MATRICE_SIZE && game.getMatriceData(i, j) == player && j < MATRICE_SIZE; ++i, ++j)
		++line3;
	for(int i=x-1, j=y-1; i > -1 && game.getMatriceData(i, j) == player && j > -1; --i, --j)
		++line3;
	//Count pawn in second diagonal line.
	for(int i=x+1, j=y-1; i < MATRICE_SIZE && game.getMatriceData(i, j) == player && j > -1; ++i, --j)
		++line4;
	for(int i=x-1, j=y+1; i > -1 && game.getMatriceData(i, j) == player && j < MATRICE_SIZE; --i, ++j)
		++line4;
	//If position is winner's position.
	if(line1 > 2 
		|| line2 > 2 
		|| line3 > 2 
		|| line4 > 2){
		//If IA win.
		if(player == CELL_IA){
			return 1000 + game.countPawns(CELL_EMPTY);
		}
		//If human win.
		else if(player == CELL_HUMAN){
			return -1000 - game.countPawns(CELL_EMPTY);
		}
		else
			return 0;
	}
	//If there are 2 pawns, evaluation is 30*(count pawn)
	if(line1 > 1)
		gameValue += 30*line1;
	//If there is 1 pawn, evaluation is 10.
	else if(line1 > 0)
		gameValue += 10*line1;
	else
		gameValue += 0;
	if(line2 > 1)
		gameValue += 30*line2;
	else if(line2 > 0)
		gameValue += 10*line2;
	else
		gameValue += 0;
	if(line3 > 1)
		gameValue += 30*line3;
	else if(line3 > 0)
		gameValue += 10*line3;
	else
		gameValue += 0;
	if(line4 > 1)
		gameValue += 30*line4;
	else if(line4 > 0)
		gameValue += 10*line4;
	else
		gameValue += 0;
	//If position evaluated is human's position => evaluation * -1.
	if(player == CELL_HUMAN)
		gameValue *= -1;
	return gameValue;
}

int Ia::getMax(Game game, int pos, int alpha, int beta){
	int gameValue, tmp;
	gameValue = tmp = -10000;
	if(game.checkWin(pos%MATRICE_SIZE, pos/MATRICE_SIZE)){
	//If position played is winner's position, return evaluation of this position.
		return eval(game, pos%MATRICE_SIZE, pos/MATRICE_SIZE);
	}
	//If is end game, return position's evaluation.
	if(game.isEndGame()){
		return eval(game, pos%MATRICE_SIZE, pos/MATRICE_SIZE);
	}
	//For each positions in matrice.
	for(int i=0; i < MATRICE_SIZE*MATRICE_SIZE; ++i){
		//If this position can be played.
		if(game.getMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE) == CELL_EMPTY){
			//IA play this position.
			game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_IA);
			//Maximise minimum's evaluation (IA maximise evaluation)
			tmp = getMin(game, i, alpha, beta);
			alpha = (alpha > tmp) ? alpha : tmp;
			if(beta <= alpha)
				return alpha;
			//Delete position.
			game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_EMPTY);
		}
	}
	return alpha;
}

int Ia::getMin(Game game, int pos, int alpha, int beta){
	int gameValue, tmp;
	gameValue = tmp = +10000;
	//If position played is winner's position, return evaluation of this position.
	if(game.checkWin(pos%MATRICE_SIZE, pos/MATRICE_SIZE)){
		return eval(game, pos%MATRICE_SIZE, pos/MATRICE_SIZE);
	}
	//If is end game, return position's evaluation.
	if(game.isEndGame()){
		return eval(game, pos%MATRICE_SIZE, pos/MATRICE_SIZE);
	}
	//For each positions in matrice.
	for(int i=0; i < MATRICE_SIZE*MATRICE_SIZE; ++i){
		//If this position can be played.
		if(game.getMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE) == CELL_EMPTY){
			//Human play this position.
			game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_HUMAN);
			//Minimise maximum's evaluation (Human minimise evaluation)
			tmp = getMax(game, i, alpha, beta);
			beta = (beta > tmp) ? tmp : beta;
			if(beta <= alpha)
				return beta;
			//Delete position.
			game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_EMPTY);
		}
	}
	return beta;
}

int Ia::playPosition(){
	int positionPlayed = -1;
	int gameValue, tmp;
	gameValue = tmp = -10000;	
	//For each positions in game matrice.
	for(int i=0; i < MATRICE_SIZE*MATRICE_SIZE; ++i){
		//If position can be played.
		if(_game.getMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE) == CELL_EMPTY){
			//Play this position.
			_game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_IA);
			//Evaluation of this position.
			tmp = getMin(_game, i, -1000, 1000);
			//Delete position.
			_game.setMatriceData(i%MATRICE_SIZE, i/MATRICE_SIZE, CELL_EMPTY);
			//Get best position (MAX evaluation)
			if(tmp > gameValue){
				gameValue = tmp;
				positionPlayed = i;
			}
		}
	}
	//Return best position.
	return positionPlayed;
}
