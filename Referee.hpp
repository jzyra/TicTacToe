/*!
	* \file Referee.hpp
	* \brief Class header for launch game and manage rounds.
	* \author Jeremy ZYRA
	* \version 1.0
*/
#ifndef REFEREE_H
#define REFEREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <limits>
#include "Game.hpp"
#include "Ia.hpp"
#include "defines.hpp"
using namespace std;

/*!
	* \class Game
	* \brief Class header for launch game and manage rounds.
*/
class Referee {
	private:
	/*
		* \brief Function for IA round.
	*/
	void iaPlay(Game &game);
	/*
		* \brief Function for human round.
	*/
	void humanPlay(Game &game);
	/*
		* \brief Function get human choice by cin object.
		* \param number entry by human.
		* \return if human played.
	*/
	bool readCin(int &n);

	public:
	Referee();
	/*
		* \brief Run game.
	*/
	void run();
};

#endif
