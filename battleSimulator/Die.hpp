/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Header file for Die class
******************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include <cstdlib>

class Die
{
protected:
	int sides;
	int numRoll;
public:
	Die();
	virtual int roll() = 0;
};
#endif