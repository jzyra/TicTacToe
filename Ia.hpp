/*!
	* \file Ia.hpp
	* \brief Class header for implement IA game (minmax and alpha-beta pruning).
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef IA_H
#define IA_H

#include "defines.hpp"
#include "Game.hpp"

/*!
	* \class Game
	* \brief Class header for implement IA game (minmax and alpha-beta pruning).
*/
class Ia {
	private:
	Game _game;
	/*
		* \brief Function for get position's evaluation.
		* \param x pawn's position.
		* \param y pawn's position.
		* \return evaluation position value.
	*/
	int eval(Game game, int x, int y);
	/*
		* \brief Function for get max position's evaluation.
		* \param Game object.
		* \param position.
		* \param alpha value.
		* \param beta value.
		* \return max position.
	*/
	int getMax(Game game, int pos, int alpha, int beta);
	/*
		* \brief Function for get min position's evaluation.
		* \param Game object.
		* \param position.
		* \param alpha value.
		* \param beta value.
		* \return min position.
	*/
	int getMin(Game game, int pos, int alpha, int beta);

	public:
	/*
		* \brief IA constructor.
	*/
	Ia(Game game);
	/*
		* \brief Function for play.
		* \return position played by IA.
	*/
	int playPosition();
};

#endif
