/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Creates a menu object and calls menu.
** Also calls random seed for later use
******************************************************/
#include "Menu.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	//Call random seed using time
	unsigned seed;
	seed = time(0);
	srand(seed);

	Menu m1;

	m1.callMenu();

	return 0;
}