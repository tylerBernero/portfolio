/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for D12 class
******************************************************/
#include "D12.hpp"


/*****************************************************
** Description: Default constructor for D12
** class.  Sets sides to 12
******************************************************/
D12::D12()
{
	sides = 12;
}

/*****************************************************
** Description: Rolls random number between 1-12
******************************************************/
int D12::roll()
{
	return numRoll = (rand() % sides) + 1;
}