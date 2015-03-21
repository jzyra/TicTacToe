/*!
	* \file Referee.cpp
	* \brief Class for launch game and manage rounds.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#include "Referee.hpp"

Referee::Referee() {
}

bool Referee::readCin(int &n) { 
	cout << "Choose position: " ;   
	while (!(cin >> n) || n < 0 || n > 8) { 
		if (cin.eof()) {   
			return false;  
		} else if (cin.fail()) {   
			cout << "Choose position: ";  
			cin.clear();  
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		} else { 
			cout << "Choose position: "; 
		}
	}
	return true; 
} 


void Referee::humanPlay(Game &game) {
	int cellP1 = -1;
	cout << "Your round" << endl << endl;
	input:;
	if(readCin(cellP1)) {
		if(game.getMatriceData(cellP1%MATRICE_SIZE, cellP1/MATRICE_SIZE) != CELL_EMPTY) {
			goto input;
		}
		game.setMatriceData(cellP1%MATRICE_SIZE, cellP1/MATRICE_SIZE, CELL_HUMAN);
		if(game.checkWin(cellP1%MATRICE_SIZE, cellP1/MATRICE_SIZE)){
			game.printGame();
			cout << endl << "Player X win !" << endl;
			exit(1);
		}
	}
}

void Referee::iaPlay(Game &game) {
	int cellP2;
	cout << "IA round" << endl;
	Ia ia(game);
	cellP2 = ia.playPosition();
	game.setMatriceData(cellP2%MATRICE_SIZE, cellP2/MATRICE_SIZE, CELL_IA);
	if(game.checkWin(cellP2%MATRICE_SIZE, cellP2/MATRICE_SIZE)){
		game.printGame();
		cout << endl << "Player O win !" << endl;
		exit(1);
	}
}

void Referee::run() {
	Game game;
	srand(time(NULL));
	cout << "TIC-TAC-TOE" << endl;
	while(!game.isEndGame()){
		game.printGame();
		cout << endl;
		if(game.getRound()){
			humanPlay(game);
		}
		else{
			iaPlay(game);
		}
		game.setRound(!game.getRound());
	}
	game.printGame();
	cout << endl << "End game" << endl;
}
