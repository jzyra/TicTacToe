/*!
	* \file Game.hpp
	* \brief Class header for implement game.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "defines.hpp"
using namespace std;

/*!
	* \class Game
	* \brief Class header for implement game.
*/
class Game {
	private:
	int _matrice[MATRICE_SIZE][MATRICE_SIZE];
	bool _round;

	public:
	/*
		* \brief Game constructor.
	*/
	Game();
	/*!
		* \brief Accessor on round.
		* \return round.
	*/
	bool getRound();
	/*!
		* \brief Accessor on round.
		Set round in game.
		* \param round.
	*/
	void setRound(bool round);
	/*!
		* \brief Determine if is end of game.
		* \return true if this is the end of game.
	*/
	bool isEndGame();
	/*!
		* \brief Count panws in game.
		Count pawns in function of param.
		* \param pawn's type.
		* \return Pawn's count.
	*/
	int countPawns(int pawn);
	/*!
		* \brief Get pawn's type.
		* \param x pawn's position.
		* \param y pawn's position.
		* \return Pawn's type.
	*/
	int getMatriceData(int x, int y);
	/*!
		* \brief Set pawn's type.
		* \param x pawn's position.
		* \param y pawn's position.
		* \param pawn's type.
	*/
	void setMatriceData(int x, int y, int value);
	/*!
		* \brief Check if position win.
		* \param x pawn's position.
		* \param y pawn's position.
		* \return true if position win.
	*/
	bool checkWin(int x, int y);
	/*!
		* \brief Print game matrice.
	*/
	void printGame();
};

#endif
