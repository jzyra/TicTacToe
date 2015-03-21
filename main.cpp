/*!
	* \file main.cpp
	* \brief Program's entry point.
	* \author Jeremy ZYRA
*/
#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Referee.hpp"
using namespace std;

/*!
	* \brief Program's entry point.
*/
int main(void){
	Referee referee;
	referee.run();
	return 1;
}
