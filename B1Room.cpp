#include "B1Room.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for B1Room Class
****************************************************************/

B1Room::B1Room()
{
	name = "B1";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	specialItem = "Cracked wall";
	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void B1Room::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool B1Room::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string B1Room::getSpecialItem()
{
	return specialItem;
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void B1Room::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void B1Room::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void B1Room::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void B1Room::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int B1Room::dispayMenu()
{
	if (getSpecialAction() == false)
	{
		cout << endl << endl;

		cout << "Now you find yourself inside the first basement of the dungeon." << endl;
		cout << "You only see 1 door: To the South returning to the Skulltula Room." << endl;
		cout << "You carefuly observe the room and a crack in the northern wall catches your attention." << endl;
		cout << "What do you do?" << endl << endl;
		cout << "1. Investigate the cracked wall" << endl;
		cout << "2. Go South" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;

		choice = intInputValid();
		cout << endl << endl << endl;

		while (choice < 1 || choice > 3)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
			choice = intInputValid();
		}

		return choice;
	}
	else
	{
		cout << endl << endl;

		cout << "You now see 2 doors: 1 to the South returning to the Skulltula Room and 1 to the North." << endl;
		cout << "What do you do?" << endl;
		cout << "1. Go North" << endl;
		cout << "2. Go South" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;

		choice = intInputValid();

		while (choice < 1 || choice > 3)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
			choice = intInputValid();
		}

		return choice;
	}
}
