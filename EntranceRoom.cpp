#include "EntranceRoom.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for EnrtanceRoom Class
****************************************************************/

EntranceRoom::EntranceRoom()
{
	name = "Entrance";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void EntranceRoom::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool EntranceRoom::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string EntranceRoom::getSpecialItem()
{
	return string();
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void EntranceRoom::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void EntranceRoom::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void EntranceRoom::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void EntranceRoom::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int EntranceRoom::dispayMenu()
{
	cout << endl << endl;

		cout << "You're inside the entrance of the Great Deku Tree.  You see 3 doors:" << endl;
		cout << "1 to the North, 1 to the East, and 1 to West." << endl;
		cout << "What do you do?" << endl << endl;
		cout << "1. Go North" << endl;
		cout << "2. Go West" << endl;
		cout << "3. Go East" << endl;
		cout << "4. Abandon your quest to save Navi and leave her to die" << endl;

		choice = intInputValid();
		cout << endl << endl << endl;

		while (choice < 1 || choice > 4)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 4." << endl << endl;
			choice = intInputValid();
			cout << endl << endl << endl;
		}

		return choice;
}
