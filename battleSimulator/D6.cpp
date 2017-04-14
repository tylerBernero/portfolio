/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D6 class
******************************************************/
#include "D6.hpp"


/*****************************************************
** Description: Default constructor for D6
** class.  Sets sides to 6
******************************************************/
D6::D6()
{
	sides = 6;
}

/*****************************************************
** Description: Rolls random number between 1-6
******************************************************/
int D6::roll()
{
	return numRoll = (rand() % sides) + 1;
}