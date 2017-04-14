/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Creates a text-based adventure game for the
** user to play
** Cited: Heavily influenced by Chris Merril's example final
****************************************************************/
#include "Game.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{

	cout << "Final Project" << endl;
	cout << "Tyler Bernero" << endl << endl;
	cout << "The Memory of Zelda" << endl;

	cin.get();
	cout << endl << endl << endl << endl;


	cout << "This is a work of fiction. Names, characters," << endl;
	cout << "businesses, places, events and incidents are either the products" << endl;
	cout << "of the author\'s imagination or used in a fictitious manner." << endl;
	cout << "Any resemblance to actual persons, living or dead, or actual" << endl;
	cout << "events is purely coincidental." << endl;

	cin.get();
	cout << endl << endl << endl << endl;

	cout << "This work of fiction, however, is based upon that of \"The Legend of Zelda\" franchise." << endl;
	cout << "Any resemblance to persons or events in said franchise is purely intentional." << endl;

	cin.get();
	cout << endl << endl << endl << endl;

	cout << "You wake up next to the cold, petrified body of the Great Deku Tree. Or rather, what's left of it." << endl;
	cout << "You look around for your fairy, Navi, who is no where to be seen.You can still hear her voice in the" << endl;
	cout << "back of your mind, \"Hey!Listen!\" With your faithful companion missing, there is but one way to go: Forward." << endl;
	cout << "You gather up your wooden sword, slingshot, and what few deku seeds you have left and venture forth into the Great Deku Tree." << endl;
	cin.get();

	Game g1;
	g1.play();

	return 0;
}