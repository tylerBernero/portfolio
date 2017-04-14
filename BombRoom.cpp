#include "BombRoom.hpp"
/***************************************************************
** Title: Final Project
** Author: Tyler Bernero
** Date: March 21, 2017
** Description: Source file for Bomb Class
****************************************************************/

BombRoom::BombRoom()
{
	name = "BombRoom";
	north = nullptr;
	south = nullptr;
	east = nullptr;
	west = nullptr;

	specialItem = "Bombs";
	changedStatus = false;
}

/*****************************************************
** Description: Performs special action of room
******************************************************/
void BombRoom::specialAction()
{
	changedStatus = true;
}

/*****************************************************
** Description: Returns if status has changed
******************************************************/
bool BombRoom::getSpecialAction()
{
	return changedStatus;
}

/*****************************************************
** Description: Get special item of room
******************************************************/
string BombRoom::getSpecialItem()
{
	return specialItem;
}

/*****************************************************
** Description: Sets North pointer
******************************************************/
void BombRoom::setNorth(Dungeon* room)
{
	north = room;
}

/*****************************************************
** Description: Sets South pointer
******************************************************/
void BombRoom::setSouth(Dungeon* room)
{
	south = room;
}

/*****************************************************
** Description: Sets East pointer
******************************************************/
void BombRoom::setEast(Dungeon* room)
{
	east = room;
}

/*****************************************************
** Description: Sets SWest pointer
******************************************************/
void BombRoom::setWest(Dungeon* room)
{
	west = room;
}

/*****************************************************
** Description: Displays and returns menu choice
******************************************************/
int BombRoom::dispayMenu()
{
	if (getSpecialAction() == false)
	{
		cout << endl << endl;

		cout << "You emerge through the door and find a well-lit room with no other exit than the door you just entered through." << endl;
		cout << "You notice a rather large pile of rubble in one corner of the room." << endl;
		cout << "What do you do?" << endl << endl;
		cout << "1. Investigate the rubble" << endl;
		cout << "2. Return to the entrance" << endl;
		cout << "3. Abandon your quest to save Navi and leave her to die" << endl;
		
		choice = intInputValid();
		while (choice < 1 || choice > 3)
		{
			cout << endl << "That is not a valid input.  Please enter a number between 1 and 3." << endl << endl;
			choice = intInputValid();
		}

		if (choice == 1)
		{
			cout << endl << endl;

			cout << "You cautiously approach the mysterious pile of rubble." << endl;
			cout << "No danger alerts itself to you." << endl;
			cout << "You bend down and start clearing the rubble." << endl;
			cout << "A treasure chest! You open it and see what's inside." << endl;
			cout << "You found bombs! Maybe they can be used to break a cracked wall somewhere." << endl;
			specialAction();

		}

		return choice;
	}
	else
	{
		cout << endl << endl;

		cout << "You've already collected the bombs from this room." << endl;
		cout << "This room has nothing left to offer you." << endl;
		cout << "You return to the entrance." << endl;
		cout << endl << endl;
		choice = 2;
		return choice;
	}

}
