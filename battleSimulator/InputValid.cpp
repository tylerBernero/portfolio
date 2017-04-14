/*****************************************************
** Title: Project 4
** Author: Tyler Bernero
** Date: March 5, 2017
** Description: Source file for Input Valid class
******************************************************/
#include "InputValid.hpp"
#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;

/*****************************************************
** Description: Takes user input and ensures it is
** a positive integer
******************************************************/
int inputValid()
{
	int input;
	cin >> input;

	while (cin.fail())
	{
		cout << "That is not a valid input.  Please input an integer." << endl << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');
		cin >> input;
	}

	return input;
}