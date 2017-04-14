#include "B2Room.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for B2Room Class
****************************************************************/

/*****************************************************
** Description: Default constructor for B2
******************************************************/
B2Room::B2Room()
{
	name = "B2";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	specialItem = "Key";
	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void B2Room::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool B2Room::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string B2Room::getSpecialItem()
{
	return specialItem;
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void B2Room::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void B2Room::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void B2Room::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void B2Room::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int B2Room::dispayMenu()
{
	if (getSpecialAction() == false)
	{
		cout << endl << endl;

		cout << "You walk through the hole in the wall and are greeted by a blinding light in the second basement." << endl;
		cout << "It takes a few seconds, but your eyes slowly adjust to the brightness." << endl;
		cout << "You take a look around and discover one of the floor tiles is oddly shaped." << endl;
		cout << "What do you do?" << endl << endl;
		cout << "1. Investigate the odd tile" << endl;
		cout << "2. Return to the first basement" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;

		choice = intInputValid();
		cout << endl << endl << endl;

		while (choice < 1 || choice > 3)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
			choice = intInputValid();
			cout << endl << endl << endl;
		}

		if (choice == 1)
		{
			cout << endl << endl;

			cout << "You walk over to the tile and realize it overlaps the adjacent tiles." << endl;
			cout << "You pick up the tile and underneath you discover a key!" << endl;
			cout << "Maybe this key unlocks a door somewhere in the dungeon." << endl;
			specialAction();
		}

		return choice;
	}
	else
	{
		cout << endl << endl;

		cout << "You've already collected the key from this room." << endl;
		cout << "This room has nothing left to offer you." << endl;
		cout << "You return to the first basement." << endl;
		cout << endl << endl;
		choice = 2;
		cout << endl << endl << endl;
		return choice;
	}
}
