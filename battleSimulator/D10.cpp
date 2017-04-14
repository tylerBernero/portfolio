/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D10 class
******************************************************/
#include "D10.hpp"


/*****************************************************
** Description: Default constructor for D10
** class.  Sets sides to 10
******************************************************/
D10::D10()
{
	sides = 10;
}

/*****************************************************
** Description: Rolls random number between 1-10
******************************************************/
int D10::roll()
{
	return numRoll = (rand() % sides) + 1;
}